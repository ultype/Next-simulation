/**************************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 **************************************************************************************

   Filename:
    $Id: OS_Includes.h 1206 2010-04-15 11:59:09Z sebastiand $
   Last Modification:
    $Author: sebastiand $
    $Date: 2010-04-15 13:59:09 +0200 (Thu, 15 Apr 2010) $
    $Revision: 1206 $

   Targets:
     Linux        : yes

   Description:
    OS Dependent function declaration. These functions must be implemented to allow 
    abstraction from the operating system

   Changes:

     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
     1        25.05.2010   SD       initial version
 

**************************************************************************************/
#ifndef __OS_INCLUDES__H
#define __OS_INCLUDES__H

#ifdef __cplusplus
extern "C"
{
#endif

#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <unistd.h>

#include <sys/time.h>
#include <signal.h>


#ifndef NULL
  #define NULL  ((void*)0)
#endif

#ifndef UNREFERENCED_PARAMETER
  #define UNREFERENCED_PARAMETER(a) (a=a)
#endif

#define SOCKET int
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

#define TYPE_FD_SET fd_set
#define BOOL bool
#define TRUE true

void*            OS_MALLOC      (uint32_t ulSize);
void             OS_FREE        (void* pvMem);
#define          OS_MEMCPY      memcpy

int              OS_STRNICMP    (const char* pszBuf1, const char* pszBuf2, uint32_t ulLen);
#define          OS_STRNCPY     strncpy

uint32_t         OS_GETTICKCOUNT(void);

pthread_mutex_t* OS_CREATELOCK  (void);
int              OS_LOCK        (void);
void             OS_UNLOCK      (int iLock);
void             OS_DELETELOCK  (pthread_mutex_t* mutex);


#ifdef __cplusplus
}
#endif

#endif /* __OS_INCLUDES__H */
