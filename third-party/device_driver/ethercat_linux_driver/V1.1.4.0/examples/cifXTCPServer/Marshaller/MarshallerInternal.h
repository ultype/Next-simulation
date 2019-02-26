/**************************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 **************************************************************************************

   Filename:
    $Id: MarshallerInternal.h 1866 2010-07-06 10:38:23Z MichaelT $
   Last Modification:
    $Author: MichaelT $
    $Date: 2010-07-06 12:38:23 +0200 (Tue, 06 Jul 2010) $
    $Revision: 1866 $

   Targets:
     OS independent : yes

   Description:
    Marshaller internal structure definitions

   Changes:

     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
     5        06.07.2010   MT       Change:
                                     - Re-Added Tx Buffers, as they were used by 
                                       Packet Transport
                                     - Added new configuration elements per 
                                       connector for configuration of TX Buffers (see HIL_MARSHALLER_CONNECTOR_T)
     4        23.09.2009   MS       Change:
                                     - Removed unused Tx buffers and doubled number of Rx buffers to avoid resource errors without increasing memory footprint.
     3        22.09.2009   MS       Addon:
                                     - Added member ulMode to CONNECTOR_DATA_T.
     2        28.07.2009   MS       Change:
                                     - Moved Marshaller version constants to MarshallerVersion.h.
     1        25.05.2009   MT       initial version

**************************************************************************************/

/*****************************************************************************/
/*! \file MarshallerInternal.h
*   Internal structure and API definitions of the netX Marshaller            */
/*****************************************************************************/

#ifndef __MARSHALLERINTERNAL__H
#define __MARSHALLERINTERNAL__H

#include "cifXAPI_Wrapper.h"
#include "MarshallerConfig.h"
#include "HilTransport.h"
#include <sys/queue.h>

/*****************************************************************************/
/*! \addtogroup NETX_MARSHALLER_INTERNAL
*   \{                                                                       */
/*****************************************************************************/

