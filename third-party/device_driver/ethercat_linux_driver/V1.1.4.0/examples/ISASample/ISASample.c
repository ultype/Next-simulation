/**************************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 **************************************************************************************

   Filename:
    $Workfile: ISASample.c $
   Last Modification:
    $Author: sebastiand $
    $Modtime: 9.02.10 15:45 $
    $Revision: 3961 $

   Targets:
     Linux : yes

   Description:
     Linux ISA I/O test application

   Changes:

     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
      1        02.07.2014  SD       - Initial Version (based on cifxsample)

**************************************************************************************/

#include "cifxlinux.h"
#include "cifXEndianess.h"

#include "rcX_Public.h"

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/mman.h>
#include <time.h>

#define CIFX_DEV "cifX0"

#ifndef UNREFERENCED_PARAMETER
  #define UNREFERENCED_PARAMETER(a) (a=a)
#endif

typedef struct SYNC_CALLBACK_DATAtag
{
  CIFXHANDLE hDevice;
} SYNC_CALLBACK_DATA;


/*****************************************************************************/
/*! Callback rountine for events
*   \param ulNotification Sync command
*   \param ulDataLen      Length of buffer referenced by pvData
*   \param pvData         Data
*   \param pvUser         User pointer                                       */
/*****************************************************************************/
void APIENTRY EventCallback (uint32_t ulNotification, uint32_t ulDataLen, void* pvData, void* pvUser)
{
  UNREFERENCED_PARAMETER(pvData);
  UNREFERENCED_PARAMETER(ulDataLen);

  switch (ulNotification)
  {
    case CIFX_NOTIFY_RX_MBX_FULL:
      printf("EventCallback(): CIFX_NOTIFY_RX_MBX_FULL\n");
    break;

    case CIFX_NOTIFY_TX_MBX_EMPTY:
      printf("EventCallback(): CIFX_NOTIFY_TX_MBX_EMPTY\n");
    break;

    case CIFX_NOTIFY_PD0_IN:
      printf("EventCallback(): CIFX_NOTIFY_PD0_IN\n");
    break;

    case CIFX_NOTIFY_PD0_OUT:
      printf("EventCallback(): CIFX_NOTIFY_PD0_OUT\n");
    break;

    case CIFX_NOTIFY_PD1_IN:
      printf("EventCallback(): CIFX_NOTIFY_PD1_IN\n");
    break;

    case CIFX_NOTIFY_PD1_OUT:
      printf("EventCallback(): CIFX_NOTIFY_PD1_OUT\n");
    break;

    default:
      printf("EventCallback(): UNKNOWN Event, Event number %lu, pvUser 0x%08lx \n", (long unsigned int)ulNotification, (unsigned long)pvUser);
    break;
  }
}


/*****************************************************************************/
/*! Callback rountine for sync events
*   \param ulNotification Sync command
*   \param ulDataLen      Length of buffer referenced by pvData
*   \param pvData         Data
*   \param pvUser         User pointer                                       */
/*****************************************************************************/
void APIENTRY SyncEventCallback (uint32_t ulNotification, uint32_t ulDataLen, void* pvData, void* pvUser)
{
  int32_t             lRet         = 0;
  uint32_t            ulErrorCount = 0;
  SYNC_CALLBACK_DATA* ptSynchData  = (SYNC_CALLBACK_DATA*)pvUser;

  UNREFERENCED_PARAMETER(pvData);
  UNREFERENCED_PARAMETER(ulDataLen);
  UNREFERENCED_PARAMETER(ulNotification);

  printf("SyncCallback()\n");

  lRet = xChannelSyncState( ptSynchData->hDevice, CIFX_SYNC_ACKNOWLEDGE_CMD, 1000, &ulErrorCount);
  if(CIFX_NO_ERROR != lRet)
  {
    printf("Error signaling the Sync, lRet = 0x%08X\n", (unsigned int)lRet);
  }
}


static int kbhit()
{
  struct termios oldt, newt;
  int    ch;
  int    oldf;
  int    iRet = 0;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    iRet = 1;
  }
  return iRet;
}


/*****************************************************************************/
/*! Displays cifX error
*   \param lError     Error code                                             */
/*****************************************************************************/
void ShowError( int32_t lError )
{
  if( lError != CIFX_NO_ERROR)
  {
    char szError[1024] ={0};
    xDriverGetErrorDescription( lError,  szError, sizeof(szError));
    printf("Error: 0x%X, <%s>\n", (unsigned int)lError, szError);
  }
}


/*****************************************************************************/
/*! Displays a hex dump on the debug console (16 bytes per line)
*   \param pbData     Pointer to dump data
*   \param ulDataLen  Length of data dump                                    */
/*****************************************************************************/
void DumpData(unsigned char* pbData, unsigned long ulDataLen)
{
  unsigned long ulIdx;

  for(ulIdx = 0; ulIdx < ulDataLen; ++ulIdx)
  {
    if(0 == (ulIdx % 16))
      printf("\r\n");

    printf("%02X ", pbData[ulIdx]);
  }
  printf("\r\n");
}

