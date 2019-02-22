/**************************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 **************************************************************************************

   Last Modification:
   
    @version $Id: EcsV4_Public.h 24512 2012-05-23 14:39:07Z Richard $

   Description:

    EtherCAT Slave V4

   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2012-05-23  RW            replaced ECAT_SET_CONFIG_SYNCSOURCE_ defines by ECAT_DPM_SYNC_SOURCE_ defines
     2012-05-16  RW            adjusted define for header to __ECSV4_PUBLIC_H
     2012-01-18  SB            updated structure packing to __TLR_PACKED_PRE/POST
     2011-12-02  RW            created
**************************************************************************************/

#ifndef __ECSV4_PUBLIC_H
#define __ECSV4_PUBLIC_H

#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_PACK_1(ECS_PUBLIC)
#endif

/* -----------------------------------------------------------------------------
 *  defines
 * -----------------------------------------------------------------------------
 */

/* AL state */
#define ECAT_AL_STATE_INIT                                          0x01
#define ECAT_AL_STATE_PRE_OPERATIONAL                               0x02
#define ECAT_AL_STATE_BOOTSTRAP_MODE                                0x03
#define ECAT_AL_STATE_SAFE_OPERATIONAL                              0x04
#define ECAT_AL_STATE_OPERATIONAL                                   0x08

/* AL status changes */
#define ECAT_AL_STATUS_CHANGE_CONFIRMATION                          0x00
#define ECAT_AL_STATUS_CHANGE_ERROR                                 0x01

/* AL status code definitions */
#define ECAT_AL_STATUS_CODE_NO_ERROR                                0x0000
#define ECAT_AL_STATUS_CODE_UNSPECIFIED_ERROR                       0x0001
#define ECAT_AL_STATUS_CODE_INVALID_REQUESTED_STATE_CHANGE          0x0011
#define ECAT_AL_STATUS_CODE_UNKNOWN_REQUESTED_STATE                 0x0012
#define ECAT_AL_STATUS_CODE_BOOTSTRAP_NOT_SUPPORTED                 0x0013
#define ECAT_AL_STATUS_CODE_NO_VALID_FIRMWARE                       0x0014
#define ECAT_AL_STATUS_CODE_INVALID_MAILBOX_CONFIGURATION_BOOTSTRAP 0x0015
#define ECAT_AL_STATUS_CODE_INVALID_MAILBOX_CONFIGURATION_PREOP     0x0016
#define ECAT_AL_STATUS_CODE_INVALID_SYNC_MANAGER_CONFIGURATION      0x0017
#define ECAT_AL_STATUS_CODE_NO_VALID_INPUTS_AVAILABLE               0x0018
#define ECAT_AL_STATUS_CODE_NO_VALID_OUTPUTS                        0x0019
#define ECAT_AL_STATUS_CODE_SYNCHRONIZATION_ERROR                   0x001A
#define ECAT_AL_STATUS_CODE_SYNC_MANAGER_WATCHDOG                   0x001B
#define ECAT_AL_STATUS_CODE_INVALID_OUTPUT_CONFIGURATION            0x001D
#define ECAT_AL_STATUS_CODE_INVALID_INPUT_CONFIGURATION             0x001E
#define ECAT_AL_STATUS_CODE_SLAVE_NEEDS_COLD_START                  0x0020
#define ECAT_AL_STATUS_CODE_SLAVE_NEEDS_INIT                        0x0021
#define ECAT_AL_STATUS_CODE_SLAVE_NEEDS_PREOP                       0x0022
#define ECAT_AL_STATUS_CODE_SLAVE_NEEDS_SAFEOP                      0x0023
#define ECAT_AL_STATUS_CODE_HOST_NOT_READY                          0x8000
#define ECAT_AL_STATUS_CODE_IO_DATA_SIZE_NOT_CONFIGURED             0x8001
#define ECAT_AL_STATUS_CODE_DPM_HOST_WATCHDOG_TRIGGERED             0x8002
#define ECAT_AL_STATUS_CODE_DC_CFG_INVALID                          0x8003
#define ECAT_AL_STATUS_CODE_FIRMWARE_IS_BOOTING                     0x8004
#define ECAT_AL_STATUS_CODE_WARMSTART_REQUESTED                     0x8005
#define ECAT_AL_STATUS_CODE_CHANNEL_INIT_REQUESTED                  0x8006
#define ECAT_AL_STATUS_CODE_CONFIGURATION_CLEARED                   0x8007

/* EtherCAT error LED codes */
#define ECAT_ERRORLED_OFF                                           0
#define ECAT_ERRORLED_SOLID_ON                                      1
#define ECAT_ERRORLED_FLICKERING                                    2
#define ECAT_ERRORLED_SINGLE_FLICKER                                3
#define ECAT_ERRORLED_BLINKING                                      4
#define ECAT_ERRORLED_SINGLE_FLASH                                  5
#define ECAT_ERRORLED_DOUBLE_FLASH                                  6
#define ECAT_ERRORLED_TRIPLE_FLASH                                  7
#define ECAT_ERRORLED_QUADRUPLE_FLASH                               8
#define ECAT_ERRORLED_QUINTUPLE_FLASH                               9

/* codes for parameters of "set configuration" packet */
#define ECAT_SET_CONFIG_COE                                         0x00000001
#define ECAT_SET_CONFIG_EOE                                         0x00000002
#define ECAT_SET_CONFIG_FOE                                         0x00000004
#define ECAT_SET_CONFIG_SOE                                         0x00000008
#define ECAT_SET_CONFIG_SYNCMODES                                   0x00000010
#define ECAT_SET_CONFIG_SYNCPDI                                     0x00000020
#define ECAT_SET_CONFIG_UID                                         0x00000040
#define ECAT_SET_CONFIG_SYSTEMFLAGS_AUTOSTART                       0x00000000
#define ECAT_SET_CONFIG_SYSTEMFLAGS_APP_CONTROLLED                  0x00000001
#define ECAT_SET_CONFIG_COEDETAILS_ENABLE_SDO                       0x01
#define ECAT_SET_CONFIG_COEDETAILS_ENABLE_SDOINFO                   0x02
#define ECAT_SET_CONFIG_COEDETAILS_ENABLE_PDOASSIGN                 0x04
#define ECAT_SET_CONFIG_COEDETAILS_ENABLE_PDOCONFIGURATION          0x08
#define ECAT_SET_CONFIG_COEDETAILS_ENABLE_UPLOAD                    0x10
#define ECAT_SET_CONFIG_COEDETAILS_ENABLE_SDOCOMPLETEACCESS         0x20
#define ECAT_SET_CONFIG_COEFLAGS_USE_CUSTOM_OD                      0x01
#define ECAT_SET_CONFIG_SYNCPDI_SYNC0_OUTPUT_TYPE_MASK              0x01
#define ECAT_SET_CONFIG_SYNCPDI_SYNC0_POLARITY_MASK                 0x02
#define ECAT_SET_CONFIG_SYNCPDI_SYNC0_OUTPUT_ENABLE_MASK            0x04
#define ECAT_SET_CONFIG_SYNCPDI_SYNC0_IRQ_ENABLE_MASK               0x08
#define ECAT_SET_CONFIG_SYNCPDI_SYNC1_OUTPUT_TYPE_MASK              0x10
#define ECAT_SET_CONFIG_SYNCPDI_SYNC1_POLARITY_MASK                 0x20
#define ECAT_SET_CONFIG_SYNCPDI_SYNC1_OUTPUT_ENABLE_MASK            0x40
#define ECAT_SET_CONFIG_SYNCPDI_SYNC1_IRQ_ENABLE_MASK               0x80

/* DPM sync sources */
#define ECAT_DPM_SYNC_SOURCE_FREERUN                                0x00
#define ECAT_DPM_SYNC_SOURCE_SYNC0                                  0x02
#define ECAT_DPM_SYNC_SOURCE_SYNC1                                  0x03
#define ECAT_DPM_SYNC_SOURCE_SM2                                    0x22
#define ECAT_DPM_SYNC_SOURCE_SM3                                    0x23

/* ready wait bits */
#define ECAT_READYWAIT_APPLICATION_MASK                             0xfff00000
#define ECAT_READYWAIT_STACK_MASK                                   0x000fffff
#define ECAT_READYWAIT_CYCLIC_DPM                                   0x00008000
#define ECAT_READYWAIT_APP_TASK_1                                   0x00100000
#define ECAT_READYWAIT_APP_TASK_2                                   0x00200000
#define ECAT_READYWAIT_APP_TASK_3                                   0x00400000
#define ECAT_READYWAIT_APP_TASK_4                                   0x00800000
#define ECAT_READYWAIT_APP_TASK_5                                   0x01000000
#define ECAT_READYWAIT_APP_TASK_6                                   0x02000000
#define ECAT_READYWAIT_APP_TASK_7                                   0x04000000
#define ECAT_READYWAIT_APP_TASK_8                                   0x08000000
#define ECAT_READYWAIT_APP_TASK_9                                   0x10000000
#define ECAT_READYWAIT_APP_TASK_10                                  0x20000000
#define ECAT_READYWAIT_APP_TASK_11                                  0x40000000
#define ECAT_READYWAIT_APP_TASK_12                                  0x80000000

