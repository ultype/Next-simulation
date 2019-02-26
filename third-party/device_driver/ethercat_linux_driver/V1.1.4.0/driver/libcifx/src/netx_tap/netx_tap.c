/**************************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 **************************************************************************************

   Filename:
    $Workfile: netx_tap.c $
   Last Modification:
    $Author: sebastiand $
    $Modtime: 30.09.09 14:10 $
    $Revision: 5301 $

   Targets:
     Linux        : yes

   Description:


   Changes:

     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
     2        08.12.2017   SD   Reworked send/recv handling not to discard messages
                                we are not interrested (see DevTransferPacket())
                                this may lead to loosing packets and therefore NEVER a link state update
     1        12.02.2014   SD   Initial version

**************************************************************************************/
#ifdef CIFXETHERNET

#include <sys/ioctl.h>
#include <sys/select.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <malloc.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/socket.h>
#include <stdio.h>
#include <ctype.h>
#include <dirent.h>

#include "TLR_Types.h"
#include "TLR_Results.h"
#include "EthIntf_Public.h"
#include "cifXUser.h"
#include "cifXErrors.h"
#include "rcX_User.h"
#include "rcX_Public.h"
#include "cifXHWFunctions.h"
#include "netx_tap.h"

#define TUNTAP_DEVICEPATH    "/dev/net/tun"

#define SEND_RETRIES 0

void*            g_eth_list_lock;
uint32_t         g_device_cnt = 0;

typedef struct NETX_ETH_DEV_Ttag
{
  int                eth_fd;
  char               cifxeth_name[CIFX_MAX_FILE_NAME_LENGTH];
  char               event_path[CIFX_MAX_FILE_NAME_LENGTH];
  NETX_ETH_DEV_CFG_T config;
  CIFXHANDLE         cifx_driver;
  CIFXHANDLE         cifx_channel;
  PDEVICEINSTANCE    devinst;
  uint32_t           channel_no;
  pthread_t          eth_to_cifx_thread;
  pthread_t          cifx_to_eth_thread;
  int                stop_to_eth;
  int                stop_to_cifx;
  void*              com_lock;
  void*              send_event;
  uint32_t           active_sends;
  uint32_t           send_packets;
  uint32_t           recv_packets;
  int                link_up;
  void*              link_event;
  uint32_t           link_state_change;

} NETX_ETH_DEV_T;

NETX_ETH_DEV_T** g_DeviceList = NULL;

static int32_t cifxeth_search_eth_channel   ( char* szDeviceName, uint32_t ulSearchIdx, uint32_t* pulChannelNumber);
static int     cifxeth_allocate_tap         ( NETX_ETH_DEV_T* internal_dev, char* prefix, char *dev, int fClose);
static void    cifxeth_free_tap             ( NETX_ETH_DEV_T* internal_dev, char* name);
static void    cifxeth_delete_device        ( NETX_ETH_DEV_T* internal_dev);
static int32_t cifxeth_register_app         ( NETX_ETH_DEV_T* internal_dev, int fRegister);
static int     cifxeth_create_com_thread    ( NETX_ETH_DEV_T* internal_dev);
static int     cifxeth_create_cifx_thread   ( NETX_ETH_DEV_T* internal_dev);
static int32_t cifxeth_update_device_config ( NETX_ETH_DEV_T* internal_dev);
static int32_t cifxeth_update_link_state    ( NETX_ETH_DEV_T* internal_dev);
static int32_t cifxeth_get_extended_info    ( NETX_ETH_DEV_T* internal_dev, uint32_t ulInformationRequest, void* pvBuffer, uint32_t ulBufLen);
static void*   eth_to_cifx_thread           ( void* arg);
static void*   cifx_to_eth_thread           ( void* arg);
static NETX_ETH_DEV_T* find_device          ( char* name);