/*****************************************************************************/
/*! Dumps a rcX packet to debug console
*   \param ptPacket Pointer to packed being dumped                           */
/*****************************************************************************/
void DumpPacket(CIFX_PACKET* ptPacket)
{
  printf("Dest   : 0x%08lX      ID   : 0x%08lX\r\n",(long unsigned int)HOST_TO_LE32(ptPacket->tHeader.ulDest),  (long unsigned int)HOST_TO_LE32(ptPacket->tHeader.ulId));
  printf("Src    : 0x%08lX      Sta  : 0x%08lX\r\n",(long unsigned int)HOST_TO_LE32(ptPacket->tHeader.ulSrc),   (long unsigned int)HOST_TO_LE32(ptPacket->tHeader.ulState));
  printf("DestID : 0x%08lX      Cmd  : 0x%08lX\r\n",(long unsigned int)HOST_TO_LE32(ptPacket->tHeader.ulDestId),(long unsigned int)HOST_TO_LE32(ptPacket->tHeader.ulCmd));
  printf("SrcID  : 0x%08lX      Ext  : 0x%08lX\r\n",(long unsigned int)HOST_TO_LE32(ptPacket->tHeader.ulSrcId), (long unsigned int)HOST_TO_LE32(ptPacket->tHeader.ulExt));
  printf("Len    : 0x%08lX      Rout : 0x%08lX\r\n",(long unsigned int)HOST_TO_LE32(ptPacket->tHeader.ulLen),   (long unsigned int)HOST_TO_LE32(ptPacket->tHeader.ulRout));

  printf("Data:");
  DumpData(ptPacket->abData, HOST_TO_LE32(ptPacket->tHeader.ulLen));
}

/*****************************************************************************/
/*! Function to display driver information
 *   \param  hDriver  Handle to cifX driver
 *   \param  ptVTable Pointer to cifX API function table
 *   \return CIFX_NO_ERROR on success                                        */
/*****************************************************************************/
void DisplayDriverInformation (void)
{
  int32_t            lRet             = CIFX_NO_ERROR;
  DRIVER_INFORMATION tDriverInfo      = {{0}};
  char               szDrvVersion[32] = "";
  CIFXHANDLE         hDriver          = NULL;

  if (CIFX_NO_ERROR == (lRet = xDriverOpen(&hDriver)))
  {
    printf("\n---------- Display Driver Version ----------\n");
    if( CIFX_NO_ERROR != (lRet = xDriverGetInformation(NULL, sizeof(tDriverInfo), &tDriverInfo)) )
      ShowError( lRet);
    else if ( CIFX_NO_ERROR != (lRet = cifXGetDriverVersion( sizeof(szDrvVersion)/sizeof(*szDrvVersion), szDrvVersion)))
      ShowError( lRet);
    else
      printf("Driver Version: %s, based on %.32s \n\n", szDrvVersion, tDriverInfo.abDriverVersion);

    /* close previously opened driver */
    xDriverClose(hDriver);
  }
  printf(" State = 0x%08X\r\n", (unsigned int)lRet);
  printf("----------------------------------------------------\r\n");
}

/*****************************************************************************/
/*! Function to demonstrate the board/channel enumeration
*   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
int32_t EnumBoardDemo(void)
{
  CIFXHANDLE hDriver = NULL;
  int32_t    lRet    = xDriverOpen(&hDriver);

  printf("---------- Board/Channel enumeration demo ----------\r\n");

  if(CIFX_NO_ERROR == lRet)
  {
    /* Driver/Toolkit successfully opened */
    unsigned long     ulBoard    = 0;
    BOARD_INFORMATION tBoardInfo = {0};

    /* Iterate over all boards */
    while(CIFX_NO_ERROR == xDriverEnumBoards(hDriver, ulBoard, sizeof(tBoardInfo), &tBoardInfo))
    {
      printf("Found Board %s\r\n", tBoardInfo.abBoardName);
      if(strlen( (char*)tBoardInfo.abBoardAlias) != 0)
        printf(" Alias        : %s\r\n", tBoardInfo.abBoardAlias);

      printf(" DeviceNumber : %lu\r\n",(long unsigned int)tBoardInfo.tSystemInfo.ulDeviceNumber);
      printf(" SerialNumber : %lu\r\n",(long unsigned int)tBoardInfo.tSystemInfo.ulSerialNumber);
      printf(" Board ID     : %lu\r\n",(long unsigned int)tBoardInfo.ulBoardID);
      printf(" System Error : 0x%08lX\r\n",(long unsigned int)tBoardInfo.ulSystemError);
      printf(" Channels     : %lu\r\n",(long unsigned int)tBoardInfo.ulChannelCnt);
      printf(" DPM Size     : %lu\r\n",(long unsigned int)tBoardInfo.ulDpmTotalSize);

      unsigned long       ulChannel    = 0;
      CHANNEL_INFORMATION tChannelInfo = {{0}};

      /* iterate over all channels on the current board */
      while(CIFX_NO_ERROR == xDriverEnumChannels(hDriver, ulBoard, ulChannel, sizeof(tChannelInfo), &tChannelInfo))
      {
        printf(" - Channel %lu:\r\n", ulChannel);
        printf("    Firmware : %s\r\n", tChannelInfo.abFWName);
        printf("    Version  : %u.%u.%u build %u\r\n",
               tChannelInfo.usFWMajor,
               tChannelInfo.usFWMinor,
               tChannelInfo.usFWRevision,
               tChannelInfo.usFWBuild);
        printf("    Date     : %02u/%02u/%04u\r\n",
               tChannelInfo.bFWMonth,
               tChannelInfo.bFWDay,
               tChannelInfo.usFWYear);

        printf("  Device Nr. : %lu\r\n",(long unsigned int)tChannelInfo.ulDeviceNumber);
        printf("  Serial Nr. : %lu\r\n",(long unsigned int)tChannelInfo.ulSerialNumber);
        printf("  netX Flags : 0x%08X\r\n", tChannelInfo.ulNetxFlags);
        printf("  Host Flags : 0x%08X\r\n", tChannelInfo.ulHostFlags);
        printf("  Host COS   : 0x%08X\r\n", tChannelInfo.ulHostCOSFlags);
        printf("  Device COS : 0x%08X\r\n", tChannelInfo.ulDeviceCOSFlags);

        ++ulChannel;
      }

      ++ulBoard;
    }

    /* close previously opened driver */
    xDriverClose(hDriver);
  }

  printf(" State = 0x%08X\r\n", (unsigned int)lRet);
  printf("----------------------------------------------------\r\n");

  return lRet;
}

