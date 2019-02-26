/**************************************************************************************
 
   Copyright (c) Hilscher GmbH. All Rights Reserved.
 
 **************************************************************************************
 
   Filename:
    $Workfile: CifxConsole_Download.cpp
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
     Windows CE OS Abstraction Layer implementation.
       
   Changes:
 
     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
     1         21.07.2010  RM       initial version
 
     
**************************************************************************************/
#include "OS_Includes.h"
#include "CifXConsole.h"

/*===========================================================================*/
/* Progress Callback                                                         */
/*                                                                           */
/*                                                                           */
/*===========================================================================*/
static void APIENTRY ProgressCallback(uint32_t ulStep, uint32_t ulMaxStep, void* /*pvUser*/, int8_t /*bFinished*/, int32_t /*lError*/)
{
  printf("%3d%%", ulStep*100/ulMaxStep);
}

/*===========================================================================*/
/* Send configuration request                                                */
/*                                                                           */
/*                                                                           */
/*===========================================================================*/
bool SendConfigRequest( CIFXHANDLE hDevice)
{
  int32_t lRet = CIFX_NO_ERROR;

  uint32_t      ulReceiveCount  = 0;
  uint32_t      ulSendCount     = 0;
  CIFX_PACKET   tSendPacket     = {{0}};
  CIFX_PACKET   tRecvPacket     = {{0}};
  
   //------------------------------
  // Read all available packet
  //------------------------------
  // Get actual packet state    
  lRet = xChannelGetMBXState(hDevice, &ulReceiveCount, &ulSendCount);
  while (ulReceiveCount > 0)
  {
    // Read packet
    lRet = xChannelGetPacket(hDevice, sizeof(tRecvPacket), &tRecvPacket, 1000);
    ulReceiveCount--;
  }
  
  //------------------------------
  // Send packet to hardware
  //------------------------------
  tSendPacket.tHeader.ulSrc   = 0;
  tSendPacket.tHeader.ulDest  = RCX_PACKET_DEST_DEFAULT_CHANNEL;
  tSendPacket.tHeader.ulCmd   = RCX_CHANNEL_INIT_REQ;
  tSendPacket.tHeader.ulLen   = 0;
  tSendPacket.tHeader.ulState = 0;
  tSendPacket.tHeader.ulExt   = 0;
  
  // Send packet
  lRet = xChannelPutPacket(hDevice, &tSendPacket, 1000);

  printf( "Send Configuration Request\r\n" \
          "--------------------------\n" \
          "Source : 0x%08X\n" \
          "Dest   : 0x%08X\n" \
          "Cmd    : 0x%08X\n" \
          "Len    : 0x%08X\n" \
          "State  : 0x%08X\n" \
          "Ext    : 0x%08X\n" \
          "lRet   : 0x%X\n",
          tSendPacket.tHeader.ulSrc,   tSendPacket.tHeader.ulDest, 
          tSendPacket.tHeader.ulCmd,   tSendPacket.tHeader.ulLen,
          tSendPacket.tHeader.ulState, tSendPacket.tHeader.ulExt,
          lRet);

  //------------------------------
  // Read packet
  //------------------------------
  lRet = xChannelGetPacket(hDevice, sizeof(tRecvPacket), &tRecvPacket, 1000);

  printf("Received Configuration Request Confirmation\n" \
        "--------------------------------------------\n" \
        "Source : 0x%08X\n" \
        "Dest   : 0x%08X\n" \
        "Cmd    : 0x%08X\n" \
        "Len    : 0x%08X\n" \
        "State  : 0x%08X\n" \
        "Ext    : 0x%08X\n" \
        "lRet   : 0x%X\n",
        (unsigned int)tRecvPacket.tHeader.ulSrc,   (unsigned int)tRecvPacket.tHeader.ulDest,
        (unsigned int)tRecvPacket.tHeader.ulCmd,   (unsigned int)tRecvPacket.tHeader.ulLen,
        (unsigned int)tRecvPacket.tHeader.ulState, (unsigned int)tSendPacket.tHeader.ulExt,
        (unsigned int)lRet);
          
  return true;
}