/*****************************************************************************/
/*! This function creates a netX based ethernet interface
*   \param config  pointer to configuration structure
*   \return != NULL on success                                               */
/*****************************************************************************/
void* cifxeth_create_device(NETX_ETH_DEV_CFG_T* config)
{
  NETX_ETH_DEV_T* internal_dev = NULL;
  void*           ret          = NULL;
  int32_t         cifx_error   = CIFX_NO_ERROR;
  int32_t         search_error = CIFX_NO_ERROR;
  uint32_t        channel_no   = 0;
  uint32_t        eth_no       = 0;
  int             err          = 0;

  if (NULL == config)
    goto exit;

  if (NULL != find_device( config->cifx_name))
    return NULL;

  /* try to find a channel providing an ethernet interface */
  while (CIFX_NO_ERROR == (search_error = cifxeth_search_eth_channel( config->cifx_name, channel_no, &channel_no)))
  {
    if(NULL != (internal_dev = (NETX_ETH_DEV_T*)OS_Memalloc( sizeof(*internal_dev))))
    {
      OS_Memset( internal_dev, 0, sizeof(NETX_ETH_DEV_T));
      if (NULL == (internal_dev->com_lock = OS_CreateLock()))
      {
        OS_Memfree( internal_dev);
        goto exit;

      } else if (NULL == (internal_dev->send_event = OS_CreateEvent()))
      {
        OS_DeleteLock( internal_dev->com_lock);
        OS_Memfree( internal_dev);
        goto exit;

      } else if (NULL == (internal_dev->link_event = OS_CreateEvent()))
      {
        OS_DeleteEvent( internal_dev->send_event);
        OS_DeleteLock( internal_dev->com_lock);
        OS_Memfree( internal_dev);
        goto exit;
      }
      internal_dev->channel_no = channel_no;

      if(CIFX_NO_ERROR != (cifx_error = xDriverOpen( &internal_dev->cifx_driver)))
      {
        fprintf(stderr, "Ethernet-IF Error: %s: Error opening cifX Device Driver (Ret=0x%08X)\n", __TIME__, cifx_error);

      } else if(CIFX_NO_ERROR == (cifx_error = xChannelOpen(internal_dev->cifx_driver,
                                                            config->cifx_name,
                                                            internal_dev->channel_no,
                                                            &internal_dev->cifx_channel)))
      {
        char             prefix[CIFX_MAX_FILE_NAME_LENGTH];
        uint32_t         i        = 0;
        PCHANNELINSTANCE ptdevice = (PCHANNELINSTANCE)internal_dev->cifx_channel;
        internal_dev->devinst     = (PDEVICEINSTANCE)ptdevice->pvDeviceInstance;

        OS_Memcpy( &internal_dev->config, config, sizeof(internal_dev->config));
        strcpy( internal_dev->config.cifx_name, config->cifx_name);
        strcpy( prefix, config->cifx_name);
        for (i=0; i<strlen(config->cifx_name); i++)
          prefix[i] = tolower(prefix[i]);

        internal_dev->eth_fd = -1;
        if( (err = cifxeth_allocate_tap( internal_dev, prefix, internal_dev->cifxeth_name, 1)) < 0)
        {
          if(g_ulTraceLevel & TRACE_LEVEL_ERROR)
          {
            USER_Trace( internal_dev->devinst, TRACE_LEVEL_ERROR, "Ethernet-IF Error: Error allocating tap device for '%s'. Error=%d", config->cifx_name, internal_dev->eth_fd);
          }
        } else
        {
          eth_no++;
          strcpy( config->eth_dev_name, internal_dev->cifxeth_name);

          if(g_ulTraceLevel & TRACE_LEVEL_INFO)
          {
            USER_Trace( internal_dev->devinst, TRACE_LEVEL_INFO, "Ethernet-IF Info: Successfully created '%s' at channel %d on device '%s'", internal_dev->cifxeth_name, channel_no, config->cifx_name);
          }
          /* de-register application since may not be de-registered */
          cifxeth_register_app( internal_dev, 0);
          /* Register for ethernet service on device */
          if (CIFX_NO_ERROR == (cifxeth_register_app( internal_dev, 1)))
          {
            /* Create threads for packet exchange */
            if(cifxeth_create_cifx_thread( internal_dev) != 0)
            {
              if(g_ulTraceLevel & TRACE_LEVEL_ERROR)
              {
                USER_Trace( internal_dev->devinst, TRACE_LEVEL_ERROR, "Ethernet-IF Error: Error creating cifX ethernet channel thread for %s.", internal_dev->cifxeth_name);
              }
            } else
            {
              void* tmp = NULL;

              /* Set device MAC address from response packet */
              //cifxeth_update_device_config( internal_dev);

              /* Device successfully created */
              OS_EnterLock( g_eth_list_lock);
              tmp = (NETX_ETH_DEV_T**)OS_Memrealloc( g_DeviceList, sizeof(internal_dev)*g_device_cnt+2);
              if (NULL != tmp)
              {
                g_DeviceList = tmp;
                g_DeviceList[g_device_cnt]   = internal_dev;
                g_DeviceList[g_device_cnt+1] = NULL;
                ret                          = internal_dev;
                g_device_cnt++;
              }
              OS_LeaveLock( g_eth_list_lock);
              if(NULL == ret)
              {
                if(g_ulTraceLevel & TRACE_LEVEL_ERROR)
                {
                  USER_Trace( internal_dev->devinst, TRACE_LEVEL_ERROR, "Ethernet-IF Error: Not enough memory to create cifx virtual ethernet interface!");
                }
              }
            }
          }
        }
      } else
      {
        fprintf(stderr, "Ethernet-IF Error: %s: Error opening cifX Ethernet Channel (Board=%s, Channel=%u, Errror=0x%08X)\n", __TIME__,
                config->cifx_name, internal_dev->channel_no, cifx_error);
      }
      if(NULL == ret)
      {
        cifxeth_delete_device( internal_dev);
      }
    }
    channel_no++;
  }
exit:
  return ret;
}

/*****************************************************************************/
/*! This removes a previously with cifxeth_create_device() created netX based ethernet interface
 * The function requires either a handle or config structure containing the name of the cifX device
*   \param devicehandle pointer to handle returned by cifxeth_create_device()
*   \param config       pointer to configuration structure
*   \return != NULL on success                                               */
/*****************************************************************************/
void cifxeth_remove_device( void* devicehandle, NETX_ETH_DEV_CFG_T* config)
{
  NETX_ETH_DEV_T* internal_dev = (NETX_ETH_DEV_T*)devicehandle;

  if ((NULL == internal_dev) && (NULL == config))
    return;

  if ((NULL != internal_dev) || (NULL != (internal_dev = find_device( config->cifx_name))))
  {
    cifxeth_delete_device( internal_dev);
  }
}

/*****************************************************************************/
/*! This function deletes netX based ethernet interface
*   \param internal_dev pointer to internal netx-ethernet device
*   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
static void cifxeth_delete_device( NETX_ETH_DEV_T* internal_dev)
{
  if(NULL != internal_dev)
  {
    if (0 != internal_dev->eth_to_cifx_thread) {
      internal_dev->stop_to_cifx = 1;
      pthread_join( internal_dev->eth_to_cifx_thread, NULL);
    }

    if (0 != internal_dev->cifx_to_eth_thread) {
      internal_dev->stop_to_eth = 1;
      pthread_join( internal_dev->cifx_to_eth_thread, NULL);
    }

    if (internal_dev->cifx_channel != NULL)
      cifxeth_register_app( internal_dev, 0);

    cifxeth_free_tap(internal_dev,internal_dev->cifxeth_name);

    if (NULL != internal_dev->link_event)
      OS_DeleteEvent( internal_dev->link_event);

    if (NULL != internal_dev->com_lock)
      OS_DeleteLock( internal_dev->com_lock);

    if (NULL != internal_dev->send_event)
      OS_DeleteEvent( internal_dev->send_event);

    if(NULL != internal_dev->cifx_channel)
      xChannelClose(internal_dev->cifx_channel);

    if(NULL != internal_dev->cifx_driver)
      xDriverClose(internal_dev->cifx_driver);

    OS_EnterLock( g_eth_list_lock);
    if (NULL != g_DeviceList)
    {
      int   found = 0;
      int   tmp   = 0;
      void* list  = NULL;

      for (tmp=0;tmp<g_device_cnt;tmp++)
      {
        if (NULL != g_DeviceList[tmp])
        {
          if (internal_dev == g_DeviceList[tmp])
          {
            found = 1;
            OS_Memfree(internal_dev);
          }
          if (1 == found)
            g_DeviceList[tmp] = g_DeviceList[tmp+1];
        }
      }
      if (1 == found)
      {
        if (g_device_cnt > 1)
        {
          if (NULL != (list = OS_Memrealloc( g_DeviceList, sizeof(internal_dev)*g_device_cnt+1)))
          {
            g_DeviceList = list;
            g_device_cnt--;
          }

        } else
        {
          OS_Memfree( g_DeviceList);
          g_DeviceList = NULL;
          g_device_cnt = 0;
        }
      }
    }
    OS_LeaveLock( g_eth_list_lock);
  }
}

/*****************************************************************************/
/*! removes all cifx tap devices reside in /sys/class/net                    */
/*****************************************************************************/
void cifxeth_sys_cleanup(void) {
  struct dirent**       namelist;
  int                   num_virt_eth;

  num_virt_eth = scandir("/sys/class/net/", &namelist, 0, alphasort);
  if(num_virt_eth > 0)
  {
    int currenteth;
    for(currenteth = 0; currenteth < num_virt_eth; ++currenteth)
    {
      if (0 == strncmp("cifx",namelist[currenteth]->d_name,4)) {
        cifxeth_free_tap(NULL,namelist[currenteth]->d_name);
      }
      free(namelist[currenteth]);
    }
    free(namelist);
  }
}

