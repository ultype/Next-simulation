/**************************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 **************************************************************************************

   Filename:
    $Id: HilMarshaller.c 7057 2015-07-21 08:16:50Z LuisContreras $
   Last Modification:
    $Author: LuisContreras $
    $Date: 2015-07-21 10:16:50 +0200 (Tue, 21 Jul 2015) $
    $Revision: 7057 $

   Targets:
     OS independent : yes

   Description:
    Hilscher Transport marshalling main module

   Changes:

     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
     18       16.07.2015   RM       Change:
                                     - Adapted to new APIHeader directory and MarshallerFrame.h
     17       06.05.2013   MT       Bugfix:
                                     - ACK's or zero length packets, may be send with a checksum (!=0)
     16       06.07.2010   MT       Change:
                                     - Re-Added Tx buffers, which were never unused in Packet Transport (on rcX)
                                     - Added ulTxBufferSize / ulTxBufferSize on connector registration to setup
                                       Tx Buffer usage (if needed)
     15       23.09.2009   MS       Change:
                                     - Removed unused Tx buffers and doubled number of Rx buffers to avoid resource errors without increasing memory footprint.
     14       22.09.2009   MS       Addon:
                                     - Added HilMarshallerSetMode(), mode evaluation in HilMarshallerConnRxData().
     13       04.09.2009   MS       Bugfix:
                                     - Do not discard "superfluous" data on reception of a transport ACK from the host. Instead, start a new receive cycle.
     12       02.09.2009   MS       Change:
                                     - HilMarshallerMain() returns TLR_E_FAIL if no message can be retrieved from the pending requests list.
     11       01.09.2009   MS       Bugfix:
                                     - Removed redundant calls to OS_FREE() following call to HilMarshallerStop() after failure in HilMarshallerStart().
     10       26.08.2009   MS       Change:
                                     - Use HilMarshallerGetBuffer() and HilMarshallerFreeBuffer() in SendAcknowledge() instead of STAILQ_xxx macros.
     9        25.08.2009   MS       Bugfix:
                                     - No need to perform buffer handling in case of incoming Tx Ack.
     8        19.08.2009   MS       Bugfixes:
                                     - Corrected calculation of the used buffer length for a QUERYSERVER response.
                                     - Zero ulActualSendOffset when allocating buffer.
     7        13.08.2009   MS       Bugfix:
                                     - Set fAnswer flag to trigger response transmission also for regular Keep Alive message.
     6        06.08.2009   MS       Bugfix:
                                     - Changed creation of the QUERYSERVER response to be in line with the specification.
     5        04.08.2009   MS       Bugfix:
                                     - Keep Alive response: Prevent buffer from being freed by ResetRxStateMachine() while not transmitted completely.
     4        28.07.2009   MS       Change:
                                     - Moved Marshaller version constants to MarshallerVersion.h
     3        21.07.2009   MS       Bugfix:
                                     - Need to initialize Connectors before Transports because
                                       Transport initialization uses Connector data
     2        02.06.2009   MT       Bugfix:
                                     - Buffer handling for Connectors with Idx > 0 did not work
                                       (Connectors will run out of buffers)
     1        25.05.2009   MT       initial version

**************************************************************************************/

/*****************************************************************************/
/*! \file HilMarshaller.c
*   netX Marshaller implementation                                           */
/*****************************************************************************/

#include <OS_Includes.h>
#include "MarshallerConfig.h"
#include "MarshallerInternal.h"
#include "MarshallerFrame.h"
#include "MarshallerVersion.h"


#ifndef min
  #define min(a,b)  ((a > b)? b : a)
#endif

/*****************************************************************************/
/*! \addtogroup NETX_MARSHALLER_MAIN
*   \{                                                                       */
/*****************************************************************************/

/*****************************************************************************/
/*! Calculate CCITT/ITU CRC-16 checksum.
*   Polynomial  : x^16 + x^12 + x^5 + 1 (0x1021)
*   Start value : 0xFFFF
*   Result      : XORed with 0xFFFF
*    \param pbData        Buffer to calculate CRC for
*    \param ulDataLength  Length of buffer
*    \return CRC-16 checksum                                                 */
/*****************************************************************************/
static TLR_UINT16 CalculateCRC16 (const TLR_UINT8* pbData, TLR_UINT32 ulDataLength)
{
  TLR_UINT16 usCRC;
  TLR_UINT32 ulOffset;

  usCRC = 0xFFFF;
  if (pbData != NULL && ulDataLength > 0)
  { /* Buffer address and data length are valid. */
    for (ulOffset = 0; ulOffset < ulDataLength; ++ulOffset)
    { /* Update CRC value for each byte in the buffer. */
      usCRC =  (TLR_UINT16) ((usCRC >> 8) | (usCRC << 8));
      usCRC =  (TLR_UINT16)(usCRC ^ pbData[ulOffset]);
      usCRC ^= (TLR_UINT16)((usCRC & 0xFF) >> 4);
      usCRC ^= (TLR_UINT16)((usCRC << 8) << 4);
      usCRC ^= (TLR_UINT16)(((usCRC & 0xFF) << 4) << 1);
    }
    usCRC = (TLR_UINT16) (~usCRC);
  }
  return (usCRC);
}


