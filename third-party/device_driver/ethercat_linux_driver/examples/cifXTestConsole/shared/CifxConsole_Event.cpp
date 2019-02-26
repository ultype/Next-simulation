/**************************************************************************************
 
   Copyright (c) Hilscher GmbH. All Rights Reserved.
 
 **************************************************************************************
 
   Filename:
    $Workfile: CifxConsole_Event.cpp
   Last Modification:
    $Author: $
    $Modtime: $
    $Revision: $
   
   Targets:
     Win32/ANSI   : no
     Win32/Unicode: no
     WinCE 5      : yes
     WinCE 6      : yes
     Linux        : yes
 
   Description:
     Windows CE OS Abstraction Layer implementation.
       
   Changes:
 
     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
     1         21.07.2010  RM       initial version
 
     
**************************************************************************************/
#include "OS_Includes.h"
#include "CifXConsole.h"
#include "rX_Results.h"

void* s_pvLock; 


/*===========================================================================*/
/* Set SYNC Mode                                                             */
/*  \param hDevice                                                           */
/*                                                                           */
/*===========================================================================*/
int32_t SetSyncMode (CIFXHANDLE hDevice)
{
  RCX_SET_HANDSHAKE_CONFIG_REQ_T tRequest       = {{0}};
  RCX_SET_HANDSHAKE_CONFIG_CNF_T tConfirmation  = {{0}};

  tRequest.tHead.ulSrc  = 0x00000001;              // My identification
  tRequest.tHead.ulDest = RCX_PACKET_DEST_DEFAULT_CHANNEL;    
  tRequest.tHead.ulCmd  = RCX_SET_HANDSHAKE_CONFIG_REQ;
  tRequest.tHead.ulLen  = sizeof(RCX_SET_HANDSHAKE_CONFIG_REQ_DATA_T);

  tRequest.tData.bPDInHskMode   = RCX_IO_MODE_BUFF_HST_CTRL;
  tRequest.tData.bPDInSource    = 0;
  tRequest.tData.bPDOutHskMode  = RCX_IO_MODE_BUFF_HST_CTRL;
  tRequest.tData.bPDOutSource   = 0;
  tRequest.tData.usPDInErrorTh  = 0;
  tRequest.tData.usPDOutErrorTh = 0;
  tRequest.tData.usSyncErrorTh  = 0;
  tRequest.tData.bSyncHskMode   = RCX_SYNC_MODE_HST_CTRL;
  tRequest.tData.bSyncSource    = RCX_SYNC_SOURCE_1;

  int32_t lRet = xChannelPutPacket(hDevice, (CIFX_PACKET*)&tRequest, 1000);
  ShowError(lRet);

  
  if(CIFX_NO_ERROR == lRet)
  {
    lRet = xChannelGetPacket(hDevice, sizeof(CIFX_PACKET), (CIFX_PACKET*)&tConfirmation, 1000);

    if( CIFX_NO_ERROR != lRet) 
    {
      ShowError(lRet);
    } else
    {
      // Packet error
      if( RCX_S_OK != (lRet = tConfirmation.tHead.ulSta))
      {
        if ( lRet == HAL_HIF_FUNCTION_ALREADY_INITIALIZED)
          lRet = RCX_S_OK;
        else 
        {
          printf("\n\r ERROR in CONFIG packet, tHeader.Status = 0x%08X\r\n", lRet);
        }
      }
    }
  }

  return lRet;
}

/*===========================================================================*/
/* Event Callback                                                            */
/*  \param ulNotification                                                    */
/*  \param ulDataLen                                                         */
/*  \param pvData                                                            */
/*  \param pvUser                                                            */
/*                                                                           */
/*===========================================================================*/
void APIENTRY EventCallbackFnc (uint32_t ulNotification, uint32_t ulDataLen, void* pvData, void* pvUser)
{
  UNREFERENCED_PARAMETER( pvUser);
  UNREFERENCED_PARAMETER( pvData);
  UNREFERENCED_PARAMETER( ulDataLen);

  OS_EnterLock(s_pvLock);   // Necessary for printf() */

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

    case CIFX_NOTIFY_COM_STATE:
      printf("EventCallback(): CIFX_NOTIFY_COM_STATE\n");
    break;
    
    default:
      printf("EventCallback(): UNKNOWN Event, Event number %u\n", ulNotification);
    break;
  }  
  
  OS_LeaveLock(s_pvLock);
}