/*****************************************************************************/
/*! This function searches a cifx device for an existing Ethernet channel
*   \param szDeviceName     name of the cifX device
*   \param ulSearchIdx      Start index for channel information search
*   \param ulSearchIdx      pointer to channel providing ethernet interface
*   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
int32_t cifxeth_search_eth_channel( char*  szDeviceName,
                                 uint32_t  ulSearchIdx,
                                 uint32_t* pulChannelNumber)
{
  int32_t          lRet       = CIFX_NO_ERROR;
  CIFXHANDLE       hSysdevice = NULL;
  CIFXHANDLE       hDriver    = NULL;
  PCHANNELINSTANCE ptdevice   = NULL;
  PDEVICEINSTANCE  ptDevInst  = NULL;

  if (ulSearchIdx>=CIFX_MAX_NUMBER_OF_CHANNELS)
    return CIFX_INVALID_PARAMETER;

  if (CIFX_NO_ERROR != xDriverOpen(&hDriver))
  {
    fprintf( stderr, "Ethernet-IF Error: %s: Error opening driver to for ethernet interface (lRet=0x%08X)\n",__TIME__,lRet);
    /* Check if we have a channel that might be used for Ethernet / NDIS */
  } else if(CIFX_NO_ERROR != (lRet = xSysdeviceOpen( hDriver,
                                              szDeviceName,
                                              &hSysdevice)))
  {
    fprintf( stderr, "Ethernet-IF Error: %s: Error opening system device to read channel info block to detect channels usable for ethernet interface (lRet=0x%08X). - %s\n",__TIME__,lRet, szDeviceName);
  } else
  {
    /* Read channel information block */
    SYSTEM_CHANNEL_CHANNEL_INFO_BLOCK tChannelInfoBlock = {{{0}}};

    ptdevice  = (PCHANNELINSTANCE)hSysdevice;
    ptDevInst = (PDEVICEINSTANCE)ptdevice->pvDeviceInstance;

    if(CIFX_NO_ERROR != (lRet = xSysdeviceInfo( hSysdevice,
                                                CIFX_INFO_CMD_SYSTEM_CHANNEL_BLOCK,
                                                sizeof(tChannelInfoBlock),
                                                &tChannelInfoBlock)))
    {
      /* Error reading system info block */
      if(g_ulTraceLevel & TRACE_LEVEL_ERROR)
      {
        USER_Trace(ptDevInst,
                   TRACE_LEVEL_ERROR,
                   "Ethernet-IF Error: Error reading channel info block to detect channels usable for ethernet interface (lRet=0x%08X).",
                   lRet);
      }

    } else
    {
      uint32_t ulStartIndex     = 0;
      int      fComChannelFound = 0;

      if (ulSearchIdx>=ptDevInst->ulCommChannelCount)
        return CIFX_INVALID_PARAMETER;

      for( ; ulStartIndex < CIFX_MAX_NUMBER_OF_CHANNELS; ++ulStartIndex)
      {
        NETX_CHANNEL_INFO_BLOCK* ptChannel = (NETX_CHANNEL_INFO_BLOCK*)&tChannelInfoBlock.abInfoBlock[ulStartIndex][0];

        if( (RCX_CHANNEL_TYPE_COMMUNICATION == ptChannel->tHandshake.bChannelType))
        {
          if (DEV_IsReady( ptDevInst->pptCommChannels[ulSearchIdx]))
          {
            fComChannelFound = 1;
            lRet             = CIFX_NO_ERROR;
            break;
          } else
          {
            lRet = CIFX_DEV_NOT_READY;
          }
        }
      }
      lRet = CIFX_INVALID_BOARD;
      /* Check system info block entries */
      for( ; (fComChannelFound && ((ulSearchIdx + ulStartIndex) < CIFX_MAX_NUMBER_OF_CHANNELS)); ++ulSearchIdx)
      {
        NETX_CHANNEL_INFO_BLOCK* ptChannel = (NETX_CHANNEL_INFO_BLOCK*)&tChannelInfoBlock.abInfoBlock[ulSearchIdx + ulStartIndex][0];

        if( (RCX_COMM_CLASS_MESSAGING  == ptChannel->tCom.usCommunicationClass) &&
            (RCX_PROT_CLASS_ETHERNET == ptChannel->tCom.usProtocolClass) )
        {
          /* only create a NDIS interface if the interface is not created already */
          if (NULL != pulChannelNumber)
            *pulChannelNumber = ulSearchIdx;

          lRet = CIFX_NO_ERROR;
          break;
        }
      }
    }
    /* Close system device */
    xSysdeviceClose(hSysdevice);
  }
  xDriverClose(hDriver);

  return lRet;
}

/*****************************************************************************/
/*! This function allocates and initializes a tap device
*   \param internal_dev pointer to internal netx-ethernet device
*   \param prefix       prefix of the device (e.g. "cifX" -> cifX[x])
*   \param dev          returns the name of created device (-> cifX[x])
*   \return a valid file descriptor to the device - on success (>=0)         */
/*****************************************************************************/
static int cifxeth_allocate_tap( NETX_ETH_DEV_T* internal_dev, char* prefix, char *dev, int fClose)
{
  struct ifreq ifr;
  int          ret;

  if( (ret = open( TUNTAP_DEVICEPATH, O_RDWR)) >= 0 )
  {
    int err;

    memset(&ifr, 0, sizeof(ifr));
    ifr.ifr_flags = (IFF_TAP | IFF_NO_PI);

    if(prefix)
      strncpy( ifr.ifr_name, prefix, IFNAMSIZ);

    if( (err = ioctl(ret, TUNSETIFF, (void *) &ifr)) < 0 )
    {
      if(g_ulTraceLevel & TRACE_LEVEL_ERROR)
      {
        USER_Trace( internal_dev->devinst, TRACE_LEVEL_ERROR, "Ethernet-IF Error: Error creating tap device (TUNSETIFF) '%s'.    Error=%d", prefix, errno);
      }
      close(ret);
      ret = err;

    } else
    {
      if ( (err = ioctl(ret, TUNSETPERSIST, 1) < 0 ) )
      {
        if(g_ulTraceLevel & TRACE_LEVEL_ERROR)
        {
          USER_Trace( internal_dev->devinst, TRACE_LEVEL_ERROR, "Ethernet-IF Error: Error creating persistent tap device (TUNSETPERSIST) '%s'.    Error=%d", prefix, errno);
        }
      }
      if (dev != NULL) {
        strcpy(dev, ifr.ifr_name);
        sprintf(internal_dev->event_path,"/sys/class/net/%s/uevent",prefix);
        internal_dev->eth_fd = ret; /* set temp. since cifxeth_update_device_config() deals with that handle */
        cifxeth_update_device_config(internal_dev);
        internal_dev->eth_fd = -1;
      }
    }
  } else
  {
    if(g_ulTraceLevel & TRACE_LEVEL_ERROR)
    {
      USER_Trace( internal_dev->devinst, TRACE_LEVEL_ERROR, "Ethernet-IF Error: Error opening tun interface '%s'. Error=%d", TUNTAP_DEVICEPATH, errno);
    }
    ret = -errno;
  }
  /* NOTE: A closed device (only persistently created) indicates link down -> open the device to indicate link up */
  if ( (fClose != 0) && (ret >= 0) )
    close(ret);

  return ret;
}

