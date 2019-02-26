/**************************************************************************************
 
   Copyright (c) Hilscher GmbH. All Rights Reserved.
 
 **************************************************************************************
 
   Filename:
    $Workfile: CifXConsole_BlockInformation.cpp
   Last Modification:
    $Author: Robert $
    $Modtime: $
    $Revision: 5511 $
   
   Targets:
     Win32/ANSI   : no
     Win32/Unicode: no
     WinCE 5      : yes
     WinCE 6      : yes
     Linux        : yes
 
   Description:
     demonstrate functions of the driver
       
   Changes:
 
     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
     1         21.07.2010  RM       initial version
 
     
**************************************************************************************/
#include "OS_Includes.h"
#include <string.h>
#include "CifXConsole.h"

//-------------------------------------------------
// Function to test
void TestChannelFunctions( CIFXHANDLE hDriver, char* szBoard);
void SendReceivePacket( CIFXHANDLE hDriver, char* szBoard);
void ReadWriteIOData( CIFXHANDLE hDriver, char* szBoard, unsigned long ulWaitTimeout);
void TestMemoryPointer( CIFXHANDLE hDriver);
void TestPLCFunctions( CIFXHANDLE hDriver, char* szBoard);
void TestFileUpload( CIFXHANDLE hDriver, char* szBoard);
void TestWatchdog( CIFXHANDLE hDriver, char* szBoard);
void TestEventHandling( CIFXHANDLE hDriver, char* szBoard);
void TestDownloadFirmware( CIFXHANDLE hDriver, char* szBoard, char* pszFileName);
void TestDownloadConfiguration( CIFXHANDLE hDriver, char* szBoard, char* pszFileName);
void TestPacketConfig( CIFXHANDLE hDriver, char* szBoard);
void TestExtendedMemoryPointer( CIFXHANDLE hDriver, char* szBoard);

//-------------------------------------------------
// Global infomation and definitions

unsigned char abReadIOBuffer[1024]  = {0};
unsigned char abWriteIOBuffer[1024] = {0};
unsigned char abBuffer[100]         = {0};

//=============================================================================
// Show error
//
//
//=============================================================================
void ShowError( int32_t lError)
{
  if( lError != CIFX_NO_ERROR)
  {
    // Read driver error description
    char szError[1024] ={0};
    xDriverGetErrorDescription( lError,  szError, sizeof(szError));
    printf("Error: 0x%X, <%s>\r\n", lError, szError);
  }
}