/*****************************************************************************/
/*! Allocates the requested data buffers and inserts them in free list
*   of connector
*    \param pvMarshaller   Marshaller handle
*    \param ptConnector    Connector to allocate buffers for
*    \param ulRxBufferCnt  Number of buffers to allocate (equals number of parallel services)
*    \param ulRxBufferSize Size of the buffers in bytes
*    \param ulTxBufferCnt  Number of transmit buffers to allocate (for unsolicited/indication data)
*    \param ulTxBufferSize Size of the transmit buffers in bytes
*    \return TLR_TRUE on success                                             */
/*****************************************************************************/
static TLR_BOOLEAN AllocateBuffers(void* pvMarshaller, CONNECTOR_DATA_T* ptConnector, TLR_UINT32 ulRxBufferCnt, TLR_UINT32 ulRxBufferSize, TLR_UINT32 ulTxBufferCnt, TLR_UINT32 ulTxBufferSize)
{
  TLR_BOOLEAN fRet = TLR_TRUE;
  TLR_UINT32  ulIdx;

  STAILQ_INIT(&ptConnector->tRxBuffer);
  STAILQ_INIT(&ptConnector->tTxBuffer);
  STAILQ_INIT(&ptConnector->tAckBuffer);
  STAILQ_INIT(&ptConnector->tKeepAliveBuffer);

  /* Use twice the number of requested data buffers for Rx data,
     to make sure we have some reserve in case a buffer has not yet been released after the confirmation has been sent */
  for(ulIdx = 0; ulIdx < ulRxBufferCnt; ++ulIdx)
  {
    HIL_MARSHALLER_BUFFER_T* ptBuffer;

    if(NULL == (ptBuffer = OS_MALLOC((TLR_UINT32)sizeof(*ptBuffer) + ulRxBufferSize)))
    {
      fRet = TLR_FALSE;
      break;
    } else
    {
      ptBuffer->tMgmt.ulConnectorIdx      = ptConnector->ulConnectorIdx;
      ptBuffer->tMgmt.pvMarshaller        = pvMarshaller;
      ptBuffer->tMgmt.ulDataBufferLen     = ulRxBufferSize;
      ptBuffer->tMgmt.eType               = eMARSHALLER_RX_BUFFER;
      ptBuffer->tMgmt.ulUsedDataBufferLen = 0;

      /* Enqueue in linked list */
      STAILQ_INSERT_TAIL(&ptConnector->tRxBuffer, ptBuffer, tList);
    }
  }

  for(ulIdx = 0; ulIdx < ulTxBufferCnt; ++ulIdx)
  {
    HIL_MARSHALLER_BUFFER_T* ptBuffer;

    if(NULL == (ptBuffer = OS_MALLOC((TLR_UINT32)sizeof(*ptBuffer) + ulTxBufferSize)))
    {
      fRet = TLR_FALSE;
    	break;
  	} else
  	{
    	ptBuffer->tMgmt.ulConnectorIdx      = ptConnector->ulConnectorIdx;
    	ptBuffer->tMgmt.pvMarshaller        = pvMarshaller;
    	ptBuffer->tMgmt.ulDataBufferLen     = ulTxBufferSize;
    	ptBuffer->tMgmt.eType               = eMARSHALLER_TX_BUFFER;
    	ptBuffer->tMgmt.ulUsedDataBufferLen = 0;
    	/* Enqueue in linked list */
			STAILQ_INSERT_TAIL(&ptConnector->tTxBuffer, ptBuffer, tList);
  	}
  }

  /* Use one additional Buffer per direction for acknowledgement,
     to make sure we can answer while we don't have databuffers
     ready (number of parallel services exceeded) */
  for(ulIdx = 0; ulIdx < ulRxBufferCnt + ulTxBufferCnt + 2; ++ulIdx)
  {
    HIL_MARSHALLER_BUFFER_T* ptBuffer;

    if(NULL == (ptBuffer = OS_MALLOC(sizeof(*ptBuffer))))
    {
      fRet = TLR_FALSE;
      break;
    } else
    {
      ptBuffer->tMgmt.ulConnectorIdx      = ptConnector->ulConnectorIdx;
      ptBuffer->tMgmt.pvMarshaller        = pvMarshaller;
      ptBuffer->tMgmt.ulDataBufferLen     = 0;
      ptBuffer->tMgmt.eType               = eMARSHALLER_ACK_BUFFER;
      ptBuffer->tMgmt.ulUsedDataBufferLen = 0;

      /* Enqueue in linked list */
      STAILQ_INSERT_TAIL(&ptConnector->tAckBuffer, ptBuffer, tList);
    }
  }

  if(fRet)
  {
    HIL_MARSHALLER_BUFFER_T* ptBuffer;

    if(NULL == (ptBuffer = OS_MALLOC(sizeof(*ptBuffer) + sizeof(HIL_TRANSPORT_KEEPALIVE_DATA_T))))
    {
      fRet = TLR_FALSE;
    } else
    {
      ptBuffer->tMgmt.ulConnectorIdx      = ptConnector->ulConnectorIdx;
      ptBuffer->tMgmt.pvMarshaller        = pvMarshaller;
      ptBuffer->tMgmt.ulDataBufferLen     = sizeof(HIL_TRANSPORT_KEEPALIVE_DATA_T);
      ptBuffer->tMgmt.eType               = eMARSHALLER_KEEPALIVE_BUFFER;
      ptBuffer->tMgmt.ulUsedDataBufferLen = 0;

      /* Enqueue in linked list */
      STAILQ_INSERT_TAIL(&ptConnector->tKeepAliveBuffer, ptBuffer, tList);
    }
  }

  return fRet;
}

/*****************************************************************************/
/*! Deallocates all data buffers from a connector
*    \param pvMarshaller Marshaller handle
*    \param ptConnector  Connector to free buffers for                      */
/*****************************************************************************/
static void DeAllocateBuffers(void* pvMarshaller, CONNECTOR_DATA_T* ptConnector)
{
  /* Deallocate all buffers in linked lists */
  HIL_MARSHALLER_BUFFER_T* ptBuffer;

  while(NULL != (ptBuffer = STAILQ_FIRST(&ptConnector->tAckBuffer)))
  {
    STAILQ_REMOVE(&ptConnector->tAckBuffer, ptBuffer, HIL_MARSHALLER_BUFFER_Ttag, tList);

    OS_FREE(ptBuffer);
  }

  while(NULL != (ptBuffer = STAILQ_FIRST(&ptConnector->tRxBuffer)))
  {
    STAILQ_REMOVE(&ptConnector->tRxBuffer, ptBuffer, HIL_MARSHALLER_BUFFER_Ttag, tList);

    OS_FREE(ptBuffer);
  }

  while(NULL != (ptBuffer = STAILQ_FIRST(&ptConnector->tTxBuffer)))
	{
  	STAILQ_REMOVE(&ptConnector->tTxBuffer, ptBuffer, HIL_MARSHALLER_BUFFER_Ttag, tList);

	  OS_FREE(ptBuffer);
	}

  while(NULL != (ptBuffer = STAILQ_FIRST(&ptConnector->tKeepAliveBuffer)))
  {
    STAILQ_REMOVE(&ptConnector->tKeepAliveBuffer, ptBuffer, HIL_MARSHALLER_BUFFER_Ttag, tList);

    OS_FREE(ptBuffer);
  }
}

/*****************************************************************************/
/*! Free a buffer
*    \param ptBuffer Buffer to free                                         */
/*****************************************************************************/
void HilMarshallerFreeBuffer(HIL_MARSHALLER_BUFFER_T* ptBuffer)
{
  HIL_MARSHALLER_DATA_T* ptMarshaller = (HIL_MARSHALLER_DATA_T*)ptBuffer->tMgmt.pvMarshaller;
  CONNECTOR_DATA_T*      ptConn       = &ptMarshaller->atConnectors[ptBuffer->tMgmt.ulConnectorIdx];
  int                    iLock;

  ptBuffer->tMgmt.ulUsedDataBufferLen = 0;

  iLock = OS_LOCK();

  switch(ptBuffer->tMgmt.eType)
  {
  case eMARSHALLER_KEEPALIVE_BUFFER:
    STAILQ_INSERT_TAIL(&ptConn->tKeepAliveBuffer, ptBuffer, tList);
    break;

  case eMARSHALLER_ACK_BUFFER:
    STAILQ_INSERT_TAIL(&ptConn->tAckBuffer, ptBuffer, tList);
    break;

  case eMARSHALLER_RX_BUFFER:
    STAILQ_INSERT_TAIL(&ptConn->tRxBuffer, ptBuffer, tList);
    break;

  case eMARSHALLER_TX_BUFFER:
    STAILQ_INSERT_TAIL(&ptConn->tTxBuffer, ptBuffer, tList);
    break;

  default:
    /* NOTE: This should never happen, only if someone free's a wrong buffer,
             or destroyed the buffer management area (programming error). */
    ptConn = ptConn;
    break;
  }

  OS_UNLOCK(iLock);
}