/*****************************************************************************/
/*! This function frees a tap device
 *   \param internal_dev pointer to internal netx-ethernet device
 *   \param name         name of device in case device is already closed (->link down) */
/*****************************************************************************/
void cifxeth_free_tap(NETX_ETH_DEV_T* internal_dev, char* name) {

  if (NULL != internal_dev) {
    if (internal_dev->eth_fd>=0) {
      ioctl(internal_dev->eth_fd, TUNSETPERSIST, 0);
      close(internal_dev->eth_fd);
      internal_dev->eth_fd = -1;
    }
  }
  /* we have also check the name, in case of link down the handle is '-1' */
  if (name != NULL) {
    struct ifreq ifr;
    int          ret;

    if ((ret = open( TUNTAP_DEVICEPATH, O_RDWR))) {
      memset(&ifr, 0, sizeof(ifr));
      ifr.ifr_flags = (IFF_TAP | IFF_NO_PI);
      strncpy( ifr.ifr_name, name, IFNAMSIZ);
      ioctl(ret, TUNSETIFF, (void *) &ifr);
      ioctl(ret, TUNSETPERSIST, 0);
      close(ret);
    }
  }
}

/*****************************************************************************/
/*! This function creates send/receivce thread
 *   \param internal_dev pointer to internal cifx eth channel
 *   \return >0 on success                                                    */
/*****************************************************************************/
static int cifxeth_create_cifx_thread(NETX_ETH_DEV_T* internal_dev)
{
  int            ret = -1;
  pthread_attr_t attr;

  internal_dev->stop_to_eth = 0;
  if(0 == (ret = pthread_attr_init(&attr)))
  {
    ret = pthread_create(&internal_dev->cifx_to_eth_thread,
                          &attr,
                          cifx_to_eth_thread,
                          internal_dev);
  }
  return ret;
}

/*****************************************************************************/
/*! This function creates send/receivce thread
*   \param internal_dev pointer to internal netx-ethernet device
*   \return >0 on success                                                    */
/*****************************************************************************/
static int cifxeth_create_com_thread(NETX_ETH_DEV_T* internal_dev)
{
  int            ret = -1;
  pthread_attr_t attr;

  internal_dev->stop_to_cifx = 0;
  if(0 == (ret = pthread_attr_init(&attr)))
  {
    ret = pthread_create(&internal_dev->eth_to_cifx_thread,
                                 &attr,
                                 eth_to_cifx_thread,
                                 internal_dev);
  }

  return ret;
}

/*****************************************************************************/
/*! Send thread: processes eth packets from tapX to cifX device
*   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
static void* eth_to_cifx_thread(void* arg)
{
  NETX_ETH_DEV_T*               internal_dev = (NETX_ETH_DEV_T*)arg;
  int                           fd           = internal_dev->eth_fd;
  char                          buffer[1514];
  ETH_INTF_SEND_ETH_FRAME_PCK_T cifx_packet;
  int                           select_ret = 0;

  memset(&cifx_packet.tReq.tHead, 0, sizeof(cifx_packet.tReq.tHead));

  cifx_packet.tReq.tHead.ulCmd  = ETH_INTF_CMD_SEND_ETH_FRAME_REQ;
  cifx_packet.tReq.tHead.ulDest = RCX_PACKET_DEST_DEFAULT_CHANNEL;

  while(1)
  {
    fd_set readfds, exceptfds;
    struct timeval  timeout = {0};
    timeout.tv_sec  = 0;
    timeout.tv_usec = 500 * 1000; /* Default wait timeout = 500ms */

    FD_ZERO(&readfds);
    FD_ZERO(&exceptfds);
    FD_SET(fd, &readfds);
    FD_SET(fd, &exceptfds);

    /* check link state */
    while (0 == internal_dev->link_up)
    {
      OS_WaitEvent( internal_dev->link_event, 10);
      if (internal_dev->stop_to_cifx == 1)
        break;
    }

    if((select_ret = select( fd+1, &readfds, NULL, &exceptfds, &timeout)) > 0)
    {
      if(FD_ISSET(fd, &exceptfds))
      {
        if(g_ulTraceLevel & TRACE_LEVEL_ERROR)
        {
          USER_Trace( internal_dev->devinst, TRACE_LEVEL_ERROR, "Ethernet-IF Error: Exception on Ethernet Device file descriptor, exiting thread");
        }
        break;
      }

      if(FD_ISSET(fd, &readfds))
      {
        int32_t cifx_error;
        ssize_t recv_len;
        int retry = 0;

        recv_len = read(fd, buffer, sizeof(buffer));

        while (internal_dev->active_sends>0x08)
        {
          OS_WaitEvent( internal_dev->send_event, 10);
          if (internal_dev->stop_to_cifx == 1)
            break;
        }
        if (internal_dev->stop_to_cifx == 1)
          break;

        if(recv_len > 0)
        {
          memcpy( &cifx_packet.tReq.tData, buffer, recv_len);
          cifx_packet.tReq.tHead.ulLen = recv_len;
          if (recv_len<60)
          {
            memset( (cifx_packet.tReq.tData.abData + recv_len), 0, (60 - recv_len));
            cifx_packet.tReq.tHead.ulLen = 60;
          }
          retry = SEND_RETRIES;
          do {
            cifx_error = xChannelPutPacket( internal_dev->cifx_channel, (CIFX_PACKET*)&cifx_packet, CIFX_TO_CONT_PACKET);
            if (cifx_error == CIFX_NO_ERROR) {
              OS_EnterLock( internal_dev->com_lock);
              internal_dev->active_sends++;
              OS_LeaveLock( internal_dev->com_lock);
            }
          } while ((cifx_error == CIFX_DEV_MAILBOX_FULL) && (retry-->0));

          if (CIFX_NO_ERROR != cifx_error)
          {
            if(g_ulTraceLevel & TRACE_LEVEL_INFO)
            {
              USER_Trace( internal_dev->devinst, TRACE_LEVEL_ERROR, "Ethernet-IF Error: Error sending frame to cifX Device. (Error=0x%08X)", cifx_error);
            }
          }
        }
      }
    } else if (0 == select_ret)
    {
      //continue;
    } else
    {
      if(g_ulTraceLevel & TRACE_LEVEL_ERROR)
      {
        USER_Trace( internal_dev->devinst, TRACE_LEVEL_ERROR, "Ethernet-IF Error: Error on select for Ethernet Device file descriptor, exiting thread");
      }
      break;
    }
    if (internal_dev->stop_to_cifx == 1)
      break;
  }

  return NULL;
}