/* object dictionary specific access rights */
#define ECAT_OD_READ_PREOP                                          (0x0001)
#define ECAT_OD_READ_SAFEOP                                         (0x0002)
#define ECAT_OD_READ_OPERATIONAL                                    (0x0004)
#define ECAT_OD_WRITE_PREOP                                         (0x0008)
#define ECAT_OD_WRITE_SAFEOP                                        (0x0010)
#define ECAT_OD_WRITE_OPERATIONAL                                   (0x0020)
#define ECAT_OD_MAPPABLE_IN_RXPDO                                   (0x0040)
#define ECAT_OD_MAPPABLE_IN_TXPDO                                   (0x0080)
#define ECAT_OD_BACKUP                                              (0x0100)
#define ECAT_OD_SETTINGS                                            (0x0200)
#define ECAT_OD_READ_INIT                                           (0x4000)
#define ECAT_OD_WRITE_INIT                                          (0x8000)
#define ECAT_OD_READ_ALL                                            (ECAT_OD_READ_PREOP|ECAT_OD_READ_SAFEOP|ECAT_OD_READ_OPERATIONAL|ECAT_OD_READ_INIT)
#define ECAT_OD_WRITE_ALL                                           (ECAT_OD_WRITE_PREOP|ECAT_OD_WRITE_SAFEOP|ECAT_OD_WRITE_OPERATIONAL|ECAT_OD_WRITE_INIT)
#define ECAT_OD_ECAT_ALL                                            (ECAT_OD_SETTINGS|ECAT_OD_BACKUP|ECAT_OD_MAPPABLE_IN_TXPDO|ECAT_OD_MAPPABLE_IN_RXPDO|ECAT_OD_READ_PREOP|ECAT_OD_READ_SAFEOP|ECAT_OD_READ_OPERATIONAL|ECAT_OD_WRITE_PREOP|ECAT_OD_WRITE_SAFEOP|ECAT_OD_WRITE_OPERATIONAL)
#define ECAT_OD_ACCESS_ALL                                          (ECAT_OD_READ_ALL | ECAT_OD_WRITE_ALL)

/* object dictionary specific datatypes */
#define ECAT_OD_DTYPE_BOOLEAN                                       0x0001
#define ECAT_OD_DTYPE_INTEGER8                                      0x0002
#define ECAT_OD_DTYPE_INTEGER16                                     0x0003
#define ECAT_OD_DTYPE_INTEGER32                                     0x0004
#define ECAT_OD_DTYPE_UNSIGNED8                                     0x0005
#define ECAT_OD_DTYPE_UNSIGNED16                                    0x0006
#define ECAT_OD_DTYPE_UNSIGNED32                                    0x0007
#define ECAT_OD_DTYPE_REAL32                                        0x0008
#define ECAT_OD_DTYPE_VISIBLE_STRING                                0x0009
#define ECAT_OD_DTYPE_OCTET_STRING                                  0x000a
#define ECAT_OD_DTYPE_UNICODE_STRING                                0x000b
#define ECAT_OD_DTYPE_TIME_OF_DAY                                   0x000c
#define ECAT_OD_DTYPE_TIME_DIFFERENCE                               0x000d
#define ECAT_OD_DTYPE_DOMAIN                                        0x000f
#define ECAT_OD_DTYPE_INTEGER24                                     0x0010
#define ECAT_OD_DTYPE_REAL64                                        0x0011
#define ECAT_OD_DTYPE_INTEGER40                                     0x0012
#define ECAT_OD_DTYPE_INTEGER48                                     0x0013
#define ECAT_OD_DTYPE_INTEGER56                                     0x0014
#define ECAT_OD_DTYPE_INTEGER64                                     0x0015
#define ECAT_OD_DTYPE_UNSIGNED24                                    0x0016
#define ECAT_OD_DTYPE_UNSIGNED40                                    0x0018
#define ECAT_OD_DTYPE_UNSIGNED48                                    0x0019
#define ECAT_OD_DTYPE_UNSIGNED56                                    0x001a
#define ECAT_OD_DTYPE_UNSIGNED64                                    0x001b
#define ECAT_OD_DTYPE_PDO_MAPPING                                   0x0021
#define ECAT_OD_DTYPE_IDENTITY                                      0x0023
#define ECAT_OD_DTYPE_COMMAND_PAR                                   0x0025
#define ECAT_OD_DTYPE_IP_PAR                                        0x0026

/* -----------------------------------------------------------------------------
 *  commands
 * -----------------------------------------------------------------------------
 */
#define ECAT_SET_CONFIG_REQ                                         0x00002CCE
#define ECAT_SET_CONFIG_CNF                                         0x00002CCF
/* Note:
 * ECAT_SET_CONFIG_REQ/ECAT_SET_CONFIG_CNF service is currently not implemented.
 * For configuration following packets can be used (see EcsV4_Legacy.h):
 * - ECAT_DPM_WARMSTART_REQ/ECAT_DPM_WARMSTART_CNF
 * - ECAT_DPM_SET_CONFIG_REQ/ECAT_DPM_SET_CONFIG_CNF
 * - ECAT_DPM_SET_CONFIGURATION_REQ/ECAT_DPM_SET_CONFIGURATION_CNF
 */

/* -----------------------------------------------------------------------------
 *  types
 * -----------------------------------------------------------------------------
 */
#ifdef __cplusplus
	extern "C" {
#endif

typedef struct ECAT_READYWAIT_STATUS_tag
{
  TLR_UINT32 uReadyWaitBits;
} ECAT_READYWAIT_STATUS_T;

/* -----------------------------------------------------------------------------
 *  packets
 * -----------------------------------------------------------------------------
 */

/*******************************************************************************
 * ECAT_SET_CONFIG_REQ/
 * ECAT_SET_CONFIG_CNF
 */

/* basic configuration */
typedef __TLR_PACKED_PRE struct ECAT_SET_CONFIG_REQ_DATA_BASIC_Ttag
{
  TLR_UINT32 ulSystemFlags;
  TLR_UINT32 ulWatchdogTime;
  TLR_UINT32 ulVendorId;
  TLR_UINT32 ulProductCode;
  TLR_UINT32 ulRevisionNumber;
  TLR_UINT32 ulSerialNumber;
  TLR_UINT32 ulProcessDataOutputSize;
  TLR_UINT32 ulProcessDataInputSize;
  TLR_UINT32 ulComponentInitialization;
  TLR_UINT32 ulExtensionNumber;
} __TLR_PACKED_POST ECAT_SET_CONFIG_REQ_DATA_BASIC_T;

/* component configuration */
typedef __TLR_PACKED_PRE struct ECAT_SET_CONFIG_COE_Ttag
{
  TLR_UINT8  bCoeFlags;
  TLR_UINT8  bCoeDetails;
  TLR_UINT32 ulOdIndicationTimeout;
  TLR_UINT32 ulDeviceType;
  TLR_UINT16 usReserved;
} __TLR_PACKED_POST ECAT_SET_CONFIG_COE_T;

typedef __TLR_PACKED_PRE struct ECAT_SET_CONFIG_EOE_Ttag
{
  TLR_UINT32 ulReserved;
} __TLR_PACKED_POST ECAT_SET_CONFIG_EOE_T;

typedef __TLR_PACKED_PRE struct ECAT_SET_CONFIG_FOE_Ttag
{
  TLR_UINT32 ulTimeout;
} __TLR_PACKED_POST ECAT_SET_CONFIG_FOE_T;

typedef __TLR_PACKED_PRE struct ECAT_SET_CONFIG_SOE_Ttag
{
  TLR_UINT32 ulIdnIndicationTimeout;
} __TLR_PACKED_POST ECAT_SET_CONFIG_SOE_T;

typedef __TLR_PACKED_PRE struct ECAT_SET_CONFIG_SYNCMODES_Ttag{

  TLR_UINT8  bPDInHskMode;
  TLR_UINT8  bPDInSource;
  TLR_UINT16 usPDInErrorTh;
  TLR_UINT8  bPDOutHskMode;
  TLR_UINT8  bPDOutSource;
  TLR_UINT16 usPDOutErrorTh;
  TLR_UINT8  bSyncHskMode;
  TLR_UINT8  bSyncSource;
  TLR_UINT16 usSyncErrorTh;
} __TLR_PACKED_POST ECAT_SET_CONFIG_SYNCMODES_T;

typedef __TLR_PACKED_PRE struct ECAT_SET_CONFIG_SYNCPDI_Ttag{

  TLR_UINT8  bSyncPdiConfig;
  TLR_UINT16 usSyncImpulseLength;
  TLR_UINT8  bReserved;
} __TLR_PACKED_POST ECAT_SET_CONFIG_SYNCPDI_T;

typedef __TLR_PACKED_PRE struct ECAT_SET_CONFIG_UID_Ttag{

  TLR_UINT16 usStationAlias;
  TLR_UINT16 usDeviceIdentificationValue;
} __TLR_PACKED_POST ECAT_SET_CONFIG_UID_T;

typedef __TLR_PACKED_PRE struct ECAT_SET_CONFIG_REQ_DATA_COMPONENTS_Ttag
{
  ECAT_SET_CONFIG_COE_T                     tCoECfg;
  ECAT_SET_CONFIG_EOE_T                     tEoECfg;
  ECAT_SET_CONFIG_FOE_T                     tFoECfg;
  ECAT_SET_CONFIG_SOE_T                     tSoECfg;
  ECAT_SET_CONFIG_SYNCMODES_T               tSyncModesCfg;
  ECAT_SET_CONFIG_SYNCPDI_T                 tSyncPdiCfg;
  ECAT_SET_CONFIG_UID_T                     tUidCfg;
} __TLR_PACKED_POST ECAT_SET_CONFIG_REQ_DATA_COMPONENTS_T;

typedef __TLR_PACKED_PRE struct ECAT_SET_CONFIG_REQ_DATA_Ttag
{
  ECAT_SET_CONFIG_REQ_DATA_BASIC_T          tBasicCfg;
  ECAT_SET_CONFIG_REQ_DATA_COMPONENTS_T     tComponentsCfg;
} __TLR_PACKED_POST ECAT_SET_CONFIG_REQ_DATA_T;

/* request packet */
typedef struct ECAT_SET_CONFIG_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_SET_CONFIG_REQ_DATA_T                tData;
} ECAT_SET_CONFIG_REQ_T;

