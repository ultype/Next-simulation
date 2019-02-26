/**************************************************************************************
 
   Copyright (c) Hilscher GmbH. All Rights Reserved.
 
 **************************************************************************************
 
   Filename:
    $Workfile: CifxConsole_Packet.cpp
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
     demonstrate packet communication
       
   Changes:
 
     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
     1         21.07.2010  RM       initial version
 
     
**************************************************************************************/
#include "OS_Includes.h"
#include "CifXConsole.h"

/*===========================================================================*/
/* Send / Receive packet                                                     */
/*                                                                           */
/*                                                                           */
/*===========================================================================*/
void SendReceivePacket( CIFXHANDLE hDriver, char* szBoard)
{
  int32_t lRet = CIFX_NO_ERROR;

  uint32_t      ulReceiveCount  = 0;
  uint32_t      ulSendCount     = 0;
  CIFX_PACKET   tSendPacket     = {{0}};
  CIFX_PACKET   tRecvPacket     = {{0}};

  printf("\n--- Send / Receive a Packet ---\r\n");  
  
  // Open channel
  CIFXHANDLE hDevice = NULL;
  lRet = xChannelOpen(hDriver, szBoard, 0, &hDevice);
  if(lRet != CIFX_NO_ERROR)
  {
    // Read driver error description
    ShowError( lRet);
  } else
  {
    //------------------------------
    // Read all available packet
    //------------------------------
    // Get actual packet state    
    lRet = xChannelGetMBXState( hDevice, &ulReceiveCount, &ulSendCount);
    while (ulReceiveCount > 0)
    {
      // Read packet
      lRet = xChannelGetPacket( hDevice, sizeof(tRecvPacket), &tRecvPacket, 1000);
      ulReceiveCount--;
    }
    
    //------------------------------
    // Get send packet
    //------------------------------
    lRet = xChannelGetSendPacket( hDevice, sizeof(tRecvPacket), &tRecvPacket);
    ShowError(lRet);

    //------------------------------
    // Create send packet
    //------------------------------
    tSendPacket.tHeader.ulSrc   = 0;
    tSendPacket.tHeader.ulDest  = 0;
    tSendPacket.tHeader.ulCmd   = 0;
    tSendPacket.tHeader.ulLen   = 0;
    tSendPacket.tHeader.ulState = 0;
    tSendPacket.tHeader.ulExt   = 0;
    
    printf("\n Sending/recieving packets. Press (Q) to stop... \r\n");
    do
    {
      //------------------------------
      // Put packet
      //------------------------------
      lRet = xChannelPutPacket(hDevice, &tSendPacket, 1000);
      
      printf( "Send Packet\n" \
              "-----------\n" \
              "Source : 0x%08X\n" \
              "Dest   : 0x%08X\n" \
              "Cmd    : 0x%08X\n" \
              "Len    : 0x%08X\n" \
              "Id     : 0x%08X\n" \
              "State  : 0x%08X\n" \
              "Ext    : 0x%08X\n" \
              "lRet   : 0x%08X\n",
              tSendPacket.tHeader.ulSrc,   tSendPacket.tHeader.ulDest, 
              tSendPacket.tHeader.ulCmd,   tSendPacket.tHeader.ulLen, tSendPacket.tHeader.ulId,
              tSendPacket.tHeader.ulState, tSendPacket.tHeader.ulExt,
              lRet);

      //------------------------------
      // Get packet
      //------------------------------
      lRet = xChannelGetPacket(hDevice, sizeof(tRecvPacket), &tRecvPacket, 1000);
      
      printf( "Received Packet\n" \
              "---------------\n" \
              "Source : 0x%08X\n" \
              "Dest   : 0x%08X\n" \
              "Cmd    : 0x%08X\n" \
              "Len    : 0x%08X\n" \
              "Id     : 0x%08X\n" \
              "State  : 0x%08X\n" \
              "Ext    : 0x%08X\n" \
              "lRet   : 0x%08X\n",
              tRecvPacket.tHeader.ulSrc,   tRecvPacket.tHeader.ulDest, 
              tRecvPacket.tHeader.ulCmd,   tRecvPacket.tHeader.ulLen, tRecvPacket.tHeader.ulId,
              tRecvPacket.tHeader.ulState, tRecvPacket.tHeader.ulExt,
              lRet);

      tSendPacket.tHeader.ulId++;
    }while(!OS_KbHit());
    
    // Close channel
    if( hDevice != NULL) xChannelClose(hDevice);
  } 

  printf("\n Send / Receive a Packet done\r\n");  
}

