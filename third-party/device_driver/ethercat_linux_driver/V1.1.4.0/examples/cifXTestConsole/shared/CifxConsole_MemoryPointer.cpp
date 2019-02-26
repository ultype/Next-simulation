/**************************************************************************************
 
   Copyright (c) Hilscher GmbH. All Rights Reserved.
 
 **************************************************************************************
 
   Filename:
    $Workfile: CifXConsole_MemoryPointer.cpp
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

       
   Changes:
 
     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
     1         21.07.2010  RM       initial version
 
     
**************************************************************************************/
#include "OS_Includes.h"
#include "CifXConsole.h"

/*===========================================================================*/
/* Test memory pointer                                                       */
/*                                                                           */
/*                                                                           */
/*===========================================================================*/
void TestMemoryPointer( CIFXHANDLE hDriver)
{
  unsigned char abBuffer[100] = {0};
  
  printf("\n--- Test Memory Pointer ---\r\n");  
  
  // Open channel
  uint32_t        ulMemoryID            = 0;
  unsigned char*  pabDPMMemory          = NULL;
  uint32_t        ulMemorySize          = 0;
  uint32_t        ulChannelStartOffset  = 0;
  uint32_t        ulChannelSize         = 0;
  int32_t         lRet                  = CIFX_NO_ERROR;
  
  MEMORY_INFORMATION tMemory = {0};
  tMemory.pvMemoryID            = &ulMemoryID;            // Identification of the memory area
  tMemory.ppvMemoryPtr          = (void**)&pabDPMMemory;  // Memory pointer
  tMemory.pulMemorySize         = &ulMemorySize;          // Complete size of the mapped memory
  tMemory.ulChannel             = CIFX_NO_CHANNEL;        // Requested channel number
  tMemory.pulChannelStartOffset = &ulChannelStartOffset;  // Start offset of the requested channel
  tMemory.pulChannelSize        = &ulChannelSize;         // Memory size of the requested channel
  
  // Open a DPM memory pointer
  lRet = xDriverMemoryPointer( hDriver, 0, CIFX_MEM_PTR_OPEN, &tMemory);
  if(lRet != CIFX_NO_ERROR)
  {
    // Failed to get the memory mapping
    ShowError( lRet);
  } else
  {
      printf( "Memory ID      : %p\n" \
              "Memory Pointer : %p\n" \
              "Memory Size    : 0x%08X\n" \
              "Channel        : 0x%08X\n" \
              "Channel Offset : 0x%08X\n" \
              "Channel Size   : 0x%08X\n",
              tMemory.pvMemoryID, pabDPMMemory,
              ulMemorySize, tMemory.ulChannel, ulChannelStartOffset,
              ulChannelSize);

    // We have a memory mapping                                                   1
    // Read 100 Bytes
    OS_Memcpy( abBuffer, pabDPMMemory, sizeof(abBuffer));
    printf("DPM content:\r\n"); 
    printf("0x0000: %d (%c)\r\n", abBuffer[0], abBuffer[0]); 
    printf("0x0001: %d (%c)\r\n", abBuffer[1], abBuffer[1]); 
    printf("0x0002: %d (%c)\r\n", abBuffer[2], abBuffer[2]); 
    printf("0x0003: %d (%c)\r\n", abBuffer[3], abBuffer[3]); 
    OS_Memcpy( pabDPMMemory, abBuffer, sizeof(abBuffer));
  } 

  // Return the DPM memory pointer  
  lRet = xDriverMemoryPointer( hDriver, 0, CIFX_MEM_PTR_CLOSE, &tMemory); 
  ShowError( lRet);

  // Test done
  printf("\n Memory Pointer test done\r\n");
}
