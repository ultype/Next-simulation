/**************************************************************************************
 
   Copyright (c) Hilscher GmbH. All Rights Reserved.
 
 **************************************************************************************
 
   Filename:
    $Workfile: CifXTest_Console.h
   Last Modification:
    $Author: sebastiand $
    $Modtime: $
    $Revision: 3126 $
   
   Targets:
     Win32/ANSI   : no
     Win32/Unicode: no
     WinCE 5      : yes
     WinCE 6      : yes
     Linux        : yes
 
   Description:
     
       
   Changes:
 
     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
     1         21.07.2010  RM       initial version
 
     
**************************************************************************************/

/* prevent multiple inclusion */
#ifndef __CIFx_TEST_CONSOLE_H
#define __CIFx_TEST_CONSOLE_H

#include "cifXUser.h"
#include "cifXErrors.h"
#include "rcX_Public.h"
#include "rcX_User.h"

/***************************************************************************
* Global Functions
***************************************************************************/
void ShowError          (int32_t lError);
void RunCifXConsoleTest (char* szBoard, char* pszFirmwareFileName, char* pszConfigFileName, 
                         unsigned long ulTimerResolution, unsigned long ulIOTimeout);

#endif  /* __CIFxUSER_H */