/*****************************************************************************/
/*! Function to demonstrate system channel functionality (PacketTransfer)
*   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
int32_t SysdeviceDemo()
{
  CIFXHANDLE hDriver = NULL;
  int32_t    lRet    = xDriverOpen(&hDriver);

  printf("---------- System Device handling demo ----------\r\n");

  if(CIFX_NO_ERROR == lRet)
  {
    /* Driver/Toolkit successfully opened */
    CIFXHANDLE hSys = NULL;
    lRet = xSysdeviceOpen(hDriver, CIFX_DEV, &hSys);

    if(CIFX_NO_ERROR != lRet)
    {
      printf("Error opening SystemDevice!\r\n");

    } else
    {
      SYSTEM_CHANNEL_SYSTEM_INFO_BLOCK    tSysInfoBlock = {{0}};
      SYSTEM_CHANNEL_SYSTEM_INFORMATION   tSysInfo      = {0};
      SYSTEM_CHANNEL_SYSTEM_CONTROL_BLOCK tControlBlock = {0};
      SYSTEM_CHANNEL_SYSTEM_STATUS_BLOCK  tStatusBlock  = {0};

      /* System channel successfully opened, try to read the System Info Block */
      if( CIFX_NO_ERROR != (lRet = xSysdeviceInfo(hSys, CIFX_INFO_CMD_SYSTEM_INFO_BLOCK, sizeof(tSysInfoBlock), &tSysInfoBlock)))
      {
        printf("Error querying system information block\r\n");
      } else
      {
        printf("System Channel Info Block:\r\n");
        printf("==========================\r\n");
        printf("DPM Cookie       : %.4s\r\n",(char*)tSysInfoBlock.abCookie);
        printf("DPM Size         : %lu\r\n",(long unsigned int)tSysInfoBlock.ulDpmTotalSize);
        printf("Device Number    : %lu\r\n",(long unsigned int)tSysInfoBlock.ulDeviceNumber);
        printf("Serial Number    : %lu\r\n",(long unsigned int)tSysInfoBlock.ulSerialNumber);
        printf("HW Options       : 0x%04X 0x%04X 0x%04X 0x%04X\r\n",
               tSysInfoBlock.ausHwOptions[0], tSysInfoBlock.ausHwOptions[1],
               tSysInfoBlock.ausHwOptions[2], tSysInfoBlock.ausHwOptions[3]);
        printf("Manufacturer     : %u\r\n", tSysInfoBlock.usManufacturer);
        printf("Production Date  : %u\r\n", tSysInfoBlock.usProductionDate);
        printf("Device Class     : %u\r\n", tSysInfoBlock.usDeviceClass);
        printf("HW Revision      : %u\r\n", tSysInfoBlock.bHwRevision);
        printf("HW Compatibility : %u\r\n", tSysInfoBlock.bHwCompatibility);

        printf("License Flags 1  : 0x%08X\r\n", tSysInfoBlock.ulLicenseFlags1);
        printf("License Flags 2  : 0x%08X\r\n", tSysInfoBlock.ulLicenseFlags2);
        printf("LicenseID        : 0x%04X\r\n", tSysInfoBlock.usNetxLicenseID);
        printf("LicenseFlags     : 0x%04X\r\n", tSysInfoBlock.usNetxLicenseFlags);
        printf("==========================\r\n");
      }

      /* Try to read the System Information */
      if( CIFX_NO_ERROR != (lRet = xSysdeviceInfo(hSys, CIFX_INFO_CMD_SYSTEM_INFORMATION, sizeof(tSysInfo), &tSysInfo)))
      {
        printf("Error querying system information\r\n");
      } else
      {
        printf("System Information:\r\n");
        printf("===================\r\n");
        printf("System Error     : 0x%08X\r\n", tSysInfo.ulSystemError);
        printf("DPM Size         : %lu\r\n",    (long unsigned int)tSysInfo.ulDpmTotalSize);
        printf("Mailbox size     : %lu\r\n",    (long unsigned int)tSysInfo.ulMBXSize);
        printf("Device Number    : %lu\r\n",    (long unsigned int)tSysInfo.ulDeviceNumber);
        printf("Serial Number    : %lu\r\n",    (long unsigned int)tSysInfo.ulSerialNumber);
        printf("Open Count       : %lu\r\n",    (long unsigned int)tSysInfo.ulOpenCnt);
        printf("===================\r\n");
      }

      /* Try to read the System Control Block */
      if( CIFX_NO_ERROR != (lRet = xSysdeviceInfo(hSys, CIFX_INFO_CMD_SYSTEM_CONTROL_BLOCK, sizeof(tControlBlock), &tControlBlock)))
      {
        printf("Error querying system control block\r\n");
      } else
      {
        printf("System Control Block:\r\n");
        printf("=====================\r\n");
        printf("Command COS      : 0x%08X\r\n", tControlBlock.ulSystemCommandCOS);
        printf("Reserved         : 0x%08X\r\n", tControlBlock.ulReserved);
        printf("=====================\r\n");
      }

      printf("Waiting 2s to let cifX card calculate CPU load!\r\n");
      sleep(2);

      /* Try to read the System Status Block */
      if( CIFX_NO_ERROR != (lRet = xSysdeviceInfo(hSys, CIFX_INFO_CMD_SYSTEM_STATUS_BLOCK, sizeof(tStatusBlock), &tStatusBlock)))
      {
        printf("Error querying system status block\r\n");
      } else
      {
        printf("System Status Block:\r\n");
        printf("====================\r\n");
        printf("System COS       : 0x%08X\r\n", tStatusBlock.ulSystemCOS);
        printf("System Status    : 0x%08X\r\n", tStatusBlock.ulSystemStatus);
        printf("System Error     : 0x%08X\r\n", tStatusBlock.ulSystemError);
        printf("Time since start : %lu\r\n",    (long unsigned int)tStatusBlock.ulTimeSinceStart);
        printf("CPU Load [%%]     : %.2f\r\n",  (float)tStatusBlock.usCpuLoad / 100);
        printf("====================\r\n");
      }

      unsigned long ulSendPktCount = 0;
      unsigned long ulRecvPktCount = 0;

      printf("\r\n");
      printf("Trying to read Security Eeprom:\r\n");
      printf("===============================\r\n");


      /* Read Security EEPROM zone 1*/
      xSysdeviceGetMBXState(hSys, (TLR_UINT32*)&ulRecvPktCount, (TLR_UINT32*)&ulSendPktCount);
      printf("System Mailbox State: MaxSend = %lu, Pending Receive = %lu\r\n",
             ulSendPktCount, ulRecvPktCount);

      RCX_SECURITY_EEPROM_READ_REQ_T tCryptoRead    = {{0}};
      RCX_SECURITY_EEPROM_READ_CNF_T tCryptoReadCnf = {{0}};

      tCryptoRead.tHead.ulDest   = HOST_TO_LE32(RCX_PACKET_DEST_SYSTEM);
      tCryptoRead.tHead.ulLen    = HOST_TO_LE32(sizeof(tCryptoRead.tData));
      tCryptoRead.tHead.ulCmd    = HOST_TO_LE32(RCX_SECURITY_EEPROM_READ_REQ);
      tCryptoRead.tData.ulZoneId = HOST_TO_LE32(1);

      if(CIFX_NO_ERROR != (lRet = xSysdevicePutPacket(hSys, (CIFX_PACKET*)&tCryptoRead, 10)))
      {
        printf("Error sending packet to device!\r\n");
      } else
      {
        printf("Send Packet (Read Crypto Flash Zone 1):\r\n");
        DumpPacket((CIFX_PACKET*)&tCryptoRead);

        xSysdeviceGetMBXState(hSys, (TLR_UINT32*)&ulRecvPktCount, (TLR_UINT32*)&ulSendPktCount);
        printf("System Mailbox State: MaxSend = %lu, Pending Receive = %lu\r\n",
              ulSendPktCount, ulRecvPktCount);

        if(CIFX_NO_ERROR != (lRet = xSysdeviceGetPacket(hSys, sizeof(tCryptoReadCnf), (CIFX_PACKET*)&tCryptoReadCnf, 20)) )
        {
          printf("Error getting packet from device! (lRet=0x%08X)\r\n",(unsigned int)lRet);
        } else
        {
          printf("Received Packet (Read Crypto Flash Zone 1):\r\n");
          DumpPacket((CIFX_PACKET*)&tCryptoReadCnf);

          xSysdeviceGetMBXState(hSys, (TLR_UINT32*)&ulRecvPktCount, (TLR_UINT32*)&ulSendPktCount);
          printf("System Mailbox State: MaxSend = %lu, Pending Receive = %lu\r\n",
                ulSendPktCount, ulRecvPktCount);
        }
      }

      printf("===============================\r\n");
      printf("\r\n");

      xSysdeviceClose(hSys);
    }

    xDriverClose(hDriver);
  }

  printf(" State = 0x%08X\r\n", (unsigned int)lRet);
  printf("----------------------------------------------------\r\n");

  return lRet;
}