/* confirmation packet */
typedef struct ECAT_SET_CONFIG_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_SET_CONFIG_CNF_T;

/*******************************************************************************

 #######
  #    #
  #
  #  #    #####  ### #
  ####   #     #  # # #
  #  #    ###     # # #
  #          ##   # # #
  #    # #     #  # # #
 #######  #####  ## # ##

*/

/******************************************************************************/

/* -----------------------------------------------------------------------------
 *  defines
 * -----------------------------------------------------------------------------
 */
#define ECAT_ESM_PROCESS_QUEUE_NAME                                 "ECAT_ESM_QUE"
#define ECAT_MBX_PROCESS_QUEUE_NAME                                 "ECAT_MBX_QUE"
#define ECAT_MBX_SEND_PROCESS_QUEUE_NAME                            "ECAT_MBXS_QUE"

#define ECAT_ESM_FILTER_SIIWRITE_INDICATIONS_STATION_ALIAS          0x00000001

#define ECAT_ESM_SII_READ_DATA_BYTESIZE                             1024
#define ECAT_ESM_SII_WRITE_DATA_BYTESIZE                            1024

/* -----------------------------------------------------------------------------
 *  commands
 * -----------------------------------------------------------------------------
 */
#define ECAT_ESM_SETREADY_REQ                                       0x00001980
#define ECAT_ESM_SETREADY_CNF                                       0x00001981
#define ECAT_ESM_INIT_COMPLETE_IND                                  0x0000198E
#define ECAT_ESM_INIT_COMPLETE_RES                                  0x0000198F

#define ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_REQ             0x00001B18
#define ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_CNF             0x00001B19
#define ECAT_ESM_UNREGISTER_FROM_ALCONTROL_INDICATIONS_REQ          0x00001B1A
#define ECAT_ESM_UNREGISTER_FROM_ALCONTROL_INDICATIONS_CNF          0x00001B1B
#define ECAT_ESM_ALCONTROL_CHANGED_IND                              0x00001B1C
#define ECAT_ESM_ALCONTROL_CHANGED_RES                              0x00001B1D
#define ECAT_ESM_ALSTATUS_CHANGED_IND                               0x000019DE
#define ECAT_ESM_ALSTATUS_CHANGED_RES                               0x000019DF
#define ECAT_ESM_SET_ALSTATUS_REQ                                   0x00001B48
#define ECAT_ESM_SET_ALSTATUS_CNF                                   0x00001B49
#define ECAT_ESM_GET_ALSTATUS_REQ                                   0x00002CD0
#define ECAT_ESM_GET_ALSTATUS_CNF                                   0x00002CD1

#define ECAT_ESM_SII_READ_REQ                                       0x00001914
#define ECAT_ESM_SII_READ_CNF                                       0x00001915
#define ECAT_ESM_SII_WRITE_REQ                                      0x00001912
#define ECAT_ESM_SII_WRITE_CNF                                      0x00001913
#define ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_REQ              0x00001B82
#define ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_CNF              0x00001B83
#define ECAT_ESM_UNREGISTER_FROM_SIIWRITE_INDICATIONS_REQ           0x00001B84
#define ECAT_ESM_UNREGISTER_FROM_SIIWRITE_INDICATIONS_CNF           0x00001B85
#define ECAT_ESM_SII_WRITE_IND                                      0x00001B80
#define ECAT_ESM_SII_WRITE_RES                                      0x00001B81

/* -----------------------------------------------------------------------------
 *  types
 * -----------------------------------------------------------------------------
 */

typedef __TLR_PACKED_PRE struct ECAT_ALCONTROL_tag
{
  TLR_UINT8 uState                : 4;
  TLR_UINT8 fAcknowledge          : 1;
  TLR_UINT8 reserved              : 3;
  TLR_UINT8 bApplicationSpecific  : 8;
} __TLR_PACKED_POST ECAT_ALCONTROL_T;

typedef __TLR_PACKED_PRE struct ECAT_ALSTATUS_Ttag
{
  TLR_UINT8 uState                : 4;
  TLR_UINT8 fChange               : 1;
  TLR_UINT8 reserved              : 3;
  TLR_UINT8 bApplicationSpecific  : 8;
} __TLR_PACKED_POST ECAT_ALSTATUS_T;

/* -----------------------------------------------------------------------------
 *  packets
 * -----------------------------------------------------------------------------
 */

/*******************************************************************************
 * ECAT_ESM_SETREADY_REQ/
 * ECAT_ESM_SETREADY_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_ESM_SETREADY_REQ_DATA_Ttag
{
  TLR_UINT32 ulReadyBits;
} __TLR_PACKED_POST ECAT_ESM_SETREADY_REQ_DATA_T;

typedef struct ECAT_ESM_SETREADY_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_ESM_SETREADY_REQ_DATA_T              tData;
} ECAT_ESM_SETREADY_REQ_T;

/* confirmation packet */
typedef struct ECAT_ESM_SETREADY_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_ESM_SETREADY_CNF_T;

/*******************************************************************************
 * ECAT_ESM_INIT_COMPLETE_IND/
 * ECAT_ESM_INIT_COMPLETE_RES
 */

/* indication packet */
typedef struct ECAT_ESM_INIT_COMPLETE_IND_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_ESM_INIT_COMPLETE_IND_T;

/* response packet */
typedef struct ECAT_ESM_INIT_COMPLETE_RES_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_ESM_INIT_COMPLETE_RES_T;

/*******************************************************************************
 * ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_REQ/
 * ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_CNF
 */

/* request packet */
typedef struct ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_REQ_T;

/* confirmation packet */
typedef struct ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_CNF_T;

/*******************************************************************************
 * ECAT_ESM_UNREGISTER_FROM_ALCONTROL_INDICATIONS_REQ/
 * ECAT_ESM_UNREGISTER_FROM_ALCONTROL_INDICATIONS_CNF
 */

/* request packet */
typedef struct ECAT_ESM_UNREGISTER_FROM_ALCONTROL_INDICATIONS_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_ESM_UNREGISTER_FROM_ALCONTROL_INDICATIONS_REQ_T;

/* confirmation packet */
typedef struct ECAT_ESM_UNREGISTER_FROM_ALCONTROL_INDICATIONS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_ESM_UNREGISTER_FROM_ALCONTROL_INDICATIONS_CNF_T;

/*******************************************************************************
 * ECAT_ESM_ALCONTROL_CHANGED_IND/
 * ECAT_ESM_ALCONTROL_CHANGED_RES
 */

/* indication packet */
typedef __TLR_PACKED_PRE struct ECAT_ESM_ALCONTROL_CHANGED_IND_DATA_Ttag
{
  ECAT_ALCONTROL_T tAlControl;
  TLR_UINT16       usErrorLed;
  TLR_UINT16       usSyncControl;
  TLR_UINT16       usSyncImpulseLength;
  TLR_UINT32       ulSync0CycleTime;
  TLR_UINT32       ulSync1CycleTime;
  TLR_UINT8        bSyncPdiConfig;
} __TLR_PACKED_POST ECAT_ESM_ALCONTROL_CHANGED_IND_DATA_T;

typedef struct ECAT_ESM_ALCONTROL_CHANGED_IND_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_ESM_ALCONTROL_CHANGED_IND_DATA_T     tData;
} ECAT_ESM_ALCONTROL_CHANGED_IND_T;

/* response packet */
typedef struct ECAT_ESM_ALCONTROL_CHANGED_RES_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_ESM_ALCONTROL_CHANGED_RES_T;

/*******************************************************************************
 * ECAT_ESM_ALSTATUS_CHANGED_IND/
 * ECAT_ESM_ALSTATUS_CHANGED_RES
 */

typedef __TLR_PACKED_PRE struct ECAT_ESM_ALSTATUS_CHANGED_IND_DATA_Ttag
{
  ECAT_ALSTATUS_T tAlStatus;
  TLR_UINT16      usErrorLed;
  TLR_UINT16      usAlStatusCode;
} __TLR_PACKED_POST ECAT_ESM_ALSTATUS_CHANGED_IND_DATA_T;

typedef struct ECAT_ESM_ALSTATUS_CHANGED_IND_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_ESM_ALSTATUS_CHANGED_IND_DATA_T      tData;
} ECAT_ESM_ALSTATUS_CHANGED_IND_T;

typedef struct ECAT_ESM_ALSTATUS_CHANGED_RES_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_ESM_ALSTATUS_CHANGED_RES_T;

/*******************************************************************************
 * ECAT_ESM_SET_ALSTATUS_REQ/
 * ECAT_ESM_SET_ALSTATUS_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_ESM_SET_ALSTATUS_REQ_DATA_Ttag
{
  TLR_UINT8  bAlStatus;
  TLR_UINT8  bErrorLedState;
  TLR_UINT16 usAlStatusCode;
} __TLR_PACKED_POST ECAT_ESM_SET_ALSTATUS_REQ_DATA_T;

typedef struct ECAT_ESM_CHANGE_SET_ALSTATUS_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_ESM_SET_ALSTATUS_REQ_DATA_T          tData;
} ECAT_ESM_SET_ALSTATUS_REQ_T;

/* confirmation packet */
typedef struct ECAT_ESM_SET_ALSTATUS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_ESM_SET_ALSTATUS_CNF_T;

