/**************************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 **************************************************************************************

   Filename:
    $Id: TCPConnector.cpp 1206 2010-04-15 11:59:09Z stephans $
   Last Modification:
    $Author: stephans $
    $Date: 2010-04-15 13:59:09 +0200 (Thu, 15 Apr 2010) $
    $Revision: 1206 $

   Targets:
     Linux        : yes

   Description:
    TCP/IP connector for Hilscher marshaller package

   Changes:

     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
     4        25.05.2010   SD       - initial linux-version

     3        15.04.2010   SS       - Timeout handling added to close client after 5
                                      seconds of inactivity
                                    - Bugfix: Application crashes if loading of cifX
                                      device driver failed
     2        04.12.2009   SS       - Query client name
                                    - Show TCP traffic via timer event
     1        25.05.2009   MT       initial version

**************************************************************************************/

#include <stdio.h>
#include <limits.h>
#include <pthread.h>
#include <unistd.h>

#include "TCPConnector.h"

extern void*          g_pvMarshaller;
  /* flag to display once the network traffic */
extern int            g_fTrafficOnce;

extern unsigned short g_usPortNumber;

/*****************************************************************************/
/*! Function called from marshaller when data is to be sent to interface
*   \param ptBuffer   Buffer to send
*   \param pvUser     TCP connector internal data                            */
/*****************************************************************************/
static TLR_RESULT TCPConnectorSend(HIL_MARSHALLER_BUFFER_T* ptBuffer, void* pvUser)
{
  TCP_CONN_INTERNAL_T* ptTcpData = (TCP_CONN_INTERNAL_T*)pvUser;
  unsigned long        ulDataLen = sizeof(ptBuffer->tTransport) +
                                   ptBuffer->tMgmt.ulUsedDataBufferLen;

  ptTcpData->ulTxCount += ulDataLen;

  send(ptTcpData->hClient,
       (char*)&ptBuffer->tTransport,
       ulDataLen,
       0);

  HilMarshallerConnTxComplete(ptBuffer->tMgmt.pvMarshaller,
                              ptTcpData->ulConnectorIdx,
                              ptBuffer);

  return TLR_S_OK;
}

/*****************************************************************************/
/*! TCP connector uninitialization
*   \param pvUser Pointer to internal connector data                         */
/*****************************************************************************/
static void TCPConnectorDeinit(void* pvUser)
{
  TCP_CONN_INTERNAL_T* ptTcpData = (TCP_CONN_INTERNAL_T*)pvUser;

  /* Check if data is valid */
  if(NULL != ptTcpData)
  {
    pthread_t hClientThread = ptTcpData->hClientThread;
    ptTcpData->fRunning  = 0;

    if(0 != hClientThread)
    {
      pthread_join(ptTcpData->hClientThread,NULL);
    }

    if(INVALID_SOCKET != ptTcpData->hClient)
      close(ptTcpData->hClient);

    if(0 != ptTcpData->hServerThread)
    {
      pthread_join(ptTcpData->hServerThread,NULL);
    }

    if(INVALID_SOCKET != ptTcpData->hListen)
      close(ptTcpData->hListen);

    /* Unregister from Marshaller */
    if(ptTcpData->ulConnectorIdx != (unsigned long int)~0)
    {
      HilMarshallerUnregisterConnector(ptTcpData->pvMarshaller, ptTcpData->ulConnectorIdx);
    }

    free(ptTcpData);
  }

}

