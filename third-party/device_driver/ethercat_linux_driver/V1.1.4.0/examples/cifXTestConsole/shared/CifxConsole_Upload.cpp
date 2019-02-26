/**************************************************************************************
 
   Copyright (c) Hilscher GmbH. All Rights Reserved.
 
 **************************************************************************************
 
   Filename:
    $Workfile: CifxConsole_Upload.cpp
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
     loads a file from the hardware
       
   Changes:
 
     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
     1         21.07.2010  RM       initial version
 
     
**************************************************************************************/
#include "OS_Includes.h"
#include "CifXConsole.h"
#include <vector>

/*===========================================================================*/
/* Structure for directory listing entries                                   */
/*===========================================================================*/
typedef struct DIRECTORY_ENTRYtag
{
  char          szFilename[256];  //!< Name of the file on the hardware
  unsigned long ulFileLength;     //!< Length in bytes of the file
  unsigned char bFileType;        //!< File type (needed for TransferType)
  
} DIRECTORY_ENTRY;

typedef std::vector<DIRECTORY_ENTRY> DIRECTORY_LIST;

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
/* Send Receive a packet                                                     */
/*  \param hDevice    handle to device                                       */
/*  \param ptSend     Pointer to SendPacket                                  */
/*  \param ptRecv     Pointer to RecievePacket                               */
/*  \param ulRecvSize number of recieve size                                 */
/*  \param ulTimeout  timeout for call                                       */
/*                                                                           */
/*===========================================================================*/
int32_t TransferPacket( CIFXHANDLE hDevice, CIFX_PACKET* ptSend, CIFX_PACKET* ptRecv, unsigned long ulRecvSize, unsigned long ulTimeout)
{
  int32_t lRet = xChannelPutPacket(hDevice, ptSend, ulTimeout);
  
  if(CIFX_NO_ERROR == lRet)
  {
    lRet = xChannelGetPacket(hDevice, ulRecvSize, ptRecv, ulTimeout);
  }
  
  
  return lRet;
}

/*===========================================================================*/
/* Reads the directory of a channel                                          */
/*   \param cvDirList      Reference to vector for storing the found files   */ 
/*   \param ulChannel      Channel to get the directory for                  */
/*   \param szFilename     Filename filter option. NULL if no filtering      */ 
/*   \return CIFX_NO_ERROR on success                                        */
/*===========================================================================*/
int32_t ReadDirectoryList(CIFXHANDLE hDevice, DIRECTORY_LIST& cvDirList, unsigned long ulChannel, char* szFilename)
{
  int32_t lRet = CIFX_NO_ERROR;
  
  RCX_DIR_LIST_REQ_T tDirListReq = {{0}};

  if(NULL != szFilename)
  {
    tDirListReq.tData.usDirNameLength = (unsigned short)(OS_Strlen(szFilename) + 1);
    OS_Strncpy( (char*)((&tDirListReq.tData) + 1),
                 szFilename, 
                 tDirListReq.tData.usDirNameLength);
  }
 
  // Create request packet 
  tDirListReq.tHead.ulSrc       = 0;
  tDirListReq.tHead.ulDest      = RCX_PACKET_DEST_SYSTEM;  
  tDirListReq.tHead.ulCmd       = RCX_DIR_LIST_REQ;
  tDirListReq.tHead.ulLen       = sizeof(tDirListReq.tData) + tDirListReq.tData.usDirNameLength;
  tDirListReq.tData.ulChannelNo = ulChannel;

  RCX_DIR_LIST_CNF_T  tDirListCnf = {{0}};
  
  lRet = TransferPacket(hDevice,
                        (CIFX_PACKET*)&tDirListReq,
                        (CIFX_PACKET*)&tDirListCnf,
                        sizeof(tDirListCnf),
                        CIFX_TO_SEND_PACKET);
    
  if(CIFX_NO_ERROR == lRet)
  {
    // Check packet error 
    if( RCX_S_OK != (lRet = tDirListCnf.tHead.ulSta))
    {
      printf("Error reading directory list, confirmation state 0x%X\n", lRet);
    } else
    {
      DIRECTORY_ENTRY tEntry = {{0}};
      
      OS_Strncpy(tEntry.szFilename,
                 tDirListCnf.tData.szName,
                 sizeof(tEntry.szFilename));
              
      tEntry.bFileType    = tDirListCnf.tData.bFileType;
      tEntry.ulFileLength = tDirListCnf.tData.ulFileSize;
      
      cvDirList.push_back(tEntry);
      
      int32_t lIter = CIFX_NO_ERROR;

      do
      {     
        ++tDirListReq.tHead.ulId;
        tDirListReq.tHead.ulExt = RCX_PACKET_SEQ_MIDDLE;

        lIter = TransferPacket(hDevice,
                              (CIFX_PACKET*)&tDirListReq,
                              (CIFX_PACKET*)&tDirListCnf,
                              sizeof(tDirListCnf),
                              CIFX_TO_SEND_PACKET);

        if( CIFX_NO_ERROR == lIter)
        {
          // Check packet error 
          if( RCX_S_OK != (lRet = tDirListCnf.tHead.ulSta))
          {
            printf("  Error reading directory list, confirmation state 0x%X\n", lRet);
            break;
          } else if ( RCX_PACKET_SEQ_LAST != (tDirListCnf.tHead.ulExt & RCX_PACKET_SEQ_MASK))
          {
            DIRECTORY_ENTRY tEntry = {{0}};
            
            OS_Strncpy(tEntry.szFilename,
                       tDirListCnf.tData.szName,
                       sizeof(tEntry.szFilename));
                    
            tEntry.bFileType    = tDirListCnf.tData.bFileType;
            tEntry.ulFileLength = tDirListCnf.tData.ulFileSize;
            
            cvDirList.push_back(tEntry);
          }
        }
      } while( (CIFX_NO_ERROR == lIter) && ( (tDirListCnf.tHead.ulExt & RCX_PACKET_SEQ_MASK) != RCX_PACKET_SEQ_LAST) );
    }
  } 

  return lRet;
}