/*****************************************************************************/
/*! send confirmation of the packet
 *   \param internal_dev Pointer to internal device
 *   \param ptPacket Pointer to packet to handle
 *   \param ulTimeout timeout
 *   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
int32_t send_confirmation( NETX_ETH_DEV_T* internal_dev, CIFX_PACKET* ptPacket, uint32_t ulTimeout) {
  int32_t ret = CIFX_NO_ERROR;

  if (ptPacket == NULL)
    return CIFX_NO_ERROR;

  if ((ptPacket->tHeader.ulCmd & RCX_MSK_PACKET_ANSWER) == 0) {
    ptPacket->tHeader.ulCmd   |= RCX_MSK_PACKET_ANSWER;
    ptPacket->tHeader.ulState  = 0;
    ptPacket->tHeader.ulLen    = 0;

    ret = xChannelPutPacket(internal_dev->cifx_channel, ptPacket, ulTimeout);
  }
  return ret;
}

/* Packet is required to confirm link change */
 CIFX_PACKET tConfLinkPacket = {0};

/*****************************************************************************/
/*! handles incoming packets
 *   \param internal_dev Pointer to internal device
 *   \param ptPacket Pointer to packet to handle
 *   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
void handle_incoming_packet( NETX_ETH_DEV_T* internal_dev, CIFX_PACKET* ptPacket) {

  switch(ptPacket->tHeader.ulCmd) {
    case ETH_INTF_CMD_SEND_ETH_FRAME_CNF:
      /* Send response */
      OS_EnterLock( internal_dev->com_lock);
      internal_dev->active_sends--;
      OS_SetEvent(internal_dev->send_event);
      OS_LeaveLock( internal_dev->com_lock);
    break;

    case ETH_INTF_CMD_RECV_ETH_FRAME_IND:
    {
      if (internal_dev->link_up) {
        uint32_t data_len = ptPacket->tHeader.ulLen;
        ssize_t  send_res = data_len;
        int      ret = 0;

        /* New RX packet */
        if(send_res != (ret = write(internal_dev->eth_fd, ptPacket->abData, data_len))) {
          if(g_ulTraceLevel & TRACE_LEVEL_ERROR) {
            USER_Trace( internal_dev->devinst, TRACE_LEVEL_ERROR, "Ethernet-IF Error: Error sending incoming data to ethernet device (%d)\n", ret);
          }
        }
      }
    }
    break;

    case ETH_INTF_CMD_EVENT_IND:
    {
      ETH_INTF_EVENT_IND_T* ptEventInd = (ETH_INTF_EVENT_IND_T*)ptPacket;

      /* currently only check link state */
      if (ptEventInd->tData.uiEventCnt[ETH_INTF_EVENT_LINKCHANGED] > 0) {
        /* update link state */
        memcpy (&tConfLinkPacket, ptPacket,sizeof(tConfLinkPacket));
        ptPacket = NULL;
        internal_dev->link_state_change++;
      }
    }
    break;

    default:
    break;
  }
  /* in case of an error we might get no further packets */
  if (ptPacket != NULL) {
    uint8_t bRetry = 3;
    while ((CIFX_NO_ERROR != send_confirmation( internal_dev, ptPacket, CIFX_TO_CONT_PACKET)) && (bRetry > 0)){
      bRetry--;
    };
  }
}

/*****************************************************************************/
/*! Receiver thread: processes eth packets from cifX to tapX device
*   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
static void* cifx_to_eth_thread(void* arg)
{
  NETX_ETH_DEV_T* internal_dev = (NETX_ETH_DEV_T*)arg;
  CIFX_PACKET     cifx_packet;
  uint32_t        ulRecvPktCount   = 0;
  uint32_t        ulSendPktCount   = 0;
  uint32_t        update_linkstate = 0;
  int32_t         lRet;

  while(1)
  {
    if (internal_dev->stop_to_eth == 1)
      break;

    ulRecvPktCount = 1;
    while(ulRecvPktCount > 0) {
      if (CIFX_NO_ERROR == (lRet = xChannelGetPacket( internal_dev->cifx_channel, sizeof(cifx_packet), &cifx_packet, CIFX_TO_CONT_PACKET))) {
        handle_incoming_packet( internal_dev, &cifx_packet);
      }
      if (lRet == CIFX_DEV_GET_NO_PACKET) {
        /* in some case the firmware may deliver wrong mailbox state. */
        /* In case of false state, break here to update link state or */
        /* to be able to interrupt/stop the running thread.           */
        break;
      }
      if (CIFX_NO_ERROR != (lRet = xChannelGetMBXState( internal_dev->cifx_channel, &ulRecvPktCount, &ulSendPktCount))) {
        break;
      }
    }
    if (update_linkstate != internal_dev->link_state_change) {
      if (CIFX_NO_ERROR == cifxeth_update_link_state( internal_dev)) {
        update_linkstate++;
      }
    }
  }
  return NULL;
}