/*****************************************************************************/
/*! Thread handling connection with client
*   \param pvParam Pointer reference to TCP connection structure
*   \return        Always 0                                                  */
/*****************************************************************************/
void* ClientThread(void* pvParam)
{
  TCP_CONN_INTERNAL_T* ptTcpData = (TCP_CONN_INTERNAL_T*)pvParam;

  /* add here code to create timer event to display network traffic
  callback function -> TrafficTimer */

  while(ptTcpData->fRunning)
  {
    TYPE_FD_SET  tRead, tExcept;
    struct timeval tTimeout = {0};

    tTimeout.tv_sec = 5;

    FD_ZERO(&tRead);
    FD_ZERO(&tExcept);

    FD_SET(ptTcpData->hClient, &tRead);
    FD_SET(ptTcpData->hClient, &tExcept);

    int iErr = select(ptTcpData->hClient + 1, &tRead, NULL, &tExcept, &tTimeout);
    if(0 < iErr)
    {
      if(FD_ISSET(ptTcpData->hClient, &tRead))
      {
        /* We have data to read */
        unsigned long  ulDataLen;
        unsigned char* pbData;
        int            iRecv;

        ioctl(ptTcpData->hClient,FIONREAD,&ulDataLen);

        pbData    = (unsigned char*)malloc(ulDataLen);

        iRecv = recv(ptTcpData->hClient, (char*)pbData, ulDataLen, 0);

        if( (SOCKET_ERROR == iRecv) ||
            (0            == iRecv) )
        {
          /* Gracefully closed socket */
          ptTcpData->hClient = INVALID_SOCKET;
          free(pbData);
          break;

        } else
        {
          unsigned long ulDataLen = (unsigned long)iRecv;

          ptTcpData->ulRxCount += ulDataLen;

          HilMarshallerConnRxData(ptTcpData->pvMarshaller,
                                  ptTcpData->ulConnectorIdx,
                                  pbData,
                                  ulDataLen);
        }

        /* Exmaple: show traffic (but only call it once) */
        /* its better to call it in a cyclic timer function, like noted above*/
        if (!g_fTrafficOnce) TrafficTimer((void*)ptTcpData);

        free(pbData);
      }

      if(FD_ISSET(ptTcpData->hClient, &tExcept))
      {
        /* Socket has been closed */
        ptTcpData->hClient = INVALID_SOCKET;
        break;
      }
    } else if (iErr == 0)
    {
      /* Timeout -> close socket */
      close(ptTcpData->hClient);
      ptTcpData->hClient = INVALID_SOCKET;
      break;
    }
  }

  ptTcpData->hClientThread = 0;

  /* add code here to Kill network traffic timer event */
  printf("Connection closed!\n");

  return 0;
}

/*****************************************************************************/
/*! Thread serving incoming TCP connections
*   \param pvParam Pointer reference to TCP connection structure
*   \return        Always 0                                                  */
/*****************************************************************************/
void* ServerThread(void* pvParam)
{
  TCP_CONN_INTERNAL_T* ptTcpData = (TCP_CONN_INTERNAL_T*)pvParam;

  while(ptTcpData->fRunning)
  {
    TYPE_FD_SET        tRead;
    struct timeval tTimeout = {0};

    tTimeout.tv_sec = 1;

    FD_ZERO(&tRead);
    FD_SET(ptTcpData->hListen, &tRead);


    if(0 < select(ptTcpData->hListen + 1, &tRead, NULL, NULL, &tTimeout))
    {
      if(FD_ISSET(ptTcpData->hListen, &tRead))
      {
        /* We have a client to accept */
        struct sockaddr_in tSockAddr  = {0};
        socklen_t iSockAddrLen = sizeof(tSockAddr);

        SOCKET      hClient      = accept(ptTcpData->hListen, (struct sockaddr*)&tSockAddr, &iSockAddrLen);

        if(ptTcpData->hClient != INVALID_SOCKET)
        {
          /* We already have a client, so reject this one */
          close(hClient);
        } else
        {
          char  szHostname[NI_MAXHOST];

          ptTcpData->ulRxCount = 0;
          ptTcpData->ulTxCount = 0;

          /* print host-ip */
          printf("Connected with client : %s\n", inet_ntoa(tSockAddr.sin_addr));

          /* Query remote name */
          if (0 == getnameinfo( (struct sockaddr *) &tSockAddr, sizeof (struct sockaddr),
                                szHostname,NI_MAXHOST, NULL, 0, 0))
          {
            printf("Host Name : %s\n", szHostname);

          } else
          {
            printf("Host unknown!\n");
          }

          int iNoDelay = 1;
          if ( setsockopt(hClient, IPPROTO_TCP, TCP_NODELAY, (void*)&iNoDelay, sizeof(iNoDelay)) != 0 )
          {
            printf("The server is not able to send small packets.\n");
            printf("So the communication could be very slow!\n");
          }

          ptTcpData->hClient       = hClient;
          pthread_create(&ptTcpData->hClientThread, NULL,ClientThread, (void*)ptTcpData);
        }
      }
    }
  }

  return 0;
}

