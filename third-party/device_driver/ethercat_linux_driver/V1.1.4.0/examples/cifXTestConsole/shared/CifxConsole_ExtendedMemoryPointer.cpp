/**************************************************************************************
 
   Copyright (c) Hilscher GmbH. All Rights Reserved.
 
 **************************************************************************************
 
   Filename:
    $Workfile: CifxConsole_ExtendedMemoryPointer.cpp
   Last Modification:
    $Author: $
    $Modtime: $
    $Revision: $
   
   Targets:
     Win32        : yes
     WinCE 5      : yes
     WinCE 6      : yes
     Linux        : yes
 
   Description:
     
       
   Changes:
 
     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
     1         17.01.2012  SD       initial version
 
     
**************************************************************************************/
#include "OS_Includes.h"
#include "CifXConsole.h"

//=============================================================================
// Test memory pointer
//
//
//=============================================================================
void TestExtendedMemoryPointer( CIFXHANDLE hDriver, char* szBoard)
{
  CIFXHANDLE    hSysdevice    = NULL;
  int32_t       lRet          = CIFX_NO_ERROR;
  uint8_t       abBuffer[100] = {0};
  
  printf("\n--- Test Extended Memory Pointer ---\r\n");  

  lRet = xSysdeviceOpen( hDriver, szBoard, &hSysdevice);

  if ( CIFX_NO_ERROR != lRet)
  {
    ShowError( lRet);
  } else  
  {
    CIFX_EXTENDED_MEMORY_INFORMATION tExtMemory = {0};
    
    // Open a DPM memory pointer
    lRet = xSysdeviceExtendedMemory( hSysdevice, CIFX_GET_EXTENDED_MEMORY_INFO, &tExtMemory);
    if(lRet != CIFX_NO_ERROR)
    {
      // Failed to get the memory mapping
      printf("xSysdeviceExtendedMemory(): Failed to read the extended memory information, Error: 0x%X\r\n", lRet);
      ShowError( lRet);
    } else
    {
      
      printf("Extended Memory Information: Size = %u, Type = 0x%.8x\n",
              tExtMemory.ulMemorySize,
              tExtMemory.ulMemoryType);
      
      
      /* Get an extended memory pointer */
      lRet = xSysdeviceExtendedMemory( hSysdevice, CIFX_GET_EXTENDED_MEMORY_POINTER, &tExtMemory);
      if(lRet != CIFX_NO_ERROR)
      {
        // Failed to get the memory mapping
        printf("xSysdeviceExtendedMemory(): Failed to get an extended Memory pointer, Error: 0x%X\r\n", lRet);
        ShowError( lRet);
      } else
      {
        // We have a memory mapping 
        uint8_t* pbExtMem = (uint8_t*)tExtMemory.pvMemoryPtr;
        uint32_t ulIdx    = 0;
        
        printf("\n Press (Q) to stop to stop the extended read/write test\r\n");
        do
        {
          // Read 100 Bytes
          OS_Memcpy( abBuffer, pbExtMem, sizeof(abBuffer));

          printf("Read data from the extended memory (%li bytes):\n",
                 sizeof(abBuffer));
          
          for (ulIdx = 0;ulIdx<sizeof(abBuffer);ulIdx++)
          {
            if (0 == (ulIdx % 16))
              printf("\n");  
            printf("0x%02X ", abBuffer[ulIdx]);
          }
            
          printf("\nIncrement the read data:\n");
          for ( uint32_t ulIdx =0; ulIdx < sizeof(abBuffer); ulIdx++)
          {
            abBuffer[ulIdx] +=1;
          }

          printf("Write data back to the extened memory:\n");
          OS_Memcpy( pbExtMem, abBuffer, sizeof(abBuffer));

        }while(!OS_KbHit());

        lRet = xSysdeviceExtendedMemory( hSysdevice, CIFX_FREE_EXTENDED_MEMORY_POINTER, &tExtMemory);
        if(lRet != CIFX_NO_ERROR)
        {
          // Failed to free the memory mapping
          printf("xSysdeviceExtendedMemory(): Failed to free the extended memory pointer, Error: 0x%X\r\n", lRet);
          ShowError( lRet);
        }
      }
    } 
  
    /* Close the system device */
    lRet = xSysdeviceClose( hSysdevice);
    if ( CIFX_NO_ERROR != lRet)
    {
      ShowError( lRet);
    }
  }

  // Test done
  printf("\n Extended Memory Pointer test done\r\n");
 
}