/*! **************************************************************************
* Function retrieves the device link state and updates the corresponding
* tap device
*   \param internal_dev Pointer to internal device
*   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
static int32_t cifxeth_update_link_state( NETX_ETH_DEV_T* internal_dev)
{
  LINK_STATE_T tLinkState = {0};
  int32_t      lRet       = CIFX_NO_ERROR;
  int          skt        = 0;
  struct ifreq ifr        = {{{0}}};
  int          bRetry     = 0;

  memset(&ifr, 0, sizeof(ifr));
  strcpy( ifr.ifr_name, internal_dev->cifxeth_name);
  skt = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
  ioctl( skt, SIOCGIFFLAGS, &ifr);

  if (CIFX_NO_ERROR == (lRet = cifxeth_get_extended_info( internal_dev, EXT_INFO_LINKSTATE, &tLinkState, sizeof(tLinkState))))
  {
    int fSkipUpdate = 0;
    if ((internal_dev->eth_fd >= 0) && (tLinkState.bLinkState)) {
      /* device is already online */
      fSkipUpdate = 1;
    }
    if ((internal_dev->eth_fd < 0) && (tLinkState.bLinkState == 0)) {
      /* already offline... skip handling */
      fSkipUpdate = 1;
    }
    if (fSkipUpdate == 0) {
      if (tLinkState.bLinkState)
      {
        /* notify link state change */
        internal_dev->link_up = 1;
        OS_SetEvent( internal_dev->link_event);

        if( (internal_dev->eth_fd = cifxeth_allocate_tap( internal_dev, internal_dev->cifxeth_name, NULL, 0)) < 0)
        {
          lRet = CIFX_FUNCTION_FAILED;
          if(g_ulTraceLevel & TRACE_LEVEL_ERROR)
          {
            USER_Trace( internal_dev->devinst, TRACE_LEVEL_ERROR, "Ethernet-IF Error: Link-up-error: error open tun device '%s'. Error=%d", internal_dev->cifxeth_name, internal_dev->eth_fd);
          }
        } else {
          if (cifxeth_create_com_thread( internal_dev) != 0) {
            lRet = CIFX_FUNCTION_FAILED;
            if(g_ulTraceLevel & TRACE_LEVEL_ERROR)
            {
              USER_Trace( internal_dev->devinst, TRACE_LEVEL_ERROR, "Ethernet-IF Error: Error creating cifX Ethernet communication thread for %s.",internal_dev->cifxeth_name);
            }
          } else {
            FILE *file = NULL;
            /* notify link up via uevent */
            if (NULL != (file = fopen(internal_dev->event_path,"r+"))) {
              fprintf(file, "online");
              fclose(file);
            } else {
              lRet = CIFX_FUNCTION_FAILED;
              if(g_ulTraceLevel & TRACE_LEVEL_ERROR)
              {
                USER_Trace( internal_dev->devinst, TRACE_LEVEL_ERROR, "Ethernet-IF Error: Error opening event path of cifX Ethernet IF %s (online event).",internal_dev->cifxeth_name);
              }
            }
          }
        }
      } else
      {
        FILE *file = NULL;
        internal_dev->link_up = 0;

        /* stop eth-if to cifx communication since we we will remove the handle */
        internal_dev->stop_to_cifx = 1;

        if (internal_dev->eth_to_cifx_thread != 0) {
          pthread_join( internal_dev->eth_to_cifx_thread, 0);
          internal_dev->eth_to_cifx_thread = 0;
        }
        if (internal_dev->eth_fd >= 0) {
          close(internal_dev->eth_fd);
          internal_dev->eth_fd = -1;
        }
        /* notify link down via uevent */
        if (NULL != (file = fopen(internal_dev->event_path,"r+"))) {
          fprintf(file, "offline");
          fclose(file);
        } else {
          if(g_ulTraceLevel & TRACE_LEVEL_ERROR)
          {
            USER_Trace( internal_dev->devinst, TRACE_LEVEL_ERROR, "Ethernet-IF Error: Error opening event path of cifX Ethernet IF %s (offline event).",internal_dev->cifxeth_name);
          }
          lRet = CIFX_FUNCTION_FAILED;
        }
      }
    }
  }
  /* Confirma always also in case of an error??? confirm link indication otherwise we get no new indication */
  bRetry = 3;
  while ((CIFX_NO_ERROR != send_confirmation( internal_dev, &tConfLinkPacket, CIFX_TO_CONT_PACKET)) && (bRetry > 0)) {
    bRetry--;
  };
  return lRet;
}

/*! **************************************************************************
* Function retrieves the device configuration and initialize the corresponding
* tap device
*   \param internal_dev Pointer to internal device
*   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
static int32_t cifxeth_update_device_config( NETX_ETH_DEV_T* internal_dev)
{
  IPCONFIG_T tExtInfo = {0};
  int32_t    lRet     = CIFX_NO_ERROR;

  if (CIFX_NO_ERROR == (lRet = cifxeth_get_extended_info( internal_dev, EXT_INFO_INTF_CONFIG, &tExtInfo, sizeof(tExtInfo))))
  {
    struct ifreq ifr;
    memset( &ifr, 0, sizeof(ifr));

    memcpy( ifr.ifr_hwaddr.sa_data, tExtInfo.abEthernetMACAddr, 6);
    ifr.ifr_hwaddr.sa_family = 1;

    if( (ioctl( internal_dev->eth_fd, SIOCSIFHWADDR, (void *) &ifr)) < 0 )
    {
      if(g_ulTraceLevel & TRACE_LEVEL_ERROR)
      {
        USER_Trace( internal_dev->devinst, TRACE_LEVEL_ERROR, "Ethernet-IF Error: Failed to set MAC address of %s (%d)", internal_dev->cifxeth_name, errno);
      }
    }
  }
  return lRet;
}

/*! *************************************************************************
 * Receive callback function. requried to handle incoming packets during admin
 * communication
 *   \param ptRecvPkt
 *   \param pvUser                */
/****************************************************************************/
void PacketRecvCallBack( CIFX_PACKET* ptRecvPkt, void* pvUser)
{
  NETX_ETH_DEV_T* internal_dev = (NETX_ETH_DEV_T*)pvUser;

  handle_incoming_packet( internal_dev, ptRecvPkt);
}