/*****************************************************************************/
/*! Get a buffer for incoming data from connector
*    \param pvMarshaller Marshaller handle
*    \param eType        Type of buffer to acquire
*    \param ulConnector  Connector index
*    \return NULL if no buffer is available, valid buffer otherwise          */
/*****************************************************************************/
HIL_MARSHALLER_BUFFER_T* HilMarshallerGetBuffer(void* pvMarshaller, MARSHALLER_BUFFER_TYPE_E eType, TLR_UINT32 ulConnector)
{
  HIL_MARSHALLER_DATA_T*   ptMarshaller     = (HIL_MARSHALLER_DATA_T*)pvMarshaller;
  CONNECTOR_DATA_T*        ptConn           = &ptMarshaller->atConnectors[ulConnector];
  HIL_MARSHALLER_BUFFER_T* ptBuffer         = NULL;
  struct MARSHALLER_BUFFER_HEAD* ptListHead = NULL;
  int                      iLock;

  switch(eType)
  {
  case eMARSHALLER_RX_BUFFER:
    ptListHead = &ptConn->tRxBuffer;
    break;

	case eMARSHALLER_TX_BUFFER:
	  ptListHead = &ptConn->tTxBuffer;
  	break;

  case eMARSHALLER_ACK_BUFFER:
    ptListHead = &ptConn->tAckBuffer;
    break;

  case eMARSHALLER_KEEPALIVE_BUFFER:
    ptListHead = &ptConn->tKeepAliveBuffer;
    break;

  default:
    /* NOTE: This should never happen, only if someone free's a wrong buffer,
             or destroyed the buffer management area (programming error). */
    break;
  }

  iLock = OS_LOCK();

  if( (NULL != ptListHead) &&
      (NULL != (ptBuffer = STAILQ_FIRST(ptListHead))) )
  {
    STAILQ_REMOVE(ptListHead, ptBuffer, HIL_MARSHALLER_BUFFER_Ttag, tList);
    ptBuffer->tMgmt.ulActualSendOffset  = 0;
    ptBuffer->tMgmt.ulUsedDataBufferLen = 0;
  }

  OS_UNLOCK(iLock);

  return ptBuffer;
}

/*****************************************************************************/
/*! Find a transport layer which can handle the requested data type
*    \param ptMarshaller Marshaller handle
*    \param usDataType   Datatype the transport layer is requested for
*    \return NULL if no transport is available, valid transport otherwise    */
/*****************************************************************************/
static TRANSPORT_LAYER_DATA_T* FindTransportLayer(const HIL_MARSHALLER_DATA_T* ptMarshaller, const TLR_UINT16 usDataType)
{
  TRANSPORT_LAYER_DATA_T* ptRet = NULL;
  TLR_UINT32              ulIdx;

  for(ulIdx = 0; ulIdx < ptMarshaller->ulTransports; ++ulIdx)
  {
    if(usDataType == ptMarshaller->ptTransports[ulIdx].usDataType)
    {
      ptRet = &ptMarshaller->ptTransports[ulIdx];
      break;
    }
  }

  return ptRet;
}

/*****************************************************************************/
/*! Send an HIL Transport acknowledge
*    \param ptMarshaller Marshaller handle
*    \param ulConnector  Connector to send ACK to
*    \param ptHeader     Header of incoming packet
*    \param bState       State to set in acknowledge                        */
/*****************************************************************************/
static void SendAcknowledge(HIL_MARSHALLER_DATA_T* ptMarshaller, TLR_UINT32 ulConnector, HIL_TRANSPORT_HEADER* ptHeader, unsigned char bState)
{
  HIL_MARSHALLER_BUFFER_T* ptBuffer;
  /* If we don't get a buffer, the number of parallel services is exceeded.
     This is a host error, as it is sending data too fast and we are not able to do any acknowledge */
  ptBuffer = HilMarshallerGetBuffer(ptMarshaller, eMARSHALLER_ACK_BUFFER, ulConnector);
  if(NULL != ptBuffer)
  {
    ptBuffer->tTransport                = *ptHeader;
    ptBuffer->tTransport.bState         = bState;
    ptBuffer->tTransport.usDataType     = HIL_TRANSPORT_TYPE_ACKNOWLEDGE;
    ptBuffer->tMgmt.ulUsedDataBufferLen = 0;
    if(TLR_S_OK != HilMarshallerConnTxData(ptMarshaller, ulConnector, ptBuffer))
    {
      /* Internal error, this should never happen, but if it happens, we need to free the Ack buffer again */
      HilMarshallerFreeBuffer(ptBuffer);
    }
  }
}

/*****************************************************************************/
/*! Reset internal connector receive state machine
*    \param ptConnector  Connector to reset                                 */
/*****************************************************************************/
static void ResetRxStateMachine(CONNECTOR_DATA_T* ptConnector)
{

  if((ptConnector->eScanState != HIL_SEARCH_TELEGRAM_COOKIE) &&
     (ptConnector->eScanState != HIL_SCAN_DONE)              )
  {
    ptConnector->eScanState = ptConnector->eScanState;
  }

  ptConnector->fMonitorTimeout    = TLR_FALSE;
  ptConnector->ulElapsedTime      = 0;
  ptConnector->tRxHeader.ulCookie = 0;
  ptConnector->ulRxOffset         = 0;
  if(NULL != ptConnector->ptCurrentRxBuffer)
  {
    HilMarshallerFreeBuffer(ptConnector->ptCurrentRxBuffer);
  }

  ptConnector->ptCurrentRxBuffer  = NULL;
  ptConnector->eScanState         = HIL_SEARCH_TELEGRAM_COOKIE;
}