/*****************************************************************************/
/*! Function to demonstrate communication channel functionality
*   Packet Transfer and I/O Data exchange
*   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
int32_t ChannelDemo()
{
  CIFXHANDLE hDriver = NULL;
  int32_t    lRet    = xDriverOpen(&hDriver);

  printf("---------- Communication Channel demo ----------\r\n");

  if(CIFX_NO_ERROR == lRet)
  {
    /* Driver/Toolkit successfully opened */
    CIFXHANDLE hChannel = NULL;
    lRet = xChannelOpen(NULL, CIFX_DEV, 0, &hChannel);

    if(CIFX_NO_ERROR != lRet)
    {
      printf("Error opening Channel!");

    } else
    {
      CHANNEL_INFORMATION tChannelInfo = {{0}};

      /* Channel successfully opened, so query basic information */
      if( CIFX_NO_ERROR != (lRet = xChannelInfo(hChannel, sizeof(CHANNEL_INFORMATION), &tChannelInfo)))
      {
        printf("Error querying system information block\r\n");
      } else
      {
        printf("Communication Channel Info:\r\n");
        printf("Device Number    : %lu\r\n",(long unsigned int)tChannelInfo.ulDeviceNumber);
        printf("Serial Number    : %lu\r\n",(long unsigned int)tChannelInfo.ulSerialNumber);
        printf("Firmware         : %s\r\n", tChannelInfo.abFWName);
        printf("FW Version       : %u.%u.%u build %u\r\n",
                tChannelInfo.usFWMajor,
                tChannelInfo.usFWMinor,
                tChannelInfo.usFWRevision,
                tChannelInfo.usFWBuild);
        printf("FW Date          : %02u/%02u/%04u\r\n",
                tChannelInfo.bFWMonth,
                tChannelInfo.bFWDay,
                tChannelInfo.usFWYear);

        printf("Mailbox Size     : %lu\r\n",(long unsigned int)tChannelInfo.ulMailboxSize);
      }

      CIFX_PACKET tSendPkt = {{0}};
      CIFX_PACKET tRecvPkt = {{0}};

      printf("\nStart put/get packet Demo!\n");

      /* Do a basic Packet Transfer */
      if(CIFX_NO_ERROR != (lRet = xChannelPutPacket(hChannel, &tSendPkt, 10)))
      {
        printf("Error sending packet to device!\r\n");
      } else
      {
        printf("Send Packet:\r\n");
        DumpPacket(&tSendPkt);

        if(CIFX_NO_ERROR != (lRet = xChannelGetPacket(hChannel, sizeof(tRecvPkt), &tRecvPkt, 20)) )
        {
          printf("Error getting packet from device!\r\n");
        } else
        {
          printf("Received Packet:\r\n");
          DumpPacket(&tRecvPkt);
        }
      }

      sleep(1);

      printf("\nStart read/write IO-Data!\n");

      /* Read and write I/O data (32Bytes). Output data will be incremented each cyle */
      unsigned char abSendData[32] = {0};
      unsigned char abRecvData[32] = {0};
      unsigned long ulCycles       = 0;
      unsigned long ulState;

      if(CIFX_NO_ERROR != (lRet = xChannelBusState(hChannel, CIFX_BUS_STATE_ON,(TLR_UINT32*) &ulState, 10000)))
      {
        printf("Error setting Bus state lRet = 0x%08X!\r\n",(unsigned int)lRet);

         xChannelClose(hChannel);
         xDriverClose(hDriver);
         return lRet;
      }

      printf("IO Demo running <Hit any key to abort>:\n");

      while(!kbhit())
      {
        ++ulCycles;

        usleep(1 * 1000); /* Wait 1 ms so we can see the counter on the LEDs */
        if(CIFX_NO_ERROR != (lRet = xChannelIORead(hChannel, 0, 0, sizeof(abRecvData), abRecvData, 10)))
        {
          printf("Error reading IO Data area!\r\n");
          break;
        } else
        {
          printf("IORead Data:");
          DumpData(abRecvData, sizeof(abRecvData));
          memcpy(abSendData, abRecvData, sizeof(abRecvData));

          /* On a CB-AB32 we will echo the input 8 buttons if one is pressed, otherwise a counter
             will be placed on output */
          if(abRecvData[0] == 0)
            abSendData[0] = (unsigned char)ulCycles;

          if(CIFX_NO_ERROR != (lRet = xChannelIOWrite(hChannel, 0, 0, sizeof(abSendData), abSendData, 10)))
          {
            printf("Error writing to IO Data area!\r\n");
            break;
          } else
          {
            printf("IOWrite Data:");
            DumpData(abSendData, sizeof(abSendData));
          }
        }
      }
      printf("IODemo ended. Total cycles %lu\n", ulCycles);

      if(CIFX_NO_ERROR != (lRet = xChannelBusState(hChannel, CIFX_BUS_STATE_OFF, (TLR_UINT32*)&ulState, 10000)))
      {
        printf("Error setting Bus state lRet = 0x%08X!\r\n",(unsigned int)lRet);
      }


      xChannelClose(hChannel);
    }

    xDriverClose(hDriver);
  }

  printf(" State = 0x%08X\r\n", (unsigned int)lRet);
  printf("----------------------------------------------------\r\n");

  return lRet;

}

