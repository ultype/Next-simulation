/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: rX_Types.h 1845 2012-05-23 14:46:56Z stephans $

  Description:
    Basic Typedefinifions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifndef __RX_TYPES_H
  #define __RX_TYPES_H


  /*
  *****************************************************
  *       Type-Definitions
  *****************************************************
  */

  typedef unsigned char  UINT8;
  typedef signed   char  INT8;
  typedef unsigned short UINT16;
  typedef unsigned short WORD;
  typedef signed   short INT16;
  typedef signed   short SHORT;
  typedef signed   long  LONG;
  typedef signed   int   INT;
  typedef unsigned int   UINT;
  typedef unsigned long  DWORD;
  typedef unsigned long  ULONG;
  typedef char STRING;
  typedef char CHAR;
  typedef float          FLOAT;

#ifdef __GNUC__
#define __NANOSEC_TIME_VALID
  typedef unsigned long long NANOSEC_TIME;
#elif defined(_CONSOLE_32_)
#endif

#if !(defined(_WINNT_) || defined(_BASETSD_H))
  typedef unsigned long  UINT32;
  typedef signed   long  INT32;
  typedef unsigned char  BYTE;
  typedef unsigned char  UCHAR;
  typedef unsigned short USHORT;
  typedef unsigned int   BOOLEAN;
  typedef unsigned int   BOOL;
  typedef void           VOID;
#endif

  #if !defined(__GNUC__) && !defined(__BORLANDC__)
    #ifndef size_t
    typedef unsigned size_t;
    #endif
  #endif

  enum RX_DATA_TYPEtag {
    RX_DATTYPE_UNUSED  = 0,
    RX_DATTYPE_BOOLEAN = 1,
    RX_DATTYPE_INT8    = 2,
    RX_DATTYPE_INT16   = 3,
    RX_DATTYPE_INT32   = 4,
    RX_DATTYPE_UINT8   = 5,
    RX_DATTYPE_UINT16  = 6,
    RX_DATTYPE_UINT32  = 7,
    RX_DATTYPE_FLOAT   = 8,
    RX_DATTYPE_ASCII   = 9,
    RX_DATTYPE_STRING  = 10,
    RX_DATTYPE_BIT     = 14
  };
  typedef int RX_DATA_TYPE;

  typedef unsigned long SPIN_LOCK_T;

  /*
  ***********************************************************
  *      Typedef of Linked Lists
  ***********************************************************
  */
  typedef struct RX_DOUBLE_LINK_Ttag {
    struct RX_DOUBLE_LINK_Ttag FAR * ptNxt;  /* Pointer to next entry */
    struct RX_DOUBLE_LINK_Ttag FAR * ptPrv;  /* Pointer to previous entry */
  } RX_DOUBLE_LINK_T;

  typedef struct RX_SINGLE_LINKtag {
    struct RX_SINGLE_LINKtag FAR* ptNxt;  /* Pointer to next entry */
  } RX_SINGLE_LINK;


  /*
  *****************************************************
  *       Constant-Defintions
  *****************************************************
  */
  #ifndef FALSE
    #define FALSE (0)
  #endif

  #ifndef TRUE
    #define TRUE  (1)
  #endif

  #ifndef NULL
    #define NULL  0
  #endif

  /*
  ************************************************************
  *   Handle Defintion
  ************************************************************
  */
  typedef void FAR* RX_HANDLE;

  /*
  ************************************************************
  *   Status Bit Row Defintion
  ************************************************************
  */
   typedef struct RX_MULTIPLE_BITS_Ttag
  {
    UINT              uGrp;                              /* active token group */
    UINT8             abTbl[32];                         /* token group list */
  } RX_MULTIPLE_BITS_T;


#endif