/*****************************************************************************/
/*! Startup marshaller
*    \param ptParams       Marshaller parameters
*    \param ppvMarshHandle Returned Marshaller handle
*    \param pfnRequest     Function to call, when MarshallerMain should be called
*    \param pvUser         User parameter to pass on pfnRequest call
*    \return TLR_S_OK on success                                             */
/*****************************************************************************/
TLR_RESULT HilMarshallerStart(const HIL_MARSHALLER_PARAMS_T* ptParams, void** ppvMarshHandle, PFN_MARSHALLER_REQUEST pfnRequest, void* pvUser)
{
  TLR_RESULT                               eRet         = TLR_S_OK;
  HIL_MARSHALLER_DATA_T*                   ptMarshaller = NULL;
  TLR_UINT32                               ulIdx        = 0;
  const TRANSPORT_LAYER_CONFIG_T*          ptTransport  = NULL;
  const HIL_MARSHALLER_CONNECTOR_PARAMS_T* ptConnParams = NULL;

  if(NULL == ppvMarshHandle)
    eRet = HIL_MARSHALLER_E_INVALIDPARAMETER;
  else
  {
    *ppvMarshHandle = NULL;
    if (NULL == (ptMarshaller = OS_MALLOC(sizeof(*ptMarshaller))))
      eRet = HIL_MARSHALLER_E_OUTOFMEMORY;
    else
    {
      memset(ptMarshaller, 0, sizeof(*ptMarshaller));
      STAILQ_INIT(&ptMarshaller->tPendingRequests);
      ptMarshaller->pfnRequest      = pfnRequest;
      ptMarshaller->pvUser          = pvUser;
      ptMarshaller->ulMaxConnectors = ptParams->ulMaxConnectors;
      ptMarshaller->ulTransports    = ptParams->ulTransportCnt;
      memcpy(ptMarshaller->szServerName, ptParams->szServerName, sizeof(ptMarshaller->szServerName));
      if(NULL == (ptMarshaller->atConnectors = OS_MALLOC(ptParams->ulMaxConnectors * (uint32_t)sizeof(CONNECTOR_DATA_T))))
        eRet = HIL_MARSHALLER_E_OUTOFMEMORY;
      else
      {
        memset(ptMarshaller->atConnectors, 0, ptParams->ulMaxConnectors * sizeof(CONNECTOR_DATA_T));
        if(NULL == (ptMarshaller->ptTransports = OS_MALLOC(ptParams->ulTransportCnt * (uint32_t)sizeof(TRANSPORT_LAYER_DATA_T))))
          eRet = HIL_MARSHALLER_E_OUTOFMEMORY;
        else
        {
          memset(ptMarshaller->ptTransports, 0, ptParams->ulTransportCnt * sizeof(TRANSPORT_LAYER_DATA_T));
          for(ulIdx = 0; eRet == TLR_S_OK && ulIdx < ptParams->ulConnectorCnt; ++ulIdx)
          {
            ptConnParams = &ptParams->ptConnectors[ulIdx];
            if(ptConnParams->pfnConnectorInit)
              eRet = ptConnParams->pfnConnectorInit(ptConnParams, ptMarshaller);
          }
          for(ulIdx = 0; eRet == TLR_S_OK && ulIdx < ptParams->ulTransportCnt; ++ulIdx)
          {
            ptTransport = &ptParams->atTransports[ulIdx];
            if(ptTransport->pfnInit)
              eRet = ptTransport->pfnInit(ptMarshaller, ptTransport->pvConfig);
          }
        }
      }
    }
    if(TLR_S_OK == eRet)
      *ppvMarshHandle = ptMarshaller;
    else
      HilMarshallerStop(ptMarshaller);
  }
  return eRet;
}

/*****************************************************************************/
/*! Stop marshaller
*    \param pvMarshHandle  Marshaller handle                                 */
/*****************************************************************************/
void HilMarshallerStop(void* pvMarshHandle)
{
  HIL_MARSHALLER_DATA_T* ptMarshaller = (HIL_MARSHALLER_DATA_T*)pvMarshHandle;

  if(NULL != ptMarshaller)
  {
    if(NULL != ptMarshaller->atConnectors)
    {
      TLR_UINT32 ulConn;

      for(ulConn = 0; ulConn < ptMarshaller->ulMaxConnectors; ++ulConn)
      {
        CONNECTOR_DATA_T* ptConn = &ptMarshaller->atConnectors[ulConn];

        if(ptConn->fInUse)
        {
          ptConn->tConn.pfnDeinit(ptConn->tConn.pvUser);
        }
      }

      OS_FREE(ptMarshaller->atConnectors);
      ptMarshaller->atConnectors = NULL;
    }

    if(NULL != ptMarshaller->ptTransports)
    {
      TLR_UINT32 ulTrans;

      for(ulTrans = 0; ulTrans < ptMarshaller->ulTransports; ++ulTrans)
      {
        TRANSPORT_LAYER_DATA_T* ptTransport = &ptMarshaller->ptTransports[ulTrans];

        if(ptTransport->pfnDeinit)
        {
          ptTransport->pfnDeinit(ptTransport->pvUser);
        }
      }

      OS_FREE(ptMarshaller->ptTransports);
      ptMarshaller->ptTransports = NULL;
    }

    OS_FREE(ptMarshaller);
  }
}

/*****************************************************************************/
/*! Register a connector at marshaller
*    \param pvMarshaller     Marshaller handle
*    \param pulConnectorIdx  Returned connector number
*    \param ptConn           Connector data
*    \return TLR_S_OK on success                                             */
/*****************************************************************************/
TLR_RESULT HilMarshallerRegisterConnector(void* pvMarshaller, TLR_UINT32* pulConnectorIdx, HIL_MARSHALLER_CONNECTOR_T* ptConn)
{
  HIL_MARSHALLER_DATA_T* ptMarshaller    = (HIL_MARSHALLER_DATA_T*)pvMarshaller;
  TLR_RESULT             eRet            = TLR_S_OK;
  CONNECTOR_DATA_T*      ptConnectorData = NULL;
  TLR_UINT32             ulConnIdx;

  /* Search free connector space */
  for(ulConnIdx = 0; ulConnIdx < ptMarshaller->ulMaxConnectors; ++ulConnIdx)
  {
    if(!ptMarshaller->atConnectors[ulConnIdx].fInUse)
    {
      ptConnectorData = &ptMarshaller->atConnectors[ulConnIdx];
      ptConnectorData->ulConnectorIdx  = ulConnIdx;
      break;
    }
  }

  if(NULL == ptConnectorData)
  {
    /* No more connectors allowed */
    eRet = HIL_MARSHALLER_E_OUTOFRESOURCES;

  } else if(!AllocateBuffers(pvMarshaller,
                             ptConnectorData,
                             ptConn->ulDataBufferCnt,
                             ptConn->ulDataBufferSize,
                             ptConn->ulTxBufferCnt,
                             ptConn->ulTxBufferSize))
  {
    /* Out of memory */
    eRet = HIL_MARSHALLER_E_OUTOFMEMORY;
  } else
  {
    /* Initialize RX state machine */
    ResetRxStateMachine(ptConnectorData);

    /* Initialize conector data */
    ptConnectorData->fInUse          = TLR_TRUE;
    ptConnectorData->tConn           = *ptConn;
    *pulConnectorIdx                 = ulConnIdx;
  }

  return eRet;
}

/*****************************************************************************/
/*! Unregister a connector at marshaller
*    \param pvMarshaller     Marshaller handle
*    \param ulConnectorIdx   Connector number                               */
/*****************************************************************************/
void HilMarshallerUnregisterConnector(void* pvMarshaller, TLR_UINT32 ulConnectorIdx)
{
  HIL_MARSHALLER_DATA_T* ptMarshaller = (HIL_MARSHALLER_DATA_T*)pvMarshaller;

  if(ulConnectorIdx < ptMarshaller->ulMaxConnectors)
  {
    CONNECTOR_DATA_T* ptConnectorData = &ptMarshaller->atConnectors[ulConnectorIdx];

    DeAllocateBuffers(pvMarshaller,
                      ptConnectorData);

    ptConnectorData->fInUse = TLR_FALSE;
    memset(&ptConnectorData->tConn, 0, sizeof(ptConnectorData->tConn));
  }
}