/*****************************************************************************/
/*! Function to demonstrate control/status block functionality
*   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
int32_t BlockDemo( void)
{
  CIFXHANDLE hDriver = NULL;
  int32_t    lRet    = xDriverOpen(&hDriver);

  printf("\n--- Read / Write Block Information ---\r\n");

  /* Open channel */
  if(CIFX_NO_ERROR == lRet)
  {
    CIFXHANDLE hDevice = NULL;
    lRet = xChannelOpen(NULL, CIFX_DEV, 0, &hDevice);
    if(lRet != CIFX_NO_ERROR)
    {
      printf("Error opening Channel!\r\n");
    } else
    {
      unsigned char abBuffer[4] = {0};

      /* Read / Write control block */
      printf("Read CONTROL Block \r\n");
      memset( abBuffer, 0, sizeof(abBuffer));
      lRet = xChannelControlBlock( hDevice, CIFX_CMD_READ_DATA, 0, 4, &abBuffer[0]);

      DumpData(abBuffer, 4);

      printf("Write CONTROL Block \r\n");
      lRet = xChannelControlBlock( hDevice, CIFX_CMD_WRITE_DATA, 0, 4, &abBuffer[0]);

      printf("Read COMMON Status Block \r\n");
      memset( abBuffer, 0, sizeof(abBuffer));
      lRet = xChannelCommonStatusBlock( hDevice, CIFX_CMD_READ_DATA, 0, 4, &abBuffer[0]);

      DumpData(abBuffer, 4);

      printf("Write COMMON Status Block \r\n");
      lRet = xChannelCommonStatusBlock( hDevice, CIFX_CMD_WRITE_DATA, 0, 4, &abBuffer[0]);

      /* this is expected to fail, as this block must not be written by Host */
      if(CIFX_NO_ERROR != lRet)
        printf("Error writing to common status block. lRet = 0x%08X\r\n", (unsigned int)lRet);

      printf("Read EXTENDED Status Block \r\n");
      memset( abBuffer, 0, sizeof(abBuffer));
      lRet = xChannelExtendedStatusBlock( hDevice, CIFX_CMD_READ_DATA, 0, 4, &abBuffer[0]);
      DumpData(abBuffer, 4);

      printf("Write EXTENDED Status Block \r\n");
      lRet = xChannelExtendedStatusBlock( hDevice, CIFX_CMD_WRITE_DATA, 0, 4, &abBuffer[0]);

      /* this is expected to fail, as this block must not be written by Host */
      if(CIFX_NO_ERROR != lRet)
        printf("Error writing to extended status block. lRet = 0x%08X\r\n", (unsigned int)lRet);

      xChannelClose(hDevice);
    }
    xDriverClose(hDriver);
  }
  return lRet;
}