typedef struct SYNC_CALLBACK_DATAtag
{
  CIFXHANDLE hDevice;
} SYNC_CALLBACK_DATA;

SYNC_CALLBACK_DATA tSynchData = {0};


/*===========================================================================*/
/* SyncEventCallback                                                         */
/*  \param ulNotification                                                    */
/*  \param ulDataLen                                                         */
/*  \param pvData                                                            */
/*  \param pvUser                                                            */
/*                                                                           */
/*===========================================================================*/
void APIENTRY SyncEventCallback (uint32_t /*ulNotification*/, uint32_t /*ulDataLen*/, void* /*pvData*/, void* /*pvUser*/)
{
  //UNREFERENCED_PARAMETER( pvUser);
  //UNREFERENCED_PARAMETER( pvData);
  //UNREFERENCED_PARAMETER( ulDataLen);
  //UNREFERENCED_PARAMETER( ulNotification);

  //uint32_t ulErrorCount = 0;
  //long     lRet         = 0;
  //
  //SYNC_CALLBACK_DATA* ptSynchData = (SYNC_CALLBACK_DATA*)pvUser;
  //
  //if(!fStart)
  //{
  //  EnterCriticalSection(&cLock);   // Necessary for printf() */
  //  printf("SyncCallback()\n");
  //  fStart = TRUE;
  //  LeaveCriticalSection(&cLock);   // Necessary for printf() */
  //}
  //
  //QueryPerformanceCounter( (LARGE_INTEGER*)&tPerfData[bPerfIdx].liCounterStart);

  //lRet = xChannelSyncState( ptSynchData->hDevice, CIFX_SYNC_ACKNOWLEDGE_CMD, 0, &ulErrorCount);
  //if(CIFX_NO_ERROR != lRet)
  //{
  //  printf("Error signaling the Sync, lRet = 0x%08x\n",lRet);
  //} else
  //{
  //  QueryPerformanceCounter( (LARGE_INTEGER*)&tPerfData[bPerfIdx].liCounterStop);
  //  if(++bPerfIdx >= PERF_DATA_COUNT)
  //    bPerfIdx = 0;
  //}
}