/*****************************************************************************/
/*! Called by connector when new data has arrived
*    \param pvMarshaller     Marshaller handle
*    \param ulConnector      Connector number
*    \param pbData           Incoming data
*    \param ulDataCnt        Number of bytes in incoming data buffer
*    \return TLR_S_OK on success                                             */
/*****************************************************************************/
TLR_RESULT HilMarshallerConnRxData(void* pvMarshaller, TLR_UINT32 ulConnector, TLR_UINT8* pbData, TLR_UINT32 ulDataCnt)
{
  HIL_MARSHALLER_DATA_T* ptMarshaller = (HIL_MARSHALLER_DATA_T*)pvMarshaller;
  TLR_RESULT             eRet         = HIL_MARSHALLER_E_INVALIDPARAMETER;

  if (ulConnector < ptMarshaller->ulMaxConnectors
  &&  ptMarshaller->atConnectors[ulConnector].ulMode != HIL_MARSHALLER_MODE_DISABLED)
  {
    CONNECTOR_DATA_T* ptConnector = &ptMarshaller->atConnectors[ulConnector];
    int               fDone       = 0;    /* Leave handler */
    uint32_t          ulRxDataIdx = 0;

    eRet = TLR_S_OK;
    ptConnector->ulElapsedTime    = 0;      /* Reschedule timeout handling */

    /*-----------------------------------------*/
    /* Start scanning of the input data        */
    /*-----------------------------------------*/
    do
    {
      switch(ptConnector->eScanState)
      {
        case HIL_SEARCH_TELEGRAM_COOKIE:
        {
          /* Parse input buffer */
          unsigned char* pabCookie = (unsigned char*)&ptConnector->tRxHeader.ulCookie;

          for ( ulRxDataIdx = 0; ulRxDataIdx < ulDataCnt; ulRxDataIdx++)
          {
            pabCookie[ptConnector->ulRxOffset] = pbData[ulRxDataIdx];
            if( ++ptConnector->ulRxOffset >= sizeof(ptConnector->tRxHeader.ulCookie))
            {
              /* Check if we have a complete cookie */
              if( HIL_TRANSPORT_COOKIE == ptConnector->tRxHeader.ulCookie)
              {
                /* Yes, store the cookie in the header */
                ulDataCnt = ulDataCnt - (ulRxDataIdx + 1);
                pbData    = &pbData[ulRxDataIdx + 1];

                /* Set next state */
                ptConnector->eScanState      = HIL_SEARCH_TELEGRAM_HEADER;
                ptConnector->fMonitorTimeout = TLR_TRUE;
                break;
              }else
              {
                  /* Still no cookie, move the data and insert next character. */
                /* Set cookie buffer index to next insertable character. */
                  memmove(pabCookie, &pabCookie[1], 3);
                  ptConnector->ulRxOffset = 3;
              }
            }
          }

          if( HIL_SEARCH_TELEGRAM_COOKIE == ptConnector->eScanState)
              fDone = 1;

          break;
        }

        case HIL_SEARCH_TELEGRAM_HEADER:
        {
          /* We searching a telegram header, cookie is already available */
          /* Check if we have more date */
          if ( 0 == ulDataCnt)
          {
            fDone = 1;
          } else
          {
            /* Append at least the header length if available */
            uint32_t       ulCopyLength = 0;
            unsigned char* pbHeader     = (unsigned char*)&ptConnector->tRxHeader;

            ulCopyLength = min(ulDataCnt,
                               sizeof(HIL_TRANSPORT_HEADER) - ptConnector->ulRxOffset);

            memcpy( &pbHeader[ptConnector->ulRxOffset],
                    pbData,
                    ulCopyLength);

            ptConnector->ulRxOffset += ulCopyLength;

            /* Check if we have more data */
            if(ptConnector->ulRxOffset < sizeof(HIL_TRANSPORT_HEADER))
            {
              /* We need more data */
              fDone = 1;

            } else if (HIL_TRANSPORT_TYPE_ACKNOWLEDGE == ptConnector->tRxHeader.usDataType)
            {
              /* Update the Rx data count and Rx data pointer for handling the remaining bytes */
              ulDataCnt -= ulCopyLength;
              pbData     = &pbData[ulCopyLength];
              ptConnector->ptCurrentRxBuffer = NULL;
              ResetRxStateMachine(ptConnector);
              /* If there are bytes left, start a new cookie search using these bytes. Otherwise terminate the receive cycle. */
              if (ulDataCnt == 0)
                fDone = 1;
              break;
            } else
            {
              /* We need a buffer */

              HIL_MARSHALLER_BUFFER_T* ptBuffer;

              if(HIL_TRANSPORT_TYPE_KEEP_ALIVE == ptConnector->tRxHeader.usDataType)
              {
                ptBuffer = HilMarshallerGetBuffer(ptMarshaller, eMARSHALLER_KEEPALIVE_BUFFER, ulConnector);

              } else
              {
                ptBuffer = HilMarshallerGetBuffer(ptMarshaller, eMARSHALLER_RX_BUFFER, ulConnector);
              }

              if(NULL == ptBuffer)
              {
                /* Send negative Ack */
                SendAcknowledge(ptMarshaller, ulConnector, &ptConnector->tRxHeader, HIL_TSTATE_RESOURCE_ERROR);
                ResetRxStateMachine(ptConnector);

              } else if(ptBuffer->tMgmt.ulDataBufferLen < ptConnector->tRxHeader.ulLength)
              {
                /* Send negative ACK (telegram too long for buffer) */
                SendAcknowledge(ptMarshaller, ulConnector, &ptConnector->tRxHeader, HIL_TSTATE_BUFFEROVERFLOW_ERROR);

                /* Release Buffer */
                HilMarshallerFreeBuffer(ptBuffer);
                ResetRxStateMachine(ptConnector);

              } else
              {
                /* We have a complete Header, wait for packet data complete */
                ulDataCnt -= ulCopyLength;
                pbData    = &pbData[ulCopyLength];

                /* Store header */
                ptBuffer->tTransport                = ptConnector->tRxHeader;
                ptBuffer->tMgmt.ulUsedDataBufferLen = 0; /* Set actual telegram data length */

                /* Set next scanner state */
                ptConnector->ptCurrentRxBuffer = ptBuffer;
                ptConnector->eScanState        = HIL_WAIT_TELEGRAM_DATA;
              }
            }
          }
        }
        break;

        case HIL_WAIT_TELEGRAM_DATA:
        {
          /* We waiting for telegram data, wait until all data are available */
          uint32_t              ulCopyLen    = 0;
          HIL_TRANSPORT_HEADER* ptHeader     = &ptConnector->ptCurrentRxBuffer->tTransport;
          uint32_t              ulDataOffset = ptConnector->ulRxOffset - (uint32_t)sizeof(HIL_TRANSPORT_HEADER);

          if(0 == ptHeader->ulLength)
          {
            /* We have all data */
            ptConnector->eScanState = HIL_CHECK_TELEGRAM;

          /* We have packet data, wait until all data are available */
          } else if(0 != ulDataCnt)
          {
            HIL_MARSHALLER_BUFFER_T* ptBuffer = ptConnector->ptCurrentRxBuffer;

              /* Check if all data must be copied or if we have more data than necessary */
            ulCopyLen = ulDataCnt;
              if( (ulDataCnt + ulDataOffset) > ptHeader->ulLength)
              {
                  /* Just copy the necessary data and keep the rest for a new cookie ssearch */
              ulCopyLen = ptHeader->ulLength - ulDataOffset;
              }

            memcpy(&ptBuffer->abData[ulDataOffset], pbData, ulCopyLen);
            ptConnector->ulRxOffset             += ulCopyLen;
            ptBuffer->tMgmt.ulUsedDataBufferLen += ulCopyLen;
          }

          if(ptConnector->ulRxOffset < (ptHeader->ulLength + sizeof(*ptHeader)))
          {
              /* We have to wait for more data */
              fDone = 1;
          } else
          {
              /* We have a complete telegram */

              /* Check if we have data left */
              ulDataCnt -= ulCopyLen;
              pbData    = &pbData[ulCopyLen];

            /* We have all data */
            ptConnector->eScanState = HIL_CHECK_TELEGRAM;
          }
        }
        break;

        case HIL_CHECK_TELEGRAM:
        {
          HIL_TRANSPORT_HEADER*    ptHeader = &ptConnector->ptCurrentRxBuffer->tTransport;
          HIL_MARSHALLER_BUFFER_T* ptBuffer = ptConnector->ptCurrentRxBuffer;

          if( (ptHeader->ulLength > 0)    &&
              (ptHeader->usChecksum != 0) &&
              (ptHeader->usChecksum != CalculateCRC16(ptBuffer->abData,
                                                      ptConnector->tRxHeader.ulLength)) )
          {
            SendAcknowledge(ptMarshaller, ulConnector, &ptConnector->tRxHeader, HIL_TSTATE_CHECKSUM_ERROR);
          } else
          {
            /* We have a complete telegram */
            /* Check for Acknowledge */
            switch(ptHeader->usDataType)
            {
            case HIL_TRANSPORT_TYPE_ACKNOWLEDGE:
              break;

            case HIL_TRANSPORT_TYPE_QUERYSERVER:
            {
              if(NULL == ptBuffer)
                ptBuffer = HilMarshallerGetBuffer(pvMarshaller, eMARSHALLER_TX_BUFFER, ulConnector);

              if(NULL == ptBuffer)
              {
                SendAcknowledge(ptMarshaller, ulConnector, &ptConnector->tRxHeader, HIL_TSTATE_RESOURCE_ERROR);

              } else
              {
                PHIL_TRANSPORT_ADMIN_QUERYSERVER_DATA_T ptServerData = (PHIL_TRANSPORT_ADMIN_QUERYSERVER_DATA_T)ptBuffer->abData;
                TLR_UINT32                              ulIdx;

                SendAcknowledge(ptMarshaller, ulConnector, &ptConnector->tRxHeader, HIL_TRANSPORT_STATE_OK);

                /* Fill in data */
                ptBuffer->tTransport = ptConnector->ptCurrentRxBuffer->tTransport;

                ptServerData->ulStructVersion    = 1;
                memcpy(ptServerData->szServerName, ptMarshaller->szServerName, sizeof(ptServerData->szServerName));
                ptServerData->ulVersionMajor     = MARSHALLER_VERSION_MAJOR;
                ptServerData->ulVersionMinor     = MARSHALLER_VERSION_MINOR;
                ptServerData->ulVersionBuild     = MARSHALLER_VERSION_BUILD;
                ptServerData->ulVersionRevision  = MARSHALLER_VERSION_REVISION;
#if defined(HIL_MARSHALLER_PERMANENT_CONNECTION)
                ptServerData->ulFeatures         = HIL_TRANSPORT_FEATURES_KEEPALIVE |
                                                   HIL_TRANSPORT_FEATURES_PERMANENT_CONNECTION;
#else
                ptServerData->ulFeatures         = HIL_TRANSPORT_FEATURES_KEEPALIVE;
#endif
                ptServerData->ulParallelServices = ptConnector->tConn.ulDataBufferCnt;
                ptServerData->ulBufferSize       = ptConnector->tConn.ulDataBufferSize;
                ptServerData->ulDatatypeCnt      = ptMarshaller->ulTransports;

                for(ulIdx = 0; ulIdx < ptMarshaller->ulTransports; ++ulIdx)
                  ptServerData->ausDataTypes[ulIdx] = ptMarshaller->ptTransports[ulIdx].usDataType;

                /* Add the Keep Alive transport type to the list. */
                ptServerData->ausDataTypes[ulIdx] = HIL_TRANSPORT_TYPE_KEEP_ALIVE;
                ptServerData->ulDatatypeCnt++;

                /* Calculate the actual response data length. */
                ptBuffer->tMgmt.ulUsedDataBufferLen = (uint32_t)((TLR_UINT8*) ptServerData->ausDataTypes - (TLR_UINT8*) ptServerData
                                                        + (ptServerData->ulDatatypeCnt) * sizeof (ptServerData->ausDataTypes[0]));

                if(TLR_S_OK != HilMarshallerConnTxData(pvMarshaller,
                                                       ulConnector,
                                                       ptBuffer))
                {
                  HilMarshallerFreeBuffer(ptBuffer);
                  ptConnector->ptCurrentRxBuffer = NULL;
                } else
                {
                  /* Prevent buffer from being freed by ResetRxStateMachine() while not transmitted completely. */
                  ptConnector->ptCurrentRxBuffer = NULL;
                }
              }
            }
            break;

            /*TODO: Implement Administration commands (QUERY_DEVICE) */

            case HIL_TRANSPORT_TYPE_KEEP_ALIVE:
              {
                PHIL_TRANSPORT_KEEPALIVE_DATA_T ptKeepAlive = (PHIL_TRANSPORT_KEEPALIVE_DATA_T)ptConnector->ptCurrentRxBuffer->abData;
                unsigned char                   bState      = HIL_TRANSPORT_STATE_OK;
                TLR_BOOLEAN                     fSendAnswer = TLR_FALSE;

                if(ptHeader->ulLength != sizeof(*ptKeepAlive))
                {
                  /* Illegal length of keepalive packet */
                  bState = HIL_TSTATE_LENGTH_INCOMPLETE;

                } else if(0 == ptKeepAlive->ulComID)
                {
                  /* New Keepalive ID requested */
                  TLR_UINT32 ulNewId = OS_GETTICKCOUNT();

                  if(0 == ulNewId)
                    ++ptConnector->ulKeepaliveID;

                  if(ulNewId == ptConnector->ulKeepaliveID)
                  {
                    ptConnector->ulKeepaliveID = ~ulNewId;
                  } else
                  {
                    ptConnector->ulKeepaliveID = ulNewId;
                  }

                  ptKeepAlive->ulComID       = ptConnector->ulKeepaliveID;
                  fSendAnswer                = TLR_TRUE;

                } else if(ptKeepAlive->ulComID != ptConnector->ulKeepaliveID)
                {
                  /* ComID does not match, so just return a negative Acknowledge */
                  bState = HIL_TSTATE_KEEP_ALIVE_ERROR;
                } else
                {
                  /* Everything is fine */
                  ptKeepAlive->ulComID       = ptConnector->ulKeepaliveID;
                  fSendAnswer                = TLR_TRUE;
                  bState = HIL_TRANSPORT_STATE_OK;
                }

                SendAcknowledge(ptMarshaller, ulConnector, &ptConnector->tRxHeader, bState);

                if(!fSendAnswer)
                {
                  HilMarshallerFreeBuffer(ptConnector->ptCurrentRxBuffer);
                  ptConnector->ptCurrentRxBuffer = NULL;

                } else if(TLR_S_OK != HilMarshallerConnTxData(pvMarshaller,
                                                              ulConnector,
                                                              ptConnector->ptCurrentRxBuffer))
                {
                  HilMarshallerFreeBuffer(ptConnector->ptCurrentRxBuffer);
                  ptConnector->ptCurrentRxBuffer = NULL;
                } else
                {
                  /* Prevent buffer from being freed by ResetRxStateMachine() while not transmitted completely. */
                  ptConnector->ptCurrentRxBuffer = NULL;
                }
              }
              break;

            default:
              {
                TRANSPORT_LAYER_DATA_T* ptTransport = FindTransportLayer(ptMarshaller, ptHeader->usDataType);

                if(NULL == ptTransport)
                {
                  SendAcknowledge(ptMarshaller, ulConnector, &ptConnector->tRxHeader, HIL_TSTATE_DATA_TYPE_UNKNOWN);

                  HilMarshallerFreeBuffer(ptConnector->ptCurrentRxBuffer);
                  ptConnector->ptCurrentRxBuffer = NULL;

                } else
                {
                  int iLock;

                  SendAcknowledge(ptMarshaller, ulConnector, &ptConnector->tRxHeader, HIL_TRANSPORT_STATE_OK);

                  /* Enqueue this request into list, and let user handle it in it's own task
                     We need to set the current Rx Buffer to NULL, so that ResetRxStateMachine won't
                     free it. */
                  ptConnector->ptCurrentRxBuffer = NULL;

                  iLock = OS_LOCK();
                  STAILQ_INSERT_TAIL(&ptMarshaller->tPendingRequests, ptBuffer, tList);
                  OS_UNLOCK(iLock);

                  ptMarshaller->pfnRequest(ptMarshaller, ptMarshaller->pvUser);
                }
              }
              break;
            }
          }

          /* Reset state machine */
          ResetRxStateMachine(ptConnector);

          /* Check if we have processed all incoming data */
          if( 0 == ulDataCnt)
          {
            /* Start with scan for cookie */
            fDone = 1;
          }
        }
        break;

        default:
          ;
        break;
      } /* end switch state */

    } while (0 == fDone);
  }

  return eRet;
}