/*****************************************************************************/
/*! Function to demonstrate bus / host state
*   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
int32_t StateDemo (void)
{
  CIFXHANDLE    hDriver  = NULL;
  CIFXHANDLE    hChannel = NULL;
  int32_t       lRet     = xDriverOpen(&hDriver);

  printf("\n--- Set Bus / Host State Demo ---\n");

  if (CIFX_NO_ERROR == lRet)
  {
    /* Open channel */
    if( CIFX_NO_ERROR != (lRet = xChannelOpen(hDriver, "cifX0", 0, &hChannel)))
    {
      printf("Error opening Channel!\n");

    } else
    {
      uint32_t ulState  = 0;

      /* Set Host ready */
      lRet = xChannelHostState( hChannel, CIFX_HOST_STATE_READY, &ulState, 1000);
      if (CIFX_NO_ERROR != lRet)
        printf("Error CIFX_HOST_STATE_READY, state %lu, error 0x%08X !\n", (long unsigned int)ulState, (unsigned int)lRet);
      else
        printf("Set CIFX_HOST_STATE_READY!\n");

      /* Get Host state */
      lRet = xChannelHostState( hChannel, CIFX_HOST_STATE_READ, &ulState, 1000);
      if (CIFX_NO_ERROR != lRet)
        printf("Error CIFX_HOST_STATE_READ, state %lu, error 0x%08X !\n", (long unsigned int)ulState, (unsigned int)lRet);
      else
        printf("CIFX_HOST_STATE_READ, state %lu !\n", (long unsigned int)ulState);

      /* Set Bus state on */
      lRet = xChannelBusState  (hChannel, CIFX_BUS_STATE_ON, &ulState, 1000);
      if (CIFX_NO_ERROR != lRet)
        printf("Error CIFX_BUS_STATE_ON, state %lu, error 0x%08X !\n", (long unsigned int)ulState, (unsigned int)lRet);
      else
        printf("CIFX_BUS_STATE_ON, state %lul !\n", (long unsigned int)ulState);

      /* Set Bus state off */
      lRet = xChannelBusState  (hChannel, CIFX_BUS_STATE_OFF, &ulState, 1000);
      if (CIFX_NO_ERROR != lRet)
        printf("Error CIFX_BUS_STATE_OFF, state %lu, error 0x%08X !\n", (long unsigned int)ulState, (unsigned int)lRet);
      else
        printf("CIFX_BUS_STATE_OFF, state %lu !\n", (long unsigned int)ulState);

      /* Set Host not ready */
      lRet = xChannelHostState(hChannel, CIFX_HOST_STATE_NOT_READY, &ulState, 1000);
      if (CIFX_NO_ERROR != lRet)
        printf("Error CIFX_HOST_STATE_NOT_READY, state %lu, error 0x%08X !\n", (long unsigned int)ulState,(unsigned int)lRet);
      else
        printf("Set CIFX_HOST_STATE_NOT_READY!\n");

      /* Get Host state */
      lRet = xChannelHostState( hChannel, CIFX_HOST_STATE_READ, &ulState, 1000);
      if (CIFX_NO_ERROR != lRet)
        printf("Error CIFX_HOST_STATE_READ, state %lu, error 0x%08X !\n", (long unsigned int)ulState, (unsigned int)lRet);
      else
        printf("CIFX_HOST_STATE_READ, state %lu !\n", (long unsigned int)ulState);

      xChannelClose(hChannel);
    }
    xDriverClose(hDriver);
  }
  printf(" State = 0x%08X\n", (unsigned int)lRet);
  printf("----------------------------------------------------\n");

  return lRet;
}