/*===========================================================================*/
/* Event handling test                                                       */
/*                                                                           */
/*                                                                           */
/*===========================================================================*/
void TestEventHandling(CIFXHANDLE hDriver, char* szBoard)
{
  int32_t   lRet          = CIFX_NO_ERROR;
  uint32_t  ulErrorCount  = 0;

  printf("\n--- Test Event Handling ---\r\n");  

  /* Create critical section for printf() handling */
  s_pvLock = OS_CreateLock();
  
  // Open channel
  CIFXHANDLE hDevice = NULL;
  
  lRet = xChannelOpen(hDriver, szBoard, 0, &hDevice);
  if(lRet != CIFX_NO_ERROR)
  {
    // Read driver error description
    ShowError( lRet);
  } else
  {
    uint32_t ulState = 0;

    tSynchData.hDevice = hDevice;
    
    // Set the master Sync mode
    if( CIFX_NO_ERROR == (lRet = SetSyncMode(hDevice)))
    {

      // Register for events 
      if( (CIFX_NO_ERROR != (lRet = xChannelRegisterNotification( hDevice, CIFX_NOTIFY_RX_MBX_FULL,   EventCallbackFnc,      (void*)1))) ||
          (CIFX_NO_ERROR != (lRet = xChannelRegisterNotification( hDevice, CIFX_NOTIFY_TX_MBX_EMPTY,  EventCallbackFnc,      (void*)2))) ||   
          (CIFX_NO_ERROR != (lRet = xChannelRegisterNotification( hDevice, CIFX_NOTIFY_PD0_IN,        EventCallbackFnc,      (void*)3))) ||  
          (CIFX_NO_ERROR != (lRet = xChannelRegisterNotification( hDevice, CIFX_NOTIFY_PD0_OUT,       EventCallbackFnc,      (void*)5))) ||
          (CIFX_NO_ERROR != (lRet = xChannelRegisterNotification( hDevice, CIFX_NOTIFY_COM_STATE,     EventCallbackFnc,      (void*)6))) ||
          (CIFX_NO_ERROR != (lRet = xChannelRegisterNotification( hDevice, CIFX_NOTIFY_SYNC,          SyncEventCallback,  (void*)&tSynchData))) )
      {
        // Failed to register one of the events */
        // Read driver error description
        OS_EnterLock(s_pvLock);
        ShowError( lRet);
        OS_LeaveLock(s_pvLock);
      } else
      {
        /* Get actual host state */
        if( (lRet = xChannelHostState( hDevice, CIFX_HOST_STATE_READ, &ulState, 0L)) != CIFX_NO_ERROR)
        {
          // Read driver error description
          OS_EnterLock(s_pvLock);
          ShowError( lRet);
          OS_LeaveLock(s_pvLock);
        }
        
        /* Set host ready */
        if( (lRet = xChannelHostState( hDevice, CIFX_HOST_STATE_READY, NULL, 2000L)) != CIFX_NO_ERROR)
        {
          // Read driver error description
          OS_EnterLock(s_pvLock);
          ShowError( lRet);
          OS_LeaveLock(s_pvLock);
        }
        
        /*-------------------*/
        /* Wait for user     */
        /*-------------------*/
        OS_EnterLock(s_pvLock);

        printf("\n\r EVENT-Handling activ! Press (Q) to stop... \r\n");

        OS_LeaveLock(s_pvLock);
        
        do 
        {
          lRet = xChannelSyncState( hDevice, CIFX_SYNC_SIGNAL_CMD, 10, &ulErrorCount);
          if(CIFX_NO_ERROR != lRet)
          {
            printf("Error signaling the Sync, lRet = 0x%08X\n",lRet);
          }  

          OS_Sleep(10);

      	}while(!OS_KbHit());
      }

      /*-------------------*/
      /* Unregister Events */
      /*-------------------*/
      lRet = xChannelUnregisterNotification( hDevice, CIFX_NOTIFY_RX_MBX_FULL);
      if( CIFX_NO_ERROR != lRet)
      {
        printf("xChannelUnregisterNotification() CIFX_NOTIFY_RX_MBX_FULL\n\r");
        ShowError(lRet);
      }
        
      lRet = xChannelUnregisterNotification( hDevice, CIFX_NOTIFY_TX_MBX_EMPTY);
      if( CIFX_NO_ERROR != lRet)
      {
        printf("xChannelUnregisterNotification() CIFX_NOTIFY_TX_MBX_EMPTY\n\r");
        ShowError(lRet);
      }
      
      lRet = xChannelUnregisterNotification( hDevice, CIFX_NOTIFY_PD0_IN);
      if( CIFX_NO_ERROR != lRet)
      {
        printf("xChannelUnregisterNotification() CIFX_NOTIFY_PD0_IN\n\r");
        ShowError(lRet);
      }

      lRet = xChannelUnregisterNotification( hDevice, CIFX_NOTIFY_PD0_OUT);
      if( CIFX_NO_ERROR != lRet)
      {
        printf("xChannelUnregisterNotification() CIFX_NOTIFY_PD0_OUT\n\r");
        ShowError(lRet);
      }
      
      lRet = xChannelUnregisterNotification( hDevice, CIFX_NOTIFY_SYNC);
      if( CIFX_NO_ERROR != lRet)
      {
        printf("xChannelUnregisterNotification() CIFX_NOTIFY_SYNC\n\r");
        ShowError(lRet);
      }

      lRet = xChannelUnregisterNotification( hDevice, CIFX_NOTIFY_COM_STATE);
      if( CIFX_NO_ERROR != lRet)
      {
        printf("xChannelUnregisterNotification() CIFX_NOTIFY_COM_STATE\n\r");
        ShowError(lRet);
      }
    }

    // Close channel
    if( hDevice != NULL) 
      xChannelClose(hDevice);

  }      
  
  /* Delete critical section for printf() handling */
  OS_DeleteLock(s_pvLock);  
  

  printf("\n Test done\r\n"); 
}