/*****************************************************************************/
/*! Called by transport when new data should be send to line
*    \param pvMarshaller     Marshaller handle
*    \param ulConnector      Connector number
*    \param ptBuffer         Outgoing data
*    \return TLR_S_OK on success                                             */
/*****************************************************************************/
TLR_RESULT HilMarshallerConnTxData(void* pvMarshaller, TLR_UINT32 ulConnector, HIL_MARSHALLER_BUFFER_T* ptBuffer)
{
  HIL_MARSHALLER_DATA_T* ptMarshaller = (HIL_MARSHALLER_DATA_T*)pvMarshaller;
  CONNECTOR_DATA_T*      ptConn       = &ptMarshaller->atConnectors[ulConnector];

  ptBuffer->tTransport.ulLength = ptBuffer->tMgmt.ulUsedDataBufferLen;

  if(ptBuffer->tTransport.ulLength > 0)
  {
    ptBuffer->tTransport.usChecksum = CalculateCRC16(ptBuffer->abData,
                                                     ptBuffer->tTransport.ulLength);
  } else
  {
    ptBuffer->tTransport.usChecksum = 0;
  }

  return ptConn->tConn.pfnTransmit(ptBuffer, ptConn->tConn.pvUser);
}

/*****************************************************************************/
/*! Called by connector data has been sent
*    \param pvMarshaller     Marshaller handle
*    \param ulConnector      Connector number
*    \param ptBuffer         Outgoing data buffer
*    \return TLR_S_OK on success                                             */
/*****************************************************************************/
TLR_RESULT HilMarshallerConnTxComplete(void* pvMarshaller, TLR_UINT32 ulConnector, HIL_MARSHALLER_BUFFER_T* ptBuffer)
{
  HilMarshallerFreeBuffer(ptBuffer);

  return TLR_S_OK;
}