/*******************************************************************************
 * ECAT_ESM_GET_ALSTATUS_REQ/
 * ECAT_ESM_GET_ALSTATUS_CNF
 */

/* request packet */
typedef struct ECAT_ESM_GET_ALSTATUS_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_ESM_GET_ALSTATUS_REQ_T;

/* confirmation packet */
typedef __TLR_PACKED_PRE struct ECAT_ESM_GET_ALSTATUS_CNF_DATA_Ttag
{
  TLR_UINT8  bAlStatus;
  TLR_UINT8  bErrorLedState;
  TLR_UINT16 usAlStatusCode;
} __TLR_PACKED_POST ECAT_ESM_GET_ALSTATUS_CNF_DATA_T;

typedef struct ECAT_ESM_GET_ALSTATUS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_ESM_GET_ALSTATUS_CNF_DATA_T          tData;
} ECAT_ESM_GET_ALSTATUS_CNF_T;

/*******************************************************************************
 * ECAT_ESM_SII_READ_REQ/
 * ECAT_ESM_SII_READ_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_ESM_SII_READ_REQ_DATA_Ttag
{
  TLR_UINT32 ulOffset;
  TLR_UINT32 ulSize;
} __TLR_PACKED_POST ECAT_ESM_SII_READ_REQ_DATA_T;

typedef struct ECAT_ESM_SII_READ_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_ESM_SII_READ_REQ_DATA_T              tData;
} ECAT_ESM_SII_READ_REQ_T;

/* confirmation packet */
typedef __TLR_PACKED_PRE struct ECAT_ESM_SII_READ_CNF_DATA_Ttag
{
  TLR_UINT8 abData[ECAT_ESM_SII_READ_DATA_BYTESIZE];
} __TLR_PACKED_POST ECAT_ESM_SII_READ_CNF_DATA_T;

typedef struct ECAT_ESM_SII_READ_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_ESM_SII_READ_CNF_DATA_T              tData;
} ECAT_ESM_SII_READ_CNF_T;


/*******************************************************************************
 * ECAT_ESM_SII_WRITE_REQ/
 * ECAT_ESM_SII_WRITE_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_ESM_SII_WRITE_REQ_DATA_Ttag
{
  TLR_UINT32 ulOffset;
  TLR_UINT8  abData[ECAT_ESM_SII_WRITE_DATA_BYTESIZE];
} __TLR_PACKED_POST ECAT_ESM_SII_WRITE_REQ_DATA_T;

typedef struct ECAT_ESM_SII_WRITE_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_ESM_SII_WRITE_REQ_DATA_T             tData;
} ECAT_ESM_SII_WRITE_REQ_T;

/* confirmation packet */
typedef struct ECAT_ESM_SII_WRITE_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_ESM_SII_WRITE_CNF_T;

/*******************************************************************************
 * ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_REQ/
 * ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_REQ_DATA_Ttag
{
  TLR_UINT32 ulIndicationFlags;
} __TLR_PACKED_POST ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_REQ_DATA_T;

typedef struct ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                   tHead;
  ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_REQ_DATA_T tData;
} ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_REQ_T;

/* confirmation packet */
typedef struct ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                   tHead;
  /* no data part */
} ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_CNF_T;


/*******************************************************************************
 * ECAT_ESM_UNREGISTER_FROM_SIIWRITE_INDICATIONS_REQ/
 * ECAT_ESM_UNREGISTER_FROM_SIIWRITE_INDICATIONS_CNF
 */

/* request packet */
typedef struct ECAT_ESM_UNREGISTER_FROM_SIIWRITE_INDICATIONS_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_ESM_UNREGISTER_FROM_SIIWRITE_INDICATIONS_REQ_T;

/* confirmation packet */
typedef struct ECAT_ESM_UNREGISTER_FROM_SIIWRITE_INDICATIONS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_ESM_UNREGISTER_FROM_SIIWRITE_INDICATIONS_CNF_T;

/*******************************************************************************
 * ECAT_ESM_SII_WRITE_IND/
 * ECAT_ESM_SII_WRITE_RES
 */

/* indication packet */
typedef __TLR_PACKED_PRE struct ECAT_ESM_SII_WRITE_IND_DATA_Ttag
{
  TLR_UINT32 ulSiiWriteStartAddress;
  TLR_UINT8  abData[2];
} __TLR_PACKED_POST ECAT_ESM_SII_WRITE_IND_DATA_T;

typedef struct ECAT_ESM_SII_WRITE_IND_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_ESM_SII_WRITE_IND_DATA_T             tData;
} ECAT_ESM_SII_WRITE_IND_T;

/* response packet */
typedef struct ECAT_ESM_SII_WRITE_RES_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_ESM_SII_WRITE_RES_T;


/*******************************************************************************


 #####   ######  ##   ##
  #   #   #    #  #   #
  #    #  #    #  ## ##
  #    #  #    #  ## ##
  #    #  #####   # # #
  #    #  #       # # #
  #    #  #       #   #
  #   #   #       #   #
 #####   ####    ### ###


*/

/* -----------------------------------------------------------------------------
 *  defines
 * -----------------------------------------------------------------------------
 */
#define ECAT_DPM_QUEUE_NAME                                         "QUE_ECAT_DPM"

/* -----------------------------------------------------------------------------
 *  commands
 * -----------------------------------------------------------------------------
 */
#define ECAT_DPM_SET_IO_SIZE_REQ                                    0x00002CC0
#define ECAT_DPM_SET_IO_SIZE_CNF                                    0x00002CC1
#define ECAT_DPM_SET_STATION_ALIAS_REQ                              0x00002CC6
#define ECAT_DPM_SET_STATION_ALIAS_CNF                              0x00002CC7
#define ECAT_DPM_GET_STATION_ALIAS_REQ                              0x00002CC8
#define ECAT_DPM_GET_STATION_ALIAS_CNF                              0x00002CC9

/* -----------------------------------------------------------------------------
 *  types
 * -----------------------------------------------------------------------------
 */

/* -----------------------------------------------------------------------------
 *  packets
 * -----------------------------------------------------------------------------
 */

/*******************************************************************************
 * ECAT_DPM_SET_IO_SIZE_REQ/
 * ECAT_DPM_SET_IO_SIZE_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_DPM_SET_IO_SIZE_REQ_DATA_Ttag
{
  TLR_UINT32 ulProcessDataOutputSize;
  TLR_UINT32 ulProcessDataInputSize;
} __TLR_PACKED_POST ECAT_DPM_SET_IO_SIZE_REQ_DATA_T;

typedef struct ECAT_DPM_SET_IO_SIZE_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_DPM_SET_IO_SIZE_REQ_DATA_T           tData;
} ECAT_DPM_SET_IO_SIZE_REQ_T;

/* confirmation packet */
typedef struct ECAT_DPM_SET_IO_SIZE_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_DPM_SET_IO_SIZE_CNF_T;

/*******************************************************************************
 * ECAT_DPM_SET_STATION_ALIAS_REQ/
 * ECAT_DPM_SET_STATION_ALIAS_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_DPM_SET_STATION_ALIAS_REQ_DATA_Ttag
{
  TLR_UINT16 usStationAlias;
} __TLR_PACKED_POST ECAT_DPM_SET_STATION_ALIAS_REQ_DATA_T;

typedef struct ECAT_DPM_SET_STATION_ALIAS_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_DPM_SET_STATION_ALIAS_REQ_DATA_T     tData;
} ECAT_DPM_SET_STATION_ALIAS_REQ_T;

/* confirmation packet */
typedef struct ECAT_DPM_SET_STATION_ALIAS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_DPM_SET_STATION_ALIAS_CNF_T;

/*******************************************************************************
 * ECAT_DPM_GET_STATION_ALIAS_REQ/
 * ECAT_DPM_GET_STATION_ALIAS_CNF
 */

/* request packet */
typedef struct ECAT_DPM_GET_STATION_ALIAS_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_DPM_GET_STATION_ALIAS_REQ_T;

/* confirmation packet */
typedef __TLR_PACKED_PRE struct ECAT_DPM_GET_STATION_ALIAS_CNF_DATA_Ttag
{
  TLR_UINT16 usStationAlias;
} __TLR_PACKED_POST ECAT_DPM_GET_STATION_ALIAS_CNF_DATA_T;

typedef struct ECAT_DPM_GET_STATION_ALIAS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_DPM_GET_STATION_ALIAS_CNF_DATA_T     tData;
} ECAT_DPM_GET_STATION_ALIAS_CNF_T;



/*******************************************************************************


   ####          #######
  #    #          #    #
 #                #
 #        #####   #  #
 #       #     #  ####
 #       #     #  #  #
 #       #     #  #
  #    # #     #  #    #
   ####   #####  #######


*/

/* -----------------------------------------------------------------------------
 *  defines
 * -----------------------------------------------------------------------------
 */
#define ECAT_COE_PROCESS_QUEUE_NAME                                 "ECAT_COE_QUE"
#define ECAT_SDO_PROCESS_QUEUE_NAME                                 "ECAT_SDO_QUE"