#ifdef __cplusplus
  extern "C" {
#endif

typedef enum MARSHALLER_BUFFER_TYPE_Etag
{
  eMARSHALLER_RX_BUFFER,
  eMARSHALLER_TX_BUFFER,
  eMARSHALLER_ACK_BUFFER,
  eMARSHALLER_KEEPALIVE_BUFFER,

} MARSHALLER_BUFFER_TYPE_E;

/*****************************************************************************/
/*! Marshaller Send/Receive buffer structure                                 */
/*****************************************************************************/
struct HIL_MARSHALLER_BUFFER_Ttag
{
  /* Single linked list */
  STAILQ_ENTRY(HIL_MARSHALLER_BUFFER_Ttag) tList;

  struct
  {
    TLR_UINT32  ulConnectorIdx;       /*!< Connector number of this buffer */
    void*       pvMarshaller;         /*!< Marshaller object this buffer has been allocated by */

    MARSHALLER_BUFFER_TYPE_E eType;   /*!< Type of buffer */

    TLR_UINT32  ulDataBufferLen;      /*!< Total length of buffer (only counting the size of abData[] */
    TLR_UINT32  ulUsedDataBufferLen;  /*!< Number of used bytes in abData[] */

    TLR_UINT32  ulActualSendOffset;   /*!< Can be used by connector for fragmented sending   */
  } tMgmt;

  HIL_TRANSPORT_HEADER  tTransport;   /*!< Transport header */
  TLR_UINT8             abData[1];    /*!< User data        */
};

typedef struct HIL_MARSHALLER_BUFFER_Ttag HIL_MARSHALLER_BUFFER_T;

typedef TLR_RESULT(*PFN_CONN_TRANSMIT)(HIL_MARSHALLER_BUFFER_T* ptBuffer, void* pvUser);
typedef void(*PFN_CONN_DEINIT)(void* pvUser);
typedef void(*PFN_CONN_POLL)(void* pvUser);

/*****************************************************************************/
/*! Connector registration information (filled by Connector)                 */
/*****************************************************************************/
typedef struct HIL_MARSHALLER_CONNECTOR_Ttag
{
  PFN_CONN_TRANSMIT pfnTransmit;  /*!< Transmit function         */
  PFN_CONN_DEINIT   pfnDeinit;    /*!< Uninitialization function */
  PFN_CONN_POLL     pfnPoll;      /*!< Function to call, if the connector needs to be polled */

  TLR_UINT32        ulDataBufferSize; /*!< Size for the RX buffers in Bytes */
  TLR_UINT32        ulDataBufferCnt;  /*!< Number of RX buffers to allocate per Connector */
  TLR_UINT32        ulTimeout;        /*!< Timeout for RX state machine */

  void*             pvUser;           /*!< User parameter to provide on function calls */

  /* NOTE: These information were added to the end of the structure to be old
           compatible. When using the previous structure initializations these fields
           will automatically be set to 0 */
  TLR_UINT32        ulTxBufferSize;   /*!< TX Buffer size for unsolicited packets / calls (indication / callbacks)  */
  TLR_UINT32        ulTxBufferCnt;    /*!< TX Buffer count for unsolicited packets / calls (indication / callbacks) */

} HIL_MARSHALLER_CONNECTOR_T;

typedef void(*PFN_TRANSPORT_HANDLER)(void* pvMarshaller, HIL_MARSHALLER_BUFFER_T* ptBuffer, void* pvUser);
typedef void(*PFN_TRANSPORT_DEINIT)(void* pvUser);
typedef void(*PFN_TRANSPORT_POLL)(void* pvUser);

/*****************************************************************************/
/*! Transport layer registration information                                 */
/*****************************************************************************/
typedef struct TRANSPORT_LAYER_DATA_Ttag
{
  TLR_UINT16            usDataType;
  TLR_UINT16            usReserved;
  PFN_TRANSPORT_HANDLER pfnHandler;
  PFN_TRANSPORT_DEINIT  pfnDeinit;
  PFN_TRANSPORT_POLL    pfnPoll;
  void*                 pvUser;
} TRANSPORT_LAYER_DATA_T;

/* This function is called by a connector when it receives data from the line */
TLR_RESULT HilMarshallerConnRxData(void* pvMarshaller, TLR_UINT32 ulConnector, TLR_UINT8* pbData, TLR_UINT32 ulDataCnt);

/* This function is called by a transport, to send an answer */
TLR_RESULT HilMarshallerConnTxData(void* pvMarshaller, TLR_UINT32 ulConnector, HIL_MARSHALLER_BUFFER_T* ptBuffer);

/* This function is called by a connector, to signal transfer complete */
TLR_RESULT HilMarshallerConnTxComplete(void* pvMarshaller, TLR_UINT32 ulConnector, HIL_MARSHALLER_BUFFER_T* ptBuffer);

/* Connector registration/deregistration */
TLR_RESULT HilMarshallerRegisterConnector(void* pvMarshaller, TLR_UINT32* pulConnectorIdx, HIL_MARSHALLER_CONNECTOR_T* ptConn);
void       HilMarshallerUnregisterConnector(void* pvMarshaller, TLR_UINT32 ulConnectorIdx);

/* Register data transport layers */
TLR_RESULT HilMarshallerRegisterTransport(void* pvMarshaller, const TRANSPORT_LAYER_DATA_T* ptLayerData);
void       HilMarshallerUnregisterTransport(void* pvMarshaller, TLR_UINT16 usDataType);

void                     HilMarshallerFreeBuffer(HIL_MARSHALLER_BUFFER_T* ptBuffer);
HIL_MARSHALLER_BUFFER_T* HilMarshallerGetBuffer(void* pvMarshaller, MARSHALLER_BUFFER_TYPE_E eType, TLR_UINT32 ulConnector);


/*****************************************************************************/
/*! Enum for the receive data state machine                                  */
/*****************************************************************************/
typedef enum
{
  HIL_SCAN_DONE   = 0,
  HIL_SEARCH_TELEGRAM_COOKIE,
  HIL_SEARCH_TELEGRAM_HEADER,
  HIL_WAIT_TELEGRAM_DATA,
  HIL_CHECK_TELEGRAM
} HIL_SCAN_STATE_E;

STAILQ_HEAD(MARSHALLER_BUFFER_HEAD, HIL_MARSHALLER_BUFFER_Ttag);

/*****************************************************************************/
/*! Marshaller internal connector data storage                               */
/*****************************************************************************/
typedef struct CONNECTOR_DATA_Ttag
{
  TLR_BOOLEAN                   fInUse;           /*!< TRUE if connector slot is in use (contains a registered connector) */
  TLR_UINT32                    ulConnectorIdx;   /*!< Number of the connector */
  TLR_UINT32                    ulMode;           /*!< connector mode, see MARSHALLER_MODE_xxx constants */

  /* Connector Registration data */
  HIL_MARSHALLER_CONNECTOR_T    tConn;            /*!< Registration data */

  /* Data for parsing RX telegram data */
  HIL_SCAN_STATE_E              eScanState;       /*!< Current state of receive state machine                       */
  HIL_TRANSPORT_HEADER          tRxHeader;        /*!< Transport header used by parser for start of frame detection */
  TLR_UINT32                    ulRxOffset;       /*!< Current receive offset inside tRxHeader (used by parser)     */
  TLR_BOOLEAN                   fMonitorTimeout;  /*!< TRUE if timeout should be monitored                          */
  TLR_UINT32                    ulElapsedTime;    /*!< Time since last scanner process, used for RX data timeout    */

  TLR_UINT32                    ulKeepaliveID;    /*!< Last valid keep alive ID */

  HIL_MARSHALLER_BUFFER_T*      ptCurrentRxBuffer;/*!< Current used RX buffer to collect data                       */

  /* RX / Ack Buffer list */
  struct MARSHALLER_BUFFER_HEAD tRxBuffer;
  struct MARSHALLER_BUFFER_HEAD tTxBuffer;
  struct MARSHALLER_BUFFER_HEAD tAckBuffer;
  struct MARSHALLER_BUFFER_HEAD tKeepAliveBuffer;

} CONNECTOR_DATA_T;

/*****************************************************************************/
/*! Marshaller data storage                                                  */
/*****************************************************************************/
typedef struct HIL_MARSHALLER_DATA_Ttag
{
  char                          szServerName[HIL_TRANSPORT_QUERYSERVER_NAMELEN];
  TLR_UINT32                    ulMaxConnectors;  /*!< Maximum number of connectors (size of atConnectors[]) */
  CONNECTOR_DATA_T*             atConnectors;     /*!< Array of available connectors */

  /* cifX API Layer configuration */
  TLR_UINT32                    ulTransports;     /*!< Number of available transport handler                 */
  TRANSPORT_LAYER_DATA_T*       ptTransports;     /*!< Array of available transport handler                  */

  struct MARSHALLER_BUFFER_HEAD tPendingRequests;

  PFN_MARSHALLER_REQUEST        pfnRequest;
  void*                         pvUser;

}  HIL_MARSHALLER_DATA_T;

#ifdef __cplusplus
  }
#endif


/*****************************************************************************/
/*! \}                                                                       */
/*****************************************************************************/

#endif /*  __MARSHALLERINTERNAL__H */