/*===========================================================================*/
/* Test configuration Download                                               */
/*                                                                           */
/*                                                                           */
/*===========================================================================*/
bool DownloadConfiguration( CIFXHANDLE hDriver, char* szBoard, char* pszFileName)
{
  //------------------------------
  // Load a file
  //------------------------------
  uint32_t ulFileSize  = 0;
  void*    pvFile      = OS_FileOpen(pszFileName, &ulFileSize);
  
  if ( pvFile == NULL)
  {
    // Error opening the file 
    printf("DownloadConfiguration(): File <%s> open error, LastError: %d\r\n", pszFileName, OS_GetLastError());
  } else
  {
    unsigned char* pabFileData = new unsigned char[ulFileSize];
    uint32_t       ulBytesRead = OS_FileRead(pvFile, 0, ulFileSize, pabFileData);
    
    if (!ulBytesRead)
    {
      // Error opening the file 
      printf("DownloadConfiguration(): Error reading file <%s>, LastError: %d\r\n", pszFileName, OS_GetLastError());
    } else
    {
      //------------------------------
      // Download configuration
      //------------------------------
      int32_t    lRet      = CIFX_NO_ERROR;
      CIFXHANDLE hChannel  = NULL;
      
      lRet = xChannelOpen ( hDriver,  szBoard, 0, &hChannel);
      if(lRet != CIFX_NO_ERROR)
      {
        // Error opening a channel
        ShowError( lRet);
      } else
      {
        lRet = xChannelDownload( hChannel, DOWNLOAD_MODE_CONFIG, (char*)"config.nxd", pabFileData, ulFileSize, NULL, NULL, NULL);
        if(lRet != CIFX_NO_ERROR)
        {
          // Read driver error description
          ShowError( lRet);
        } 

        lRet = xChannelDownload( hChannel, DOWNLOAD_MODE_CONFIG, (char*)"config.nxd", pabFileData, ulFileSize, ProgressCallback, NULL, NULL);
        if(lRet != CIFX_NO_ERROR)
        {
          // Read driver error description
          ShowError( lRet);
        } 
        
        if(lRet != CIFX_NO_ERROR)
        {
          // Start hardware with new configuration
          lRet = xChannelReset( hChannel, CIFX_CHANNELINIT, CIFX_TO_FIRMWARE_START); 
          if(lRet != CIFX_NO_ERROR)
          {
            // Read driver error description
            ShowError( lRet);
          }
        }
        
        xChannelClose( hChannel);
      }
    } 
    
    delete [] pabFileData;
    OS_FileClose(pvFile);
  }
  
  return true;
}


/*===========================================================================*/
/* Test Firmware Download                                                    */
/*                                                                           */
/*                                                                           */
/*===========================================================================*/
bool DownloadFirmware( CIFXHANDLE hDriver, char* szBoard, char* pszFileName)
{
  //------------------------------
  // Load a file
  //------------------------------
  uint32_t ulFileSize       = 0;
  void*    pvFile           = OS_FileOpen(pszFileName, &ulFileSize);
  bool     fDownloadSuccess = false;

  if ( pvFile == NULL)
  {
    // Error opening the file 
    printf("DownloadFirmware(): File <%s> open error, LastError: %d\r\n", pszFileName, OS_GetLastError());
  } else
  {
    unsigned char* pabFileData = new unsigned char[ulFileSize];
    uint32_t       ulBytesRead = OS_FileRead(pvFile, 0, ulFileSize, pabFileData);
    
    if (!ulBytesRead)
    {
      // Error opening the file 
      printf("DownloadFirmware(): Error reading file <%s>, LastError: %d\r\n", pszFileName, OS_GetLastError());
    } else
    {
      //------------------------------
      // Download configuration
      //------------------------------
      int32_t    lRet             = CIFX_NO_ERROR;
      CIFXHANDLE hSys             = NULL;

      lRet = xSysdeviceOpen( hDriver, szBoard, &hSys);
            
      lRet = xSysdeviceDownload( hSys, 0, DOWNLOAD_MODE_FIRMWARE, (char*)"firmware.nxf", pabFileData, ulFileSize, NULL, NULL, NULL);
      if(lRet != CIFX_NO_ERROR)
      {
        // Read driver error description
        ShowError( lRet);
      }
      
      lRet = xSysdeviceDownload( hSys, 0, DOWNLOAD_MODE_FIRMWARE, (char*)"firmware.nxf", pabFileData, ulFileSize, ProgressCallback, NULL, NULL);
      if(lRet != CIFX_NO_ERROR)
      {
        // Read driver error description
        ShowError( lRet);
      }
      
      if(lRet == CIFX_NO_ERROR)
      {
        fDownloadSuccess = true;
      }
      
      lRet = xSysdeviceClose(hSys);
    } 
    
    delete [] pabFileData;
    OS_FileClose(pvFile);
  }
  
  return fDownloadSuccess;
}


/*===========================================================================*/
/* Download firmware                                                         */
/*                                                                           */
/*                                                                           */
/*===========================================================================*/
void TestDownloadFirmware( CIFXHANDLE hDriver, char* szBoard, char* pszFileName)
{
  printf("\n--- Download Firmware File <%s> ---\r\n", pszFileName);  

  // Test firmware download
  DownloadFirmware( hDriver, szBoard, pszFileName);

  printf("\n Download Firmware done\r\n");  
}

/*===========================================================================*/
/* Download configuration                                                    */
/*                                                                           */
/*                                                                           */
/*===========================================================================*/
void TestDownloadConfiguration( CIFXHANDLE hDriver, char* szBoard, char* pszFileName)
{
  printf("\n--- Download Configuration File <%s> ---\r\n", pszFileName);  

  // Test configuration download
  DownloadConfiguration( hDriver, szBoard, pszFileName);

  printf("\n Download Configuration done\r\n");  
}