/* -----------------------------------------------------------------------------
 *  commands
 * -----------------------------------------------------------------------------
 */
#define ECAT_COE_SEND_EMERGENCY_REQ                                 0x00001994
#define ECAT_COE_SEND_EMERGENCY_CNF                                 0x00001995

/* -----------------------------------------------------------------------------
 *  types
 * -----------------------------------------------------------------------------
 */

/* -----------------------------------------------------------------------------
 *  packets
 * -----------------------------------------------------------------------------
 */

/*******************************************************************************
 * ECAT_COE_SEND_EMERGENCY_REQ/
 * ECAT_COE_SEND_EMERGENCY_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_COE_SEND_EMERGENCY_REQ_DATA_Ttag
{
  TLR_UINT16 usStationAddress;
  TLR_UINT16 usPriority;
  TLR_UINT16 usErrorCode;
  TLR_UINT8  bErrorRegister;
  TLR_UINT8  abDiagnosticData[5];
} __TLR_PACKED_POST ECAT_COE_SEND_EMERGENCY_REQ_DATA_T;

typedef struct ECAT_COE_SEND_EMERGENCY_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_COE_SEND_EMERGENCY_REQ_DATA_T        tData;
} ECAT_COE_SEND_EMERGENCY_REQ_T;

/* confirmation packet */
typedef struct ECAT_COE_SEND_EMERGENCY_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_COE_SEND_EMERGENCY_CNF_T;

/*******************************************************************************

 #######          #######
  #    #           #    #
  #                #
  #  #     #####   #  #
  ####    #     #  ####
  #  #    #     #  #  #
  #       #     #  #
  #    #  #     #  #    #
 #######   #####  #######

*/

/* -----------------------------------------------------------------------------
 *  defines
 * -----------------------------------------------------------------------------
 */
#define ECAT_EOE_PROCESS_QUEUE_NAME                                 "ECAT_EOE_QUE"

#define ECAT_EOE_FRAME_DATA_SIZE                                    1504
#define ECAT_EOE_FRAME_HEADER_SIZE                                  14

#define ECAT_EOE_FRAME_FLAG_TIME_REQUEST                            0x0001
#define ECAT_EOE_FRAME_FLAG_TIME_VALID                              0x0002

#define ECAT_EOE_SET_IP_PARAM_MAC_ADDRESS_INCLUDED                  0x00000001
#define ECAT_EOE_SET_IP_PARAM_IP_ADDRESS_INCLUDED                   0x00000002
#define ECAT_EOE_SET_IP_PARAM_SUBNET_MASK_INCLUDED                  0x00000004
#define ECAT_EOE_SET_IP_PARAM_DEFAULT_GATEWAY_INCLUDED              0x00000008
#define ECAT_EOE_SET_IP_PARAM_DNS_SERVER_IP_ADDR_INCLUDED           0x00000010
#define ECAT_EOE_SET_IP_PARAM_DNS_NAME_INCLUDED                     0x00000020

#define ECAT_EOE_GET_IP_PARAM_MAC_ADDRESS_INCLUDED                  0x00000001
#define ECAT_EOE_GET_IP_PARAM_IP_ADDRESS_INCLUDED                   0x00000002
#define ECAT_EOE_GET_IP_PARAM_SUBNET_MASK_INCLUDED                  0x00000004
#define ECAT_EOE_GET_IP_PARAM_DEFAULT_GATEWAY_INCLUDED              0x00000008
#define ECAT_EOE_GET_IP_PARAM_DNS_SERVER_IP_ADDR_INCLUDED           0x00000010
#define ECAT_EOE_GET_IP_PARAM_DNS_NAME_INCLUDED                     0x00000020

/* -----------------------------------------------------------------------------
 *  commands
 * -----------------------------------------------------------------------------
 */
#define ECAT_EOE_REGISTER_FOR_FRAME_INDICATIONS_REQ                 0x00001B76
#define ECAT_EOE_REGISTER_FOR_FRAME_INDICATIONS_CNF                 0x00001B77
#define ECAT_EOE_UNREGISTER_FROM_FRAME_INDICATIONS_REQ              0x00001B78
#define ECAT_EOE_UNREGISTER_FROM_FRAME_INDICATIONS_CNF              0x00001B79
#define ECAT_EOE_SEND_FRAME_REQ                                     0x00001B72
#define ECAT_EOE_SEND_FRAME_CNF                                     0x00001B73
#define ECAT_EOE_FRAME_RECEIVED_IND                                 0x00001B70
#define ECAT_EOE_FRAME_RECEIVED_RES                                 0x00001B71
#define ECAT_EOE_REGISTER_FOR_IP_PARAM_INDICATIONS_REQ              0x00001B7A
#define ECAT_EOE_REGISTER_FOR_IP_PARAM_INDICATIONS_CNF              0x00001B7B
#define ECAT_EOE_UNREGISTER_FROM_IP_PARAM_INDICATIONS_REQ           0x00001B7C
#define ECAT_EOE_UNREGISTER_FROM_IP_PARAM_INDICATIONS_CNF           0x00001B7D
#define ECAT_EOE_SET_IP_PARAM_IND                                   0x00001B7E
#define ECAT_EOE_SET_IP_PARAM_RES                                   0x00001B7F
#define ECAT_EOE_GET_IP_PARAM_IND                                   0x00001B50
#define ECAT_EOE_GET_IP_PARAM_RES                                   0x00001B51

/* -----------------------------------------------------------------------------
 *  types
 * -----------------------------------------------------------------------------
 */

/* -----------------------------------------------------------------------------
 *  packets
 * -----------------------------------------------------------------------------
 */

/*******************************************************************************
 * ECAT_EOE_REGISTER_FOR_FRAME_INDICATIONS_REQ/
 * ECAT_EOE_REGISTER_FOR_FRAME_INDICATIONS_REQ
 */

/* request packet */
typedef struct ECAT_EOE_REGISTER_FOR_FRAME_INDICATIONS_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_EOE_REGISTER_FOR_FRAME_INDICATIONS_REQ_T;

/* confirmation packet */
typedef struct ECAT_EOE_REGISTER_FOR_FRAME_INDICATIONS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_EOE_REGISTER_FOR_FRAME_INDICATIONS_CNF_T;

/*******************************************************************************
 * ECAT_EOE_UNREGISTER_FROM_FRAME_INDICATIONS_REQ/
 * ECAT_EOE_UNREGISTER_FROM_FRAME_INDICATIONS_CNF
 */

/* request packet */
typedef struct ECAT_EOE_UNREGISTER_FROM_FRAME_INDICATIONS_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_EOE_UNREGISTER_FROM_FRAME_INDICATIONS_REQ_T;


/* confirmation packet */
typedef struct ECAT_EOE_UNREGISTER_FROM_FRAME_INDICATIONS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_EOE_UNREGISTER_FROM_FRAME_INDICATIONS_CNF_T;

/*******************************************************************************
 * ECAT_EOE_REGISTER_FOR_IP_PARAM_INDICATIONS_REQ/
 * ECAT_EOE_REGISTER_FOR_IP_PARAM_INDICATIONS_CNF
 */

/* request packet */
typedef struct ECAT_EOE_REGISTER_FOR_IP_PARAM_INDICATIONS_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_EOE_REGISTER_FOR_IP_PARAM_INDICATIONS_REQ_T;

/* confirmation packet */
typedef struct ECAT_EOE_REGISTER_FOR_IP_PARAM_INDICATIONS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_EOE_REGISTER_FOR_IP_PARAM_INDICATIONS_CNF_T;

/*******************************************************************************
 * ECAT_EOE_UNREGISTER_FROM_IP_PARAM_INDICATIONS_REQ/
 * ECAT_EOE_UNREGISTER_FROM_IP_PARAM_INDICATIONS_CNF
 */

/* request packet */
typedef struct ECAT_EOE_UNREGISTER_FROM_IP_PARAM_INDICATIONS_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_EOE_UNREGISTER_FROM_IP_PARAM_INDICATIONS_REQ_T;

/* confirmation packet */
typedef struct ECAT_EOE_UNREGISTER_FROM_IP_PARAM_INDICATIONS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_EOE_UNREGISTER_FROM_IP_PARAM_INDICATIONS_CNF_T;

/*******************************************************************************
 * ECAT_EOE_SET_IP_PARAM_IND/
 * ECAT_EOE_SET_IP_PARAM_RES
 */

/* indication packet */
typedef __TLR_PACKED_PRE struct ECAT_EOE_SET_IP_PARAM_IND_DATA_Ttag
{
  TLR_UINT32 ulFlags;
  TLR_UINT8  abMacAddr[6];
  TLR_UINT8  abIpAddr[4];
  TLR_UINT8  abSubnetMask[4];
  TLR_UINT8  abDefaultGateway[4];
  TLR_UINT8  abDnsServerIpAddress[4];
  TLR_STR    abDnsName[32];
} __TLR_PACKED_POST ECAT_EOE_SET_IP_PARAM_IND_DATA_T;

typedef struct ECAT_EOE_SET_IP_PARAM_IND_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_EOE_SET_IP_PARAM_IND_DATA_T          tData;
} ECAT_EOE_SET_IP_PARAM_IND_T;

/* response packet */
typedef struct ECAT_EOE_SET_IP_PARAM_RES_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_EOE_SET_IP_PARAM_RES_T;

/*******************************************************************************
 * ECAT_EOE_GET_IP_PARAM_IND/
 * ECAT_EOE_GET_IP_PARAM_RES
 */

