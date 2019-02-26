/**************************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 **************************************************************************************

   Filename:
    $Id: MarshallerConfig.h 1866 2010-07-06 10:38:23Z MichaelT $
   Last Modification:
    $Author: MichaelT $
    $Date: 2010-07-06 12:38:23 +0200 (Tue, 06 Jul 2010) $
    $Revision: 1866 $

   Targets:
     OS independent : yes

   Description:
    Public Hilscher transport marshaller definitions

   Changes:

     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
     4        06.07.2010   MT       Change:
                                     - Added new configuration elements per 
                                       connector for configuration of TX Buffers (see HIL_MARSHALLER_CONNECTOR_PARAMS_T)
     3        22.09.2009   MS       Addon:
                                    Added HilMarshallerSetMode(), and mode constants
     2        02.09.2009   MS       Change:
                                    HilMarshallerMain() returns TLR_E_FAIL if no message can be retrieved from the pending requests list.
     1        25.05.2009   MT       initial version

**************************************************************************************/

#ifndef __MARSHALLERCONFIG__H
#define __MARSHALLERCONFIG__H

/*****************************************************************************/
/*! \addtogroup NETX_MARSHALLER_CONFIGURATION
*   \{                                                                       */
/*****************************************************************************/

#ifdef __cplusplus
  extern "C" {
#endif  /* __cplusplus */

#include "TLR_Types.h"
#include "TLR_Results.h"
#include "HilTransport.h"

/* Use generic TLR Results errors for marshaller errors */
#define  HIL_MARSHALLER_E_OUTOFMEMORY         TLR_E_OUTOFMEMORY
#define  HIL_MARSHALLER_E_INVALIDPARAMETER    TLR_E_INVALID_PARAMETER
#define  HIL_MARSHALLER_E_OUTOFRESOURCES      TLR_E_INIT_FAULT
#define  HIL_MARSHALLER_E_ALREADYREGISTERED   TLR_E_APPLICATION_ALREADY_REGISTERED

/* mode constants for Marshaller mode request */
#define HIL_MARSHALLER_MODE_ENABLED           0          /* no restrictions */
#define HIL_MARSHALLER_MODE_DISABLED          1          /* no access (connector blocked) */

/* special connector ID for Marshaller mode setup */
#define HIL_MARSHALLER_CONNECTORS_ALL         0xFFFFFFFF  /* command applies to all connectors */


struct HIL_MARSHALLER_CONNECTOR_PARAMS_Ttag;

typedef TLR_RESULT(*PFN_CONN_INIT)(const struct HIL_MARSHALLER_CONNECTOR_PARAMS_Ttag* ptParams, void* pvMarshaller);

/*****************************************************************************/
/*! Connector parameter dara (needed for registration at marshaller)         */
/*****************************************************************************/
struct HIL_MARSHALLER_CONNECTOR_PARAMS_Ttag
{
  PFN_CONN_INIT  pfnConnectorInit; /*!< Array of function pointer to initialize Connectors    */

  TLR_UINT32     ulDataBufferSize; /*!< Size for the RX buffers in Bytes */
  TLR_UINT32     ulDataBufferCnt;  /*!< Number of RX buffers to allocate per Connector */

  TLR_UINT16     usFlags;          /*! connection management flags, see HIL_MARSHALLER_CONNECTION_FLAG_xxx */
  TLR_UINT32     ulTimeout;        /*!< timeout in ms, see HIL_MARSHALLER_CONNECTION_TIMEOUT_xxx */
  void*          pvConfigData;     /*!< Depends on CONNECTION_TYPE */

  /* NOTE: These information were added to the end of the structure to be old
           compatible. When using the previous structure initializations these fields
           will automatically be set to 0 */
  TLR_UINT32        ulTxBufferSize;   /*!< TX Buffer size for unsolicited packets / calls (indication / callbacks)  */
  TLR_UINT32        ulTxBufferCnt;    /*!< TX Buffer count for unsolicited packets / calls (indication / callbacks) */
};

typedef struct HIL_MARSHALLER_CONNECTOR_PARAMS_Ttag HIL_MARSHALLER_CONNECTOR_PARAMS_T;

typedef TLR_RESULT(*PFN_TRANSPORT_INIT)(void* pvMarshaller, void* pvConfig);

/*****************************************************************************/
/*! Transport layer configuration                                            */
/*****************************************************************************/
typedef struct TRANSPORT_LAYER_CONFIG_Ttag
{
  PFN_TRANSPORT_INIT pfnInit;  /*!< Initialization function */
  void*              pvConfig; /*!< Configuration data      */

} TRANSPORT_LAYER_CONFIG_T;

typedef void(*PFN_MARSHALLER_REQUEST)(void* pvMarshaller, void* pvUser);

/*****************************************************************************/
/*! Marshaller startup parameters                                            */
/*****************************************************************************/
typedef struct HIL_MARSHALLER_PARAMS_Ttag
{
  char            szServerName[32];
  TLR_UINT32      ulMaxConnectors;               /*!< Maximum number of connectors */

  TLR_UINT32      ulConnectorCnt;                /*!< Number of connectors to automatically load at startup */
  const HIL_MARSHALLER_CONNECTOR_PARAMS_T* ptConnectors;

  /* Add transport layers, currently only cifX and rcX Packet support */
  TLR_UINT32         ulTransportCnt;             /*!< Number of transports to automatically load at startup */
  const TRANSPORT_LAYER_CONFIG_T* atTransports;  /*!< Array of function pointer to initialize Transports    */

} HIL_MARSHALLER_PARAMS_T;


/*****************************************************************************/
/*! Marshaller function prototypes                                           */
/*****************************************************************************/

TLR_RESULT HilMarshallerStart (const HIL_MARSHALLER_PARAMS_T* ptParams, void** ppvMarshHandle, PFN_MARSHALLER_REQUEST pfnRequest, void* pvUser);
void       HilMarshallerStop  (void* pvMarshHandle);
void       HilMarshallerTimer (void* pvMarshaller);
TLR_RESULT HilMarshallerMain  (void* pvMarshaller);


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
                                TLR_UINT32 ulConnectorID);

#ifdef __cplusplus
  }
#endif  /* __cplusplus */

/*****************************************************************************/
/*  \}                                                                       */
/*****************************************************************************/

#endif /* __MARSHALLERCONFIG__H */
