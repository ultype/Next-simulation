/**************************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 **************************************************************************************

   Filename:
    $Id: TCPServer.h 1206 2010-04-15 11:59:09Z sebastiand $
   Last Modification:
    $Author: sebastiand $
    $Date: 2010-04-15 13:59:09 +0200 (Thu, 15 Apr 2010) $
    $Revision: 1206 $

   Targets:
     Linux        : yes
     
   Description:
    Server handling

   Changes:

     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
     1        02.06.2010   SD       initial version

**************************************************************************************/


#ifndef __TCPSERVER__H
#define __TCPSERVER__H

#ifdef __cplusplus
  extern "C" {
#endif


/*****************************************************************************/
/*! Internal UART connector data                                             */
/*****************************************************************************/
typedef struct TCP_CONN_INTERNAL_Ttag
{
TLR_UINT32 ulConnectorIdx;
void*      pvMarshaller;

int        fRunning;

SOCKET     hListen;
pthread_t  hServerThread;

SOCKET        hClient;
pthread_t     hClientThread;
unsigned long ulRxCount;
unsigned long ulTxCount;

} TCP_CONN_INTERNAL_T;



void        TrafficTimer                (void* dwUser);
void        MarshallerTimer             (int iSignal);
int32_t     APIENTRY xSysdeviceOpenWrap (CIFXHANDLE  hDriver, char*   szBoard, CIFXHANDLE* phSysdevice);
int32_t     APIENTRY xSysdeviceOpenWrap (CIFXHANDLE  hDriver, char*   szBoard, CIFXHANDLE* phSysdevice);
int32_t     APIENTRY xChannelOpenWrap   (CIFXHANDLE  hDriver,  char* szBoard, uint32_t ulChannel, CIFXHANDLE* phChannel);
int32_t     APIENTRY xChannelCloseWrap  (CIFXHANDLE  hChannel);
void        MarshallerRequest           (void* pvMarshaller, void* pvUser);
TLR_RESULT  InitMarshaller              (void);
void        DeinitMarshaller            (void);

#ifdef __cplusplus
  }
#endif

#endif /* __TCPSERVER__H */








 