/* indication packet */
typedef struct ECAT_EOE_GET_IP_PARAM_IND_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_EOE_GET_IP_PARAM_IND_T;

/* response packet */
typedef __TLR_PACKED_PRE struct ECAT_EOE_GET_IP_PARAM_RES_DATA_Ttag
{
  TLR_UINT32 ulFlags;
  TLR_UINT8  abMacAddr[6];
  TLR_UINT8  abIpAddr[4];
  TLR_UINT8  abSubnetMask[4];
  TLR_UINT8  abDefaultGateway[4];
  TLR_UINT8  abDnsServerIpAddress[4];
  TLR_STR    abDnsName[32];
} __TLR_PACKED_POST ECAT_EOE_GET_IP_PARAM_RES_DATA_T;

typedef struct ECAT_EOE_GET_IP_PARAM_RES_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_EOE_GET_IP_PARAM_RES_DATA_T          tData;
} ECAT_EOE_GET_IP_PARAM_RES_T;

/*******************************************************************************
 * ECAT_EOE_SEND_FRAME_REQ/
 * ECAT_EOE_SEND_FRAME_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_EOE_SEND_FRAME_REQ_DATA_Ttag
{
  TLR_UINT16 usFlags;
  TLR_UINT16 usPortNo;
  TLR_UINT32 ulTimestampNs;
  TLR_UINT8  abDstMacAddr[6];
  TLR_UINT8  abSrcMacAddr[6];
  TLR_UINT16 usEthType;
  TLR_UINT8  abData[ECAT_EOE_FRAME_DATA_SIZE];
} __TLR_PACKED_POST ECAT_EOE_SEND_FRAME_REQ_DATA_T;

typedef struct ECAT_EOE_SEND_FRAME_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_EOE_SEND_FRAME_REQ_DATA_T            tData;
} ECAT_EOE_SEND_FRAME_REQ_T;

/* confirmation packet */
typedef __TLR_PACKED_PRE struct ECAT_EOE_SEND_FRAME_CNF_DATA_Ttag
{
  TLR_UINT16 usFlags;
  TLR_UINT32 ulTimestampNs;
  TLR_UINT16 usFrameLen;
} __TLR_PACKED_POST ECAT_EOE_SEND_FRAME_CNF_DATA_T;

typedef struct ECAT_EOE_SEND_FRAME_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_EOE_SEND_FRAME_CNF_DATA_T            tData;
} ECAT_EOE_SEND_FRAME_CNF_T;

/*******************************************************************************
 * ECAT_EOE_FRAME_RECEIVED_IND/
 * ECAT_EOE_FRAME_RECEIVED_RES
 */

/* indication packet */
typedef __TLR_PACKED_PRE struct ECAT_EOE_FRAME_RECEIVED_IND_DATA_Ttag
{
  TLR_UINT16 usFlags;
  TLR_UINT16 usPortNo;
  TLR_UINT32 ulTimestampNs;
  TLR_UINT8  abDstMacAddr[6];
  TLR_UINT8  abSrcMacAddr[6];
  TLR_UINT16 usEthType;
  TLR_UINT8  abData[ECAT_EOE_FRAME_DATA_SIZE];
} __TLR_PACKED_POST ECAT_EOE_FRAME_RECEIVED_IND_DATA_T;

typedef struct ECAT_EOE_FRAME_RECEIVED_IND_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_EOE_FRAME_RECEIVED_IND_DATA_T        tData;
} ECAT_EOE_FRAME_RECEIVED_IND_T;

/* response packet */
typedef __TLR_PACKED_PRE struct ECAT_EOE_FRAME_RECEIVED_RES_DATA_Ttag
{
  TLR_UINT16 usFlags;
  TLR_UINT32 ulTimestampNs;
  TLR_UINT16 usFrameLen;
} __TLR_PACKED_POST ECAT_EOE_FRAME_RECEIVED_RES_DATA_T;

typedef struct ECAT_EOE_FRAME_RECEIVED_RES_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_EOE_FRAME_RECEIVED_RES_DATA_T        tData;
} ECAT_EOE_FRAME_RECEIVED_RES_T;


/*******************************************************************************


  #####          #######
 #     #          #    #
 #                #
 #        #####   #  #
  #####  #     #  ####
       # #     #  #  #
       # #     #  #
 #     # #     #  #    #
  #####   #####  #######


*/

/* -----------------------------------------------------------------------------
 *  defines
 * -----------------------------------------------------------------------------
 */
#define ECAT_SOE_IDN_PROCESS_QUEUE_NAME                             "ECAT_SOEIDN_QUE"

#define ECAT_SOEIDN_CREATE_IDN_MIN_DATA_SIZE                        (sizeof(ECAT_SOEIDN_CREATE_IDN_REQ_DATA_T) - sizeof(((ECAT_SOEIDN_CREATE_IDN_REQ_DATA_T*)0)->abData))
#define ECAT_SOEIDN_SET_IDN_NAME_REQ_MIN_SIZE                       (3 * sizeof(TLR_UINT16) + sizeof(TLR_UINT8))
#define ECAT_SOEIDN_SET_IDN_UNIT_REQ_MIN_SIZE                       (3 * sizeof(TLR_UINT16) + sizeof(TLR_UINT8))
#define ECAT_SOE_READ_IDN_RES_MIN_SIZE                              (3 * sizeof(TLR_UINT16))
#define ECAT_SOE_READ_IDN_CNF_MIN_SIZE                              (3 * sizeof(TLR_UINT16))
#define ECAT_SOE_WRITE_IDN_IND_MIN_SIZE                             (sizeof(TLR_UINT16) + sizeof(TLR_UINT8) + sizeof(TLR_UINT8) + sizeof(TLR_UINT16))
#define ECAT_SOE_WRITE_IDN_REQ_MIN_SIZE                             (sizeof(TLR_UINT16) + sizeof(TLR_UINT8) + sizeof(TLR_UINT8) + sizeof(TLR_UINT16))

/* following values are appended in order of their definition to abData */
#define MSK_ECAT_SOEIDN_CREATE_IDN_VALUE_INFO_DATASTATE             0x01
#define MSK_ECAT_SOEIDN_CREATE_IDN_VALUE_INFO_NAME                  0x02
#define MSK_ECAT_SOEIDN_CREATE_IDN_VALUE_INFO_UNIT                  0x04
#define MSK_ECAT_SOEIDN_CREATE_IDN_VALUE_INFO_MINIMUM               0x08
#define MSK_ECAT_SOEIDN_CREATE_IDN_VALUE_INFO_MAXIMUM               0x10
#define MSK_ECAT_SOEIDN_CREATE_IDN_VALUE_INFO_VALUE                 0x20
#define MSK_ECAT_SOEIDN_CREATE_IDN_VALUE_INFO_DEFVALUE              0x40

/* definitions for bElement */
#define ECAT_SOE_IDN_ELEMENT_DATASTATE                              1
#define ECAT_SOE_IDN_ELEMENT_NAME                                   2
#define ECAT_SOE_IDN_ELEMENT_ATTRIBUTE                              3
#define ECAT_SOE_IDN_ELEMENT_UNIT                                   4
#define ECAT_SOE_IDN_ELEMENT_MINIMUM_VALUE                          5
#define ECAT_SOE_IDN_ELEMENT_MAXIMUM_VALUE                          6
#define ECAT_SOE_IDN_ELEMENT_OPDATA                                 7
#define ECAT_SOE_IDN_ELEMENT_DEFAULT_VALUE                          8

/* definitions for usDataStatus */
#define MSK_ECAT_SOE_IDN_DATA_STATUS_OPDATA_INVALID                 0x0100
#define MSK_ECAT_SOE_IDN_DATA_STATUS_COMMAND_ERROR                  0x0008
#define MSK_ECAT_SOE_IDN_DATA_STATUS_COMMAND_NOT_EXECUTED           0x0004
#define MSK_ECAT_SOE_IDN_DATA_STATUS_COMMAND_EXECUTION_ENABLED      0x0002
#define MSK_ECAT_SOE_IDN_DATA_STATUS_COMMAND_SET                    0x0001

/* definitions for ulAttribute */
#define MSK_ECAT_SOE_IDN_ATTR_OPDATA_WRITE_PROTECTED_IN_CP4         0x40000000
#define MSK_ECAT_SOE_IDN_ATTR_OPDATA_WRITE_PROTECTED_IN_CP3         0x20000000
#define MSK_ECAT_SOE_IDN_ATTR_OPDATA_WRITE_PROTECTED_IN_CP2         0x10000000

#define MSK_ECAT_SOE_IDN_ATTR_DECIMAL_PLACEMENT                     0x0F000000
#define SRT_ECAT_SOE_IDN_ATTR_DECIMAL_PLACEMENT                     24

#define MSK_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT                        0x00700000
#define SRT_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT                        20
#define VAL_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT_BINARY                 0x00000000
#define VAL_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT_UNSIGNED_DECIMAL       0x00100000
#define VAL_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT_SIGNED_DECIMAL         0x00200000
#define VAL_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT_UNSIGNED_HEXADECIMAL   0x00300000
#define VAL_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT_TEXT                   0x00400000
#define VAL_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT_IDN                    0x00500000
#define VAL_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT_FLOATING_POINT         0x00600000
#define VAL_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT_RESERVED               0x00700000

#define MSK_ECAT_SOE_IDN_ATTR_OPDATA_IS_PROC_CMD                    0x00080000