/*****************************************************************************/
/*! Function to demonstrate event handling
*   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
void TestEventHandling(void)
{
  CIFXHANDLE    hDriver  = NULL;
  CIFXHANDLE    hDevice  = NULL;
  int32_t       lRet     = xDriverOpen(&hDriver);
  int           iIdx     = 0;

  printf("\n--- Event handling demo ---\r\n");

  /* Open channel */
  if (CIFX_NO_ERROR == lRet)
  {
    lRet = xChannelOpen(hDriver, "cifX0", 0, &hDevice);
    if(lRet != CIFX_NO_ERROR)
    {
      /* Read driver error description */
      ShowError( lRet);
    } else
    {
      uint32_t           ulState    = 0;
      SYNC_CALLBACK_DATA tSynchData = {0};

      tSynchData.hDevice  = hDevice;
      /* Register for events */
      if( (CIFX_NO_ERROR != (lRet = xChannelRegisterNotification( hDevice, CIFX_NOTIFY_RX_MBX_FULL,   EventCallback,      (void*)1))) ||
          (CIFX_NO_ERROR != (lRet = xChannelRegisterNotification( hDevice, CIFX_NOTIFY_TX_MBX_EMPTY,  EventCallback,      (void*)2))) ||
          (CIFX_NO_ERROR != (lRet = xChannelRegisterNotification( hDevice, CIFX_NOTIFY_PD0_IN,        EventCallback,      (void*)3))) ||
          (CIFX_NO_ERROR != (lRet = xChannelRegisterNotification( hDevice, CIFX_NOTIFY_PD0_OUT,       EventCallback,      (void*)5))) ||
          (CIFX_NO_ERROR != (lRet = xChannelRegisterNotification( hDevice, CIFX_NOTIFY_SYNC,          SyncEventCallback,  (void*)&tSynchData))) )
      {
        /* Failed to register one of the events */
        /* Read driver error description        */
        ShowError( lRet);
      } else
      {
        /* Get actual host state */
        if( (lRet = xChannelHostState( hDevice, CIFX_HOST_STATE_READ, &ulState, 0L)) != CIFX_NO_ERROR)
        {
          /* Read driver error description */
          ShowError( lRet);
        }

        /* Set host ready */
        if( (lRet = xChannelHostState( hDevice, CIFX_HOST_STATE_READY, NULL, 2000L)) != CIFX_NO_ERROR)
        {
          /* Read driver error description */
          ShowError( lRet);
        }

        for (iIdx=0; iIdx<10; iIdx++)
        {
          CIFX_PACKET tSendPkt = {{0}};
          xChannelPutPacket(hDevice, &tSendPkt, 10);
          xChannelIORead(hDevice, 0, 0, sizeof(tSendPkt), &tSendPkt, 10);
          xChannelIOWrite(hDevice, 0, 0, sizeof(tSendPkt), &tSendPkt, 10);
        }

        /*-------------------*/
        /* Unregister Events */
        /*-------------------*/
        lRet = xChannelUnregisterNotification( hDevice, CIFX_NOTIFY_RX_MBX_FULL);
        if( CIFX_NO_ERROR != lRet)
          printf("Error in Unregister CIFX_NOTIFY_RX_MBX_FULL event, Error = 0x%08X", (unsigned int)lRet);

        lRet = xChannelUnregisterNotification( hDevice, CIFX_NOTIFY_TX_MBX_EMPTY);
        if( CIFX_NO_ERROR != lRet)
          printf("Error in Unregister CIFX_NOTIFY_TX_MBX_EMPTY event, Error = 0x%08X", (unsigned int)lRet);

        lRet = xChannelUnregisterNotification( hDevice, CIFX_NOTIFY_PD0_IN);
        if( CIFX_NO_ERROR != lRet)
          printf("Error in Unregister CIFX_NOTIFY_PD0_IN event, Error = 0x%08X", (unsigned int)lRet);

        lRet = xChannelUnregisterNotification( hDevice, CIFX_NOTIFY_PD0_OUT);
        if( CIFX_NO_ERROR != lRet)
          printf("Error in Unregister CIFX_NOTIFY_PD0_OUT event, Error = 0x%08X", (unsigned int)lRet);

        lRet = xChannelUnregisterNotification( hDevice, CIFX_NOTIFY_SYNC);
        if( CIFX_NO_ERROR != lRet)
          printf("Error in Unregister CIFX_NOTIFY_SYNC event, Error = 0x%08X", (unsigned int)lRet);
      }

      /* Close channel */
      if( hDevice != NULL)
        xChannelClose(hDevice);
    }
    xDriverClose(hDriver);
  }
}