/*****************************************************************************/
/*! Called by transport layer, during initialization.
*    \param pvMarshaller     Marshaller handle
*    \param ptLayerData      Layer registration data
*    \return TLR_S_OK on success                                             */
/*****************************************************************************/
TLR_RESULT HilMarshallerRegisterTransport(void* pvMarshaller, const TRANSPORT_LAYER_DATA_T* ptLayerData)
{
  HIL_MARSHALLER_DATA_T* ptMarshaller = (HIL_MARSHALLER_DATA_T*)pvMarshaller;
  TLR_RESULT eRet;

  if(0 == ptLayerData->usDataType)
  {
    eRet = HIL_MARSHALLER_E_INVALIDPARAMETER;

  } else if(NULL != FindTransportLayer(ptMarshaller, ptLayerData->usDataType))
  {
    /* Another Transport layer is already registered for this datatype (configuration error) */
    eRet = HIL_MARSHALLER_E_ALREADYREGISTERED;
  } else
  {
    TLR_UINT32 ulIdx;

    eRet = HIL_MARSHALLER_E_OUTOFRESOURCES;

    /* Search first free array element */
    for(ulIdx = 0; ulIdx < ptMarshaller->ulTransports; ++ulIdx)
    {
      TRANSPORT_LAYER_DATA_T* ptLayer = &ptMarshaller->ptTransports[ulIdx];

      if(0 == ptLayer->usDataType)
      {
        *ptLayer = *ptLayerData;
        eRet = TLR_S_OK;
        break;
      }
    }
  }

  return eRet;
}