/*! *************************************************************************
* Register an application, so the Ethernet Stack will send indications
*   \param internal_dev Pointer to internal device
*   \param fRegister    1= register, 0 = unregister  application            */
/****************************************************************************/
static int32_t cifxeth_register_app( NETX_ETH_DEV_T* internal_dev, int fRegister)
{
  uint32_t               lRet      = CIFX_NO_ERROR;
  CIFXHANDLE             hChannel  = internal_dev->cifx_channel;
  RCX_REGISTER_APP_REQ_T tSendPkt  = {{0}};
  CIFX_PACKET            tRecvPkt  = {{0}};

  tSendPkt.tHead.ulDest = RCX_PACKET_DEST_DEFAULT_CHANNEL; /* Destination of packet, process queue */
  tSendPkt.tHead.ulSrc  = 0;                               /* Source of packet, process queue      */
  tSendPkt.tHead.ulLen  = 0;
  tSendPkt.tHead.ulId   = 0x00;                            /* Identification handle of sender      */

  if (fRegister)
  {
    tSendPkt.tHead.ulCmd = RCX_REGISTER_APP_REQ;          /* Packet command                       */
  }else
  {
    tSendPkt.tHead.ulCmd = RCX_UNREGISTER_APP_REQ;        /* Packet command                       */
  }

  lRet = DEV_TransferPacket( hChannel,
                             (CIFX_PACKET*)&tSendPkt,
                             &tRecvPkt,
                             sizeof(tRecvPkt),
                             CIFX_TO_SEND_PACKET,
                             PacketRecvCallBack, internal_dev);
  if( CIFX_NO_ERROR != lRet)
  {
    /* This is a transport error */
    if(g_ulTraceLevel & TRACE_LEVEL_ERROR)
    {
      /* This is a transport error */
      USER_Trace(internal_dev->devinst,
                TRACE_LEVEL_ERROR,
                 "Ethernet-IF Error: Error in cifXEthTransferPacket()(lRet=0x%08X).",
                lRet);
    }
  } else
  {
    /* in case of de-register ignore return value since we might not be registered */
    if (fRegister == 0) {
      /* Check if we have a state error from the stack */
      if(TLR_S_OK != (lRet = tRecvPkt.tHeader.ulState)) {
        if(g_ulTraceLevel & TRACE_LEVEL_ERROR) {
          USER_Trace(internal_dev->devinst,
                     TRACE_LEVEL_ERROR,
                     "Ethernet-IF Error: Error sending Register-Application-Request (lRet=0x%08X).",
                     lRet);
        }
      }
    }
  }
  return lRet;
}

/*! **************************************************************************
* Function reads extended status block an returns requested information
*   \param internal_dev Pointer to internal device
*   \param ulInformationRequest Command which information is retrieved
*   \param pvBuffer             Pointer to information buffer
*   \param ulBufLen             Size of pvBuffer
*   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
static int32_t cifxeth_get_extended_info( NETX_ETH_DEV_T* internal_dev, uint32_t ulInformationRequest, void* pvBuffer, uint32_t ulBufLen)
{
  int32_t     lRet             = CIFX_NO_ERROR;
  CIFX_PACKET tSendPkt         = {{0}};
  CIFX_PACKET tRecvPkt         = {{0}};
  uint32_t    ulMyPacketNumber = 1;
  CIFXHANDLE  hChannel         = internal_dev->cifx_channel;

  RCX_DPM_GET_EXTENDED_STATE_REQ_T* ptSendReq;

  /* check parameter */
  if ((pvBuffer == NULL) || (ulBufLen == 0))
    return CIFX_INVALID_PARAMETER;

  ptSendReq = (RCX_DPM_GET_EXTENDED_STATE_REQ_T*)&tSendPkt;

  ptSendReq->tHead.ulSrc          = 0;
  ptSendReq->tHead.ulId           = ++ulMyPacketNumber;
  ptSendReq->tHead.ulCmd          = RCX_DPM_GET_EXTENDED_STATE_REQ;
  ptSendReq->tHead.ulLen          = 12; /* size of request */
  ptSendReq->tHead.ulDest         = RCX_PACKET_DEST_DEFAULT_CHANNEL;
  ptSendReq->tData.ulOffset       = 0; /* offset to start the reading from the extended status block */
  ptSendReq->tData.ulDataLen      = sizeof(ETH_INTF_EXTENDED_STATE_T);
  ptSendReq->tData.ulChannelIndex = 0;

  lRet = DEV_TransferPacket( hChannel,
                             (CIFX_PACKET*)&tSendPkt,
                             &tRecvPkt,
                             sizeof(tRecvPkt),
                             CIFX_TO_SEND_PACKET,
                             PacketRecvCallBack, internal_dev);
  if( CIFX_NO_ERROR == lRet)
  {
    RCX_DPM_GET_EXTENDED_STATE_CNF_T* ptRecv = (RCX_DPM_GET_EXTENDED_STATE_CNF_T*)&tRecvPkt;

    /* check error field in response packet */
    if(TLR_S_OK == (lRet = tRecvPkt.tHeader.ulState))
    {
      /* check size of returned information structure */
      if ((ptRecv->tData.ulOffset == 0) && (ptRecv->tData.ulDataLen == sizeof(ETH_INTF_EXTENDED_STATE_T)))
      {
        ETH_INTF_EXTENDED_STATE_T* ptExtStatusInfo = (ETH_INTF_EXTENDED_STATE_T*)&ptRecv->tData.abData;

        /* check which information is requested */
        switch (ulInformationRequest)
        {
          /* return MAC address */
          case EXT_INFO_INTF_CONFIG:
            {
              if ( sizeof(IPCONFIG_T) != ulBufLen)
              {
                lRet = CIFX_INVALID_BUFFERSIZE;
              } else
              {
                PIPCONFIG_T tIPconfig = (PIPCONFIG_T)pvBuffer;
                OS_Memcpy( (void*)tIPconfig->abEthernetMACAddr, (void*)ptExtStatusInfo->tEth.abMacAddress, ETH_INTF_ETH_ADDR_SIZE);
                OS_Memcpy( (void*)&tIPconfig->ulGateway       , (void*)&ptExtStatusInfo->tEth.ulGateway  , sizeof(ptExtStatusInfo->tEth.ulGateway));
                OS_Memcpy( (void*)&tIPconfig->ulIpAddr        , (void*)&ptExtStatusInfo->tEth.ulIpAddress, sizeof(ptExtStatusInfo->tEth.ulIpAddress));
                OS_Memcpy( (void*)&tIPconfig->ulNetMask       , (void*)&ptExtStatusInfo->tEth.ulNetMask  , sizeof(ptExtStatusInfo->tEth.ulNetMask));

                lRet = CIFX_NO_ERROR;
              }
            }
            break;

          /* return Link State */
          case EXT_INFO_LINKSTATE:
            {
              if ( sizeof(LINK_STATE_T) != ulBufLen)
              {
                lRet = CIFX_INVALID_BUFFERSIZE;
              } else
              {
                PLINK_STATE_T ptLinkState = (PLINK_STATE_T)pvBuffer;
                OS_Memcpy( (void*)&ptLinkState->bLinkState, (void*)&ptExtStatusInfo->tEth.bMautype, sizeof(ptExtStatusInfo->tEth.bMautype));

                lRet = CIFX_NO_ERROR;
              }
            }
            break;

          case EXT_STATISTICS:
            {
              if ( sizeof(STATISTIC_T) != ulBufLen)
              {
                lRet = CIFX_INVALID_BUFFERSIZE;
              } else
              {
                STATISTIC_T* ptStatistic      = (STATISTIC_T*)pvBuffer;

                ptStatistic->ullIfInPkts      = ptExtStatusInfo->tEth.ullIfInPkts;
                ptStatistic->ullIfInDiscards  = ptExtStatusInfo->tEth.ullIfInDiscards;
                ptStatistic->ullIfOutPkts     = ptExtStatusInfo->tEth.ullIfOutPkts;
                ptStatistic->ullIfOutDiscards = ptExtStatusInfo->tEth.ullIfOutDiscards;
                ptStatistic->ullIfInBytes     = ptExtStatusInfo->tEth.ullIfInBytes;
                ptStatistic->ullIfOutBytes    = ptExtStatusInfo->tEth.ullIfOutBytes;

                lRet = CIFX_NO_ERROR;
              }
            }
            break;

          case EXT_INFO_MACADDR:
          case EXT_INFO_IPADDR:
          case EXT_INFO_NETMASK:
          case EXT_INFO_GATEWAY:
          case EXT_INFO_NO_RECVPKT:
          case EXT_INFO_NO_RCVPKT_DROP:
          case EXT_INFO_NO_SENDPKT:
          case EXT_INFO_NO_SENDPKT_DROP:
          default:
            lRet = CIFX_INVALID_COMMAND;
            break;
        }
      } else
      {
        lRet = CIFX_INVALID_BUFFERSIZE;
      }
    }
  }
  if (CIFX_NO_ERROR != lRet)
  {
    if(g_ulTraceLevel & TRACE_LEVEL_ERROR)
    {
      USER_Trace( internal_dev->devinst, TRACE_LEVEL_ERROR, "Ethernet-IF Error: Failed to retrieve extended info of %s (0x%X)", lRet);
    }
  }
  return lRet;
}