/*****************************************************************************/
/*! Main entry function
*   \return 0                                                                */
/*****************************************************************************/
int main(int argc, char* argv[])
{
  struct CIFX_DEVICE_T   tISADevice  = {0};
  struct CIFX_LINUX_INIT tDriverInit = {0};
  int32_t                lRet        = 0;
  int                    iISAfd      = 0;
  int                    fSucess     = 0;

  printf("ISA demo started...\n");
  /********************************************/
  /*** ISA - DEVICE SETUP                   ***/
  /********************************************/
  /* for detailed information of parameter of 'tISADevice' refer to the linux driver documentation */
  /* TODO: set 'dpmaddr' and 'dpmlen' according to the device and the configured address */
  tISADevice.dpmaddr = 0xD0000;    /*!< physical address to DPM of the ISA device, need to be set according to the system */
  tISADevice.dpmlen  = 0x4000;     /*!< length of DPM in bytes, depends on the device                                     */

  /* since device is not a uio device and no pci card invalidate all parameter */
  tISADevice.uio_num   = -1;     /*!< uio number, -1 for non-uio devices      */
  tISADevice.uio_fd    = -1;     /*!< uio file handle, -1 for non-uio devices */
  tISADevice.pci_card  = 0;      /*!< device is not a pci card */
  tISADevice.force_ram = 0;      /*!< Force usage of RAM instead of flash. Card will always be reset and all
                                     files are downloaded again */
  /* we are not interrested in any configuration state, so set parameter to NULL */
  tISADevice.notify    = NULL;  /*!< Function to call, after the card has passed several stages (usually needed on RAM based
                                     devices, that change DPM configuration during initialization) */
  tISADevice.userparam = NULL;  /*!< User specific parameter (e.g. identifier for manual added devices */
  /* there is no extra memory */
  tISADevice.extmem     = NULL; /*!< virtual pointer to extended memory  */
  tISADevice.extmemaddr = 0x00; /*!< physical address to extended memory */
  tISADevice.extmemlen  = 0;    /*!< Length of extended memory in bytes  */

  /********************************************/
  /*** PREPARE ISA ACCESS                   ***/
  /********************************************/
  /* Open the system memory file (/dev/mem). Required to map the memory of the ISA device. */
  if ((iISAfd = cifx_ISA_open())<0)
  {
    printf("Error opening the system memory (%s). Required to map the memory of the ISA device!\n", strerror(errno));
    return -1;
  }
  printf("Try to map the physical dpm address to a virtual memory, accessible by the application...\n");
  if ((fSucess = cifx_ISA_map_dpm( iISAfd,
                                 (void**)&tISADevice.dpm,
                                 tISADevice.dpmaddr,
                                 tISADevice.dpmlen))<0)
  {
    printf("Error mapping dpm (%s)!\n", strerror(errno));
    cifx_ISA_close( iISAfd);
    return -1;
  } else
  {
    printf("Mapping succeded!\n");
    /********************************************/
    /*** GENERIC DRIVER INITIALIZATION        ***/
    /********************************************/
    /* setup the standard driver initializaion structure (for detailed information refer to the linux driver documentation) */
    tDriverInit.init_options        = CIFX_DRIVER_INIT_NOSCAN; /* no scan required, we only want to initialize the 'tISADevice' device */
    tDriverInit.iCardNumber         = 0;
    tDriverInit.fEnableCardLocking  = 0;
    tDriverInit.base_dir            = NULL;
    tDriverInit.poll_interval       = 0;
    tDriverInit.poll_StackSize      = 0;
    tDriverInit.trace_level         = 255;
    tDriverInit.user_card_cnt       = 1;
    tDriverInit.user_cards          = &tISADevice; /* the previously prepared ISA device */

    printf("Try to initialize the cifX driver...\n");
    /* initialize driver */
    lRet = cifXDriverInit(&tDriverInit);

    if(CIFX_NO_ERROR == lRet)
    {
      printf("Successfully initialized the driver. Start demo...\n");
      /* Display version of cifXRTXDrv and cifXToolkit */
      DisplayDriverInformation();

      /* Demonstrate the board/channel enumeration */
      EnumBoardDemo();

      /* Demonstrate system channel functionality */
      SysdeviceDemo();

      /* Demonstrate communication channel functionality */
      ChannelDemo();

      /* Demonstrate control/status block functionality */
      BlockDemo();

      /* Demonstrate event handling */
      TestEventHandling();

      /* Demonstrate host/bus state functions */
      StateDemo ();
    } else
    {
      printf("Failed to initialize the driver lRet=0x%X\n",lRet);
    }
  }
  /* de-initilize driver */
  cifXDriverDeinit();
  /* unmap and close system memory */
  cifx_ISA_unmap_dpm( tISADevice.dpm, tISADevice.dpmlen);
  cifx_ISA_close( iISAfd);

  printf("...ISA demo ended\n");

  return 0;
}