#define MSK_ECAT_SOE_IDN_ATTR_DATA_LENGTH                           0x00070000
#define SRT_ECAT_SOE_IDN_ATTR_DATA_LENGTH                           16
#define VAL_ECAT_SOE_IDN_ATTR_DATA_LENGTH_RESERVED0                 0x00000000
#define VAL_ECAT_SOE_IDN_ATTR_DATA_LENGTH_TWO_BYTE                  0x00010000
#define VAL_ECAT_SOE_IDN_ATTR_DATA_LENGTH_FOUR_BYTE                 0x00020000
#define VAL_ECAT_SOE_IDN_ATTR_DATA_LENGTH_EIGHT_BYTE                0x00030000
#define VAL_ECAT_SOE_IDN_ATTR_DATA_LENGTH_ONE_BYTE_LIST             0x00040000
#define VAL_ECAT_SOE_IDN_ATTR_DATA_LENGTH_TWO_BYTE_LIST             0x00050000
#define VAL_ECAT_SOE_IDN_ATTR_DATA_LENGTH_FOUR_BYTE_LIST            0x00060000
#define VAL_ECAT_SOE_IDN_ATTR_DATA_LENGTH_EIGHT_BYTE_LIST           0x00070000
#define MSK_ECAT_SOE_IDN_ATTR_DATA_LENGTH_IS_LIST                   0x00040000

#define MSK_ECAT_SOE_IDN_ATTR_SCALING                               0x0000FFFF
#define SRT_ECAT_SOE_IDN_ATTR_SCALING                               0

/* -----------------------------------------------------------------------------
 *  commands
 * -----------------------------------------------------------------------------
 */
#define ECAT_SOEIDN_CREATE_IDN_REQ                                  0x00005840
#define ECAT_SOEIDN_CREATE_IDN_CNF                                  0x00005841
#define ECAT_SOEIDN_DELETE_IDN_REQ                                  0x00005842
#define ECAT_SOEIDN_DELETE_IDN_CNF                                  0x00005843
#define ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_REQ                0x00005844
#define ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_CNF                0x00005845
#define ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_REQ             0x00005846
#define ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_CNF             0x00005847
#define ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_REQ      0x00005848
#define ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_CNF      0x00005849
#define ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_REQ   0x0000584A
#define ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_CNF   0x0000584B
#define ECAT_SOEIDN_SET_IDN_NAME_REQ                                0x0000584C
#define ECAT_SOEIDN_SET_IDN_NAME_CNF                                0x0000584D
#define ECAT_SOEIDN_SET_IDN_UNIT_REQ                                0x0000584E
#define ECAT_SOEIDN_SET_IDN_UNIT_CNF                                0x0000584F

#define ECAT_SOE_READ_IDN_REQ                                       0x00005802
#define ECAT_SOE_READ_IDN_CNF                                       0x00005803
#define ECAT_SOE_READ_IDN_IND                                       0x00005802
#define ECAT_SOE_READ_IDN_RES                                       0x00005803
#define ECAT_SOE_WRITE_IDN_REQ                                      0x00005800
#define ECAT_SOE_WRITE_IDN_CNF                                      0x00005801
#define ECAT_SOE_WRITE_IDN_IND                                      0x00005800
#define ECAT_SOE_WRITE_IDN_RES                                      0x00005801

#define ECAT_SOE_PROCCMD_NOTIFY_REQ                                 0x00005810
#define ECAT_SOE_PROCCMD_NOTIFY_CNF                                 0x00005811

/* -----------------------------------------------------------------------------
 *  types
 * -----------------------------------------------------------------------------
 */

/* -----------------------------------------------------------------------------
 *  packets
 * -----------------------------------------------------------------------------
 */

/*******************************************************************************
 *  ECAT_SOEIDN_CREATE_IDN_REQ/
 *  ECAT_SOEIDN_CREATE_IDN_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_SOEIDN_CREATE_IDN_REQ_DATA_Ttag
{
  /* unfragmentable part */
  TLR_UINT32 ulTotalLength;
  TLR_UINT16 usIdn;
  TLR_UINT16 usMaxListDataSize;
  TLR_UINT32 ulAttribute;
  TLR_UINT8  bDriveNo;
  TLR_UINT8  bValueInfo;
  TLR_UINT16 usMaxNameLength;
  TLR_UINT16 usMaxUnitLength;
  /* fragmentable part */
  TLR_UINT8 abData[1];
} __TLR_PACKED_POST ECAT_SOEIDN_CREATE_IDN_REQ_DATA_T;

typedef struct ECAT_SOEIDN_CREATE_IDN_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_SOEIDN_CREATE_IDN_REQ_DATA_T         tData;
} ECAT_SOEIDN_CREATE_IDN_REQ_T;

/* confirmation packet */
typedef __TLR_PACKED_PRE struct ECAT_SOEIDN_CREATE_IDN_CNF_DATA_Ttag
{
  TLR_UINT16 usIdn;
  TLR_UINT8  bDriveNo;
} __TLR_PACKED_POST ECAT_SOEIDN_CREATE_IDN_CNF_DATA_T;

typedef struct ECAT_SOEIDN_CREATE_IDN_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_SOEIDN_CREATE_IDN_CNF_DATA_T         tData;
} ECAT_SOEIDN_CREATE_IDN_CNF_T;

/*******************************************************************************
 *  ECAT_SOEIDN_DELETE_IDN_REQ/
 *  ECAT_SOEIDN_DELETE_IDN_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_SOEIDN_DELETE_IDN_REQ_DATA_Ttag
{
  TLR_UINT16 usIdn;
  TLR_UINT8  bDriveNo;
} __TLR_PACKED_POST ECAT_SOEIDN_DELETE_IDN_REQ_DATA_T;

typedef struct ECAT_SOEIDN_DELETE_IDN_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_SOEIDN_DELETE_IDN_REQ_DATA_T         tData;
} ECAT_SOEIDN_DELETE_IDN_REQ_T;

/* confirmation packet */
typedef __TLR_PACKED_PRE struct ECAT_SOEIDN_DELETE_IDN_CNF_DATA_Ttag
{
  TLR_UINT16 usIdn;
  TLR_UINT8  bDriveNo;
} __TLR_PACKED_POST ECAT_SOEIDN_DELETE_IDN_CNF_DATA_T;

typedef struct ECAT_SOEIDN_DELETE_IDN_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_SOEIDN_DELETE_IDN_CNF_DATA_T         tData;
} ECAT_SOEIDN_DELETE_IDN_CNF_T;

/*******************************************************************************
 * ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_REQ/
 * ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_REQ_DATA_Ttag
{
  TLR_UINT16   usIdn;
  TLR_UINT8    bDriveNo;
  TLR_BOOLEAN8 fReadNotify;
  TLR_BOOLEAN8 fWriteNotify;
} __TLR_PACKED_POST ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_REQ_DATA_T;

typedef struct ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                   tHead;
  ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_REQ_DATA_T   tData;
} ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_REQ_T;

/* confirmation packet */
typedef __TLR_PACKED_PRE struct ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_CNF_DATA_Ttag
{
  TLR_UINT16 usIdn;
  TLR_UINT8  bDriveNo;
} __TLR_PACKED_POST ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_CNF_DATA_T;

typedef struct ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                   tHead;
  ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_CNF_DATA_T   tData;
} ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_CNF_T;

/*******************************************************************************
 *  ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_REQ/
 *  ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_REQ_DATA_Ttag
{
  TLR_UINT16 usIdn;
  TLR_UINT8  bDriveNo;
} __TLR_PACKED_POST ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_REQ_DATA_T;

typedef struct ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_REQ_DATA_T  tData;
} ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_REQ_T;

/* confirmation packet */
typedef __TLR_PACKED_PRE struct ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_CNF_DATA_Ttag
{
  TLR_UINT16 usIdn;
  TLR_UINT8  bDriveNo;
} __TLR_PACKED_POST ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_CNF_DATA_T;

typedef struct ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_CNF_DATA_T  tData;
} ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_CNF_T;

/*******************************************************************************
 *  ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_REQ/
 *  ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_REQ_DATA_Ttag
{
  TLR_UINT8 bDriveNo;
} __TLR_PACKED_POST ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_REQ_DATA_T;

typedef struct ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                               tHead;
  ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_REQ_DATA_T     tData;
} ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_REQ_T;

/* confirmation packet */
typedef __TLR_PACKED_PRE struct ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_CNF_DATA_Ttag
{
  TLR_UINT8 bDriveNo;
} __TLR_PACKED_POST ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_CNF_DATA_T;

typedef struct ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                               tHead;
  ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_CNF_DATA_T     tData;
} ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_CNF_T;

/*******************************************************************************
 * ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_REQ/
 * ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_REQ_DATA_Ttag
{
  TLR_UINT8 bDriveNo;
} __TLR_PACKED_POST ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_REQ_DATA_T;

typedef struct ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                               tHead;
  ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_REQ_DATA_T  tData;
} ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_REQ_T;

/* confirmation packet */
typedef __TLR_PACKED_PRE struct ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_CNF_DATA_Ttag
{
  TLR_UINT8 bDriveNo;
} __TLR_PACKED_POST ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_CNF_DATA_T;

typedef struct ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                               tHead;
  ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_CNF_DATA_T  tData;
} ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_CNF_T;

