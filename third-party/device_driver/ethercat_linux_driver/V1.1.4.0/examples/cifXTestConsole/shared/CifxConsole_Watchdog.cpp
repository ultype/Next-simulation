/**************************************************************************************
 
   Copyright (c) Hilscher GmbH. All Rights Reserved.
 
 **************************************************************************************
 
   Filename:
    $Workfile: CifxTest_Watchdog.cpp
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
     starts watchdog and display WatchDogValue
          
   Changes:
 
     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
     1         21.07.2010  RM       initial version
 
     
**************************************************************************************/
#include "OS_Includes.h"
#include "CifXConsole.h"

/*===========================================================================*/
/* Test Watchdog                                                             */
/*                                                                           */
/*                                                                           */
/*===========================================================================*/
void TestWatchdog( CIFXHANDLE hDriver, char* szBoard)
{
  printf("\n--- Test Watchdog ---\r\n");  

  int32_t lRet = CIFX_NO_ERROR;
    
  // Open channel
  CIFXHANDLE hDevice = NULL;
  lRet = xChannelOpen(hDriver, szBoard, 0, &hDevice);
  if(lRet != CIFX_NO_ERROR)
  {
    ShowError(lRet);
  } else
  {
    uint32_t ulWatchdogValue = 0;    

    lRet = xChannelWatchdog( hDevice, CIFX_WATCHDOG_START, &ulWatchdogValue);
    ShowError(lRet);

    if ( lRet == CIFX_NO_ERROR)    
    {
      
      printf("\n Display WatchDogValue. Press (Q) to stop... \r\n");
      do
      {
        OS_Sleep (10);

        lRet = xChannelWatchdog( hDevice, CIFX_WATCHDOG_START, &ulWatchdogValue);
        ShowError(lRet);
          
        // Display Wtachdog value
        printf("--> Watchdog Value = %d\n", ulWatchdogValue);
      }while(!OS_KbHit());

      lRet = xChannelWatchdog( hDevice, CIFX_WATCHDOG_STOP, &ulWatchdogValue);
      ShowError(lRet);
    }

    // Stop Watchdog checking
    printf("Watchdog test done\r\n");  
  } 
  
  // Close channel
  if( hDevice != NULL) xChannelClose(hDevice);
}