/*****************************************************************************/
/*! Searchs for internal device structure of the device given by name
*   \param name Name of the requested cifX device
*   \return pointer to internal device (!= NULL on success)                  */
/*****************************************************************************/
static NETX_ETH_DEV_T* find_device(char* name)
{
  NETX_ETH_DEV_T* internal_dev = NULL;

  OS_EnterLock( g_eth_list_lock);
  if (NULL != g_DeviceList)
  {
    int tmp = 0;
    for (tmp=0;tmp<g_device_cnt;tmp++)
    {
      if (NULL != g_DeviceList[tmp])
      {
        if (0 == strcmp( g_DeviceList[tmp]->config.cifx_name, name))
        {
          internal_dev = g_DeviceList[tmp];
          break;
        }
      }
    }
  }
  OS_LeaveLock( g_eth_list_lock);

  return internal_dev;
}

/*****************************************************************************/
/*! NOTE: xSysdeviceReset() is a cifx toolkit function. In case of an ethernet
 * interface a function wrapper is required since xSysdeviceReset() will reset
 * the whole device including the raw ethernet channel. So we need a wrap
 * around to remove all previously registered ethernet interfaces.           */
/*****************************************************************************/
extern int32_t APIENTRY xSysdeviceResetTK( CIFXHANDLE hSysdevice, uint32_t ulTimeout);
/*****************************************************************************/
/*! Hard resets a complete device via system channel
*   \param hSysdevice Handle to system device
*   \param ulTimeout  Timeout to wait for card to finish reset
*   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
int32_t APIENTRY xSysdeviceReset( CIFXHANDLE hSysdevice, uint32_t ulTimeout)
{
  int32_t            ret          = CIFX_NO_ERROR;
  PCHANNELINSTANCE   ptdevice     = (PCHANNELINSTANCE)hSysdevice;
  PDEVICEINSTANCE    ptDevInst    = (PDEVICEINSTANCE)ptdevice->pvDeviceInstance;
  NETX_ETH_DEV_T*    internal_dev = find_device( ptDevInst->szName);
  NETX_ETH_DEV_CFG_T config       = {{0}};
  int                ethdevice    = 0;

  if (NULL != internal_dev)
  {
    ethdevice = 1;
    strcpy( config.cifx_name, internal_dev->config.cifx_name);
    cifxeth_delete_device( internal_dev);
  }

  if (CIFX_NO_ERROR == (ret = xSysdeviceResetTK( hSysdevice, ulTimeout)))
  {
    if (1 == ethdevice)
      cifxeth_create_device( &config);
  }
  return ret;
}

/*****************************************************************************/
/*! NOTE: xChannelReset() is a cifx toolkit function. In case of an ethernet
 * interface a function wrapper is required since xChannelReset() (with mode set
 * to CIFX_SYSTEMSTART) will reset the whole device including the raw ethernet
 * channel. So we need a wrap around to remove all previously registered ethernet
 * interfaces.                                                               */
/*****************************************************************************/
extern int32_t APIENTRY xChannelResetTK( CIFXHANDLE hChannel, uint32_t ulResetMode, uint32_t ulTimeout);
/*****************************************************************************/
/*! Hard resets a complete device via system channel
*   \param hChannel Handle to system device
*   \param ulResetMode Reset Mode
*   \param ulTimeout  Timeout to wait for card to finish reset
*   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
int32_t APIENTRY xChannelReset(CIFXHANDLE  hChannel, uint32_t ulResetMode, uint32_t ulTimeout)
{
  int32_t            ret          = CIFX_NO_ERROR;
  PCHANNELINSTANCE   ptdevice     = (PCHANNELINSTANCE)hChannel;
  PDEVICEINSTANCE    ptDevInst    = (PDEVICEINSTANCE)ptdevice->pvDeviceInstance;
  NETX_ETH_DEV_T*    internal_dev = find_device( ptDevInst->szName);
  NETX_ETH_DEV_CFG_T config       = {{0}};
  int                ethdevice    = 0;

  switch(ulResetMode)
  {
    case CIFX_SYSTEMSTART:
    {
      if (NULL != internal_dev)
      {
        ethdevice = 1;
        strcpy( config.cifx_name, internal_dev->config.cifx_name);
        cifxeth_delete_device( internal_dev);
      }

      if (CIFX_NO_ERROR == (ret = xChannelResetTK( hChannel, ulResetMode, ulTimeout)))
      {
        if (1 == ethdevice)
          cifxeth_create_device( &config);
      }
    }
    default:
    {
      ret = xChannelResetTK( hChannel, ulResetMode, ulTimeout);
    }
    break;
  }
  return ret;
}

#endif //CIFXETHERNET