/*****************************************************************************/
/*! Called by transport layer, during uninitialization.
*    \param pvMarshaller     Marshaller handle
*    \param usDataType       Datatype the layer was registered at           */
/*****************************************************************************/
void HilMarshallerUnregisterTransport(void* pvMarshaller, TLR_UINT16 usDataType)
{
  HIL_MARSHALLER_DATA_T*  ptMarshaller = (HIL_MARSHALLER_DATA_T*)pvMarshaller;
  TRANSPORT_LAYER_DATA_T* ptLayer      = FindTransportLayer(ptMarshaller, usDataType);

  if(ptLayer != NULL)
  {
    memset(ptLayer, 0, sizeof(*ptLayer));
  }
}

/*****************************************************************************/
/*! Cyclic timer event, which needs to be called by user for timeout management
*    \param pvMarshaller     Marshaller handle                              */
/*****************************************************************************/
void HilMarshallerTimer(void* pvMarshaller)
{
  TLR_UINT32              ulIdx;
  HIL_MARSHALLER_DATA_T*  ptMarshaller = (HIL_MARSHALLER_DATA_T*)pvMarshaller;

  /* Check all transports for polling functions */
  for(ulIdx = 0; ulIdx < ptMarshaller->ulTransports; ++ulIdx)
  {
    TRANSPORT_LAYER_DATA_T* ptLayer = &ptMarshaller->ptTransports[ulIdx];

    if(ptLayer->pfnPoll)
      ptLayer->pfnPoll(ptLayer->pvUser);
  }

  /* Check all connectors for polling functions */
  for(ulIdx = 0; ulIdx < ptMarshaller->ulMaxConnectors; ++ulIdx)
  {
    CONNECTOR_DATA_T* ptConn = &ptMarshaller->atConnectors[ulIdx];

    /* Timeout management for all connector Rx state machines */
    /* Check if the RX state machine is active */
    if(ptConn->fMonitorTimeout)
    {
      /* Incremet the elapsed time */
      ptConn->ulElapsedTime += 10;

      if( ptConn->tConn.ulTimeout < ptConn->ulElapsedTime)
      {
        ResetRxStateMachine( ptConn);
      }
    }

    if(ptConn->fInUse && ptConn->tConn.pfnPoll)
      ptConn->tConn.pfnPoll(ptConn->tConn.pvUser);
  }
}

/*****************************************************************************/
/*! Main marshaller module. This must be called by user, every time it receives
*   the pfnRequest callback.
*    \param pvMarshaller     Marshaller handle
*    \return TLR_S_OK on success
*    \and TLR_E_FAIL if no message retrieved from the pending requests list  */
/*****************************************************************************/
TLR_RESULT HilMarshallerMain(void* pvMarshaller)
{
  TLR_RESULT               eRet            = TLR_S_OK;
  HIL_MARSHALLER_DATA_T*   ptMarshaller    = (HIL_MARSHALLER_DATA_T*) pvMarshaller;
  int                      iLock           = 0;
  HIL_MARSHALLER_BUFFER_T* ptBuffer        = NULL;
  TRANSPORT_LAYER_DATA_T*  ptTransport     = NULL;
  CONNECTOR_DATA_T*        ptConn          = NULL;

  if (ptMarshaller == NULL)
    eRet = TLR_E_FAIL;
  else
  {
    iLock    = OS_LOCK();
    ptBuffer = STAILQ_FIRST(&ptMarshaller->tPendingRequests);
    OS_UNLOCK(iLock);
    if (ptBuffer == NULL)
      eRet = TLR_E_FAIL;
    else
    {
      ptTransport = FindTransportLayer(ptMarshaller, ptBuffer->tTransport.usDataType);
      ptConn      = &ptMarshaller->atConnectors[ptBuffer->tMgmt.ulConnectorIdx];
      if (ptTransport == NULL || ptConn == NULL)
        eRet = TLR_E_FAIL;
      else
      {
        iLock = OS_LOCK();
        STAILQ_REMOVE(&ptMarshaller->tPendingRequests, ptBuffer, HIL_MARSHALLER_BUFFER_Ttag, tList);
        OS_UNLOCK(iLock);

        ptTransport->pfnHandler(ptMarshaller, ptBuffer, ptTransport->pvUser);
      }
    }
  }
  return eRet;
}


/*****************************************************************************/
/*! HilMarshallerSetMode() sets the mode (unrestricted / restricted / disabled)
*   either of a single connector or of all connectors.
*   \param pvMarshaller     Marshaller handle
*   \param ulMode           see MARSHALLER_MODE_xxx constants above
*   \param ulConnectorID    connector index or MARSHALLER_CONNECTORS_ALL
*   \return TLR_S_OK        on success
*   \ HIL_MARSHALLER_E_INVALIDPARAMETER  if mode invalid
*   \ HIL_MARSHALLER_E_OUTOFRESOURCES    if connector reference invalid      */
/*****************************************************************************/

TLR_RESULT HilMarshallerSetMode(void*      pvMarshaller,
                                TLR_UINT32 ulMode,
                                TLR_UINT32 ulConnectorID)

{
  TLR_RESULT             eRet         = TLR_S_OK;
  HIL_MARSHALLER_DATA_T* ptMarshaller = (HIL_MARSHALLER_DATA_T*)pvMarshaller;
  TLR_UINT32             ulIndex;
  TLR_UINT32             ulMinConnectorID = ulConnectorID;
  TLR_UINT32             ulMaxConnectorID = ulConnectorID;

  /* check the scope of the command (single connector / all connectors) */
  if (ulConnectorID == HIL_MARSHALLER_CONNECTORS_ALL)
  { /* change mode of all connectors */
    ulMinConnectorID = 0;
    ulMaxConnectorID = ptMarshaller->ulMaxConnectors;
  }
  else
  { /* check the given connector index */
    if (ulConnectorID > ptMarshaller->ulMaxConnectors)
      eRet = HIL_MARSHALLER_E_OUTOFRESOURCES;
  }
  if (eRet == TLR_S_OK)
  {
    switch (ulMode)
    {
      case HIL_MARSHALLER_MODE_ENABLED:
      { /* set mode for a single connector or for all connectors */
        for (ulIndex = ulMinConnectorID; ulIndex < ulMaxConnectorID; ulIndex++)
          ptMarshaller->atConnectors[ulIndex].ulMode = ulMode;
        break;
      }
      case HIL_MARSHALLER_MODE_DISABLED:
      { /* set mode for a single connector or for all connectors */
        for (ulIndex = ulMinConnectorID; ulIndex < ulMaxConnectorID; ulIndex++)
          ptMarshaller->atConnectors[ulIndex].ulMode = ulMode;
        break;
      }
      default:
      { /* invalid mode parameter */
        eRet = HIL_MARSHALLER_E_INVALIDPARAMETER;
      }
    }
  }
  return (eRet);
}


/*****************************************************************************/
/*! \}                                                                       */
/*****************************************************************************/