/*****************************************************************************/
/*! TCP connector initialization
*   \param ptParams     Marshaller specific parameters (e.g. timeout)
*   \param ptConfigData UART configuration data
*   \param pvMarshaller Handle to the marshaller, this connector should be added
*   \return TLR_S_OK on success                                              */
/*****************************************************************************/
TLR_RESULT TCPConnectorInit(const HIL_MARSHALLER_CONNECTOR_PARAMS_T* ptParams, void* pvMarshaller)
{
  HIL_MARSHALLER_CONNECTOR_T tMarshConn;
  TCP_CONN_INTERNAL_T*       ptTcpData = NULL;
  TLR_RESULT                 eRet;

  if(NULL == (ptTcpData = (TCP_CONN_INTERNAL_T*)malloc(sizeof(*ptTcpData))))
  {
    eRet = HIL_MARSHALLER_E_OUTOFMEMORY;
  } else
  {
    struct sockaddr_in tSockAddr = {0};

    memset(&tMarshConn, 0, sizeof(tMarshConn));
    memset(ptTcpData, 0, sizeof(*ptTcpData));

    ptTcpData->ulConnectorIdx = (TLR_UINT32)~0;
    ptTcpData->pvMarshaller   = pvMarshaller;
    ptTcpData->hClient        = INVALID_SOCKET;
    ptTcpData->fRunning       = 1;

    tSockAddr.sin_addr.s_addr = INADDR_ANY;
    tSockAddr.sin_port        = htons(g_usPortNumber);
    tSockAddr.sin_family      = AF_INET;

    if(INVALID_SOCKET == (ptTcpData->hListen = socket(AF_INET, SOCK_STREAM, 0)))
    {
      eRet = HIL_MARSHALLER_E_OUTOFRESOURCES;

    } else if(SOCKET_ERROR == bind(ptTcpData->hListen, (struct sockaddr*)&tSockAddr, sizeof(tSockAddr)))
    {
      eRet = HIL_MARSHALLER_E_OUTOFRESOURCES;

    } else if(SOCKET_ERROR == listen(ptTcpData->hListen, 0))
    {
      eRet = HIL_MARSHALLER_E_OUTOFRESOURCES;

    } else if (0 != (pthread_create(&ptTcpData->hServerThread, NULL,ServerThread, (void*)ptTcpData)))
    {
      eRet = HIL_MARSHALLER_E_OUTOFRESOURCES;

    } else
    {
      tMarshConn.pfnTransmit      = TCPConnectorSend;
      tMarshConn.pfnDeinit        = TCPConnectorDeinit;
      tMarshConn.pvUser           = ptTcpData;
      tMarshConn.ulDataBufferSize = ptParams->ulDataBufferSize;
      tMarshConn.ulDataBufferCnt  = ptParams->ulDataBufferCnt;
      tMarshConn.ulTimeout        = ptParams->ulTimeout;

      eRet = HilMarshallerRegisterConnector(pvMarshaller,
                                            &ptTcpData->ulConnectorIdx,
                                            &tMarshConn);

    }

    /* Something has failed, so uninitialize this connector instance */
    if(eRet != TLR_S_OK)
    {
      TCPConnectorDeinit(ptTcpData);
    }
  }

  return eRet;
}