/*===========================================================================*/
/* Test file upload                                                          */
/*                                                                           */
/*                                                                           */
/*===========================================================================*/
void TestFileUpload( CIFXHANDLE hDriver, char* szBoard)
{
  int32_t    lRet = CIFX_NO_ERROR;
  CIFXHANDLE hDev = NULL;
   
  std::vector<DIRECTORY_ENTRY> cvDirectory;
  
  printf("\n--- Test File Upload ---\r\n");    
  
  // Open channel  
  lRet = xChannelOpen(hDriver, szBoard, 0, &hDev);
  if (lRet != CIFX_NO_ERROR)
  {
    ShowError(lRet);
  } else
  {
    // Read the directory list
    lRet = ReadDirectoryList(hDev, cvDirectory, 0, NULL);
    if( lRet != CIFX_NO_ERROR)
    {
      ShowError(lRet);    
    } else
    {
      // Display all file entries    
      for(int iIdx = 0; iIdx < (int)cvDirectory.size(); ++iIdx)
      {
        printf("\n");
        printf("File : %s\n", cvDirectory[iIdx].szFilename);
        printf("Type : %u\n", cvDirectory[iIdx].bFileType);
        printf("Size : %u\n", (unsigned int)cvDirectory[iIdx].ulFileLength);
        printf("--------------------------------------------\n");
            
        if(cvDirectory[iIdx].bFileType == RCX_DIR_LIST_CNF_FILE_TYPE_FILE)
        {
          uint32_t ulDataLen     = cvDirectory[iIdx].ulFileLength;
          unsigned char* pabData = new unsigned char[ulDataLen];
          
          printf("Running upload for file %s\n", cvDirectory[iIdx].szFilename);
          printf("  File size: %u bytes\n", ulDataLen);
           
          lRet = xChannelUpload( hDev, DOWNLOAD_MODE_CONFIG, cvDirectory[iIdx].szFilename, pabData, &ulDataLen, NULL, NULL, NULL);
          if( lRet != CIFX_NO_ERROR)
          {
            // Show upload error          
            ShowError(lRet);
          } 

          lRet = xChannelUpload( hDev, DOWNLOAD_MODE_CONFIG, cvDirectory[iIdx].szFilename, pabData, &ulDataLen, ProgressCallback, NULL, NULL);
          if( lRet != CIFX_NO_ERROR)
          {
            // Show upload error          
            ShowError(lRet);
          } 

          if( lRet != CIFX_NO_ERROR)
          {
            printf("Upload done!\n");
            printf("  Upload size: %u bytes\n", ulDataLen);
          }
          
          delete [] pabData;
        }
      }  
    }
     
    lRet = xChannelClose(hDev);
  }

  printf("\n File Upload test done\r\n");
}