/*******************************************************************************
 * ECAT_SOEIDN_SET_NAME_REQ/
 * ECAT_SOEIDN_SET_NAME_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_SOEIDN_SET_IDN_NAME_REQ_DATA_Ttag
{
  TLR_UINT8  bDriveNo;
  TLR_UINT16 usIdn;
  TLR_UINT16 usNameLength;
  TLR_UINT16 usPad;
  TLR_STR    szName[256];
} __TLR_PACKED_POST ECAT_SOEIDN_SET_IDN_NAME_REQ_DATA_T;

typedef struct ECAT_SOEIDN_SET_IDN_NAME_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_SOEIDN_SET_IDN_NAME_REQ_DATA_T       tData;
} ECAT_SOEIDN_SET_IDN_NAME_REQ_T;

/* confirmation packet */
typedef __TLR_PACKED_PRE struct ECAT_SOEIDN_SET_IDN_NAME_CNF_DATA_Ttag
{
  TLR_UINT8  bDriveNo;
  TLR_UINT16 usIdn;
} __TLR_PACKED_POST ECAT_SOEIDN_SET_IDN_NAME_CNF_DATA_T;

typedef struct ECAT_SOEIDN_SET_IDN_NAME_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_SOEIDN_SET_IDN_NAME_CNF_DATA_T       tData;
} ECAT_SOEIDN_SET_IDN_NAME_CNF_T;

/*******************************************************************************
 * ECAT_SOEIDN_SET_UNIT_REQ/
 * ECAT_SOEIDN_SET_UNIT_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_SOEIDN_SET_IDN_UNIT_REQ_DATA_Ttag
{
  TLR_UINT8  bDriveNo;
  TLR_UINT16 usIdn;
  TLR_UINT16 usUnitLength;
  TLR_UINT16 usPad;
  TLR_STR    szUnit[256];
} __TLR_PACKED_POST ECAT_SOEIDN_SET_IDN_UNIT_REQ_DATA_T;

typedef struct ECAT_SOEIDN_SET_IDN_UNIT_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_SOEIDN_SET_IDN_UNIT_REQ_DATA_T       tData;
} ECAT_SOEIDN_SET_IDN_UNIT_REQ_T;

/* confirmation packet */
typedef __TLR_PACKED_PRE struct ECAT_SOEIDN_SET_IDN_UNIT_CNF_DATA_Ttag
{
  TLR_UINT8  bDriveNo;
  TLR_UINT16 usIdn;
} __TLR_PACKED_POST ECAT_SOEIDN_SET_IDN_UNIT_CNF_DATA_T;

typedef struct ECAT_SOEIDN_SET_IDN_UNIT_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_SOEIDN_SET_IDN_UNIT_CNF_DATA_T       tData;
} ECAT_SOEIDN_SET_IDN_UNIT_CNF_T;

/*******************************************************************************
 * ECAT_SOE_READ_IDN_REQ/
 * ECAT_SOE_READ_IDN_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_SOE_READ_IDN_REQ_DATA_Ttag
{
  TLR_UINT16 usIdn;
  TLR_UINT8  bElement;
  TLR_UINT8  bDriveNo;
  TLR_UINT16 usMaxReadLength;
} __TLR_PACKED_POST ECAT_SOE_READ_IDN_REQ_DATA_T;

typedef struct ECAT_SOE_READ_IDN_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_SOE_READ_IDN_REQ_DATA_T              tData;
} ECAT_SOE_READ_IDN_REQ_T;

/* confirmation packet */
typedef __TLR_PACKED_PRE struct ECAT_SOE_READ_IDN_CNF_DATA_Ttag
{
  /* unfragmentable part */
  TLR_UINT16 usIdn;
  TLR_UINT8  bElement;
  TLR_UINT8  bDriveNo;
  TLR_UINT16 usTotalLength;
  /* fragmentable part */
  TLR_UINT8  abData[1];
} __TLR_PACKED_POST ECAT_SOE_READ_IDN_CNF_DATA_T;

typedef struct ECAT_SOE_READ_IDN_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_SOE_READ_IDN_CNF_DATA_T              tData;
} ECAT_SOE_READ_IDN_CNF_T;

/*******************************************************************************
 * ECAT_SOE_READ_IDN_IND/
 * ECAT_SOE_READ_IDN_RES
 */

/* indication packet */
typedef __TLR_PACKED_PRE struct ECAT_SOE_READ_IDN_IND_DATA_Ttag
{
  TLR_UINT16 usIdn;
  TLR_UINT8  bElement;
  TLR_UINT8  bDriveNo;
  TLR_UINT16 usMaxReadLength;
} __TLR_PACKED_POST ECAT_SOE_READ_IDN_IND_DATA_T;

typedef struct ECAT_SOE_READ_IDN_IND_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_SOE_READ_IDN_IND_DATA_T              tData;
} ECAT_SOE_READ_IDN_IND_T;

/* response packet */
typedef __TLR_PACKED_PRE struct ECAT_SOE_READ_IDN_RES_DATA_Ttag
{
  /* unfragmentable part */
  TLR_UINT16 usIdn;
  TLR_UINT8  bElement;
  TLR_UINT8  bDriveNo;
  TLR_UINT16 usTotalLength;
  /* fragmentable part */
  TLR_UINT8  abData[1];
} __TLR_PACKED_POST ECAT_SOE_READ_IDN_RES_DATA_T;

typedef struct ECAT_SOE_READ_IDN_RES_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_SOE_READ_IDN_RES_DATA_T              tData;
} ECAT_SOE_READ_IDN_RES_T;

/*******************************************************************************
 * ECAT_SOE_WRITE_IDN_REQ/
 * ECAT_SOE_WRITE_IDN_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_SOE_WRITE_IDN_REQ_DATA_Ttag
{
  /* unfragmentable part */
  TLR_UINT16 usIdn;
  TLR_UINT8  bElement;
  TLR_UINT8  bDriveNo;
  TLR_UINT16 usTotalLength;
  /* fragmentable part */
  TLR_UINT8  abData[1];
} __TLR_PACKED_POST ECAT_SOE_WRITE_IDN_REQ_DATA_T;

typedef struct ECAT_SOE_WRITE_IDN_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_SOE_WRITE_IDN_REQ_DATA_T             tData;
} ECAT_SOE_WRITE_IDN_REQ_T;

/* confirmation packet */
typedef __TLR_PACKED_PRE struct ECAT_SOE_WRITE_IDN_CNF_DATA_Ttag
{
  /* unfragmentable part */
  TLR_UINT16 usIdn;
  TLR_UINT8  bElement;
  TLR_UINT8  bDriveNo;
} __TLR_PACKED_POST ECAT_SOE_WRITE_IDN_CNF_DATA_T;

typedef struct ECAT_SOE_WRITE_IDN_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_SOE_WRITE_IDN_CNF_DATA_T             tData;
} ECAT_SOE_WRITE_IDN_CNF_T;

/*******************************************************************************
 * ECAT_SOE_WRITE_IDN_IND/
 * ECAT_SOE_WRITE_IDN_RES
 */

/* indication packet */
typedef __TLR_PACKED_PRE struct ECAT_SOE_WRITE_IDN_IND_DATA_Ttag
{
  /* unfragmentable part */
  TLR_UINT16 usIdn;
  TLR_UINT8  bElement;
  TLR_UINT8  bDriveNo;
  TLR_UINT16 usTotalLength;
  /* fragmentable part */
  TLR_UINT8  abData[1];
} __TLR_PACKED_POST ECAT_SOE_WRITE_IDN_IND_DATA_T;

typedef struct ECAT_SOE_WRITE_IDN_IND_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_SOE_WRITE_IDN_IND_DATA_T             tData;
} ECAT_SOE_WRITE_IDN_IND_T;

/* response packet */
typedef __TLR_PACKED_PRE struct ECAT_SOE_WRITE_IDN_RES_DATA_Ttag
{
  /* unfragmentable part */
  TLR_UINT16 usIdn;
  TLR_UINT8  bElement;
  TLR_UINT8  bDriveNo;
} __TLR_PACKED_POST ECAT_SOE_WRITE_IDN_RES_DATA_T;

typedef struct ECAT_SOE_WRITE_IDN_RES_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_SOE_WRITE_IDN_RES_DATA_T             tData;
} ECAT_SOE_WRITE_IDN_RES_T;

/*******************************************************************************
 * ECAT_SOE_PROCCMD_NOTIFY_REQ/
 * ECAT_SOE_PROCCMD_NOTIFY_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ECAT_SOE_PROCCMD_NOTIFY_REQ_DATA_Ttag
{
  TLR_UINT16 usIdn;
  TLR_UINT8  bDriveNo;
  TLR_UINT16 usDataState;
} __TLR_PACKED_POST ECAT_SOE_PROCCMD_NOTIFY_REQ_DATA_T;

typedef struct ECAT_SOE_PROCCMD_NOTIFY_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_SOE_PROCCMD_NOTIFY_REQ_DATA_T        tData;
} ECAT_SOE_PROCCMD_NOTIFY_REQ_T;

/* confirmation packet */
typedef __TLR_PACKED_PRE struct ECAT_SOE_PROCCMD_NOTIFY_CNF_DATA_Ttag
{
  TLR_UINT16 usIdn;
  TLR_UINT8  bDriveNo;
} __TLR_PACKED_POST ECAT_SOE_PROCCMD_NOTIFY_CNF_DATA_T;

typedef struct ECAT_SOE_PROCCMD_NOTIFY_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_SOE_PROCCMD_NOTIFY_CNF_DATA_T        tData;
} ECAT_SOE_PROCCMD_NOTIFY_CNF_T;

#ifdef __cplusplus
	}
#endif


#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_UNPACK_1(ECS_PUBLIC)
#endif

#endif /* __ECSV4_PUBLIC_H */