//=============================================================================
// Run CifX Console Test Applicattion
//
//
//=============================================================================
void RunCifXConsoleTest(char* szBoard, 
                        char* pszFirmwareFileName, 
                        char* pszConfigFileName, 
                        unsigned long /*ulTimerResolution*/, 
                        unsigned long ulIOTimeout)
{
  DRIVER_INFORMATION tDriverInfo = {{0}};
  CIFXHANDLE         hDriver     = NULL;

  printf("************************************************\r\n");
  printf("*** CIFx Driver Test Program \r\n");
  printf("************************************************\r\n\n");
  
  //------------------------------------------
  // Read driver information
  //------------------------------------------
  if (CIFX_NO_ERROR != xDriverOpen(&hDriver))
    return;

  //------------------------------------------
  // Read driver information
  //------------------------------------------
  int32_t lRet = xDriverGetInformation(hDriver, sizeof(tDriverInfo), &tDriverInfo);
  if( lRet != CIFX_NO_ERROR)
    // Read driver error description
    ShowError( lRet);
  else
    printf("Driver Version: %s\r\n\n", tDriverInfo.abDriverVersion);

  //------------------------------------------
  // Find out how many boards are installed
  //------------------------------------------
  bool          fBoardFound = false;
  unsigned long ulBoardIdx  = 0;
  
  int32_t lBoardRet = CIFX_NO_ERROR;
  while(lBoardRet == CIFX_NO_ERROR)
  {
    // Enumerate the boards
    BOARD_INFORMATION tBoardInfo = {0};
    lBoardRet = xDriverEnumBoards(hDriver, ulBoardIdx, sizeof(tBoardInfo), &tBoardInfo);

    if(lBoardRet != CIFX_NO_ERROR)
    {
      // No more boards
      break;
    }
    {
      // Board found
      unsigned long ulChannelIdx  = 0;
      int32_t       lChannelRet   = CIFX_NO_ERROR;

      printf("Board%u Information:\r\n", (unsigned int)ulBoardIdx);
      printf(" Name : %s\r\n", tBoardInfo.abBoardName);
      printf(" Alias: %s\r\n", tBoardInfo.abBoardAlias);
      printf(" DevNr: %lu\r\n", (long unsigned int)tBoardInfo.tSystemInfo.ulDeviceNumber);
      printf(" SN   : %lu\r\n", (long unsigned int)tBoardInfo.tSystemInfo.ulSerialNumber);
      printf("\r\n");

      //------------------------------------------
      // If no board name is passed use first found
      // board to proceed with tests
      //------------------------------------------
      if (NULL == szBoard)
      {
        // Show information
        printf("Error in application, missing a board name buffer!\n");
        break;
      }

      if (0 == OS_Strlen(szBoard))
      {
        OS_Strncpy( szBoard, tBoardInfo.abBoardName, OS_Strlen(tBoardInfo.abBoardName));
      }

      //------------------------------------------
      // Find out how many channels are active
      // on this board
      //------------------------------------------
      while(lChannelRet == CIFX_NO_ERROR)
      {
        // Read all channel information from the given board
        CHANNEL_INFORMATION tChannelInfo = {{0}};
        lChannelRet = xDriverEnumChannels(hDriver, ulBoardIdx, ulChannelIdx, sizeof(tChannelInfo), &tChannelInfo);
        if(lChannelRet != CIFX_NO_ERROR)
        {
          if (lChannelRet != CIFX_NO_MORE_ENTRIES)
          {
            // Show information
            printf("Error during xDriverEnumChannels(): Channel %u\r\n", (unsigned int)ulChannelIdx);
            ShowError(lChannelRet);
          }
        } else
        {
          // We have a board and a channel
          fBoardFound = true;
          
          // Show information
          printf("  Channel%u Information:\r\n", (unsigned int)ulChannelIdx);
          printf("   Channel Error            : 0x%08X\r\n",  tChannelInfo.ulChannelError);
          printf("   Board Name               : %s\r\n",  tChannelInfo.abBoardName);
          printf("   Alias Name               : %s\r\n",  tChannelInfo.abBoardAlias);
          printf("   Device Nr.               : %lu\r\n",  (long unsigned int)tChannelInfo.ulDeviceNumber);
          printf("   Serial Nr.               : %lu\r\n",  (long unsigned int)tChannelInfo.ulSerialNumber);
          printf("   MBX Size                 : %lu\r\n",  (long unsigned int)tChannelInfo.ulMailboxSize);
          printf("   Firmware Name            : %s\r\n",  tChannelInfo.abFWName);
          printf("   Firmware Version         : %d.%d.%d Build %d\r\n",  tChannelInfo.usFWMajor, tChannelInfo.usFWMinor,tChannelInfo.usFWRevision, tChannelInfo.usFWBuild);
          printf("   Open Counter             : %lu\r\n",  (long unsigned int)tChannelInfo.ulOpenCnt);
          printf("   Put Packet Counter       : %lu\r\n",  (long unsigned int)tChannelInfo.ulPutPacketCnt);
          printf("   Get Packet Counter       : %lu\r\n",  (long unsigned int)tChannelInfo.ulGetPacketCnt);
          printf("   Number of IO Input Areas : %lu\r\n",  (long unsigned int)tChannelInfo.ulIOInAreaCnt);
          printf("   Number of IO Output Areas: %lu\r\n",  (long unsigned int)tChannelInfo.ulIOOutAreaCnt);
          printf("   Size of handshake cells  : %lu\r\n",  (long unsigned int)tChannelInfo.ulHskSize);
          printf("   Actual netX Flags        : 0x%08X\r\n",tChannelInfo.ulNetxFlags);
          printf("   Actual host Flags        : 0x%08X\r\n",tChannelInfo.ulHostFlags);
        }
        ++ulChannelIdx;    // Next channel
      }
      ++ulBoardIdx;    // Next board
      printf("\n");
    }
  }
  printf("\r\n\n");
  printf("************************************************\r\n");
  printf("*** Running tests on device <%s>\r\n", szBoard);
  printf("************************************************\r\n\n");

  //---------------------------------
  // Device Restart
  //---------------------------------
  if( fBoardFound == true)
  {
    // Wait for user 
    printf("\n\r Press (Y) for Device Restart  or (Q) to skip!!!!!\r\n");

	  if( 'Y' == OS_GetChar() )
	  {
      lRet = xDriverRestartDevice( hDriver, szBoard, NULL);
      if( CIFX_NO_ERROR != lRet)
      {
        ShowError( lRet);
      }
    } else
      printf("\r Function skipped\r\n");
  }

  //---------------------------------
  // Channel functions
  //---------------------------------
  if( fBoardFound == true)
  {
    // Wait for user 
    printf("\n\r Press (Y) to test Channel functions  or (Q) to skip!!!!!\r\n");

	  if( 'Y' == OS_GetChar() )
    {
      // Test read/write of block informations
      TestChannelFunctions(hDriver, szBoard);
    } else
      printf("\r Function skipped\r\n");
  }

  //---------------------------------
  // Download Firmware
  //---------------------------------
  if( fBoardFound == true)
  {
    // Wait for user 
    printf("\n\r Press (Y) for Firmware Download or (Q) to skip!!!!!\r\n");
  
  	if( 'Y' == OS_GetChar() )
    {
      // Test a firmware download
      TestDownloadFirmware(hDriver, szBoard, pszFirmwareFileName);
    } else
      printf("\r Function skipped\r\n");
  }
                                     
  //---------------------------------
  // Download Configuration
  //---------------------------------
  if( fBoardFound == true)
  {
    // Wait for user 
    printf("\n\r Press (Y) for Configuration Download or (Q) to skip !!!!!\r\n");
    
	  if( 'Y' == OS_GetChar() )
    {
      // Test a configuration download
      TestDownloadConfiguration(hDriver, szBoard, pszConfigFileName);
    } else
      printf("\r Function skipped\r\n");
  }

  //---------------------------------
  // Send receive packets
  //---------------------------------
  if( fBoardFound == true)
  {
    // Wait for user 
    printf("\n\r Press (Y) for Send / Receive Packets or (Q) to skip !!!!!\r\n");
    
    if( 'Y' == OS_GetChar() )
    {
      // Send receive a packet
      SendReceivePacket(hDriver, szBoard);
    } else
      printf("\r Function skipped\r\n");
  }
  
  //------------------------------
  // Read / Write IO data
  //------------------------------
  if( fBoardFound == true)
  {
    // Wait for user 
    printf("\n\r Press (Y) for IO/Data read/write or (Q) to skip !!!!!\r\n");
    
	  if( 'Y' == OS_GetChar() )
    {
      // Read write I/O data
      ReadWriteIOData(hDriver, szBoard, ulIOTimeout);
    } else
      printf("\r Function skipped\r\n");
  }

  //------------------------------
  // Test memory pointer
  //------------------------------
  if( fBoardFound == true)
  {
    // Wait for user 
    printf("\n\r Press (Y) to test Memory Pointer or (Q) to skip !!!!!\r\n");
    
	  if( 'Y' == OS_GetChar() )
    {
      // Test the function to get a DPM memory pointer
      TestMemoryPointer(hDriver);
    } else
      printf("\r Function skipped\r\n");
  }

  //------------------------------
  // Test file upload
  //------------------------------
  if( fBoardFound == true)
  {
    // Wait for user 
    printf("\n\r Press (Y) to test File Upload or (Q) to skip !!!!!\r\n");
    
    if( 'Y' == OS_GetChar() )
    {
      TestFileUpload(hDriver, szBoard);
    } else
      printf("\r Function skipped\r\n");
  }

  //------------------------------
  // Test WATCHDOG
  //------------------------------
  if( fBoardFound == true)
  {
    // Wait for user 
    printf("\n\r Press (Y) to test WatchDog or (Q) to skip !!!!!\r\n");
    
	  if( 'Y' == OS_GetChar() )
    {
      TestWatchdog(hDriver, szBoard);
    } else
      printf("\r Function skipped\r\n");
  }

  //------------------------------
  // Test PLC functions
  //------------------------------
  if( fBoardFound == true)
  {
    // Wait for user 
    printf("\n\r Press (Y) to test PLC Functions or (Q) to skip !!!!!\r\n");
    
	  if( 'Y' == OS_GetChar() )
    {
      // Test the function to get a DPM memory pointer
      TestPLCFunctions(hDriver, szBoard);
    } else
      printf("\r Function skipped\r\n");
  }

  //------------------------------
  // Test EVENT functions
  //------------------------------
  if( fBoardFound == true)
  {
    // Wait for user 
    printf("\n\r Press (Y) to test Event Functions or (Q) to skip !!!!!\r\n");
    
	  if( 'Y' == OS_GetChar() )
    {
      // Test the function to get a DPM memory pointer
      TestEventHandling(hDriver, szBoard);
    } else
      printf("\r Function skipped\r\n");
  }

  //------------------------------
  // Test Packet Config
  //------------------------------
  if( fBoardFound == true)
  {
    // Wait for user 
    printf("\n\r Press (Y) to test Packet Configuration Functions or (Q) to skip !!!!!\r\n");
    
	  if( 'Y' == OS_GetChar() )
    {
      // Test packet configuration function
      TestPacketConfig(hDriver, szBoard); 
    } else
      printf("\r Function skipped\r\n");
  }
  
  //------------------------------
  // Test Packet Config
  //------------------------------
  if( fBoardFound == true)
  {
    // Wait for user 
    printf("\n\r Press (Y) to test Extended Memory or (Q) to skip !!!!!\r\n");
    
    if( 'Y' == OS_GetChar() )
    {
      // Test extended memory
      TestExtendedMemoryPointer( hDriver, szBoard); 
    } else
      printf("\r Function skipped\r\n");
  }

  printf("********************************************************************************\r\n");
    
  xDriverClose(hDriver);

  // Wait for user 
  printf("\n\r Press (Q) to close program!!!!!\r\n");
  OS_GetChar();
}
