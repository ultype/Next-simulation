/**************************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 **************************************************************************************

   Filename:
    $Id: TCPConnector.h 1206 2010-04-15 11:59:09Z stephans $
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
     1        25.05.2009   MT       initial version

**************************************************************************************/


#ifndef __TCPCONNECTOR__H
#define __TCPCONNECTOR__H

#include "OS_Includes.h"
#include "MarshallerInternal.h"
#include "CifXTransport.h"
#include "TCPServer.h"


#ifdef __cplusplus
  extern "C" {
#endif



TLR_RESULT InitMarshaller   ( void);
void       DeinitMarshaller ( void);
TLR_RESULT TCPConnectorInit (const HIL_MARSHALLER_CONNECTOR_PARAMS_T* ptParams, void* pvMarshaller);


#ifdef __cplusplus
  }
#endif

#endif /* __TCPCONNECTOR__H */
