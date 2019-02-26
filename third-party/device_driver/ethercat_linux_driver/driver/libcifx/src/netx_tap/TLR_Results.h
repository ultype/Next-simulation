/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft f�r Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: TLR_Results.h 12375 2010-11-19 13:29:03Z andreasme $

  Description:
    TLR result definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-04-27  NC            File created.

******************************************************************************/


#ifdef DO_NOT_INCLUDE_THIS_HEADER_IN_TLR_AUTOGEN_HEADERS
#ifndef __TLR_FACILITIES_H
#define __TLR_FACILITIES_H


/* /////////////////////////////////////////////////////////////////////////////////// */
/*  type definition */
/* /////////////////////////////////////////////////////////////////////////////////// */



/* /////////////////////////////////////////////////////////////////////////////////// */
/*  bit masks */
/* /////////////////////////////////////////////////////////////////////////////////// */
#define  TLR_STATUS_BIT_TASK_INSTANCE(n)     ((n << 28) & 0x30000000)
#define  TLR_STATUS_BIT_TASK_IDENTIFIER(n)   ((n << 16) & 0x0FFF0000)
#define  TLR_STATUS_BIT_SEVERITY_NAME(n)     ((n << 30) & 0xC0000000)



/*  */
/*   Values are 32 bit values layed out as follows: */
/*  */
/*    3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 */
/*    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 */
/*   +---+---+-----------------------+-------------------------------+ */
/*   |Sev|Ins|    Unique Task ID     |             Status Code       | */
/*   +---+---+-----------------------+-------------------------------+ */
/*  */
/*   where */
/*  */
/*     Sev - is the severity code   */
/*  */
/*           00 - Success */
/*           01 - Informational */
/*           10 - Warning */
/*           11 - Error */
/*  */
/*     Ins - is the Task Instance      */
/*  */
/*                             */
/*  */
/*     Task ID - is the unique Task ID   */
/*  */
/*     Status Code - is the specific status   */
/*  */
/*  */
/*  Define the facility codes */
/*  */
#define TLR_UNQ_NR_VIRTUALSWITCH         0x27
#define TLR_UNQ_NR_USER_AREA             0xFF0
#define TLR_UNQ_NR_USB_TLRROUTER         0x44
#define TLR_UNQ_NR_UDP_DEBUG_CLIENT      0x1B
#define TLR_UNQ_NR_TLR_TIMER             0x2
#define TLR_UNQ_NR_TLR_ROUTER            0x2F
#define TLR_UNQ_NR_TCPIP_TCP_AP          0x94
#define TLR_UNQ_NR_TCPIP_TCP             0x8
#define TLR_UNQ_NR_TCPIP_SOCKIF          0x74
#define TLR_UNQ_NR_TCPIP_IP              0x7
#define TLR_UNQ_NR_TCP_CONNECTOR         0x86
#define TLR_UNQ_NR_SSIO_AP               0x76
#define TLR_UNQ_NR_SSIO                  0x75
#define TLR_UNQ_NR_SNMP_SERVER           0x3B
#define TLR_UNQ_NR_SERVX                 0x92
#define TLR_UNQ_NR_SERCOSIII_SVC         0x33
#define TLR_UNQ_NR_SERCOSIII_SL_SVC      0x4F
#define TLR_UNQ_NR_SERCOSIII_SL_RTD      0x50
#define TLR_UNQ_NR_SERCOSIII_SL_IDN      0x85
#define TLR_UNQ_NR_SERCOSIII_SL_COM      0x4E
#define TLR_UNQ_NR_SERCOSIII_SL_AP       0x51
#define TLR_UNQ_NR_SERCOSIII_MA_SVC      0x71
#define TLR_UNQ_NR_SERCOSIII_MA_NRT      0x79
#define TLR_UNQ_NR_SERCOSIII_MA_CP       0x70
#define TLR_UNQ_NR_SERCOSIII_MA_AP       0x72
#define TLR_UNQ_NR_SERCOSIII_ETH         0x36
#define TLR_UNQ_NR_SERCOSIII_DL          0x35
#define TLR_UNQ_NR_SERCOSIII_CYCLIC      0x37
#define TLR_UNQ_NR_SERCOSIII_API         0x34
#define TLR_UNQ_NR_SERCOS_SL             0x4B
#define TLR_UNQ_NR_RPC                   0x2E
#define TLR_UNQ_NR_PROFIBUS_MPI_RFC      0x73
#define TLR_UNQ_NR_PROFIBUS_MPI_AP       0x68
#define TLR_UNQ_NR_PROFIBUS_MPI          0x67
#define TLR_UNQ_NR_PROFIBUS_FSPMS        0x9
#define TLR_UNQ_NR_PROFIBUS_FSPMM2       0x69
#define TLR_UNQ_NR_PROFIBUS_FSPMM        0x38
#define TLR_UNQ_NR_PROFIBUS_DL           0x6
#define TLR_UNQ_NR_PROFIBUS_APS          0x1D
#define TLR_UNQ_NR_PROFIBUS_APM          0x39
#define TLR_UNQ_NR_PNS_SOCKET_SRV        0x52
#define TLR_UNQ_NR_PNS_SOCKET            0x55
#define TLR_UNQ_NR_PNS_IF_INTERN         0x58
#define TLR_UNQ_NR_PNS_IF                0x30
#define TLR_UNQ_NR_PNS_EDD_LOW           0x54
#define TLR_UNQ_NR_PNS_EDD_HIGH          0x53
#define TLR_UNQ_NR_PNS_DCP               0x56
#define TLR_UNQ_NR_PNS_CLRPC             0x57
#define TLR_UNQ_NR_PNS_4BITIO            0x45
#define TLR_UNQ_NR_PNS_32BITIO           0x5E
#define TLR_UNQ_NR_PNIOD_LENZE_INIT      0x1C
#define TLR_UNQ_NR_PNIOD_LENZE           0x10
#define TLR_UNQ_NR_PNIOD_DPMIF           0x1A
#define TLR_UNQ_NR_PNIOD_16BITIO         0x3A
#define TLR_UNQ_NR_PNIO_MGT              0x13
#define TLR_UNQ_NR_PNIO_IRT_SCHED        0x81
#define TLR_UNQ_NR_PNIO_EDD              0xE
#define TLR_UNQ_NR_PNIO_DCP              0x12
#define TLR_UNQ_NR_PNIO_CMDEV            0xB
#define TLR_UNQ_NR_PNIO_CMCTL            0xA
#define TLR_UNQ_NR_PNIO_APDEV            0xD
#define TLR_UNQ_NR_PNIO_APCTL            0xC
#define TLR_UNQ_NR_PNIO_APCFG            0x14
#define TLR_UNQ_NR_PNIO_ACP              0x11
#define TLR_UNQ_NR_PACKET_ROUTER         0x83
#define TLR_UNQ_NR_OS                    0x1
#define TLR_UNQ_NR_OMB_OMB_AP            0x61
#define TLR_UNQ_NR_OMB_OMB               0x60
#define TLR_UNQ_NR_OD2                   0x28
#define TLR_UNQ_NR_NT100_GATEWAY         0x84
#define TLR_UNQ_NR_NETSCRIPT             0x80
#define TLR_UNQ_MPI_GATEWAY              0x78
#define TLR_UNQ_NR_MODBUS_RTU_AP         0x6F
#define TLR_UNQ_NR_MODBUS_RTU            0x6E
#define TLR_UNQ_NR_MID_SYS               0x2B
#define TLR_UNQ_NR_MID_STARTUP           0x5F
#define TLR_UNQ_NR_MID_DBG               0x31
#define TLR_UNQ_NR_MIB_DATABASE          0x3C
#define TLR_UNQ_NR_MEMORY_MAP            0x77
#define TLR_UNQ_NR_MARSHALLER            0x82
#define TLR_UNQ_NR_LLDP                  0x3E
#define TLR_UNQ_NR_ITEM_SERVER           0x87
#define TLR_UNQ_NR_ISAGRAF_VM            0x8B
#define TLR_UNQ_NR_ISAGRAF_LOG           0x8C
#define TLR_UNQ_NR_ISAGRAF_ISARSI        0x88
#define TLR_UNQ_NR_ISAGRAF_ETCP          0x89
#define TLR_UNQ_NR_ISAGRAF               0x8A
#define TLR_UNQ_NR_IOLINK_MASTER         0x6D
#define TLR_UNQ_NR_IO_SIGNAL             0x91
#define TLR_UNQ_NR_INX                   0x93
#define TLR_UNQ_NR_ICONL_TIMER           0x2A
#define TLR_UNQ_NR_ICONL_RUN             0x29
#define TLR_UNQ_NR_GLOBAL                0x0
#define TLR_UNQ_NR_EXAMPLE_TASK3         0x5
#define TLR_UNQ_NR_EXAMPLE_TASK2         0x4
#define TLR_UNQ_NR_EXAMPLE_TASK1         0x3
#define TLR_UNQ_NR_ETHERNETIP_OBJECT     0x1F
#define TLR_UNQ_NR_ETHERNETIP_ENCAP      0x1E
#define TLR_UNQ_NR_ETH_INTF              0x5D
#define TLR_UNQ_NR_EPL_SDO               0x16
#define TLR_UNQ_NR_EPL_PLD               0x19
#define TLR_UNQ_NR_EPL_PDO               0x15
#define TLR_UNQ_NR_EPL_NMT               0x17
#define TLR_UNQ_NR_EPL_MN                0x3D
#define TLR_UNQ_NR_EPL_ALI               0x18
#define TLR_UNQ_NR_EIP_APS               0x59
#define TLR_UNQ_NR_EIP_APM               0x5A
#define TLR_UNQ_NR_ECS_LENZE             0x6C
#define TLR_UNQ_NR_ECAT_VOE              0x26
#define TLR_UNQ_NR_ECAT_SOE              0x22
#define TLR_UNQ_NR_ECAT_MASTER_AP        0x64
#define TLR_UNQ_NR_ECAT_MASTER           0x65
#define TLR_UNQ_NR_ECAT_FOE              0x24
#define TLR_UNQ_NR_ECAT_ESM              0x4D
#define TLR_UNQ_NR_ECAT_EOE              0x23
#define TLR_UNQ_NR_ECAT_DPM              0x4C
#define TLR_UNQ_NR_ECAT_COE              0x21
#define TLR_UNQ_NR_ECAT_BASE             0x20
#define TLR_UNQ_NR_ECAT_AOE              0x25
#define TLR_UNQ_NR_DRV_EDD               0xF
#define TLR_UNQ_NR_DPM_OD2               0x48
#define TLR_UNQ_NR_DNS_FAL               0x62
#define TLR_UNQ_NR_DNS_AP                0x63
#define TLR_UNQ_NR_DF1_AP                0x8E
#define TLR_UNQ_NR_DF1                   0x8D
#define TLR_UNQ_NR_DEVNET_FAL            0x47
#define TLR_UNQ_NR_DEVNET_APS            0x5C
#define TLR_UNQ_NR_DEVNET_AP             0x5B
#define TLR_UNQ_NR_DDL_ENPDDL            0x40
#define TLR_UNQ_NR_DDL_DDL               0x41
#define TLR_UNQ_NR_COMPONET_SLAVE_AP     0x7D
#define TLR_UNQ_NR_COMPONET_SLAVE        0x7C
#define TLR_UNQ_NR_CCLINK_SLAVE          0x6A
#define TLR_UNQ_NR_CCLINK_APS            0x6B
#define TLR_UNQ_NR_CANOPEN_SLAVE         0x43
#define TLR_UNQ_NR_CANOPEN_MASTER        0x42
#define TLR_UNQ_NR_CANOPEN_APS           0x4A
#define TLR_UNQ_NR_CANOPEN_APM           0x49
#define TLR_UNQ_NR_CANDL_APSAMPLE        0x46
#define TLR_UNQ_NR_CAN_DL                0x3F
#define TLR_UNQ_NR_ASI_MASTER            0x7A
#define TLR_UNQ_NR_ASI_ECTRL             0x32
#define TLR_UNQ_NR_ASI_APM               0x7B
#define TLR_UNQ_NR_ASCII_AP              0x7F
#define TLR_UNQ_NR_ASCII                 0x7E
#define TLR_UNQ_NR_AN_TRANS              0x66
#define TLR_UNQ_NR_3964R_AP              0x90
#define TLR_UNQ_NR_3964R                 0x8F


/*  */
/*  Define the severity codes */
/*  */
#define TLR_STATUS_TYPE_WARNING          0x2
#define TLR_STATUS_TYPE_SUCCESS          0x0
#define TLR_STATUS_TYPE_INFO             0x1
#define TLR_STATUS_TYPE_ERROR            0x3


/*  */
/*  MessageId: TLR_E_COMPILE_THIS_AS_TLR_FACILITIES */
/*  */
/*  MessageText: */
/*  */
/*   TLR Facilities Dummy Code. */
/*  */
#define TLR_E_COMPILE_THIS_AS_TLR_FACILITIES ((TLR_RESULT)0xC000FFFFL)

#endif /*  TLR_FACILITIES_H */
#endif /* DO_NOT_INCLUDE_THIS_HEADER_IN_TLR_AUTOGEN_HEADERS */
#ifndef __ASCII_APP_ERROR_H
#define __ASCII_APP_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  ASCII APP  ERROR codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_ASCII_APP_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_ASCII_APP_COMMAND_INVALID  ((TLR_RESULT)0xC07F0001L)




#endif  /* __ASCII_APP_ERROR_H */

#ifndef __ASCII_STACK_ERROR_H
#define __ASCII_STACK_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  ASCII Stack  ERROR codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_ASCII_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_ASCII_COMMAND_INVALID      ((TLR_RESULT)0xC07E0001L)

/*  */
/*  MessageId: TLR_E_ASCII_STACK_DATA_SIZE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Data size is invalid. */
/*  */
#define TLR_E_ASCII_STACK_DATA_SIZE_INVALID ((TLR_RESULT)0xC07E0002L)

/*  */
/*  MessageId: TLR_E_ASCII_STACK_BUSY */
/*  */
/*  MessageText: */
/*  */
/*   ASCII stack is busy. */
/*  */
#define TLR_E_ASCII_STACK_BUSY           ((TLR_RESULT)0xC07E0003L)

/*  */
/*  MessageId: TLR_E_ASCII_STACK_PACKET_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Packet is too long. */
/*  */
#define TLR_E_ASCII_STACK_PACKET_TOO_LONG ((TLR_RESULT)0xC07E0004L)

/*  */
/*  MessageId: TLR_E_ASCII_STACK_DATA_OVERLAPPED */
/*  */
/*  MessageText: */
/*  */
/*   Previous data is overwritten. */
/*  */
#define TLR_E_ASCII_STACK_DATA_OVERLAPPED ((TLR_RESULT)0xC07E0005L)

/*  */
/*  MessageId: TLR_E_ASCII_STACK_RESPONCE_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Responce timeout expired. */
/*  */
#define TLR_E_ASCII_STACK_RESPONCE_TIMEOUT ((TLR_RESULT)0xC07E0006L)

/*  */
/*  MessageId: TLR_E_ASCII_STACK_WAITING_RESPONCE */
/*  */
/*  MessageText: */
/*  */
/*   ASCII is waiting for responce. */
/*  */
#define TLR_E_ASCII_STACK_WAITING_RESPONCE ((TLR_RESULT)0xC07E0007L)

/*  */
/*  MessageId: TLR_E_ASCII_STACK_LED_NOT_SUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   LED is not supported. */
/*  */
#define TLR_E_ASCII_STACK_LED_NOT_SUPPORTED ((TLR_RESULT)0xC07E0008L)

/*  */
/*  MessageId: TLR_E_ASCII_STACK_MSG_MODE_DISABLED */
/*  */
/*  MessageText: */
/*  */
/*   Message mode is currently disabled. */
/*  */
#define TLR_E_ASCII_STACK_MSG_MODE_DISABLED ((TLR_RESULT)0xC07E0009L)




#endif  /* __ASCII_STACK_ERROR_H */

#ifndef __ASI_ECTRL_ERROR_H
#define __ASI_ECTRL_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  AS-Interface ECTRL-Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_ASI_ECTRL_INVAL_REQ_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Invalid data in request detected. */
/*  */
#define TLR_E_ASI_ECTRL_INVAL_REQ_DATA   ((TLR_RESULT)0xC0320001L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_REQ_RUNNING */
/*  */
/*  MessageText: */
/*  */
/*   The request cannot be executed, because the previous request is still running. */
/*  */
#define TLR_E_ASI_ECTRL_REQ_RUNNING      ((TLR_RESULT)0xC0320002L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_UNKNOWN_REQ */
/*  */
/*  MessageText: */
/*  */
/*   Unknown or unsupported request received. */
/*  */
#define TLR_E_ASI_ECTRL_UNKNOWN_REQ      ((TLR_RESULT)0xC0320003L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_APF_DETECTED */
/*  */
/*  MessageText: */
/*  */
/*   The request cannot be executed, because AS-Interface power failure is detected. */
/*  */
#define TLR_E_ASI_ECTRL_APF_DETECTED     ((TLR_RESULT)0xC0320004L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_NOT_IN_LAS */
/*  */
/*  MessageText: */
/*  */
/*   The requested Slave is not in list of activated Slaves. */
/*  */
#define TLR_E_ASI_ECTRL_NOT_IN_LAS       ((TLR_RESULT)0xC0320005L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_NOT_IN_LDS */
/*  */
/*  MessageText: */
/*  */
/*   The requested Slave is not in list of detected Slaves. */
/*  */
#define TLR_E_ASI_ECTRL_NOT_IN_LDS       ((TLR_RESULT)0xC0320006L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_INVAL_SLV_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   The request cannot be processed for specific type of Slave. */
/*  */
#define TLR_E_ASI_ECTRL_INVAL_SLV_TYPE   ((TLR_RESULT)0xC0320007L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_SET_OFF_PHASE_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   An error occurred during the 'set offline mode' procedure, mode not changed. */
/*  */
#define TLR_E_ASI_ECTRL_SET_OFF_PHASE_FAIL ((TLR_RESULT)0xC0320008L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_SET_OP_MODE_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   An error occurred during the 'set operation mode' procedure, mode not changed. */
/*  */
#define TLR_E_ASI_ECTRL_SET_OP_MODE_FAIL ((TLR_RESULT)0xC0320009L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_SET_OP_MODE_SD0 */
/*  */
/*  MessageText: */
/*  */
/*   The AS-Interface Master could not change to protected mode, because a Slave with zero address is detected. */
/*  */
#define TLR_E_ASI_ECTRL_SET_OP_MODE_SD0  ((TLR_RESULT)0xC032000AL)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_SET_DATA_EXCH_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   An error occurred during the 'set data exchange' procedure, mode not changed. */
/*  */
#define TLR_E_ASI_ECTRL_SET_DATA_EXCH_FAIL ((TLR_RESULT)0xC032000BL)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_SET_AUTO_ADDR_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   An error occurred during the 'set auto address' procedure, mode not changed. */
/*  */
#define TLR_E_ASI_ECTRL_SET_AUTO_ADDR_FAIL ((TLR_RESULT)0xC032000CL)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_WRITE_PARAM_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Parameter value could not be stored or written to Slave. */
/*  */
#define TLR_E_ASI_ECTRL_WRITE_PARAM_FAIL ((TLR_RESULT)0xC032000DL)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_WRITE_ID1_CODE_SND */
/*  */
/*  MessageText: */
/*  */
/*   Extended ID1-Code could not be set, because Slave with zero address is not detected. */
/*  */
#define TLR_E_ASI_ECTRL_WRITE_ID1_CODE_SND ((TLR_RESULT)0xC032000EL)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_WRITE_ID1_CODE_SE */
/*  */
/*  MessageText: */
/*  */
/*   Error with setting Extended ID1-Code. */
/*  */
#define TLR_E_ASI_ECTRL_WRITE_ID1_CODE_SE ((TLR_RESULT)0xC032000FL)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_WRITE_ID1_CODE_ET */
/*  */
/*  MessageText: */
/*  */
/*   Extended ID1-Code stored temporarily. */
/*  */
#define TLR_E_ASI_ECTRL_WRITE_ID1_CODE_ET ((TLR_RESULT)0xC0320010L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_WRITE_ID1_CODE_RE */
/*  */
/*  MessageText: */
/*  */
/*   Error with reading Extended ID1-Code. */
/*  */
#define TLR_E_ASI_ECTRL_WRITE_ID1_CODE_RE ((TLR_RESULT)0xC0320011L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_CHANGE_ADDR_EQUAL_ADDR */
/*  */
/*  MessageText: */
/*  */
/*   Old and new address are identical. */
/*  */
#define TLR_E_ASI_ECTRL_CHANGE_ADDR_EQUAL_ADDR ((TLR_RESULT)0xC0320012L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_CHANGE_ADDR_SND */
/*  */
/*  MessageText: */
/*  */
/*   Slave with old address not detected. */
/*  */
#define TLR_E_ASI_ECTRL_CHANGE_ADDR_SND  ((TLR_RESULT)0xC0320013L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_CHANGE_ADDR_SD0 */
/*  */
/*  MessageText: */
/*  */
/*   Slave with zero address not detected. */
/*  */
#define TLR_E_ASI_ECTRL_CHANGE_ADDR_SD0  ((TLR_RESULT)0xC0320014L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_CHANGE_ADD_SD2 */
/*  */
/*  MessageText: */
/*  */
/*   Slave with new address detected. */
/*  */
#define TLR_E_ASI_ECTRL_CHANGE_ADD_SD2   ((TLR_RESULT)0xC0320015L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_CHANGE_ADDR_DE */
/*  */
/*  MessageText: */
/*  */
/*   Error with deletion of old address. */
/*  */
#define TLR_E_ASI_ECTRL_CHANGE_ADDR_DE   ((TLR_RESULT)0xC0320016L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_CHANGE_ADDR_RE */
/*  */
/*  MessageText: */
/*  */
/*   Error with reading the Extended ID1-Code of Slave with old address. */
/*  */
#define TLR_E_ASI_ECTRL_CHANGE_ADDR_RE   ((TLR_RESULT)0xC0320017L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_CHANGE_ADDR_SE */
/*  */
/*  MessageText: */
/*  */
/*   Error with setting of new address. */
/*  */
#define TLR_E_ASI_ECTRL_CHANGE_ADDR_SE   ((TLR_RESULT)0xC0320018L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_CHANGE_ADDR_AT */
/*  */
/*  MessageText: */
/*  */
/*   New address stored temporarily. */
/*  */
#define TLR_E_ASI_ECTRL_CHANGE_ADDR_AT   ((TLR_RESULT)0xC0320019L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_EXECUTE_CMD_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Execution of single command failed. */
/*  */
#define TLR_E_ASI_ECTRL_EXECUTE_CMD_FAIL ((TLR_RESULT)0xC032001AL)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_GET_STATE_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get ECTRL-Task state. */
/*  */
#define TLR_E_ASI_ECTRL_GET_STATE_FAIL   ((TLR_RESULT)0xC032001BL)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_GET_ACT_CONFIG_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get actual configuration of AS-Interface network. */
/*  */
#define TLR_E_ASI_ECTRL_GET_ACT_CONFIG_FAIL ((TLR_RESULT)0xC032001CL)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_GET_PERM_CONFIG_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get permanent configuration of AS-Interface network. */
/*  */
#define TLR_E_ASI_ECTRL_GET_PERM_CONFIG_FAIL ((TLR_RESULT)0xC032001DL)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_STORE_ACT_PARAM_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Actual parameter of AS-Interface network could not be stored. */
/*  */
#define TLR_E_ASI_ECTRL_STORE_ACT_PARAM_FAIL ((TLR_RESULT)0xC032001EL)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_SET_PERM_CONFIG_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Set permanent configuration of AS-Interface network failed. */
/*  */
#define TLR_E_ASI_ECTRL_SET_PERM_CONFIG_FAIL ((TLR_RESULT)0xC032001FL)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_SET_PERM_CONFIG_ALREADY_IN_LPS */
/*  */
/*  MessageText: */
/*  */
/*   Slave not added to permanent configuration of AS-Interface network, because Slave is already projected. */
/*  */
#define TLR_E_ASI_ECTRL_SET_PERM_CONFIG_ALREADY_IN_LPS ((TLR_RESULT)0xC0320020L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_SET_PERM_CONFIG_NOT_IN_LPS */
/*  */
/*  MessageText: */
/*  */
/*   Slave is not changed or deleted from permanent configuration of AS-Interface network, because Slave is not projected. */
/*  */
#define TLR_E_ASI_ECTRL_SET_PERM_CONFIG_NOT_IN_LPS ((TLR_RESULT)0xC0320021L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_STORE_ACT_CONFIG_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Actual configuration of AS-Interface network could not be stored. */
/*  */
#define TLR_E_ASI_ECTRL_STORE_ACT_CONFIG_FAIL ((TLR_RESULT)0xC0320022L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_READ_ID_STR_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Identification string could not be read from requested Slave. */
/*  */
#define TLR_E_ASI_ECTRL_READ_ID_STR_FAIL ((TLR_RESULT)0xC0320023L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_READ_PARAM_STR_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Parameter string could not be read from requested Slave. */
/*  */
#define TLR_E_ASI_ECTRL_READ_PARAM_STR_FAIL ((TLR_RESULT)0xC0320024L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_READ_DIAG_STR_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Diagnostic string could not be read from requested Slave. */
/*  */
#define TLR_E_ASI_ECTRL_READ_DIAG_STR_FAIL ((TLR_RESULT)0xC0320025L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_WRITE_PARAM_STR_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Parameter string could not be written to requested Slave. */
/*  */
#define TLR_E_ASI_ECTRL_WRITE_PARAM_STR_FAIL ((TLR_RESULT)0xC0320026L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_READ_IN_DATA_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Read input data failed. */
/*  */
#define TLR_E_ASI_ECTRL_READ_IN_DATA_FAIL ((TLR_RESULT)0xC0320027L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_WRITE_OUT_DATA_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Write output data failed. */
/*  */
#define TLR_E_ASI_ECTRL_WRITE_OUT_DATA_FAIL ((TLR_RESULT)0xC0320028L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_READ_ANLG_IN_DATA_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Read analog input data failed. */
/*  */
#define TLR_E_ASI_ECTRL_READ_ANLG_IN_DATA_FAIL ((TLR_RESULT)0xC0320029L)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_WRITE_ANLG_OUT_DATA_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Write analog output data failed. */
/*  */
#define TLR_E_ASI_ECTRL_WRITE_ANLG_OUT_DATA_FAIL ((TLR_RESULT)0xC032002AL)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_SET_PERM_PARAM_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Set permanent parameter of AS-Interface network failed. */
/*  */
#define TLR_E_ASI_ECTRL_SET_PERM_PARAM_FAIL ((TLR_RESULT)0xC032002BL)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_INVAL_LEN */
/*  */
/*  MessageText: */
/*  */
/*   Invalid length in packet received. */
/*  */
#define TLR_E_ASI_ECTRL_INVAL_LEN        ((TLR_RESULT)0xC032002CL)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_WRITE_ID1_CODE_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Write Extended ID1-Code failed. */
/*  */
#define TLR_E_ASI_ECTRL_WRITE_ID1_CODE_FAIL ((TLR_RESULT)0xC032002DL)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_CHANGE_ADDR_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Change slave address failed. */
/*  */
#define TLR_E_ASI_ECTRL_CHANGE_ADDR_FAIL ((TLR_RESULT)0xC032002EL)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_NOT_IN_NORMAL_OP */
/*  */
/*  MessageText: */
/*  */
/*   The request cannot be executed, because the AS-Interface Master is not in normal operation. */
/*  */
#define TLR_E_ASI_ECTRL_NOT_IN_NORMAL_OP ((TLR_RESULT)0xC032002FL)

/*  */
/*  MessageId: TLR_E_ASI_ECTRL_NOT_ALLOWED_IN_PROTECTED_MODE */
/*  */
/*  MessageText: */
/*  */
/*   The request is not allowed in protected mode. */
/*  */
#define TLR_E_ASI_ECTRL_NOT_ALLOWED_IN_PROTECTED_MODE ((TLR_RESULT)0xC0320030L)




#endif  /* __ASI_ECTRL_ERROR_H */

#ifndef __ASI_APM_ERROR_H
#define __ASI_APM_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  AS-Interface Master Application Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_ASI_APM_PARAM_CYCLETIME */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for parameter cycletime. */
/*  */
#define TLR_E_ASI_APM_PARAM_CYCLETIME    ((TLR_RESULT)0xC07B0001L)

/*  */
/*  MessageId: TLR_E_ASI_APM_PARAM_CHN_INSTANCE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for parameter channel instance. */
/*  */
#define TLR_E_ASI_APM_PARAM_CHN_INSTANCE ((TLR_RESULT)0xC07B0002L)

/*  */
/*  MessageId: TLR_E_ASI_APM_PARAM_QUEUE_ELEMENT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for parameter queue element. */
/*  */
#define TLR_E_ASI_APM_PARAM_QUEUE_ELEMENT ((TLR_RESULT)0xC07B0003L)

/*  */
/*  MessageId: TLR_E_ASI_APM_PARAM_POOL_ELEMENT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for parameter pool element. */
/*  */
#define TLR_E_ASI_APM_PARAM_POOL_ELEMENT ((TLR_RESULT)0xC07B0004L)

/*  */
/*  MessageId: TLR_E_ASI_APM_PARAM_AUTO_CLEAR */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for parameter auto-clear. */
/*  */
#define TLR_E_ASI_APM_PARAM_AUTO_CLEAR   ((TLR_RESULT)0xC07B0005L)

/*  */
/*  MessageId: TLR_E_ASI_APM_SLAVE_ALREADY_CONFIGURED */
/*  */
/*  MessageText: */
/*  */
/*   Slave is already configured. */
/*  */
#define TLR_E_ASI_APM_SLAVE_ALREADY_CONFIGURED ((TLR_RESULT)0xC07B0006L)

/*  */
/*  MessageId: TLR_E_ASI_APM_INVALID_DBM_VERSION */
/*  */
/*  MessageText: */
/*  */
/*   Invalid version of database. */
/*  */
#define TLR_E_ASI_APM_INVALID_DBM_VERSION ((TLR_RESULT)0xC07B0007L)

/*  */
/*  MessageId: TLR_E_ASI_APM_STORE_CONFIGURATION_NOT_POSSIBLE */
/*  */
/*  MessageText: */
/*  */
/*   Permanent storage of configuration is not possible. */
/*  */
#define TLR_E_ASI_APM_STORE_CONFIGURATION_NOT_POSSIBLE ((TLR_RESULT)0xC07B0008L)

/*  */
/*  MessageId: TLR_E_ASI_APM_INVALID_SLAVE_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid slave parameter. */
/*  */
#define TLR_E_ASI_APM_INVALID_SLAVE_PARAMETER ((TLR_RESULT)0xC07B0009L)

/*  */
/*  MessageId: TLR_E_ASI_APM_ACTIVATE_WATCHDOG */
/*  */
/*  MessageText: */
/*  */
/*   Failed to activate watchdog supervision. */
/*  */
#define TLR_E_ASI_APM_ACTIVATE_WATCHDOG  ((TLR_RESULT)0xC07B000AL)

/*  */
/*  MessageId: TLR_E_ASI_APM_NOT_ALLOWED_IN_PROTECTED_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Request is not allowed in protected mode. */
/*  */
#define TLR_E_ASI_APM_NOT_ALLOWED_IN_PROTECTED_MODE ((TLR_RESULT)0xC07B000BL)

/*  */
/*  MessageId: TLR_E_ASI_APM_IO_STATUS_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for IO status offset. */
/*  */
#define TLR_E_ASI_APM_IO_STATUS_OFFSET   ((TLR_RESULT)0xC07B000CL)




#endif  /* __ASI_APM_ERROR_H */

#ifndef __ASI_MASTER_ERROR_H
#define __ASI_MASTER_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  AS-Interface Master */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_ASI_MASTER_PARAM_CYCLETIME */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for parameter cycletime. */
/*  */
#define TLR_E_ASI_MASTER_PARAM_CYCLETIME ((TLR_RESULT)0xC07A0001L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_PARAM_XC_INSTANCE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for parameter xC instance. */
/*  */
#define TLR_E_ASI_MASTER_PARAM_XC_INSTANCE ((TLR_RESULT)0xC07A0002L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_PARAM_QUEUE_ELEMENT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for parameter queue element. */
/*  */
#define TLR_E_ASI_MASTER_PARAM_QUEUE_ELEMENT ((TLR_RESULT)0xC07A0003L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_PARAM_POOL_ELEMENT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for parameter pool element. */
/*  */
#define TLR_E_ASI_MASTER_PARAM_POOL_ELEMENT ((TLR_RESULT)0xC07A0004L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_PARAM_MIN_CYCLE_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for parameter min cycle timer. */
/*  */
#define TLR_E_ASI_MASTER_PARAM_MIN_CYCLE_TIME ((TLR_RESULT)0xC07A0005L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_PARAM_OPERATION_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for parameter operation mode. */
/*  */
#define TLR_E_ASI_MASTER_PARAM_OPERATION_MODE ((TLR_RESULT)0xC07A0006L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_PARAM_DATA_EXCHANGE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for parameter data exchange. */
/*  */
#define TLR_E_ASI_MASTER_PARAM_DATA_EXCHANGE ((TLR_RESULT)0xC07A0007L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_PARAM_AUTO_ADDRESS_ENABLE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for parameter auto address enable. */
/*  */
#define TLR_E_ASI_MASTER_PARAM_AUTO_ADDRESS_ENABLE ((TLR_RESULT)0xC07A0008L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_PARAM_MANAGEMENT_PHASE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for parameter management phase. */
/*  */
#define TLR_E_ASI_MASTER_PARAM_MANAGEMENT_PHASE ((TLR_RESULT)0xC07A0009L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_PARAM_PROCESS_DATA_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for parameter process data mode. */
/*  */
#define TLR_E_ASI_MASTER_PARAM_PROCESS_DATA_MODE ((TLR_RESULT)0xC07A000AL)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_PARAM_DATA_FORMAT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for parameter process data format. */
/*  */
#define TLR_E_ASI_MASTER_PARAM_DATA_FORMAT ((TLR_RESULT)0xC07A000BL)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_INIT_BUFFER */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize data buffer. */
/*  */
#define TLR_E_ASI_MASTER_INIT_BUFFER     ((TLR_RESULT)0xC07A000CL)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_INITIALIZING */
/*  */
/*  MessageText: */
/*  */
/*   Master is initializing. */
/*  */
#define TLR_E_ASI_MASTER_INITIALIZING    ((TLR_RESULT)0xC07A000DL)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_DATA_COUNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid data count. */
/*  */
#define TLR_E_ASI_MASTER_DATA_COUNT      ((TLR_RESULT)0xC07A000EL)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_DATA_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Invalid data offset. */
/*  */
#define TLR_E_ASI_MASTER_DATA_OFFSET     ((TLR_RESULT)0xC07A000FL)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_NOT_ALLOWED_IN_PROTECTED_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Request is not allowed in protected mode. */
/*  */
#define TLR_E_ASI_MASTER_NOT_ALLOWED_IN_PROTECTED_MODE ((TLR_RESULT)0xC07A0010L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_AUTO_CLEAR */
/*  */
/*  MessageText: */
/*  */
/*   Master is in auto-clear state. */
/*  */
#define TLR_E_ASI_MASTER_AUTO_CLEAR      ((TLR_RESULT)0xC07A0011L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_CONTROL_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Control error detected. */
/*  */
#define TLR_E_ASI_MASTER_CONTROL_ERROR   ((TLR_RESULT)0xC07A0012L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_SLAVE_MISSING */
/*  */
/*  MessageText: */
/*  */
/*   Slave is missing. */
/*  */
#define TLR_E_ASI_MASTER_SLAVE_MISSING   ((TLR_RESULT)0xC07A0013L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_POWER_FAILURE */
/*  */
/*  MessageText: */
/*  */
/*   Power failure detected. */
/*  */
#define TLR_E_ASI_MASTER_POWER_FAILURE   ((TLR_RESULT)0xC07A0014L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_OFFLINE_READY */
/*  */
/*  MessageText: */
/*  */
/*   Master is in offline ready state. */
/*  */
#define TLR_E_ASI_MASTER_OFFLINE_READY   ((TLR_RESULT)0xC07A0015L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_NOT_IN_NORMAL_OPERATION */
/*  */
/*  MessageText: */
/*  */
/*   Master is not in normal operation. */
/*  */
#define TLR_E_ASI_MASTER_NOT_IN_NORMAL_OPERATION ((TLR_RESULT)0xC07A0016L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_INVALID_SLAVE_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid slave address. */
/*  */
#define TLR_E_ASI_MASTER_INVALID_SLAVE_ADDRESS ((TLR_RESULT)0xC07A0017L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_SLAVE_ACTIVATED */
/*  */
/*  MessageText: */
/*  */
/*   Slave is activated. */
/*  */
#define TLR_E_ASI_MASTER_SLAVE_ACTIVATED ((TLR_RESULT)0xC07A0018L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_SLAVE_NOT_ACTIVATED */
/*  */
/*  MessageText: */
/*  */
/*   Slave is not activated. */
/*  */
#define TLR_E_ASI_MASTER_SLAVE_NOT_ACTIVATED ((TLR_RESULT)0xC07A0019L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_SLAVE_DETECTED */
/*  */
/*  MessageText: */
/*  */
/*   Slave is detected. */
/*  */
#define TLR_E_ASI_MASTER_SLAVE_DETECTED  ((TLR_RESULT)0xC07A001AL)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_SLAVE_NOT_DETECTED */
/*  */
/*  MessageText: */
/*  */
/*   Slave is not detected. */
/*  */
#define TLR_E_ASI_MASTER_SLAVE_NOT_DETECTED ((TLR_RESULT)0xC07A001BL)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Timeout detected. */
/*  */
#define TLR_E_ASI_MASTER_TIMEOUT         ((TLR_RESULT)0xC07A001CL)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_SLAVE_0_DETECTED */
/*  */
/*  MessageText: */
/*  */
/*   Slave at address 0 detected. */
/*  */
#define TLR_E_ASI_MASTER_SLAVE_0_DETECTED ((TLR_RESULT)0xC07A001DL)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_NEW_SLAVE_DETECTED */
/*  */
/*  MessageText: */
/*  */
/*   Slave at new address detected. */
/*  */
#define TLR_E_ASI_MASTER_NEW_SLAVE_DETECTED ((TLR_RESULT)0xC07A001EL)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_DELETE_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   Error with deletion of address. */
/*  */
#define TLR_E_ASI_MASTER_DELETE_ADDRESS  ((TLR_RESULT)0xC07A001FL)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_READ_EXT_ID1 */
/*  */
/*  MessageText: */
/*  */
/*   Error with reading extended ID code 1. */
/*  */
#define TLR_E_ASI_MASTER_READ_EXT_ID1    ((TLR_RESULT)0xC07A0020L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_SET_EXT_ID1 */
/*  */
/*  MessageText: */
/*  */
/*   Error with setting extended ID code 1. */
/*  */
#define TLR_E_ASI_MASTER_SET_EXT_ID1     ((TLR_RESULT)0xC07A0021L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_ADDRESS_SET_TEMPORARY */
/*  */
/*  MessageText: */
/*  */
/*   New address stored temporarily. */
/*  */
#define TLR_E_ASI_MASTER_ADDRESS_SET_TEMPORARY ((TLR_RESULT)0xC07A0022L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_SET_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   Error with setting new address. */
/*  */
#define TLR_E_ASI_MASTER_SET_ADDRESS     ((TLR_RESULT)0xC07A0023L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_EXT_ID1_SET_TEMPORARY */
/*  */
/*  MessageText: */
/*  */
/*   Extended ID code 1 stored temporarily. */
/*  */
#define TLR_E_ASI_MASTER_EXT_ID1_SET_TEMPORARY ((TLR_RESULT)0xC07A0024L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_INVALID_SLAVE_PROFILE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid slave profile. */
/*  */
#define TLR_E_ASI_MASTER_INVALID_SLAVE_PROFILE ((TLR_RESULT)0xC07A0025L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_SLAVE_CONFIG */
/*  */
/*  MessageText: */
/*  */
/*   Invalid slave configuration. */
/*  */
#define TLR_E_ASI_MASTER_SLAVE_CONFIG    ((TLR_RESULT)0xC07A0026L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_SLAVE_ALREADY_CONFIGURED */
/*  */
/*  MessageText: */
/*  */
/*   Slave is alrady configured. */
/*  */
#define TLR_E_ASI_MASTER_SLAVE_ALREADY_CONFIGURED ((TLR_RESULT)0xC07A0027L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_STRING_TRANSFER_DATA_OVERFLOW */
/*  */
/*  MessageText: */
/*  */
/*   Data overflow during stringtansfer detected. */
/*  */
#define TLR_E_ASI_MASTER_STRING_TRANSFER_DATA_OVERFLOW ((TLR_RESULT)0xC07A0028L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_PARAM_AUTOCLEAR_WITH_AUTOADRESS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for parameter autoclear in combiantion with value for parameter autoaddress. */
/*  */
#define TLR_E_ASI_MASTER_PARAM_AUTOCLEAR_WITH_AUTOADRESS ((TLR_RESULT)0xC07A0029L)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_PARAM_AUTOCLEAR_WITH_CONFIG_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for parameter autoclear in combiantion with value for parameter operationmode. */
/*  */
#define TLR_E_ASI_MASTER_PARAM_AUTOCLEAR_WITH_CONFIG_MODE ((TLR_RESULT)0xC07A002AL)

/*  */
/*  MessageId: TLR_E_ASI_MASTER_COMMAND_NOT_ALLOWD_WITH_AUTOCLEAR */
/*  */
/*  MessageText: */
/*  */
/*   Commad is not allowed if autoclear is active. */
/*  */
#define TLR_E_ASI_MASTER_COMMAND_NOT_ALLOWD_WITH_AUTOCLEAR ((TLR_RESULT)0xC07A002BL)




#endif  /* __ASI_MASTER_ERROR_H */

#ifndef __CAN_DL_ERROR_H
#define __CAN_DL_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CAN DL Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_CAN_DL_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_CAN_DL_COMMAND_INVALID     ((TLR_RESULT)0xC03F0001L)

/*  */
/*  MessageId: TLR_E_CAN_DL_CMD_LENGTH_MISMATCH */
/*  */
/*  MessageText: */
/*  */
/*   The length code of the command is invalid. */
/*  */
#define TLR_E_CAN_DL_CMD_LENGTH_MISMATCH ((TLR_RESULT)0xC03F0002L)

/*  */
/*  MessageId: TLR_E_CAN_DL_UNKNOWN_PARAMETER_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   The parameter type of the command "Set Paramter" is invalid. */
/*  */
#define TLR_E_CAN_DL_UNKNOWN_PARAMETER_TYPE ((TLR_RESULT)0xC03F0003L)

/*  */
/*  MessageId: TLR_E_CAN_DL_SET_MODE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Within the command "Set Parameter" the function set "CAN Mode" failed. */
/*  */
#define TLR_E_CAN_DL_SET_MODE_FAILED     ((TLR_RESULT)0xC03F0004L)

/*  */
/*  MessageId: TLR_E_CAN_DL_SET_BAUDRATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Within the command "Set Parameter" the function set "Baudrate" failed. */
/*  */
#define TLR_E_CAN_DL_SET_BAUDRATE_FAILED ((TLR_RESULT)0xC03F0005L)

/*  */
/*  MessageId: TLR_E_CAN_DL_SET_TXABORT_TIME_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Within the command "Set Parameter" the function set "Transmission Abort Timer" failed. */
/*  */
#define TLR_E_CAN_DL_SET_TXABORT_TIME_FAILED ((TLR_RESULT)0xC03F0006L)

/*  */
/*  MessageId: TLR_E_CAN_DL_SET_EVENTS_REQUESTED_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Within the command "Set Parameter" the function set "Requetsed Events" failed. */
/*  */
#define TLR_E_CAN_DL_SET_EVENTS_REQUESTED_FAILED ((TLR_RESULT)0xC03F0007L)

/*  */
/*  MessageId: TLR_E_CAN_DL_SET_FILTER_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Within the command "Set Parameter" or "Set Filter the function set "CAN Filter" failed. */
/*  */
#define TLR_E_CAN_DL_SET_FILTER_FAILED   ((TLR_RESULT)0xC03F0008L)

/*  */
/*  MessageId: TLR_E_CAN_DL_SET_ENABLE_DISABLE_RXID_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Within the command Enable or Diasble of receive identifiers an error occurred. */
/*  */
#define TLR_E_CAN_DL_SET_ENABLE_DISABLE_RXID_FAILED ((TLR_RESULT)0xC03F0009L)

/*  */
/*  MessageId: TLR_E_CAN_DL_TX_FRAME_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   At least one CAN frame could not be send. Normaly because the send process was aborted by the transmission abort timer. */
/*  */
#define TLR_E_CAN_DL_TX_FRAME_FAILED     ((TLR_RESULT)0xC03F000AL)

/*  */
/*  MessageId: TLR_E_CAN_DL_TX_BUFFER_OVERRUN */
/*  */
/*  MessageText: */
/*  */
/*   The send request of CAN frames was rejected because the internal buffer for send requests is full. */
/*  */
#define TLR_E_CAN_DL_TX_BUFFER_OVERRUN   ((TLR_RESULT)0xC03F000BL)

/*  */
/*  MessageId: TLR_E_CAN_DL_UNKNOWN_DIAG_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   The diagnostic type of the command "Get Diag" is invalid. */
/*  */
#define TLR_E_CAN_DL_UNKNOWN_DIAG_TYPE   ((TLR_RESULT)0xC03F000CL)

/*  */
/*  MessageId: TRL_E_CAN_DL_TX_ABORT_ALREADY_IN_REQUEST */
/*  */
/*  MessageText: */
/*  */
/*   The command "Transmission Abort" is already requested. */
/*  */
#define TRL_E_CAN_DL_TX_ABORT_ALREADY_IN_REQUEST ((TLR_RESULT)0xC03F000DL)

/*  */
/*  MessageId: TRL_E_CAN_DL_TX_ABORT */
/*  */
/*  MessageText: */
/*  */
/*   The send process of can frames was aborted  by "Transmission Abort" command. */
/*  */
#define TRL_E_CAN_DL_TX_ABORT            ((TLR_RESULT)0xC03F000EL)




#endif  /* __CAN_DL_ERROR_H */

#ifndef __CANOPEN_APM_ERROR_H
#define __CANOPEN_APM_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CANopen Master Application Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_CANOPEN_APM_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_CANOPEN_APM_COMMAND_INVALID ((TLR_RESULT)0xC0490001L)

/*  */
/*  MessageId: TLR_I_CANOPEN_APM_CONFIG_LOCK */
/*  */
/*  MessageText: */
/*  */
/*   Configuration is locked. */
/*  */
#define TLR_I_CANOPEN_APM_CONFIG_LOCK    ((TLR_RESULT)0x40490002L)

/*  */
/*  MessageId: TLR_E_CANOPEN_APM_PACKET_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Invalid packet length. */
/*  */
#define TLR_E_CANOPEN_APM_PACKET_LENGTH  ((TLR_RESULT)0xC0490003L)

/*  */
/*  MessageId: TLR_E_CANOPEN_APM_WATCHDOG_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for watchdog. */
/*  */
#define TLR_E_CANOPEN_APM_WATCHDOG_PARAMETER ((TLR_RESULT)0xC0490004L)

/*  */
/*  MessageId: TLR_I_CANOPEN_APM_OPEN_DBM_FILE */
/*  */
/*  MessageText: */
/*  */
/*   Database file not found. */
/*  */
#define TLR_I_CANOPEN_APM_OPEN_DBM_FILE  ((TLR_RESULT)0x40490005L)

/*  */
/*  MessageId: TLR_E_CANOPEN_APM_DATASET */
/*  */
/*  MessageText: */
/*  */
/*   Failed to open configuration dataset. */
/*  */
#define TLR_E_CANOPEN_APM_DATASET        ((TLR_RESULT)0xC0490006L)

/*  */
/*  MessageId: TLR_E_CANOPEN_APM_TABLE_GLOBAL */
/*  */
/*  MessageText: */
/*  */
/*   Failed to open GLOBAL configuration dataset. */
/*  */
#define TLR_E_CANOPEN_APM_TABLE_GLOBAL   ((TLR_RESULT)0xC0490007L)

/*  */
/*  MessageId: TLR_E_CANOPEN_APM_TABLE_BUS_CAN */
/*  */
/*  MessageText: */
/*  */
/*   Failed to open BUS_CAN configuration dataset. */
/*  */
#define TLR_E_CANOPEN_APM_TABLE_BUS_CAN  ((TLR_RESULT)0xC0490008L)

/*  */
/*  MessageId: TLR_E_CANOPEN_APM_TABLE_BUS_CAN_EXT */
/*  */
/*  MessageText: */
/*  */
/*   Failed to open BUS_CAN_EXT configuration dataset. */
/*  */
#define TLR_E_CANOPEN_APM_TABLE_BUS_CAN_EXT ((TLR_RESULT)0xC0490009L)

/*  */
/*  MessageId: TLR_E_CANOPEN_APM_TABLE_NODES */
/*  */
/*  MessageText: */
/*  */
/*   Failed to open NODES configuration dataset. */
/*  */
#define TLR_E_CANOPEN_APM_TABLE_NODES    ((TLR_RESULT)0xC049000AL)

/*  */
/*  MessageId: TLR_E_CANOPEN_APM_WATCHDOG_ACTIVATE */
/*  */
/*  MessageText: */
/*  */
/*   Failed to activate watchdog supervision. */
/*  */
#define TLR_E_CANOPEN_APM_WATCHDOG_ACTIVATE ((TLR_RESULT)0xC049000BL)

/*  */
/*  MessageId: TLR_E_CANOPEN_APM_SIZE_TABLE_BUS_CAN */
/*  */
/*  MessageText: */
/*  */
/*   Invalid size of BUS_CAN configuration dataset. */
/*  */
#define TLR_E_CANOPEN_APM_SIZE_TABLE_BUS_CAN ((TLR_RESULT)0xC049000CL)

/*  */
/*  MessageId: TLR_E_CANOPEN_APM_SIZE_TABLE_BUS_CAN_EXT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid size of BUS_CAN_EXT configuration dataset. */
/*  */
#define TLR_E_CANOPEN_APM_SIZE_TABLE_BUS_CAN_EXT ((TLR_RESULT)0xC049000DL)

/*  */
/*  MessageId: TLR_E_CANOPEN_APM_NODE_ALREADY_CONFIGURED */
/*  */
/*  MessageText: */
/*  */
/*   Node already configured. */
/*  */
#define TLR_E_CANOPEN_APM_NODE_ALREADY_CONFIGURED ((TLR_RESULT)0xC049000EL)

/*  */
/*  MessageId: TLR_E_CANOPEN_APM_INVALID_NODE_ID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Node ID. */
/*  */
#define TLR_E_CANOPEN_APM_INVALID_NODE_ID ((TLR_RESULT)0xC049000FL)

/*  */
/*  MessageId: TLR_E_CANOPEN_APM_DATABASE_FOUND */
/*  */
/*  MessageText: */
/*  */
/*   Configuration database found. */
/*  */
#define TLR_E_CANOPEN_APM_DATABASE_FOUND ((TLR_RESULT)0xC0490010L)

/*  */
/*  MessageId: TLR_E_CANOPEN_APM_REQUEST_RUNNING */
/*  */
/*  MessageText: */
/*  */
/*   Request already running. */
/*  */
#define TLR_E_CANOPEN_APM_REQUEST_RUNNING ((TLR_RESULT)0xC0490011L)




#endif  /* __CANOPEN_APM_ERROR_H */

#ifndef __CANOPEN_APS_ERROR_H
#define __CANOPEN_APS_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CANopen Slave Application  Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_CANOPEN_APS_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_CANOPEN_APS_COMMAND_INVALID ((TLR_RESULT)0xC04A0001L)

/*  */
/*  MessageId: TLR_E_CANOPEN_APS_DATABASE_FOUND */
/*  */
/*  MessageText: */
/*  */
/*   Configuration database found. */
/*  */
#define TLR_E_CANOPEN_APS_DATABASE_FOUND ((TLR_RESULT)0xC04A0002L)

/*  */
/*  MessageId: TLR_E_CANOPEN_APS_NODE_ID_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for node id. */
/*  */
#define TLR_E_CANOPEN_APS_NODE_ID_PARAMETER ((TLR_RESULT)0xC04A0003L)

/*  */
/*  MessageId: TLR_E_CANOPEN_APS_BAUDRATE_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for baudrate. */
/*  */
#define TLR_E_CANOPEN_APS_BAUDRATE_PARAMETER ((TLR_RESULT)0xC04A0004L)

/*  */
/*  MessageId: TLR_E_CANOPEN_APS_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Request not possible in current state. */
/*  */
#define TLR_E_CANOPEN_APS_STATE          ((TLR_RESULT)0xC04A0005L)

/*  */
/*  MessageId: TLR_E_CANOPEN_APS_REQUEST_RUNNING */
/*  */
/*  MessageText: */
/*  */
/*   Request already running. */
/*  */
#define TLR_E_CANOPEN_APS_REQUEST_RUNNING ((TLR_RESULT)0xC04A0006L)

/*  */
/*  MessageId: TLR_I_CANOPEN_APS_OPEN_DBM_FILE */
/*  */
/*  MessageText: */
/*  */
/*   Failed to open configuration database. */
/*  */
#define TLR_I_CANOPEN_APS_OPEN_DBM_FILE  ((TLR_RESULT)0x404A0007L)

/*  */
/*  MessageId: TLR_E_CANOPEN_APS_DATASET */
/*  */
/*  MessageText: */
/*  */
/*   Failed to open configuration dataset. */
/*  */
#define TLR_E_CANOPEN_APS_DATASET        ((TLR_RESULT)0xC04A0008L)

/*  */
/*  MessageId: TLR_E_CANOPEN_APS_TABLE_GLOBAL */
/*  */
/*  MessageText: */
/*  */
/*   Failed to open GLOBAL configuration dataset. */
/*  */
#define TLR_E_CANOPEN_APS_TABLE_GLOBAL   ((TLR_RESULT)0xC04A0009L)

/*  */
/*  MessageId: TLR_E_CANOPEN_APS_TABLE_BUS_CAN */
/*  */
/*  MessageText: */
/*  */
/*   Failed to open BUS_CAN configuration dataset. */
/*  */
#define TLR_E_CANOPEN_APS_TABLE_BUS_CAN  ((TLR_RESULT)0xC04A000AL)

/*  */
/*  MessageId: TLR_E_CANOPEN_APS_SIZE_TABLE_BUS_CAN */
/*  */
/*  MessageText: */
/*  */
/*   Invalid size of BUS_CAN configuration dataset. */
/*  */
#define TLR_E_CANOPEN_APS_SIZE_TABLE_BUS_CAN ((TLR_RESULT)0xC04A000BL)

/*  */
/*  MessageId: TLR_I_CANOPEN_APS_CONFIG_LOCK */
/*  */
/*  MessageText: */
/*  */
/*   Configuration is locked. */
/*  */
#define TLR_I_CANOPEN_APS_CONFIG_LOCK    ((TLR_RESULT)0x404A000CL)

/*  */
/*  MessageId: TLR_E_CANOPEN_APS_PACKET_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Invalid packet length. */
/*  */
#define TLR_E_CANOPEN_APS_PACKET_LENGTH  ((TLR_RESULT)0xC04A000DL)

/*  */
/*  MessageId: TLR_E_CANOPEN_APS_WATCHDOG_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for watchdog supervision. */
/*  */
#define TLR_E_CANOPEN_APS_WATCHDOG_PARAMETER ((TLR_RESULT)0xC04A000EL)

/*  */
/*  MessageId: TLR_E_CANOPEN_APS_WATCHDOG_ACTIVATE */
/*  */
/*  MessageText: */
/*  */
/*   Failed to activate watchdog supervision. */
/*  */
#define TLR_E_CANOPEN_APS_WATCHDOG_ACTIVATE ((TLR_RESULT)0xC04A000FL)




#endif  /* __CANOPEN_APS_ERROR_H */

#ifndef __CANOPEN_MASTER_ERROR_H
#define __CANOPEN_MASTER_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CANopen Master */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_CANOPEN_MASTER_COMMAND_INVALID ((TLR_RESULT)0xC0420001L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_PACKET_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Invalid length in packet. */
/*  */
#define TLR_E_CANOPEN_MASTER_PACKET_LENGTH ((TLR_RESULT)0xC0420002L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_DATA_COUNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid data count. */
/*  */
#define TLR_E_CANOPEN_MASTER_DATA_COUNT  ((TLR_RESULT)0xC0420003L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_DATA_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Invalid data offset. */
/*  */
#define TLR_E_CANOPEN_MASTER_DATA_OFFSET ((TLR_RESULT)0xC0420004L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_DATA_COUNT_WITH_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Invalid data count in combination with offset. */
/*  */
#define TLR_E_CANOPEN_MASTER_DATA_COUNT_WITH_OFFSET ((TLR_RESULT)0xC0420005L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid mode in command. */
/*  */
#define TLR_E_CANOPEN_MASTER_MODE        ((TLR_RESULT)0xC0420006L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Command is not allowed in current state. */
/*  */
#define TLR_E_CANOPEN_MASTER_STATE       ((TLR_RESULT)0xC0420007L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_NO_VALID_BUS_PARAM */
/*  */
/*  MessageText: */
/*  */
/*   No valid bus configuration parameterized. */
/*  */
#define TLR_E_CANOPEN_MASTER_NO_VALID_BUS_PARAM ((TLR_RESULT)0xC0420008L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_REQUEST_RUNNING */
/*  */
/*  MessageText: */
/*  */
/*   A request is already running. */
/*  */
#define TLR_E_CANOPEN_MASTER_REQUEST_RUNNING ((TLR_RESULT)0xC0420009L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_BUS_RUNNING */
/*  */
/*  MessageText: */
/*  */
/*   Command is not allowed because CANopen is running. */
/*  */
#define TLR_E_CANOPEN_MASTER_BUS_RUNNING ((TLR_RESULT)0xC042000AL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_BUS_PARAM_ALREADY_SET */
/*  */
/*  MessageText: */
/*  */
/*   Bus parameters are already configured. */
/*  */
#define TLR_E_CANOPEN_MASTER_BUS_PARAM_ALREADY_SET ((TLR_RESULT)0xC042000BL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_LOCAL_NODE_ID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Node ID for CANopen Master. */
/*  */
#define TLR_E_CANOPEN_MASTER_LOCAL_NODE_ID ((TLR_RESULT)0xC042000CL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_BAUDRATE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Baudrate. */
/*  */
#define TLR_E_CANOPEN_MASTER_BAUDRATE    ((TLR_RESULT)0xC042000DL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_29BIT_SELECTOR */
/*  */
/*  MessageText: */
/*  */
/*   Invaiid parameter for 29 bit selector. */
/*  */
#define TLR_E_CANOPEN_MASTER_29BIT_SELECTOR ((TLR_RESULT)0xC042000EL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_SYNC_TIMER_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Invaiid parameter for SYNC timer. */
/*  */
#define TLR_E_CANOPEN_MASTER_SYNC_TIMER_VALUE ((TLR_RESULT)0xC042000FL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_COB_ID_SYNC */
/*  */
/*  MessageText: */
/*  */
/*   Invaiid parameter for COB-ID SYNC. */
/*  */
#define TLR_E_CANOPEN_MASTER_COB_ID_SYNC ((TLR_RESULT)0xC0420010L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_PROD_HEARTBEAT_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Invaiid parameter for Producer Heartbeat time. */
/*  */
#define TLR_E_CANOPEN_MASTER_PROD_HEARTBEAT_TIME ((TLR_RESULT)0xC0420011L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_PACKET_SEQUENCE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid packet sequence detected. */
/*  */
#define TLR_E_CANOPEN_MASTER_PACKET_SEQUENCE ((TLR_RESULT)0xC0420012L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_NODE_PARAM_SET_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid size of Node parameter set. */
/*  */
#define TLR_E_CANOPEN_MASTER_NODE_PARAM_SET_SIZE ((TLR_RESULT)0xC0420013L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_NODE_PARAM_HEADER_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid size of Node parameter header. */
/*  */
#define TLR_E_CANOPEN_MASTER_NODE_PARAM_HEADER_SIZE ((TLR_RESULT)0xC0420014L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_NODE_ALREADY_CONFIGURED */
/*  */
/*  MessageText: */
/*  */
/*   Node is already configured. */
/*  */
#define TLR_E_CANOPEN_MASTER_NODE_ALREADY_CONFIGURED ((TLR_RESULT)0xC0420015L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_SLAVE_NODE_ID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Node ID for Slave. */
/*  */
#define TLR_E_CANOPEN_MASTER_SLAVE_NODE_ID ((TLR_RESULT)0xC0420016L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_NODE_ID_EQUAL */
/*  */
/*  MessageText: */
/*  */
/*   Node ID of Slave is equal to Master Node ID. */
/*  */
#define TLR_E_CANOPEN_MASTER_NODE_ID_EQUAL ((TLR_RESULT)0xC0420017L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_PARAMETER_SET_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Length of parameter set is different from length in parameter header. */
/*  */
#define TLR_E_CANOPEN_MASTER_PARAMETER_SET_LENGTH ((TLR_RESULT)0xC0420018L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_SDO_PARAMETER_SET_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Invalid size of SDO parameter set. */
/*  */
#define TLR_E_CANOPEN_MASTER_SDO_PARAMETER_SET_LENGTH ((TLR_RESULT)0xC0420019L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_PDO_PARAMETER_SET_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Invalid size of PDO parameter set. */
/*  */
#define TLR_E_CANOPEN_MASTER_PDO_PARAMETER_SET_LENGTH ((TLR_RESULT)0xC042001AL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_ADDR_TABLE_SET_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Invalid size of address table. */
/*  */
#define TLR_E_CANOPEN_MASTER_ADDR_TABLE_SET_LENGTH ((TLR_RESULT)0xC042001BL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_ADDR_TABLE_LENGTH_INCONSISTENT */
/*  */
/*  MessageText: */
/*  */
/*   Address table size is inconsistent. */
/*  */
#define TLR_E_CANOPEN_MASTER_ADDR_TABLE_LENGTH_INCONSISTENT ((TLR_RESULT)0xC042001CL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_TPDO_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid number of transmitt PDOs. */
/*  */
#define TLR_E_CANOPEN_MASTER_TPDO_CNT    ((TLR_RESULT)0xC042001EL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_RPDO_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid number of receive PDOs. */
/*  */
#define TLR_E_CANOPEN_MASTER_RPDO_CNT    ((TLR_RESULT)0xC042001FL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_COB_ID_EMCY */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for COB-ID Emergency. */
/*  */
#define TLR_E_CANOPEN_MASTER_COB_ID_EMCY ((TLR_RESULT)0xC0420020L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_COB_ID_GUARD */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for COB-ID Guard. */
/*  */
#define TLR_E_CANOPEN_MASTER_COB_ID_GUARD ((TLR_RESULT)0xC0420021L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MEMORY_ALLOCATION */
/*  */
/*  MessageText: */
/*  */
/*   No memory for parameter set. */
/*  */
#define TLR_E_CANOPEN_MEMORY_ALLOCATION  ((TLR_RESULT)0xC0420022L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SDO_DATA_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for SDO data count. */
/*  */
#define TLR_E_CANOPEN_SDO_DATA_CNT       ((TLR_RESULT)0xC0420023L)

/*  */
/*  MessageId: TLR_E_CANOPEN_PDO_DATA_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for PDO data count. */
/*  */
#define TLR_E_CANOPEN_PDO_DATA_CNT       ((TLR_RESULT)0xC0420024L)

/*  */
/*  MessageId: TLR_E_CANOPEN_ADDR_TAB_DATA_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for address table data count. */
/*  */
#define TLR_E_CANOPEN_ADDR_TAB_DATA_CNT  ((TLR_RESULT)0xC0420025L)

/*  */
/*  MessageId: TLR_E_CANOPEN_ADDR_TAB_PDO_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for address table PDO count. */
/*  */
#define TLR_E_CANOPEN_ADDR_TAB_PDO_CNT   ((TLR_RESULT)0xC0420026L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_NODE_SDO_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Timeout during SDO transfer. */
/*  */
#define TLR_E_CANOPEN_MASTER_NODE_SDO_TIMEOUT ((TLR_RESULT)0xC0420027L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_NODE_SDO_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error during SDO transfer. */
/*  */
#define TLR_E_CANOPEN_MASTER_NODE_SDO_ERROR ((TLR_RESULT)0xC0420028L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_NO_PDO_AVAILABLE */
/*  */
/*  MessageText: */
/*  */
/*   No further PDO available. */
/*  */
#define TLR_E_CANOPEN_MASTER_NO_PDO_AVAILABLE ((TLR_RESULT)0xC0420029L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_AUTO_CLEAR_ACTIVE */
/*  */
/*  MessageText: */
/*  */
/*   Master is in auto clear state. */
/*  */
#define TLR_E_CANOPEN_MASTER_AUTO_CLEAR_ACTIVE ((TLR_RESULT)0xC042002AL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_WATCHDOG_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Watchdog failure detected. */
/*  */
#define TLR_E_CANOPEN_MASTER_WATCHDOG_FAIL ((TLR_RESULT)0xC042002BL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_INVALID_INDEX */
/*  */
/*  MessageText: */
/*  */
/*   Invalid index for request. */
/*  */
#define TLR_E_CANOPEN_MASTER_INVALID_INDEX ((TLR_RESULT)0xC042002CL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_NODE_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Request not possible in current Node state. */
/*  */
#define TLR_E_CANOPEN_MASTER_NODE_STATE  ((TLR_RESULT)0xC042002DL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_NODE_NOT_CONFIGURED */
/*  */
/*  MessageText: */
/*  */
/*   Node is not configuerd. */
/*  */
#define TLR_E_CANOPEN_MASTER_NODE_NOT_CONFIGURED ((TLR_RESULT)0xC042002EL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_SDO_REQUEST_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   SDO request failed. */
/*  */
#define TLR_E_CANOPEN_MASTER_SDO_REQUEST_FAILED ((TLR_RESULT)0xC042002FL)

/*  */
/*  MessageId: TLR_I_CANOPEN_MASTER_ALREADY_IN_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Master is already in requested state. */
/*  */
#define TLR_I_CANOPEN_MASTER_ALREADY_IN_STATE ((TLR_RESULT)0x40420030L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_COB_ID_PDO */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for PDO COB-ID. */
/*  */
#define TLR_E_CANOPEN_MASTER_COB_ID_PDO  ((TLR_RESULT)0xC0420031L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_SEND_EMCY */
/*  */
/*  MessageText: */
/*  */
/*   Send emergency-telegram failed. */
/*  */
#define TLR_E_CANOPEN_MASTER_SEND_EMCY   ((TLR_RESULT)0xC0420032L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_INIT_SDO_REQUEST */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize SDO request. */
/*  */
#define TLR_E_CANOPEN_MASTER_INIT_SDO_REQUEST ((TLR_RESULT)0xC0420033L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_SET_NMT_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Set NMT state failed. */
/*  */
#define TLR_E_CANOPEN_MASTER_SET_NMT_STATE ((TLR_RESULT)0xC0420034L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_ERROR_PASSIVE */
/*  */
/*  MessageText: */
/*  */
/*   CANopen is in error-passive state. */
/*  */
#define TLR_E_CANOPEN_MASTER_ERROR_PASSIVE ((TLR_RESULT)0xC0420035L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_BUS_OFF */
/*  */
/*  MessageText: */
/*  */
/*   CANopen is in bus-off state. */
/*  */
#define TLR_E_CANOPEN_MASTER_BUS_OFF     ((TLR_RESULT)0xC0420036L)

/*  */
/*  MessageId: TLR_I_CANOPEN_MASTER_NODE_DEACTIVATED */
/*  */
/*  MessageText: */
/*  */
/*   Node is deactivated in configuration. */
/*  */
#define TLR_I_CANOPEN_MASTER_NODE_DEACTIVATED ((TLR_RESULT)0x40420037L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_DL_REQ_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   CAN-DL request failed. */
/*  */
#define TLR_E_CANOPEN_MASTER_DL_REQ_FAILED ((TLR_RESULT)0xC0420038L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_PUT_OBJECT_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Failed to write object data. */
/*  */
#define TLR_E_CANOPEN_MASTER_PUT_OBJECT_DATA ((TLR_RESULT)0xC0420039L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_SET_OBJECT_DATA_VALID */
/*  */
/*  MessageText: */
/*  */
/*   Failed to set object data valid. */
/*  */
#define TLR_E_CANOPEN_MASTER_SET_OBJECT_DATA_VALID ((TLR_RESULT)0xC042003AL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_INIT_LIB */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialite CANopen library. */
/*  */
#define TLR_E_CANOPEN_MASTER_INIT_LIB    ((TLR_RESULT)0xC042003BL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_SET_COB_ID_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   COB-ID could not be set. */
/*  */
#define TLR_E_CANOPEN_MASTER_SET_COB_ID_FAILED ((TLR_RESULT)0xC042003CL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_ADD_REMOTE_NODE_REQUEST */
/*  */
/*  MessageText: */
/*  */
/*   Failed to add remote Node. */
/*  */
#define TLR_E_CANOPEN_MASTER_ADD_REMOTE_NODE_REQUEST ((TLR_RESULT)0xC042003DL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_SET_HEARTBEAT_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Heartbeat time could not be set. */
/*  */
#define TLR_E_CANOPEN_MASTER_SET_HEARTBEAT_TIME ((TLR_RESULT)0xC042003EL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_ADD_GUARDING_SLAVE */
/*  */
/*  MessageText: */
/*  */
/*   Node could not be added to Node guarding list. */
/*  */
#define TLR_E_CANOPEN_MASTER_ADD_GUARDING_SLAVE ((TLR_RESULT)0xC042003FL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_SET_GUARDING_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Node guard time could not be set. */
/*  */
#define TLR_E_CANOPEN_MASTER_SET_GUARDING_TIME ((TLR_RESULT)0xC0420040L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_START_NODE_GUARD */
/*  */
/*  MessageText: */
/*  */
/*   Node guarding could not be started. */
/*  */
#define TLR_E_CANOPEN_MASTER_START_NODE_GUARD ((TLR_RESULT)0xC0420041L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_RESET_NODE */
/*  */
/*  MessageText: */
/*  */
/*   Reset Node failed. */
/*  */
#define TLR_E_CANOPEN_MASTER_RESET_NODE  ((TLR_RESULT)0xC0420042L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_RESET_COMMUNICATION */
/*  */
/*  MessageText: */
/*  */
/*   Failed to reset communication of Node. */
/*  */
#define TLR_E_CANOPEN_MASTER_RESET_COMMUNICATION ((TLR_RESULT)0xC0420043L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_SET_NODE_PREOPERATIONAL */
/*  */
/*  MessageText: */
/*  */
/*   Failed to set Node to preoperational state. */
/*  */
#define TLR_E_CANOPEN_MASTER_SET_NODE_PREOPERATIONAL ((TLR_RESULT)0xC0420044L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_STOP_NODE */
/*  */
/*  MessageText: */
/*  */
/*   Failed to set Node to stop state. */
/*  */
#define TLR_E_CANOPEN_MASTER_STOP_NODE   ((TLR_RESULT)0xC0420045L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_START_NODE */
/*  */
/*  MessageText: */
/*  */
/*   Failed to set Node to operational state. */
/*  */
#define TLR_E_CANOPEN_MASTER_START_NODE  ((TLR_RESULT)0xC0420046L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_SET_EMCY_COB_ID */
/*  */
/*  MessageText: */
/*  */
/*   Failed to set Emergency COB-ID. */
/*  */
#define TLR_E_CANOPEN_MASTER_SET_EMCY_COB_ID ((TLR_RESULT)0xC0420047L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_START_SYNC */
/*  */
/*  MessageText: */
/*  */
/*   Failed to start SYNC-telegram. */
/*  */
#define TLR_E_CANOPEN_MASTER_START_SYNC  ((TLR_RESULT)0xC0420048L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_STOP_SYNC */
/*  */
/*  MessageText: */
/*  */
/*   Failed to stop SYNC-telegram. */
/*  */
#define TLR_E_CANOPEN_MASTER_STOP_SYNC   ((TLR_RESULT)0xC0420049L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_NODE_UNEXPECTED_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Node is not in expected state. */
/*  */
#define TLR_E_CANOPEN_MASTER_NODE_UNEXPECTED_STATE ((TLR_RESULT)0xC042004AL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_NODE_LOST_CONNECTION */
/*  */
/*  MessageText: */
/*  */
/*   Connection to Node lost. */
/*  */
#define TLR_E_CANOPEN_MASTER_NODE_LOST_CONNECTION ((TLR_RESULT)0xC042004BL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_NODE_GUARDING_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Node guarding error. */
/*  */
#define TLR_E_CANOPEN_MASTER_NODE_GUARDING_ERROR ((TLR_RESULT)0xC042004CL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_NODE_HEARTBEAT_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Heartbeat error. */
/*  */
#define TLR_E_CANOPEN_MASTER_NODE_HEARTBEAT_ERROR ((TLR_RESULT)0xC042004DL)

/*  */
/*  MessageId: TLR_I_CANOPEN_MASTER_NODE_HEARTBEAT_STARTED */
/*  */
/*  MessageText: */
/*  */
/*   Heartbeat supervision of Node started. */
/*  */
#define TLR_I_CANOPEN_MASTER_NODE_HEARTBEAT_STARTED ((TLR_RESULT)0x4042004EL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_NODE_UNEXPECTED_BOOTUP */
/*  */
/*  MessageText: */
/*  */
/*   Unexpected Bootup message from Node received. */
/*  */
#define TLR_E_CANOPEN_MASTER_NODE_UNEXPECTED_BOOTUP ((TLR_RESULT)0xC042004FL)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_WRITE_PDO_REQ */
/*  */
/*  MessageText: */
/*  */
/*   Failed to transmit PDO. */
/*  */
#define TLR_E_CANOPEN_MASTER_WRITE_PDO_REQ ((TLR_RESULT)0xC0420050L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_READ_PDO_REQ */
/*  */
/*  MessageText: */
/*  */
/*   Failed to request PDO. */
/*  */
#define TLR_E_CANOPEN_MASTER_READ_PDO_REQ ((TLR_RESULT)0xC0420051L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_INIT_BUFFER */
/*  */
/*  MessageText: */
/*  */
/*   Initialization of buffer failed. */
/*  */
#define TLR_E_CANOPEN_MASTER_INIT_BUFFER ((TLR_RESULT)0xC0420052L)

/*  */
/*  MessageId: TLR_I_CANOPEN_MASTER_NODE_STATE_NOT_HANDLED */
/*  */
/*  MessageText: */
/*  */
/*   State of Node not handled. */
/*  */
#define TLR_I_CANOPEN_MASTER_NODE_STATE_NOT_HANDLED ((TLR_RESULT)0x40420053L)

/*  */
/*  MessageId: TLR_E_CANOPEN_MASTER_NODE_DEVICE_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Node Device Type unequal to configured Device Type. */
/*  */
#define TLR_E_CANOPEN_MASTER_NODE_DEVICE_TYPE ((TLR_RESULT)0xC0420054L)

/*  */
/*  MessageId: TLR_I_CANOPEN_MASTER_NODE_EMERGENCY_RECEIVED */
/*  */
/*  MessageText: */
/*  */
/*   Emergency message received from Node. */
/*  */
#define TLR_I_CANOPEN_MASTER_NODE_EMERGENCY_RECEIVED ((TLR_RESULT)0x40420055L)

/*  */
/*  MessageId: TLR_I_CANOPEN_MASTER_INITIALIZE */
/*  */
/*  MessageText: */
/*  */
/*   Master is initializing. */
/*  */
#define TLR_I_CANOPEN_MASTER_INITIALIZE  ((TLR_RESULT)0x40420056L)

/*  */
/*  MessageId: TLR_I_CANOPEN_MASTER_NODE_BOOTUP */
/*  */
/*  MessageText: */
/*  */
/*   Bootup message from Node received. */
/*  */
#define TLR_I_CANOPEN_MASTER_NODE_BOOTUP ((TLR_RESULT)0x40420057L)




#endif  /* __CANOPEN_MASTER_ERROR_H */

#ifndef __CANOPEN_SLAVE_ERROR_H
#define __CANOPEN_SLAVE_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CANopen Slave */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_CANOPEN_SLAVE_COMMAND_INVALID ((TLR_RESULT)0xC0430001L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_PACKET_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Invalid length in packet. */
/*  */
#define TLR_E_CANOPEN_SLAVE_PACKET_LENGTH ((TLR_RESULT)0xC0430002L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_DATA_COUNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid data count. */
/*  */
#define TLR_E_CANOPEN_SLAVE_DATA_COUNT   ((TLR_RESULT)0xC0430003L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_DATA_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Invalid data offset. */
/*  */
#define TLR_E_CANOPEN_SLAVE_DATA_OFFSET  ((TLR_RESULT)0xC0430004L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_DATA_COUNT_WITH_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Invalid data count in combination with offset. */
/*  */
#define TLR_E_CANOPEN_SLAVE_DATA_COUNT_WITH_OFFSET ((TLR_RESULT)0xC0430005L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid mode in command. */
/*  */
#define TLR_E_CANOPEN_SLAVE_MODE         ((TLR_RESULT)0xC0430006L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Command is not allowed in current state. */
/*  */
#define TLR_E_CANOPEN_SLAVE_STATE        ((TLR_RESULT)0xC0430007L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_REQUEST_RUNNING */
/*  */
/*  MessageText: */
/*  */
/*   A request is already running. */
/*  */
#define TLR_E_CANOPEN_SLAVE_REQUEST_RUNNING ((TLR_RESULT)0xC0430008L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_BUS_RUNNING */
/*  */
/*  MessageText: */
/*  */
/*   Command is not allowed because CANopen is running. */
/*  */
#define TLR_E_CANOPEN_SLAVE_BUS_RUNNING  ((TLR_RESULT)0xC0430009L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_BUS_PARAM_ALREADY_SET */
/*  */
/*  MessageText: */
/*  */
/*   Bus parameters are already configured. */
/*  */
#define TLR_E_CANOPEN_SLAVE_BUS_PARAM_ALREADY_SET ((TLR_RESULT)0xC043000AL)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_LOCAL_NODE_ID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Node ID for CANopen Slave. */
/*  */
#define TLR_E_CANOPEN_SLAVE_LOCAL_NODE_ID ((TLR_RESULT)0xC043000BL)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_BAUDRATE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Baudrate. */
/*  */
#define TLR_E_CANOPEN_SLAVE_BAUDRATE     ((TLR_RESULT)0xC043000CL)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_29BIT_SELECTOR */
/*  */
/*  MessageText: */
/*  */
/*   Invaiid parameter for 29 bit selector. */
/*  */
#define TLR_E_CANOPEN_SLAVE_29BIT_SELECTOR ((TLR_RESULT)0xC043000DL)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_WATCHDOG_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Watchdog failure detected. */
/*  */
#define TLR_E_CANOPEN_SLAVE_WATCHDOG_FAIL ((TLR_RESULT)0xC043000EL)

/*  */
/*  MessageId: TLR_I_CANOPEN_SLAVE_ALREADY_IN_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Slave is already in requested state. */
/*  */
#define TLR_I_CANOPEN_SLAVE_ALREADY_IN_STATE ((TLR_RESULT)0x4043000FL)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_SEND_EMCY */
/*  */
/*  MessageText: */
/*  */
/*   Send emergency-telegram failed. */
/*  */
#define TLR_E_CANOPEN_SLAVE_SEND_EMCY    ((TLR_RESULT)0xC0430010L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_INIT_LIB */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize CANopen library. */
/*  */
#define TLR_E_CANOPEN_SLAVE_INIT_LIB     ((TLR_RESULT)0xC0430011L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_ERROR_PASSIVE */
/*  */
/*  MessageText: */
/*  */
/*   CANopen is in error-passive state. */
/*  */
#define TLR_E_CANOPEN_SLAVE_ERROR_PASSIVE ((TLR_RESULT)0xC0430012L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_BUS_OFF */
/*  */
/*  MessageText: */
/*  */
/*   CANopen is in bus-off state. */
/*  */
#define TLR_E_CANOPEN_SLAVE_BUS_OFF      ((TLR_RESULT)0xC0430013L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_PUT_OBJECT_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Failed to write object data. */
/*  */
#define TLR_E_CANOPEN_SLAVE_PUT_OBJECT_DATA ((TLR_RESULT)0xC0430014L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_SET_OBJECT_DATA_VALID */
/*  */
/*  MessageText: */
/*  */
/*   Language        = English */
/*   Failed to set object data valid. */
/*  */
#define TLR_E_CANOPEN_SLAVE_SET_OBJECT_DATA_VALID ((TLR_RESULT)0xC0430015L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_GET_OBJECT_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get object data. */
/*  */
#define TLR_E_CANOPEN_SLAVE_GET_OBJECT_DATA ((TLR_RESULT)0xC0430016L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_WRITE_PDO_REQ */
/*  */
/*  MessageText: */
/*  */
/*   Failed to transmit PDO. */
/*  */
#define TLR_E_CANOPEN_SLAVE_WRITE_PDO_REQ ((TLR_RESULT)0xC0430017L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_GUARD_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Guard error detected. */
/*  */
#define TLR_E_CANOPEN_SLAVE_GUARD_ERROR  ((TLR_RESULT)0xC0430018L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_INIT_BUFFER */
/*  */
/*  MessageText: */
/*  */
/*   Initialization of buffer failed. */
/*  */
#define TLR_E_CANOPEN_SLAVE_INIT_BUFFER  ((TLR_RESULT)0xC0430019L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_DL_REQ_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   CAN-DL request failed. */
/*  */
#define TLR_E_CANOPEN_SLAVE_DL_REQ_FAILED ((TLR_RESULT)0xC043001AL)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_INVALID_INDEX */
/*  */
/*  MessageText: */
/*  */
/*   Invalid object index. */
/*  */
#define TLR_E_CANOPEN_SLAVE_INVALID_INDEX ((TLR_RESULT)0xC043001BL)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_INVALID_SUB_INDEX */
/*  */
/*  MessageText: */
/*  */
/*   Invalid object index. */
/*  */
#define TLR_E_CANOPEN_SLAVE_INVALID_SUB_INDEX ((TLR_RESULT)0xC043001CL)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_INVALID_MAP_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Invalid mapping length. */
/*  */
#define TLR_E_CANOPEN_SLAVE_INVALID_MAP_LENGTH ((TLR_RESULT)0xC043001DL)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_INVALID_PDO_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid transmission mode for PDO. */
/*  */
#define TLR_E_CANOPEN_SLAVE_INVALID_PDO_MODE ((TLR_RESULT)0xC043001EL)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_INVALID_PDO_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Invalid length for PDO. */
/*  */
#define TLR_E_CANOPEN_SLAVE_INVALID_PDO_LENGTH ((TLR_RESULT)0xC043001FL)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_NO_WRITE_PERM */
/*  */
/*  MessageText: */
/*  */
/*   No write permission for object. */
/*  */
#define TLR_E_CANOPEN_SLAVE_NO_WRITE_PERM ((TLR_RESULT)0xC0430020L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_NO_READ_PERM */
/*  */
/*  MessageText: */
/*  */
/*   No read permission for object. */
/*  */
#define TLR_E_CANOPEN_SLAVE_NO_READ_PERM ((TLR_RESULT)0xC0430021L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_VALUE_TOO_LOW */
/*  */
/*  MessageText: */
/*  */
/*   Value for object too low. */
/*  */
#define TLR_E_CANOPEN_SLAVE_VALUE_TOO_LOW ((TLR_RESULT)0xC0430022L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_VALUE_TOO_HIGH */
/*  */
/*  MessageText: */
/*  */
/*   Value for object too high. */
/*  */
#define TLR_E_CANOPEN_SLAVE_VALUE_TOO_HIGH ((TLR_RESULT)0xC0430023L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_INVALID_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for object. */
/*  */
#define TLR_E_CANOPEN_SLAVE_INVALID_PARAMETER ((TLR_RESULT)0xC0430024L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_INVALID_PDO_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid PDO state. */
/*  */
#define TLR_E_CANOPEN_SLAVE_INVALID_PDO_STATE ((TLR_RESULT)0xC0430025L)

/*  */
/*  MessageId: TLR_I_CANOPEN_SLAVE_INITIALIZE */
/*  */
/*  MessageText: */
/*  */
/*   Slave is initializing. */
/*  */
#define TLR_I_CANOPEN_SLAVE_INITIALIZE   ((TLR_RESULT)0x40430026L)

/*  */
/*  MessageId: TLR_E_CANOPEN_SLAVE_OBJECT_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid size for object. */
/*  */
#define TLR_E_CANOPEN_SLAVE_OBJECT_SIZE  ((TLR_RESULT)0xC0430027L)




#endif  /* __CANOPEN_SLAVE_ERROR_H */

#ifndef __CCLINK_APS_ERROR_H
#define __CCLINK_APS_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CC-Link Slave Application Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_CCLINK_APS_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_CCLINK_APS_COMMAND_INVALID ((TLR_RESULT)0xC06B0001L)

/*  */
/*  MessageId: TLR_I_CCLINK_APS_OPEN_DBM_FILE */
/*  */
/*  MessageText: */
/*  */
/*   Failed to open configuration database. */
/*  */
#define TLR_I_CCLINK_APS_OPEN_DBM_FILE   ((TLR_RESULT)0x406B0002L)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_DATASET */
/*  */
/*  MessageText: */
/*  */
/*   Failed to open configuration dataset. */
/*  */
#define TLR_E_CCLINK_APS_DATASET         ((TLR_RESULT)0xC06B0003L)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_TABLE_GLOBAL */
/*  */
/*  MessageText: */
/*  */
/*   Failed to open GLOBAL configuration dataset. */
/*  */
#define TLR_E_CCLINK_APS_TABLE_GLOBAL    ((TLR_RESULT)0xC06B0004L)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_TABLE_CCLS_INI */
/*  */
/*  MessageText: */
/*  */
/*   Failed to open CCLS_INI configuration dataset. */
/*  */
#define TLR_E_CCLINK_APS_TABLE_CCLS_INI  ((TLR_RESULT)0xC06B0005L)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_WATCHDOG_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for watchdog supervision. */
/*  */
#define TLR_E_CCLINK_APS_WATCHDOG_PARAMETER ((TLR_RESULT)0xC06B0006L)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_SIZE_TABLE_CCLS_INI */
/*  */
/*  MessageText: */
/*  */
/*   Invalid size of CCLS_INI configuration dataset. */
/*  */
#define TLR_E_CCLINK_APS_SIZE_TABLE_CCLS_INI ((TLR_RESULT)0xC06B0007L)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_PACKET_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Invalid packet length. */
/*  */
#define TLR_E_CCLINK_APS_PACKET_LENGTH   ((TLR_RESULT)0xC06B0008L)

/*  */
/*  MessageId: TLR_I_CCLINK_APS_CONFIG_LOCK */
/*  */
/*  MessageText: */
/*  */
/*   Configuration is locked. */
/*  */
#define TLR_I_CCLINK_APS_CONFIG_LOCK     ((TLR_RESULT)0x406B0009L)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_DATABASE_FOUND */
/*  */
/*  MessageText: */
/*  */
/*   Configuration database found. */
/*  */
#define TLR_E_CCLINK_APS_DATABASE_FOUND  ((TLR_RESULT)0xC06B000AL)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_SLAVE_STATION_ADDR_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for slave station address. */
/*  */
#define TLR_E_CCLINK_APS_SLAVE_STATION_ADDR_PARAMETER ((TLR_RESULT)0xC06B000BL)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_BAUDRATE_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for baudrate. */
/*  */
#define TLR_E_CCLINK_APS_BAUDRATE_PARAMETER ((TLR_RESULT)0xC06B000CL)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_NO_STATION_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for number of stations. */
/*  */
#define TLR_E_CCLINK_APS_NO_STATION_PARAMETER ((TLR_RESULT)0xC06B000DL)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_MODE_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for mode. */
/*  */
#define TLR_E_CCLINK_APS_MODE_PARAMETER  ((TLR_RESULT)0xC06B000EL)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_VENDOR_CODE_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for vendor code. */
/*  */
#define TLR_E_CCLINK_APS_VENDOR_CODE_PARAMETER ((TLR_RESULT)0xC06B000FL)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_MODEL_CODE_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for model code. */
/*  */
#define TLR_E_CCLINK_APS_MODEL_CODE_PARAMETER ((TLR_RESULT)0xC06B0010L)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_SW_VERSION_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for software version. */
/*  */
#define TLR_E_CCLINK_APS_SW_VERSION_PARAMETER ((TLR_RESULT)0xC06B0011L)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_MODEL_TYPE_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for model type. */
/*  */
#define TLR_E_CCLINK_APS_MODEL_TYPE_PARAMETER ((TLR_RESULT)0xC06B0012L)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_IO_MODE_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for IO mode. */
/*  */
#define TLR_E_CCLINK_APS_IO_MODE_PARAMETER ((TLR_RESULT)0xC06B0013L)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_REQUEST_RUNNING */
/*  */
/*  MessageText: */
/*  */
/*   Request already running. */
/*  */
#define TLR_E_CCLINK_APS_REQUEST_RUNNING ((TLR_RESULT)0xC06B0014L)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_INVALD_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Request not allowed in current state. */
/*  */
#define TLR_E_CCLINK_APS_INVALD_STATE    ((TLR_RESULT)0xC06B0015L)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_PARAM_CYCLETIME */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for cycletime. */
/*  */
#define TLR_E_CCLINK_APS_PARAM_CYCLETIME ((TLR_RESULT)0xC06B0016L)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_PARAM_CHN_INSTANCE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for DPM instance. */
/*  */
#define TLR_E_CCLINK_APS_PARAM_CHN_INSTANCE ((TLR_RESULT)0xC06B0017L)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_SET_SWITCH_CHANGE_NOT_ALLOWED */
/*  */
/*  MessageText: */
/*  */
/*   Change switch state not allowed. */
/*  */
#define TLR_E_CCLINK_APS_SET_SWITCH_CHANGE_NOT_ALLOWED ((TLR_RESULT)0xC06B0018L)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_CCLINK_VERSION_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for CC-Link version. */
/*  */
#define TLR_E_CCLINK_APS_CCLINK_VERSION_PARAMETER ((TLR_RESULT)0xC06B0019L)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_STATION_TYPE_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for station type. */
/*  */
#define TLR_E_CCLINK_APS_STATION_TYPE_PARAMETER ((TLR_RESULT)0xC06B001AL)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_STATION_ADDR_WITH_NO_STATIONS_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for station address in combination with number of stations. */
/*  */
#define TLR_E_CCLINK_APS_STATION_ADDR_WITH_NO_STATIONS_PARAMETER ((TLR_RESULT)0xC06B001BL)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_EXTENSION_CYCLE_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter extension cycle. */
/*  */
#define TLR_E_CCLINK_APS_EXTENSION_CYCLE_PARAMETER ((TLR_RESULT)0xC06B001CL)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_STATION_TYPE_WITH_CCLINK_VERSION_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for station type in combination with CC-Link version. */
/*  */
#define TLR_E_CCLINK_APS_STATION_TYPE_WITH_CCLINK_VERSION_PARAMETER ((TLR_RESULT)0xC06B001DL)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_PARAM_QUEUE_ELEMENT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for number of queue elements. */
/*  */
#define TLR_E_CCLINK_APS_PARAM_QUEUE_ELEMENT ((TLR_RESULT)0xC06B001EL)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_PARAM_POOL_ELEMENT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for number of pool elements. */
/*  */
#define TLR_E_CCLINK_APS_PARAM_POOL_ELEMENT ((TLR_RESULT)0xC06B001FL)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_PARAM_SWITCH */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for switch parameter. */
/*  */
#define TLR_E_CCLINK_APS_PARAM_SWITCH    ((TLR_RESULT)0xC06B0020L)

/*  */
/*  MessageId: TLR_E_CCLINK_APS_PARAM_IO_TYPES_POINTS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for number of I/O types and I/O points. */
/*  */
#define TLR_E_CCLINK_APS_PARAM_IO_TYPES_POINTS ((TLR_RESULT)0xC06B0021L)




#endif  /* __CCLINK_APS_ERROR_H */

#ifndef __CCLINK_SLAVE_ERROR_H
#define __CCLINK_SLAVE_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CC-Link Slave */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_CCLINK_SLAVE_COMMAND_INVALID ((TLR_RESULT)0xC06A0001L)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_WATCHDOG_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Watchdog failure detected. */
/*  */
#define TLR_E_CCLINK_SLAVE_WATCHDOG_FAIL ((TLR_RESULT)0xC06A0002L)

/*  */
/*  MessageId: TLR_I_CCLINK_SLAVE_ALREADY_IN_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Slave is already in requested state. */
/*  */
#define TLR_I_CCLINK_SLAVE_ALREADY_IN_STATE ((TLR_RESULT)0x406A0003L)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_PACKET_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Invalid length in packet. */
/*  */
#define TLR_E_CCLINK_SLAVE_PACKET_LENGTH ((TLR_RESULT)0xC06A0004L)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_DATA_COUNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid data count. */
/*  */
#define TLR_E_CCLINK_SLAVE_DATA_COUNT    ((TLR_RESULT)0xC06A0005L)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_DATA_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Invalid data offset. */
/*  */
#define TLR_E_CCLINK_SLAVE_DATA_OFFSET   ((TLR_RESULT)0xC06A0006L)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_INIT_BUFFER */
/*  */
/*  MessageText: */
/*  */
/*   Initialization of buffer failed. */
/*  */
#define TLR_E_CCLINK_SLAVE_INIT_BUFFER   ((TLR_RESULT)0xC06A0007L)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_INVALID_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Command is not allowed in current state. */
/*  */
#define TLR_E_CCLINK_SLAVE_INVALID_STATE ((TLR_RESULT)0xC06A0008L)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid mode in command. */
/*  */
#define TLR_E_CCLINK_SLAVE_MODE          ((TLR_RESULT)0xC06A0009L)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_PARAM_BAUDRATE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Baudrate. */
/*  */
#define TLR_E_CCLINK_SLAVE_PARAM_BAUDRATE ((TLR_RESULT)0xC06A000AL)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_PARAM_STATION_ADDR */
/*  */
/*  MessageText: */
/*  */
/*   Invalid station address for CC-Link Slave. */
/*  */
#define TLR_E_CCLINK_SLAVE_PARAM_STATION_ADDR ((TLR_RESULT)0xC06A000BL)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_PARAM_NO_STATIONS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for number of stations. */
/*  */
#define TLR_E_CCLINK_SLAVE_PARAM_NO_STATIONS ((TLR_RESULT)0xC06A000CL)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_PARAM_VENDOR_CODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for vendor code. */
/*  */
#define TLR_E_CCLINK_SLAVE_PARAM_VENDOR_CODE ((TLR_RESULT)0xC06A000DL)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_PARAM_MODEL_CODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for model code. */
/*  */
#define TLR_E_CCLINK_SLAVE_PARAM_MODEL_CODE ((TLR_RESULT)0xC06A000EL)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_PARAM_SW_VERSION */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for software version. */
/*  */
#define TLR_E_CCLINK_SLAVE_PARAM_SW_VERSION ((TLR_RESULT)0xC06A000FL)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_PARAM_MODEL_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for model type. */
/*  */
#define TLR_E_CCLINK_SLAVE_PARAM_MODEL_TYPE ((TLR_RESULT)0xC06A0010L)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_PARAM_STATION_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for station type. */
/*  */
#define TLR_E_CCLINK_SLAVE_PARAM_STATION_TYPE ((TLR_RESULT)0xC06A0011L)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_PARAM_CYCLETIME */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for cycle time. */
/*  */
#define TLR_E_CCLINK_SLAVE_PARAM_CYCLETIME ((TLR_RESULT)0xC06A0012L)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_PARAM_XC_INSTANCE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for XC-Instance. */
/*  */
#define TLR_E_CCLINK_SLAVE_PARAM_XC_INSTANCE ((TLR_RESULT)0xC06A0013L)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_PARAM_STATION_ADDR_WITH_NO_STATIONS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for station address in combination with number of stations. */
/*  */
#define TLR_E_CCLINK_SLAVE_PARAM_STATION_ADDR_WITH_NO_STATIONS ((TLR_RESULT)0xC06A0014L)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_PARAM_CCLINK_VERSION */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for CC-Link version. */
/*  */
#define TLR_E_CCLINK_SLAVE_PARAM_CCLINK_VERSION ((TLR_RESULT)0xC06A0015L)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_PARAM_EXTENSION_CYCLE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for extension cycle. */
/*  */
#define TLR_E_CCLINK_SLAVE_PARAM_EXTENSION_CYCLE ((TLR_RESULT)0xC06A0016L)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_PARAM_STATION_TYPE_WITH_CCLINK_VERSION */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for station type in combination with CC-Link version. */
/*  */
#define TLR_E_CCLINK_SLAVE_PARAM_STATION_TYPE_WITH_CCLINK_VERSION ((TLR_RESULT)0xC06A0017L)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_PARAM_QUEUE_ELEMENT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for number of queue elements. */
/*  */
#define TLR_E_CCLINK_SLAVE_PARAM_QUEUE_ELEMENT ((TLR_RESULT)0xC06A0018L)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_PARAM_POOL_ELEMENT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for number of pool elements. */
/*  */
#define TLR_E_CCLINK_SLAVE_PARAM_POOL_ELEMENT ((TLR_RESULT)0xC06A0019L)

/*  */
/*  MessageId: TLR_E_CCLINK_SLAVE_PARAM_IO_TYPES_POINTS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for number of I/O types and I/O points. */
/*  */
#define TLR_E_CCLINK_SLAVE_PARAM_IO_TYPES_POINTS ((TLR_RESULT)0xC06A001AL)




#endif  /* __CCLINK_SLAVE_ERROR_H */

#ifndef __COMPONET_SLAVE_ERROR_H
#define __COMPONET_SLAVE_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  COMPONET SLAVE  ERROR codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_COMPONET_SLAVE_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_COMPONET_SLAVE_COMMAND_INVALID ((TLR_RESULT)0xC07C0001L)

/*  */
/*  MessageId: TLR_E_CPS_INIT_TRI_BUFFER */
/*  */
/*  MessageText: */
/*  */
/*   Triple Buffer Initialization Failed. */
/*  */
#define TLR_E_CPS_INIT_TRI_BUFFER        ((TLR_RESULT)0xC07C0002L)

/*  */
/*  MessageId: TLR_E_CPS_DIAG_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Unknown Diagnostic Type. */
/*  */
#define TLR_E_CPS_DIAG_TYPE              ((TLR_RESULT)0xC07C0003L)

/*  */
/*  MessageId: TLR_E_CPS_DATA_LEN_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Data Size. */
/*  */
#define TLR_E_CPS_DATA_LEN_INVALID       ((TLR_RESULT)0xC07C0004L)

/*  */
/*  MessageId: TLR_E_CPS_WATCHDOG_INVALID_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Watchdog Value. */
/*  */
#define TLR_E_CPS_WATCHDOG_INVALID_VALUE ((TLR_RESULT)0xC07C0005L)

/*  */
/*  MessageId: TLR_E_CPS_COMM_LOST */
/*  */
/*  MessageText: */
/*  */
/*   Communication Lost. */
/*  */
#define TLR_E_CPS_COMM_LOST              ((TLR_RESULT)0xC07C0006L)

/*  */
/*  MessageId: TLR_E_CPS_SLAVE_DUPLICATE_MAC_ID */
/*  */
/*  MessageText: */
/*  */
/*   Duplicate MAC ID Detected. */
/*  */
#define TLR_E_CPS_SLAVE_DUPLICATE_MAC_ID ((TLR_RESULT)0xC07C0007L)

/*  */
/*  MessageId: TLR_E_CPS_IRQ_ENABLE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Enable CPS Interrupt Failed. */
/*  */
#define TLR_E_CPS_IRQ_ENABLE_ERROR       ((TLR_RESULT)0xC07C0008L)

/*  */
/*  MessageId: TLR_E_CPS_IRQ_DISABLE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Enable CPS Interrupt Failed. */
/*  */
#define TLR_E_CPS_IRQ_DISABLE_ERROR      ((TLR_RESULT)0xC07C0009L)

/*  */
/*  MessageId: TLR_E_CPS_UNKNOWN_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Unknown Parameter Received. */
/*  */
#define TLR_E_CPS_UNKNOWN_PARAMETER      ((TLR_RESULT)0xC07C000AL)

/*  */
/*  MessageId: TLR_E_CPS_WRONG_CHANNEL */
/*  */
/*  MessageText: */
/*  */
/*   Wrong XC Channel Selected. */
/*  */
#define TLR_E_CPS_WRONG_CHANNEL          ((TLR_RESULT)0xC07C000BL)

/*  */
/*  MessageId: TLR_E_CPS_WRONG_EVENT_LEN */
/*  */
/*  MessageText: */
/*  */
/*   CompoNet Frame Invalid Data. */
/*  */
#define TLR_E_CPS_WRONG_EVENT_LEN        ((TLR_RESULT)0xC07C000CL)

/*  */
/*  MessageId: TLR_E_CPS_WRONG_DEST_MAC_ID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Slave MAC ID. */
/*  */
#define TLR_E_CPS_WRONG_DEST_MAC_ID      ((TLR_RESULT)0xC07C000DL)

/*  */
/*  MessageId: TLR_E_CPS_WRONG_EVENT_CMD_ID */
/*  */
/*  MessageText: */
/*  */
/*   CompoNet Frame Invalid Commnad. */
/*  */
#define TLR_E_CPS_WRONG_EVENT_CMD_ID     ((TLR_RESULT)0xC07C000EL)

/*  */
/*  MessageId: TLR_E_CPS_EVENT_NOT_RECEIVED */
/*  */
/*  MessageText: */
/*  */
/*   CompoNet Frame Not Received. */
/*  */
#define TLR_E_CPS_EVENT_NOT_RECEIVED     ((TLR_RESULT)0xC07C000FL)

/*  */
/*  MessageId: TLR_E_CPS_DEVICE_NOT_ONLINE */
/*  */
/*  MessageText: */
/*  */
/*   Slave is not Allocated. */
/*  */
#define TLR_E_CPS_DEVICE_NOT_ONLINE      ((TLR_RESULT)0xC07C0010L)

/*  */
/*  MessageId: TLR_E_CPS_GENERAL_HAL_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   General HAL Erorr. */
/*  */
#define TLR_E_CPS_GENERAL_HAL_ERROR      ((TLR_RESULT)0xC07C0011L)

/*  */
/*  MessageId: TLR_E_CPS_WRONG_BAUD_RATE */
/*  */
/*  MessageText: */
/*  */
/*   Wrong Baud Rate. */
/*  */
#define TLR_E_CPS_WRONG_BAUD_RATE        ((TLR_RESULT)0xC07C0012L)

/*  */
/*  MessageId: TLR_E_CPS_WRONG_NODE_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Wrong Node Type. */
/*  */
#define TLR_E_CPS_WRONG_NODE_TYPE        ((TLR_RESULT)0xC07C0013L)

/*  */
/*  MessageId: TLR_E_CPS_WRONG_IO_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Wrong I/O Mode. */
/*  */
#define TLR_E_CPS_WRONG_IO_MODE          ((TLR_RESULT)0xC07C0014L)

/*  */
/*  MessageId: TLR_E_CPS_CLASS_ALREADY_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   CIP Class Already Registred. */
/*  */
#define TLR_E_CPS_CLASS_ALREADY_REGISTERED ((TLR_RESULT)0xC07C0015L)

/*  */
/*  MessageId: TLR_E_CPS_MAX_CLASS_NUMB_REACHED */
/*  */
/*  MessageText: */
/*  */
/*   Maximum Number of CIP Class Registred. */
/*  */
#define TLR_E_CPS_MAX_CLASS_NUMB_REACHED ((TLR_RESULT)0xC07C0016L)

/*  */
/*  MessageId: TLR_E_CPS_CLASS_DOES_NOT_EXIST */
/*  */
/*  MessageText: */
/*  */
/*   Requested CIP Class Dosn't Exist. */
/*  */
#define TLR_E_CPS_CLASS_DOES_NOT_EXIST   ((TLR_RESULT)0xC07C0017L)




#endif  /* __COMPONET_SLAVE_ERROR_H */

#ifndef __COMPONET_SLAVE_APS_ERROR_H
#define __COMPONET_SLAVE_APS_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  COMPONET SLAVE APS  ERROR codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_COMPONET_SLAVE_APS_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_COMPONET_SLAVE_APS_COMMAND_INVALID ((TLR_RESULT)0xC07D0001L)




#endif  /* __COMPONET_SLAVE_APS_ERROR_H */

#ifndef __DDL_DDL_ERROR_H
#define __DDL_DDL_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  DDL Task Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_DDL_DDL_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_DDL_DDL_COMMAND_INVALID    ((TLR_RESULT)0xC0410001L)




#endif  /* __DDL_DDL_ERROR_H */

#ifndef __DDL_ENPDDL_ERROR_H
#define __DDL_ENPDDL_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  ENPDDL Task Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_DDL_ENPDDL_COMMAND_INVALID ((TLR_RESULT)0xC0400001L)

/* //////// DDL errors: 0x0020 ... 0x003F                               ////////// */
/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_DDL_ADDRESS_MISMATCH_GAP */
/*  */
/*  MessageText: */
/*  */
/*   A DDL address error was detected (ADDRESS_MISMATCH or ADDRESS_GAP). */
/*  */
#define TLR_E_DDL_ENPDDL_DDL_ADDRESS_MISMATCH_GAP ((TLR_RESULT)0xC0400020L)

/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_DDL_WRONG_DATALENGTH */
/*  */
/*  MessageText: */
/*  */
/*   A DDL data length error was detected (WRONG_DATALENGTH). The given output data length from Ethernet master */
/*   is unequal to the detected output data length of all DDL slaves. */
/*  */
#define TLR_E_DDL_ENPDDL_DDL_WRONG_DATALENGTH ((TLR_RESULT)0xC0400021L)

/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_DDL_PARAMETER_REPEAT */
/*  */
/*  MessageText: */
/*  */
/*   An error has occured by sending DDL parameter. The parameter sending is repeated. */
/*  */
#define TLR_E_DDL_ENPDDL_DDL_PARAMETER_REPEAT ((TLR_RESULT)0xC0400022L)

/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_DDL_CAN_DL_SEND */
/*  */
/*  MessageText: */
/*  */
/*   An error has occured by sending CAN_DL frame(s). */
/*  */
#define TLR_E_DDL_ENPDDL_DDL_CAN_DL_SEND ((TLR_RESULT)0xC0400023L)

/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_DDL_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   The received DDL type is out of the valid range (4 ... 8). */
/*  */
#define TLR_E_DDL_ENPDDL_DDL_TYPE        ((TLR_RESULT)0xC0400024L)

/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_DDL_ADR */
/*  */
/*  MessageText: */
/*  */
/*   The received DDL address is out of the valid range (> 14). */
/*  */
#define TLR_E_DDL_ENPDDL_DDL_ADR         ((TLR_RESULT)0xC0400025L)

/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_DDL_ADR_AUTO */
/*  */
/*  MessageText: */
/*  */
/*   The received DDL address is unequal to zero by automatic addressing. */
/*  */
#define TLR_E_DDL_ENPDDL_DDL_ADR_AUTO    ((TLR_RESULT)0xC0400026L)

/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_DDL_ADR_MANUAL */
/*  */
/*  MessageText: */
/*  */
/*   The received DDL address is zero by manual addressing. */
/*  */
#define TLR_E_DDL_ENPDDL_DDL_ADR_MANUAL  ((TLR_RESULT)0xC0400027L)

/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_DDL_MASTER_INIT_FT */
/*  */
/*  MessageText: */
/*  */
/*   The received DDL frame type is unequal to "Parameter, Inputdaten" while DDL initialization. */
/*  */
#define TLR_E_DDL_ENPDDL_DDL_MASTER_INIT_FT ((TLR_RESULT)0xC0400028L)

/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_DDL_MASTER_INIT_FRAME_LEN */
/*  */
/*  MessageText: */
/*  */
/*   The received DDL frame length of config telegram is unequal to 8 (DDL initialization). */
/*  */
#define TLR_E_DDL_ENPDDL_DDL_MASTER_INIT_FRAME_LEN ((TLR_RESULT)0xC0400029L)

/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_DDL_MASTER_INIT_ADR_INCONSISTENT */
/*  */
/*  MessageText: */
/*  */
/*   The received DDL address in config telegram is unequal to the DDL address in the CAN-ID (DDL initialization). */
/*  */
#define TLR_E_DDL_ENPDDL_DDL_MASTER_INIT_ADR_INCONSISTENT ((TLR_RESULT)0xC040002AL)

/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_DDL_MASTER_INIT_TYPE_INCONSISTENT */
/*  */
/*  MessageText: */
/*  */
/*   The received DDL type in config telegram is unequal to the DDL type in the CAN-ID (DDL initialization). */
/*  */
#define TLR_E_DDL_ENPDDL_DDL_MASTER_INIT_TYPE_INCONSISTENT ((TLR_RESULT)0xC040002BL)

/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_DDL_MASTER_INIT_DATA_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Min. one of the received DDL data lengths in config telegram are to big (> 16) (DDL initialization). */
/*  */
#define TLR_E_DDL_ENPDDL_DDL_MASTER_INIT_DATA_LENGTH ((TLR_RESULT)0xC040002CL)

/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_DDL_MASTER_INIT_RESERVEDS */
/*  */
/*  MessageText: */
/*  */
/*   Min. one of the received reserved values in config telegram are unequal to zero (DDL initialization). */
/*  */
#define TLR_E_DDL_ENPDDL_DDL_MASTER_INIT_RESERVEDS ((TLR_RESULT)0xC040002DL)

/* //////// MID_CDG_PUT_CODE_DIAG() source code diagnostics:            ////////// */
/* ////////   - Infos         MID_CDG_LVL_INFO    : 0x0100 ... 0x01FF   ////////// */
/* ////////   - Warnings      MID_CDG_LVL_WARNING : 0x0200 ... 0x02FF   ////////// */
/* ////////   - Errors        MID_CDG_LVL_ERROR   : 0x0300 ... 0x03FF   ////////// */
/* ////////   - Fatal errors  MID_CDG_LVL_FATAL   : 0x0400 ... 0x04FF   ////////// */
/* ////////   Remark: Use always the Severity Error                     ////////// */
/* //////// MID_CDG_PUT_CODE_DIAG() Infos       : 0x0100 ... 0x01FF     ////////// */
/* //////// MID_CDG_PUT_CODE_DIAG() Warnings    : 0x0200 ... 0x02FF     ////////// */
/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_MID_CDG_CAN_DL_CNF */
/*  */
/*  MessageText: */
/*  */
/*   The CAN_DL task send confirmation is not yet received. The DDL state machine (DSM) waits any longer for */
/*   the send confirmation (Repeating with the corresponding timeout). ulUserParam is the actual DSM state. */
/*  */
#define TLR_E_DDL_ENPDDL_MID_CDG_CAN_DL_CNF ((TLR_RESULT)0xC0400200L)

/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_MID_CDG_UNKNOWN_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   The DDL state machine (DSM) has received an unknown and unexpected packet respectively. The packet will be */
/*   discarded. ulUserParam is the packet command ulCmd. */
/*  */
#define TLR_E_DDL_ENPDDL_MID_CDG_UNKNOWN_PACKET ((TLR_RESULT)0xC0400201L)

/* //////// MID_CDG_PUT_CODE_DIAG() Errors      : 0x0300 ... 0x03FF     ////////// */
/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_DDL_UNKNOWN_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Unknown DSM (DDL State machine) state. ulUserParam is the unknown DSM state. */
/*  */
#define TLR_E_DDL_ENPDDL_DDL_UNKNOWN_STATE ((TLR_RESULT)0xC0400300L)

/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_ECAT_READ_SYNC_MAN_NULL_PTR */
/*  */
/*  MessageText: */
/*  */
/*   The function EcatHal_ReadSyncMan() has delivered a NULL pointer. ulUserParam is the sync manager handle. */
/*  */
#define TLR_E_DDL_ENPDDL_ECAT_READ_SYNC_MAN_NULL_PTR ((TLR_RESULT)0xC0400301L)

/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_ECAT_WRITE_SYNC_MAN_NULL_PTR */
/*  */
/*  MessageText: */
/*  */
/*   The function EcatHal_WriteSyncMan() has delivered a NULL pointer. ulUserParam is the sync manager handle. */
/*  */
#define TLR_E_DDL_ENPDDL_ECAT_WRITE_SYNC_MAN_NULL_PTR ((TLR_RESULT)0xC0400302L)

/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_CAN_DL_CMD_DATA_IND_LEN */
/*  */
/*  MessageText: */
/*  */
/*   The CAN_DL_CMD_DATA_IND packet length ulLen is zero or not a multiple of the CAN frame size. */
/*   ulUserParam is the length ulLen. */
/*  */
#define TLR_E_DDL_ENPDDL_CAN_DL_CMD_DATA_IND_LEN ((TLR_RESULT)0xC0400303L)

/* //////// MID_CDG_PUT_CODE_DIAG() Fatal errors: 0x0400 ... 0x04FF     ////////// */
/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_MID_CDG_PACKET_NULL_PTR */
/*  */
/*  MessageText: */
/*  */
/*   The DDL state machine (DSM) has received a NULL pointer packet. The system will be stopped. */
/*   ulUserParam is the actual DSM state. */
/*  */
#define TLR_E_DDL_ENPDDL_MID_CDG_PACKET_NULL_PTR ((TLR_RESULT)0xC0400400L)

/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_MID_CDG_TLR_POOL_PACKET_GET */
/*  */
/*  MessageText: */
/*  */
/*   A TLR_POOL_PACKET_GET() error has occured. The system will be stopped. */
/*   ulUserParam is the error code. */
/*  */
#define TLR_E_DDL_ENPDDL_MID_CDG_TLR_POOL_PACKET_GET ((TLR_RESULT)0xC0400401L)

/*  */
/*  MessageId: TLR_E_DDL_ENPDDL_MID_CDG_TLR_QUE_SENDPACKET_FIFO */
/*  */
/*  MessageText: */
/*  */
/*   A TLR_QUE_SENDPACKET_FIFO() error has occured. The system will be stopped. */
/*   ulUserParam is the error code. */
/*  */
#define TLR_E_DDL_ENPDDL_MID_CDG_TLR_QUE_SENDPACKET_FIFO ((TLR_RESULT)0xC0400402L)




#endif  /* __DDL_ENPDDL_ERROR_H */

#ifndef __DEVNET_AP_ERROR_H
#define __DEVNET_AP_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  DeviceNet AP Task (Standard Dualport Application Task). */
/* /////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Error General: Codes 0x01 - 0xFF. */
/*  */
/*  MessageId: TLR_E_DEVNET_AP_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_DEVNET_AP_COMMAND_INVALID  ((TLR_RESULT)0xC05B0001L)

/*  */
/*  MessageId: TLR_E_DEVNET_AP_SERVICE_NOT_SUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   Service not supported. */
/*  */
#define TLR_E_DEVNET_AP_SERVICE_NOT_SUPPORTED ((TLR_RESULT)0xC05B0002L)

/*  */
/*  MessageId: TLR_E_DEVNET_AP_NO_DATA_BASE */
/*  */
/*  MessageText: */
/*  */
/*   No data base found. */
/*  */
#define TLR_E_DEVNET_AP_NO_DATA_BASE     ((TLR_RESULT)0xC05B0010L)

/*  */
/*  MessageId: TLR_E_DEVNET_AP_ERR_OPEN_DATA_BASE */
/*  */
/*  MessageText: */
/*  */
/*   Error while opening data base. */
/*  */
#define TLR_E_DEVNET_AP_ERR_OPEN_DATA_BASE ((TLR_RESULT)0xC05B0011L)

/*  */
/*  MessageId: TLR_E_DEVNET_AP_ERR_READ_DATA_BASE */
/*  */
/*  MessageText: */
/*  */
/*   Error while reading data base. */
/*  */
#define TLR_E_DEVNET_AP_ERR_READ_DATA_BASE ((TLR_RESULT)0xC05B0012L)

/*  */
/*  MessageId: TLR_E_DEVNET_AP_TABLE_NOT_FOUND */
/*  */
/*  MessageText: */
/*  */
/*   Table not fond in data base. */
/*  */
#define TLR_E_DEVNET_AP_TABLE_NOT_FOUND  ((TLR_RESULT)0xC05B0013L)

/*  */
/*  MessageId: TLR_E_DEVNET_AP_INVALID_DNM_DATA_BASE */
/*  */
/*  MessageText: */
/*  */
/*   No valid DeviceNet data base. */
/*  */
#define TLR_E_DEVNET_AP_INVALID_DNM_DATA_BASE ((TLR_RESULT)0xC05B0014L)

/*  */
/*  MessageId: TLR_E_DEVNET_AP_NON_EXCHANGE_SLAVE */
/*  */
/*  MessageText: */
/*  */
/*   No data exchange with at least one slave. */
/*  */
#define TLR_E_DEVNET_AP_NON_EXCHANGE_SLAVE ((TLR_RESULT)0xC05B0100L)

/*  */
/*  MessageId: TLR_E_DEVNET_AP_NON_EXCHANGE_ALL */
/*  */
/*  MessageText: */
/*  */
/*   No slave in data exchange. */
/*  */
#define TLR_E_DEVNET_AP_NON_EXCHANGE_ALL ((TLR_RESULT)0xC05B0101L)

/*  */
/*  MessageId: TLR_E_DEVNET_AP_ILLEGAL_PACKET_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Illegal packete length. */
/*  */
#define TLR_E_DEVNET_AP_ILLEGAL_PACKET_LENGTH ((TLR_RESULT)0xC05B0110L)

/*  */
/*  MessageId: TLR_E_DEVNET_AP_WRONG_WD_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Wrong watchdog. */
/*  */
#define TLR_E_DEVNET_AP_WRONG_WD_VALUE   ((TLR_RESULT)0xC05B0111L)




#endif  /* __DEVNET_AP_ERROR_H */

#ifndef __DEVNET_FAL_ERROR_H
#define __DEVNET_FAL_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  DeviceNet FAL Task (Fieldbus Application Layer). */
/* /////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Error General: Codes 0x01 - 0x0F. */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_DEVNET_FAL_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_DEVNET_FAL_COMMAND_INVALID ((TLR_RESULT)0xC0470001L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_SERVICE_NOT_SUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   Service not supported. */
/*  */
#define TLR_E_DEVNET_FAL_SERVICE_NOT_SUPPORTED ((TLR_RESULT)0xC0470002L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_RESET_IN_REQUEST */
/*  */
/*  MessageText: */
/*  */
/*   Reset is in request. */
/*  */
#define TLR_E_DEVNET_FAL_RESET_IN_REQUEST ((TLR_RESULT)0xC0470003L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_UNRECOVER_RESET_FAULT */
/*  */
/*  MessageText: */
/*  */
/*   Unrecoverable reset fault. */
/*  */
#define TLR_E_DEVNET_FAL_UNRECOVER_RESET_FAULT ((TLR_RESULT)0xC0470004L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Error Command: SetModeReq 0x10 - 0x1F. */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_DEVNET_FAL_SET_MODE_INVALID_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value for 'mode' of command. */
/*  */
#define TLR_E_DEVNET_FAL_SET_MODE_INVALID_MODE ((TLR_RESULT)0xC0470010L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_SET_MODE_ALREADY_IN_REQUEST */
/*  */
/*  MessageText: */
/*  */
/*   Command already in request. */
/*  */
#define TLR_E_DEVNET_FAL_SET_MODE_ALREADY_IN_REQUEST ((TLR_RESULT)0xC0470011L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Error Command: ClearConfigReq 0x20 - 0x2F.  */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_DEVNET_FAL_CLR_CONFIG_NOT_ALLOWED_IN_ACTUAL_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Not allowed to clear configuration in actual mode. */
/*  */
#define TLR_E_DEVNET_FAL_CLR_CONFIG_NOT_ALLOWED_IN_ACTUAL_STATE ((TLR_RESULT)0xC0470020L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Error Command: DownloadReq General codes 0x30 - 0x3F.                              */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_DEVNET_FAL_DOWNLOAD_NOT_ALLOWED_IN_ACTUAL_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Download not allowed in actual state. */
/*  */
#define TLR_E_DEVNET_FAL_DOWNLOAD_NOT_ALLOWED_IN_ACTUAL_STATE ((TLR_RESULT)0xC0470030L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_DOWNLOAD_INVALID_AREA_CODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value in 'AreaCode' of command. */
/*  */
#define TLR_E_DEVNET_FAL_DOWNLOAD_INVALID_AREA_CODE ((TLR_RESULT)0xC0470031L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_DOWNLOAD_INVALID_SEQUENCE */
/*  */
/*  MessageText: */
/*  */
/*   Sequence error. */
/*  */
#define TLR_E_DEVNET_FAL_DOWNLOAD_INVALID_SEQUENCE ((TLR_RESULT)0xC0470032L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_DOWNLOAD_TO_MUCH_DATA */
/*  */
/*  MessageText: */
/*  */
/*   To much data. */
/*  */
#define TLR_E_DEVNET_FAL_DOWNLOAD_TO_MUCH_DATA ((TLR_RESULT)0xC0470033L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_DOWNLOAD_TO_LESS_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Less data. */
/*  */
#define TLR_E_DEVNET_FAL_DOWNLOAD_TO_LESS_DATA ((TLR_RESULT)0xC0470034L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_DOWNLOAD_ALLREADY_CONFIGURED */
/*  */
/*  MessageText: */
/*  */
/*   DeviceNet Stack allready configured. */
/*  */
#define TLR_E_DEVNET_FAL_DOWNLOAD_ALLREADY_CONFIGURED ((TLR_RESULT)0xC0470035L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_DOWNLOAD_FAULTY_CONFIGURATION */
/*  */
/*  MessageText: */
/*  */
/*   DeviceNet Stack with an faulty configured loaded. */
/*  */
#define TLR_E_DEVNET_FAL_DOWNLOAD_FAULTY_CONFIGURATION ((TLR_RESULT)0xC0470036L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Error Command: DownloadReq ValidetParameter 0x100 - 0x1FF. */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_DEVNET_FAL_BAUDRATE_OUT_OF_RANGE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Baudrate. */
/*  */
#define TLR_E_DEVNET_FAL_BAUDRATE_OUT_OF_RANGE ((TLR_RESULT)0xC0470100L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_MAC_ID_OUT_OF_RANGE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid MAC Id. */
/*  */
#define TLR_E_DEVNET_FAL_MAC_ID_OUT_OF_RANGE ((TLR_RESULT)0xC0470101L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_ADR_DOUBLE */
/*  */
/*  MessageText: */
/*  */
/*   Slave already configured. */
/*  */
#define TLR_E_DEVNET_FAL_ADR_DOUBLE      ((TLR_RESULT)0xC0470102L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_DATA_SET_FIELD_LEN */
/*  */
/*  MessageText: */
/*  */
/*   Invalid length of slave parameter set. */
/*  */
#define TLR_E_DEVNET_FAL_DATA_SET_FIELD_LEN ((TLR_RESULT)0xC0470103L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_PRED_MST_SL_ADD_LEN */
/*  */
/*  MessageText: */
/*  */
/*   Invalid length of address table in parameter set. */
/*  */
#define TLR_E_DEVNET_FAL_PRED_MST_SL_ADD_LEN ((TLR_RESULT)0xC0470104L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_PRED_MSTSL_CFG_FIELD_LEN */
/*  */
/*  MessageText: */
/*  */
/*   Invalid length of predefined master slave config table in parameter set. */
/*  */
#define TLR_E_DEVNET_FAL_PRED_MSTSL_CFG_FIELD_LEN ((TLR_RESULT)0xC0470105L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_PRED_MST_SL_ADD_TAB_INCONS */
/*  */
/*  MessageText: */
/*  */
/*   Inconsitency between addresstable and configured connection length. */
/*  */
#define TLR_E_DEVNET_FAL_PRED_MST_SL_ADD_TAB_INCONS ((TLR_RESULT)0xC0470106L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_EXPL_PRM_FIELD_LEN */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Length of explicit parameter data in slave parameter set. */
/*  */
#define TLR_E_DEVNET_FAL_EXPL_PRM_FIELD_LEN ((TLR_RESULT)0xC0470107L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_PRED_MSTSL_CFG_ADD_INPUT_INCONS */
/*  */
/*  MessageText: */
/*  */
/*   Inconsistency between number of input address offsets and configured input modules. */
/*  */
#define TLR_E_DEVNET_FAL_PRED_MSTSL_CFG_ADD_INPUT_INCONS ((TLR_RESULT)0xC0470108L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_PRED_MSTSL_CFG_ADD_OUTPUT_INCONS */
/*  */
/*  MessageText: */
/*  */
/*   Inconsistency between number of output address offsets and configured output modules. */
/*  */
#define TLR_E_DEVNET_FAL_PRED_MSTSL_CFG_ADD_OUTPUT_INCONS ((TLR_RESULT)0xC0470109L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_UNKNOWN_DATA_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Unknown data type in of the module definition. */
/*  */
#define TLR_E_DEVNET_FAL_UNKNOWN_DATA_TYPE ((TLR_RESULT)0xC047010AL)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_MODULE_DATA_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid data size in of the module definition. */
/*  */
#define TLR_E_DEVNET_FAL_MODULE_DATA_SIZE ((TLR_RESULT)0xC047010BL)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_OUTPUT_OFF_RANGE */
/*  */
/*  MessageText: */
/*  */
/*   Output address offset exceeds the maximum allowed area. */
/*  */
#define TLR_E_DEVNET_FAL_OUTPUT_OFF_RANGE ((TLR_RESULT)0xC047010CL)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_INPUT_OFF_RANGE */
/*  */
/*  MessageText: */
/*  */
/*   Input address offset exceeds the maximum allowed area. */
/*  */
#define TLR_E_DEVNET_FAL_INPUT_OFF_RANGE ((TLR_RESULT)0xC047010DL)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_WRONG_TYPE_OF_CONNECTION */
/*  */
/*  MessageText: */
/*  */
/*   Invalid type of connection configured. */
/*  */
#define TLR_E_DEVNET_FAL_WRONG_TYPE_OF_CONNECTION ((TLR_RESULT)0xC047010EL)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_TYPE_CONNECTION_REDEFINITION */
/*  */
/*  MessageText: */
/*  */
/*   Redifinition of connection type. */
/*  */
#define TLR_E_DEVNET_FAL_TYPE_CONNECTION_REDEFINITION ((TLR_RESULT)0xC047010FL)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_EXP_PACKET_LESS_PROD_INHIBIT */
/*  */
/*  MessageText: */
/*  */
/*   Configured 'Production Inhibit Time' is smaller then 'Expected Packet Rate'. */
/*  */
#define TLR_E_DEVNET_FAL_EXP_PACKET_LESS_PROD_INHIBIT ((TLR_RESULT)0xC0470110L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_PRM_FIELD_LEN_INCONSISTENT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid length of parameter field in slave parameter set. */
/*  */
#define TLR_E_DEVNET_FAL_PRM_FIELD_LEN_INCONSISTENT ((TLR_RESULT)0xC0470111L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_SET_BAUDRATE_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Error while setting baudrate. */
/*  */
#define TLR_E_DEVNET_FAL_SET_BAUDRATE_FAIL ((TLR_RESULT)0xC0470112L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_REG_FRAG_TIMEOUT_OUT_OF_RANGE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value of fragmentation timeout. */
/*  */
#define TLR_E_DEVNET_FAL_REG_FRAG_TIMEOUT_OUT_OF_RANGE ((TLR_RESULT)0xC0470113L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_PRM_OUT_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Out of memory for configuration data. */
/*  */
#define TLR_E_DEVNET_FAL_PRM_OUT_MEMORY  ((TLR_RESULT)0xC0470114L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Error Command:  GetSetAttributeReq 0x200 - 0x2FF */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_DEVNET_FAL_CON_NA */
/*  */
/*  MessageText: */
/*  */
/*   No response from device. */
/*  */
#define TLR_E_DEVNET_FAL_CON_NA          ((TLR_RESULT)0xC0470211L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_CON_MDA */
/*  */
/*  MessageText: */
/*  */
/*   To much data received. */
/*  */
#define TLR_E_DEVNET_FAL_CON_MDA         ((TLR_RESULT)0xC0470215L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_CON_LE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid length of requested service. */
/*  */
#define TLR_E_DEVNET_FAL_CON_LE          ((TLR_RESULT)0xC0470233L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_CON_AD */
/*  */
/*  MessageText: */
/*  */
/*   Another service still active. */
/*  */
#define TLR_E_DEVNET_FAL_CON_AD          ((TLR_RESULT)0xC0470236L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_CON_SE */
/*  */
/*  MessageText: */
/*  */
/*   Sequence error in response sequence. */
/*  */
#define TLR_E_DEVNET_FAL_CON_SE          ((TLR_RESULT)0xC0470239L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_CON_OC */
/*  */
/*  MessageText: */
/*  */
/*   Explicit Message Handler is occupied. */
/*  */
#define TLR_E_DEVNET_FAL_CON_OC          ((TLR_RESULT)0xC0470240L)

/*  */
/*  MessageId: TLR_E_DEVNET_FAL_CON_ERR_RES */
/*  */
/*  MessageText: */
/*  */
/*   Service Error Response. */
/*  */
#define TLR_E_DEVNET_FAL_CON_ERR_RES     ((TLR_RESULT)0xC0470294L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Error Command: InitReq */
/* /////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Error : Data echange related */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_DEVNET_FAL_SLAVE_NOEXCHANGE */
/*  */
/*  MessageText: */
/*  */
/*   Service Error Response. */
/*  */
#define TLR_E_DEVNET_FAL_SLAVE_NOEXCHANGE ((TLR_RESULT)0xC0471000L)




#endif  /* __DEVNET_FAL_ERROR_H */

#ifndef __DF1_STACK_ERROR_H
#define __DF1_STACK_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  DF1 Stack  ERROR codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_DF1_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_DF1_COMMAND_INVALID        ((TLR_RESULT)0xC08D0001L)




#endif  /* __DF1_STACK_ERROR_H */

#ifndef __DF1_AP_ERROR_H
#define __DF1_AP_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  DF1 Aplication  ERROR codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_DF1_AP_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_DF1_AP_COMMAND_INVALID     ((TLR_RESULT)0xC08E0001L)




#endif  /* __DF1_AP_ERROR_H */

#ifndef __DNS_AP_ERROR_H
#define __DNS_AP_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  DNS AP Task (Dualport Application). */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_DNS_APS_NOTREGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   User Application not registered. */
/*  */
#define TLR_E_DNS_APS_NOTREGISTERED      ((TLR_RESULT)0xC0630000L)

/*  */
/*  MessageId: TLR_E_DNS_APS_ALREADY_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   User Application already registered. */
/*  */
#define TLR_E_DNS_APS_ALREADY_REGISTERED ((TLR_RESULT)0xC0630001L)

/*  */
/*  MessageId: TLR_E_DNS_APS_PACKET_LENGTH_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid packet length for register/unregister command. */
/*  */
#define TLR_E_DNS_APS_PACKET_LENGTH_INVALID ((TLR_RESULT)0xC0630002L)

/*  */
/*  MessageId: TLR_E_DNS_APS_ACCESS_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Unregister application queue access failed. */
/*  */
#define TLR_E_DNS_APS_ACCESS_FAIL        ((TLR_RESULT)0xC0630003L)

/*  */
/*  MessageId: TLR_E_DNS_APS_CONFIG_LOCK */
/*  */
/*  MessageText: */
/*  */
/*   Function not allowed because configuration locked. */
/*  */
#define TLR_E_DNS_APS_CONFIG_LOCK        ((TLR_RESULT)0xC0630004L)

/*  */
/*  MessageId: TLR_E_DNS_AP_NO_DATA_BASE */
/*  */
/*  MessageText: */
/*  */
/*   Not data base available. */
/*  */
#define TLR_E_DNS_AP_NO_DATA_BASE        ((TLR_RESULT)0xC0630005L)

/*  */
/*  MessageId: TLR_E_DNS_AP_OPEN_DATA_BASE */
/*  */
/*  MessageText: */
/*  */
/*   Error open database. */
/*  */
#define TLR_E_DNS_AP_OPEN_DATA_BASE      ((TLR_RESULT)0xC0630006L)

/*  */
/*  MessageId: TLR_E_DNS_AP_IV_DNS_DATA_BASE */
/*  */
/*  MessageText: */
/*  */
/*   Not a valid DeviceNet Slave database. */
/*  */
#define TLR_E_DNS_AP_IV_DNS_DATA_BASE    ((TLR_RESULT)0xC0630007L)

/*  */
/*  MessageId: TLR_E_DNS_AP_READ_DATA_BASE_TBL_GLB */
/*  */
/*  MessageText: */
/*  */
/*   Error while rading table GLOBAL. */
/*  */
#define TLR_E_DNS_AP_READ_DATA_BASE_TBL_GLB ((TLR_RESULT)0xC0630008L)

/*  */
/*  MessageId: TLR_E_DNS_AP_OPEN_DATA_BASE_TBL_GLB */
/*  */
/*  MessageText: */
/*  */
/*   Error while open table GLOBAL. */
/*  */
#define TLR_E_DNS_AP_OPEN_DATA_BASE_TBL_GLB ((TLR_RESULT)0xC0630009L)

/*  */
/*  MessageId: TLR_E_DNS_AP_OPEN_DATA_BASE_TBL_DNS */
/*  */
/*  MessageText: */
/*  */
/*   Error while open table DNS. */
/*  */
#define TLR_E_DNS_AP_OPEN_DATA_BASE_TBL_DNS ((TLR_RESULT)0xC063000AL)

/*  */
/*  MessageId: TLR_E_DNS_AP_READ_DATA_BASE_TBL_DNS */
/*  */
/*  MessageText: */
/*  */
/*   Error while reading table DNS. */
/*  */
#define TLR_E_DNS_AP_READ_DATA_BASE_TBL_DNS ((TLR_RESULT)0xC063000BL)




#endif  /* __DNS_AP_ERROR_H */

#ifndef __DNS_FAL_ERROR_H
#define __DNS_FAL_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  DeviceNet Slave FAL Task (Fieldbus Application Layer). */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_DNS_FAL_DUPLICATE_MAC_ID */
/*  */
/*  MessageText: */
/*  */
/*   Duplicate MAC ID found. */
/*  */
#define TLR_E_DNS_FAL_DUPLICATE_MAC_ID   ((TLR_RESULT)0xC0620001L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_INIT_TO_LESS_DATA */
/*  */
/*  MessageText: */
/*  */
/*   To less data for init command. */
/*  */
#define TLR_E_DNS_FAL_INIT_TO_LESS_DATA  ((TLR_RESULT)0xC0620002L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_FUNCTION_NOT_SUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   Function not supported. */
/*  */
#define TLR_E_DNS_FAL_FUNCTION_NOT_SUPPORTED ((TLR_RESULT)0xC0620003L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_COMMAND_ALLREADY_IN_REQUEST */
/*  */
/*  MessageText: */
/*  */
/*   Command allready in request. */
/*  */
#define TLR_E_DNS_FAL_COMMAND_ALLREADY_IN_REQUEST ((TLR_RESULT)0xC0620004L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_PRM_ERR_CODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter in Init Stack request. */
/*  */
#define TLR_E_DNS_FAL_PRM_ERR_CODE       ((TLR_RESULT)0xC0620006L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_BAUDRATE_OUT_RANGE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Baudrate entered in Init Stack request. */
/*  */
#define TLR_E_DNS_FAL_BAUDRATE_OUT_RANGE ((TLR_RESULT)0xC0620007L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_MAC_ID_OUT_RANGE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid MAC ID entered in Init Stack request. */
/*  */
#define TLR_E_DNS_FAL_MAC_ID_OUT_RANGE   ((TLR_RESULT)0xC0620008L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_INVALID_PRODUCT_LEN */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Product Name Length entered in Init Stack request.. */
/*  */
#define TLR_E_DNS_FAL_INVALID_PRODUCT_LEN ((TLR_RESULT)0xC0620009L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_INVALID_PRODUCED_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Produced Size entered in Init Stack request. */
/*  */
#define TLR_E_DNS_FAL_INVALID_PRODUCED_SIZE ((TLR_RESULT)0xC062000AL)

/*  */
/*  MessageId: TLR_E_DNS_FAL_INVALID_CONSUMED_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Consumed Size entered in Init Stack request. */
/*  */
#define TLR_E_DNS_FAL_INVALID_CONSUMED_SIZE ((TLR_RESULT)0xC062000BL)

/*  */
/*  MessageId: TLR_E_DNS_FAL_INVALID_MAJOR_REV */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Major Rev entered in Init Stack request. */
/*  */
#define TLR_E_DNS_FAL_INVALID_MAJOR_REV  ((TLR_RESULT)0xC062000CL)

/*  */
/*  MessageId: TLR_E_DNS_FAL_INVALID_MINOR_REV */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Minor Rev entered in Init Stack request. */
/*  */
#define TLR_E_DNS_FAL_INVALID_MINOR_REV  ((TLR_RESULT)0xC062000DL)

/*  */
/*  MessageId: TLR_E_DNS_FAL_INVALID_VENDOR_ID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Vendor ID entered in Init Stack request. */
/*  */
#define TLR_E_DNS_FAL_INVALID_VENDOR_ID  ((TLR_RESULT)0xC062000EL)

/*  */
/*  MessageId: TLR_E_DNS_FAL_INVALID_PRODUCT_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Product Type entered in Init Stack request. */
/*  */
#define TLR_E_DNS_FAL_INVALID_PRODUCT_TYPE ((TLR_RESULT)0xC062000FL)

/*  */
/*  MessageId: TLR_E_DNS_FAL_INVALID_PRODUCT_CODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Product Code entered in Init Stack request. */
/*  */
#define TLR_E_DNS_FAL_INVALID_PRODUCT_CODE ((TLR_RESULT)0xC0620010L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_ALREADY_CONFIGURED */
/*  */
/*  MessageText: */
/*  */
/*   Slave is already configured. */
/*  */
#define TLR_E_DNS_FAL_ALREADY_CONFIGURED ((TLR_RESULT)0xC0620011L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_SET_MODE_INVALID_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid operation mode during Set Mode Request. */
/*  */
#define TLR_E_DNS_FAL_SET_MODE_INVALID_MODE ((TLR_RESULT)0xC0620012L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_SET_MODE_ALLREADY_IN_REQUEST */
/*  */
/*  MessageText: */
/*  */
/*   Slave is currently in the mode requested. */
/*  */
#define TLR_E_DNS_FAL_SET_MODE_ALLREADY_IN_REQUEST ((TLR_RESULT)0xC0620013L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_GET_STATUS_INVALID_STATUS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid paramter in Get Status Command. */
/*  */
#define TLR_E_DNS_FAL_GET_STATUS_INVALID_STATUS ((TLR_RESULT)0xC0620014L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_UPDATE_IO_INVALID_IN_LEN */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Input Length specified in Update I/O Command. */
/*  */
#define TLR_E_DNS_FAL_UPDATE_IO_INVALID_IN_LEN ((TLR_RESULT)0xC0620015L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_UPDATE_IO_INVALID_OUT_LEN */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Output Length specified in Update I/O Command. */
/*  */
#define TLR_E_DNS_FAL_UPDATE_IO_INVALID_OUT_LEN ((TLR_RESULT)0xC0620016L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_UPDATE_IO_INVALID_OUT_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Output Offset specified in Update I/O Command. */
/*  */
#define TLR_E_DNS_FAL_UPDATE_IO_INVALID_OUT_OFFSET ((TLR_RESULT)0xC0620017L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_UPDATE_IO_INVALID_IN_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Input Offset specified in Update I/O Command. */
/*  */
#define TLR_E_DNS_FAL_UPDATE_IO_INVALID_IN_OFFSET ((TLR_RESULT)0xC0620018L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_SET_INPUT_INVALID_IN_LEN */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Input Length specified in Set Input Command. */
/*  */
#define TLR_E_DNS_FAL_SET_INPUT_INVALID_IN_LEN ((TLR_RESULT)0xC0620019L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_SET_INPUT_INVALID_IN_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Input Offset specified in Set Input Command. */
/*  */
#define TLR_E_DNS_FAL_SET_INPUT_INVALID_IN_OFFSET ((TLR_RESULT)0xC062001AL)

/*  */
/*  MessageId: TLR_E_DNS_FAL_GET_OUTPUT_INVALID_OUT_LEN */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Output Length specified in Get Output Command. */
/*  */
#define TLR_E_DNS_FAL_GET_OUTPUT_INVALID_OUT_LEN ((TLR_RESULT)0xC062001BL)

/*  */
/*  MessageId: TLR_E_DNS_FAL_GET_OUTPUT_INVALID_OUT_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Output Offset specified in Get Output Command. */
/*  */
#define TLR_E_DNS_FAL_GET_OUTPUT_INVALID_OUT_OFFSET ((TLR_RESULT)0xC062001CL)

/*  */
/*  MessageId: TLR_E_DNS_FAL_DOWNLOAD_INVALID_AREA_CODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid download area specified. */
/*  */
#define TLR_E_DNS_FAL_DOWNLOAD_INVALID_AREA_CODE ((TLR_RESULT)0xC062001EL)

/*  */
/*  MessageId: TLR_E_DNS_FAL_DOWNLOAD_INVALID_SEQUENCE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Download Sequence. */
/*  */
#define TLR_E_DNS_FAL_DOWNLOAD_INVALID_SEQUENCE ((TLR_RESULT)0xC062001FL)

/*  */
/*  MessageId: TLR_E_DNS_FAL_DOWNLOAD_TO_MUCH_DATA */
/*  */
/*  MessageText: */
/*  */
/*   To much data received. */
/*  */
#define TLR_E_DNS_FAL_DOWNLOAD_TO_MUCH_DATA ((TLR_RESULT)0xC0620020L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_DOWNLOAD_TO_LESS_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Not enough data received during the download. */
/*  */
#define TLR_E_DNS_FAL_DOWNLOAD_TO_LESS_DATA ((TLR_RESULT)0xC0620021L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_NO_CONFIGURATION */
/*  */
/*  MessageText: */
/*  */
/*   No configuration. */
/*  */
#define TLR_E_DNS_FAL_NO_CONFIGURATION   ((TLR_RESULT)0xC0620022L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_BUS_OFF_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Network error BUS OFF detected. */
/*  */
#define TLR_E_DNS_FAL_BUS_OFF_STATE      ((TLR_RESULT)0xC0620023L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_NO_NETWORK */
/*  */
/*  MessageText: */
/*  */
/*   No network access. */
/*  */
#define TLR_E_DNS_FAL_NO_NETWORK         ((TLR_RESULT)0xC0620024L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_BUS_STOP */
/*  */
/*  MessageText: */
/*  */
/*   Communication not released by application (BUS Stop). */
/*  */
#define TLR_E_DNS_FAL_BUS_STOP           ((TLR_RESULT)0xC0620025L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_NO_COMMUNICATION */
/*  */
/*  MessageText: */
/*  */
/*   No communication. */
/*  */
#define TLR_E_DNS_FAL_NO_COMMUNICATION   ((TLR_RESULT)0xC0620026L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_SERVICE_DATA_LENGTH_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid length of service data. */
/*  */
#define TLR_E_DNS_FAL_SERVICE_DATA_LENGTH_INVALID ((TLR_RESULT)0xC0620027L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_USER_OBJ_CONFIGURED */
/*  */
/*  MessageText: */
/*  */
/*   User object already configured. */
/*  */
#define TLR_E_DNS_FAL_USER_OBJ_CONFIGURED ((TLR_RESULT)0xC0620028L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_USER_OBJ_LOCKED */
/*  */
/*  MessageText: */
/*  */
/*   User object is locked and can not be passed through. */
/*  */
#define TLR_E_DNS_FAL_USER_OBJ_LOCKED    ((TLR_RESULT)0xC0620029L)

/*  */
/*  MessageId: TLR_E_DNS_FAL_USER_OBJ_ALREADY_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   User object has already been registered. */
/*  */
#define TLR_E_DNS_FAL_USER_OBJ_ALREADY_REGISTERED ((TLR_RESULT)0xC062002AL)

/*  */
/*  MessageId: TLR_E_DNS_FAL_USER_OBJ_NOT_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   User object has not been registered. */
/*  */
#define TLR_E_DNS_FAL_USER_OBJ_NOT_REGISTERED ((TLR_RESULT)0xC062002BL)




#endif  /* __DNS_FAL_ERROR_H */

#ifndef __DPM_OD2_ERROR_H
#define __DPM_OD2_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Object Dictionary V2 DPM Adapter Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_DPM_OD2_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_DPM_OD2_COMMAND_INVALID    ((TLR_RESULT)0xC0480001L)




#endif  /* __DPM_OD2_ERROR_H */

#ifndef __DRV_EDD_ERROR_H
#define __DRV_EDD_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  DRV EDD Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_DRV_EDD_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_DRV_EDD_COMMAND_INVALID    ((TLR_RESULT)0xC00F0001L)




#endif  /* __DRV_EDD_ERROR_H */

#ifndef __ECAT_DPM_ERROR_H
#define __ECAT_DPM_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Ecat Slave DPM Application  Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_ECAT_DPM_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_ECAT_DPM_COMMAND_INVALID   ((TLR_RESULT)0xC04C0001L)

/*  */
/*  MessageId: TLR_E_ECAT_DPM_INVALID_IO_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid I/O size has been tried to be configured. */
/*  */
#define TLR_E_ECAT_DPM_INVALID_IO_SIZE   ((TLR_RESULT)0xC04C0002L)

/*  */
/*  MessageId: TLR_E_ECAT_DPM_WATCHDOG_TIMEOUT_EXPIRED */
/*  */
/*  MessageText: */
/*  */
/*   Watchdog timeout expired. */
/*  */
#define TLR_E_ECAT_DPM_WATCHDOG_TIMEOUT_EXPIRED ((TLR_RESULT)0xC04C0003L)

/*  */
/*  MessageId: TLR_E_ECAT_DPM_INVALID_WATCHDOG_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Watchdog time has been tried to be configured. */
/*  */
#define TLR_E_ECAT_DPM_INVALID_WATCHDOG_TIME ((TLR_RESULT)0xC04C0004L)

/*  */
/*  MessageId: TLR_E_ECAT_DPM_INVALID_IO_SIZE_2 */
/*  */
/*  MessageText: */
/*  */
/*   Invalid I/O size has been tried to be configured. */
/*  */
#define TLR_E_ECAT_DPM_INVALID_IO_SIZE_2 ((TLR_RESULT)0xC04C0005L)

/*  */
/*  MessageId: TLR_E_ECAT_DPM_INVALID_IO_SIZE_3 */
/*  */
/*  MessageText: */
/*  */
/*   Invalid I/O size has been tried to be configured. */
/*  */
#define TLR_E_ECAT_DPM_INVALID_IO_SIZE_3 ((TLR_RESULT)0xC04C0006L)

/*  */
/*  MessageId: TLR_E_ECAT_DPM_INVALID_IO_SIZE_4 */
/*  */
/*  MessageText: */
/*  */
/*   Invalid I/O size has been tried to be configured. */
/*  */
#define TLR_E_ECAT_DPM_INVALID_IO_SIZE_4 ((TLR_RESULT)0xC04C0007L)

/*  */
/*  MessageId: TLR_E_ECAT_DPM_BUS_SYNCHRONOUS_NOT_SUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   Bus Synchronous Mode is not supported. */
/*  */
#define TLR_E_ECAT_DPM_BUS_SYNCHRONOUS_NOT_SUPPORTED ((TLR_RESULT)0xC04C0008L)

/*  */
/*  MessageId: TLR_E_ECAT_DPM_UPDATE_CFG_SM2_UPDATE_PARAMETER_IS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Sm2 Update Parameter is invalid. */
/*  */
#define TLR_E_ECAT_DPM_UPDATE_CFG_SM2_UPDATE_PARAMETER_IS_INVALID ((TLR_RESULT)0xC04C0009L)

/*  */
/*  MessageId: TLR_E_ECAT_DPM_UPDATE_CFG_SM3_UPDATE_PARAMETER_IS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Sm2 Update Parameter is invalid. */
/*  */
#define TLR_E_ECAT_DPM_UPDATE_CFG_SM3_UPDATE_PARAMETER_IS_INVALID ((TLR_RESULT)0xC04C000AL)

/*  */
/*  MessageId: TLR_E_ECAT_DPM_UPDATE_CFG_BUS_SYNC_UPDATE_PARAMETER_IS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Bus-Sync Update Parameter is invalid. */
/*  */
#define TLR_E_ECAT_DPM_UPDATE_CFG_BUS_SYNC_UPDATE_PARAMETER_IS_INVALID ((TLR_RESULT)0xC04C000BL)




#endif  /* __ECAT_DPM_ERROR_H */

#ifndef __ECAT_ERROR_H
#define __ECAT_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  EtherCAT Base stack error codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_ECAT_BASE_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_ECAT_BASE_COMMAND_INVALID  ((TLR_RESULT)0xC0200001L)

/*  */
/*  MessageId: TLR_W_ECAT_BASE_MAILBOX_NOT_ACTIVE */
/*  */
/*  MessageText: */
/*  */
/*   Mailbox communication is not active. */
/*  */
#define TLR_W_ECAT_BASE_MAILBOX_NOT_ACTIVE ((TLR_RESULT)0x80200002L)

/*  */
/*  MessageId: TLR_W_ECAT_BASE_NO_MAILBOX_TYPE_RECEIVER_CONNECTED */
/*  */
/*  MessageText: */
/*  */
/*   No receiver for mailbox type connected. */
/*  */
#define TLR_W_ECAT_BASE_NO_MAILBOX_TYPE_RECEIVER_CONNECTED ((TLR_RESULT)0x80200003L)

/*  */
/*  MessageId: TLR_E_ECAT_BASE_MBX_INVALID_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Mailbox type id. */
/*  */
#define TLR_E_ECAT_BASE_MBX_INVALID_TYPE ((TLR_RESULT)0xC0200004L)

/*  */
/*  MessageId: TLR_E_ECAT_BASE_MBX_ALREADY_CONNECTED */
/*  */
/*  MessageText: */
/*  */
/*   Mailbox type is already connected to listener. */
/*  */
#define TLR_E_ECAT_BASE_MBX_ALREADY_CONNECTED ((TLR_RESULT)0xC0200005L)

/*  */
/*  MessageId: TLR_E_ECAT_BASE_TOO_MANY_ALCONTROL_RECEIVERS */
/*  */
/*  MessageText: */
/*  */
/*   Too many ALcontrol receivers registered. */
/*  */
#define TLR_E_ECAT_BASE_TOO_MANY_ALCONTROL_RECEIVERS ((TLR_RESULT)0xC0200006L)

/*  */
/*  MessageId: TLR_E_ECAT_BASE_QUEUE_DOES_NOT_EXIST */
/*  */
/*  MessageText: */
/*  */
/*   Queue does not exist. */
/*  */
#define TLR_E_ECAT_BASE_QUEUE_DOES_NOT_EXIST ((TLR_RESULT)0xC0200007L)

/*  */
/*  MessageId: TLR_E_ECAT_BASE_MBX_PACKET_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Queue does not exist. */
/*  */
#define TLR_E_ECAT_BASE_MBX_PACKET_TOO_LONG ((TLR_RESULT)0xC0200008L)

/*  */
/*  MessageId: TLR_E_ECAT_BASE_NO_QUEUE_REGISTERED_FOR_MBX_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   No queue registered for mailbox type. */
/*  */
#define TLR_E_ECAT_BASE_NO_QUEUE_REGISTERED_FOR_MBX_TYPE ((TLR_RESULT)0xC0200009L)

/*  */
/*  MessageId: TLR_E_ECAT_BASE_DEADSLAVE_CALLBACK_TABLE_FULL */
/*  */
/*  MessageText: */
/*  */
/*   Dead slave callback table full. */
/*  */
#define TLR_E_ECAT_BASE_DEADSLAVE_CALLBACK_TABLE_FULL ((TLR_RESULT)0xC020000AL)

/*  */
/*  MessageId: TLR_E_ECAT_BASE_NO_SUCH_ETHERCAT_STACK_NAME */
/*  */
/*  MessageText: */
/*  */
/*   No EtherCAT stack with that name. */
/*  */
#define TLR_E_ECAT_BASE_NO_SUCH_ETHERCAT_STACK_NAME ((TLR_RESULT)0xC020000BL)

/*  */
/*  MessageId: TLR_E_ECAT_BASE_DUPLICATE_ETHERCAT_STACK_NAME */
/*  */
/*  MessageText: */
/*  */
/*   Duplicate EtherCAT stack name. */
/*  */
#define TLR_E_ECAT_BASE_DUPLICATE_ETHERCAT_STACK_NAME ((TLR_RESULT)0xC020000CL)

/*  */
/*  MessageId: TLR_E_ECAT_BASE_DYNAMICDATA_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   EtherCAT stack dynamic data invalid. */
/*  */
#define TLR_E_ECAT_BASE_DYNAMICDATA_INVALID ((TLR_RESULT)0xC020000DL)

/*  */
/*  MessageId: TLR_E_ECAT_BASE_INVALID_TIMEOUT_PARAMS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid timeout parameters. */
/*  */
#define TLR_E_ECAT_BASE_INVALID_TIMEOUT_PARAMS ((TLR_RESULT)0xC020000EL)

/*  */
/*  MessageId: TLR_E_ECAT_BASE_NOT_ENOUGH_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Not enough memory. */
/*  */
#define TLR_E_ECAT_BASE_NOT_ENOUGH_MEMORY ((TLR_RESULT)0xC020000FL)

/*  */
/*  MessageId: TLR_E_ECAT_BASE_INVALID_ALSTATUS_STATE_CHANGE */
/*  */
/*  MessageText: */
/*  */
/*   Not enough memory. */
/*  */
#define TLR_E_ECAT_BASE_INVALID_ALSTATUS_STATE_CHANGE ((TLR_RESULT)0xC0200010L)

/*  */
/*  MessageId: TLR_E_ECAT_BASE_NO_DATA_AVAILABLE */
/*  */
/*  MessageText: */
/*  */
/*   Not enough memory. */
/*  */
#define TLR_E_ECAT_BASE_NO_DATA_AVAILABLE ((TLR_RESULT)0xC0200011L)

/*  */
/*  MessageId: TLR_E_ECAT_BASE_ALREADY_CONNECTED */
/*  */
/*  MessageText: */
/*  */
/*   Not enough memory. */
/*  */
#define TLR_E_ECAT_BASE_ALREADY_CONNECTED ((TLR_RESULT)0xC0200012L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  EtherCAT CoE stack error codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_ECAT_COE_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_ECAT_COE_COMMAND_INVALID   ((TLR_RESULT)0xC0210001L)

/*  */
/*  MessageId: TLR_W_ECAT_COE_NO_SERVICE_RECEIVER_CONNECTED */
/*  */
/*  MessageText: */
/*  */
/*   No CoE Service receiver connected. */
/*  */
#define TLR_W_ECAT_COE_NO_SERVICE_RECEIVER_CONNECTED ((TLR_RESULT)0x80210002L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_INVALID_SERVICE_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid CoE service type id. */
/*  */
#define TLR_E_ECAT_COE_INVALID_SERVICE_TYPE ((TLR_RESULT)0xC0210003L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_ALREADY_CONNECTED */
/*  */
/*  MessageText: */
/*  */
/*   CoE service already connected. */
/*  */
#define TLR_E_ECAT_COE_ALREADY_CONNECTED ((TLR_RESULT)0xC0210004L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_QUEUE_DOES_NOT_EXIST */
/*  */
/*  MessageText: */
/*  */
/*   Queue does not exist. */
/*  */
#define TLR_E_ECAT_COE_QUEUE_DOES_NOT_EXIST ((TLR_RESULT)0xC0210005L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_PDO_INVALID_ID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid PDO Id. */
/*  */
#define TLR_E_ECAT_COE_PDO_INVALID_ID    ((TLR_RESULT)0xC0210006L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_PDO_UNDEFINED_ID */
/*  */
/*  MessageText: */
/*  */
/*   Undefined PDO Id. */
/*  */
#define TLR_E_ECAT_COE_PDO_UNDEFINED_ID  ((TLR_RESULT)0xC0210007L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_PDO_MAPPING_FAILED_DUE_TO_MISSING_OBJECT */
/*  */
/*  MessageText: */
/*  */
/*   PDO Mapping failed due to missing object. */
/*  */
#define TLR_E_ECAT_COE_PDO_MAPPING_FAILED_DUE_TO_MISSING_OBJECT ((TLR_RESULT)0xC0210008L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_PROTOCOL_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   SDO Protocol timeout. */
/*  */
#define TLR_E_ECAT_COE_SDO_PROTOCOL_TIMEOUT ((TLR_RESULT)0xC0210009L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_SCS_SPECIFIER_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Client/Server command specifier not valid or unknown. */
/*  */
#define TLR_E_ECAT_COE_SDO_SCS_SPECIFIER_INVALID ((TLR_RESULT)0xC021000AL)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Out of Memory. */
/*  */
#define TLR_E_ECAT_COE_SDO_OUT_OF_MEMORY ((TLR_RESULT)0xC021000BL)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_UNSUPPORTED_ACCESS_TO_OBJECT */
/*  */
/*  MessageText: */
/*  */
/*   Unsupported access to an object. */
/*  */
#define TLR_E_ECAT_COE_SDO_UNSUPPORTED_ACCESS_TO_OBJECT ((TLR_RESULT)0xC021000CL)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_ATTEMPT_TO_READ_A_WRITE_ONLY_OBJECT */
/*  */
/*  MessageText: */
/*  */
/*   Attempt to read a write only object. */
/*  */
#define TLR_E_ECAT_COE_SDO_ATTEMPT_TO_READ_A_WRITE_ONLY_OBJECT ((TLR_RESULT)0xC021000DL)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_ATTEMPT_TO_WRITE_A_READ_ONLY_OBJECT */
/*  */
/*  MessageText: */
/*  */
/*   Attempt to write a read only object. */
/*  */
#define TLR_E_ECAT_COE_SDO_ATTEMPT_TO_WRITE_A_READ_ONLY_OBJECT ((TLR_RESULT)0xC021000EL)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_OBJECT_DOES_NOT_EXIST */
/*  */
/*  MessageText: */
/*  */
/*   The object does not exist in the object dictionary. */
/*  */
#define TLR_E_ECAT_COE_SDO_OBJECT_DOES_NOT_EXIST ((TLR_RESULT)0xC021000FL)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_OBJECT_CAN_NOT_BE_MAPPED_INTO_THE_PDO */
/*  */
/*  MessageText: */
/*  */
/*   The object can not be mapped into the PDO. */
/*  */
#define TLR_E_ECAT_COE_SDO_OBJECT_CAN_NOT_BE_MAPPED_INTO_THE_PDO ((TLR_RESULT)0xC0210010L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_OBJECTS_WOULD_EXCEED_PDO_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   The number and length of the objects to be mapped would exceed the PDO length. */
/*  */
#define TLR_E_ECAT_COE_SDO_OBJECTS_WOULD_EXCEED_PDO_LENGTH ((TLR_RESULT)0xC0210011L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_GENERAL_PARAMETER_INCOMPATIBILITY_REASON */
/*  */
/*  MessageText: */
/*  */
/*   General parameter incompatibility reason. */
/*  */
#define TLR_E_ECAT_COE_SDO_GENERAL_PARAMETER_INCOMPATIBILITY_REASON ((TLR_RESULT)0xC0210012L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_GENERAL_INTERNAL_INCOMPATIBILITY_IN_DEVICE */
/*  */
/*  MessageText: */
/*  */
/*   General internal incompatibility in the device. */
/*  */
#define TLR_E_ECAT_COE_SDO_GENERAL_INTERNAL_INCOMPATIBILITY_IN_DEVICE ((TLR_RESULT)0xC0210013L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_ACCESS_FAILED_DUE_TO_A_HARDWARE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Access failed due to a hardware error. */
/*  */
#define TLR_E_ECAT_COE_SDO_ACCESS_FAILED_DUE_TO_A_HARDWARE_ERROR ((TLR_RESULT)0xC0210014L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_DATA_TYPE_DOES_NOT_MATCH_LEN_OF_SRV_PARAM_DOES_NOT_MATCH */
/*  */
/*  MessageText: */
/*  */
/*   Data type does not match, length of service parameter does not match. */
/*  */
#define TLR_E_ECAT_COE_SDO_DATA_TYPE_DOES_NOT_MATCH_LEN_OF_SRV_PARAM_DOES_NOT_MATCH ((TLR_RESULT)0xC0210015L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_DATA_TYPE_DOES_NOT_MATCH_LEN_OF_SRV_PARAM_TOO_HIGH */
/*  */
/*  MessageText: */
/*  */
/*   Data type does not match, length of service parameter too high. */
/*  */
#define TLR_E_ECAT_COE_SDO_DATA_TYPE_DOES_NOT_MATCH_LEN_OF_SRV_PARAM_TOO_HIGH ((TLR_RESULT)0xC0210016L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_DATA_TYPE_DOES_NOT_MATCH_LEN_OF_SRV_PARAM_TOO_LOW */
/*  */
/*  MessageText: */
/*  */
/*   Data type does not match, length of service parameter too low. */
/*  */
#define TLR_E_ECAT_COE_SDO_DATA_TYPE_DOES_NOT_MATCH_LEN_OF_SRV_PARAM_TOO_LOW ((TLR_RESULT)0xC0210017L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_SUBINDEX_DOES_NOT_EXIST */
/*  */
/*  MessageText: */
/*  */
/*   Subindex does not exist. */
/*  */
#define TLR_E_ECAT_COE_SDO_SUBINDEX_DOES_NOT_EXIST ((TLR_RESULT)0xC0210018L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_VALUE_RANGE_OF_PARAMETER_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   Value range of parameter exceeded. */
/*  */
#define TLR_E_ECAT_COE_SDO_VALUE_RANGE_OF_PARAMETER_EXCEEDED ((TLR_RESULT)0xC0210019L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_VALUE_OF_PARAMETER_WRITTEN_TOO_HIGH */
/*  */
/*  MessageText: */
/*  */
/*   Value of parameter written too high. */
/*  */
#define TLR_E_ECAT_COE_SDO_VALUE_OF_PARAMETER_WRITTEN_TOO_HIGH ((TLR_RESULT)0xC021001AL)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_VALUE_OF_PARAMETER_WRITTEN_TOO_LOW */
/*  */
/*  MessageText: */
/*  */
/*   Value of parameter written too low. */
/*  */
#define TLR_E_ECAT_COE_SDO_VALUE_OF_PARAMETER_WRITTEN_TOO_LOW ((TLR_RESULT)0xC021001BL)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_MAXIMUM_VALUE_IS_LESS_THAN_MINIMUM_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Maximum value is less than minimum value. */
/*  */
#define TLR_E_ECAT_COE_SDO_MAXIMUM_VALUE_IS_LESS_THAN_MINIMUM_VALUE ((TLR_RESULT)0xC021001CL)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_GENERAL_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   General error. */
/*  */
#define TLR_E_ECAT_COE_SDO_GENERAL_ERROR ((TLR_RESULT)0xC021001DL)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_DATA_CANNOT_BE_TRANSFERRED_OR_STORED_TO_THE_APP */
/*  */
/*  MessageText: */
/*  */
/*   Data cannot be transferred or stored to the application. */
/*  */
#define TLR_E_ECAT_COE_SDO_DATA_CANNOT_BE_TRANSFERRED_OR_STORED_TO_THE_APP ((TLR_RESULT)0xC021001EL)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_DATA_NO_TRANSFER_DUE_TO_LOCAL_CONTROL */
/*  */
/*  MessageText: */
/*  */
/*   Data cannot be transferred or stored to the application because of local control. */
/*  */
#define TLR_E_ECAT_COE_SDO_DATA_NO_TRANSFER_DUE_TO_LOCAL_CONTROL ((TLR_RESULT)0xC021001FL)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_DATA_NO_TRANSFER_DUE_TO_PRESENT_DEVICE_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Data cannot be transferred or stored to the application because of present device state. */
/*  */
#define TLR_E_ECAT_COE_SDO_DATA_NO_TRANSFER_DUE_TO_PRESENT_DEVICE_STATE ((TLR_RESULT)0xC0210020L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_NO_OBJECT_DICTIONARY_PRESENT */
/*  */
/*  MessageText: */
/*  */
/*   Object dictionary dynamic generation fails or no object dictionary present. */
/*  */
#define TLR_E_ECAT_COE_SDO_NO_OBJECT_DICTIONARY_PRESENT ((TLR_RESULT)0xC0210021L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_UNKNOWN_ABORT_CODE */
/*  */
/*  MessageText: */
/*  */
/*   Unknown SDO abort code. */
/*  */
#define TLR_E_ECAT_COE_SDO_UNKNOWN_ABORT_CODE ((TLR_RESULT)0xC0210022L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_TOGGLE_BIT_NOT_TOGGLED */
/*  */
/*  MessageText: */
/*  */
/*   SDO toggle bit was not toggled. */
/*  */
#define TLR_E_ECAT_COE_SDO_TOGGLE_BIT_NOT_TOGGLED ((TLR_RESULT)0xC0210023L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_CLIENT_STACK_BUSY */
/*  */
/*  MessageText: */
/*  */
/*   SDO client stack busy. */
/*  */
#define TLR_E_ECAT_COE_SDO_CLIENT_STACK_BUSY ((TLR_RESULT)0xC0210024L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SDO_CLIENT_STACK_NO_TRANSFER */
/*  */
/*  MessageText: */
/*  */
/*   SDO client stack has no active transfer identified by station address. */
/*  */
#define TLR_E_ECAT_COE_SDO_CLIENT_STACK_NO_TRANSFER ((TLR_RESULT)0xC0210025L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_PDO_SUBOBJECT_PTR_UNALIGNED */
/*  */
/*  MessageText: */
/*  */
/*   Subobject data pointer is unaligned. */
/*  */
#define TLR_E_ECAT_COE_PDO_SUBOBJECT_PTR_UNALIGNED ((TLR_RESULT)0xC0210026L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_COULD_NOT_SEND_MBX_MESSAGE */
/*  */
/*  MessageText: */
/*  */
/*   Could not send mailbox message. */
/*  */
#define TLR_E_ECAT_COE_COULD_NOT_SEND_MBX_MESSAGE ((TLR_RESULT)0xC0210027L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_INVALID_MBX_MESSAGE */
/*  */
/*  MessageText: */
/*  */
/*   Could not send mailbox message due to format errors. */
/*  */
#define TLR_E_ECAT_COE_INVALID_MBX_MESSAGE ((TLR_RESULT)0xC0210028L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_NO_OBJECT_DICTIONARY_PRESENT */
/*  */
/*  MessageText: */
/*  */
/*   No object dictionary present. */
/*  */
#define TLR_E_ECAT_COE_NO_OBJECT_DICTIONARY_PRESENT ((TLR_RESULT)0xC0210029L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_INVALID_PDO_DBM_CONFIGURATION */
/*  */
/*  MessageText: */
/*  */
/*   Invalid PDO DBM configuration. */
/*  */
#define TLR_E_ECAT_COE_INVALID_PDO_DBM_CONFIGURATION ((TLR_RESULT)0xC021002AL)

/*  */
/*  MessageId: TLR_I_ECAT_COE_CONFIG_INTERFACE_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   configuration interface not initialized. */
/*  */
#define TLR_I_ECAT_COE_CONFIG_INTERFACE_NOT_INITIALIZED ((TLR_RESULT)0x4021002BL)

/*  */
/*  MessageId: TLR_W_ECAT_COE_NO_OUTPUT_DATA */
/*  */
/*  MessageText: */
/*  */
/*   no output data available. */
/*  */
#define TLR_W_ECAT_COE_NO_OUTPUT_DATA    ((TLR_RESULT)0x8021002CL)

/*  */
/*  MessageId: TLR_E_ECAT_COE_INVALID_TIMEOUT_PARAMS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid timeout parameters. */
/*  */
#define TLR_E_ECAT_COE_INVALID_TIMEOUT_PARAMS ((TLR_RESULT)0xC021002DL)

/*  */
/*  MessageId: TLR_E_ECAT_COE_SHUTDOWN_ACTIVE */
/*  */
/*  MessageText: */
/*  */
/*   Shutdown on task is active. */
/*  */
#define TLR_E_ECAT_COE_SHUTDOWN_ACTIVE   ((TLR_RESULT)0xC021002EL)

/*  */
/*  MessageId: TLR_E_ECAT_COE_OD_NOTIFY_TABLE_FULL */
/*  */
/*  MessageText: */
/*  */
/*   Od Notify Table Full. */
/*  */
#define TLR_E_ECAT_COE_OD_NOTIFY_TABLE_FULL ((TLR_RESULT)0xC021002FL)

/*  */
/*  MessageId: TLR_E_ECAT_COE_OD_UNDEFINED_NOTIFY_APPLICATION_ALREADY_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   An application already registered for the Undefined object notify. */
/*  */
#define TLR_E_ECAT_COE_OD_UNDEFINED_NOTIFY_APPLICATION_ALREADY_REGISTERED ((TLR_RESULT)0xC0210030L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_OD_SDOINFO_NOTIFY_APPLICATION_ALREADY_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   An application already registered for the SDOInfo packet hook. */
/*  */
#define TLR_E_ECAT_COE_OD_SDOINFO_NOTIFY_APPLICATION_ALREADY_REGISTERED ((TLR_RESULT)0xC0210031L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_OD_DPM_MODE_OBJECTS_CAN_ONLY_BE_READONLY */
/*  */
/*  MessageText: */
/*  */
/*   DPM Mode Objects can only be set readonly. */
/*  */
#define TLR_E_ECAT_COE_OD_DPM_MODE_OBJECTS_CAN_ONLY_BE_READONLY ((TLR_RESULT)0xC0210032L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_OD_DPM_MODE_OBJECTS_DIRECTION_PARAMETER_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid direction parameter for DPM Mode Objects. */
/*  */
#define TLR_E_ECAT_COE_OD_DPM_MODE_OBJECTS_DIRECTION_PARAMETER_INVALID ((TLR_RESULT)0xC0210033L)

/*  */
/*  MessageId: TLR_E_ECAT_COE_OD_DPM_MODE_SUBOBJECT_OFFSET_OUT_OF_RANGE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid offset parameter for DPM Mode Objects. */
/*  */
#define TLR_E_ECAT_COE_OD_DPM_MODE_SUBOBJECT_OFFSET_OUT_OF_RANGE ((TLR_RESULT)0xC0210034L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  EtherCAT VoE stack error codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_ECAT_VOE_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_ECAT_VOE_COMMAND_INVALID   ((TLR_RESULT)0xC0260001L)

/*  */
/*  MessageId: TLR_W_ECAT_VOE_NO_RECEIVER_FOR_VENDOR_PROFILE */
/*  */
/*  MessageText: */
/*  */
/*   No receiver for vendor profile. */
/*  */
#define TLR_W_ECAT_VOE_NO_RECEIVER_FOR_VENDOR_PROFILE ((TLR_RESULT)0x80260002L)

/*  */
/*  MessageId: TLR_E_ECAT_VOE_VENDOR_PROFILE_ALREADY_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   Vendor profile is already registered. */
/*  */
#define TLR_E_ECAT_VOE_VENDOR_PROFILE_ALREADY_REGISTERED ((TLR_RESULT)0xC0260003L)

/*  */
/*  MessageId: TLR_E_ECAT_VOE_VENDOR_PROFILE_NOT_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   Vendor profile is not registered. */
/*  */
#define TLR_E_ECAT_VOE_VENDOR_PROFILE_NOT_REGISTERED ((TLR_RESULT)0xC0260004L)

/*  */
/*  MessageId: TLR_E_ECAT_VOE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Out of memory. */
/*  */
#define TLR_E_ECAT_VOE_OUT_OF_MEMORY     ((TLR_RESULT)0xC0260005L)

/*  */
/*  MessageId: TLR_E_ECAT_VOE_COULD_NOT_SEND_MBX_MESSAGE */
/*  */
/*  MessageText: */
/*  */
/*   Could not send mailbox message. */
/*  */
#define TLR_E_ECAT_VOE_COULD_NOT_SEND_MBX_MESSAGE ((TLR_RESULT)0xC0260006L)

/*  */
/*  MessageId: TLR_E_ECAT_VOE_NOT_ENOUGH_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Not enough memory. */
/*  */
#define TLR_E_ECAT_VOE_NOT_ENOUGH_MEMORY ((TLR_RESULT)0xC0260007L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  EtherCAT FoE stack error codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_ECAT_FOE_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_ECAT_FOE_COMMAND_INVALID   ((TLR_RESULT)0xC0240001L)

/*  */
/*  MessageId: TLR_W_ECAT_FOE_INVALID_OPCODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid FoE opcode. */
/*  */
#define TLR_W_ECAT_FOE_INVALID_OPCODE    ((TLR_RESULT)0x80240002L)

/*  */
/*  MessageId: TLR_E_ECAT_FOE_UNKNOWN_FILESYSTEM */
/*  */
/*  MessageText: */
/*  */
/*   Unknown filesystem. */
/*  */
#define TLR_E_ECAT_FOE_UNKNOWN_FILESYSTEM ((TLR_RESULT)0xC0240003L)

/*  */
/*  MessageId: TLR_I_ECAT_FOE_CONFIG_INTERFACE_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   configuration interface not initialized. */
/*  */
#define TLR_I_ECAT_FOE_CONFIG_INTERFACE_NOT_INITIALIZED ((TLR_RESULT)0x40240004L)

/*  */
/*  MessageId: TLR_E_ECAT_FOE_INVALID_TIMEOUT_PARAMS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid timeout parameters. */
/*  */
#define TLR_E_ECAT_FOE_INVALID_TIMEOUT_PARAMS ((TLR_RESULT)0xC0240005L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  EtherCAT SoE stack error codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/* Range 0x1000-0x7FFF is reserved for SSC error mapping */
/* Range 0x8000-0x8FFF is reserved for default value error codes */
/*  */
/*  MessageId: TLR_E_ECAT_SOE_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_ECAT_SOE_COMMAND_INVALID   ((TLR_RESULT)0xC0220001L)

/*  */
/*  MessageId: TLR_I_ECAT_SOE_CONFIG_INTERFACE_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   configuration interface not initialized. */
/*  */
#define TLR_I_ECAT_SOE_CONFIG_INTERFACE_NOT_INITIALIZED ((TLR_RESULT)0x40220002L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_INVALID_TIMEOUT_PARAMS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid timeout parameters. */
/*  */
#define TLR_E_ECAT_SOE_INVALID_TIMEOUT_PARAMS ((TLR_RESULT)0xC0220003L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_ALREADY_EXISTS */
/*  */
/*  MessageText: */
/*  */
/*   IDN already exists. */
/*  */
#define TLR_E_ECAT_SOE_IDN_ALREADY_EXISTS ((TLR_RESULT)0xC0220004L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_ATTRIBUTE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid attribute specified. */
/*  */
#define TLR_E_ECAT_SOE_IDN_ATTRIBUTE_INVALID ((TLR_RESULT)0xC0220005L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_INVALID_MAX_DATA_SIZE_SPECIFIED */
/*  */
/*  MessageText: */
/*  */
/*   Invalid max data size specified. */
/*  */
#define TLR_E_ECAT_SOE_IDN_INVALID_MAX_DATA_SIZE_SPECIFIED ((TLR_RESULT)0xC0220006L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_DRIVE_NUMBER_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Drive number invalid. */
/*  */
#define TLR_E_ECAT_SOE_IDN_DRIVE_NUMBER_INVALID ((TLR_RESULT)0xC0220007L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_UNDEFINED_NOTIFY_ALREADY_IN_USE */
/*  */
/*  MessageText: */
/*  */
/*   Undefined notify already in use. */
/*  */
#define TLR_E_ECAT_SOE_IDN_UNDEFINED_NOTIFY_ALREADY_IN_USE ((TLR_RESULT)0xC0220008L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_INVALID_ELEMENT_ID */
/*  */
/*  MessageText: */
/*  */
/*   Invlaid element id. */
/*  */
#define TLR_E_ECAT_SOE_IDN_INVALID_ELEMENT_ID ((TLR_RESULT)0xC0220009L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_APP_PACKET_RESPONSE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Application's Response Packet invalid. */
/*  */
#define TLR_E_ECAT_SOE_IDN_APP_PACKET_RESPONSE_INVALID ((TLR_RESULT)0xC022000AL)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_APP_SSC_TRANSFER_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Application's Transfer Data too long. */
/*  */
#define TLR_E_ECAT_SOE_IDN_APP_SSC_TRANSFER_TOO_LONG ((TLR_RESULT)0xC022000BL)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_APP_SSC_TRANSFER_LENGTH_WRONG */
/*  */
/*  MessageText: */
/*  */
/*   Application's Transfer Data length is invalid. */
/*  */
#define TLR_E_ECAT_SOE_IDN_APP_SSC_TRANSFER_LENGTH_WRONG ((TLR_RESULT)0xC022000CL)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_APP_MTU_TOO_LOW */
/*  */
/*  MessageText: */
/*  */
/*   Application's MTU is too low. */
/*  */
#define TLR_E_ECAT_SOE_IDN_APP_MTU_TOO_LOW ((TLR_RESULT)0xC022000DL)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_INVALID_DEST_ID */
/*  */
/*  MessageText: */
/*  */
/*   ECAT_SOEIDN: Invalid DestId. */
/*  */
#define TLR_E_ECAT_SOE_IDN_INVALID_DEST_ID ((TLR_RESULT)0xC022000EL)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_LISTS_CANNOT_HAVE_A_MINIMUM_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Lists cannot have a minimum value. */
/*  */
#define TLR_E_ECAT_SOE_IDN_LISTS_CANNOT_HAVE_A_MINIMUM_VALUE ((TLR_RESULT)0xC022000FL)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_LISTS_CANNOT_HAVE_A_MAXIMUM_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Lists cannot have a maximum value. */
/*  */
#define TLR_E_ECAT_SOE_IDN_LISTS_CANNOT_HAVE_A_MAXIMUM_VALUE ((TLR_RESULT)0xC0220010L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_NAME_EXCEEDS_ALLOCATED_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Name exceeds allocated length. */
/*  */
#define TLR_E_ECAT_SOE_IDN_NAME_EXCEEDS_ALLOCATED_LENGTH ((TLR_RESULT)0xC0220011L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_UNIT_EXCEEDS_ALLOCATED_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Unit exceeds allocated length. */
/*  */
#define TLR_E_ECAT_SOE_IDN_UNIT_EXCEEDS_ALLOCATED_LENGTH ((TLR_RESULT)0xC0220012L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_OPDATA_EXCEEDS_ALLOCATED_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   OpData exceeds allocated length. */
/*  */
#define TLR_E_ECAT_SOE_IDN_OPDATA_EXCEEDS_ALLOCATED_LENGTH ((TLR_RESULT)0xC0220013L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_INVALID_MAX_LIST_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Invalid max list length. */
/*  */
#define TLR_E_ECAT_SOE_IDN_INVALID_MAX_LIST_LENGTH ((TLR_RESULT)0xC0220014L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_DEFAULT_VALUE_EXCEEDS_ALLOCATED_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Default value exceeds allocated length. */
/*  */
#define TLR_E_ECAT_SOE_IDN_DEFAULT_VALUE_EXCEEDS_ALLOCATED_LENGTH ((TLR_RESULT)0xC0220015L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_MINIMUM_AND_MAXIMUM_VALUE_MUST_BE_USED_TOGETHER */
/*  */
/*  MessageText: */
/*  */
/*   Minimum and maximum value must be used together. */
/*  */
#define TLR_E_ECAT_SOE_IDN_MINIMUM_AND_MAXIMUM_VALUE_MUST_BE_USED_TOGETHER ((TLR_RESULT)0xC0220016L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_IDN_USER_APPLICATION_TRANSFER_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   User application transfer error. */
/*  */
#define TLR_E_ECAT_SOE_IDN_USER_APPLICATION_TRANSFER_ERROR ((TLR_RESULT)0xC0220017L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_NO_IDN */
/*  */
/*  MessageText: */
/*  */
/*   IDN not available. */
/*  */
#define TLR_E_ECAT_SOE_SSC_NO_IDN        ((TLR_RESULT)0xC0221001L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_INVALID_ACCESS_TO_ELEMENT_1 */
/*  */
/*  MessageText: */
/*  */
/*   Invalid access to element 1. */
/*  */
#define TLR_E_ECAT_SOE_SSC_INVALID_ACCESS_TO_ELEMENT_1 ((TLR_RESULT)0xC0221009L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_NO_NAME */
/*  */
/*  MessageText: */
/*  */
/*   No Name. */
/*  */
#define TLR_E_ECAT_SOE_SSC_NO_NAME       ((TLR_RESULT)0xC0222001L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_NAME_TRANSMISSION_IS_TOO_SHORT */
/*  */
/*  MessageText: */
/*  */
/*   Name transmision is too short. */
/*  */
#define TLR_E_ECAT_SOE_SSC_NAME_TRANSMISSION_IS_TOO_SHORT ((TLR_RESULT)0xC0222002L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_NAME_TRANSMISSION_IS_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Name transmision is too long. */
/*  */
#define TLR_E_ECAT_SOE_SSC_NAME_TRANSMISSION_IS_TOO_LONG ((TLR_RESULT)0xC0222003L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_NAME_CANNOT_BE_CHANGED */
/*  */
/*  MessageText: */
/*  */
/*   Name cannot be changed (read only). */
/*  */
#define TLR_E_ECAT_SOE_SSC_NAME_CANNOT_BE_CHANGED ((TLR_RESULT)0xC0222004L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_NAME_IS_WRITE_PROTECTED_AT_THIS_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Name is write protected at this time. */
/*  */
#define TLR_E_ECAT_SOE_SSC_NAME_IS_WRITE_PROTECTED_AT_THIS_TIME ((TLR_RESULT)0xC0222005L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_ATTRIBUTE_TRANSMISSION_IS_TOO_SHORT */
/*  */
/*  MessageText: */
/*  */
/*   Attribute transmision is too short. */
/*  */
#define TLR_E_ECAT_SOE_SSC_ATTRIBUTE_TRANSMISSION_IS_TOO_SHORT ((TLR_RESULT)0xC0223002L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_ATTRIBUTE_TRANSMISSION_IS_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Attribute transmision is too long. */
/*  */
#define TLR_E_ECAT_SOE_SSC_ATTRIBUTE_TRANSMISSION_IS_TOO_LONG ((TLR_RESULT)0xC0223003L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_ATTRIBUTE_CANNOT_BE_CHANGED */
/*  */
/*  MessageText: */
/*  */
/*   Attribute cannot be changed (read only). */
/*  */
#define TLR_E_ECAT_SOE_SSC_ATTRIBUTE_CANNOT_BE_CHANGED ((TLR_RESULT)0xC0223004L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_ATTRIBUTE_IS_WRITE_PROTECTED_AT_THIS_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Attribute is write protected at this time. */
/*  */
#define TLR_E_ECAT_SOE_SSC_ATTRIBUTE_IS_WRITE_PROTECTED_AT_THIS_TIME ((TLR_RESULT)0xC0223005L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_NO_UNIT */
/*  */
/*  MessageText: */
/*  */
/*   No unit. */
/*  */
#define TLR_E_ECAT_SOE_SSC_NO_UNIT       ((TLR_RESULT)0xC0224001L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_UNIT_TRANSMISSION_IS_TOO_SHORT */
/*  */
/*  MessageText: */
/*  */
/*   Unit transmision is too short. */
/*  */
#define TLR_E_ECAT_SOE_SSC_UNIT_TRANSMISSION_IS_TOO_SHORT ((TLR_RESULT)0xC0224002L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_UNIT_TRANSMISSION_IS_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Unit transmision is too long. */
/*  */
#define TLR_E_ECAT_SOE_SSC_UNIT_TRANSMISSION_IS_TOO_LONG ((TLR_RESULT)0xC0224003L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_UNIT_CANNOT_BE_CHANGED */
/*  */
/*  MessageText: */
/*  */
/*   Unit cannot be changed (read only). */
/*  */
#define TLR_E_ECAT_SOE_SSC_UNIT_CANNOT_BE_CHANGED ((TLR_RESULT)0xC0224004L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_UNIT_IS_WRITE_PROTECTED_AT_THIS_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Unit is write protected at this time. */
/*  */
#define TLR_E_ECAT_SOE_SSC_UNIT_IS_WRITE_PROTECTED_AT_THIS_TIME ((TLR_RESULT)0xC0224005L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_NO_MINIMUM_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   No minimum value. */
/*  */
#define TLR_E_ECAT_SOE_SSC_NO_MINIMUM_VALUE ((TLR_RESULT)0xC0225001L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_MINIMUM_VALUE_TRANSMISSION_IS_TOO_SHORT */
/*  */
/*  MessageText: */
/*  */
/*   Minimum value transmision is too short. */
/*  */
#define TLR_E_ECAT_SOE_SSC_MINIMUM_VALUE_TRANSMISSION_IS_TOO_SHORT ((TLR_RESULT)0xC0225002L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_MINIMUM_VALUE_TRANSMISSION_IS_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Minimum value transmision is too long. */
/*  */
#define TLR_E_ECAT_SOE_SSC_MINIMUM_VALUE_TRANSMISSION_IS_TOO_LONG ((TLR_RESULT)0xC0225003L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_MINIMUM_VALUE_CANNOT_BE_CHANGED */
/*  */
/*  MessageText: */
/*  */
/*   Minimum value cannot be changed (read only). */
/*  */
#define TLR_E_ECAT_SOE_SSC_MINIMUM_VALUE_CANNOT_BE_CHANGED ((TLR_RESULT)0xC0225004L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_MINIMUM_VALUE_IS_WRITE_PROTECTED_AT_THIS_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Minimum value is write protected at this time. */
/*  */
#define TLR_E_ECAT_SOE_SSC_MINIMUM_VALUE_IS_WRITE_PROTECTED_AT_THIS_TIME ((TLR_RESULT)0xC0225005L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_NO_MAXIMUM_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   No maximum value. */
/*  */
#define TLR_E_ECAT_SOE_SSC_NO_MAXIMUM_VALUE ((TLR_RESULT)0xC0226001L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_MAXIMUM_VALUE_TRANSMISSION_IS_TOO_SHORT */
/*  */
/*  MessageText: */
/*  */
/*   Maximum value transmision is too short. */
/*  */
#define TLR_E_ECAT_SOE_SSC_MAXIMUM_VALUE_TRANSMISSION_IS_TOO_SHORT ((TLR_RESULT)0xC0226002L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_MAXIMUM_VALUE_TRANSMISSION_IS_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Maximum value transmision is too long. */
/*  */
#define TLR_E_ECAT_SOE_SSC_MAXIMUM_VALUE_TRANSMISSION_IS_TOO_LONG ((TLR_RESULT)0xC0226003L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_MAXIMUM_VALUE_CANNOT_BE_CHANGED */
/*  */
/*  MessageText: */
/*  */
/*   Maximum value cannot be changed (read only). */
/*  */
#define TLR_E_ECAT_SOE_SSC_MAXIMUM_VALUE_CANNOT_BE_CHANGED ((TLR_RESULT)0xC0226004L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_MAXIMUM_VALUE_IS_WRITE_PROTECTED_AT_THIS_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Maximum value is write protected at this time. */
/*  */
#define TLR_E_ECAT_SOE_SSC_MAXIMUM_VALUE_IS_WRITE_PROTECTED_AT_THIS_TIME ((TLR_RESULT)0xC0226005L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_OPDATA_TRANSMISSION_IS_TOO_SHORT */
/*  */
/*  MessageText: */
/*  */
/*   Operation data transmision is too short. */
/*  */
#define TLR_E_ECAT_SOE_SSC_OPDATA_TRANSMISSION_IS_TOO_SHORT ((TLR_RESULT)0xC0227002L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_OPDATA_TRANSMISSION_IS_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Operation data transmision is too long. */
/*  */
#define TLR_E_ECAT_SOE_SSC_OPDATA_TRANSMISSION_IS_TOO_LONG ((TLR_RESULT)0xC0227003L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_OPDATA_CANNOT_BE_CHANGED */
/*  */
/*  MessageText: */
/*  */
/*   Operation data cannot be changed (read only). */
/*  */
#define TLR_E_ECAT_SOE_SSC_OPDATA_CANNOT_BE_CHANGED ((TLR_RESULT)0xC0227004L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_OPDATA_IS_WRITE_PROTECTED_AT_THIS_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Operation data is write protected at this time. */
/*  */
#define TLR_E_ECAT_SOE_SSC_OPDATA_IS_WRITE_PROTECTED_AT_THIS_TIME ((TLR_RESULT)0xC0227005L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_OPDATA_IS_LOWER_THAN_MINIMUM_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Operation data is lower than Minimum value. */
/*  */
#define TLR_E_ECAT_SOE_SSC_OPDATA_IS_LOWER_THAN_MINIMUM_VALUE ((TLR_RESULT)0xC0227006L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_OPDATA_IS_HIGHER_THAN_MAXIMUM_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Operation data is higher than Maximum value. */
/*  */
#define TLR_E_ECAT_SOE_SSC_OPDATA_IS_HIGHER_THAN_MAXIMUM_VALUE ((TLR_RESULT)0xC0227007L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_OPDATA_IS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid operation data. */
/*  */
#define TLR_E_ECAT_SOE_SSC_OPDATA_IS_INVALID ((TLR_RESULT)0xC0227008L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_OPDATA_IS_WRITE_PROTECTED_BY_PASSWORD */
/*  */
/*  MessageText: */
/*  */
/*   Operation data is write protected by password. */
/*  */
#define TLR_E_ECAT_SOE_SSC_OPDATA_IS_WRITE_PROTECTED_BY_PASSWORD ((TLR_RESULT)0xC0227009L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_OPDATA_IS_WRITE_PROTECTED_DUE_CYCLICALLY_CONFIGURED */
/*  */
/*  MessageText: */
/*  */
/*   Operation data is write protected. It is configured cyclically. */
/*  */
#define TLR_E_ECAT_SOE_SSC_OPDATA_IS_WRITE_PROTECTED_DUE_CYCLICALLY_CONFIGURED ((TLR_RESULT)0xC022700AL)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_OPDATA_INVALID_INDIRECT_ADDRESSING */
/*  */
/*  MessageText: */
/*  */
/*   Invalid indirect addressing. */
/*  */
#define TLR_E_ECAT_SOE_SSC_OPDATA_INVALID_INDIRECT_ADDRESSING ((TLR_RESULT)0xC022700BL)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_OPDATA_IS_WRITE_PROTECTED_DUE_OTHER_SETTINGS */
/*  */
/*  MessageText: */
/*  */
/*   Operation data is write protected due other settings. */
/*  */
#define TLR_E_ECAT_SOE_SSC_OPDATA_IS_WRITE_PROTECTED_DUE_OTHER_SETTINGS ((TLR_RESULT)0xC022700CL)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_OPDATA_INVALID_FLOATING_POINT_NUMBER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid floating point number. */
/*  */
#define TLR_E_ECAT_SOE_SSC_OPDATA_INVALID_FLOATING_POINT_NUMBER ((TLR_RESULT)0xC022700DL)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_OPDATA_IS_WRITE_PROTECTED_AT_PARAMETERIZATION_LEVEL */
/*  */
/*  MessageText: */
/*  */
/*   Operation data is write protected at parameterization level. */
/*  */
#define TLR_E_ECAT_SOE_SSC_OPDATA_IS_WRITE_PROTECTED_AT_PARAMETERIZATION_LEVEL ((TLR_RESULT)0xC022700EL)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_OPDATA_IS_WRITE_PROTECTED_AT_OPERATION_LEVEL */
/*  */
/*  MessageText: */
/*  */
/*   Operation data is write protected at operation level. */
/*  */
#define TLR_E_ECAT_SOE_SSC_OPDATA_IS_WRITE_PROTECTED_AT_OPERATION_LEVEL ((TLR_RESULT)0xC022700FL)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_OPDATA_PROCEDURE_COMMAND_ALREADY_ACTIVE */
/*  */
/*  MessageText: */
/*  */
/*   Procedure command already active. */
/*  */
#define TLR_E_ECAT_SOE_SSC_OPDATA_PROCEDURE_COMMAND_ALREADY_ACTIVE ((TLR_RESULT)0xC0227010L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_OPDATA_PROCEDURE_COMMAND_NOT_INTERRUPTIBLE */
/*  */
/*  MessageText: */
/*  */
/*   Procedure command not interruptible. */
/*  */
#define TLR_E_ECAT_SOE_SSC_OPDATA_PROCEDURE_COMMAND_NOT_INTERRUPTIBLE ((TLR_RESULT)0xC0227011L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_OPDATA_PROCEDURE_COMMAND_NOT_EXECUTABLE_AT_THIS_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Procedure Command is not executable at this time (e.g. wrong slave state). */
/*  */
#define TLR_E_ECAT_SOE_SSC_OPDATA_PROCEDURE_COMMAND_NOT_EXECUTABLE_AT_THIS_TIME ((TLR_RESULT)0xC0227012L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_OPDATA_PROCEDURE_COMMAND_NOT_EXECUTABLE_INVALID_PARAM */
/*  */
/*  MessageText: */
/*  */
/*   Procedure Command is not executable due invalid parameters. */
/*  */
#define TLR_E_ECAT_SOE_SSC_OPDATA_PROCEDURE_COMMAND_NOT_EXECUTABLE_INVALID_PARAM ((TLR_RESULT)0xC0227013L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_NO_DEFAULT_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   No default value. */
/*  */
#define TLR_E_ECAT_SOE_SSC_NO_DEFAULT_VALUE ((TLR_RESULT)0xC0228001L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_DEFAULT_VALUE_CANNOT_BE_CHANGED */
/*  */
/*  MessageText: */
/*  */
/*   Default value cannot be changed (read only). */
/*  */
#define TLR_E_ECAT_SOE_SSC_DEFAULT_VALUE_CANNOT_BE_CHANGED ((TLR_RESULT)0xC0228004L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_DEFAULT_VALUE_TRANSMISSION_IS_TOO_SHORT */
/*  */
/*  MessageText: */
/*  */
/*   Default value transmision is too short. */
/*  */
#define TLR_E_ECAT_SOE_SSC_DEFAULT_VALUE_TRANSMISSION_IS_TOO_SHORT ((TLR_RESULT)0xC0228002L)

/*  */
/*  MessageId: TLR_E_ECAT_SOE_SSC_DEFAULT_VALUE_TRANSMISSION_IS_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Default value transmision is too long. */
/*  */
#define TLR_E_ECAT_SOE_SSC_DEFAULT_VALUE_TRANSMISSION_IS_TOO_LONG ((TLR_RESULT)0xC0228003L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  EtherCAT AoE stack error codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_ECAT_AOE_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_ECAT_AOE_COMMAND_INVALID   ((TLR_RESULT)0xC0250001L)

/*  */
/*  MessageId: TLR_I_ECAT_AOE_CONFIG_INTERFACE_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   configuration interface not initialized. */
/*  */
#define TLR_I_ECAT_AOE_CONFIG_INTERFACE_NOT_INITIALIZED ((TLR_RESULT)0x40250002L)

/*  */
/*  MessageId: TLR_E_ECAT_AOE_INVALID_TIMEOUT_PARAMS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid timeout parameters. */
/*  */
#define TLR_E_ECAT_AOE_INVALID_TIMEOUT_PARAMS ((TLR_RESULT)0xC0250003L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  EtherCAT EoE stack error codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_ECAT_EOE_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_ECAT_EOE_COMMAND_INVALID   ((TLR_RESULT)0xC0230001L)

/*  */
/*  MessageId: TLR_E_ECAT_EOE_VIRTUAL_SWITCH_NOT_PRESENT */
/*  */
/*  MessageText: */
/*  */
/*   Virtual Switch not present. */
/*  */
#define TLR_E_ECAT_EOE_VIRTUAL_SWITCH_NOT_PRESENT ((TLR_RESULT)0xC0230002L)

/*  */
/*  MessageId: TLR_I_ECAT_EOE_CONFIG_INTERFACE_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   configuration interface not initialized. */
/*  */
#define TLR_I_ECAT_EOE_CONFIG_INTERFACE_NOT_INITIALIZED ((TLR_RESULT)0x40230002L)

/*  */
/*  MessageId: TLR_S_ECAT_EOE_IP_CONFIG_DATA_NOT_VALID */
/*  */
/*  MessageText: */
/*  */
/*   IP configuration data not valid. */
/*  */
#define TLR_S_ECAT_EOE_IP_CONFIG_DATA_NOT_VALID ((TLR_RESULT)0x00230003L)

/*  */
/*  MessageId: TLR_E_ECAT_EOE_INVALID_TIMEOUT_PARAMS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid timeout parameters. */
/*  */
#define TLR_E_ECAT_EOE_INVALID_TIMEOUT_PARAMS ((TLR_RESULT)0xC0230004L)

/*  */
/*  MessageId: TLR_E_ECAT_EOE_PARAM_UNSPECIFIED_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Unspecified Error. */
/*  */
#define TLR_E_ECAT_EOE_PARAM_UNSPECIFIED_ERROR ((TLR_RESULT)0xC0230005L)

/*  */
/*  MessageId: TLR_E_ECAT_EOE_PARAM_UNSUPPORTED_FRAME_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Unsupported Frame Type. */
/*  */
#define TLR_E_ECAT_EOE_PARAM_UNSUPPORTED_FRAME_TYPE ((TLR_RESULT)0xC0230006L)

/*  */
/*  MessageId: TLR_E_ECAT_EOE_PARAM_NO_IP_SUPPORT */
/*  */
/*  MessageText: */
/*  */
/*   No IP Support. */
/*  */
#define TLR_E_ECAT_EOE_PARAM_NO_IP_SUPPORT ((TLR_RESULT)0xC0230007L)

/*  */
/*  MessageId: TLR_E_ECAT_EOE_PARAM_NO_FILTER_SUPPORT */
/*  */
/*  MessageText: */
/*  */
/*   No Filter Support. */
/*  */
#define TLR_E_ECAT_EOE_PARAM_NO_FILTER_SUPPORT ((TLR_RESULT)0xC0230008L)




#endif  /* __ECAT_ERROR_H */

#ifndef _APM
#define _APM

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Ethernet/IP Application Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_EIP_APM_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_EIP_APM_COMMAND_INVALID    ((TLR_RESULT)0xC05A0001L)

/*  */
/*  MessageId: TLR_E_EIP_APM_PACKET_LENGTH_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid packet length. */
/*  */
#define TLR_E_EIP_APM_PACKET_LENGTH_INVALID ((TLR_RESULT)0xC05A0002L)

/*  */
/*  MessageId: TLR_E_EIP_APM_PACKET_PARAMETER_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Parameter of the packet are invalid. */
/*  */
#define TLR_E_EIP_APM_PACKET_PARAMETER_INVALID ((TLR_RESULT)0xC05A0003L)

/*  */
/*  MessageId: TLR_E_EIP_APM_TCP_CONFIG_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Configuration of TCP/IP failed. */
/*  */
#define TLR_E_EIP_APM_TCP_CONFIG_FAIL    ((TLR_RESULT)0xC05A0004L)

/*  */
/*  MessageId: TLR_E_EIP_APM_CONNECTION_CLOSED */
/*  */
/*  MessageText: */
/*  */
/*   Existing connection is closed. */
/*  */
#define TLR_E_EIP_APM_CONNECTION_CLOSED  ((TLR_RESULT)0xC05A0005L)

/*  */
/*  MessageId: TLR_E_EIP_APM_ALREADY_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   A application is already registered. */
/*  */
#define TLR_E_EIP_APM_ALREADY_REGISTERED ((TLR_RESULT)0xC05A0006L)

/*  */
/*  MessageId: TLR_E_EIP_APM_ACCESS_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Command is not allowed. */
/*  */
#define TLR_E_EIP_APM_ACCESS_FAIL        ((TLR_RESULT)0xC05A0007L)

/*  */
/*  MessageId: TLR_E_EIP_APM_STATE_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Command not allowed at this state. */
/*  */
#define TLR_E_EIP_APM_STATE_FAIL         ((TLR_RESULT)0xC05A0008L)

/*  */
/*  MessageId: TLR_E_EIP_APM_NO_CONFIG_DBM */
/*  */
/*  MessageText: */
/*  */
/*   Database config.dpm not found. */
/*  */
#define TLR_E_EIP_APM_NO_CONFIG_DBM      ((TLR_RESULT)0xC05A0009L)

/*  */
/*  MessageId: TLR_E_EIP_APM_NO_NWID_DBM */
/*  */
/*  MessageText: */
/*  */
/*   Database nwid.dpm not found. */
/*  */
#define TLR_E_EIP_APM_NO_NWID_DBM        ((TLR_RESULT)0xC05A000AL)

/*  */
/*  MessageId: TLR_E_EIP_APM_CONFIG_DBM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Database config.dpm invalid. */
/*  */
#define TLR_E_EIP_APM_CONFIG_DBM_INVALID ((TLR_RESULT)0xC05A000BL)

/*  */
/*  MessageId: TLR_E_EIP_APM_NWID_DBM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Database nwid.dpm invalid. */
/*  */
#define TLR_E_EIP_APM_NWID_DBM_INVALID   ((TLR_RESULT)0xC05A000CL)

/*  */
/*  MessageId: TLR_E_EIP_APM_FOLDER_NOT_FOUND */
/*  */
/*  MessageText: */
/*  */
/*   Channel folder not found. */
/*  */
#define TLR_E_EIP_APM_FOLDER_NOT_FOUND   ((TLR_RESULT)0xC05A000DL)

/*  */
/*  MessageId: TLR_E_EIP_APM_IO_OFFSET_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid dual port memory I/O offset. */
/*  */
#define TLR_E_EIP_APM_IO_OFFSET_INVALID  ((TLR_RESULT)0xC05A000EL)




#endif  /* _APM */

#ifndef __EIP_APS_ERROR_H
#define __EIP_APS_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Ethernet/IP Application Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_EIP_APS_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_EIP_APS_COMMAND_INVALID    ((TLR_RESULT)0xC0590001L)

/*  */
/*  MessageId: TLR_E_EIP_APS_PACKET_LENGTH_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid packet length. */
/*  */
#define TLR_E_EIP_APS_PACKET_LENGTH_INVALID ((TLR_RESULT)0xC0590002L)

/*  */
/*  MessageId: TLR_E_EIP_APS_PACKET_PARAMETER_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Parameter of the packet are invalid. */
/*  */
#define TLR_E_EIP_APS_PACKET_PARAMETER_INVALID ((TLR_RESULT)0xC0590003L)

/*  */
/*  MessageId: TLR_E_EIP_APS_TCP_CONFIG_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Configuration of TCP/IP failed. */
/*  */
#define TLR_E_EIP_APS_TCP_CONFIG_FAIL    ((TLR_RESULT)0xC0590004L)

/*  */
/*  MessageId: TLR_E_EIP_APS_CONNECTION_CLOSED */
/*  */
/*  MessageText: */
/*  */
/*   Existing connection is closed. */
/*  */
#define TLR_E_EIP_APS_CONNECTION_CLOSED  ((TLR_RESULT)0xC0590005L)

/*  */
/*  MessageId: TLR_E_EIP_APS_ALREADY_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   A application is already registered. */
/*  */
#define TLR_E_EIP_APS_ALREADY_REGISTERED ((TLR_RESULT)0xC0590006L)

/*  */
/*  MessageId: TLR_E_EIP_APS_ACCESS_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Command is not allowed. */
/*  */
#define TLR_E_EIP_APS_ACCESS_FAIL        ((TLR_RESULT)0xC0590007L)

/*  */
/*  MessageId: TLR_E_EIP_APS_STATE_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Command not allowed at this state. */
/*  */
#define TLR_E_EIP_APS_STATE_FAIL         ((TLR_RESULT)0xC0590008L)

/*  */
/*  MessageId: TLR_E_EIP_APS_IO_OFFSET_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid offset for I/O data. */
/*  */
#define TLR_E_EIP_APS_IO_OFFSET_INVALID  ((TLR_RESULT)0xC0590009L)

/*  */
/*  MessageId: TLR_E_EIP_APS_FOLDER_NOT_FOUND */
/*  */
/*  MessageText: */
/*  */
/*   Folder for database not found. */
/*  */
#define TLR_E_EIP_APS_FOLDER_NOT_FOUND   ((TLR_RESULT)0xC059000AL)

/*  */
/*  MessageId: TLR_E_EIP_APS_CONFIG_DBM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Configuration database invalid. */
/*  */
#define TLR_E_EIP_APS_CONFIG_DBM_INVALID ((TLR_RESULT)0xC059000BL)

/*  */
/*  MessageId: TLR_E_EIP_APS_NO_CONFIG_DBM */
/*  */
/*  MessageText: */
/*  */
/*   Configuration database not found. */
/*  */
#define TLR_E_EIP_APS_NO_CONFIG_DBM      ((TLR_RESULT)0xC059000CL)

/*  */
/*  MessageId: TLR_E_EIP_APS_NWID_DBM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   network database invalid. */
/*  */
#define TLR_E_EIP_APS_NWID_DBM_INVALID   ((TLR_RESULT)0xC059000DL)

/*  */
/*  MessageId: TLR_E_EIP_APS_NO_NWID_DBM */
/*  */
/*  MessageText: */
/*  */
/*   network database not found. */
/*  */
#define TLR_E_EIP_APS_NO_NWID_DBM        ((TLR_RESULT)0xC059000EL)

/*  */
/*  MessageId: TLR_E_EIP_APS_NO_DBM */
/*  */
/*  MessageText: */
/*  */
/*   no database found. */
/*  */
#define TLR_E_EIP_APS_NO_DBM             ((TLR_RESULT)0xC059000FL)




#endif  /* __EIP_APS_ERROR_H */

#ifndef __EIP_ENCAP_ERROR_H
#define __EIP_ENCAP_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Ethernet/IP Encapsulation */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_EIP_ENCAP_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_EIP_ENCAP_COMMAND_INVALID  ((TLR_RESULT)0xC01E0001L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   Encapsulation layer is not initialized. */
/*  */
#define TLR_E_EIP_ENCAP_NOT_INITIALIZED  ((TLR_RESULT)0xC01E0002L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   System is out of memory. */
/*  */
#define TLR_E_EIP_ENCAP_OUT_OF_MEMORY    ((TLR_RESULT)0xC01E0003L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_OUT_OF_PACKETS */
/*  */
/*  MessageText: */
/*  */
/*   Task runs out of empty packets at the local packet pool. */
/*  */
#define TLR_E_EIP_ENCAP_OUT_OF_PACKETS   ((TLR_RESULT)0xC01E0010L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_SEND_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Sending a packet failed. */
/*  */
#define TLR_E_EIP_ENCAP_SEND_PACKET      ((TLR_RESULT)0xC01E0011L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_SOCKET_OVERRUN */
/*  */
/*  MessageText: */
/*  */
/*   No free socket is available. */
/*  */
#define TLR_E_EIP_ENCAP_SOCKET_OVERRUN   ((TLR_RESULT)0xC01E0012L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_INVALID_SOCKET */
/*  */
/*  MessageText: */
/*  */
/*   Socket ID is invalid. */
/*  */
#define TLR_E_EIP_ENCAP_INVALID_SOCKET   ((TLR_RESULT)0xC01E0013L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_CEP_OVERRUN */
/*  */
/*  MessageText: */
/*  */
/*   Connection could not be open. No resource for a new Connection Endpoint available. */
/*  */
#define TLR_E_EIP_ENCAP_CEP_OVERRUN      ((TLR_RESULT)0xC01E0014L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_UCMM_OVERRUN */
/*  */
/*  MessageText: */
/*  */
/*   Message couldn't send. All Unconnect Message Buffers are in use. */
/*  */
#define TLR_E_EIP_ENCAP_UCMM_OVERRUN     ((TLR_RESULT)0xC01E0015L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_TRANSP_OVERRUN */
/*  */
/*  MessageText: */
/*  */
/*   Connection couldn't be opened. All transports are in use. */
/*  */
#define TLR_E_EIP_ENCAP_TRANSP_OVERRUN   ((TLR_RESULT)0xC01E0016L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_UNKNOWN_CONN_TYP */
/*  */
/*  MessageText: */
/*  */
/*   Received Message include an unknown connection typ. */
/*  */
#define TLR_E_EIP_ENCAP_UNKNOWN_CONN_TYP ((TLR_RESULT)0xC01E0017L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_CONN_CLOSED */
/*  */
/*  MessageText: */
/*  */
/*   Connection was closed. */
/*  */
#define TLR_E_EIP_ENCAP_CONN_CLOSED      ((TLR_RESULT)0xC01E0000L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_CONN_RESETED */
/*  */
/*  MessageText: */
/*  */
/*   Connection is reseted from remote device. */
/*  */
#define TLR_E_EIP_ENCAP_CONN_RESETED     ((TLR_RESULT)0xC01E0019L)

/*  */
/*  MessageId: TLR_S_EIP_ENCAP_CONN_UNREGISTER */
/*  */
/*  MessageText: */
/*  */
/*   We closed the conncetion successful. With an unregister command. */
/*  */
#define TLR_S_EIP_ENCAP_CONN_UNREGISTER  ((TLR_RESULT)0x001E001AL)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_CONN_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Wrong connection state for this service. */
/*  */
#define TLR_E_EIP_ENCAP_CONN_STATE       ((TLR_RESULT)0xC01E001BL)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_CONN_INACTIV */
/*  */
/*  MessageText: */
/*  */
/*   Encapsulation sesson was deactivated */
/*  */
#define TLR_E_EIP_ENCAP_CONN_INACTIV     ((TLR_RESULT)0xC01E001CL)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_INVALID_IPADDR */
/*  */
/*  MessageText: */
/*  */
/*   received an invalid IP address. */
/*  */
#define TLR_E_EIP_ENCAP_INVALID_IPADDR   ((TLR_RESULT)0xC01E001DL)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_INVALID_TRANSP */
/*  */
/*  MessageText: */
/*  */
/*   Invalid transport typ. */
/*  */
#define TLR_E_EIP_ENCAP_INVALID_TRANSP   ((TLR_RESULT)0xC01E001EL)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_TRANSP_INUSE */
/*  */
/*  MessageText: */
/*  */
/*   Transport is still in use. */
/*  */
#define TLR_E_EIP_ENCAP_TRANSP_INUSE     ((TLR_RESULT)0xC01E001FL)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_TRANSP_CLOSED */
/*  */
/*  MessageText: */
/*  */
/*   Transport is closed. */
/*  */
#define TLR_E_EIP_ENCAP_TRANSP_CLOSED    ((TLR_RESULT)0xC01E0020L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_INVALID_MSGID */
/*  */
/*  MessageText: */
/*  */
/*   The received message has a invalid message ID. */
/*  */
#define TLR_E_EIP_ENCAP_INVALID_MSGID    ((TLR_RESULT)0xC01E0021L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_INVALID_MSG */
/*  */
/*  MessageText: */
/*  */
/*   invalid encapsulation message received. */
/*  */
#define TLR_E_EIP_ENCAP_INVALID_MSG      ((TLR_RESULT)0xC01E0022L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_INVALID_MSGLEN */
/*  */
/*  MessageText: */
/*  */
/*   Received message with invalid length. */
/*  */
#define TLR_E_EIP_ENCAP_INVALID_MSGLEN   ((TLR_RESULT)0xC01E0023L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_CL3_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Class 3 connection runs into timeout. */
/*  */
#define TLR_E_EIP_ENCAP_CL3_TIMEOUT      ((TLR_RESULT)0xC01E0030L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_UCMM_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Unconnected message gets a timeout. */
/*  */
#define TLR_E_EIP_ENCAP_UCMM_TIMEOUT     ((TLR_RESULT)0xC01E0031L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_CL1_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Timeout of a class 3 connection. */
/*  */
#define TLR_E_EIP_ENCAP_CL1_TIMEOUT      ((TLR_RESULT)0xC01E0032L)

/*  */
/*  MessageId: TLR_W_EIP_ENCAP_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Encapsulation service is finished by timeout. */
/*  */
#define TLR_W_EIP_ENCAP_TIMEOUT          ((TLR_RESULT)0x801E0033L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_CMDRUNNING */
/*  */
/*  MessageText: */
/*  */
/*   Encapsulation service is still running. */
/*  */
#define TLR_E_EIP_ENCAP_CMDRUNNING       ((TLR_RESULT)0xC01E0034L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_NO_TIMER */
/*  */
/*  MessageText: */
/*  */
/*   No empty timer available. */
/*  */
#define TLR_E_EIP_ENCAP_NO_TIMER         ((TLR_RESULT)0xC01E0035L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_INVALID_DATA_IDX */
/*  */
/*  MessageText: */
/*  */
/*   The data index is unknown by the task. Please ensure that it is the same as at the indication. */
/*  */
#define TLR_E_EIP_ENCAP_INVALID_DATA_IDX ((TLR_RESULT)0xC01E0036L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_INVALID_DATA_AREA */
/*  */
/*  MessageText: */
/*  */
/*   The parameter of the data area are invalid. Please check length and offset. */
/*  */
#define TLR_E_EIP_ENCAP_INVALID_DATA_AREA ((TLR_RESULT)0xC01E0037L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_INVALID_DATA_LEN */
/*  */
/*  MessageText: */
/*  */
/*   Packet length is invalid. Please check length of the packet. */
/*  */
#define TLR_E_EIP_ENCAP_INVALID_DATA_LEN ((TLR_RESULT)0xC01E0038L)

/*  */
/*  MessageId: TLR_E_EIP_ENCAP_TASK_RESETING */
/*  */
/*  MessageText: */
/*  */
/*   Ethernet/IP Encapsulation Layer runs a reset. */
/*  */
#define TLR_E_EIP_ENCAP_TASK_RESETING    ((TLR_RESULT)0xC01E0039L)




#endif  /* __EIP_ENCAP_ERROR_H */

#ifndef __EIP_OBJECT_ERROR_H
#define __EIP_OBJECT_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Ethernet/IP Object */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_EIP_OBJECT_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_EIP_OBJECT_COMMAND_INVALID ((TLR_RESULT)0xC01F0001L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   System is out of memory. */
/*  */
#define TLR_E_EIP_OBJECT_OUT_OF_MEMORY   ((TLR_RESULT)0xC01F0002L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_OUT_OF_PACKETS */
/*  */
/*  MessageText: */
/*  */
/*   Task runs out of empty packets at the local packet pool. */
/*  */
#define TLR_E_EIP_OBJECT_OUT_OF_PACKETS  ((TLR_RESULT)0xC01F0003L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_SEND_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Sending a packet failed. */
/*  */
#define TLR_E_EIP_OBJECT_SEND_PACKET     ((TLR_RESULT)0xC01F0004L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_AS_ALLREADY_EXIST */
/*  */
/*  MessageText: */
/*  */
/*   Assembly instance already exist. */
/*  */
#define TLR_E_EIP_OBJECT_AS_ALLREADY_EXIST ((TLR_RESULT)0xC01F0010L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_AS_INVALID_INST */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Assembly Instance. */
/*  */
#define TLR_E_EIP_OBJECT_AS_INVALID_INST ((TLR_RESULT)0xC01F0011L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_AS_INVALID_LEN */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Assembly length. */
/*  */
#define TLR_E_EIP_OBJECT_AS_INVALID_LEN  ((TLR_RESULT)0xC01F0012L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_CONN_OVERRUN */
/*  */
/*  MessageText: */
/*  */
/*   No free connection buffer available */
/*  */
#define TLR_E_EIP_OBJECT_CONN_OVERRUN    ((TLR_RESULT)0xC01F0020L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_INVALID_CLASS */
/*  */
/*  MessageText: */
/*  */
/*   Object class is invalid. */
/*  */
#define TLR_E_EIP_OBJECT_INVALID_CLASS   ((TLR_RESULT)0xC01F0021L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_SEGMENT_FAULT */
/*  */
/*  MessageText: */
/*  */
/*   Segment of the path is invalid. */
/*  */
#define TLR_E_EIP_OBJECT_SEGMENT_FAULT   ((TLR_RESULT)0xC01F0022L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_CLASS_ALLREADY_EXIST */
/*  */
/*  MessageText: */
/*  */
/*   Object Class is already used. */
/*  */
#define TLR_E_EIP_OBJECT_CLASS_ALLREADY_EXIST ((TLR_RESULT)0xC01F0023L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_CONNECTION_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Connection failed. */
/*  */
#define TLR_E_EIP_OBJECT_CONNECTION_FAIL ((TLR_RESULT)0xC01F0024L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_CONNECTION_PARAM */
/*  */
/*  MessageText: */
/*  */
/*   Unknown format of connection parameter */
/*  */
#define TLR_E_EIP_OBJECT_CONNECTION_PARAM ((TLR_RESULT)0xC01F0025L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_UNKNOWN_CONNECTION */
/*  */
/*  MessageText: */
/*  */
/*   Invalid connection ID. */
/*  */
#define TLR_E_EIP_OBJECT_UNKNOWN_CONNECTION ((TLR_RESULT)0xC01F0026L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_NO_OBJ_RESSOURCE */
/*  */
/*  MessageText: */
/*  */
/*   No resource for creating a new class object available. */
/*  */
#define TLR_E_EIP_OBJECT_NO_OBJ_RESSOURCE ((TLR_RESULT)0xC01F0027L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_ID_INVALID_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid request parameter. */
/*  */
#define TLR_E_EIP_OBJECT_ID_INVALID_PARAMETER ((TLR_RESULT)0xC01F0028L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_CONNECTION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   General connection failure. See also General Error Code and Extended Error Code for more details. */
/*  */
#define TLR_E_EIP_OBJECT_CONNECTION_FAILED ((TLR_RESULT)0xC01F0029L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_PACKET_LEN */
/*  */
/*  MessageText: */
/*  */
/*   Packet length of the request is invalid. */
/*  */
#define TLR_E_EIP_OBJECT_PACKET_LEN      ((TLR_RESULT)0xC01F0030L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_READONLY_INST */
/*  */
/*  MessageText: */
/*  */
/*   Access denied. Instance is read only. */
/*  */
#define TLR_E_EIP_OBJECT_READONLY_INST   ((TLR_RESULT)0xC01F0031L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_DPM_USED */
/*  */
/*  MessageText: */
/*  */
/*   DPM address is already used by an other instance. */
/*  */
#define TLR_E_EIP_OBJECT_DPM_USED        ((TLR_RESULT)0xC01F0032L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_SET_OUTPUT_RUNNING */
/*  */
/*  MessageText: */
/*  */
/*   Set Output command is already runnning. */
/*  */
#define TLR_E_EIP_OBJECT_SET_OUTPUT_RUNNING ((TLR_RESULT)0xC01F0033L)

/*  */
/*  MessageId: TLR_E_EIP_OBJECT_TASK_RESETING */
/*  */
/*  MessageText: */
/*  */
/*   Etthernet/IP Object Task is running a reset. */
/*  */
#define TLR_E_EIP_OBJECT_TASK_RESETING   ((TLR_RESULT)0xC01F0034L)




#endif  /* __EIP_OBJECT_ERROR_H */

#ifndef __EPL_ERROR_H
#define __EPL_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  POWERLINK EPL PDO Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_EPL_PDO_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_EPL_PDO_COMMAND_INVALID    ((TLR_RESULT)0xC0150001L)

/*  */
/*  MessageId: TLR_E_EPL_PDO_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup parameter. */
/*  */
#define TLR_E_EPL_PDO_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0150002L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  POWERLINK EPL SDO Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_EPL_SDO_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_EPL_SDO_COMMAND_INVALID    ((TLR_RESULT)0xC0160001L)

/*  */
/*  MessageId: TLR_E_EPL_SDO_PROTOCOL_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   SDO Protocol timeout. */
/*  */
#define TLR_E_EPL_SDO_PROTOCOL_TIMEOUT   ((TLR_RESULT)0xC0160002L)

/*  */
/*  MessageId: TLR_E_EPL_SDO_SCS_SPECIFIER_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Client/Server command specifier not valid or unknown. */
/*  */
#define TLR_E_EPL_SDO_SCS_SPECIFIER_INVALID ((TLR_RESULT)0xC0160003L)

/*  */
/*  MessageId: TLR_E_EPL_SDO_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Out of Memory. */
/*  */
#define TLR_E_EPL_SDO_OUT_OF_MEMORY      ((TLR_RESULT)0xC0160004L)

/*  */
/*  MessageId: TLR_E_EPL_SDO_UNSUPPORTED_ACCESS_TO_OBJECT */
/*  */
/*  MessageText: */
/*  */
/*   Unsupported access to an object. */
/*  */
#define TLR_E_EPL_SDO_UNSUPPORTED_ACCESS_TO_OBJECT ((TLR_RESULT)0xC0160005L)

/*  */
/*  MessageId: TLR_E_EPL_SDO_ATTEMPT_TO_READ_A_WRITE_ONLY_OBJECT */
/*  */
/*  MessageText: */
/*  */
/*   Attempt to read a write only object. */
/*  */
#define TLR_E_EPL_SDO_ATTEMPT_TO_READ_A_WRITE_ONLY_OBJECT ((TLR_RESULT)0xC0160006L)

/*  */
/*  MessageId: TLR_E_EPL_SDO_ATTEMPT_TO_WRITE_A_READ_ONLY_OBJECT */
/*  */
/*  MessageText: */
/*  */
/*   Attempt to write a read only object. */
/*  */
#define TLR_E_EPL_SDO_ATTEMPT_TO_WRITE_A_READ_ONLY_OBJECT ((TLR_RESULT)0xC0160007L)

/*  */
/*  MessageId: TLR_E_EPL_SDO_OBJECT_DOES_NOT_EXIST */
/*  */
/*  MessageText: */
/*  */
/*   The object does not exist in the object dictionary. */
/*  */
#define TLR_E_EPL_SDO_OBJECT_DOES_NOT_EXIST ((TLR_RESULT)0xC0160008L)

/*  */
/*  MessageId: TLR_E_EPL_SDO_OBJECT_CAN_NOT_BE_MAPPED_INTO_THE_PDO */
/*  */
/*  MessageText: */
/*  */
/*   The object can not be mapped into the PDO. */
/*  */
#define TLR_E_EPL_SDO_OBJECT_CAN_NOT_BE_MAPPED_INTO_THE_PDO ((TLR_RESULT)0xC0160009L)

/*  */
/*  MessageId: TLR_E_EPL_SDO_OBJECTS_WOULD_EXCEED_PDO_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   The number and length of the objects to be mapped would exceed the PDO length. */
/*  */
#define TLR_E_EPL_SDO_OBJECTS_WOULD_EXCEED_PDO_LENGTH ((TLR_RESULT)0xC016000AL)

/*  */
/*  MessageId: TLR_E_EPL_SDO_GENERAL_PARAMETER_INCOMPATIBILITY_REASON */
/*  */
/*  MessageText: */
/*  */
/*   General parameter incompatibility reason. */
/*  */
#define TLR_E_EPL_SDO_GENERAL_PARAMETER_INCOMPATIBILITY_REASON ((TLR_RESULT)0xC016000BL)

/*  */
/*  MessageId: TLR_E_EPL_SDO_GENERAL_INTERNAL_INCOMPATIBILITY_IN_DEVICE */
/*  */
/*  MessageText: */
/*  */
/*   General internal incompatibility in the device. */
/*  */
#define TLR_E_EPL_SDO_GENERAL_INTERNAL_INCOMPATIBILITY_IN_DEVICE ((TLR_RESULT)0xC016000CL)

/*  */
/*  MessageId: TLR_E_EPL_SDO_ACCESS_FAILED_DUE_TO_A_HARDWARE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Access failed due to a hardware error. */
/*  */
#define TLR_E_EPL_SDO_ACCESS_FAILED_DUE_TO_A_HARDWARE_ERROR ((TLR_RESULT)0xC016000DL)

/*  */
/*  MessageId: TLR_E_EPL_SDO_DATA_TYPE_DOES_NOT_MATCH_LEN_OF_SRV_PARAM_DOES_NOT_MATCH */
/*  */
/*  MessageText: */
/*  */
/*   Data type does not match, length of service parameter does not match. */
/*  */
#define TLR_E_EPL_SDO_DATA_TYPE_DOES_NOT_MATCH_LEN_OF_SRV_PARAM_DOES_NOT_MATCH ((TLR_RESULT)0xC016000EL)

/*  */
/*  MessageId: TLR_E_EPL_SDO_DATA_TYPE_DOES_NOT_MATCH_LEN_OF_SRV_PARAM_TOO_HIGH */
/*  */
/*  MessageText: */
/*  */
/*   Data type does not match, length of service parameter too high. */
/*  */
#define TLR_E_EPL_SDO_DATA_TYPE_DOES_NOT_MATCH_LEN_OF_SRV_PARAM_TOO_HIGH ((TLR_RESULT)0xC016000FL)

/*  */
/*  MessageId: TLR_E_EPL_SDO_DATA_TYPE_DOES_NOT_MATCH_LEN_OF_SRV_PARAM_TOO_LOW */
/*  */
/*  MessageText: */
/*  */
/*   Data type does not match, length of service parameter too low. */
/*  */
#define TLR_E_EPL_SDO_DATA_TYPE_DOES_NOT_MATCH_LEN_OF_SRV_PARAM_TOO_LOW ((TLR_RESULT)0xC0160010L)

/*  */
/*  MessageId: TLR_E_EPL_SDO_SUBINDEX_DOES_NOT_EXIST */
/*  */
/*  MessageText: */
/*  */
/*   Subindex does not exist. */
/*  */
#define TLR_E_EPL_SDO_SUBINDEX_DOES_NOT_EXIST ((TLR_RESULT)0xC0160011L)

/*  */
/*  MessageId: TLR_E_EPL_SDO_VALUE_RANGE_OF_PARAMETER_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   Value range of parameter exceeded. */
/*  */
#define TLR_E_EPL_SDO_VALUE_RANGE_OF_PARAMETER_EXCEEDED ((TLR_RESULT)0xC0160012L)

/*  */
/*  MessageId: TLR_E_EPL_SDO_VALUE_OF_PARAMETER_WRITTEN_TOO_HIGH */
/*  */
/*  MessageText: */
/*  */
/*   Value of parameter written too high. */
/*  */
#define TLR_E_EPL_SDO_VALUE_OF_PARAMETER_WRITTEN_TOO_HIGH ((TLR_RESULT)0xC0160013L)

/*  */
/*  MessageId: TLR_E_EPL_SDO_VALUE_OF_PARAMETER_WRITTEN_TOO_LOW */
/*  */
/*  MessageText: */
/*  */
/*   Value of parameter written too low. */
/*  */
#define TLR_E_EPL_SDO_VALUE_OF_PARAMETER_WRITTEN_TOO_LOW ((TLR_RESULT)0xC0160014L)

/*  */
/*  MessageId: TLR_E_EPL_SDO_MAXIMUM_VALUE_IS_LESS_THAN_MINIMUM_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Maximum value is less than minimum value. */
/*  */
#define TLR_E_EPL_SDO_MAXIMUM_VALUE_IS_LESS_THAN_MINIMUM_VALUE ((TLR_RESULT)0xC0160015L)

/*  */
/*  MessageId: TLR_E_EPL_SDO_GENERAL_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   General error. */
/*  */
#define TLR_E_EPL_SDO_GENERAL_ERROR      ((TLR_RESULT)0xC0160016L)

/*  */
/*  MessageId: TLR_E_EPL_SDO_DATA_CANNOT_BE_TRANSFERRED_OR_STORED_TO_THE_APP */
/*  */
/*  MessageText: */
/*  */
/*   Data cannot be transferred or stored to the application. */
/*  */
#define TLR_E_EPL_SDO_DATA_CANNOT_BE_TRANSFERRED_OR_STORED_TO_THE_APP ((TLR_RESULT)0xC0160017L)

/*  */
/*  MessageId: TLR_E_EPL_SDO_DATA_NO_TRANSFER_DUE_TO_LOCAL_CONTROL */
/*  */
/*  MessageText: */
/*  */
/*   Data cannot be transferred or stored to the application because of local control. */
/*  */
#define TLR_E_EPL_SDO_DATA_NO_TRANSFER_DUE_TO_LOCAL_CONTROL ((TLR_RESULT)0xC0160018L)

/*  */
/*  MessageId: TLR_E_EPL_SDO_DATA_NO_TRANSFER_DUE_TO_PRESENT_DEVICE_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Data cannot be transferred or stored to the application because of present device state. */
/*  */
#define TLR_E_EPL_SDO_DATA_NO_TRANSFER_DUE_TO_PRESENT_DEVICE_STATE ((TLR_RESULT)0xC0160019L)

/*  */
/*  MessageId: TLR_E_EPL_SDO_NO_OBJECT_DICTIONARY_PRESENT */
/*  */
/*  MessageText: */
/*  */
/*   Object dictionary dynamic generation fails or no object dictionary present. */
/*  */
#define TLR_E_EPL_SDO_NO_OBJECT_DICTIONARY_PRESENT ((TLR_RESULT)0xC016001AL)

/*  */
/*  MessageId: TLR_E_EPL_SDO_UNKNOWN_ABORT_CODE */
/*  */
/*  MessageText: */
/*  */
/*   Unknown SDO abort code. */
/*  */
#define TLR_E_EPL_SDO_UNKNOWN_ABORT_CODE ((TLR_RESULT)0xC016001BL)

/*  */
/*  MessageId: TLR_E_EPL_CONN_BUFFER_FULL */
/*  */
/*  MessageText: */
/*  */
/*   Connection buffer full. */
/*  */
#define TLR_E_EPL_CONN_BUFFER_FULL       ((TLR_RESULT)0xC016001CL)

/*  */
/*  MessageId: TLR_E_EPL_SDO_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup parameter. */
/*  */
#define TLR_E_EPL_SDO_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC016001DL)

/*  */
/*  MessageId: TLR_E_EPLCN_SDO_OD_DPM_MODE_OBJECTS_CAN_ONLY_BE_READONLY */
/*  */
/*  MessageText: */
/*  */
/*   DPM Mode Objects can only be set readonly. */
/*  */
#define TLR_E_EPLCN_SDO_OD_DPM_MODE_OBJECTS_CAN_ONLY_BE_READONLY ((TLR_RESULT)0xC016001EL)

/*  */
/*  MessageId: TLR_E_EPLCN_SDO_OD_DPM_MODE_OBJECTS_DIRECTION_PARAMETER_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid direction parameter for DPM Mode Objects. */
/*  */
#define TLR_E_EPLCN_SDO_OD_DPM_MODE_OBJECTS_DIRECTION_PARAMETER_INVALID ((TLR_RESULT)0xC016001FL)

/*  */
/*  MessageId: TLR_E_EPLCN_SDO_OD_DPM_MODE_SUBOBJECT_OFFSET_OUT_OF_RANGE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid offset parameter for DPM Mode Objects. */
/*  */
#define TLR_E_EPLCN_SDO_OD_DPM_MODE_SUBOBJECT_OFFSET_OUT_OF_RANGE ((TLR_RESULT)0xC0160020L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  POWERLINK EPL ALI Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_EPL_ALI_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_EPL_ALI_COMMAND_INVALID    ((TLR_RESULT)0xC0180001L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  POWERLINK EPL NMT Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_EPL_NMT_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_EPL_NMT_COMMAND_INVALID    ((TLR_RESULT)0xC0170001L)

/*  */
/*  MessageId: TLR_E_EPL_NMT_OUTPUT_DATA_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Output data invalid. */
/*  */
#define TLR_E_EPL_NMT_OUTPUT_DATA_INVALID ((TLR_RESULT)0xC0170002L)

/*  */
/*  MessageId: TLR_E_EPL_NMT_INPUT_DATA_OVERSIZED */
/*  */
/*  MessageText: */
/*  */
/*   Input data oversized. */
/*  */
#define TLR_E_EPL_NMT_INPUT_DATA_OVERSIZED ((TLR_RESULT)0xC0170003L)

/*  */
/*  MessageId: TLR_E_EPL_NMT_NODE_INPUT_DATA_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Node-specific Input data invalid. */
/*  */
#define TLR_E_EPL_NMT_NODE_INPUT_DATA_INVALID ((TLR_RESULT)0xC0170004L)

/*  */
/*  MessageId: TLR_E_EPL_NMT_PDO_DOES_NOT_EXIST */
/*  */
/*  MessageText: */
/*  */
/*   Node-specific PDO does not exist. */
/*  */
#define TLR_E_EPL_NMT_PDO_DOES_NOT_EXIST ((TLR_RESULT)0xC0170005L)

/*  */
/*  MessageId: TLR_E_EPL_NMT_PDO_EXISTS */
/*  */
/*  MessageText: */
/*  */
/*   Node-specific PDO exists. */
/*  */
#define TLR_E_EPL_NMT_PDO_EXISTS         ((TLR_RESULT)0xC0170006L)

/*  */
/*  MessageId: TLR_E_EPL_NMT_PDO_EXCEEDS_POLL_IN_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   PDO will exceed Poll In size. */
/*  */
#define TLR_E_EPL_NMT_PDO_EXCEEDS_POLL_IN_SIZE ((TLR_RESULT)0xC0170007L)

/*  */
/*  MessageId: TLR_E_EPL_NMT_PDO_EXCEEDS_POLL_OUT_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   PDO will exceed Poll Out size. */
/*  */
#define TLR_E_EPL_NMT_PDO_EXCEEDS_POLL_OUT_SIZE ((TLR_RESULT)0xC0170008L)

/*  */
/*  MessageId: TLR_E_EPL_NMT_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup parameter. */
/*  */
#define TLR_E_EPL_NMT_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0170009L)

/*  */
/*  MessageId: TLR_E_EPL_NMT_INVALID_STATE_CHANGE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid state change requested. */
/*  */
#define TLR_E_EPL_NMT_INVALID_STATE_CHANGE ((TLR_RESULT)0xC017000AL)

/*  */
/*  MessageId: TLR_E_EPL_NMT_FAILED_TO_LOCK_MUTEX */
/*  */
/*  MessageText: */
/*  */
/*   Failed to lock mutex. */
/*  */
#define TLR_E_EPL_NMT_FAILED_TO_LOCK_MUTEX ((TLR_RESULT)0xC017000BL)

/*  */
/*  MessageId: TLR_E_EPL_NMT_COULD_NOT_CREATE_SDO_MUTEX */
/*  */
/*  MessageText: */
/*  */
/*   Could not create SDO mutex. */
/*  */
#define TLR_E_EPL_NMT_COULD_NOT_CREATE_SDO_MUTEX ((TLR_RESULT)0xC017000CL)

/*  */
/*  MessageId: TLR_E_EPL_NMT_COULD_NOT_CREATE_NMT_MUTEX */
/*  */
/*  MessageText: */
/*  */
/*   Could not create NMT mutex. */
/*  */
#define TLR_E_EPL_NMT_COULD_NOT_CREATE_NMT_MUTEX ((TLR_RESULT)0xC017000DL)

/*  */
/*  MessageId: TLR_E_EPL_NMT_COULD_NOT_CREATE_ERRH_MUTEX */
/*  */
/*  MessageText: */
/*  */
/*   Could not create Error Handling mutex. */
/*  */
#define TLR_E_EPL_NMT_COULD_NOT_CREATE_ERRH_MUTEX ((TLR_RESULT)0xC017000EL)

/*  */
/*  MessageId: TLR_E_EPL_NMT_COULD_NOT_CREATE_SDO_TASK */
/*  */
/*  MessageText: */
/*  */
/*   Could not create SDO task. */
/*  */
#define TLR_E_EPL_NMT_COULD_NOT_CREATE_SDO_TASK ((TLR_RESULT)0xC017000FL)

/*  */
/*  MessageId: TLR_E_EPL_NMT_COULD_NOT_CREATE_NMT_TASK */
/*  */
/*  MessageText: */
/*  */
/*   Could not create NMT task. */
/*  */
#define TLR_E_EPL_NMT_COULD_NOT_CREATE_NMT_TASK ((TLR_RESULT)0xC0170010L)

/*  */
/*  MessageId: TLR_E_EPL_NMT_COULD_NOT_CREATE_SDO_SIGNAL */
/*  */
/*  MessageText: */
/*  */
/*   Could not create SDO signal. */
/*  */
#define TLR_E_EPL_NMT_COULD_NOT_CREATE_SDO_SIGNAL ((TLR_RESULT)0xC0170011L)

/*  */
/*  MessageId: TLR_E_EPL_NMT_COULD_NOT_CREATE_NMT_SIGNAL */
/*  */
/*  MessageText: */
/*  */
/*   Could not create NMT signal. */
/*  */
#define TLR_E_EPL_NMT_COULD_NOT_CREATE_NMT_SIGNAL ((TLR_RESULT)0xC0170012L)

/*  */
/*  MessageId: TLR_E_EPL_NMT_COULD_NOT_CREATE_BASIC_ETH_TIMER */
/*  */
/*  MessageText: */
/*  */
/*   Could not create Basic Ethernet timer. */
/*  */
#define TLR_E_EPL_NMT_COULD_NOT_CREATE_BASIC_ETH_TIMER ((TLR_RESULT)0xC0170013L)

/*  */
/*  MessageId: TLR_E_EPL_NMT_COULD_NOT_CREATE_SOC_TIMER */
/*  */
/*  MessageText: */
/*  */
/*   Could not create SoC timer. */
/*  */
#define TLR_E_EPL_NMT_COULD_NOT_CREATE_SOC_TIMER ((TLR_RESULT)0xC0170014L)

/*  */
/*  MessageId: TLR_E_EPL_NMT_COULD_NOT_CREATE_SEQU_LAYER_TIMER */
/*  */
/*  MessageText: */
/*  */
/*   Could not create Sequence Layer timer. */
/*  */
#define TLR_E_EPL_NMT_COULD_NOT_CREATE_SEQU_LAYER_TIMER ((TLR_RESULT)0xC0170015L)

/*  */
/*  MessageId: TLR_E_EPL_NMT_COULD_NOT_CREATE_OBJECT_DICTIONARY */
/*  */
/*  MessageText: */
/*  */
/*   Could not create object dictionary. */
/*  */
#define TLR_E_EPL_NMT_COULD_NOT_CREATE_OBJECT_DICTIONARY ((TLR_RESULT)0xC0170016L)

/*  */
/*  MessageId: TLR_E_EPL_NMT_EMERGENCY_QUEUE_OVERFLOW */
/*  */
/*  MessageText: */
/*  */
/*   Emergency Queue overflow. */
/*  */
#define TLR_E_EPL_NMT_EMERGENCY_QUEUE_OVERFLOW ((TLR_RESULT)0xC0170017L)

/*  */
/*  MessageId: TLR_E_EPL_NMT_INVALID_STATUS_ENTRY_INDEX */
/*  */
/*  MessageText: */
/*  */
/*   Invalid status entry index. */
/*  */
#define TLR_E_EPL_NMT_INVALID_STATUS_ENTRY_INDEX ((TLR_RESULT)0xC0170018L)

/*  */
/*  MessageId: TLR_E_EPL_NMT_COULD_NOT_LOCK_MUTEX */
/*  */
/*  MessageText: */
/*  */
/*   Could not lock mutex. */
/*  */
#define TLR_E_EPL_NMT_COULD_NOT_LOCK_MUTEX ((TLR_RESULT)0xC0170019L)

/*  */
/*  MessageId: TLR_E_EPL_NMT_INVALID_STATIC_BIT_FIELD_NUMBER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid static bit field bit number. */
/*  */
#define TLR_E_EPL_NMT_INVALID_STATIC_BIT_FIELD_NUMBER ((TLR_RESULT)0xC017001AL)

/*  */
/*  MessageId: TLR_E_EPL_NMT_NO_MORE_APP_HANDLES */
/*  */
/*  MessageText: */
/*  */
/*   No more App handles. */
/*  */
#define TLR_E_EPL_NMT_NO_MORE_APP_HANDLES ((TLR_RESULT)0xC017001BL)

/*  */
/*  MessageId: TLR_E_EPL_NMT_APP_NOT_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   Application queue is not registered. */
/*  */
#define TLR_E_EPL_NMT_APP_NOT_REGISTERED ((TLR_RESULT)0xC017001CL)

/*  */
/*  MessageId: TLR_E_EPL_NMT_APP_ALREADY_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   Application queue is already registered. */
/*  */
#define TLR_E_EPL_NMT_APP_ALREADY_REGISTERED ((TLR_RESULT)0xC017001DL)

/*  */
/*  MessageId: TLR_E_EPL_NMT_FAILED_TO_INITIALIZE_EPLCN_INTERFACE */
/*  */
/*  MessageText: */
/*  */
/*   EplCn-Interface could not be initialized. */
/*  */
#define TLR_E_EPL_NMT_FAILED_TO_INITIALIZE_EPLCN_INTERFACE ((TLR_RESULT)0xC017001EL)

/*  */
/*  MessageId: TLR_E_EPL_NMT_INVALID_PARAMETERS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Parameters. */
/*  */
#define TLR_E_EPL_NMT_INVALID_PARAMETERS ((TLR_RESULT)0xC017001FL)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  POWERLINK EPL MN Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_EPL_MN_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_EPL_MN_COMMAND_INVALID     ((TLR_RESULT)0xC03D0001L)

/*  */
/*  MessageId: TLR_E_EPL_MN_CN_EXISTS */
/*  */
/*  MessageText: */
/*  */
/*   CN exists already. */
/*  */
#define TLR_E_EPL_MN_CN_EXISTS           ((TLR_RESULT)0xC03D0002L)

/*  */
/*  MessageId: TLR_E_EPL_MN_CN_DOES_NOT_EXIST */
/*  */
/*  MessageText: */
/*  */
/*   CN does not exist. */
/*  */
#define TLR_E_EPL_MN_CN_DOES_NOT_EXIST   ((TLR_RESULT)0xC03D0003L)

/*  */
/*  MessageId: TLR_E_EPL_MN_CN_ALREADY_CONNECTED */
/*  */
/*  MessageText: */
/*  */
/*   CN already connected. */
/*  */
#define TLR_E_EPL_MN_CN_ALREADY_CONNECTED ((TLR_RESULT)0xC03D0004L)

/*  */
/*  MessageId: TLR_E_EPL_MN_CN_NO_OUTPUT_DATA */
/*  */
/*  MessageText: */
/*  */
/*   CN has no valid output data. */
/*  */
#define TLR_E_EPL_MN_CN_NO_OUTPUT_DATA   ((TLR_RESULT)0xC03D0005L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  POWERLINK EPL PLD Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_EPL_PLD_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_EPL_PLD_COMMAND_INVALID    ((TLR_RESULT)0xC0190001L)




#endif  /* __EPL_ERROR_H */

#ifndef __ETH_INTF_ERROR_H
#define __ETH_INTF_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Ethernet Interface Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_ETH_INTF_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_ETH_INTF_COMMAND_INVALID   ((TLR_RESULT)0xC05D0001L)

/*  */
/*  MessageId: TLR_E_ETH_INTF_CONFIG_LOCK */
/*  */
/*  MessageText: */
/*  */
/*   Configuration is locked. */
/*  */
#define TLR_E_ETH_INTF_CONFIG_LOCK       ((TLR_RESULT)0xC05D0002L)

/*  */
/*  MessageId: TLR_E_ETH_INTF_INVALID_PACKET_LENGHT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid packet length. */
/*  */
#define TLR_E_ETH_INTF_INVALID_PACKET_LENGHT ((TLR_RESULT)0xC05D0003L)

/*  */
/*  MessageId: TLR_E_ETH_INTF_INVALID_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid mode in request. */
/*  */
#define TLR_E_ETH_INTF_INVALID_MODE      ((TLR_RESULT)0xC05D0004L)

/*  */
/*  MessageId: TLR_E_ETH_INTF_PARAM_AUTO_NEGOTIATION_PORT_0 */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for auto-negotiation port 0. */
/*  */
#define TLR_E_ETH_INTF_PARAM_AUTO_NEGOTIATION_PORT_0 ((TLR_RESULT)0xC05D0005L)

/*  */
/*  MessageId: TLR_E_ETH_INTF_PARAM_AUTO_NEGOTIATION_PORT_1 */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for auto-negotiation port 1. */
/*  */
#define TLR_E_ETH_INTF_PARAM_AUTO_NEGOTIATION_PORT_1 ((TLR_RESULT)0xC05D0006L)

/*  */
/*  MessageId: TLR_E_ETH_INTF_PARAM_DUPLEX_MODE_PORT_0 */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for duplex mode port 0. */
/*  */
#define TLR_E_ETH_INTF_PARAM_DUPLEX_MODE_PORT_0 ((TLR_RESULT)0xC05D0007L)

/*  */
/*  MessageId: TLR_E_ETH_INTF_PARAM_DUPLEX_MODE_PORT_1 */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for duplex mode port 1. */
/*  */
#define TLR_E_ETH_INTF_PARAM_DUPLEX_MODE_PORT_1 ((TLR_RESULT)0xC05D0008L)

/*  */
/*  MessageId: TLR_E_ETH_INTF_PARAM_TRANSMISSION_RATE_PORT_0 */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for transmission rate port 0. */
/*  */
#define TLR_E_ETH_INTF_PARAM_TRANSMISSION_RATE_PORT_0 ((TLR_RESULT)0xC05D0009L)

/*  */
/*  MessageId: TLR_E_ETH_INTF_PARAM_TRANSMISSION_RATE_PORT_1 */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for transmission rate port 1. */
/*  */
#define TLR_E_ETH_INTF_PARAM_TRANSMISSION_RATE_PORT_1 ((TLR_RESULT)0xC05D000AL)

/*  */
/*  MessageId: TLR_E_ETH_INTF_PARAM_AUTO_CROSSOVER_PORT_0 */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for auto cross-over port 0. */
/*  */
#define TLR_E_ETH_INTF_PARAM_AUTO_CROSSOVER_PORT_0 ((TLR_RESULT)0xC05D000BL)

/*  */
/*  MessageId: TLR_E_ETH_INTF_PARAM_AUTO_CROSSOVER_PORT_1 */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for auto cross-over port 1. */
/*  */
#define TLR_E_ETH_INTF_PARAM_AUTO_CROSSOVER_PORT_1 ((TLR_RESULT)0xC05D000CL)

/*  */
/*  MessageId: TLR_E_ETH_INTF_NO_CONFIGURATION */
/*  */
/*  MessageText: */
/*  */
/*   Task is not configured. */
/*  */
#define TLR_E_ETH_INTF_NO_CONFIGURATION  ((TLR_RESULT)0xC05D000DL)

/*  */
/*  MessageId: TLR_E_ETH_INTF_APP_NOT_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   No application registered. */
/*  */
#define TLR_E_ETH_INTF_APP_NOT_REGISTERED ((TLR_RESULT)0xC05D000EL)

/*  */
/*  MessageId: TLR_E_ETH_INTF_APP_SET_NOT_READY */
/*  */
/*  MessageText: */
/*  */
/*   Application set not ready. */
/*  */
#define TLR_E_ETH_INTF_APP_SET_NOT_READY ((TLR_RESULT)0xC05D000FL)

/*  */
/*  MessageId: TLR_E_ETH_INTF_LINK_DOWN */
/*  */
/*  MessageText: */
/*  */
/*   No Ethernet link. */
/*  */
#define TLR_E_ETH_INTF_LINK_DOWN         ((TLR_RESULT)0xC05D0010L)

/*  */
/*  MessageId: TLR_E_ETH_INTF_GET_SEND_BUFFER */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get send buffer. */
/*  */
#define TLR_E_ETH_INTF_GET_SEND_BUFFER   ((TLR_RESULT)0xC05D0011L)

/*  */
/*  MessageId: TLR_E_ETH_INTF_SEND_FRAME */
/*  */
/*  MessageText: */
/*  */
/*   Failed to send Ethernet frame. */
/*  */
#define TLR_E_ETH_INTF_SEND_FRAME        ((TLR_RESULT)0xC05D0012L)

/*  */
/*  MessageId: TLR_E_ETH_INTF_SET_DRV_EDD_CFG */
/*  */
/*  MessageText: */
/*  */
/*   Failed to set driver EDD configuration. */
/*  */
#define TLR_E_ETH_INTF_SET_DRV_EDD_CFG   ((TLR_RESULT)0xC05D0013L)

/*  */
/*  MessageId: TLR_E_ETH_INTF_INVALID_ETH_PORT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for ethernet port. */
/*  */
#define TLR_E_ETH_INTF_INVALID_ETH_PORT  ((TLR_RESULT)0xC05D0014L)

/*  */
/*  MessageId: TLR_E_ETH_INTF_UNKNOWN_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Unknown error detected. */
/*  */
#define TLR_E_ETH_INTF_UNKNOWN_ERROR     ((TLR_RESULT)0xC05DFFFFL)




#endif  /* __ETH_INTF_ERROR_H */

#ifndef __ETHERCATMASTER_ERROR_H
#define __ETHERCATMASTER_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  EtherCAT Master Packet Status codes (EtherCAT Master Stack) */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_ETHERCAT_MASTER_COMMAND_INVALID ((TLR_RESULT)0xC0650001L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_NO_LINK */
/*  */
/*  MessageText: */
/*  */
/*   No link exists. */
/*  */
#define TLR_E_ETHERCAT_MASTER_NO_LINK    ((TLR_RESULT)0xC0650002L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_ERROR_READING_BUSCONFIG */
/*  */
/*  MessageText: */
/*  */
/*   Error during reading the bus configuration. */
/*  */
#define TLR_E_ETHERCAT_MASTER_ERROR_READING_BUSCONFIG ((TLR_RESULT)0xC0650003L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_ERROR_PARSING_BUSCONFIG */
/*  */
/*  MessageText: */
/*  */
/*   Error during processing the bus configuration. */
/*  */
#define TLR_E_ETHERCAT_MASTER_ERROR_PARSING_BUSCONFIG ((TLR_RESULT)0xC0650004L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_ERROR_BUSSCAN_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Existing bus does not match configured bus. */
/*  */
#define TLR_E_ETHERCAT_MASTER_ERROR_BUSSCAN_FAILED ((TLR_RESULT)0xC0650005L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_NOT_ALL_SLAVES_AVAIL */
/*  */
/*  MessageText: */
/*  */
/*   Not all slaves are available. */
/*  */
#define TLR_E_ETHERCAT_MASTER_NOT_ALL_SLAVES_AVAIL ((TLR_RESULT)0xC0650006L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_STOPMASTER_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error during Reset (stopping the master). */
/*  */
#define TLR_E_ETHERCAT_MASTER_STOPMASTER_ERROR ((TLR_RESULT)0xC0650007L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_DEINITMASTER_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error during Reset (deinitialize the master). */
/*  */
#define TLR_E_ETHERCAT_MASTER_DEINITMASTER_ERROR ((TLR_RESULT)0xC0650008L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_CLEANUP_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error during Reset (cleanup the dynamic resources). */
/*  */
#define TLR_E_ETHERCAT_MASTER_CLEANUP_ERROR ((TLR_RESULT)0xC0650009L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_CRITIAL_ERROR_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Master is in critical error state, reset required. */
/*  */
#define TLR_E_ETHERCAT_MASTER_CRITIAL_ERROR_STATE ((TLR_RESULT)0xC065000AL)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_INVALID_BUSCYCLETIME */
/*  */
/*  MessageText: */
/*  */
/*   The requested bus cycle time is invalid. */
/*  */
#define TLR_E_ETHERCAT_MASTER_INVALID_BUSCYCLETIME ((TLR_RESULT)0xC065000BL)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_INVALID_BROKEN_SLAVE_BEHAVIOUR_PARA */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for broken slave behaviour. */
/*  */
#define TLR_E_ETHERCAT_MASTER_INVALID_BROKEN_SLAVE_BEHAVIOUR_PARA ((TLR_RESULT)0xC065000CL)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_WRONG_INTERNAL_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Master is in wrong internal state. */
/*  */
#define TLR_E_ETHERCAT_MASTER_WRONG_INTERNAL_STATE ((TLR_RESULT)0xC065000DL)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_WATCHDOG_TIMEOUT_EXPIRED */
/*  */
/*  MessageText: */
/*  */
/*   The watchdog expired. */
/*  */
#define TLR_E_ETHERCAT_MASTER_WATCHDOG_TIMEOUT_EXPIRED ((TLR_RESULT)0xC065000EL)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_COE_INVALID_SLAVEID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid SlaveId was used for CoE. */
/*  */
#define TLR_E_ETHERCAT_MASTER_COE_INVALID_SLAVEID ((TLR_RESULT)0xC065000FL)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_COE_NO_RESOURCE */
/*  */
/*  MessageText: */
/*  */
/*   No available resources for CoE transfer. */
/*  */
#define TLR_E_ETHERCAT_MASTER_COE_NO_RESOURCE ((TLR_RESULT)0xC0650010L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_COE_INTERNAL_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Internal error during CoE usage. */
/*  */
#define TLR_E_ETHERCAT_MASTER_COE_INTERNAL_ERROR ((TLR_RESULT)0xC0650011L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_COE_INVALID_INDEX */
/*  */
/*  MessageText: */
/*  */
/*   Invalid slave index requested. */
/*  */
#define TLR_E_ETHERCAT_MASTER_COE_INVALID_INDEX ((TLR_RESULT)0xC0650012L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_COE_INVALID_COMMUNICATION_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid bus communication state for CoE usage. */
/*  */
#define TLR_E_ETHERCAT_MASTER_COE_INVALID_COMMUNICATION_STATE ((TLR_RESULT)0xC0650013L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_COE_FRAME_LOST */
/*  */
/*  MessageText: */
/*  */
/*   Frame with CoE data is lost. */
/*  */
#define TLR_E_ETHERCAT_MASTER_COE_FRAME_LOST ((TLR_RESULT)0xC0650014L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_COE_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Timeout during CoE service. */
/*  */
#define TLR_E_ETHERCAT_MASTER_COE_TIMEOUT ((TLR_RESULT)0xC0650015L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_COE_SLAVE_NOT_ADDRESSABLE */
/*  */
/*  MessageText: */
/*  */
/*   Slave is not addressable (not on bus or power down?). */
/*  */
#define TLR_E_ETHERCAT_MASTER_COE_SLAVE_NOT_ADDRESSABLE ((TLR_RESULT)0xC0650016L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_COE_INVALID_LIST_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid list type requested (during GetOdList). */
/*  */
#define TLR_E_ETHERCAT_MASTER_COE_INVALID_LIST_TYPE ((TLR_RESULT)0xC0650017L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_COE_SLAVE_RESPONSE_TOO_BIG */
/*  */
/*  MessageText: */
/*  */
/*   Data in Slave Response is too big for confirmation packet. */
/*  */
#define TLR_E_ETHERCAT_MASTER_COE_SLAVE_RESPONSE_TOO_BIG ((TLR_RESULT)0xC0650018L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_COE_INVALID_ACCESSBITMASK */
/*  */
/*  MessageText: */
/*  */
/*   Invalid access mask selected (during GetEntryDesc). */
/*  */
#define TLR_E_ETHERCAT_MASTER_COE_INVALID_ACCESSBITMASK ((TLR_RESULT)0xC0650019L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_COE_WKC_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Slave Working Counter error during CoE service. */
/*  */
#define TLR_E_ETHERCAT_MASTER_COE_WKC_ERROR ((TLR_RESULT)0xC065001AL)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_SERVICE_IN_USE */
/*  */
/*  MessageText: */
/*  */
/*   The service is already in use. */
/*  */
#define TLR_E_ETHERCAT_MASTER_SERVICE_IN_USE ((TLR_RESULT)0xC065001BL)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_INVALID_COMMUNICATION_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Command is not useable in this communication state. */
/*  */
#define TLR_E_ETHERCAT_MASTER_INVALID_COMMUNICATION_STATE ((TLR_RESULT)0xC065001CL)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_DC_NOT_ACTIVATED */
/*  */
/*  MessageText: */
/*  */
/*   Distributed Clocks must be activated for this command. */
/*  */
#define TLR_E_ETHERCAT_MASTER_DC_NOT_ACTIVATED ((TLR_RESULT)0xC065001DL)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_BUS_SCAN_CURRENTLY_RUNNING */
/*  */
/*  MessageText: */
/*  */
/*   Bus Scan is currently running. */
/*  */
#define TLR_E_ETHERCAT_MASTER_BUS_SCAN_CURRENTLY_RUNNING ((TLR_RESULT)0xC065001EL)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_BUS_SCAN_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Bus Scan Timeout. No slave found. */
/*  */
#define TLR_E_ETHERCAT_MASTER_BUS_SCAN_TIMEOUT ((TLR_RESULT)0xC065001FL)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_BUS_SCAN_NOT_READY_YET */
/*  */
/*  MessageText: */
/*  */
/*   Bus Scan is not ready yet. */
/*  */
#define TLR_E_ETHERCAT_MASTER_BUS_SCAN_NOT_READY_YET ((TLR_RESULT)0xC0650020L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_BUS_SCAN_INVALID_SLAVE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid slave. No information available. */
/*  */
#define TLR_E_ETHERCAT_MASTER_BUS_SCAN_INVALID_SLAVE ((TLR_RESULT)0xC0650021L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_COE_INVALIDACCESS */
/*  */
/*  MessageText: */
/*  */
/*   Slave does not allow reading or writing (CoE access). */
/*  */
#define TLR_E_ETHERCAT_MASTER_COE_INVALIDACCESS ((TLR_RESULT)0xC0650022L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_COE_NO_MBX_SUPPORT */
/*  */
/*  MessageText: */
/*  */
/*   Slave does not support a mailbox. */
/*  */
#define TLR_E_ETHERCAT_MASTER_COE_NO_MBX_SUPPORT ((TLR_RESULT)0xC0650023L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_COE_NO_COE_SUPPORT */
/*  */
/*  MessageText: */
/*  */
/*   Slave does not support CoE. */
/*  */
#define TLR_E_ETHERCAT_MASTER_COE_NO_COE_SUPPORT ((TLR_RESULT)0xC0650024L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_TASK_CREATION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Task could not be created during runtime. */
/*  */
#define TLR_E_ETHERCAT_MASTER_TASK_CREATION_FAILED ((TLR_RESULT)0xC0650025L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_INVALID_SLAVE_SM_CONFIGURATION */
/*  */
/*  MessageText: */
/*  */
/*   The Sync Manager configuration of a slave is invalid. */
/*  */
#define TLR_E_ETHERCAT_MASTER_INVALID_SLAVE_SM_CONFIGURATION ((TLR_RESULT)0xC0650026L)




#endif  /* __ETHERCATMASTER_ERROR_H */

#ifndef __ETHERCATMASTERAPTASK_ERROR_H
#define __ETHERCATMASTERAPTASK_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  EtherCAT Master AP Packet Status codes (EtherCAT Master AP Task) */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_AP_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_ETHERCAT_MASTER_AP_COMMAND_INVALID ((TLR_RESULT)0xC0640001L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_AP_DPM_WATCHDOG_TIMEOUT_EXPIRED */
/*  */
/*  MessageText: */
/*  */
/*   The watchdog expired. */
/*  */
#define TLR_E_ETHERCAT_MASTER_AP_DPM_WATCHDOG_TIMEOUT_EXPIRED ((TLR_RESULT)0xC0640002L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_AP_WATCHDOG_TIME_TOO_SMALL */
/*  */
/*  MessageText: */
/*  */
/*   The requested Watchdog time is too small. */
/*  */
#define TLR_E_ETHERCAT_MASTER_AP_WATCHDOG_TIME_TOO_SMALL ((TLR_RESULT)0xC0640003L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_AP_WATCHDOG_TIME_TOO_LARGE */
/*  */
/*  MessageText: */
/*  */
/*   The requested Watchdog time is too large. */
/*  */
#define TLR_E_ETHERCAT_MASTER_AP_WATCHDOG_TIME_TOO_LARGE ((TLR_RESULT)0xC0640004L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_AP_WATCHDOG_RESET_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error during Reset (resetting watchdog). */
/*  */
#define TLR_E_ETHERCAT_MASTER_AP_WATCHDOG_RESET_ERROR ((TLR_RESULT)0xC0640005L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_AP_CLEANUP_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error during Reset (cleanup the dynamic resources). */
/*  */
#define TLR_E_ETHERCAT_MASTER_AP_CLEANUP_ERROR ((TLR_RESULT)0xC0640006L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_AP_CRITIAL_ERROR_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Master is in critical error state, reset required. */
/*  */
#define TLR_E_ETHERCAT_MASTER_AP_CRITIAL_ERROR_STATE ((TLR_RESULT)0xC0640007L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_AP_WATCHDOG_ACTIVATE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error activating the watchdog. */
/*  */
#define TLR_E_ETHERCAT_MASTER_AP_WATCHDOG_ACTIVATE_ERROR ((TLR_RESULT)0xC0640008L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_AP_INPUT_DATA_TOO_LARGE */
/*  */
/*  MessageText: */
/*  */
/*   Size of configured input data is larger than cyclic DPM input data size. */
/*  */
#define TLR_E_ETHERCAT_MASTER_AP_INPUT_DATA_TOO_LARGE ((TLR_RESULT)0xC0640009L)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_AP_OUTPUT_DATA_TOO_LARGE */
/*  */
/*  MessageText: */
/*  */
/*   Size of configured output data is larger than cyclic DPM output data size. */
/*  */
#define TLR_E_ETHERCAT_MASTER_AP_OUTPUT_DATA_TOO_LARGE ((TLR_RESULT)0xC064000AL)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_AP_ENABLE_BUS_SYNC_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Bus Synchronus mode could not be activated. */
/*  */
#define TLR_E_ETHERCAT_MASTER_AP_ENABLE_BUS_SYNC_FAILED ((TLR_RESULT)0xC064000BL)

/*  */
/*  MessageId: TLR_E_ETHERCAT_MASTER_AP_TASK_CREATION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Task could not be created during runtime. */
/*  */
#define TLR_E_ETHERCAT_MASTER_AP_TASK_CREATION_FAILED ((TLR_RESULT)0xC064000CL)




#endif  /* __ETHERCATMASTERAPTASK_ERROR_H */

#ifndef __EXAMPLE_TASKS_ERROR_H
#define __EXAMPLE_TASKS_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Example Task 1 Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_EXAMPLETASK1_INVALID_COMMAND */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_EXAMPLETASK1_INVALID_COMMAND ((TLR_RESULT)0xC0030001L)

/*  */
/*  MessageId: TLR_E_EXAMPLETASK1_PROCESS_CANCELED */
/*  */
/*  MessageText: */
/*  */
/*   Cancel process is in progress, command can not be executed. */
/*  */
#define TLR_E_EXAMPLETASK1_PROCESS_CANCELED ((TLR_RESULT)0xC0030002L)

/*  */
/*  MessageId: TLR_I_EXAMPLETASK1_TEST_COUNTER_ODD */
/*  */
/*  MessageText: */
/*  */
/*   Counter value of Test-Command is odd. */
/*  */
#define TLR_I_EXAMPLETASK1_TEST_COUNTER_ODD ((TLR_RESULT)0x40030003L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Example Task 2 Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_EXAMPLETASK2_INVALID_COMMAND */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_EXAMPLETASK2_INVALID_COMMAND ((TLR_RESULT)0xC0040001L)

/*  */
/*  MessageId: TLR_E_EXAMPLETASK2_PROCESS_CANCELED */
/*  */
/*  MessageText: */
/*  */
/*   Cancel process is in progress, command can not be executed. */
/*  */
#define TLR_E_EXAMPLETASK2_PROCESS_CANCELED ((TLR_RESULT)0xC0040002L)

/*  */
/*  MessageId: TLR_I_EXAMPLETASK2_TEST_COUNTER_ODD */
/*  */
/*  MessageText: */
/*  */
/*   Counter value of Test-Command is odd. */
/*  */
#define TLR_I_EXAMPLETASK2_TEST_COUNTER_ODD ((TLR_RESULT)0x40040003L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Example Task 3 Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_EXAMPLETASK3_INVALID_COMMAND */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_EXAMPLETASK3_INVALID_COMMAND ((TLR_RESULT)0xC0050001L)

/*  */
/*  MessageId: TLR_E_EXAMPLETASK3_PROCESS_CANCELED */
/*  */
/*  MessageText: */
/*  */
/*   Cancel process is in progress, command can not be executed. */
/*  */
#define TLR_E_EXAMPLETASK3_PROCESS_CANCELED ((TLR_RESULT)0xC0050002L)

/*  */
/*  MessageId: TLR_I_EXAMPLETASK3_TEST_COUNTER_ODD */
/*  */
/*  MessageText: */
/*  */
/*   Counter value of Test-Command is odd. */
/*  */
#define TLR_I_EXAMPLETASK3_TEST_COUNTER_ODD ((TLR_RESULT)0x40050003L)




#endif  /* __EXAMPLE_TASKS_ERROR_H */

#ifndef __ICONL_ERROR_H
#define __ICONL_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  iCon-L Run Task Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_ICONL_RUN_INVALID_COMMAND */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_ICONL_RUN_INVALID_COMMAND  ((TLR_RESULT)0xC0290001L)

/*  */
/*  MessageId: TLR_E_ICONL_RUN_PROCESS_CANCELED */
/*  */
/*  MessageText: */
/*  */
/*   Cancel process is in progress, command can not be executed. */
/*  */
#define TLR_E_ICONL_RUN_PROCESS_CANCELED ((TLR_RESULT)0xC0290002L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  iCon-L Timer Task Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_ICONL_TIMER_INVALID_COMMAND */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_ICONL_TIMER_INVALID_COMMAND ((TLR_RESULT)0xC02A0001L)

/*  */
/*  MessageId: TLR_E_ICONL_TIMER_PROCESS_CANCELED */
/*  */
/*  MessageText: */
/*  */
/*   Cancel process is in progress, command can not be executed. */
/*  */
#define TLR_E_ICONL_TIMER_PROCESS_CANCELED ((TLR_RESULT)0xC02A0002L)




#endif  /* __ICONL_ERROR_H */

#ifndef __INX_ERROR_H
#define __INX_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Hilscher INX error definitions */
/* /////////////////////////////////////////////////////////////////////////////////// */

/*  */
/*  MessageId: TLR_E_INX_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   INX API not initialized. */
/*  */
#define TLR_E_INX_NOT_INITIALIZED        ((TLR_RESULT)0xC0930001L)

/*  */
/*  MessageId: TLR_E_INX_LOCK_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Lock operation failed. */
/*  */
#define TLR_E_INX_LOCK_FAILED            ((TLR_RESULT)0xC0930002L)

/*  */
/*  MessageId: TLR_E_INX_UNLOCK_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Unlock operation failed. */
/*  */
#define TLR_E_INX_UNLOCK_FAILED          ((TLR_RESULT)0xC0930003L)

/*  */
/*  MessageId: TLR_E_INX_NOT_CONNECTED */
/*  */
/*  MessageText: */
/*  */
/*   Not connected to an API. */
/*  */
#define TLR_E_INX_NOT_CONNECTED          ((TLR_RESULT)0xC0930004L)

/*  */
/*  MessageId: TLR_E_INX_CALLBACK_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   No callback registered. */
/*  */
#define TLR_E_INX_CALLBACK_ERROR         ((TLR_RESULT)0xC0930005L)

/*  */
/*  MessageId: TLR_E_INX_INVALID_API_NUMBER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid API number. */
/*  */
#define TLR_E_INX_INVALID_API_NUMBER     ((TLR_RESULT)0xC0930006L)

/*  */
/*  MessageId: TLR_E_INX_INVALID_HANDLE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid handle. */
/*  */
#define TLR_E_INX_INVALID_HANDLE         ((TLR_RESULT)0xC0930007L)

/*  */
/*  MessageId: TLR_E_INX_INVALID_POINTER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid pointer. */
/*  */
#define TLR_E_INX_INVALID_POINTER        ((TLR_RESULT)0xC0930008L)

/*  */
/*  MessageId: TLR_E_INX_RESOURCE_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Resource creation failed. */
/*  */
#define TLR_E_INX_RESOURCE_CREATE_FAILED ((TLR_RESULT)0xC0930009L)

/*  */
/*  MessageId: TLR_E_INX_RESOURCE_DELETE_NONEXISTING */
/*  */
/*  MessageText: */
/*  */
/*   Resource to be deleted does not exist. */
/*  */
#define TLR_E_INX_RESOURCE_DELETE_NONEXISTING ((TLR_RESULT)0xC093000AL)

/*  */
/*  MessageId: TLR_E_INX_OPEN_LIMIT */
/*  */
/*  MessageText: */
/*  */
/*   Limit of active inxOpen calls exceeded. */
/*  */
#define TLR_E_INX_OPEN_LIMIT             ((TLR_RESULT)0xC093000BL)

/*  */
/*  MessageId: TLR_E_INX_NOT_OPEN */
/*  */
/*  MessageText: */
/*  */
/*   Call to inxClose without preceding call to inxOpen. */
/*  */
#define TLR_E_INX_NOT_OPEN               ((TLR_RESULT)0xC093000CL)

/*  */
/*  MessageId: TLR_E_INX_CONNECT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Call to inxConnect failed. */
/*  */
#define TLR_E_INX_CONNECT_FAILED         ((TLR_RESULT)0xC093000DL)

/*  */
/*  MessageId: TLR_E_INX_DISCONNECT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Call to inxDisconnect failed. */
/*  */
#define TLR_E_INX_DISCONNECT_FAILED      ((TLR_RESULT)0xC093000EL)

/*  */
/*  MessageId: TLR_E_INX_CONTROL_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Call to INX control function failed. */
/*  */
#define TLR_E_INX_CONTROL_FAILED         ((TLR_RESULT)0xC093000FL)

/*  */
/*  MessageId: TLR_E_INX_CONTROL_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Timeout during call to INX control function. */
/*  */
#define TLR_E_INX_CONTROL_TIMEOUT        ((TLR_RESULT)0xC0930010L)

/*  */
/*  MessageId: TLR_E_INX_PACKET_TOO_BIG */
/*  */
/*  MessageText: */
/*  */
/*   Packet size exceeds INX mailbox size. */
/*  */
#define TLR_E_INX_PACKET_TOO_BIG         ((TLR_RESULT)0xC0930011L)

/*  */
/*  MessageId: TLR_E_INX_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Mailbox send operation failed. */
/*  */
#define TLR_E_INX_PACKET_SEND_FAILED     ((TLR_RESULT)0xC0930012L)

/*  */
/*  MessageId: TLR_E_INX_IO_TOO_MUCH_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Too much data while accessing INX input/output area. */
/*  */
#define TLR_E_INX_IO_TOO_MUCH_DATA       ((TLR_RESULT)0xC0930013L)




#endif  /* __INX_ERROR_H */

#ifndef __IO_SIGNALS_ERROR_H
#define __IO_SIGNALS_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  IO Signal task  ERROR codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_IO_SIGNAL_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_IO_SIGNAL_COMMAND_INVALID  ((TLR_RESULT)0xC0910001L)

/*  */
/*  MessageId: TLR_E_IO_SIGNAL_INVALID_SIGNAL_DIRECTION */
/*  */
/*  MessageText: */
/*  */
/*   The value of signal direction is invalid. */
/*  */
#define TLR_E_IO_SIGNAL_INVALID_SIGNAL_DIRECTION ((TLR_RESULT)0xC0910002L)

/*  */
/*  MessageId: TLR_E_IO_SIGNAL_INVALID_SIGNAL_AMOUNT */
/*  */
/*  MessageText: */
/*  */
/*   The value of signal amountis is invalid. */
/*  */
#define TLR_E_IO_SIGNAL_INVALID_SIGNAL_AMOUNT ((TLR_RESULT)0xC0910003L)

/*  */
/*  MessageId: TLR_E_IO_SIGNAL_INVALID_SIGNAL_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   The value of signal type is invalid. */
/*  */
#define TLR_E_IO_SIGNAL_INVALID_SIGNAL_TYPE ((TLR_RESULT)0xC0910004L)

/*  */
/*  MessageId: TLR_E_IO_SIGNAL_UNSUPPORTED_SIGNAL_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   The value of signal type is unsupported. */
/*  */
#define TLR_E_IO_SIGNAL_UNSUPPORTED_SIGNAL_TYPE ((TLR_RESULT)0xC0910005L)




#endif  /* __IO_SIGNALS_ERROR_H */

#ifndef __ITEM_SERVER_ERROR_H
#define __ITEM_SERVER_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  ITEM Server Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_ITEM_SERVER_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_ITEM_SERVER_COMMAND_INVALID ((TLR_RESULT)0xC0870001L)

/*  */
/*  MessageId: TLR_E_ITEM_SERVER_UNKNOWN_ITEM_UUID */
/*  */
/*  MessageText: */
/*  */
/*   Unknown Item UUID. */
/*  */
#define TLR_E_ITEM_SERVER_UNKNOWN_ITEM_UUID ((TLR_RESULT)0xC0870002L)




#endif  /* __ITEM_SERVER_ERROR_H */

#ifndef __LLDP_ERROR_H
#define __LLDP_ERROR_H


/* /////////////////////////////////////////////////////////////////////////////////// */
/*  LLDp Protocol */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_LLDP_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_LLDP_COMMAND_INVALID       ((TLR_RESULT)0xC03E0001L)

/*  */
/*  MessageId: TLR_I_LLDP_UNKNOWN_TLV */
/*  */
/*  MessageText: */
/*  */
/*   Unknwon TLV found. */
/*  */
#define TLR_I_LLDP_UNKNOWN_TLV           ((TLR_RESULT)0x403E0002L)

/*  */
/*  MessageId: TLR_E_LLDP_PDU_MAX_SIZE_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   Maximum Ethernet frame size exceeded. */
/*  */
#define TLR_E_LLDP_PDU_MAX_SIZE_EXCEEDED ((TLR_RESULT)0xC03E0003L)

/*  */
/*  MessageId: TLR_E_LLDP_TLV_DISCARDED */
/*  */
/*  MessageText: */
/*  */
/*   Invalid TLV content. */
/*  */
#define TLR_E_LLDP_TLV_DISCARDED         ((TLR_RESULT)0xC03E0004L)

/*  */
/*  MessageId: TLR_E_LLDP_FRAME_DISCARDED */
/*  */
/*  MessageText: */
/*  */
/*   One of TLVs has a wrong size or invalid mandatory TLV sequence. */
/*  */
#define TLR_E_LLDP_FRAME_DISCARDED       ((TLR_RESULT)0xC03E0005L)

/*  */
/*  MessageId: TLR_E_LLDP_WRONG_PARAMETERS */
/*  */
/*  MessageText: */
/*  */
/*   Parameters sent to the task are wrong. */
/*  */
#define TLR_E_LLDP_WRONG_PARAMETERS      ((TLR_RESULT)0xC03E0006L)

/*  */
/*  MessageId: TLR_E_NO_MIBS */
/*  */
/*  MessageText: */
/*  */
/*   The Task was unable to recreate MIBs during a reset due to insufficient memory. */
/*  */
#define TLR_E_NO_MIBS                    ((TLR_RESULT)0xC03E0007L)




#endif  /* __LLDP_ERROR_H */

#ifndef __MEMORY_MAP_ERROR_H
#define __MEMORY_MAP_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Memory Mapping Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_MEMMAP_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command in request detected. */
/*  */
#define TLR_E_MEMMAP_COMMAND_INVALID     ((TLR_RESULT)0xC0770001L)

/*  */
/*  MessageId: TLR_E_MEMMAP_INVALID_SSIO_CONFIG */
/*  */
/*  MessageText: */
/*  */
/*   Invalid initialization SSIO Configuration Bytes count. */
/*  */
#define TLR_E_MEMMAP_INVALID_SSIO_CONFIG ((TLR_RESULT)0xC0770002L)

/*  */
/*  MessageId: TLR_E_MEMMAP_INVALID_SSIO_STATUS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid initialization SSIO Status Bytes count. */
/*  */
#define TLR_E_MEMMAP_INVALID_SSIO_STATUS ((TLR_RESULT)0xC0770003L)

/*  */
/*  MessageId: TLR_E_MEMMAP_INVALID_INPUT_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Invalid initialization offset in the FB input area. */
/*  */
#define TLR_E_MEMMAP_INVALID_INPUT_OFFSET ((TLR_RESULT)0xC0770004L)

/*  */
/*  MessageId: TLR_E_MEMMAP_INVALID_OUTPUT_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Invalid initialization offset in the FB output area. */
/*  */
#define TLR_E_MEMMAP_INVALID_OUTPUT_OFFSET ((TLR_RESULT)0xC0770005L)

/*  */
/*  MessageId: TLR_E_MEMMAP_INVALID_RESERVED */
/*  */
/*  MessageText: */
/*  */
/*   Invalid initialization values for the reserved areas. */
/*  */
#define TLR_E_MEMMAP_INVALID_RESERVED    ((TLR_RESULT)0xC0770006L)

/*  */
/*  MessageId: TLR_E_MEMMAP_INVALID_DIAG_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Invalid initialization offset for the diagnostic mapping in the FB output area. */
/*  */
#define TLR_E_MEMMAP_INVALID_DIAG_OFFSET ((TLR_RESULT)0xC0770007L)

/*  */
/*  MessageId: TLR_E_MEMMAP_INVALID_DIAG_ENTRIES */
/*  */
/*  MessageText: */
/*  */
/*   Invalid initialization number of diagnostic entries. */
/*  */
#define TLR_E_MEMMAP_INVALID_DIAG_ENTRIES ((TLR_RESULT)0xC0770008L)

/*  */
/*  MessageId: TLR_E_MEMMAP_INVALID_COLUSION */
/*  */
/*  MessageText: */
/*  */
/*   Colusion between diagnostic mapping and the SSIO inputs in the FB output area. */
/*  */
#define TLR_E_MEMMAP_INVALID_COLUSION    ((TLR_RESULT)0xC0770009L)




#endif  /* __MEMORY_MAP_ERROR_H */

#ifndef __MIB_DATABASE_ERROR_H
#define __MIB_DATABASE_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  MIB Database Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_MIB_DATABASE_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_MIB_DATABASE_COMMAND_INVALID ((TLR_RESULT)0xC03C0001L)

/*  */
/*  MessageId: TLR_E_MIB_NO_SUCH_INSTANCE */
/*  */
/*  MessageText: */
/*  */
/*   No such instance of this Mib-variable. */
/*  */
#define TLR_E_MIB_NO_SUCH_INSTANCE       ((TLR_RESULT)0xC03C0002L)

/*  */
/*  MessageId: TLR_E_MIB_END_OF_COL */
/*  */
/*  MessageText: */
/*  */
/*   End of column reached while searching successor (GETNEXT). */
/*  */
#define TLR_E_MIB_END_OF_COL             ((TLR_RESULT)0xC03C0003L)

/*  */
/*  MessageId: TLR_E_MIB_NO_SUCH_NAME */
/*  */
/*  MessageText: */
/*  */
/*   The requested OID is not available. */
/*  */
#define TLR_E_MIB_NO_SUCH_NAME           ((TLR_RESULT)0xC03C0004L)




#endif  /* __MIB_DATABASE_ERROR_H */

#ifndef __MID_DBG_ERROR_H
#define __MID_DBG_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Mid_Dbg Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_MID_DBG_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_MID_DBG_COMMAND_INVALID    ((TLR_RESULT)0xC0310001L)

/*  */
/*  MessageId: TLR_E_MID_DBG_REQUESTED_MEM_BLOCK_SIZE_TOO_LARGE */
/*  */
/*  MessageText: */
/*  */
/*   Requested Memory Block Size too large. */
/*  */
#define TLR_E_MID_DBG_REQUESTED_MEM_BLOCK_SIZE_TOO_LARGE ((TLR_RESULT)0xC0310002L)

/*  */
/*  MessageId: TLR_E_MID_DBG_INVALID_TASK_HANDLE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid task handle. */
/*  */
#define TLR_E_MID_DBG_INVALID_TASK_HANDLE ((TLR_RESULT)0xC0310003L)

/*  */
/*  MessageId: TLR_E_MID_DBG_DENIED_ACC_DBG_TASK */
/*  */
/*  MessageText: */
/*  */
/*   Access to debug task denied. */
/*  */
#define TLR_E_MID_DBG_DENIED_ACC_DBG_TASK ((TLR_RESULT)0xC0310005L)

/*  */
/*  MessageId: TLR_E_MID_DBG_ALL_BKPTS_IN_USE */
/*  */
/*  MessageText: */
/*  */
/*   All breakpoints in use. */
/*  */
#define TLR_E_MID_DBG_ALL_BKPTS_IN_USE   ((TLR_RESULT)0xC0310007L)

/*  */
/*  MessageId: TLR_E_MID_DBG_BKPT_ADDRESS_ALREADY_DEFINED */
/*  */
/*  MessageText: */
/*  */
/*   Breakpoint address is already defined. */
/*  */
#define TLR_E_MID_DBG_BKPT_ADDRESS_ALREADY_DEFINED ((TLR_RESULT)0xC0310008L)

/*  */
/*  MessageId: TLR_E_MID_DBG_UNKNOWN_CODE_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Code type not known. */
/*  */
#define TLR_E_MID_DBG_UNKNOWN_CODE_TYPE  ((TLR_RESULT)0xC0310009L)

/*  */
/*  MessageId: TLR_E_MID_DBG_NO_BKPT_IN_ROM_POSSIBLE */
/*  */
/*  MessageText: */
/*  */
/*   No breakpoint in rom location possible. */
/*  */
#define TLR_E_MID_DBG_NO_BKPT_IN_ROM_POSSIBLE ((TLR_RESULT)0xC031000AL)

/*  */
/*  MessageId: TLR_E_MID_DBG_NO_SUCH_REGISTER_TO_WRITE */
/*  */
/*  MessageText: */
/*  */
/*   No such register to write to. */
/*  */
#define TLR_E_MID_DBG_NO_SUCH_REGISTER_TO_WRITE ((TLR_RESULT)0xC031000BL)

/*  */
/*  MessageId: TLR_E_MID_DBG_UNDEFINED_JUMP_TABLE_INDEX */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_MID_DBG_UNDEFINED_JUMP_TABLE_INDEX ((TLR_RESULT)0xC031000CL)

/*  */
/*  MessageId: TLR_E_MID_DBG_NO_JUMP_TABLE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_MID_DBG_NO_JUMP_TABLE      ((TLR_RESULT)0xC031000DL)




#endif  /* __MID_DBG_ERROR_H */

#ifndef __MID_STARTUP_ERROR_H
#define __MID_STARTUP_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  MID Startup Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_MID_STARTUP_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_MID_STARTUP_COMMAND_INVALID ((TLR_RESULT)0xC05F0001L)




#endif  /* __MID_STARTUP_ERROR_H */

#ifndef __MODBUS_RTU_ERROR_H
#define __MODBUS_RTU_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  MODBUS RTU Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_MODBUS_RTU_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_MODBUS_RTU_COMMAND_INVALID ((TLR_RESULT)0xC06E0001L)

/*  */
/*  MessageId: TLR_E_MODBUS_RTU_CMD_LENGTH_MISMATCH */
/*  */
/*  MessageText: */
/*  */
/*   Error Text 2. */
/*  */
#define TLR_E_MODBUS_RTU_CMD_LENGTH_MISMATCH ((TLR_RESULT)0xC06E0002L)




#endif  /* __MODBUS_RTU_ERROR_H */

#ifndef __MPI_GATEWAY_ERROR_H
#define __MPI_GATEWAY_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  MPI Gateway Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_MPI_GATEWAY_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_MPI_GATEWAY_COMMAND_INVALID ((TLR_RESULT)0xC0780001L)

/*  */
/*  MessageId: TLR_E_MPI_GATEWAY_NO_RECEIVER_FOR_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Packet could not be assigned to a receiver. */
/*  */
#define TLR_E_MPI_GATEWAY_NO_RECEIVER_FOR_PACKET ((TLR_RESULT)0xC0780002L)

/*  */
/*  MessageId: TLR_E_MPI_GATEWAY_DISCONNECT_RUNNING */
/*  */
/*  MessageText: */
/*  */
/*   The disconnect sequence is already running. */
/*  */
#define TLR_E_MPI_GATEWAY_DISCONNECT_RUNNING ((TLR_RESULT)0xC0780003L)




#endif  /* __CAN_DL_ERROR_H */

#ifndef __SSIO_MAP_ERROR_H
#define __SSIO_MAP_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  netIC SSIO Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_SSIO_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command in request detected. */
/*  */
#define TLR_E_SSIO_COMMAND_INVALID       ((TLR_RESULT)0xC0750001L)

/*  */
/*  MessageId: TLR_E_SSIO_NOT_INIT */
/*  */
/*  MessageText: */
/*  */
/*   Initialization GPIOs error. */
/*  */
#define TLR_E_SSIO_NOT_INIT              ((TLR_RESULT)0xC0750002L)

/*  */
/*  MessageId: TLR_E_SSIO_INVALID_SYSTEM_FLAGS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid initialization System flags value. */
/*  */
#define TLR_E_SSIO_INVALID_SYSTEM_FLAGS  ((TLR_RESULT)0xC0750003L)

/*  */
/*  MessageId: TLR_E_SSIO_INVALID_WDG */
/*  */
/*  MessageText: */
/*  */
/*   Invalid initialization Watchdog value. */
/*  */
#define TLR_E_SSIO_INVALID_WDG           ((TLR_RESULT)0xC0750004L)

/*  */
/*  MessageId: TLR_E_SSIO_INVALID_OUTPUTS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid initialization Output bytes value. */
/*  */
#define TLR_E_SSIO_INVALID_OUTPUTS       ((TLR_RESULT)0xC0750005L)

/*  */
/*  MessageId: TLR_E_SSIO_INVALID_INPUTS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid initialization Input bytes value. */
/*  */
#define TLR_E_SSIO_INVALID_INPUTS        ((TLR_RESULT)0xC0750006L)

/*  */
/*  MessageId: TLR_E_SSIO_INVALID_BAUDRATE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid initialization Baudrate value. */
/*  */
#define TLR_E_SSIO_INVALID_BAUDRATE      ((TLR_RESULT)0xC0750007L)

/*  */
/*  MessageId: TLR_E_SSIO_INVALID_CONFIG_FLAGS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid initialization Config flags value. */
/*  */
#define TLR_E_SSIO_INVALID_CONFIG_FLAGS  ((TLR_RESULT)0xC0750008L)

/*  */
/*  MessageId: TLR_E_SSIO_INVALID_RESERVED */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command in request detected. */
/*  */
#define TLR_E_SSIO_INVALID_RESERVED      ((TLR_RESULT)0xC0750009L)




#endif  /* __SSIO_ERROR_H */

#ifndef __NETSCRIPT_ERROR_H
#define __NETSCRIPT_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  netScript Task ERROR codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_NETSCRIPT_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_NETSCRIPT_COMMAND_INVALID  ((TLR_RESULT)0xC0800001L)

/*  */
/*  MessageId: TLR_E_NETSCRIPT_OUTOFMEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Memory allocation failure in netSCRIPT task. */
/*  */
#define TLR_E_NETSCRIPT_OUTOFMEMORY      ((TLR_RESULT)0xC0800002L)

/*  */
/*  MessageId: TLR_E_NETSCRIPT_LUA_OPEN_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Initialization of interpreter (lua_open) failed. */
/*  */
#define TLR_E_NETSCRIPT_LUA_OPEN_FAIL    ((TLR_RESULT)0xC0800080L)

/*  */
/*  MessageId: TLR_E_NETSCRIPT_NO_SCRIPT */
/*  */
/*  MessageText: */
/*  */
/*   No script found, or script file could not be loaded. */
/*  */
#define TLR_E_NETSCRIPT_NO_SCRIPT        ((TLR_RESULT)0xC0800081L)

/*  */
/*  MessageId: TLR_E_NETSCRIPT_NO_CYCLIC_FN */
/*  */
/*  MessageText: */
/*  */
/*   The value of __CYCLIC_FUNCTION is not a function. */
/*  */
#define TLR_E_NETSCRIPT_NO_CYCLIC_FN     ((TLR_RESULT)0xC0800082L)

/*  */
/*  MessageId: TLR_E_NETSCRIPT_LUA_ERROR_HANDLER_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   An error occurred inside an error handler. */
/*  */
#define TLR_E_NETSCRIPT_LUA_ERROR_HANDLER_FAILED ((TLR_RESULT)0xC0800083L)

/*  */
/*  MessageId: TLR_E_NETSCRIPT_LUA_OUTOFMEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Memory allocation failure in interpreter. */
/*  */
#define TLR_E_NETSCRIPT_LUA_OUTOFMEMORY  ((TLR_RESULT)0xC0800084L)

/*  */
/*  MessageId: TLR_E_NETSCRIPT_LUA_PANIC */
/*  */
/*  MessageText: */
/*  */
/*   A Lua panic occurred. */
/*  */
#define TLR_E_NETSCRIPT_LUA_PANIC        ((TLR_RESULT)0xC0800085L)

/*  */
/*  MessageId: TLR_E_NSC_LUA_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   An error was raised by Lua. See extended diagnosis. */
/*  */
#define TLR_E_NSC_LUA_ERROR              ((TLR_RESULT)0xC0800101L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  netScript UART  ERROR codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_NSC_PORT_INVALID_CONFIG */
/*  */
/*  MessageText: */
/*  */
/*   Port: Invalid configuration parameter. */
/*  */
#define TLR_E_NSC_PORT_INVALID_CONFIG    ((TLR_RESULT)0xC0800201L)

/*  */
/*  MessageId: TLR_E_NSC_PORT_INVALID_PORT */
/*  */
/*  MessageText: */
/*  */
/*   Port: HAL was called with an invalid port number. */
/*  */
#define TLR_E_NSC_PORT_INVALID_PORT      ((TLR_RESULT)0xC0800202L)

/*  */
/*  MessageId: TLR_E_NSC_PORT_WRONG_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Port: Char mode function called in block mode, or vice versa. */
/*  */
#define TLR_E_NSC_PORT_WRONG_MODE        ((TLR_RESULT)0xC0800203L)

/*  */
/*  MessageId: TLR_E_NSC_PORT_FIFO_EMPTY */
/*  */
/*  MessageText: */
/*  */
/*   Port: A FIFO is empty or does not contain as many entries as requested. */
/*  */
#define TLR_E_NSC_PORT_FIFO_EMPTY        ((TLR_RESULT)0x40800204L)

/*  */
/*  MessageId: TLR_E_NSC_PORT_FIFO_FULL */
/*  */
/*  MessageText: */
/*  */
/*   Port: A FIFO is full or does not have enough space to accept the input. */
/*  */
#define TLR_E_NSC_PORT_FIFO_FULL         ((TLR_RESULT)0x40800205L)

/*  */
/*  MessageId: TLR_E_NSC_PORT_XC_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Port: An error occurred while loading/initializing. */
/*  */
#define TLR_E_NSC_PORT_XC_INIT_FAILED    ((TLR_RESULT)0xC0800206L)

/*  */
/*  MessageId: TLR_E_NSC_PORT_NO_BUFFER */
/*  */
/*  MessageText: */
/*  */
/*   Port: No internal RAM buffers available for block mode operation. */
/*  */
#define TLR_E_NSC_PORT_NO_BUFFER         ((TLR_RESULT)0x40800210L)

/*  */
/*  MessageId: TLR_E_NSC_PORT_NO_SUCH_PORT */
/*  */
/*  MessageText: */
/*  */
/*   Port: The requested port instance does not exist. */
/*  */
#define TLR_E_NSC_PORT_NO_SUCH_PORT      ((TLR_RESULT)0x40800211L)

/*  */
/*  MessageId: TLR_E_NSC_PORT_ALREADY_OPEN */
/*  */
/*  MessageText: */
/*  */
/*   Port: Tried to open a port instance which is already open. */
/*  */
#define TLR_E_NSC_PORT_ALREADY_OPEN      ((TLR_RESULT)0x40800212L)

/*  */
/*  MessageId: TLR_E_NSC_PORT_NOT_OPEN */
/*  */
/*  MessageText: */
/*  */
/*   Port: Tried to call a function on a port which is not open. */
/*  */
#define TLR_E_NSC_PORT_NOT_OPEN          ((TLR_RESULT)0xC0800213L)

/*  */
/*  MessageId: TLR_E_NSC_PORT_NO_UARTDB */
/*  */
/*  MessageText: */
/*  */
/*   Port: Could not read UART config database. */
/*  */
#define TLR_E_NSC_PORT_NO_UARTDB         ((TLR_RESULT)0xC0800214L)

/*  */
/*  MessageId: TLR_E_NSC_PORT_PARSING_UARTDB */
/*  */
/*  MessageText: */
/*  */
/*   Port: Error parsing UART config database. */
/*  */
#define TLR_E_NSC_PORT_PARSING_UARTDB    ((TLR_RESULT)0xC0800215L)

/*  */
/*  MessageId: TLR_E_NSC_PORT_INVALID_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Port: A function argument is of the wrong type, or its value is outside the allowed range. */
/*  */
#define TLR_E_NSC_PORT_INVALID_PARAMETER ((TLR_RESULT)0x40800216L)

/*  */
/*  MessageId: TLR_E_NSC_PORT_NO_CONFIRMATION */
/*  */
/*  MessageText: */
/*  */
/*   Port: There is no confirmation of the requested type available. */
/*  */
#define TLR_E_NSC_PORT_NO_CONFIRMATION   ((TLR_RESULT)0x40800217L)

/*  */
/*  MessageId: TLR_E_NSC_PORT_STRING_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Port: The string passed to PortSend/PortExchange is too long. */
/*  */
#define TLR_E_NSC_PORT_STRING_TOO_LONG   ((TLR_RESULT)0x40800218L)


/* /////////////////////////////////////////////////////////////////////////////////// */
/*  netScript BusIO Error codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_NSC_BUSIO_NO_SUCH_INSTANCE */
/*  */
/*  MessageText: */
/*  */
/*   BusIO: The requested instance does not exist. */
/*  */
#define TLR_E_NSC_BUSIO_NO_SUCH_INSTANCE ((TLR_RESULT)0x40800301L)

/*  */
/*  MessageId: TLR_E_NSC_BUSIO_INSTANCE_IN_USE */
/*  */
/*  MessageText: */
/*  */
/*   BusIO: The requested instance is already in use. */
/*  */
#define TLR_E_NSC_BUSIO_INSTANCE_IN_USE  ((TLR_RESULT)0x40800302L)

/*  */
/*  MessageId: TLR_E_NSC_BUSIO_INVALID_CONFIG */
/*  */
/*  MessageText: */
/*  */
/*   BusIO: An invalid configuration parameter was passed. */
/*  */
#define TLR_E_NSC_BUSIO_INVALID_CONFIG   ((TLR_RESULT)0xC0800303L)

/*  */
/*  MessageId: TLR_E_NSC_BUSIO_NOT_OPEN */
/*  */
/*  MessageText: */
/*  */
/*   BusIO: A function was called on an instance which is not open or was closed. */
/*  */
#define TLR_E_NSC_BUSIO_NOT_OPEN         ((TLR_RESULT)0xC0800304L)

/*  */
/*  MessageId: TLR_E_NSC_BUSIO_INVALID_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   BusIO: An invalid parameter was passed. */
/*  */
#define TLR_E_NSC_BUSIO_INVALID_PARAMETER ((TLR_RESULT)0xC0800305L)

/*  */
/*  MessageId: TLR_E_NSC_BUSIO_WRONG_MODE */
/*  */
/*  MessageText: */
/*  */
/*   BusIO: Direct mode function called in Ascii mode, or vice versa. */
/*  */
#define TLR_E_NSC_BUSIO_WRONG_MODE       ((TLR_RESULT)0xC0800306L)

/*  */
/*  MessageId: TLR_E_NSC_BUSIO_NO_RX_ACK */
/*  */
/*  MessageText: */
/*  */
/*   BusIO Write: Input buffer not ready. */
/*  */
#define TLR_E_NSC_BUSIO_NO_RX_ACK        ((TLR_RESULT)0x40800311L)

/*  */
/*  MessageId: TLR_E_NSC_BUSIO_NO_RX_EN */
/*  */
/*  MessageText: */
/*  */
/*   BusIO Write: Sending not enabled (RxEnableCmd not set). */
/*  */
#define TLR_E_NSC_BUSIO_NO_RX_EN         ((TLR_RESULT)0x40800312L)

/*  */
/*  MessageId: TLR_E_NSC_BUSIO_STRING_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   BusIO Write: String too long for send buffer. Read: Invalid length in header. */
/*  */
#define TLR_E_NSC_BUSIO_STRING_TOO_LONG  ((TLR_RESULT)0x40800313L)

/*  */
/*  MessageId: TLR_E_NSC_BUSIO_BUFFER_LENGTH_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   BusIO ReadDirect/WriteDirect: Invalid offset or length. */
/*  */
#define TLR_E_NSC_BUSIO_BUFFER_LENGTH_EXCEEDED ((TLR_RESULT)0x40800314L)

/*  */
/*  MessageId: TLR_E_NSC_BUSIO_NO_TX_CMD */
/*  */
/*  MessageText: */
/*  */
/*   BusIO Read: No new data available. */
/*  */
#define TLR_E_NSC_BUSIO_NO_TX_CMD        ((TLR_RESULT)0x40800321L)

/*  */
/*  MessageId: TLR_E_NSC_BUSIO_NO_TX_EN */
/*  */
/*  MessageText: */
/*  */
/*   BusIO Read: Reading not enabled (TxEnableCmd not set). */
/*  */
#define TLR_E_NSC_BUSIO_NO_TX_EN         ((TLR_RESULT)0x40800322L)

/*  */
/*  MessageId: TLR_E_NSC_BUSIO_HEADER_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   BusIO Read: Error in header (Byte count?). */
/*  */
#define TLR_E_NSC_BUSIO_HEADER_ERROR     ((TLR_RESULT)0x40800323L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  netScript util lib error codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_NSC_UTIL_INVALID_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   util: Invalid parameter value (e.g. target type, endianness, LED identifier). */
/*  */
#define TLR_E_NSC_UTIL_INVALID_PARAMETER ((TLR_RESULT)0xC0800401L)

/*  */
/*  MessageId: TLR_E_NSC_UTIL_OUT_OF_RANGE */
/*  */
/*  MessageText: */
/*  */
/*   util: Number to convert is outside value range of target type. */
/*  */
#define TLR_E_NSC_UTIL_OUT_OF_RANGE      ((TLR_RESULT)0x40800402L)

/*  */
/*  MessageId: TLR_E_NSC_UTIL_WRONG_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   util: Length of string to convert does not match target type. */
/*  */
#define TLR_E_NSC_UTIL_WRONG_SIZE        ((TLR_RESULT)0x40800403L)

/*  */
/*  MessageId: TLR_E_NSC_DB_UNKNOWN_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Unknown variable type in variable NXD file. */
/*  */
#define TLR_E_NSC_DB_UNKNOWN_TYPE        ((TLR_RESULT)0xC0800410L)

/*  */
/*  MessageId: TLR_E_NSC_DB_STRING_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   String length in variable nxd file is too large. */
/*  */
#define TLR_E_NSC_DB_STRING_TOO_LONG     ((TLR_RESULT)0xC0800411L)




#endif  /* __NETSCRIPT_ERROR_H */

#ifndef __OD2_ERROR_H
#define __OD2_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Object Dictionary error codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_OD2_OBJECT_IN_USE */
/*  */
/*  MessageText: */
/*  */
/*   Object in use. */
/*  */
#define TLR_E_OD2_OBJECT_IN_USE          ((TLR_RESULT)0xC0280001L)

/*  */
/*  MessageId: TLR_E_OD2_INVALID_SUBINDEX */
/*  */
/*  MessageText: */
/*  */
/*   Invalid subindex. No such subobject. */
/*  */
#define TLR_E_OD2_INVALID_SUBINDEX       ((TLR_RESULT)0xC0280002L)

/*  */
/*  MessageId: TLR_E_OD2_INVALID_DATATYPE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid datatype. */
/*  */
#define TLR_E_OD2_INVALID_DATATYPE       ((TLR_RESULT)0xC0280003L)

/*  */
/*  MessageId: TLR_E_OD2_INVALID_BUFFER_PTR */
/*  */
/*  MessageText: */
/*  */
/*   Invalid buffer pointer. */
/*  */
#define TLR_E_OD2_INVALID_BUFFER_PTR     ((TLR_RESULT)0xC0280004L)

/*  */
/*  MessageId: TLR_E_OD2_INVALID_SECTOR */
/*  */
/*  MessageText: */
/*  */
/*   Invalid sector. */
/*  */
#define TLR_E_OD2_INVALID_SECTOR         ((TLR_RESULT)0xC0280005L)

/*  */
/*  MessageId: TLR_E_OD2_INVALID_SUBSECTOR */
/*  */
/*  MessageText: */
/*  */
/*   Invalid subsector. */
/*  */
#define TLR_E_OD2_INVALID_SUBSECTOR      ((TLR_RESULT)0xC0280006L)

/*  */
/*  MessageId: TLR_E_OD2_INVALID_OBJECT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid object. */
/*  */
#define TLR_E_OD2_INVALID_OBJECT         ((TLR_RESULT)0xC0280007L)

/*  */
/*  MessageId: TLR_E_OD2_INVALID_INDEX */
/*  */
/*  MessageText: */
/*  */
/*   Invalid index. No such object. */
/*  */
#define TLR_E_OD2_INVALID_INDEX          ((TLR_RESULT)0xC0280008L)

/*  */
/*  MessageId: TLR_E_OD2_SUBOBJECT_NOT_ALLOCATED */
/*  */
/*  MessageText: */
/*  */
/*   Subobject is not allocated. */
/*  */
#define TLR_E_OD2_SUBOBJECT_NOT_ALLOCATED ((TLR_RESULT)0xC0280009L)

/*  */
/*  MessageId: TLR_E_OD2_BUFFER_TOO_SMALL */
/*  */
/*  MessageText: */
/*  */
/*   Buffer too small. */
/*  */
#define TLR_E_OD2_BUFFER_TOO_SMALL       ((TLR_RESULT)0xC028000AL)

/*  */
/*  MessageId: TLR_E_OD2_READ_ONLY */
/*  */
/*  MessageText: */
/*  */
/*   Read only object. */
/*  */
#define TLR_E_OD2_READ_ONLY              ((TLR_RESULT)0xC028000BL)

/*  */
/*  MessageId: TLR_E_OD2_WRITE_ONLY */
/*  */
/*  MessageText: */
/*  */
/*   Write only object. */
/*  */
#define TLR_E_OD2_WRITE_ONLY             ((TLR_RESULT)0xC028000CL)

/*  */
/*  MessageId: TLR_E_OD2_SUBOBJECT_CNT_MISMATCH */
/*  */
/*  MessageText: */
/*  */
/*   Subobject count mismatch. */
/*  */
#define TLR_E_OD2_SUBOBJECT_CNT_MISMATCH ((TLR_RESULT)0xC028000DL)

/*  */
/*  MessageId: TLR_W_OD2_SUBOBJECT_IS_ADDRESSED_RELATIVE */
/*  */
/*  MessageText: */
/*  */
/*   Subobject is addressed relative to a base ptr. */
/*  */
#define TLR_W_OD2_SUBOBJECT_IS_ADDRESSED_RELATIVE ((TLR_RESULT)0x8028000EL)

/*  */
/*  MessageId: TLR_E_OD2_NOT_ENOUGH_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Not enough memory. */
/*  */
#define TLR_E_OD2_NOT_ENOUGH_MEMORY      ((TLR_RESULT)0xC028000FL)

/*  */
/*  MessageId: TLR_E_OD2_CALLBACK_IS_LOCKED */
/*  */
/*  MessageText: */
/*  */
/*   Callback is locked against changes. */
/*  */
#define TLR_E_OD2_CALLBACK_IS_LOCKED     ((TLR_RESULT)0xC0280010L)

/*  */
/*  MessageId: TLR_E_OD2_DATATYPE_LENGTH_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Datatype length is too long. */
/*  */
#define TLR_E_OD2_DATATYPE_LENGTH_TOO_LONG ((TLR_RESULT)0xC0280011L)

/*  */
/*  MessageId: TLR_E_OD2_PDO_LENGTH_WOULD_EXCEED */
/*  */
/*  MessageText: */
/*  */
/*   PDO length would exceed maximum transfer size. */
/*  */
#define TLR_E_OD2_PDO_LENGTH_WOULD_EXCEED ((TLR_RESULT)0xC0280012L)

/*  */
/*  MessageId: TLR_E_OD2_OBJECT_CANNOT_BE_PDO_MAPPED */
/*  */
/*  MessageText: */
/*  */
/*   An object cannot be mapped in a PDO. */
/*  */
#define TLR_E_OD2_OBJECT_CANNOT_BE_PDO_MAPPED ((TLR_RESULT)0xC0280013L)

/*  */
/*  MessageId: TLR_E_OD2_BUFFER_TOO_BIG */
/*  */
/*  MessageText: */
/*  */
/*   Buffer too big. */
/*  */
#define TLR_E_OD2_BUFFER_TOO_BIG         ((TLR_RESULT)0xC0280014L)

/*  */
/*  MessageId: TLR_E_OD2_UNSUPPORTED_ACCESS */
/*  */
/*  MessageText: */
/*  */
/*   Unsupported Access. */
/*  */
#define TLR_E_OD2_UNSUPPORTED_ACCESS     ((TLR_RESULT)0xC0280015L)

/*  */
/*  MessageId: TLR_E_OD2_VALUE_WRITTEN_TOO_HIGH */
/*  */
/*  MessageText: */
/*  */
/*   Value written too high. */
/*  */
#define TLR_E_OD2_VALUE_WRITTEN_TOO_HIGH ((TLR_RESULT)0xC0280016L)

/*  */
/*  MessageId: TLR_E_OD2_VALUE_WRITTEN_TOO_LOW */
/*  */
/*  MessageText: */
/*  */
/*   Value written too low. */
/*  */
#define TLR_E_OD2_VALUE_WRITTEN_TOO_LOW  ((TLR_RESULT)0xC0280017L)

/*  */
/*  MessageId: TLR_E_OD2_OBJECT_ALREADY_EXISTS */
/*  */
/*  MessageText: */
/*  */
/*   Object already exists. */
/*  */
#define TLR_E_OD2_OBJECT_ALREADY_EXISTS  ((TLR_RESULT)0xC0280018L)

/*  */
/*  MessageId: TLR_E_OD2_SUBOBJECT_ALREADY_EXISTS */
/*  */
/*  MessageText: */
/*  */
/*   Sub-Object already exists. */
/*  */
#define TLR_E_OD2_SUBOBJECT_ALREADY_EXISTS ((TLR_RESULT)0xC0280019L)

/*  */
/*  MessageId: TLR_E_OD2_SUBOBJECT_DOES_NOT_EXIST */
/*  */
/*  MessageText: */
/*  */
/*   Sub-Object does not exist. */
/*  */
#define TLR_E_OD2_SUBOBJECT_DOES_NOT_EXIST ((TLR_RESULT)0xC028001AL)

/*  */
/*  MessageId: TLR_E_OD2_OBJECT_CREATION_LOCKED */
/*  */
/*  MessageText: */
/*  */
/*   Object creation locked. */
/*  */
#define TLR_E_OD2_OBJECT_CREATION_LOCKED ((TLR_RESULT)0xC028001BL)




#endif  /* __OD2_ERROR_H */

#ifndef __OMB_OMBAPTASK_ERROR_H
#define __OMB_OMBAPTASK_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  OMB OmbApTask Packet Status codes (Open Modbus TCP AP Task) */
/* /////////////////////////////////////////////////////////////////////////////////// */
/* MessageId       = 0x0001 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB_AP */
/* SymbolicName    = TLR_E_OMB_OMBAPTASK_COMMAND_INVALID */
/* Language        = English */
/* Invalid command received. */
/* . */
/* Language        = German */
/* Ung�ltiges Kommando erhalten. */
/* . */
/* MessageId       = 0x0002 */
/* Severity        = Information */
/* Facility        = TLR_UNQ_NR_OMB_OMB_AP */
/* SymbolicName    = TLR_I_OMB_OMBAPTASK_CONFIG_LOCK */
/* Language        = English */
/* Configuration is locked. */
/* . */
/* Language        = German */
/* Die Konfiguration ist gesperrt. */
/* . */
/*  */
/*  MessageId: TLR_E_OMB_OMBAPTASK_WATCHDOG_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for watchdog supervision. */
/*  */
#define TLR_E_OMB_OMBAPTASK_WATCHDOG_PARAMETER ((TLR_RESULT)0xC0610003L)

/*  */
/*  MessageId: TLR_E_OMB_OMBAPTASK_WATCHDOG_ACTIVATE */
/*  */
/*  MessageText: */
/*  */
/*   Failed to activate watchdog supervision. */
/*  */
#define TLR_E_OMB_OMBAPTASK_WATCHDOG_ACTIVATE ((TLR_RESULT)0xC0610004L)

/* MessageId       = 0x0005 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB_AP */
/* SymbolicName    = TLR_E_OMB_OMBAPTASK_REQUEST_RUNNING */
/* Language        = English */
/* Request already running. */
/* . */
/* Language        = German */
/* Ein Befehl is bereits aktiv. */
/* . */
/*  */
/*  MessageId: TLR_E_OMB_OMBAPTASK_SYS_FLAG_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for system flags. */
/*  */
#define TLR_E_OMB_OMBAPTASK_SYS_FLAG_PARAMETER ((TLR_RESULT)0xC0610006L)

/*  */
/*  MessageId: TLR_E_OMB_OMBAPTASK_INVALID_STARTUP_PARAMETER_QUE_ELEM_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulQueElemCnt. */
/*  */
#define TLR_E_OMB_OMBAPTASK_INVALID_STARTUP_PARAMETER_QUE_ELEM_CNT ((TLR_RESULT)0xC0610007L)

/*  */
/*  MessageId: TLR_E_OMB_OMBAPTASK_INVALID_STARTUP_PARAMETER_POOL_ELEM_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulPoolElemCnt. */
/*  */
#define TLR_E_OMB_OMBAPTASK_INVALID_STARTUP_PARAMETER_POOL_ELEM_CNT ((TLR_RESULT)0xC0610008L)

/*  */
/*  MessageId: TLR_E_OMB_OMBAPTASK_INVALID_STARTUP_PARAMETER_START_FLAGS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulStartFlags. */
/*  */
#define TLR_E_OMB_OMBAPTASK_INVALID_STARTUP_PARAMETER_START_FLAGS ((TLR_RESULT)0xC0610009L)

/*  */
/*  MessageId: TLR_E_OMB_OMBAPTASK_INVALID_STARTUP_PARAMETER_CHN_INST */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulChnInst. */
/*  */
#define TLR_E_OMB_OMBAPTASK_INVALID_STARTUP_PARAMETER_CHN_INST ((TLR_RESULT)0xC061000AL)

/*  */
/*  MessageId: TLR_E_OMB_OMBAPTASK_FATAL_ERROR_OMB_TASK */
/*  */
/*  MessageText: */
/*  */
/*   The OMB task reports a fatal error. System has stopped. */
/*   See extended status tMidCodeDiag for further information. */
/*  */
#define TLR_E_OMB_OMBAPTASK_FATAL_ERROR_OMB_TASK ((TLR_RESULT)0xC061000BL)




#endif  /* __OMB_OMBAPTASK_ERROR_H */

#ifndef __OMB_OMBTASK_ERROR_H
#define __OMB_OMBTASK_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  OMB OmbTask Packet Status codes (Open Modbus TCP Task) */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Initialization Error Codes */
/* MessageId       = 0x0001 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_E_OMB_OMBTASK_COMMAND_INVALID */
/* Language        = English */
/* Invalid command received. */
/* . */
/* Language        = German */
/* Ung�ltiges Kommando erhalten. */
/* . */
/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_SEND_IP_SET_CONFIG_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to forward the SET_CONFIG information to TCP_UDP task (because of a */
/*   resource problem). */
/*  */
#define TLR_E_OMB_OMBTASK_SEND_IP_SET_CONFIG_FAILED ((TLR_RESULT)0xC0600002L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_SYSTEM_FUNCTION_CODE */
/*  */
/*  MessageText: */
/*  */
/*   System error: Wrong function code. */
/*  */
#define TLR_E_OMB_OMBTASK_SYSTEM_FUNCTION_CODE ((TLR_RESULT)0xC0600003L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_MOD_MEM_MOD_START_ADR */
/*  */
/*  MessageText: */
/*  */
/*   IO mode: Wrong Modbus start address. */
/*  */
#define TLR_E_OMB_OMBTASK_MOD_MEM_MOD_START_ADR ((TLR_RESULT)0xC0600004L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_MOD_MEM_LEN */
/*  */
/*  MessageText: */
/*  */
/*   IO mode: Wrong length of Memory map. */
/*  */
#define TLR_E_OMB_OMBTASK_MOD_MEM_LEN    ((TLR_RESULT)0xC0600005L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_MOD_MEM_START_MEM_OFF */
/*  */
/*  MessageText: */
/*  */
/*   IO mode: Wrong Start byteoffset in Memory map. */
/*  */
#define TLR_E_OMB_OMBTASK_MOD_MEM_START_MEM_OFF ((TLR_RESULT)0xC0600006L)

/* MessageId       = 0x00xx */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_E_OMB_OMBTASK_MOD_MEM_ADR_AND_LEN */
/* Language        = English */
/* IO mode: Wrong Modbus start address in conjunction with the length of Memory map. */
/* . */
/* Language        = German */
/* IO-Mode: Falsche Modbus Startadresse in Verbindung mit der Laenge des Abbildspeichers. */
/* . */
/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_MOD_MEM_SYSTEM_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   IO mode: System error. */
/*  */
#define TLR_E_OMB_OMBTASK_MOD_MEM_SYSTEM_ERROR ((TLR_RESULT)0xC0600007L)

/* MessageId       = 0x00xx */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_E_OMB_OMBTASK_TRIBUFF_INIT_BUFFER */
/* Language        = English */
/* The initialization of buffer has failed. */
/* . */
/* Language        = German */
/* Die Initialisierung der Puffer ist fehlgeschlagen. */
/* . */
/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_QUE_ELEM_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulQueElemCnt. */
/*  */
#define TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_QUE_ELEM_CNT ((TLR_RESULT)0xC0600008L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_POOL_ELEM_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulPoolElemCnt. */
/*  */
#define TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_POOL_ELEM_CNT ((TLR_RESULT)0xC0600009L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_START_FLAGS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulStartFlags. */
/*  */
#define TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_START_FLAGS ((TLR_RESULT)0xC060000AL)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_OMB_CYCLE_EVENT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulOmbCycleEvent. */
/*  */
#define TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_OMB_CYCLE_EVENT ((TLR_RESULT)0xC060000BL)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_APPLICATION_TIMER_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to create an application timer (Timer task). */
/*  */
#define TLR_E_OMB_OMBTASK_APPLICATION_TIMER_CREATE_FAILED ((TLR_RESULT)0xC060000CL)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_APPLICATION_TIMER_INIT_PACKET_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize a packet of application timer (Timer task). */
/*  */
#define TLR_E_OMB_OMBTASK_APPLICATION_TIMER_INIT_PACKET_FAILED ((TLR_RESULT)0xC060000DL)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_TCP_UDP_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to identify the TCP_UDP task. */
/*  */
#define TLR_E_OMB_OMBTASK_TCP_UDP_IDENTIFY_FAILED ((TLR_RESULT)0xC060000EL)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_TCP_UDP_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The queue identification of TCP_UDP task queue has failed. */
/*  */
#define TLR_E_OMB_OMBTASK_TCP_UDP_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC060000FL)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_BUFFER_QUEUE_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of buffer queue failed. */
/*  */
#define TLR_E_OMB_OMBTASK_BUFFER_QUEUE_CREATE_FAILED ((TLR_RESULT)0xC0600010L)

/* MessageId       = 0x0011 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_E_OMB_OMBTASK_NOT_CONFIGURED */
/* Language        = English */
/* No configuration available. */
/* . */
/* Language        = German */
/* Keine Konfiguration vorhanden. */
/* . */
/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_FLAGS_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter 'Flags' (ulFlags). */
/*  */
#define TLR_E_OMB_OMBTASK_FLAGS_VALUE    ((TLR_RESULT)0xC0600012L)

/*  Initialization Error Codes (Numbers MessageId are compatible to old RCS errors) */
/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_SERVER_CONNECT_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter 'Open Server Sockets' (ulOpenServerSockets). */
/*  */
#define TLR_E_OMB_OMBTASK_SERVER_CONNECT_VALUE ((TLR_RESULT)0xC0600034L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_ANSWER_TIMEOUT_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter 'Answer Timeout' (ulAnswerTimeout). */
/*  */
#define TLR_E_OMB_OMBTASK_ANSWER_TIMEOUT_VALUE ((TLR_RESULT)0xC0600035L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_OPEN_TIMEOUT_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter 'Omb Open Time' (ulOmbOpenTime). */
/*  */
#define TLR_E_OMB_OMBTASK_OPEN_TIMEOUT_VALUE ((TLR_RESULT)0xC0600036L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_MODE_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter 'Mode' (ulMode). */
/*  */
#define TLR_E_OMB_OMBTASK_MODE_VALUE     ((TLR_RESULT)0xC0600037L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_SEND_TIMEOUT_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter 'Send Timeout' (ulSendTimeout). */
/*  */
#define TLR_E_OMB_OMBTASK_SEND_TIMEOUT_VALUE ((TLR_RESULT)0xC0600038L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_CONNECT_TIMEOUT_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter 'Connect Timeout' (ulConnectTimeout). */
/*  */
#define TLR_E_OMB_OMBTASK_CONNECT_TIMEOUT_VALUE ((TLR_RESULT)0xC0600039L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_CLOSE_TIMEOUT_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter 'Close Timeout' (ulCloseTimeout). */
/*  */
#define TLR_E_OMB_OMBTASK_CLOSE_TIMEOUT_VALUE ((TLR_RESULT)0xC060003AL)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_SWAB_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter 'Swap' (ulSwap). */
/*  */
#define TLR_E_OMB_OMBTASK_SWAB_VALUE     ((TLR_RESULT)0xC060003BL)

/* MessageId       = 60 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_E_OMB_OMBTASK_ERR_INIT_TCP_TASK_NOT_READY */
/* Language        = English */
/* TCP_UDP task not ready. */
/* . */
/* Language        = German */
/* . */
/* . */
/* MessageId       = 61 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_E_OMB_OMBTASK_ERR_INIT_PLC_TASK_NOT_READY */
/* Language        = English */
/* PLC task not found. */
/* . */
/* Language        = German */
/* . */
/* . */
/* MessageId       = 62 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_E_OMB_OMBTASK_ERR_INIT_TASK_CONFIG */
/* Language        = English */
/* . */
/* . */
/* Language        = German */
/* . */
/* . */
/* MessageId       = 63 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_E_OMB_OMBTASK_PLC_ERR_INIT_MODE */
/* Language        = English */
/* . */
/* . */
/* Language        = German */
/* . */
/* . */
/*  Run-time Error Codes (Numbers MessageId are compatible to old RCS errors) */
/* MessageId       = 111 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_E_OMB_OMBTASK_UNKNOWN_TX */
/* Language        = English */
/* . */
/* . */
/* Language        = German */
/* . */
/* . */
/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_ERR_ANSWER */
/*  */
/*  MessageText: */
/*  */
/*   TCP_UDP task answered with an error. */
/*  */
#define TLR_E_OMB_OMBTASK_ERR_ANSWER     ((TLR_RESULT)0xC0600070L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_ERR_STATE */
/*  */
/*  MessageText: */
/*  */
/*   No socket in specific status found. */
/*  */
#define TLR_E_OMB_OMBTASK_ERR_STATE      ((TLR_RESULT)0xC0600071L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_ERR_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid value in command. */
/*  */
#define TLR_E_OMB_OMBTASK_ERR_VALUE      ((TLR_RESULT)0xC0600072L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_ERR_TCP_TASK_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Error in TCP_UDP task state. */
/*  */
#define TLR_E_OMB_OMBTASK_ERR_TCP_TASK_STATE ((TLR_RESULT)0xC0600073L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_ERR_MODBUS */
/*  */
/*  MessageText: */
/*  */
/*   Error in Modbus telegram - for further information, see variable ulException in this chapter. */
/*  */
#define TLR_E_OMB_OMBTASK_ERR_MODBUS     ((TLR_RESULT)0xC0600074L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_ERR_NO_SOCKET */
/*  */
/*  MessageText: */
/*  */
/*   No free and unused socket found. */
/*  */
#define TLR_E_OMB_OMBTASK_ERR_NO_SOCKET  ((TLR_RESULT)0xC0600075L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_ERR_UNKNOWN_SOCKET */
/*  */
/*  MessageText: */
/*  */
/*   TCP_UDP command for an unknown socket received. */
/*  */
#define TLR_E_OMB_OMBTASK_ERR_UNKNOWN_SOCKET ((TLR_RESULT)0xC0600076L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_ERR_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   The timeout for the Client-Job is expired. Timeout-Count starts after target has */
/*   received the command. */
/*  */
#define TLR_E_OMB_OMBTASK_ERR_TIMEOUT    ((TLR_RESULT)0xC0600077L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_ERR_UNEXPECTED_CLOSE */
/*  */
/*  MessageText: */
/*  */
/*   Socket was unexpected closed. */
/*  */
#define TLR_E_OMB_OMBTASK_ERR_UNEXPECTED_CLOSE ((TLR_RESULT)0xC0600078L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_USER_NOT_READY */
/*  */
/*  MessageText: */
/*  */
/*   The User is not ready (not registered). */
/*  */
#define TLR_E_OMB_OMBTASK_USER_NOT_READY ((TLR_RESULT)0xC0600079L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_NO_SOCKET_AVAILABLE */
/*  */
/*  MessageText: */
/*  */
/*   OMB task is not able to open sockets (TCP_UDP task is not ready). */
/*  */
#define TLR_E_OMB_OMBTASK_NO_SOCKET_AVAILABLE ((TLR_RESULT)0xC060007AL)

/* MessageId       = 123 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_E_OMB_OMBTASK_WATCHDOG */
/* Language        = English */
/* Watchdog error. */
/* . */
/* Language        = German */
/* Watchdog-Fehler. */
/* . */
/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_ERR_IP_CONFIG */
/*  */
/*  MessageText: */
/*  */
/*   TCP_UDP task is in configuration status. */
/*  */
#define TLR_E_OMB_OMBTASK_ERR_IP_CONFIG  ((TLR_RESULT)0xC060007CL)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_PLC_TASK_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   No Dualport-memory access. */
/*  */
#define TLR_E_OMB_OMBTASK_PLC_TASK_NOT_INITIALIZED ((TLR_RESULT)0xC060007DL)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_SEVER_SOCKET_CLOSED */
/*  */
/*  MessageText: */
/*  */
/*   Server Socket was closed, before the answer is received. */
/*  */
#define TLR_E_OMB_OMBTASK_SEVER_SOCKET_CLOSED ((TLR_RESULT)0xC060007EL)

/* MessageId       = 151 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_E_OMB_OMBTASK_MESSAGESIZE */
/* Language        = English */
/* Invalid packet length detected. */
/* . */
/* Language        = German */
/* Falsche Packet-L�nge. */
/* . */
/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_DEVICE_ADR */
/*  */
/*  MessageText: */
/*  */
/*   Invalid device address (IP address). */
/*  */
#define TLR_E_OMB_OMBTASK_DEVICE_ADR     ((TLR_RESULT)0xC06000A1L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_DATA_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Data count. */
/*  */
#define TLR_E_OMB_OMBTASK_DATA_CNT       ((TLR_RESULT)0xC06000A5L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_FUNCTION */
/*  */
/*  MessageText: */
/*  */
/*   Wrong Function code. Function code is not supported. */
/*  */
#define TLR_E_OMB_OMBTASK_FUNCTION       ((TLR_RESULT)0xC06000A7L)

/* //////// New rxC error codes, starting with a value bigger than the RCS error codes = 255  ////////// */
/* /// General OMB errors 0x0100 ... 0x01FF (reserved) ///// */
/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_MOD_DATA_ADR */
/*  */
/*  MessageText: */
/*  */
/*   IO mode: Wrong Modbus address. Modbus address is outside of Memory map. */
/*  */
#define TLR_E_OMB_OMBTASK_MOD_DATA_ADR   ((TLR_RESULT)0xC0600100L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_MOD_DATA_CNT */
/*  */
/*  MessageText: */
/*  */
/*   IO mode: Wrong Data count in conjunction with the Modbus address. */
/*   The access area is outside of Memory map. */
/*  */
#define TLR_E_OMB_OMBTASK_MOD_DATA_CNT   ((TLR_RESULT)0xC0600101L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_MOD_FUNCTION_CODE */
/*  */
/*  MessageText: */
/*  */
/*   IO mode: Wrong Function code. Function code is not supported. */
/*  */
#define TLR_E_OMB_OMBTASK_MOD_FUNCTION_CODE ((TLR_RESULT)0xC0600102L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_MOD_DATA_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   IO mode: Wrong data type. */
/*  */
#define TLR_E_OMB_OMBTASK_MOD_DATA_TYPE  ((TLR_RESULT)0xC0600103L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_MOD_BIT_AREA */
/*  */
/*  MessageText: */
/*  */
/*   IO mode: Addressed coil is outside of the IO area. */
/*  */
#define TLR_E_OMB_OMBTASK_MOD_BIT_AREA   ((TLR_RESULT)0xC0600104L)

/* MessageId       = 0x0105 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_E_OMB_OMBTASK_REQUEST_RUNNING */
/* Language        = English */
/* Request already running. */
/* . */
/* Language        = German */
/* Ein Befehl is bereits aktiv. */
/* . */
/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_SEND_TCP_CONFIG_RELOAD_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to forward the configuration reload to TCP_UDP task (because of a */
/*   resource problem). */
/*  */
#define TLR_E_OMB_OMBTASK_SEND_TCP_CONFIG_RELOAD_FAILED ((TLR_RESULT)0xC0600106L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_WRONG_CONFIG_RELOAD_STS */
/*  */
/*  MessageText: */
/*  */
/*   Wrong configuration reload state. */
/*  */
#define TLR_E_OMB_OMBTASK_WRONG_CONFIG_RELOAD_STS ((TLR_RESULT)0xC0600107L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_RESOURCE_OCCUPIED */
/*  */
/*  MessageText: */
/*  */
/*   System error: The requestet resource is occupied. */
/*  */
#define TLR_E_OMB_OMBTASK_RESOURCE_OCCUPIED ((TLR_RESULT)0xC0600108L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_AP_ALREADY_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   A application is already registered. */
/*  */
#define TLR_E_OMB_OMBTASK_AP_ALREADY_REGISTERED ((TLR_RESULT)0xC0600109L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_AP_NOT_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   A application is not registered. */
/*  */
#define TLR_E_OMB_OMBTASK_AP_NOT_REGISTERED ((TLR_RESULT)0xC060010AL)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_START_STOP_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Wrong mode ulMode in command OMB_OMBTASK_CMD_START_STOP_OMB_REQ. */
/*  */
#define TLR_E_OMB_OMBTASK_START_STOP_MODE ((TLR_RESULT)0xC060010BL)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_START_STOP_STATE_CHANGE */
/*  */
/*  MessageText: */
/*  */
/*   No senseful state change request (Start/stop) in command */
/*   OMB_OMBTASK_CMD_START_STOP_OMB_REQ. */
/*  */
#define TLR_E_OMB_OMBTASK_START_STOP_STATE_CHANGE ((TLR_RESULT)0xC060010CL)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_IO_MODE_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   IO mode:Invalid command received */
/*  */
#define TLR_E_OMB_OMBTASK_IO_MODE_COMMAND_INVALID ((TLR_RESULT)0xC060010DL)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_STATE_NOT_RUNNING */
/*  */
/*  MessageText: */
/*  */
/*   The OMB stack is not in running state (Info status: ulTaskState is not */
/*   OMB_ST_TASK_RUNNING) or the Communication state is not operating */
/*   (ulCommunicationState is not RCX_COMM_STATE_OPERATE). */
/*  */
#define TLR_E_OMB_OMBTASK_STATE_NOT_RUNNING ((TLR_RESULT)0xC060010EL)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_MBAP_HEADER */
/*  */
/*  MessageText: */
/*  */
/*   Wrong MBAP header received (Transaction Identifier, Protocol Identifier) */
/*  */
#define TLR_E_OMB_OMBTASK_MBAP_HEADER    ((TLR_RESULT)0xC060010FL)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_UNIT_ID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Unit identifier (ulUnitId). */
/*  */
#define TLR_E_OMB_OMBTASK_UNIT_ID        ((TLR_RESULT)0xC0600110L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_EXCEPTION */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Exception code (ulException). */
/*  */
#define TLR_E_OMB_OMBTASK_EXCEPTION      ((TLR_RESULT)0xC0600111L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_MBAP_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Invalid MBAP header Length value. */
/*  */
#define TLR_E_OMB_OMBTASK_MBAP_LENGTH    ((TLR_RESULT)0xC0600112L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_PDU_BYTE_COUNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid PDU Byte count. */
/*  */
#define TLR_E_OMB_OMBTASK_PDU_BYTE_COUNT ((TLR_RESULT)0xC0600113L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_PDU_REF_NUMBER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid PDU Reference Number (Starting Address). */
/*  */
#define TLR_E_OMB_OMBTASK_PDU_REF_NUMBER ((TLR_RESULT)0xC0600114L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_PDU_DATA_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid PDU Data count (Quantity). */
/*  */
#define TLR_E_OMB_OMBTASK_PDU_DATA_CNT   ((TLR_RESULT)0xC0600115L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_PDU_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid PDU Value. */
/*  */
#define TLR_E_OMB_OMBTASK_PDU_VALUE      ((TLR_RESULT)0xC0600116L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_DATA_ADR */
/*  */
/*  MessageText: */
/*  */
/*   Wrong Modbus address. The Modbus address is outside of the Modbus Data model */
/*   (Range 0 ... 65535). */
/*  */
#define TLR_E_OMB_OMBTASK_DATA_ADR       ((TLR_RESULT)0xC0600117L)

/*  */
/*  MessageId: TLR_E_OMB_OMBTASK_DATA_ADR_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Wrong Data count in conjunction with the Modbus address. */
/*   The access area is outside of the Modbus Data model (Range 0 ... 65535). */
/*  */
#define TLR_E_OMB_OMBTASK_DATA_ADR_CNT   ((TLR_RESULT)0xC0600118L)




#endif  /* __OMB_OMBTASK_ERROR_H */

#ifndef __P3964R_APP_ERROR_H
#define __P3964R_APP_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  3964R App  ERROR codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_P3964R_APP_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_P3964R_APP_COMMAND_INVALID ((TLR_RESULT)0xC0900001L)

/*  */
/*  MessageId: TLR_E_P3964R_APP_RINGBUFFER_FULL */
/*  */
/*  MessageText: */
/*  */
/*   Ringbuffer full. */
/*  */
#define TLR_E_P3964R_APP_RINGBUFFER_FULL ((TLR_RESULT)0xC0900002L)

/*  */
/*  MessageId: TLR_E_P3964R_APP_RINGBUFFER_EMPTY */
/*  */
/*  MessageText: */
/*  */
/*   Ringbuffer empty. */
/*  */
#define TLR_E_P3964R_APP_RINGBUFFER_EMPTY ((TLR_RESULT)0x40900003L)

/*  */
/*  MessageId: TLR_E_P3964R_APP_RINGBUFFER_INIT_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Ringbuffer init error. */
/*  */
#define TLR_E_P3964R_APP_RINGBUFFER_INIT_ERROR ((TLR_RESULT)0xC0900004L)




#endif  /* __P3964R_APP_ERROR_H */

#ifndef __P3964R_STACK_ERROR_H
#define __P3964R_STACK_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  3964R Stack  ERROR codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_P3964R_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_P3964R_COMMAND_INVALID     ((TLR_RESULT)0xC08F0001L)

/*  */
/*  MessageId: TLR_E_P3964R_STACK_PACKET_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Packet is too long. */
/*  */
#define TLR_E_P3964R_STACK_PACKET_TOO_LONG ((TLR_RESULT)0xC08F0002L)

/*  */
/*  MessageId: TLR_E_P3964R_STACK_LED_NOT_SUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   LED is not supported. */
/*  */
#define TLR_E_P3964R_STACK_LED_NOT_SUPPORTED ((TLR_RESULT)0xC08F0003L)

/*  */
/*  MessageId: TLR_E_P3964R_INIT_CONFLICT_HIGH_PRIO */
/*  */
/*  MessageText: */
/*  */
/*   Init conflict, both devices have high priority */
/*  */
#define TLR_E_P3964R_INIT_CONFLICT_HIGH_PRIO ((TLR_RESULT)0xC08F0004L)

/*  */
/*  MessageId: TLR_E_P3964R_INIT_CONFLICT_LOW_PRIO */
/*  */
/*  MessageText: */
/*  */
/*   Init conflict, both devices have low priority */
/*  */
#define TLR_E_P3964R_INIT_CONFLICT_LOW_PRIO ((TLR_RESULT)0xC08F0005L)

/*  */
/*  MessageId: TLR_E_P3964R_TX_NEG_ACK_TO_CON_CLEARDOWN */
/*  */
/*  MessageText: */
/*  */
/*   Transm Error: Negative Ackn at connection cleardown. */
/*  */
#define TLR_E_P3964R_TX_NEG_ACK_TO_CON_CLEARDOWN ((TLR_RESULT)0xC08F0006L)

/*  */
/*  MessageId: TLR_E_P3964R_TX_NEG_ACK_TO_CON_BUILDUP */
/*  */
/*  MessageText: */
/*  */
/*   Transm Error: Negative Ackn at connection buildup. */
/*  */
#define TLR_E_P3964R_TX_NEG_ACK_TO_CON_BUILDUP ((TLR_RESULT)0xC08F0007L)

/*  */
/*  MessageId: TLR_E_P3964R_TX_TRANSM_ABORT_BY_RECEIVER */
/*  */
/*  MessageText: */
/*  */
/*   Transm Error: Transmission aborted by receiver. */
/*  */
#define TLR_E_P3964R_TX_TRANSM_ABORT_BY_RECEIVER ((TLR_RESULT)0xC08F0008L)

/*  */
/*  MessageId: TLR_E_P3964R_TX_ACK_TIMEOUT_AT_BUILDUP */
/*  */
/*  MessageText: */
/*  */
/*   Transm Error: Ackn timeout at connection buildup. */
/*  */
#define TLR_E_P3964R_TX_ACK_TIMEOUT_AT_BUILDUP ((TLR_RESULT)0xC08F0009L)

/*  */
/*  MessageId: TLR_E_P3964R_TX_ACK_TIMEOUT_AT_CLEARDOWN */
/*  */
/*  MessageText: */
/*  */
/*   Transm Error: Ackn timeout at connection cleardown. */
/*  */
#define TLR_E_P3964R_TX_ACK_TIMEOUT_AT_CLEARDOWN ((TLR_RESULT)0xC08F000AL)

/*  */
/*  MessageId: TLR_E_P3964R_TX_DATA_TRANSM_INTERRUPTED */
/*  */
/*  MessageText: */
/*  */
/*   Transm Error: Transmission interrupted by receiver. */
/*  */
#define TLR_E_P3964R_TX_DATA_TRANSM_INTERRUPTED ((TLR_RESULT)0xC08F001BL)

/*  */
/*  MessageId: TLR_E_P3964R_TX_RAND_CHAR_TO_CON_BUILDUP */
/*  */
/*  MessageText: */
/*  */
/*   Transm Error: Recvd arbitrary char at connection buildup. */
/*  */
#define TLR_E_P3964R_TX_RAND_CHAR_TO_CON_BUILDUP ((TLR_RESULT)0xC08F000CL)

/*  */
/*  MessageId: TLR_E_P3964R_TX_RAND_CHAR_TO_CON_CLEARDOWN */
/*  */
/*  MessageText: */
/*  */
/*   Transm Error: Recvd arbitrary char at connection cleardown. */
/*  */
#define TLR_E_P3964R_TX_RAND_CHAR_TO_CON_CLEARDOWN ((TLR_RESULT)0xC08F000DL)

/*  */
/*  MessageId: TLR_E_P3964R_RX_FRAME_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Recept. Error: Frame too long. */
/*  */
#define TLR_E_P3964R_RX_FRAME_TOO_LONG   ((TLR_RESULT)0xC08F000EL)

/*  */
/*  MessageId: TLR_E_P3964R_RX_DLE_NOT_DOUBLED */
/*  */
/*  MessageText: */
/*  */
/*   Recept. Error: DLE not doubled. */
/*  */
#define TLR_E_P3964R_RX_DLE_NOT_DOUBLED  ((TLR_RESULT)0xC08F000FL)

/*  */
/*  MessageId: TLR_E_P3964R_RX_RANDOM_CHAR_RECVD_IN_IDLE */
/*  */
/*  MessageText: */
/*  */
/*   Recept. Error: char other than STX received in idle state. */
/*  */
#define TLR_E_P3964R_RX_RANDOM_CHAR_RECVD_IN_IDLE ((TLR_RESULT)0xC08F0010L)

/*  */
/*  MessageId: TLR_E_P3964R_RX_CHARACTER_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Recept. Error: Character timeout. */
/*  */
#define TLR_E_P3964R_RX_CHARACTER_TIMEOUT ((TLR_RESULT)0xC08F0011L)

/*  */
/*  MessageId: TLR_E_P3964R_RX_CHECKSUM_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Recept. Error: Checksum error(BCC). */
/*  */
#define TLR_E_P3964R_RX_CHECKSUM_ERROR   ((TLR_RESULT)0xC08F0012L)

/*  */
/*  MessageId: TLR_E_P3964R_RX_NO_MEM_SEG_AVAILABLE */
/*  */
/*  MessageText: */
/*  */
/*   Recept. Error: No memory segment available. */
/*  */
#define TLR_E_P3964R_RX_NO_MEM_SEG_AVAILABLE ((TLR_RESULT)0xC08F0013L)

/*  */
/*  MessageId: TLR_E_P3964R_UART_PARITY_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   UART parity error. */
/*  */
#define TLR_E_P3964R_UART_PARITY_ERROR   ((TLR_RESULT)0xC08F0014L)

/*  */
/*  MessageId: TLR_E_P3964R_UART_BREAK */
/*  */
/*  MessageText: */
/*  */
/*   UART break. */
/*  */
#define TLR_E_P3964R_UART_BREAK          ((TLR_RESULT)0xC08F0015L)

/*  */
/*  MessageId: TLR_E_P3964R_UART_FRAME_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   UART framing error. */
/*  */
#define TLR_E_P3964R_UART_FRAME_ERROR    ((TLR_RESULT)0xC08F0016L)

/*  */
/*  MessageId: TLR_E_P3964R_UART_OVERRUN */
/*  */
/*  MessageText: */
/*  */
/*   UART overrun. */
/*  */
#define TLR_E_P3964R_UART_OVERRUN        ((TLR_RESULT)0xC08F0017L)




#endif  /* __P3964R_STACK_ERROR_H */

#ifndef __PNIO_APCTL_ERROR_H
#define __PNIO_APCTL_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PNIO APCTL Diagnostic Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PNIO_APCTL_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_PNIO_APCTL_COMMAND_INVALID ((TLR_RESULT)0xC00C0001L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_RSC_OUTOFMEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Unsufficient memory to handle the request. */
/*  */
#define TLR_E_PNIO_APCTL_RSC_OUTOFMEMORY ((TLR_RESULT)0xC00C0002L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_HIF_IDENT */
/*  */
/*  MessageText: */
/*  */
/*   Error indetifying HIF. */
/*  */
#define TLR_E_PNIO_APCTL_HIF_IDENT       ((TLR_RESULT)0xC00C0003L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_AREA_IDENT */
/*  */
/*  MessageText: */
/*  */
/*   Unable to identify requested DPM Channel. */
/*  */
#define TLR_E_PNIO_APCTL_AREA_IDENT      ((TLR_RESULT)0xC00C0004L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_GETAREA_IDENT */
/*  */
/*  MessageText: */
/*  */
/*   Unable to identify DPM section "STD INPUT". */
/*  */
#define TLR_E_PNIO_APCTL_GETAREA_IDENT   ((TLR_RESULT)0xC00C0005L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_SETAREA_IDENT */
/*  */
/*  MessageText: */
/*  */
/*   Unable to identify DPM section "STD OUTPUT". */
/*  */
#define TLR_E_PNIO_APCTL_SETAREA_IDENT   ((TLR_RESULT)0xC00C0006L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_SETAREA_INFO_GET */
/*  */
/*  MessageText: */
/*  */
/*   Unable to get configuration for DPM section "STD OUTPUT". */
/*  */
#define TLR_E_PNIO_APCTL_SETAREA_INFO_GET ((TLR_RESULT)0xC00C0007L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_TOHOST_MBX_NAME_GET */
/*  */
/*  MessageText: */
/*  */
/*   Unable to identify DPM section "TOHOST MBX". */
/*  */
#define TLR_E_PNIO_APCTL_TOHOST_MBX_NAME_GET ((TLR_RESULT)0xC00C0008L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_TOHOST_MBX_INFO_GET */
/*  */
/*  MessageText: */
/*  */
/*   Unable to get configuration for DPM section "TOHOST MBX". */
/*  */
#define TLR_E_PNIO_APCTL_TOHOST_MBX_INFO_GET ((TLR_RESULT)0xC00C0009L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_MIDSYS_QUE_IDENT */
/*  */
/*  MessageText: */
/*  */
/*   Unable to identify queue to MidSys. */
/*  */
#define TLR_E_PNIO_APCTL_MIDSYS_QUE_IDENT ((TLR_RESULT)0xC00C000AL)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_ENABLE_BUSON_CBK */
/*  */
/*  MessageText: */
/*  */
/*   Enabling callback function for ApplicationCOS.BUS_ON bit did not succeed. */
/*  */
#define TLR_E_PNIO_APCTL_ENABLE_BUSON_CBK ((TLR_RESULT)0xC00C000BL)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_ENABLE_APPREADY_CBK */
/*  */
/*  MessageText: */
/*  */
/*   Enabling callback function for ApplicationCOS.APP_READY bit did not succeed. */
/*  */
#define TLR_E_PNIO_APCTL_ENABLE_APPREADY_CBK ((TLR_RESULT)0xC00C000CL)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_COMMONAREA_IDENT */
/*  */
/*  MessageText: */
/*  */
/*   Unable to identify DPM section "COMMON STATUS". */
/*  */
#define TLR_E_PNIO_APCTL_COMMONAREA_IDENT ((TLR_RESULT)0xC00C000DL)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_STATUSAREA_IDENT */
/*  */
/*  MessageText: */
/*  */
/*   Unable to identify DPM section "EXTENDED STATUS". */
/*  */
#define TLR_E_PNIO_APCTL_STATUSAREA_IDENT ((TLR_RESULT)0xC00C000EL)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_CONTROLAREA_IDENT */
/*  */
/*  MessageText: */
/*  */
/*   Unable to identify DPM section "CONTROL". */
/*  */
#define TLR_E_PNIO_APCTL_CONTROLAREA_IDENT ((TLR_RESULT)0xC00C000FL)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_GETAREA_INT_ENBL */
/*  */
/*  MessageText: */
/*  */
/*   Unable to enable DPM section "STD INPUT". */
/*  */
#define TLR_E_PNIO_APCTL_GETAREA_INT_ENBL ((TLR_RESULT)0xC00C0010L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_SETAREA_INT_ENBL */
/*  */
/*  MessageText: */
/*  */
/*   Unable to enable DPM section "STD OUTPUT". */
/*  */
#define TLR_E_PNIO_APCTL_SETAREA_INT_ENBL ((TLR_RESULT)0xC00C0011L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_ENABLE_INIT_CBK */
/*  */
/*  MessageText: */
/*  */
/*   Enabling callback function for ApplicationCOS.INITIALIZATION bit did not succeed. */
/*  */
#define TLR_E_PNIO_APCTL_ENABLE_INIT_CBK ((TLR_RESULT)0xC00C0012L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_VOL_IDENT */
/*  */
/*  MessageText: */
/*  */
/*   Unable to identify SysVolume. */
/*  */
#define TLR_E_PNIO_APCTL_VOL_IDENT       ((TLR_RESULT)0xC00C0013L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_VOL_MOUNT */
/*  */
/*  MessageText: */
/*  */
/*   Unable to mount SysVolume */
/*  */
#define TLR_E_PNIO_APCTL_VOL_MOUNT       ((TLR_RESULT)0xC00C0014L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_FAT_FRMT */
/*  */
/*  MessageText: */
/*  */
/*   Unable to format SysVolume. */
/*  */
#define TLR_E_PNIO_APCTL_FAT_FRMT        ((TLR_RESULT)0xC00C0015L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_QUE_CREATE */
/*  */
/*  MessageText: */
/*  */
/*   The Queue for APCTL task could not be created. */
/*  */
#define TLR_E_PNIO_APCTL_QUE_CREATE      ((TLR_RESULT)0xC00C0016L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_CMCTL_QUE_IDENT */
/*  */
/*  MessageText: */
/*  */
/*   The Queue for CMCTL task could not be identified. */
/*  */
#define TLR_E_PNIO_APCTL_CMCTL_QUE_IDENT ((TLR_RESULT)0xC00C0017L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_MGT_QUE_IDENT */
/*  */
/*  MessageText: */
/*  */
/*   The Queue for MGT task could not be identified. */
/*  */
#define TLR_E_PNIO_APCTL_MGT_QUE_IDENT   ((TLR_RESULT)0xC00C0018L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_ACP_QUE_IDENT */
/*  */
/*  MessageText: */
/*  */
/*   The Queue for ACP task could not be identified. */
/*  */
#define TLR_E_PNIO_APCTL_ACP_QUE_IDENT   ((TLR_RESULT)0xC00C0019L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_GETAREA_INFO_GET */
/*  */
/*  MessageText: */
/*  */
/*   Unable to get configuration for DPM section "STD INPUT". */
/*  */
#define TLR_E_PNIO_APCTL_GETAREA_INFO_GET ((TLR_RESULT)0xC00C001AL)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_CLR_PCK_GET */
/*  */
/*  MessageText: */
/*  */
/*   Unable to get a free packet from packet pool to unregister DPM channel from rcX. */
/*  */
#define TLR_E_PNIO_APCTL_CLR_PCK_GET     ((TLR_RESULT)0xC00C001BL)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_SET_PCK_GET */
/*  */
/*  MessageText: */
/*  */
/*   Unable to get a free packet from packet pool to register DPM channel from rcX. */
/*  */
#define TLR_E_PNIO_APCTL_SET_PCK_GET     ((TLR_RESULT)0xC00C001CL)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_IDENT_QUE_MIDSYS */
/*  */
/*  MessageText: */
/*  */
/*   The Queue of rcX MidSys task could not be identified. */
/*  */
#define TLR_E_PNIO_APCTL_IDENT_QUE_MIDSYS ((TLR_RESULT)0xC00C001DL)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_CREATE_TIMER_SET */
/*  */
/*  MessageText: */
/*  */
/*   The timer for firmware-controlled handling of IO-data in DPM could not be created. */
/*  */
#define TLR_E_PNIO_APCTL_CREATE_TIMER_SET ((TLR_RESULT)0xC00C001EL)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_MEMALLOC_TIMER_SET */
/*  */
/*  MessageText: */
/*  */
/*   Not enough free memory available for firmware-controlled handling of IO-data in DPM. */
/*  */
#define TLR_E_PNIO_APCTL_MEMALLOC_TIMER_SET ((TLR_RESULT)0xC00C001FL)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_WDG_INIT */
/*  */
/*  MessageText: */
/*  */
/*   The Watchdog timer could not be initialized. */
/*  */
#define TLR_E_PNIO_APCTL_WDG_INIT        ((TLR_RESULT)0xC00C0020L)

/*  */
/*  MessageId: TLR_E_INFO_FIELD_ONE_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The field for extended APCTL task status information could not be created. */
/*  */
#define TLR_E_INFO_FIELD_ONE_CREATE_FAILED ((TLR_RESULT)0xC00C0021L)

/*  */
/*  MessageId: TLR_E_INFO_FIELD_TWO_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   An undefined field could not be created (unused). */
/*  */
#define TLR_E_INFO_FIELD_TWO_CREATE_FAILED ((TLR_RESULT)0xC00C0022L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_POOL_CREATE */
/*  */
/*  MessageText: */
/*  */
/*   The packet pool for APCTL task could not be created. */
/*  */
#define TLR_E_PNIO_APCTL_POOL_CREATE     ((TLR_RESULT)0xC00C0023L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_IOCR_LIST */
/*  */
/*  MessageText: */
/*  */
/*   The number of the input IOCRs is not equal to the number of the output IOCRs. */
/*  */
#define TLR_E_PNIO_APCTL_IOCR_LIST       ((TLR_RESULT)0xC00C0024L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_DPM */
/*  */
/*  MessageText: */
/*  */
/*   The requested function is not supported because DPM is not initialized. */
/*  */
#define TLR_E_PNIO_APCTL_DPM             ((TLR_RESULT)0xC00C0025L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_ENABLE_LOCKCONFIG_CBK */
/*  */
/*  MessageText: */
/*  */
/*   Enabling callback function for ApplicationCOS.LOCK_CONFIGURATION bit did not succeed. */
/*  */
#define TLR_E_PNIO_APCTL_ENABLE_LOCKCONFIG_CBK ((TLR_RESULT)0xC00C0026L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_LED_CREATE */
/*  */
/*  MessageText: */
/*  */
/*   The LEDs could not be initialized. */
/*  */
#define TLR_E_PNIO_APCTL_LED_CREATE      ((TLR_RESULT)0xC00C0027L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_ENABLE_DMA_CBK */
/*  */
/*  MessageText: */
/*  */
/*   Enabling callback function to enable DMA mode did not succeed. */
/*  */
#define TLR_E_PNIO_APCTL_ENABLE_DMA_CBK  ((TLR_RESULT)0xC00C0028L)

/*  The following codes are used by Benjamin */
/*  */
/*  MessageId: TLR_E_PNIO_APCTL_RPC_REQUEST_LIMIT_REACHED */
/*  */
/*  MessageText: */
/*  */
/*   Too many outstanding RPC-requests for this IO-Device. */
/*  */
#define TLR_E_PNIO_APCTL_RPC_REQUEST_LIMIT_REACHED ((TLR_RESULT)0xC00C0030L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Error while sending internal message to another task. */
/*  */
#define TLR_E_PNIO_APCTL_PACKET_SEND_FAILED ((TLR_RESULT)0xC00C0031L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_INVALID_CMCTL_HANDLE */
/*  */
/*  MessageText: */
/*  */
/*   The handle used for IO-Device is wrong. */
/*  */
#define TLR_E_PNIO_APCTL_INVALID_CMCTL_HANDLE ((TLR_RESULT)0xC00C0032L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_INVALID_NAME_OF_STATION_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   The name to be set has incorrect length. */
/*  */
#define TLR_E_PNIO_APCTL_INVALID_NAME_OF_STATION_LENGTH ((TLR_RESULT)0xC00C0033L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_DCP_REQUEST_LIMIT_REACHED */
/*  */
/*  MessageText: */
/*  */
/*   Too many outstanding DCP-requests for this IO-Device. */
/*  */
#define TLR_E_PNIO_APCTL_DCP_REQUEST_LIMIT_REACHED ((TLR_RESULT)0xC00C0034L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_OTHER_CONFIG_PACKET_IN_PROCESS */
/*  */
/*  MessageText: */
/*  */
/*   An other configuration packet is in process wait for its confimation packet. */
/*  */
#define TLR_E_PNIO_APCTL_OTHER_CONFIG_PACKET_IN_PROCESS ((TLR_RESULT)0xC00C0035L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_APCFG_QUE_IDENT */
/*  */
/*  MessageText: */
/*  */
/*   Identification of APCFG queue in remote resources failed. */
/*  */
#define TLR_E_PNIO_APCTL_APCFG_QUE_IDENT ((TLR_RESULT)0xC00C0036L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_UNKNOWN_ALARM_SPECIFIER */
/*  */
/*  MessageText: */
/*  */
/*   The Alarmspecifier is unknown to IO-Controller. */
/*  */
#define TLR_E_PNIO_APCTL_UNKNOWN_ALARM_SPECIFIER ((TLR_RESULT)0xC00C0037L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_DCP_REQUEST_NO_ANSWER */
/*  */
/*  MessageText: */
/*  */
/*   The requested IO-Device did not answer to the DCP-requests. */
/*  */
#define TLR_E_PNIO_APCTL_DCP_REQUEST_NO_ANSWER ((TLR_RESULT)0xC00C0038L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_APPLICATION_ALREADY_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   There is alredy an Application registered to APCTL-Task. */
/*  */
#define TLR_E_PNIO_APCTL_APPLICATION_ALREADY_REGISTERED ((TLR_RESULT)0xC00C0040L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_NO_APPLICATION_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   There is no Application registered to APCTL-Task. */
/*  */
#define TLR_E_PNIO_APCTL_NO_APPLICATION_REGISTERED ((TLR_RESULT)0xC00C0041L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_UNREGISTER_APPLICATION_IMPOSSIBLE */
/*  */
/*  MessageText: */
/*  */
/*   It is impossible to unregister the Application in APCTL-Task. Either there is no Application registered or the Unregister Request was not send by the registered Application. */
/*  */
#define TLR_E_PNIO_APCTL_UNREGISTER_APPLICATION_IMPOSSIBLE ((TLR_RESULT)0xC00C0042L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_CHANNEL_INIT_REQUESTED */
/*  */
/*  MessageText: */
/*  */
/*   The request is rejected because a Channel Init was requested. */
/*  */
#define TLR_E_PNIO_APCTL_CHANNEL_INIT_REQUESTED ((TLR_RESULT)0xC00C0050L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_BUS_STATE_OFF */
/*  */
/*  MessageText: */
/*  */
/*   The request is rejected because bus state is set OFF or a running request was interrupted by setting bus state to OFF. */
/*  */
#define TLR_E_PNIO_APCTL_BUS_STATE_OFF   ((TLR_RESULT)0xC00C0051L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_CYCLIC_WATCHDOG_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   The connection to an IO-Device was closed because too many cyclic frames were missing. */
/*  */
#define TLR_E_PNIO_APCTL_CYCLIC_WATCHDOG_ERROR ((TLR_RESULT)0xC00C0052L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_CONNECTION_CLOSED_BY_IODEVICE */
/*  */
/*  MessageText: */
/*  */
/*   The connection was shutdown by an IO-Device. */
/*  */
#define TLR_E_PNIO_APCTL_CONNECTION_CLOSED_BY_IODEVICE ((TLR_RESULT)0xC00C0053L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_WATCHDOG_TIME_TOO_SMALL */
/*  */
/*  MessageText: */
/*  */
/*   The watchdog time specified is too small. */
/*  */
#define TLR_E_PNIO_APCTL_WATCHDOG_TIME_TOO_SMALL ((TLR_RESULT)0xC00C0054L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_WATCHDOG_TIME_TOO_BIG */
/*  */
/*  MessageText: */
/*  */
/*   The watchdog time specified is too big. */
/*  */
#define TLR_E_PNIO_APCTL_WATCHDOG_TIME_TOO_BIG ((TLR_RESULT)0xC00C0055L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_IO_DEVICE_NOT_IN_DATAEXCHANGE */
/*  */
/*  MessageText: */
/*  */
/*   The service is unavailable because the IO-Device is not in cyclic data exchange. */
/*  */
#define TLR_E_PNIO_APCTL_IO_DEVICE_NOT_IN_DATAEXCHANGE ((TLR_RESULT)0xC00C0056L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_ACYCLIC_REQ_FAILED_REMOTE */
/*  */
/*  MessageText: */
/*  */
/*   The acyclic service failed. The IO-Device answered with an error code which is contained in confirmation packet. */
/*  */
#define TLR_E_PNIO_APCTL_ACYCLIC_REQ_FAILED_REMOTE ((TLR_RESULT)0xC00C0060L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_ACYCLIC_REQ_FAILED_RPC */
/*  */
/*  MessageText: */
/*  */
/*   The acyclic service failed. The RPC-layer detected an error which is contained in confirmation packet. */
/*  */
#define TLR_E_PNIO_APCTL_ACYCLIC_REQ_FAILED_RPC ((TLR_RESULT)0xC00C0061L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_ACYCLIC_REQ_FAILED_INTERNAL */
/*  */
/*  MessageText: */
/*  */
/*   The acyclic service failed. An internal error occured. */
/*  */
#define TLR_E_PNIO_APCTL_ACYCLIC_REQ_FAILED_INTERNAL ((TLR_RESULT)0xC00C0062L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_TOO_MUCH_IO_DATA_CONFIGURED */
/*  */
/*  MessageText: */
/*  */
/*   The maximum supported IO-data size is exceeded. */
/*  */
#define TLR_E_PNIO_APCTL_TOO_MUCH_IO_DATA_CONFIGURED ((TLR_RESULT)0xC00C0063L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_INVALID_IP_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   The IP address is invalid. */
/*  */
#define TLR_E_PNIO_APCTL_INVALID_IP_ADDRESS ((TLR_RESULT)0xC00C0064L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_INVALID_NETMASK */
/*  */
/*  MessageText: */
/*  */
/*   The Netmask is invalid. */
/*  */
#define TLR_E_PNIO_APCTL_INVALID_NETMASK ((TLR_RESULT)0xC00C0065L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_INVALID_GATEWAY */
/*  */
/*  MessageText: */
/*  */
/*   The gateway address is invalid. */
/*  */
#define TLR_E_PNIO_APCTL_INVALID_GATEWAY ((TLR_RESULT)0xC00C0066L)

/*  */
/*  MessageId: TLR_E_PNIO_APCTL_TOO_MUCH_DATA_REQUESTED */
/*  */
/*  MessageText: */
/*  */
/*   The maximum supported data size for this service is exceeded. */
/*  */
#define TLR_E_PNIO_APCTL_TOO_MUCH_DATA_REQUESTED ((TLR_RESULT)0xC00C0067L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PNIO APCFG Diagnostic Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PNIO_APCFG_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_PNIO_APCFG_COMMAND_INVALID ((TLR_RESULT)0xC0140001L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DBM_UNKNOWN_VERSION */
/*  */
/*  MessageText: */
/*  */
/*   Unknown DBM version. */
/*  */
#define TLR_E_PNIO_APCFG_DBM_UNKNOWN_VERSION ((TLR_RESULT)0xC0140002L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DBM_NO_DATASET */
/*  */
/*  MessageText: */
/*  */
/*   No dataset existing. */
/*  */
#define TLR_E_PNIO_APCFG_DBM_NO_DATASET  ((TLR_RESULT)0xC0140003L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DBM_WRONG_SIZE_OF_DATASET */
/*  */
/*  MessageText: */
/*  */
/*   Wrong size of DBM dataset. */
/*  */
#define TLR_E_PNIO_APCFG_DBM_WRONG_SIZE_OF_DATASET ((TLR_RESULT)0xC0140004L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DBM_WRONG_LEN_TYPEOFSTATION */
/*  */
/*  MessageText: */
/*  */
/*   Type of station is too large. */
/*  */
#define TLR_E_PNIO_APCFG_DBM_WRONG_LEN_TYPEOFSTATION ((TLR_RESULT)0xC0140005L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DBM_WRONG_LEN_NAMEOFSTATION */
/*  */
/*  MessageText: */
/*  */
/*   Name of station is too large. */
/*  */
#define TLR_E_PNIO_APCFG_DBM_WRONG_LEN_NAMEOFSTATION ((TLR_RESULT)0xC0140006L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DBM_UNKNOWN_IOCR_KEY */
/*  */
/*  MessageText: */
/*  */
/*   Unkwown IOCR relationship in submodule description. */
/*  */
#define TLR_E_PNIO_APCFG_DBM_UNKNOWN_IOCR_KEY ((TLR_RESULT)0xC0140007L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DBM_IOCR_ALREADY_IN_USE */
/*  */
/*  MessageText: */
/*  */
/*   IOCR is in use by another IO-Device. */
/*  */
#define TLR_E_PNIO_APCFG_DBM_IOCR_ALREADY_IN_USE ((TLR_RESULT)0xC0140008L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DBM_WRONG_IOCR_IN_SUBMDESCR */
/*  */
/*  MessageText: */
/*  */
/*   Wrong IO-Type of IOCR in submodule description. */
/*  */
#define TLR_E_PNIO_APCFG_DBM_WRONG_IOCR_IN_SUBMDESCR ((TLR_RESULT)0xC0140009L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DBM_WRONG_DATALEN_IN_SUBMDESCR */
/*  */
/*  MessageText: */
/*  */
/*   Wrong data length in submodule description. */
/*  */
#define TLR_E_PNIO_APCFG_DBM_WRONG_DATALEN_IN_SUBMDESCR ((TLR_RESULT)0xC014000AL)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DBM_WRONG_DATADESCR_IN_SUBMDESCR */
/*  */
/*  MessageText: */
/*  */
/*   Wrong IO-type in data description of the submodule description. */
/*  */
#define TLR_E_PNIO_APCFG_DBM_WRONG_DATADESCR_IN_SUBMDESCR ((TLR_RESULT)0xC014000BL)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DBM_UNEXP_SUBMDESCR */
/*  */
/*  MessageText: */
/*  */
/*   Unexpected submodule description. */
/*  */
#define TLR_E_PNIO_APCFG_DBM_UNEXP_SUBMDESCR ((TLR_RESULT)0xC014000CL)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DBM_MISSING_SUBMDESCR */
/*  */
/*  MessageText: */
/*  */
/*   Missing submodule description. */
/*  */
#define TLR_E_PNIO_APCFG_DBM_MISSING_SUBMDESCR ((TLR_RESULT)0xC014000DL)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DBM_ASSERTION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Assertion failed. */
/*  */
#define TLR_E_PNIO_APCFG_DBM_ASSERTION_FAILED ((TLR_RESULT)0xC014000EL)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_PKT_UNEXP_TREE_IDENTIFICATON */
/*  */
/*  MessageText: */
/*  */
/*   Wrong sequence/numbering in the tree identification numbers. */
/*  */
#define TLR_E_PNIO_APCFG_PKT_UNEXP_TREE_IDENTIFICATON ((TLR_RESULT)0xC014000FL)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_PKT_OVERWRITING_CONSISTING_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Addressed dataset is already existing and would be overwritten. */
/*  */
#define TLR_E_PNIO_APCFG_PKT_OVERWRITING_CONSISTING_DATA ((TLR_RESULT)0xC0140010L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_PKT_MISSING_IOCR */
/*  */
/*  MessageText: */
/*  */
/*   Input or output IOCR of module is missing. */
/*  */
#define TLR_E_PNIO_APCFG_PKT_MISSING_IOCR ((TLR_RESULT)0xC0140011L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_PKT_WRONG_IO_TYPE_IN_IOCR */
/*  */
/*  MessageText: */
/*  */
/*   Wrong input or output type in IOCR. */
/*  */
#define TLR_E_PNIO_APCFG_PKT_WRONG_IO_TYPE_IN_IOCR ((TLR_RESULT)0xC0140012L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_PKT_WRONG_SEQUENCE_OF_FRAGMENTED_PACKETS */
/*  */
/*  MessageText: */
/*  */
/*   Wrong sequence of fragmented packets. */
/*  */
#define TLR_E_PNIO_APCFG_PKT_WRONG_SEQUENCE_OF_FRAGMENTED_PACKETS ((TLR_RESULT)0xC0140013L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_PKT_WRONG_FRAGMENT_IDENTIFIER */
/*  */
/*  MessageText: */
/*  */
/*   Wrong fragment identifier in fragmented packets. */
/*  */
#define TLR_E_PNIO_APCFG_PKT_WRONG_FRAGMENT_IDENTIFIER ((TLR_RESULT)0xC0140014L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_PKT_CONFIGURATION_IS_ALREADY_DONE_VIA_DBM */
/*  */
/*  MessageText: */
/*  */
/*   Configuration is already done via DBM configuration packets are not accepted. */
/*  */
#define TLR_E_PNIO_APCFG_PKT_CONFIGURATION_IS_ALREADY_DONE_VIA_DBM ((TLR_RESULT)0xC0140015L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DBM_INCOMPLETE_CONFIGURATION */
/*  */
/*  MessageText: */
/*  */
/*   Incomplete configuration - not all devices are fully developet until submodule descriptions. */
/*  */
#define TLR_E_PNIO_APCFG_DBM_INCOMPLETE_CONFIGURATION ((TLR_RESULT)0xC0140016L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_PKT_DOWNLOAD_ALREADY_FINISHED */
/*  */
/*  MessageText: */
/*  */
/*   Paket download is already finished by download finish request. */
/*  */
#define TLR_E_PNIO_APCFG_PKT_DOWNLOAD_ALREADY_FINISHED ((TLR_RESULT)0xC0140017L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DBM_UNEXP_NUMBER_OF_RECORDS_IN_PNIOC_TABLES */
/*  */
/*  MessageText: */
/*  */
/*   More than one entry for one key was found in the tables of the fieldbus specific data. */
/*  */
#define TLR_E_PNIO_APCFG_DBM_UNEXP_NUMBER_OF_RECORDS_IN_PNIOC_TABLES ((TLR_RESULT)0xC0140018L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DBM_UNEXP_SIGNAL_ATTRIBUT */
/*  */
/*  MessageText: */
/*  */
/*   Unexpected parameter Signal_Attrib in SIGNALS table. */
/*  */
#define TLR_E_PNIO_APCFG_DBM_UNEXP_SIGNAL_ATTRIBUT ((TLR_RESULT)0xC0140019L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DBM_IMPROPER_DPM_OFFSETS_AND_DATA_LENGTHS_IN_SIGNALS */
/*  */
/*  MessageText: */
/*  */
/*   Improper DPM offset and data length in SIGNALS. */
/*  */
#define TLR_E_PNIO_APCFG_DBM_IMPROPER_DPM_OFFSETS_AND_DATA_LENGTHS_IN_SIGNALS ((TLR_RESULT)0xC014001AL)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DBM_WRONG_TEST_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Wrong test data. */
/*  */
#define TLR_E_PNIO_APCFG_DBM_WRONG_TEST_DATA ((TLR_RESULT)0xC0140020L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DBM_INVALID_IO_DEVICE_AMOUNT */
/*  */
/*  MessageText: */
/*  */
/*   Too many IO-Devices are configured. */
/*  */
#define TLR_E_PNIO_APCFG_DBM_INVALID_IO_DEVICE_AMOUNT ((TLR_RESULT)0xC0140021L)

/*  standard error codes  */
/*  */
/*  MessageId: TLR_E_PNIO_APCFG_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Not enough memory available for current request. */
/*  */
#define TLR_E_PNIO_APCFG_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0140030L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Error while sending internal message to another task. */
/*  */
#define TLR_E_PNIO_APCFG_PACKET_SEND_FAILED ((TLR_RESULT)0xC0140031L)

/* Packet configuration check error codes */
/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_NAME_OF_STATION_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   The length of parameter NameOfStation is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_NAME_OF_STATION_LENGTH ((TLR_RESULT)0xC0140040L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_NAME_OF_STATION_CHARACTER */
/*  */
/*  MessageText: */
/*  */
/*   The NameOfStation contains an invalid character. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_NAME_OF_STATION_CHARACTER ((TLR_RESULT)0xC0140041L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_TYPE_OF_STATION_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   The length of parameter TypeOfStation is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_TYPE_OF_STATION_LENGTH ((TLR_RESULT)0xC0140042L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_TYPE_OF_STATION_CHARACTER */
/*  */
/*  MessageText: */
/*  */
/*   The TypeOfStation cintains an invalid character. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_TYPE_OF_STATION_CHARACTER ((TLR_RESULT)0xC0140043L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_SYSTEMFLAGS */
/*  */
/*  MessageText: */
/*  */
/*   The parameter SystemFlags is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_SYSTEMFLAGS ((TLR_RESULT)0xC0140044L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_WATCHDOG_TIME */
/*  */
/*  MessageText: */
/*  */
/*   The parameter WatchdogTime is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_WATCHDOG_TIME ((TLR_RESULT)0xC0140045L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_VENDORID */
/*  */
/*  MessageText: */
/*  */
/*   The Parameter VendorID is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_VENDORID ((TLR_RESULT)0xC0140046L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_DEVICEID */
/*  */
/*  MessageText: */
/*  */
/*   The parameter DeviceID is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_DEVICEID ((TLR_RESULT)0xC0140047L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_IP_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   The IP-Address to use is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_IP_ADDRESS ((TLR_RESULT)0xC0140048L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_NETMASK */
/*  */
/*  MessageText: */
/*  */
/*   The NetworkMask to use is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_NETMASK ((TLR_RESULT)0xC0140049L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_GATEWAY */
/*  */
/*  MessageText: */
/*  */
/*   The Gateway-Address to use is invalid or unreachable. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_GATEWAY ((TLR_RESULT)0xC014004AL)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_IP_FLAGS */
/*  */
/*  MessageText: */
/*  */
/*   The parameter IPFlags is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_IP_FLAGS ((TLR_RESULT)0xC014004BL)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_NAME_OF_STATION_STARTLABEL */
/*  */
/*  MessageText: */
/*  */
/*   The NameOfStation shall not start with - . or port-xyz. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_NAME_OF_STATION_STARTLABEL ((TLR_RESULT)0xC014004CL)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_NAME_OF_STATION_LABEL_TOO_SHORT */
/*  */
/*  MessageText: */
/*  */
/*   One label of NameOfStation is too short. */
/*  */
#define TLR_E_PNIO_APCFG_NAME_OF_STATION_LABEL_TOO_SHORT ((TLR_RESULT)0xC014004DL)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_NAME_OF_STATION_LABEL_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   One label of NameOfStation is too long. */
/*  */
#define TLR_E_PNIO_APCFG_NAME_OF_STATION_LABEL_TOO_LONG ((TLR_RESULT)0xC014004EL)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_NAME_OF_STATION_TOO_MANY_LABELS */
/*  */
/*  MessageText: */
/*  */
/*   The NameOfStation contains too many labels. */
/*  */
#define TLR_E_PNIO_APCFG_NAME_OF_STATION_TOO_MANY_LABELS ((TLR_RESULT)0xC014004FL)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_RTA_RETRIES */
/*  */
/*  MessageText: */
/*  */
/*   The parameter RTARetries is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_RTA_RETRIES ((TLR_RESULT)0xC0140050L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_RTA_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   The parameter RTATimeout is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_RTA_TIMEOUT ((TLR_RESULT)0xC0140051L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_AR_PROPERTIES */
/*  */
/*  MessageText: */
/*  */
/*   The parameter ARProperties is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_AR_PROPERTIES ((TLR_RESULT)0xC0140052L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_AR_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   The parameter ARType is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_AR_TYPE ((TLR_RESULT)0xC0140053L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_AR_UUID */
/*  */
/*  MessageText: */
/*  */
/*   The parameter ARUUID is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_AR_UUID ((TLR_RESULT)0xC0140054L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_ALARMCR_PROPERTIES */
/*  */
/*  MessageText: */
/*  */
/*   The parameter AlarmCRProperties is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_ALARMCR_PROPERTIES ((TLR_RESULT)0xC0140055L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_ALARMCR_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   The Parameter AlarmCRType is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_ALARMCR_TYPE ((TLR_RESULT)0xC0140056L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_MCAST_MAC */
/*  */
/*  MessageText: */
/*  */
/*   The parameter MulticastMACAddress is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_MCAST_MAC ((TLR_RESULT)0xC0140060L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_FRAMESENDOFFSET */
/*  */
/*  MessageText: */
/*  */
/*   The parameter FrameSendOffset is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_FRAMESENDOFFSET ((TLR_RESULT)0xC0140061L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_IOCR_PROPERTIES */
/*  */
/*  MessageText: */
/*  */
/*   The parameter IOCRProperties is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_IOCR_PROPERTIES ((TLR_RESULT)0xC0140062L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_IOCR_DATA_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   The parameter IOCRDataLength is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_IOCR_DATA_LENGTH ((TLR_RESULT)0xC0140063L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_IOCR_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   The parameter IOCRType is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_IOCR_TYPE ((TLR_RESULT)0xC0140064L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_DATAHOLDFACTOR */
/*  */
/*  MessageText: */
/*  */
/*   The parameter DataHoldFactor is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_DATAHOLDFACTOR ((TLR_RESULT)0xC0140065L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_WATCHDOGFACTOR */
/*  */
/*  MessageText: */
/*  */
/*   The Parameter WatchdogFactor is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_WATCHDOGFACTOR ((TLR_RESULT)0xC0140066L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_SENDCLOCKFACTOR */
/*  */
/*  MessageText: */
/*  */
/*   The parameter SendClockFactor is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_SENDCLOCKFACTOR ((TLR_RESULT)0xC0140067L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_REDUCTIONRATIO */
/*  */
/*  MessageText: */
/*  */
/*   The parameter ReductionRatio is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_REDUCTIONRATIO ((TLR_RESULT)0xC0140068L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_PHASE */
/*  */
/*  MessageText: */
/*  */
/*   The Parameter Phase is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_PHASE   ((TLR_RESULT)0xC0140069L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_IOCS_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   The parameter IOCSLength is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_IOCS_LENGTH ((TLR_RESULT)0xC0140070L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_IOPS_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   The parameter IOPSLength is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_IOPS_LENGTH ((TLR_RESULT)0xC0140071L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_DPM_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   The parameter DPMOffset is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_DPM_OFFSET ((TLR_RESULT)0xC0140072L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_FRAME_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   The parameter FrameOffset is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_FRAME_OFFSET ((TLR_RESULT)0xC0140073L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_IOCS_FRAME_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   The parameter IOCSFrameOffset is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_IOCS_FRAME_OFFSET ((TLR_RESULT)0xC0140074L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_SUBMODULE_DATA_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   The parameter SubmoduleDataLength is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_SUBMODULE_DATA_LENGTH ((TLR_RESULT)0xC0140075L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_DATA_DESCRIPTION */
/*  */
/*  MessageText: */
/*  */
/*   The Parameter DataDescription is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_DATA_DESCRIPTION ((TLR_RESULT)0xC0140076L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_OVERLAPPING_FRAMEOFFSET_DATA */
/*  */
/*  MessageText: */
/*  */
/*   The frame offset to use for IO-Data is already in use by another submodule. */
/*  */
#define TLR_E_PNIO_APCFG_OVERLAPPING_FRAMEOFFSET_DATA ((TLR_RESULT)0xC0140077L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_OVERLAPPING_FRAMEOFFSET_IOCS */
/*  */
/*  MessageText: */
/*  */
/*   The frame offset to use for the IOCS is already in use by another submodule. */
/*  */
#define TLR_E_PNIO_APCFG_OVERLAPPING_FRAMEOFFSET_IOCS ((TLR_RESULT)0xC0140078L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_OVERLAPPING_DPMOFFSET */
/*  */
/*  MessageText: */
/*  */
/*   The DPM offset to use for IO-Data is already in use by another submodule. */
/*  */
#define TLR_E_PNIO_APCFG_OVERLAPPING_DPMOFFSET ((TLR_RESULT)0xC0140079L)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_FRAMEOFFSET_OUTSIDE_DEFINED_IOCR */
/*  */
/*  MessageText: */
/*  */
/*   The frame offset is bigger than the IOCR-length. */
/*  */
#define TLR_E_PNIO_APCFG_FRAMEOFFSET_OUTSIDE_DEFINED_IOCR ((TLR_RESULT)0xC014007AL)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_IOCS_FRAMEOFFSET_OUTSIDE_DEFINED_IOCR */
/*  */
/*  MessageText: */
/*  */
/*   The IOCS frame offset is bigger than the IOCR-length. */
/*  */
#define TLR_E_PNIO_APCFG_IOCS_FRAMEOFFSET_OUTSIDE_DEFINED_IOCR ((TLR_RESULT)0xC014007BL)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_IOCR_PROD_ID */
/*  */
/*  MessageText: */
/*  */
/*   The IOCRIdProd is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_IOCR_PROD_ID ((TLR_RESULT)0xC014007CL)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_IOCR_CONS_ID */
/*  */
/*  MessageText: */
/*  */
/*   The IOCRICons is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_IOCR_CONS_ID ((TLR_RESULT)0xC014007DL)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_INVALID_RECORD_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   The record data length is invalid. */
/*  */
#define TLR_E_PNIO_APCFG_INVALID_RECORD_LENGTH ((TLR_RESULT)0xC014007EL)

/*  */
/*  MessageId: TLR_E_PNIO_APCFG_DUPLICATE_ARUUID */
/*  */
/*  MessageText: */
/*  */
/*   The ARUUID of this IO-Device is already in use by another IO-Device. */
/*  */
#define TLR_E_PNIO_APCFG_DUPLICATE_ARUUID ((TLR_RESULT)0xC014007FL)




#endif  /* __PNIO_APCTL_ERROR_H */

#ifndef __PNIOC_ERROR_H
#define __PNIOC_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PNIO CTL Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CMCTL-Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Received invalid command in CMCTL task. */
/*  */
#define TLR_E_PNIO_CMCTL_COMMAND_INVALID ((TLR_RESULT)0xC00A0001L)

/*  */
/*  MessageId: TLR_E_PNIO_STATUS */
/*  */
/*  MessageText: */
/*  */
/*   Generic error code. See packets data-status code for details. */
/*  */
#define TLR_E_PNIO_STATUS                ((TLR_RESULT)0xC00A0002L)

/*  CMCTL */
/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_INIT_PARAM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter in CMCTL_ResourceInit(). */
/*  */
#define TLR_E_PNIO_CMCTL_INIT_PARAM_INVALID ((TLR_RESULT)0xC00A0010L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_RESOURCE_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   No more CMCTL protocol machines possible. */
/*  */
#define TLR_E_PNIO_CMCTL_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC00A0011L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory for this request to CMCTL. */
/*  */
#define TLR_E_PNIO_CMCTL_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC00A0012L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_CLOSED */
/*  */
/*  MessageText: */
/*  */
/*   This CMCTL protocol machine was closed. */
/*  */
#define TLR_E_PNIO_CMCTL_CLOSED          ((TLR_RESULT)0xC00A0013L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_STATE_CONFLICT */
/*  */
/*  MessageText: */
/*  */
/*   This request can not be served in current CMCTL state. */
/*  */
#define TLR_E_PNIO_CMCTL_STATE_CONFLICT  ((TLR_RESULT)0xC00A0014L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_CONFIG_PENDING */
/*  */
/*  MessageText: */
/*  */
/*   The state of CMCTL's managment resource is pending. */
/*  */
#define TLR_E_PNIO_CMCTL_CONFIG_PENDING  ((TLR_RESULT)0xC00A0015L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_CONFIG_STATE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The state of CMCTL's managment resource is invalid. */
/*  */
#define TLR_E_PNIO_CMCTL_CONFIG_STATE_INVALID ((TLR_RESULT)0xC00A0016L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_PACKET_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory to create a packet in CMCTL task. */
/*  */
#define TLR_E_PNIO_CMCTL_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC00A0017L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Error while sending a packet to another task in CMCTL. */
/*  */
#define TLR_E_PNIO_CMCTL_PACKET_SEND_FAILED ((TLR_RESULT)0xC00A0018L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_CONN_REQ_LEN_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The length of the Connect-Packet in CMCTL_Connect_req() is invalid. */
/*  */
#define TLR_E_PNIO_CMCTL_CONN_REQ_LEN_INVALID ((TLR_RESULT)0xC00A0019L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_NAME_LEN_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The length of the name for IO-Device does not match to the name in CMCTL_Connect_req(). */
/*  */
#define TLR_E_PNIO_CMCTL_NAME_LEN_INVALID ((TLR_RESULT)0xC00A001AL)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_BLKNUM_UNEXPECTED */
/*  */
/*  MessageText: */
/*  */
/*   The Connect-Confirmation contains an incorrect amount of blocks. */
/*  */
#define TLR_E_PNIO_CMCTL_BLKNUM_UNEXPECTED ((TLR_RESULT)0xC00A001BL)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_BLKNUM_UNEXPECTED_MEMORY_FAULT */
/*  */
/*  MessageText: */
/*  */
/*   The Connect-Confirmation contains an incorrect amount of blocks but may be received correctly in RPC-layer. CMCTL protocol-machine has not reserved enough memory for the whole confirmation. */
/*  */
#define TLR_E_PNIO_CMCTL_BLKNUM_UNEXPECTED_MEMORY_FAULT ((TLR_RESULT)0xC00A001CL)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_INVALID_FRAMEID_RECEIVED */
/*  */
/*  MessageText: */
/*  */
/*   The Connect-Response from IO-Device specified an invalid FrameID to use for IO-Controllers OutputCR. */
/*  */
#define TLR_E_PNIO_CMCTL_INVALID_FRAMEID_RECEIVED ((TLR_RESULT)0xC00A001DL)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_EMPTY_POOL_DETECTED */
/*  */
/*  MessageText: */
/*  */
/*   The packet pool of CMCTL is empty. */
/*  */
#define TLR_E_PNIO_CMCTL_EMPTY_POOL_DETECTED ((TLR_RESULT)0xC00A001EL)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_BLKTYPE_UNEXPECTED */
/*  */
/*  MessageText: */
/*  */
/*   The connect-confirmation contains an unexpected block. */
/*  */
#define TLR_E_PNIO_CMCTL_BLKTYPE_UNEXPECTED ((TLR_RESULT)0xC00A0020L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_BLKTYPE_UNEXPECTED_INIT */
/*  */
/*  MessageText: */
/*  */
/*   CMCTL_Connect_req() expected an INIT-block that is missing. */
/*  */
#define TLR_E_PNIO_CMCTL_BLKTYPE_UNEXPECTED_INIT ((TLR_RESULT)0xC00A0021L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_BLKTYPE_UNEXPECTED_IODW_REQ */
/*  */
/*  MessageText: */
/*  */
/*   CMCTL_RMWrite_req() expected a WriteReq-block that is missing. */
/*  */
#define TLR_E_PNIO_CMCTL_BLKTYPE_UNEXPECTED_IODW_REQ ((TLR_RESULT)0xC00A0022L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_BLKTYPE_UNEXPECTED_IODW_DATA */
/*  */
/*  MessageText: */
/*  */
/*   CMCTL_RMWrite_req() expected a WriteData-block that is missing. */
/*  */
#define TLR_E_PNIO_CMCTL_BLKTYPE_UNEXPECTED_IODW_DATA ((TLR_RESULT)0xC00A0023L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_BLKLEN_INVALID_INIT */
/*  */
/*  MessageText: */
/*  */
/*   INIT-block length for CMCTL_Connect_req() is invalid. */
/*  */
#define TLR_E_PNIO_CMCTL_BLKLEN_INVALID_INIT ((TLR_RESULT)0xC00A0030L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_BLKLEN_INVALID_IODW_REQ */
/*  */
/*  MessageText: */
/*  */
/*   WriteReq-block's length for CMCTL_RMWrite_req() is invalid. */
/*  */
#define TLR_E_PNIO_CMCTL_BLKLEN_INVALID_IODW_REQ ((TLR_RESULT)0xC00A0031L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_BLKLEN_INVALID_IODW_DATA */
/*  */
/*  MessageText: */
/*  */
/*   WriteData-block's length for CMCTL_RMWrite_req() is invalid. */
/*  */
#define TLR_E_PNIO_CMCTL_BLKLEN_INVALID_IODW_DATA ((TLR_RESULT)0xC00A0032L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_INVALID_PM_INDEX */
/*  */
/*  MessageText: */
/*  */
/*   The index of CMCTL protocol-machine is invalid. */
/*  */
#define TLR_E_PNIO_CMCTL_INVALID_PM_INDEX ((TLR_RESULT)0xC00A0040L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_INVALID_PM */
/*  */
/*  MessageText: */
/*  */
/*   The CMCTL protocol-machine corresponding to index is invalid. */
/*  */
#define TLR_E_PNIO_CMCTL_INVALID_PM      ((TLR_RESULT)0xC00A0041L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_INVALID_CMCTL_HANDLE */
/*  */
/*  MessageText: */
/*  */
/*   The handle to CMCTL protocol-machine is invalid. */
/*  */
#define TLR_E_PNIO_CMCTL_INVALID_CMCTL_HANDLE ((TLR_RESULT)0xC00A0042L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_DEVICE_NOT_RESPONDING */
/*  */
/*  MessageText: */
/*  */
/*   The IO-Device which shall be connected does not answer. */
/*  */
#define TLR_E_PNIO_CMCTL_DEVICE_NOT_RESPONDING ((TLR_RESULT)0xC00A0050L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_DUPLICATE_DEVICE_NAME_DETECTED */
/*  */
/*  MessageText: */
/*  */
/*   More than one IO-Device with the specified NameOfStation exists; a connection can not be established. */
/*  */
#define TLR_E_PNIO_CMCTL_DUPLICATE_DEVICE_NAME_DETECTED ((TLR_RESULT)0xC00A0051L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_DEVICE_IP_ADDRESS_ALREADY_IN_USE */
/*  */
/*  MessageText: */
/*  */
/*   The IP-address the controller shall use for the IO-Device is already in use by another network device; a connection can not be established. */
/*  */
#define TLR_E_PNIO_CMCTL_DEVICE_IP_ADDRESS_ALREADY_IN_USE ((TLR_RESULT)0xC00A0052L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_RPC_CONNECT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The Connect-Response of IO-Device contained an error code; a connection could not be established. */
/*  */
#define TLR_E_PNIO_CMCTL_RPC_CONNECT_FAILED ((TLR_RESULT)0xC00A0060L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_RPC_WRITE_PARAM_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The Write_Param-Response of IO-Device contained an error code; a connection could not be established. */
/*  */
#define TLR_E_PNIO_CMCTL_RPC_WRITE_PARAM_FAILED ((TLR_RESULT)0xC00A0061L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_RPC_WRITE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The Write-Response of IO-Device contained an error code. */
/*  */
#define TLR_E_PNIO_CMCTL_RPC_WRITE_FAILED ((TLR_RESULT)0xC00A0062L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_RPC_READ_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The Read-Response of IO-Device contained an error code. */
/*  */
#define TLR_E_PNIO_CMCTL_RPC_READ_FAILED ((TLR_RESULT)0xC00A0063L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_TCP_IP_SHUTDOWN */
/*  */
/*  MessageText: */
/*  */
/*   The TCP/IP-Stack closed a socket needed for communication. */
/*  */
#define TLR_E_PNIO_CMCTL_TCP_IP_SHUTDOWN ((TLR_RESULT)0xC00A0064L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_RPC_RESPONSE_TOO_SHORT */
/*  */
/*  MessageText: */
/*  */
/*   The RPC-Response received does not have the required minimum length. */
/*  */
#define TLR_E_PNIO_CMCTL_RPC_RESPONSE_TOO_SHORT ((TLR_RESULT)0xC00A0065L)

/*  CMCTL AR */
/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_AR_BLOCKTYPE */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for AR in CMCTL_RMConnect_req_LoadAr() is missing. */
/*  */
#define TLR_E_PNIO_CMCTL_AR_BLOCKTYPE    ((TLR_RESULT)0xC00A0070L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_AR_BLOCKLEN */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for AR in CMCTL_RMConnect_req_LoadAr() has an invalid length. */
/*  */
#define TLR_E_PNIO_CMCTL_AR_BLOCKLEN     ((TLR_RESULT)0xC00A0071L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_AR_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   The configuration block for AR in CMCTL_RMConnect_req_LoadAr() has an invalid type. */
/*  */
#define TLR_E_PNIO_CMCTL_AR_TYPE         ((TLR_RESULT)0xC00A0072L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_AR_UUID */
/*  */
/*  MessageText: */
/*  */
/*   The configuration block for AR in CMCTL_RMConnect_req_LoadAr() has an invalid UUID. */
/*  */
#define TLR_E_PNIO_CMCTL_AR_UUID         ((TLR_RESULT)0xC00A0073L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_AR_PROPERTY */
/*  */
/*  MessageText: */
/*  */
/*   The configuration block for AR in CMCTL_RMConnect_req_LoadAr() has an invalid network properties value. */
/*  */
#define TLR_E_PNIO_CMCTL_AR_PROPERTY     ((TLR_RESULT)0xC00A0074L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_AR_REF_UNEXPECTED */
/*  */
/*  MessageText: */
/*  */
/*   The AR-Reference for CMCTL protocol-machine is invalid. */
/*  */
#define TLR_E_PNIO_CMCTL_AR_REF_UNEXPECTED ((TLR_RESULT)0xC00A0075L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_AR_UUID_COMP_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The UUID inside IO-Device's Connect-Confirmation is incorrect. */
/*  */
#define TLR_E_PNIO_CMCTL_AR_UUID_COMP_FAILED ((TLR_RESULT)0xC00A0076L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_AR_KEY_COMP_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The session-key inside IO-Device's Connect-Confirmation is incorrect. */
/*  */
#define TLR_E_PNIO_CMCTL_AR_KEY_COMP_FAILED ((TLR_RESULT)0xC00A0077L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_AR_MAC_COMP_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The MAC-address of IO-Device is incorrect. */
/*  */
#define TLR_E_PNIO_CMCTL_AR_MAC_COMP_FAILED ((TLR_RESULT)0xC00A0078L)

/*  CMCTL ALCR */
/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_ALCR_BLOCKTYPE */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for Alarm-CR in CMCTL_RMConnect_req_LoadAlcr() is missing. */
/*  */
#define TLR_E_PNIO_CMCTL_ALCR_BLOCKTYPE  ((TLR_RESULT)0xC00A0080L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_ALCR_BLOCKLEN */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for Alarm-CR in CMCTL_RMConnect_req_LoadAlcr() has an invalid length. */
/*  */
#define TLR_E_PNIO_CMCTL_ALCR_BLOCKLEN   ((TLR_RESULT)0xC00A0081L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_ALCR_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   The configuration block for Alarm-CR in CMCTL_RMConnect_req_LoadAlcr() has an invalid type. */
/*  */
#define TLR_E_PNIO_CMCTL_ALCR_TYPE       ((TLR_RESULT)0xC00A0082L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_ALCR_PROPERTY */
/*  */
/*  MessageText: */
/*  */
/*   The configuration block for Alarm-CR in CMCTL_RMConnect_req_LoadAlcr() has an invalid network properties value. */
/*  */
#define TLR_E_PNIO_CMCTL_ALCR_PROPERTY   ((TLR_RESULT)0xC00A0083L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_ALCR_RTA_FACTOR */
/*  */
/*  MessageText: */
/*  */
/*   The configuration block for Alarm-CR in CMCTL_RMConnect_req_LoadAlcr() has an invalid RTA-factor. */
/*  */
#define TLR_E_PNIO_CMCTL_ALCR_RTA_FACTOR ((TLR_RESULT)0xC00A0084L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_ALCR_RTA_RETRY */
/*  */
/*  MessageText: */
/*  */
/*   The configuration block for Alarm-CR in CMCTL_RMConnect_req_LoadAlcr() has an invalid value for RTA-retry. */
/*  */
#define TLR_E_PNIO_CMCTL_ALCR_RTA_RETRY  ((TLR_RESULT)0xC00A0085L)

/*  CMCTL IOCR */
/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_IOCR_BLOCKLEN */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for IOCR in CMCTL_RMConnect_req_LoadIocr() has an invalid length. */
/*  */
#define TLR_E_PNIO_CMCTL_IOCR_BLOCKLEN   ((TLR_RESULT)0xC00A0090L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_IOCR_TYPE_UNSUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   The type of IOCR is unsupported. */
/*  */
#define TLR_E_PNIO_CMCTL_IOCR_TYPE_UNSUPPORTED ((TLR_RESULT)0xC00A0091L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_IOCR_TYPE_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   The type of IOCR is unknown. */
/*  */
#define TLR_E_PNIO_CMCTL_IOCR_TYPE_UNKNOWN ((TLR_RESULT)0xC00A0092L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_IOCR_RTCCLASS_UNSUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   The RTC-class is unsupported. */
/*  */
#define TLR_E_PNIO_CMCTL_IOCR_RTCCLASS_UNSUPPORTED ((TLR_RESULT)0xC00A0093L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_IOCR_RTCCLASS_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   The RTC-class is unknown. */
/*  */
#define TLR_E_PNIO_CMCTL_IOCR_RTCCLASS_UNKNOWN ((TLR_RESULT)0xC00A0094L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_IOCR_IFTYPE_UNSUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for IOCR in CMCTL_RMConnect_req_LoadIocr() has an unsupported interface-type. */
/*  */
#define TLR_E_PNIO_CMCTL_IOCR_IFTYPE_UNSUPPORTED ((TLR_RESULT)0xC00A0095L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_IOCR_SCSYNC_UNSUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for IOCR in CMCTL_RMConnect_req_LoadIocr() has an unsupported value for SendClock. */
/*  */
#define TLR_E_PNIO_CMCTL_IOCR_SCSYNC_UNSUPPORTED ((TLR_RESULT)0xC00A0096L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_IOCR_ADDRESS_UNSUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for IOCR in CMCTL_RMConnect_req_LoadIocr() has an unsupported Address-Resolution. */
/*  */
#define TLR_E_PNIO_CMCTL_IOCR_ADDRESS_UNSUPPORTED ((TLR_RESULT)0xC00A0097L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_IOCR_REDUNDANCY_UNSUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for IOCR in CMCTL_RMConnect_req_LoadIocr() has an unsupported Media-Redundancy. */
/*  */
#define TLR_E_PNIO_CMCTL_IOCR_REDUNDANCY_UNSUPPORTED ((TLR_RESULT)0xC00A0098L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_IOCR_REFERENCE */
/*  */
/*  MessageText: */
/*  */
/*   No IOCR could be found or created. */
/*  */
#define TLR_E_PNIO_CMCTL_IOCR_REFERENCE  ((TLR_RESULT)0xC00A0099L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_IOCR_OBJECT_IOD */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for IOCR in CMCTL_RMConnect_req_LoadIocr() does not contain any IO-Data. */
/*  */
#define TLR_E_PNIO_CMCTL_IOCR_OBJECT_IOD ((TLR_RESULT)0xC00A009AL)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_IOCR_OBJECT_IOS */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for IOCR in CMCTL_RMConnect_req_LoadIocr() does not contain any IO-Status. */
/*  */
#define TLR_E_PNIO_CMCTL_IOCR_OBJECT_IOS ((TLR_RESULT)0xC00A009BL)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_IOCR_API */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for IOCR in CMCTL_RMConnect_req_LoadIocr() does not contain any API. */
/*  */
#define TLR_E_PNIO_CMCTL_IOCR_API        ((TLR_RESULT)0xC00A009CL)

/*  CMCTL EXPS */
/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_EXPS_BLOCKLEN */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for Expected-Submodules in CMCTL_RMConnect_req_LoadExps() has an invalid length. */
/*  */
#define TLR_E_PNIO_CMCTL_EXPS_BLOCKLEN   ((TLR_RESULT)0xC00A00A0L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_EXPS_API */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for Expected-Submodules in CMCTL_RMConnect_req_LoadExps() does not contain any API. */
/*  */
#define TLR_E_PNIO_CMCTL_EXPS_API        ((TLR_RESULT)0xC00A00A1L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_EXPS_SUBMODULE */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for Expected-Submodules in CMCTL_RMConnect_req_LoadExps() does not contain any submodules. */
/*  */
#define TLR_E_PNIO_CMCTL_EXPS_SUBMODULE  ((TLR_RESULT)0xC00A00A2L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_EXPS_DATADESCRIPTION */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for Expected-Submodules in CMCTL_RMConnect_req_LoadExps() does not contain the expected amount of data-descriptions. */
/*  */
#define TLR_E_PNIO_CMCTL_EXPS_DATADESCRIPTION ((TLR_RESULT)0xC00A00A3L)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_ACYCLIC_REQ_FAILED_REMOTE */
/*  */
/*  MessageText: */
/*  */
/*   The acyclic service failed. The IO-Device answered with an error code which is contained in confirmation packet. */
/*  */
#define TLR_E_PNIO_CMCTL_ACYCLIC_REQ_FAILED_REMOTE ((TLR_RESULT)0xC00C00AAL)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_ACYCLIC_REQ_FAILED_RPC */
/*  */
/*  MessageText: */
/*  */
/*   The acyclic service failed. The RPC-layer detected an error which is contained in confirmation packet. */
/*  */
#define TLR_E_PNIO_CMCTL_ACYCLIC_REQ_FAILED_RPC ((TLR_RESULT)0xC00C00ABL)

/*  */
/*  MessageId: TLR_E_PNIO_CMCTL_ACYCLIC_REQ_FAILED_INTERNAL */
/*  */
/*  MessageText: */
/*  */
/*   The acyclic service failed. An internal error occured. */
/*  */
#define TLR_E_PNIO_CMCTL_ACYCLIC_REQ_FAILED_INTERNAL ((TLR_RESULT)0xC00C00ACL)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CMDEV-Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Received invalid command in CMDEV task. */
/*  */
#define TLR_E_PNIO_CMDEV_COMMAND_INVALID ((TLR_RESULT)0xC00B0001L)

/*  CMDEV */
/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_INIT_PARAM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter in CMDEV_ResourceInit(). */
/*  */
#define TLR_E_PNIO_CMDEV_INIT_PARAM_INVALID ((TLR_RESULT)0xC00B0010L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_RESOURCE_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   No more CMDEV protocol machines possible. */
/*  */
#define TLR_E_PNIO_CMDEV_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC00B0011L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory for this request to CMDEV. */
/*  */
#define TLR_E_PNIO_CMDEV_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC00B0012L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_CLOSED */
/*  */
/*  MessageText: */
/*  */
/*   This CMDEV protocol machine was closed. */
/*  */
#define TLR_E_PNIO_CMDEV_CLOSED          ((TLR_RESULT)0xC00B0013L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_STATE_CONFLICT */
/*  */
/*  MessageText: */
/*  */
/*   This request can not be served in current CMDEV state. */
/*  */
#define TLR_E_PNIO_CMDEV_STATE_CONFLICT  ((TLR_RESULT)0xC00B0014L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_CONFIG_PENDING */
/*  */
/*  MessageText: */
/*  */
/*   The state of CMDEV's managment resource is pending. */
/*  */
#define TLR_E_PNIO_CMDEV_CONFIG_PENDING  ((TLR_RESULT)0xC00B0015L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_CONFIG_STATE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The state of CMDEV's managment resource is invalid. */
/*  */
#define TLR_E_PNIO_CMDEV_CONFIG_STATE_INVALID ((TLR_RESULT)0xC00B0016L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_PACKET_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory to create a packet in CMDEV task. */
/*  */
#define TLR_E_PNIO_CMDEV_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC00B0017L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Error while sending a packet to another task in CMDEV. */
/*  */
#define TLR_E_PNIO_CMDEV_PACKET_SEND_FAILED ((TLR_RESULT)0xC00B0018L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_CONN_REQ_LEN_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The length of the Connect-Packet in CMDEV_Connect_req() is invalid. */
/*  */
#define TLR_E_PNIO_CMDEV_CONN_REQ_LEN_INVALID ((TLR_RESULT)0xC00B0019L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_NAME_LEN_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The length of the name for IO-Device does not match to the name in CMDEV_Connect_req(). */
/*  */
#define TLR_E_PNIO_CMDEV_NAME_LEN_INVALID ((TLR_RESULT)0xC00B001AL)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_BLKNUM_UNEXPECTED */
/*  */
/*  MessageText: */
/*  */
/*   The Connect-Confirmation contains an incorrect amount of blocks. */
/*  */
#define TLR_E_PNIO_CMDEV_BLKNUM_UNEXPECTED ((TLR_RESULT)0xC00B001BL)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_BLKNUM_UNEXPECTED_MEMORY_FAULT */
/*  */
/*  MessageText: */
/*  */
/*   The Connect-Confirmation contains an incorrect amount of blocks but may be received correctly in RPC-layer. CMDEV protocol-machine has not reserved enough memory for the whole confirmation. */
/*  */
#define TLR_E_PNIO_CMDEV_BLKNUM_UNEXPECTED_MEMORY_FAULT ((TLR_RESULT)0xC00B001CL)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_INVALID_FRAMEID_RECEIVED */
/*  */
/*  MessageText: */
/*  */
/*   The Connect-Response from IO-Device specified an invalid FrameID to use for IO-Controllers OutputCR. */
/*  */
#define TLR_E_PNIO_CMDEV_INVALID_FRAMEID_RECEIVED ((TLR_RESULT)0xC00B001DL)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_PNIO_STATUS */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_PNIO_STATUS     ((TLR_RESULT)0xC00B001EL)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_EMPTY_POOL_DETECTED */
/*  */
/*  MessageText: */
/*  */
/*   The packet pool of CMDEV is empty. */
/*  */
#define TLR_E_PNIO_CMDEV_EMPTY_POOL_DETECTED ((TLR_RESULT)0xC00B001FL)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_PACKET_WRONG_DEVICEHANDLE */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_PACKET_WRONG_DEVICEHANDLE ((TLR_RESULT)0xC00B0020L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_POINTER_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_POINTER_INVALID ((TLR_RESULT)0xC00B0021L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_FUNCTION_RETURN_FAILURE */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_FUNCTION_RETURN_FAILURE ((TLR_RESULT)0xC00B0022L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_WAIT_FOR_PACKET_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_WAIT_FOR_PACKET_FAILED ((TLR_RESULT)0xC00B0023L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_ALPMI_ACTIVATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_ALPMI_ACTIVATE_FAILED ((TLR_RESULT)0xC00B0024L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_BUILD_CONNECT_RSP_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_BUILD_CONNECT_RSP_FAILED ((TLR_RESULT)0xC00B0025L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_AP_ENTRY_NOT_FOUND */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_AP_ENTRY_NOT_FOUND ((TLR_RESULT)0xC00B0026L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_TIMER_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_TIMER_CREATE_FAILED ((TLR_RESULT)0xC00B0027L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_ERROR_SEQUENCE */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_ERROR_SEQUENCE  ((TLR_RESULT)0xC00B0028L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_INVALID_PLUG_REQUEST_PCK */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_INVALID_PLUG_REQUEST_PCK ((TLR_RESULT)0xC00B0029L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_INVALID_PULL_REQUEST_PCK */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_INVALID_PULL_REQUEST_PCK ((TLR_RESULT)0xC00B002AL)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_PLUG_SLOT_NOT_EXPECTED */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_PLUG_SLOT_NOT_EXPECTED ((TLR_RESULT)0xC00B002BL)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_PLUG_SUBSLOT_NOT_EXPECTED */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_PLUG_SUBSLOT_NOT_EXPECTED ((TLR_RESULT)0xC00B002CL)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_RPC_PACKET_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_RPC_PACKET_INVALID ((TLR_RESULT)0xC00B002DL)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_ALPMI_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Initializing the ALPMI state machine failed. */
/*  */
#define TLR_E_PNIO_CMDEV_ALPMI_INIT_FAILED ((TLR_RESULT)0xC00B002EL)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_CHANGE_BUS_STATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Changing the internal Bus state failed. */
/*  */
#define TLR_E_PNIO_CMDEV_CHANGE_BUS_STATE_FAILED ((TLR_RESULT)0xC00B002FL)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_INVALID_PM_INDEX */
/*  */
/*  MessageText: */
/*  */
/*   The index of CMDEV protocol-machine is invalid. */
/*  */
#define TLR_E_PNIO_CMDEV_INVALID_PM_INDEX ((TLR_RESULT)0xC00B0040L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_INVALID_PM */
/*  */
/*  MessageText: */
/*  */
/*   The CMDEV protocol-machine corresponding to index is invalid. */
/*  */
#define TLR_E_PNIO_CMDEV_INVALID_PM      ((TLR_RESULT)0xC00B0041L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_INVALID_CMDEV_HANDLE */
/*  */
/*  MessageText: */
/*  */
/*   The handle to CMDEV protocol-machine is invalid. */
/*  */
#define TLR_E_PNIO_CMDEV_INVALID_CMDEV_HANDLE ((TLR_RESULT)0xC00B0042L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_SUBMODULE_NOT_IN_CYCLIC_DATA_EXCHANGE */
/*  */
/*  MessageText: */
/*  */
/*   The request can not be handled because the submodule is not contained in cyclic data exchange. */
/*  */
#define TLR_E_PNIO_CMDEV_SUBMODULE_NOT_IN_CYCLIC_DATA_EXCHANGE ((TLR_RESULT)0xC00B0043L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_DEVICE_NOT_RESPONDING */
/*  */
/*  MessageText: */
/*  */
/*   The IO-Device which shall be connected does not answer. */
/*  */
#define TLR_E_PNIO_CMDEV_DEVICE_NOT_RESPONDING ((TLR_RESULT)0xC00B0050L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_DUPLICATE_DEVICE_NAME_DETECTED */
/*  */
/*  MessageText: */
/*  */
/*   More than one IO-Device with the specified NameOfStation exists; a connection can not be established. */
/*  */
#define TLR_E_PNIO_CMDEV_DUPLICATE_DEVICE_NAME_DETECTED ((TLR_RESULT)0xC00B0051L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_DEVICE_IP_ADDRESS_ALREADY_IN_USE */
/*  */
/*  MessageText: */
/*  */
/*   The IP-address the controller shall use for the IO-Device is already in use by another network device; a connection can not be established. */
/*  */
#define TLR_E_PNIO_CMDEV_DEVICE_IP_ADDRESS_ALREADY_IN_USE ((TLR_RESULT)0xC00B0052L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_TOO_MUCH_ALARM_DATA */
/*  */
/*  MessageText: */
/*  */
/*   The packet contains to much alarm data. */
/*  */
#define TLR_E_PNIO_CMDEV_TOO_MUCH_ALARM_DATA ((TLR_RESULT)0xC00B0053L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_RPC_CONNECT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The Connect-Response of IO-Device contained an error code; a connection could not be established. */
/*  */
#define TLR_E_PNIO_CMDEV_RPC_CONNECT_FAILED ((TLR_RESULT)0xC00B0060L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_RPC_WRITE_PARAM_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The Write_Param-Response of IO-Device contained an error code; a connection could not be established. */
/*  */
#define TLR_E_PNIO_CMDEV_RPC_WRITE_PARAM_FAILED ((TLR_RESULT)0xC00B0061L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_RPC_WRITE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The Write-Response of IO-Device contained an error code. */
/*  */
#define TLR_E_PNIO_CMDEV_RPC_WRITE_FAILED ((TLR_RESULT)0xC00B0062L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_RPC_READ_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The Read-Response of IO-Device contained an error code. */
/*  */
#define TLR_E_PNIO_CMDEV_RPC_READ_FAILED ((TLR_RESULT)0xC00B0063L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_TCP_IP_SHUTDOWN */
/*  */
/*  MessageText: */
/*  */
/*   The TCP/IP-Stack closed a socket needed for communication. */
/*  */
#define TLR_E_PNIO_CMDEV_TCP_IP_SHUTDOWN ((TLR_RESULT)0xC00B0064L)

/*  CMDEV AR */
/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_AR_BLOCKTYPE */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for AR in CMDEV_RMConnect_req_LoadAr() is missing. */
/*  */
#define TLR_E_PNIO_CMDEV_AR_BLOCKTYPE    ((TLR_RESULT)0xC00B0070L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_AR_BLOCKLEN */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for AR in CMDEV_RMConnect_req_LoadAr() has an invalid length. */
/*  */
#define TLR_E_PNIO_CMDEV_AR_BLOCKLEN     ((TLR_RESULT)0xC00B0071L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_AR_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   The configuration block for AR in CMDEV_RMConnect_req_LoadAr() has an invalid type. */
/*  */
#define TLR_E_PNIO_CMDEV_AR_TYPE         ((TLR_RESULT)0xC00B0072L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_AR_UUID */
/*  */
/*  MessageText: */
/*  */
/*   The configuration block for AR in CMDEV_RMConnect_req_LoadAr() has an invalid UUID. */
/*  */
#define TLR_E_PNIO_CMDEV_AR_UUID         ((TLR_RESULT)0xC00B0073L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_AR_PROPERTY */
/*  */
/*  MessageText: */
/*  */
/*   The configuration block for AR in CMDEV_RMConnect_req_LoadAr() has an invalid network properties value. */
/*  */
#define TLR_E_PNIO_CMDEV_AR_PROPERTY     ((TLR_RESULT)0xC00B0074L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_AR_REF_UNEXPECTED */
/*  */
/*  MessageText: */
/*  */
/*   The AR-Reference for CMDEV protocol-machine is invalid. */
/*  */
#define TLR_E_PNIO_CMDEV_AR_REF_UNEXPECTED ((TLR_RESULT)0xC00B0075L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_AR_UUID_COMP_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The UUID inside IO-Device's Connect-Confirmation is incorrect. */
/*  */
#define TLR_E_PNIO_CMDEV_AR_UUID_COMP_FAILED ((TLR_RESULT)0xC00B0076L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_AR_KEY_COMP_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The session-key inside IO-Device's Connect-Confirmation is incorrect. */
/*  */
#define TLR_E_PNIO_CMDEV_AR_KEY_COMP_FAILED ((TLR_RESULT)0xC00B0077L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_AR_MAC_COMP_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The MAC-address of IO-Device is incorrect. */
/*  */
#define TLR_E_PNIO_CMDEV_AR_MAC_COMP_FAILED ((TLR_RESULT)0xC00B0078L)

/*  CMDEV adressing related problems */
/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_INSERT_MODULE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_INSERT_MODULE_ERROR ((TLR_RESULT)0xC00B0080L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_INSERT_SUBMODULE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_INSERT_SUBMODULE_ERROR ((TLR_RESULT)0xC00B0081L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_MAX_API_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_MAX_API_LIMIT_EXCEEDED ((TLR_RESULT)0xC00B0082L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_API_ALREADY_ADDED */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_API_ALREADY_ADDED ((TLR_RESULT)0xC00B0083L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_SLOT_OUT_OF_RANGE */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_SLOT_OUT_OF_RANGE ((TLR_RESULT)0xC00B0084L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_SUBSLOT_OUT_OF_RANGE */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_SUBSLOT_OUT_OF_RANGE ((TLR_RESULT)0xC00B0085L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_SUBSLOT_ALREADY_EXISTS */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_SUBSLOT_ALREADY_EXISTS ((TLR_RESULT)0xC00B0086L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_PACKET_WRONG_API */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_PACKET_WRONG_API ((TLR_RESULT)0xC00B0087L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_PACKET_WRONG_SLOT */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_PACKET_WRONG_SLOT ((TLR_RESULT)0xC00B0088L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_PACKET_WRONG_SUBSLOT */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_PACKET_WRONG_SUBSLOT ((TLR_RESULT)0xC00B0089L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_SLOT_ENTRY_NOT_FOUND */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_SLOT_ENTRY_NOT_FOUND ((TLR_RESULT)0xC00B008AL)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_SLOT_ALREADY_EXISTS */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_SLOT_ALREADY_EXISTS ((TLR_RESULT)0xC00B008BL)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_SUBSLOT_ENTRY_NOT_FOUND */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_SUBSLOT_ENTRY_NOT_FOUND ((TLR_RESULT)0xC00B008CL)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_FILTERED */
/*  */
/*  MessageText: */
/*  */
/*   A CheckIndication shall not be forwarded to the user according to configuration. */
/*  */
#define TLR_E_PNIO_CMDEV_FILTERED        ((TLR_RESULT)0xC00B008DL)

/*  CMDEV IOCR */
/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_IOCR_BLOCKLEN */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for IOCR in CMDEV_RMConnect_req_LoadIocr() has an invalid length. */
/*  */
#define TLR_E_PNIO_CMDEV_IOCR_BLOCKLEN   ((TLR_RESULT)0xC00B0090L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_IOCR_TYPE_UNSUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   The type of IOCR is unsupported. */
/*  */
#define TLR_E_PNIO_CMDEV_IOCR_TYPE_UNSUPPORTED ((TLR_RESULT)0xC00B0091L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_IOCR_TYPE_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   The type of IOCR is unknown. */
/*  */
#define TLR_E_PNIO_CMDEV_IOCR_TYPE_UNKNOWN ((TLR_RESULT)0xC00B0092L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_IOCR_RTCCLASS_UNSUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   The RTC-class is unsupported. */
/*  */
#define TLR_E_PNIO_CMDEV_IOCR_RTCCLASS_UNSUPPORTED ((TLR_RESULT)0xC00B0093L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_IOCR_RTCCLASS_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   The RTC-class is unknown. */
/*  */
#define TLR_E_PNIO_CMDEV_IOCR_RTCCLASS_UNKNOWN ((TLR_RESULT)0xC00B0094L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_IOCR_IFTYPE_UNSUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for IOCR in CMDEV_RMConnect_req_LoadIocr() has an unsupported interface-type. */
/*  */
#define TLR_E_PNIO_CMDEV_IOCR_IFTYPE_UNSUPPORTED ((TLR_RESULT)0xC00B0095L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_IOCR_SCSYNC_UNSUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for IOCR in CMDEV_RMConnect_req_LoadIocr() has an unsupported value for SendClock. */
/*  */
#define TLR_E_PNIO_CMDEV_IOCR_SCSYNC_UNSUPPORTED ((TLR_RESULT)0xC00B0096L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_IOCR_ADDRESS_UNSUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for IOCR in CMDEV_RMConnect_req_LoadIocr() has an unsupported Address-Resolution. */
/*  */
#define TLR_E_PNIO_CMDEV_IOCR_ADDRESS_UNSUPPORTED ((TLR_RESULT)0xC00B0097L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_IOCR_REDUNDANCY_UNSUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for IOCR in CMDEV_RMConnect_req_LoadIocr() has an unsupported Media-Redundancy. */
/*  */
#define TLR_E_PNIO_CMDEV_IOCR_REDUNDANCY_UNSUPPORTED ((TLR_RESULT)0xC00B0098L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_IOCR_REFERENCE */
/*  */
/*  MessageText: */
/*  */
/*   No IOCR could be found or created. */
/*  */
#define TLR_E_PNIO_CMDEV_IOCR_REFERENCE  ((TLR_RESULT)0xC00B0099L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_IOCR_OBJECT_IOD */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for IOCR in CMDEV_RMConnect_req_LoadIocr() does not contain any IO-Data. */
/*  */
#define TLR_E_PNIO_CMDEV_IOCR_OBJECT_IOD ((TLR_RESULT)0xC00B009AL)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_IOCR_OBJECT_IOS */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for IOCR in CMDEV_RMConnect_req_LoadIocr() does not contain any IO-Status. */
/*  */
#define TLR_E_PNIO_CMDEV_IOCR_OBJECT_IOS ((TLR_RESULT)0xC00B009BL)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_IOCR_API */
/*  */
/*  MessageText: */
/*  */
/*   The expected configuration block for IOCR in CMDEV_RMConnect_req_LoadIocr() does not contain any API. */
/*  */
#define TLR_E_PNIO_CMDEV_IOCR_API        ((TLR_RESULT)0xC00B009CL)

/*  CMDEV parameter faults */
/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_FRAME_ID_COUNT_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_FRAME_ID_COUNT_INVALID ((TLR_RESULT)0xC00B0100L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_FRAME_ID_OUT_OF_RANGE */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_FRAME_ID_OUT_OF_RANGE ((TLR_RESULT)0xC00B0101L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_RT_CLASS_NOT_SUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_RT_CLASS_NOT_SUPPORTED ((TLR_RESULT)0xC00B0102L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_INSERT_AR_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_INSERT_AR_ERROR ((TLR_RESULT)0xC00B0103L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_MAX_AR_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_MAX_AR_LIMIT_EXCEEDED ((TLR_RESULT)0xC00B0104L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_AR_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_AR_INVALID      ((TLR_RESULT)0xC00B0105L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_IOCR_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_IOCR_INVALID    ((TLR_RESULT)0xC00B0106L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_TYPE_LEN_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_TYPE_LEN_INVALID ((TLR_RESULT)0xC00B0107L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_INVALID_CTRL_REQUEST_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_INVALID_CTRL_REQUEST_BLOCK ((TLR_RESULT)0xC00B0108L)

/*  */
/*  MessageId: TLR_E_PNIO_CMDEV_MODULECONFIG_PACKET_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_CMDEV_MODULECONFIG_PACKET_INVALID ((TLR_RESULT)0xC00B0109L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  EDD Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PNIO_EDD_PROCESS_END */
/*  */
/*  MessageText: */
/*  */
/*   Return value of EDD_Scheduler_PreProcess(). */
/*  */
#define TLR_E_PNIO_EDD_PROCESS_END       ((TLR_RESULT)0xC00E0001L)

/*  */
/*  MessageId: TLR_E_PNIO_EDD_PARAM_INVALID_EDD */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for EDD_Scheduler_Start_req(). */
/*  */
#define TLR_E_PNIO_EDD_PARAM_INVALID_EDD ((TLR_RESULT)0xC00E0002L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  ACP Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  ACP */
/*  */
/*  MessageId: TLR_E_PNIO_ACP_PHASE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory to initialize ACP-phase. */
/*  */
#define TLR_E_PNIO_ACP_PHASE_OUT_OF_MEMORY ((TLR_RESULT)0xC0110010L)

/*  */
/*  MessageId: TLR_E_PNIO_ACP_PHASE_REDUCTION_RATIO */
/*  */
/*  MessageText: */
/*  */
/*   Invalid reduction-ratio (uiMaxRatio) in ACP_PhaseInit(). */
/*  */
#define TLR_E_PNIO_ACP_PHASE_REDUCTION_RATIO ((TLR_RESULT)0xC0110011L)

/*  */
/*  MessageId: TLR_E_PNIO_ACP_PHASE_SEND_CLOCK_FACTOR */
/*  */
/*  MessageText: */
/*  */
/*   Invalid sendClock-factor (uiScFact) in ACP_PhaseInit(). */
/*  */
#define TLR_E_PNIO_ACP_PHASE_SEND_CLOCK_FACTOR ((TLR_RESULT)0xC0110012L)

/*  */
/*  MessageId: TLR_E_PNIO_ACP_PHASE_FRAME_RESOURCES */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter (uiMaxFrame) in ACP_PhaseInit(). */
/*  */
#define TLR_E_PNIO_ACP_PHASE_FRAME_RESOURCES ((TLR_RESULT)0xC0110013L)

/*  */
/*  MessageId: TLR_E_PNIO_ACP_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Error sending a packet to another task in ACP task. */
/*  */
#define TLR_E_PNIO_ACP_PACKET_SEND_FAILED ((TLR_RESULT)0xC0110014L)

/*  */
/*  MessageId: TLR_E_PNIO_ACP_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory in ACP task. */
/*  */
#define TLR_E_PNIO_ACP_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0110015L)

/*  */
/*  MessageId: TLR_E_PNIO_ACP_DRV_EDD_IOCTL_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_ACP_DRV_EDD_IOCTL_ERROR ((TLR_RESULT)0xC0110016L)

/*  */
/*  MessageId: TLR_E_PNIO_SYNC_LOAD_IRT_DATA_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_SYNC_LOAD_IRT_DATA_ERROR ((TLR_RESULT)0xC0110017L)

/*  */
/*  MessageId: TLR_E_PNIO_ACP_EMPTY_POOL_DETECTED */
/*  */
/*  MessageText: */
/*  */
/*   The packet pool of ACP is empty. */
/*  */
#define TLR_E_PNIO_ACP_EMPTY_POOL_DETECTED ((TLR_RESULT)0xC0110018L)

/*  ALARM */
/*  */
/*  MessageId: TLR_E_PNIO_ALARM_PARAM_INVALID_INIT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter "uiMaxAlpm" in Alarm_ResourceInit(). */
/*  */
#define TLR_E_PNIO_ALARM_PARAM_INVALID_INIT ((TLR_RESULT)0xC0110020L)

/*  */
/*  MessageId: TLR_E_PNIO_ALARM_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory in Alarm_ResourceInit(). */
/*  */
#define TLR_E_PNIO_ALARM_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0110021L)

/*  ALPMR */
/*  */
/*  MessageId: TLR_E_PNIO_ALPMR_PRIORITY_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid alarm priority in request packet of ALPMR_AlarmAck_req(). */
/*  */
#define TLR_E_PNIO_ALPMR_PRIORITY_INVALID ((TLR_RESULT)0xC0110030L)

/*  */
/*  MessageId: TLR_E_PNIO_ALPMR_RESOURCE_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   The requested number of ALPMR protocol machines exceedes the highest possible number in ALPMR_Init_req(). */
/*  */
#define TLR_E_PNIO_ALPMR_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110031L)

/*  */
/*  MessageId: TLR_E_PNIO_ALPMR_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory in ALPMR_Init_req(). */
/*  */
#define TLR_E_PNIO_ALPMR_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0110032L)

/*  */
/*  MessageId: TLR_E_PNIO_ALPMR_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The ALPMR protocol-machine corresponding to the index in request packet is invalid. */
/*  */
#define TLR_E_PNIO_ALPMR_HANDLE_INVALID  ((TLR_RESULT)0xC0110033L)

/*  */
/*  MessageId: TLR_E_PNIO_ALPMR_STATE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The ALPMR protocol-machine state is invalid for the current request. */
/*  */
#define TLR_E_PNIO_ALPMR_STATE_INVALID   ((TLR_RESULT)0xC0110034L)

/*  */
/*  MessageId: TLR_E_PNIO_ALPMR_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Sending an Alarm-Indication-packet to another task failed in ALPMR. */
/*  */
#define TLR_E_PNIO_ALPMR_PACKET_SEND_FAILED ((TLR_RESULT)0xC0110035L)

/*  */
/*  MessageId: TLR_E_PNIO_ALPMR_PACKET_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Creating an Alarm-Indication-packet to be send to another task failed due to insufficient memory. */
/*  */
#define TLR_E_PNIO_ALPMR_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC0110036L)

/*  */
/*  MessageId: TLR_E_PNIO_ALPMR_RESOURCE_INDEX_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The index of ALPMR's protocol machine is invalid. */
/*  */
#define TLR_E_PNIO_ALPMR_RESOURCE_INDEX_INVALID ((TLR_RESULT)0xC0110037L)

/*  APMR */
/*  */
/*  MessageId: TLR_E_PNIO_APMR_PARAM_INVALID_INIT */
/*  */
/*  MessageText: */
/*  */
/*   The parameter uiMaxApmr (maximum number of parallel APMR protocol-machines) in APMR_ResourceInit() is invalid. */
/*  */
#define TLR_E_PNIO_APMR_PARAM_INVALID_INIT ((TLR_RESULT)0xC0110040L)

/*  */
/*  MessageId: TLR_E_PNIO_APMR_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory in APMR_ResourceInit() to create the APMR protocol machines. */
/*  */
#define TLR_E_PNIO_APMR_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0110041L)

/*  */
/*  MessageId: TLR_E_PNIO_APMR_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The APMR protocol machine or its index is invalid. */
/*  */
#define TLR_E_PNIO_APMR_HANDLE_INVALID   ((TLR_RESULT)0xC0110042L)

/*  */
/*  MessageId: TLR_E_PNIO_APMR_STATE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The state of APMR protocol machine is invalid for current request. */
/*  */
#define TLR_E_PNIO_APMR_STATE_INVALID    ((TLR_RESULT)0xC0110043L)

/*  */
/*  MessageId: TLR_E_PNIO_APMR_FRAME_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Sending an ACK or NAK in response to a received Alarm-PDU failed. */
/*  */
#define TLR_E_PNIO_APMR_FRAME_SEND_FAILED ((TLR_RESULT)0xC0110044L)

/*  APMS */
/*  */
/*  MessageId: TLR_E_PNIO_APMS_PARAM_INVALID_INIT */
/*  */
/*  MessageText: */
/*  */
/*   The parameter uiMaxApms (maximum number of parallel APMS protocol-machines) in APMS_ResourceInit() is invalid. */
/*  */
#define TLR_E_PNIO_APMS_PARAM_INVALID_INIT ((TLR_RESULT)0xC0110050L)

/*  */
/*  MessageId: TLR_E_PNIO_APMS_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory in APMS_ResourceInit() to create the APMS protocol machines. */
/*  */
#define TLR_E_PNIO_APMS_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0110051L)

/*  */
/*  MessageId: TLR_E_PNIO_APMS_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The APMS protocol machine or its index is invalid. */
/*  */
#define TLR_E_PNIO_APMS_HANDLE_INVALID   ((TLR_RESULT)0xC0110052L)

/*  */
/*  MessageId: TLR_E_PNIO_APMS_STATE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The state of APMS protocol machine is invalid for current request. */
/*  */
#define TLR_E_PNIO_APMS_STATE_INVALID    ((TLR_RESULT)0xC0110053L)

/*  */
/*  MessageId: TLR_E_PNIO_APMS_FRAME_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   APMS was not able to get an Edd_FrameBuffer for sending a packet. */
/*  */
#define TLR_E_PNIO_APMS_FRAME_OUT_OF_MEMORY ((TLR_RESULT)0xC0110054L)

/*  */
/*  MessageId: TLR_E_PNIO_APMS_FRAME_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   An error occurred while APMS was trying to send an Edd_Frame. */
/*  */
#define TLR_E_PNIO_APMS_FRAME_SEND_FAILED ((TLR_RESULT)0xC0110055L)

/*  */
/*  MessageId: TLR_E_PNIO_APMS_TIMER_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   APMS_Activate_req() was not able to create a TLR-Timer. */
/*  */
#define TLR_E_PNIO_APMS_TIMER_CREATE_FAILED ((TLR_RESULT)0xC0110056L)

/*  */
/*  MessageId: TLR_E_PNIO_APMS_TIMER_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory for APMS_Send_req_Data() to allocate a timer-indication packet. */
/*  */
#define TLR_E_PNIO_APMS_TIMER_OUT_OF_MEMORY ((TLR_RESULT)0xC0110057L)

/*  */
/*  MessageId: TLR_E_PNIO_APMS_INDEX_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_APMS_INDEX_INVALID    ((TLR_RESULT)0xC0110058L)

/*  CPM */
/*  */
/*  MessageId: TLR_E_PNIO_CPM_PARAM_INVALID_INIT */
/*  */
/*  MessageText: */
/*  */
/*   The parameter uiMaxCpmRtc1 and/or uiMaxCpmRtc2 of CPM_ResourceInit() is invalid. */
/*  */
#define TLR_E_PNIO_CPM_PARAM_INVALID_INIT ((TLR_RESULT)0xC0110060L)

/*  */
/*  MessageId: TLR_E_PNIO_CPM_PARAM_INVALID_CLASS */
/*  */
/*  MessageText: */
/*  */
/*   The requested RTC-class is invalid in CPM_Init_req(). */
/*  */
#define TLR_E_PNIO_CPM_PARAM_INVALID_CLASS ((TLR_RESULT)0xC0110061L)

/*  */
/*  MessageId: TLR_E_PNIO_CPM_RESOURCE_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   The requested amount of CPM protocol machines is higher than the highest possible value. */
/*  */
#define TLR_E_PNIO_CPM_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110062L)

/*  */
/*  MessageId: TLR_E_PNIO_CPM_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory for current request in CPM. */
/*  */
#define TLR_E_PNIO_CPM_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0110063L)

/*  */
/*  MessageId: TLR_E_PNIO_CPM_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The handle to CPM protocol machine in invalid. */
/*  */
#define TLR_E_PNIO_CPM_HANDLE_INVALID    ((TLR_RESULT)0xC0110064L)

/*  */
/*  MessageId: TLR_E_PNIO_CPM_STATE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The state of CPM protocol machine is incorrect for current request. */
/*  */
#define TLR_E_PNIO_CPM_STATE_INVALID     ((TLR_RESULT)0xC0110065L)

/*  */
/*  MessageId: TLR_E_PNIO_CPM_PHASE_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   Invalid phase found in Init-request-packet in CPM_Init_req() or in ACP_PhaseCpmAdd_req() or ACP_PhaseCpmRemove_req(). */
/*  */
#define TLR_E_PNIO_CPM_PHASE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110066L)

/*  */
/*  MessageId: TLR_E_PNIO_CPM_SEND_CLOCK_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   The SendClock-factor in Init-request-packet to CPM does not match the one in ACP_Tasks' resources. */
/*  */
#define TLR_E_PNIO_CPM_SEND_CLOCK_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110067L)

/*  */
/*  MessageId: TLR_E_PNIO_CPM_DATALEN_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   Packet size to receive is to big. Error is detected in CPM_Init_req(). */
/*  */
#define TLR_E_PNIO_CPM_DATALEN_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110069L)

/*  */
/*  MessageId: TLR_E_PNIO_CPM_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Error while sending a packet to another task in CPM. */
/*  */
#define TLR_E_PNIO_CPM_PACKET_SEND_FAILED ((TLR_RESULT)0xC011006AL)

/*  PPM */
/*  */
/*  MessageId: TLR_E_PNIO_PPM_PARAM_INVALID_INIT */
/*  */
/*  MessageText: */
/*  */
/*   The parameter "uiMaxPPMRtc1" and/or "uiMaxPPMRtc2" of PPM_ResourceInit() is invalid. */
/*  */
#define TLR_E_PNIO_PPM_PARAM_INVALID_INIT ((TLR_RESULT)0xC0110080L)

/*  */
/*  MessageId: TLR_E_PNIO_PPM_PARAM_INVALID_CLASS */
/*  */
/*  MessageText: */
/*  */
/*   The requested RTC-class is invalid in PPM_Init_req(). */
/*  */
#define TLR_E_PNIO_PPM_PARAM_INVALID_CLASS ((TLR_RESULT)0xC0110081L)

/*  */
/*  MessageId: TLR_E_PNIO_PPM_RESOURCE_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   The requested amount of PPM protocol machines is higher than the highest possible value. */
/*  */
#define TLR_E_PNIO_PPM_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110082L)

/*  */
/*  MessageId: TLR_E_PNIO_PPM_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory for current request in PPM. */
/*  */
#define TLR_E_PNIO_PPM_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0110083L)

/*  */
/*  MessageId: TLR_E_PNIO_PPM_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The handle to PPM protocol machine in invalid. */
/*  */
#define TLR_E_PNIO_PPM_HANDLE_INVALID    ((TLR_RESULT)0xC0110084L)

/*  */
/*  MessageId: TLR_E_PNIO_PPM_STATE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The state of PPM protocol machine is incorrect for current request. */
/*  */
#define TLR_E_PNIO_PPM_STATE_INVALID     ((TLR_RESULT)0xC0110085L)

/*  */
/*  MessageId: TLR_E_PNIO_PPM_PHASE_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   Invalid phase found in Init-request-packet in PPM_Init_req() or in ACP_PhasePPMAdd_req() or ACP_PhasePPMRemove_req(). */
/*  */
#define TLR_E_PNIO_PPM_PHASE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110086L)

/*  */
/*  MessageId: TLR_E_PNIO_PPM_SEND_CLOCK_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   The SendClock-factor in PPMs Init-request-packet does not match the one in ACP_Tasks' resources. */
/*  */
#define TLR_E_PNIO_PPM_SEND_CLOCK_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110087L)

/*  */
/*  MessageId: TLR_E_PNIO_PPM_DATALEN_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   Packet size to send is to big. Error is detected in PPM_Init_req(). */
/*  */
#define TLR_E_PNIO_PPM_DATALEN_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110089L)

/*  */
/*  MessageId: TLR_E_PNIO_PPM_RESOURCE_CLASS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_PPM_RESOURCE_CLASS_INVALID ((TLR_RESULT)0xC011008AL)

/*  ALPMI */
/*  */
/*  MessageId: TLR_E_PNIO_ALPMI_PRIORITY_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid alarm priority in request packet of ALPMI_AlarmAck_req(). */
/*  */
#define TLR_E_PNIO_ALPMI_PRIORITY_INVALID ((TLR_RESULT)0xC0110090L)

/*  */
/*  MessageId: TLR_E_PNIO_ALPMI_RESOURCE_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   The requested number of ALPMI protocol machines exceedes the highest possible number in ALPMI_Init_req(). */
/*  */
#define TLR_E_PNIO_ALPMI_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110091L)

/*  */
/*  MessageId: TLR_E_PNIO_ALPMI_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory in ALPMI_Init_req(). */
/*  */
#define TLR_E_PNIO_ALPMI_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0110092L)

/*  */
/*  MessageId: TLR_E_PNIO_ALPMI_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The ALPMI protocol-machine corresponding to the index in request packet is invalid. */
/*  */
#define TLR_E_PNIO_ALPMI_HANDLE_INVALID  ((TLR_RESULT)0xC0110093L)

/*  */
/*  MessageId: TLR_E_PNIO_ALPMI_STATE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The ALPMI protocol-machine state is invalid for the current request. */
/*  */
#define TLR_E_PNIO_ALPMI_STATE_INVALID   ((TLR_RESULT)0xC0110094L)

/*  */
/*  MessageId: TLR_E_PNIO_ALPMI_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Sending an Alarm-Indication-packet to another task failed in ALPMI. */
/*  */
#define TLR_E_PNIO_ALPMI_PACKET_SEND_FAILED ((TLR_RESULT)0xC0110095L)

/*  */
/*  MessageId: TLR_E_PNIO_ALPMI_PACKET_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Creating an Alarm-Indication-packet to be send to another task failed due to insufficient memory. */
/*  */
#define TLR_E_PNIO_ALPMI_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC0110096L)

/*  */
/*  MessageId: TLR_E_PNIO_ALPMI_RESOURCE_INDEX_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The index of ALPIR's protocol machine is invalid. */
/*  */
#define TLR_E_PNIO_ALPMI_RESOURCE_INDEX_INVALID ((TLR_RESULT)0xC0110097L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  DCP Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  DCP */
/*  */
/*  MessageId: TLR_E_PNIO_DCP_PARAM_INVALID_EDD */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter in Start-Edd-packet for DCP_StartEDD_req(). */
/*  */
#define TLR_E_PNIO_DCP_PARAM_INVALID_EDD ((TLR_RESULT)0xC012000AL)

/*  DCPMCR */
/*  */
/*  MessageId: TLR_E_PNIO_DCPMCR_INIT_PARAM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter (uiMaxMcr) in DCPMCR_ResourceInit(). */
/*  */
#define TLR_E_PNIO_DCPMCR_INIT_PARAM_INVALID ((TLR_RESULT)0xC0120010L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCR_INIT_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory to initialize DCPMCR protocol machines in DCPMCR_ResourceInit(). */
/*  */
#define TLR_E_PNIO_DCPMCR_INIT_OUT_OF_MEMORY ((TLR_RESULT)0xC0120011L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCR_RESOURCE_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   The index of DCPMCR's protocol machine is invalid. */
/*  */
#define TLR_E_PNIO_DCPMCR_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0120012L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCR_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory for request in DCPMCR_Activate_req(). */
/*  */
#define TLR_E_PNIO_DCPMCR_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0120013L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCR_RESOURCE_STATE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The state of DCPMCR protocol machine is incorrect for current request. */
/*  */
#define TLR_E_PNIO_DCPMCR_RESOURCE_STATE_INVALID ((TLR_RESULT)0xC0120014L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCR_RESOURCE_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The handle to DCPMCR protocol machine in invalid. */
/*  */
#define TLR_E_PNIO_DCPMCR_RESOURCE_HANDLE_INVALID ((TLR_RESULT)0xC0120015L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCR_TIMER_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   DCPMCR_Activate_req() was unable to create a TLR-timer. */
/*  */
#define TLR_E_PNIO_DCPMCR_TIMER_CREATE_FAILED ((TLR_RESULT)0xC0120016L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCR_TIMER_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory for DCPMCR_Identify_ind() to allocate a timer-indication packet. */
/*  */
#define TLR_E_PNIO_DCPMCR_TIMER_OUT_OF_MEMORY ((TLR_RESULT)0xC0120017L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCR_PACKET_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory to allocate a packet to be send to another task in DCPMCR. */
/*  */
#define TLR_E_PNIO_DCPMCR_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC0120018L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCR_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Error while sending a packet to another task in DCPMCR. */
/*  */
#define TLR_E_PNIO_DCPMCR_PACKET_SEND_FAILED ((TLR_RESULT)0xC0120019L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCR_FRAME_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   DCPMCR was not able to get an Edd_FrameBuffer for sending a packet. */
/*  */
#define TLR_E_PNIO_DCPMCR_FRAME_OUT_OF_MEMORY ((TLR_RESULT)0xC012001AL)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCR_FRAME_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   An error occurred while DCPMCR was trying to send an Edd_Frame. */
/*  */
#define TLR_E_PNIO_DCPMCR_FRAME_SEND_FAILED ((TLR_RESULT)0xC012001BL)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCR_WAIT_ACK */
/*  */
/*  MessageText: */
/*  */
/*   DCPMCR could not be closed because it is still waiting for an ACK. */
/*  */
#define TLR_E_PNIO_DCPMCR_WAIT_ACK       ((TLR_RESULT)0xC012001CL)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCR_TASK_RES_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   DCPMCR: Invalid parameter (task resources block address) while handling DCP Identify indication. */
/*  */
#define TLR_E_PNIO_DCPMCR_TASK_RES_ADDRESS ((TLR_RESULT)0xC012001DL)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCR_EDD_FRAME_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   DCPMCR: Invalid parameter (EDD frame address) while handling DCP Identify indication. */
/*  */
#define TLR_E_PNIO_DCPMCR_EDD_FRAME_ADDRESS ((TLR_RESULT)0xC012001EL)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCR_MCR_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   DCPMCR: Invalid parameter (DCPMCR state machine address) while handling DCP Identify indication. */
/*  */
#define TLR_E_PNIO_DCPMCR_MCR_ADDRESS    ((TLR_RESULT)0xC012001FL)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCR_RMPM_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   DCPMCR: Invalid parameter (RMPM state machine address) while handling DCP Identify indication. */
/*  */
#define TLR_E_PNIO_DCPMCR_RMPM_ADDRESS   ((TLR_RESULT)0xC0120020L)

/*  */
/*  MessageId: TLR_E_PNIO_DCP_EMPTY_POOL_DETECTED */
/*  */
/*  MessageText: */
/*  */
/*   The packet pool of DCP is empty. */
/*  */
#define TLR_E_PNIO_DCP_EMPTY_POOL_DETECTED ((TLR_RESULT)0xC0120021L)

/*  DCPMCS */
/*  */
/*  MessageId: TLR_E_PNIO_DCPMCS_INIT_PARAM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter (uiMaxMcs) in DCPMCS_ResourceInit(). */
/*  */
#define TLR_E_PNIO_DCPMCS_INIT_PARAM_INVALID ((TLR_RESULT)0xC0120100L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCS_INIT_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory to initialize DCPMCS protocol machines in DCPMCS_ResourceInit(). */
/*  */
#define TLR_E_PNIO_DCPMCS_INIT_OUT_OF_MEMORY ((TLR_RESULT)0xC0120101L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCS_RESOURCE_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   There are too many outstanding DCPMCS requests. New requests will not be accepted. */
/*  */
#define TLR_E_PNIO_DCPMCS_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0120102L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCS_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory for request in DCPMCS_Activate_req(). */
/*  */
#define TLR_E_PNIO_DCPMCS_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0120103L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCS_RESOURCE_STATE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The state of DCPMCS protocol machine is incorrect for current request. */
/*  */
#define TLR_E_PNIO_DCPMCS_RESOURCE_STATE_INVALID ((TLR_RESULT)0xC0120104L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCS_RESOURCE_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The handle to DCPMCS protocol machine in invalid. */
/*  */
#define TLR_E_PNIO_DCPMCS_RESOURCE_HANDLE_INVALID ((TLR_RESULT)0xC0120105L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCS_TIMER_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   DCPMCS_Activate_req() was unable to create a TLR-timer. */
/*  */
#define TLR_E_PNIO_DCPMCS_TIMER_CREATE_FAILED ((TLR_RESULT)0xC0120106L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCS_TIMER_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory for DCPMCS_Identify_req() to allocate a timer-indication packet. */
/*  */
#define TLR_E_PNIO_DCPMCS_TIMER_OUT_OF_MEMORY ((TLR_RESULT)0xC0120107L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCS_PACKET_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory to allocate a packet to be send to another task in DCPMCS. */
/*  */
#define TLR_E_PNIO_DCPMCS_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC0120108L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCS_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Error while sending a packet to another task in DCPMCS. */
/*  */
#define TLR_E_PNIO_DCPMCS_PACKET_SEND_FAILED ((TLR_RESULT)0xC0120109L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCS_FRAME_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   DCPMCS was not able to get an Edd_FrameBuffer for sending a packet. */
/*  */
#define TLR_E_PNIO_DCPMCS_FRAME_OUT_OF_MEMORY ((TLR_RESULT)0xC012010AL)

/*  */
/*  MessageId: TLR_E_PNIO_DCPMCS_FRAME_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   An error occurred while DCPMCS was trying to send an Edd_Frame. */
/*  */
#define TLR_E_PNIO_DCPMCS_FRAME_SEND_FAILED ((TLR_RESULT)0xC012010BL)

/*  DCPUCR  */
/*  */
/*  MessageId: TLR_E_PNIO_DCPUCR_INIT_PARAM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter (uiMaxUcr) in DCPUCR_ResourceInit(). */
/*  */
#define TLR_E_PNIO_DCPUCR_INIT_PARAM_INVALID ((TLR_RESULT)0xC0120200L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCR_INIT_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory to initialize DCPUCR protocol machines in DCPUCR_ResourceInit(). */
/*  */
#define TLR_E_PNIO_DCPUCR_INIT_OUT_OF_MEMORY ((TLR_RESULT)0xC0120201L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCR_RESOURCE_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   The index of DCPUCR's protocol machine is invalid. */
/*  */
#define TLR_E_PNIO_DCPUCR_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0120202L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCR_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory for request in DCPUCR_Activate_req(). */
/*  */
#define TLR_E_PNIO_DCPUCR_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0120203L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCR_RESOURCE_STATE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The state of DCPUCR protocol machine is incorrect for current request. */
/*  */
#define TLR_E_PNIO_DCPUCR_RESOURCE_STATE_INVALID ((TLR_RESULT)0xC0120204L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCR_RESOURCE_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The handle to DCPUCR protocol machine in invalid. */
/*  */
#define TLR_E_PNIO_DCPUCR_RESOURCE_HANDLE_INVALID ((TLR_RESULT)0xC0120205L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCR_TIMER_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   DCPUCR_Activate_req() was unable to create a TLR-timer. */
/*  */
#define TLR_E_PNIO_DCPUCR_TIMER_CREATE_FAILED ((TLR_RESULT)0xC0120206L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCR_TIMER_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory to allocate a timer-indication packet. */
/*  */
#define TLR_E_PNIO_DCPUCR_TIMER_OUT_OF_MEMORY ((TLR_RESULT)0xC0120207L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCR_PACKET_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory to allocate a packet to be send to another task in DCPUCR. */
/*  */
#define TLR_E_PNIO_DCPUCR_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC0120208L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCR_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Error while sending a packet to another task in DCPUCR. */
/*  */
#define TLR_E_PNIO_DCPUCR_PACKET_SEND_FAILED ((TLR_RESULT)0xC0120209L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCR_FRAME_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   DCPUCR was not able to get an Edd_FrameBuffer for sending a packet. */
/*  */
#define TLR_E_PNIO_DCPUCR_FRAME_OUT_OF_MEMORY ((TLR_RESULT)0xC012020AL)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCR_FRAME_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   An error occurred while DCPUCR was trying to send an Edd_Frame. */
/*  */
#define TLR_E_PNIO_DCPUCR_FRAME_SEND_FAILED ((TLR_RESULT)0xC012020BL)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCR_SERVICE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The DCP-command of received response does not match the outstanding request in DCPUCR. */
/*  */
#define TLR_E_PNIO_DCPUCR_SERVICE_INVALID ((TLR_RESULT)0xC012020CL)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCR_WAIT_ACK */
/*  */
/*  MessageText: */
/*  */
/*   DCPUCR could not be closed because it is still waiting for an ACK. */
/*  */
#define TLR_E_PNIO_DCPUCR_WAIT_ACK       ((TLR_RESULT)0xC012020DL)

/*  DCPUCS */
/*  */
/*  MessageId: TLR_E_PNIO_DCPUCS_INIT_PARAM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter (uiMaxUcs) in DCPUCS_ResourceInit(). */
/*  */
#define TLR_E_PNIO_DCPUCS_INIT_PARAM_INVALID ((TLR_RESULT)0xC0120300L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCS_INIT_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory to initialize DCPUCS protocol machines in DCPUCS_ResourceInit(). */
/*  */
#define TLR_E_PNIO_DCPUCS_INIT_OUT_OF_MEMORY ((TLR_RESULT)0xC0120301L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCS_RESOURCE_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   There are too many outstanding DCPUCS requests. New requests will not be accepted. */
/*  */
#define TLR_E_PNIO_DCPUCS_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0120302L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCS_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory for request in DCPUCS_Activate_req(). */
/*  */
#define TLR_E_PNIO_DCPUCS_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0120303L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCS_RESOURCE_STATE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The state of DCPUCS protocol machine is incorrect for current request. */
/*  */
#define TLR_E_PNIO_DCPUCS_RESOURCE_STATE_INVALID ((TLR_RESULT)0xC0120304L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCS_RESOURCE_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The handle to DCPUCS protocol machine in invalid. */
/*  */
#define TLR_E_PNIO_DCPUCS_RESOURCE_HANDLE_INVALID ((TLR_RESULT)0xC0120305L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCS_TIMER_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   DCPUCS_Activate_req() was unable to create a TLR-timer. */
/*  */
#define TLR_E_PNIO_DCPUCS_TIMER_CREATE_FAILED ((TLR_RESULT)0xC0120306L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCS_TIMER_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory for DCPUCS_DataSend_req() to allocate a timer-indication packet. */
/*  */
#define TLR_E_PNIO_DCPUCS_TIMER_OUT_OF_MEMORY ((TLR_RESULT)0xC0120307L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCS_PACKET_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory to allocate a packet to be send to another task in DCPUCS. */
/*  */
#define TLR_E_PNIO_DCPUCS_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC0120308L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCS_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Error while sending a packet to another task in DCPUCS. */
/*  */
#define TLR_E_PNIO_DCPUCS_PACKET_SEND_FAILED ((TLR_RESULT)0xC0120309L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCS_FRAME_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   DCPUCS was not able to get an Edd_FrameBuffer for sending a packet. */
/*  */
#define TLR_E_PNIO_DCPUCS_FRAME_OUT_OF_MEMORY ((TLR_RESULT)0xC012030AL)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCS_FRAME_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   An error occurred while DCPUCS was trying to send an Edd_Frame. */
/*  */
#define TLR_E_PNIO_DCPUCS_FRAME_SEND_FAILED ((TLR_RESULT)0xC012030BL)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCS_FRAME_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   DCPUCS did not get a response to an Edd_Frame send . */
/*  */
#define TLR_E_PNIO_DCPUCS_FRAME_TIMEOUT  ((TLR_RESULT)0xC012030CL)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCS_DCP_OPTION_UNSUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   The DCP option to set is not supported by IO-Device. */
/*  */
#define TLR_E_PNIO_DCPUCS_DCP_OPTION_UNSUPPORTED ((TLR_RESULT)0xC0120320L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCS_DCP_SUBOPTION_UNSUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   The DCP suboption to set is not supported by IO-Device. */
/*  */
#define TLR_E_PNIO_DCPUCS_DCP_SUBOPTION_UNSUPPORTED ((TLR_RESULT)0xC0120321L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCS_DCP_SUBOPTION_NOT_SET */
/*  */
/*  MessageText: */
/*  */
/*   The DCP suboption to set was not set inside IO-Device. */
/*  */
#define TLR_E_PNIO_DCPUCS_DCP_SUBOPTION_NOT_SET ((TLR_RESULT)0xC0120022L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCS_DCP_RESOURCE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   An internal resource error occured in IO-Device while performing a DCP request. */
/*  */
#define TLR_E_PNIO_DCPUCS_DCP_RESOURCE_ERROR ((TLR_RESULT)0xC0120023L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCS_DCP_SET_IMPOSSIBLE_LOCAL_REASON */
/*  */
/*  MessageText: */
/*  */
/*   The DCP (sub)option could not be set inside IO-Device for IO-Device internal reasons. */
/*  */
#define TLR_E_PNIO_DCPUCS_DCP_SET_IMPOSSIBLE_LOCAL_REASON ((TLR_RESULT)0xC0120024L)

/*  */
/*  MessageId: TLR_E_PNIO_DCPUCS_DCP_SET_IMPOSSIBLE_WHILE_OPERATION */
/*  */
/*  MessageText: */
/*  */
/*   The DCP (sub)option could not be set inside IO-Device because IO-Device is in operation. */
/*  */
#define TLR_E_PNIO_DCPUCS_DCP_SET_IMPOSSIBLE_WHILE_OPERATION ((TLR_RESULT)0xC0120025L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  MGT-Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  MGT */
/*  */
/*  MessageId: TLR_E_PNIO_MGT_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   ACP_EDDStartDCP_req() was unable to send request packet to DCP-Task. */
/*  */
#define TLR_E_PNIO_MGT_PACKET_SEND_FAILED ((TLR_RESULT)0xC0130001L)

/*  */
/*  MessageId: TLR_E_PNIO_MGT_WAIT_FOR_PACKET_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_MGT_WAIT_FOR_PACKET_FAILED ((TLR_RESULT)0xC0130002L)

/*  */
/*  MessageId: TLR_E_PNIO_MGT_CMDEV_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_MGT_CMDEV_HANDLE_INVALID ((TLR_RESULT)0xC0130003L)

/*  */
/*  MessageId: TLR_E_PNIO_MGT_MAPPER_REGISTER_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_MGT_MAPPER_REGISTER_ERROR ((TLR_RESULT)0xC0130004L)

/*  */
/*  MessageId: TLR_E_PNIO_MGT_SERVER_REGISTER_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_MGT_SERVER_REGISTER_ERROR ((TLR_RESULT)0xC0130005L)

/*  */
/*  MessageId: TLR_E_PNIO_MGT_OBJECT_REGISTER_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_MGT_OBJECT_REGISTER_ERROR ((TLR_RESULT)0xC0130006L)

/*  */
/*  MessageId: TLR_E_PNIO_MGT_CLIENT_REGISTER_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_MGT_CLIENT_REGISTER_ERROR ((TLR_RESULT)0xC0130007L)

/*  */
/*  MessageId: TLR_E_PNIO_MGT_OPCODE_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_MGT_OPCODE_UNKNOWN    ((TLR_RESULT)0xC0130008L)

/*  */
/*  MessageId: TLR_E_PNIO_MGT_RPCCLIENT_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_MGT_RPCCLIENT_HANDLE_INVALID ((TLR_RESULT)0xC0130009L)

/*  */
/*  MessageId: TLR_E_PNIO_MGT_OBJECT_UUID_NOT_FOUND */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_MGT_OBJECT_UUID_NOT_FOUND ((TLR_RESULT)0xC013000AL)

/*  */
/*  MessageId: TLR_E_PNIO_MGT_ARUUID_NOT_FOUND */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_MGT_ARUUID_NOT_FOUND  ((TLR_RESULT)0xC013000BL)

/*  */
/*  MessageId: TLR_E_PNIO_MGT_INVALID_PORT_NUMBER */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_MGT_INVALID_PORT_NUMBER ((TLR_RESULT)0xC013000CL)

/*  */
/*  MessageId: TLR_E_PNIO_MGT_DRV_EDD_IOCTL_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_MGT_DRV_EDD_IOCTL_ERROR ((TLR_RESULT)0xC013000DL)

/*  */
/*  MessageId: TLR_E_PNIO_MGT_INVALID_SESSION_KEY */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_MGT_INVALID_SESSION_KEY ((TLR_RESULT)0xC013000EL)

/*  */
/*  MessageId: TLR_E_PNIO_MGT_TARGET_UUID_NOT_NIL */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_MGT_TARGET_UUID_NOT_NIL ((TLR_RESULT)0xC013000FL)

/*  NRPM */
/*  */
/*  MessageId: TLR_E_PNIO_NRPM_PARAM_INVALID_INIT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter (uiMaxNrpm) in NRPM_ResourceInit(). */
/*  */
#define TLR_E_PNIO_NRPM_PARAM_INVALID_INIT ((TLR_RESULT)0xC0130010L)

/*  */
/*  MessageId: TLR_E_PNIO_NRPM_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The handle to NRPM protocol machine in invalid. */
/*  */
#define TLR_E_PNIO_NRPM_HANDLE_INVALID   ((TLR_RESULT)0xC0130011L)

/*  */
/*  MessageId: TLR_E_PNIO_NRPM_STATE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The state of NRPM protocol machine is invalid. */
/*  */
#define TLR_E_PNIO_NRPM_STATE_INVALID    ((TLR_RESULT)0xC0130012L)

/*  */
/*  MessageId: TLR_E_PNIO_NRPM_IDENTIFY_FLAG_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The identify-flag in NRPM_Init_req() is invalid. */
/*  */
#define TLR_E_PNIO_NRPM_IDENTIFY_FLAG_INVALID ((TLR_RESULT)0xC0130013L)

/*  */
/*  MessageId: TLR_E_PNIO_NRPM_RESOURCE_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   The requested number of NRPM protocol machines exceedes the highest possible number in NRPM_Init_req(). */
/*  */
#define TLR_E_PNIO_NRPM_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0130014L)

/*  */
/*  MessageId: TLR_E_PNIO_NRPM_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory in NRPM_Init_req(). */
/*  */
#define TLR_E_PNIO_NRPM_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0130015L)

/*  */
/*  MessageId: TLR_E_PNIO_NRPM_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Error while sending a packet to another task in NRPM. */
/*  */
#define TLR_E_PNIO_NRPM_PACKET_SEND_FAILED ((TLR_RESULT)0xC0130016L)

/*  */
/*  MessageId: TLR_E_PNIO_NRPM_PACKET_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory to allocate a packet in NRPM. */
/*  */
#define TLR_E_PNIO_NRPM_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC0130017L)

/*  */
/*  MessageId: TLR_E_PNIO_NRPM_DCP_TYPE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Received request with invalid type of DCP request in NRPM. */
/*  */
#define TLR_E_PNIO_NRPM_DCP_TYPE_INVALID ((TLR_RESULT)0xC0130018L)

/*  */
/*  MessageId: TLR_E_PNIO_NRPM_NAME_OF_STATION_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The requested NameOfStation is invalid. Either it has an invalid length or it contains invalid characters. */
/*  */
#define TLR_E_PNIO_NRPM_NAME_OF_STATION_INVALID ((TLR_RESULT)0xC0130019L)

/*  */
/*  MessageId: TLR_E_PNIO_NRPM_DCP_SET_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   The requested DCP Set operation failed. */
/*  */
#define TLR_E_PNIO_NRPM_DCP_SET_ERROR    ((TLR_RESULT)0xC013001AL)

/*  */
/*  MessageId: TLR_E_PNIO_NRPM_DEVICE_IP_ADDRESS_ALREADY_IN_USE */
/*  */
/*  MessageText: */
/*  */
/*   The IP-address the controller shall set for the IO-Device is already in use by another network device. */
/*  */
#define TLR_E_PNIO_NRPM_DEVICE_IP_ADDRESS_ALREADY_IN_USE ((TLR_RESULT)0xC013001BL)

/*  */
/*  MessageId: TLR_E_PNIO_MGT_EMPTY_POOL_DETECTED */
/*  */
/*  MessageText: */
/*  */
/*   The packet pool of MGT is empty. */
/*  */
#define TLR_E_PNIO_MGT_EMPTY_POOL_DETECTED ((TLR_RESULT)0xC01300F0L)

/*  */
/*  MessageId: TLR_E_PNIO_MGT_INVALID_DEV_INDEX */
/*  */
/*  MessageText: */
/*  */
/*   The index of the device is invalid. */
/*  */
#define TLR_E_PNIO_MGT_INVALID_DEV_INDEX ((TLR_RESULT)0xC01300F1L)

/*  RMPM */
/*  */
/*  MessageId: TLR_E_PNIO_RMPM_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The handle to RMPM is invalid. */
/*  */
#define TLR_E_PNIO_RMPM_HANDLE_INVALID   ((TLR_RESULT)0xC0130101L)

/*  */
/*  MessageId: TLR_E_PNIO_RMPM_STATE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The state of RMPM is invalid for current request. */
/*  */
#define TLR_E_PNIO_RMPM_STATE_INVALID    ((TLR_RESULT)0xC0130102L)

/*  */
/*  MessageId: TLR_E_PNIO_RMPM_STATE_CLOSING */
/*  */
/*  MessageText: */
/*  */
/*   The state of RMPM is closed */
/*  */
#define TLR_E_PNIO_RMPM_STATE_CLOSING    ((TLR_RESULT)0xC0130103L)

/*  */
/*  MessageId: TLR_E_PNIO_RMPM_RESOURCE_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   The number of RMPM state-machines is to high. */
/*  */
#define TLR_E_PNIO_RMPM_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0130104L)

/*  */
/*  MessageId: TLR_E_PNIO_RMPM_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory to fullfill the current request in RMPM. */
/*  */
#define TLR_E_PNIO_RMPM_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0130105L)

/*  */
/*  MessageId: TLR_E_PNIO_RMPM_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Error while sending a packet to another task in RMPM. */
/*  */
#define TLR_E_PNIO_RMPM_PACKET_SEND_FAILED ((TLR_RESULT)0xC0130106L)

/*  */
/*  MessageId: TLR_E_PNIO_RMPM_PACKET_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory to allocate a packet in RMPM. */
/*  */
#define TLR_E_PNIO_RMPM_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC0130107L)

/*  */
/*  MessageId: TLR_E_PNIO_RMPM_ROLE_UNSUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   The parameter "role" is unsupported in RMPM_Init_req_ParameterRole() . */
/*  */
#define TLR_E_PNIO_RMPM_ROLE_UNSUPPORTED ((TLR_RESULT)0xC0130108L)

/*  */
/*  MessageId: TLR_E_PNIO_RMPM_ROLE_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   The parameter "role" is unknown in RMPM_Init_req_ParameterRole() . */
/*  */
#define TLR_E_PNIO_RMPM_ROLE_UNKNOWN     ((TLR_RESULT)0xC0130109L)

/*  */
/*  MessageId: TLR_E_PNIO_RMPM_ROLE_IN_USE */
/*  */
/*  MessageText: */
/*  */
/*   The parameter "role" is already in use in RMPM_Init_req_ParameterRole() . */
/*  */
#define TLR_E_PNIO_RMPM_ROLE_IN_USE      ((TLR_RESULT)0xC013010AL)

/*  */
/*  MessageId: TLR_E_PNIO_RMPM_CONFIG_SEQUENCE */
/*  */
/*  MessageText: */
/*  */
/*   Incorrect sequence of configuration in RMPM_ConfigSet_req(). */
/*  */
#define TLR_E_PNIO_RMPM_CONFIG_SEQUENCE  ((TLR_RESULT)0xC013010BL)

/*  */
/*  MessageId: TLR_E_PNIO_RMPM_CONFIG_INVALID_VENDOR_ID */
/*  */
/*  MessageText: */
/*  */
/*   Incorrect configuration of Vendor-ID in RMPM_ConfigSet_req(). */
/*  */
#define TLR_E_PNIO_RMPM_CONFIG_INVALID_VENDOR_ID ((TLR_RESULT)0xC013010CL)

/*  */
/*  MessageId: TLR_E_PNIO_RMPM_CONFIG_INVALID_NAME */
/*  */
/*  MessageText: */
/*  */
/*   Incorrect name of station in RMPM_ConfigSet_req(). */
/*  */
#define TLR_E_PNIO_RMPM_CONFIG_INVALID_NAME ((TLR_RESULT)0xC013010DL)

/*  */
/*  MessageId: TLR_E_PNIO_RMPM_CONFIG_INVALID_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Incorrect name of type in RMPM_ConfigSet_req(). */
/*  */
#define TLR_E_PNIO_RMPM_CONFIG_INVALID_TYPE ((TLR_RESULT)0xC013010EL)

/*  */
/*  MessageId: TLR_E_PNIO_RMPM_DUPLICATE_NAME_OF_STATION */
/*  */
/*  MessageText: */
/*  */
/*   The NameOfStation of IO-Controller is in use by another network device. */
/*  */
#define TLR_E_PNIO_RMPM_DUPLICATE_NAME_OF_STATION ((TLR_RESULT)0xC0130110L)

/*  */
/*  MessageId: TLR_E_PNIO_RMPM_DUPLICATE_IP */
/*  */
/*  MessageText: */
/*  */
/*   The IP-address the IO-Controller shall use is in use by another network device. */
/*  */
#define TLR_E_PNIO_RMPM_DUPLICATE_IP     ((TLR_RESULT)0xC0130111L)

/*  */
/*  MessageId: TLR_E_PNIO_RMPM_RPC_PACKET_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The packet length of an RPC-packet received is invalid (most likely too short). */
/*  */
#define TLR_E_PNIO_RMPM_RPC_PACKET_INVALID ((TLR_RESULT)0xC0130112L)

/*  */
/*  MessageId: TLR_E_PNIO_RMPM_DCP_PACKET_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The packet length of an DCP-packet received is invalid (most likely too short). */
/*  */
#define TLR_E_PNIO_RMPM_DCP_PACKET_INVALID ((TLR_RESULT)0xC0130113L)

/*  IO-Device error codes */
/*  */
/*  MessageId: TLR_E_PNIO_RMPM_INVALID_IP_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   The IP address is invalid. */
/*  */
#define TLR_E_PNIO_RMPM_INVALID_IP_ADDRESS ((TLR_RESULT)0xC0130120L)

/*  */
/*  MessageId: TLR_E_PNIO_RMPM_INVALID_NETMASK */
/*  */
/*  MessageText: */
/*  */
/*   The network mask is invalid. */
/*  */
#define TLR_E_PNIO_RMPM_INVALID_NETMASK  ((TLR_RESULT)0xC0130121L)

/*  */
/*  MessageId: TLR_E_PNIO_RMPM_INVALID_GATEWAY */
/*  */
/*  MessageText: */
/*  */
/*   The gateway address is invalid. */
/*  */
#define TLR_E_PNIO_RMPM_INVALID_GATEWAY  ((TLR_RESULT)0xC0130122L)

/*  NRMC */
/*  */
/*  MessageId: TLR_E_PNIO_NRMC_PARAM_INVALID_INIT */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_NRMC_PARAM_INVALID_INIT ((TLR_RESULT)0xC0130200L)

/*  */
/*  MessageId: TLR_E_PNIO_NRMC_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The handle to NRMC is invalid. */
/*  */
#define TLR_E_PNIO_NRMC_HANDLE_INVALID   ((TLR_RESULT)0xC0130201L)

/*  */
/*  MessageId: TLR_E_PNIO_NRMC_STATE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The state of NRMC is invalid for current request. */
/*  */
#define TLR_E_PNIO_NRMC_STATE_INVALID    ((TLR_RESULT)0xC0130202L)

/*  */
/*  MessageId: TLR_E_PNIO_NRMC_IDENTIFY_FLAG_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_NRMC_IDENTIFY_FLAG_INVALID ((TLR_RESULT)0xC0130203L)

/*  */
/*  MessageId: TLR_E_PNIO_NRMC_RESOURCE_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   The number of NRMC state-machines is to high. */
/*  */
#define TLR_E_PNIO_NRMC_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0130204L)

/*  */
/*  MessageId: TLR_E_PNIO_NRMC_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory to fullfill the current request in NRMC. */
/*  */
#define TLR_E_PNIO_NRMC_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0130205L)

/*  */
/*  MessageId: TLR_E_PNIO_NRMC_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Error while sending a packet to another task in NRMC. */
/*  */
#define TLR_E_PNIO_NRMC_PACKET_SEND_FAILED ((TLR_RESULT)0xC0130206L)

/*  */
/*  MessageId: TLR_E_PNIO_NRMC_PACKET_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory to allocate a packet in NRMC. */
/*  */
#define TLR_E_PNIO_NRMC_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC0130207L)

/*  */
/*  MessageId: TLR_E_PNIO_NRMC_DCP_TYPE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   tbd. */
/*  */
#define TLR_E_PNIO_NRMC_DCP_TYPE_INVALID ((TLR_RESULT)0xC0130208L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PNIO CTL Diagnosis-Codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CMCTL-Task Diagnosis-Codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_DIAG_E_CMCTL_TASK_RESOURCE_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Initializing CMCTL's task-resources failed. */
/*  */
#define TLR_DIAG_E_CMCTL_TASK_RESOURCE_INIT_FAILED ((TLR_RESULT)0xC00AF000L)

/*  */
/*  MessageId: TLR_DIAG_E_CMCTL_TASK_CREATE_QUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to create message-queue for CMCTL. */
/*  */
#define TLR_DIAG_E_CMCTL_TASK_CREATE_QUE_FAILED ((TLR_RESULT)0xC00AF001L)

/*  */
/*  MessageId: TLR_DIAG_E_CMCTL_TASK_CREATE_SYNC_QUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to create synchronous message-queue for CMCTL. */
/*  */
#define TLR_DIAG_E_CMCTL_TASK_CREATE_SYNC_QUE_FAILED ((TLR_RESULT)0xC00AF002L)

/*  */
/*  MessageId: TLR_DIAG_E_CMCTL_TASK_RPC_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize CMCTL's local RPC-ressources. */
/*  */
#define TLR_DIAG_E_CMCTL_TASK_RPC_INIT_FAILED ((TLR_RESULT)0xC00AF003L)

/*  */
/*  MessageId: TLR_DIAG_E_CMCTL_TASK_IDENT_ACP_QUE_FALIED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get handle to ACP message-queue in CMCTL. */
/*  */
#define TLR_DIAG_E_CMCTL_TASK_IDENT_ACP_QUE_FALIED ((TLR_RESULT)0xC00AF004L)

/*  */
/*  MessageId: TLR_DIAG_E_CMCTL_TASK_IDENT_MGT_QUE_FALIED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get handle to MGT message-queue in CMCTL. */
/*  */
#define TLR_DIAG_E_CMCTL_TASK_IDENT_MGT_QUE_FALIED ((TLR_RESULT)0xC00AF005L)

/*  */
/*  MessageId: TLR_DIAG_E_CMCTL_TASK_IDENT_RPC_QUE_FALIED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get handle to RPC message-queue in CMCTL. */
/*  */
#define TLR_DIAG_E_CMCTL_TASK_IDENT_RPC_QUE_FALIED ((TLR_RESULT)0xC00AF006L)

/*  */
/*  MessageId: TLR_DIAG_E_CMCTL_TASK_IDENT_TCP_QUE_FALIED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get handle to TCP/IP message-queue in CMCTL . */
/*  */
#define TLR_DIAG_E_CMCTL_TASK_IDENT_TCP_QUE_FALIED ((TLR_RESULT)0xC00AF007L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CMDEV-Task Diagnosis-Codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_DIAG_E_CMDEV_TASK_RESOURCE_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Initializing CMDEV's task-resources failed. */
/*  */
#define TLR_DIAG_E_CMDEV_TASK_RESOURCE_INIT_FAILED ((TLR_RESULT)0xC00BF000L)

/*  */
/*  MessageId: TLR_DIAG_E_CMDEV_TASK_CREATE_QUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to create message-queue for CMDEV. */
/*  */
#define TLR_DIAG_E_CMDEV_TASK_CREATE_QUE_FAILED ((TLR_RESULT)0xC00BF001L)

/*  */
/*  MessageId: TLR_DIAG_E_CMDEV_TASK_CREATE_SYNC_QUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to create synchronous message-queue for CMDEV. */
/*  */
#define TLR_DIAG_E_CMDEV_TASK_CREATE_SYNC_QUE_FAILED ((TLR_RESULT)0xC00BF002L)

/*  */
/*  MessageId: TLR_DIAG_E_CMDEV_TASK_RPC_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize CMDEV's local RPC-ressources. */
/*  */
#define TLR_DIAG_E_CMDEV_TASK_RPC_INIT_FAILED ((TLR_RESULT)0xC00BF003L)

/*  */
/*  MessageId: TLR_DIAG_E_CMDEV_TASK_IDENT_ACP_QUE_FALIED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get handle to ACP message-queue in CMDEV. */
/*  */
#define TLR_DIAG_E_CMDEV_TASK_IDENT_ACP_QUE_FALIED ((TLR_RESULT)0xC00BF004L)

/*  */
/*  MessageId: TLR_DIAG_E_CMDEV_TASK_IDENT_MGT_QUE_FALIED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get handle to MGT message-queue in CMDEV. */
/*  */
#define TLR_DIAG_E_CMDEV_TASK_IDENT_MGT_QUE_FALIED ((TLR_RESULT)0xC00BF005L)

/*  */
/*  MessageId: TLR_DIAG_E_CMDEV_TASK_IDENT_RPC_QUE_FALIED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get handle to RPC message-queue in CMDEV. */
/*  */
#define TLR_DIAG_E_CMDEV_TASK_IDENT_RPC_QUE_FALIED ((TLR_RESULT)0xC00BF006L)

/*  */
/*  MessageId: TLR_DIAG_E_CMDEV_TASK_IDENT_TCP_QUE_FALIED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get handle to TCP/IP message-queue in CMDEV . */
/*  */
#define TLR_DIAG_E_CMDEV_TASK_IDENT_TCP_QUE_FALIED ((TLR_RESULT)0xC00BF007L)

/*  */
/*  MessageId: TLR_DIAG_E_CMDEV_TASK_IDENT_DCP_QUE_FALIED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get handle to DCP message-queue in CMDEV . */
/*  */
#define TLR_DIAG_E_CMDEV_TASK_IDENT_DCP_QUE_FALIED ((TLR_RESULT)0xC00BF008L)

/*  */
/*  MessageId: TLR_DIAG_E_CMDEV_TASK_IDENT_PNSIF_QUE_FALIED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get handle to PNSIF message-queue in CMDEV . */
/*  */
#define TLR_DIAG_E_CMDEV_TASK_IDENT_PNSIF_QUE_FALIED ((TLR_RESULT)0xC00BF009L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  ACP-Task Diagnosis-Codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PNIO_ACP_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Received invalid command in ACP task. */
/*  */
#define TLR_E_PNIO_ACP_COMMAND_INVALID   ((TLR_RESULT)0xC011F001L)

/*  */
/*  MessageId: TLR_DIAG_E_ACP_TASK_ACP_PHASE_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize ACP Phase. */
/*  */
#define TLR_DIAG_E_ACP_TASK_ACP_PHASE_INIT_FAILED ((TLR_RESULT)0xC011F010L)

/*  */
/*  MessageId: TLR_DIAG_E_ACP_TASK_ALARM_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize Alarm-machines. */
/*  */
#define TLR_DIAG_E_ACP_TASK_ALARM_INIT_FAILED ((TLR_RESULT)0xC011F011L)

/*  */
/*  MessageId: TLR_DIAG_E_ACP_TASK_APMR_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize APMR. */
/*  */
#define TLR_DIAG_E_ACP_TASK_APMR_INIT_FAILED ((TLR_RESULT)0xC011F012L)

/*  */
/*  MessageId: TLR_DIAG_E_ACP_TASK_APMS_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failes to initialize APMS. */
/*  */
#define TLR_DIAG_E_ACP_TASK_APMS_INIT_FAILED ((TLR_RESULT)0xC011F013L)

/*  */
/*  MessageId: TLR_DIAG_E_ACP_TASK_CPM_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize CPM. */
/*  */
#define TLR_DIAG_E_ACP_TASK_CPM_INIT_FAILED ((TLR_RESULT)0xC011F014L)

/*  */
/*  MessageId: TLR_DIAG_E_ACP_TASK_PPM_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize PPM. */
/*  */
#define TLR_DIAG_E_ACP_TASK_PPM_INIT_FAILED ((TLR_RESULT)0xC011F015L)

/*  */
/*  MessageId: TLR_DIAG_E_ACP_TASK_CREATE_QUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to create message-queue for ACP. */
/*  */
#define TLR_DIAG_E_ACP_TASK_CREATE_QUE_FAILED ((TLR_RESULT)0xC011F016L)

/*  */
/*  MessageId: TLR_DIAG_E_ACP_TASK_IDENT_EDD_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to identify Drv_EDD. */
/*  */
#define TLR_DIAG_E_ACP_TASK_IDENT_EDD_FAILED ((TLR_RESULT)0xC011F017L)

/*  */
/*  MessageId: TLR_DIAG_E_ACP_TASK_IDENT_EDD_QUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get handle to EDD message-queue. */
/*  */
#define TLR_DIAG_E_ACP_TASK_IDENT_EDD_QUE_FAILED ((TLR_RESULT)0xC011F018L)

/*  */
/*  MessageId: TLR_DIAG_E_ACP_TASK_IDENT_DCP_QUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get handle to DCP message-queue. */
/*  */
#define TLR_DIAG_E_ACP_TASK_IDENT_DCP_QUE_FAILED ((TLR_RESULT)0xC011F019L)

/*  */
/*  MessageId: TLR_DIAG_E_ACP_TASK_IDENT_CMDEV_QUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get handle to CMDEV message-queue. */
/*  */
#define TLR_DIAG_E_ACP_TASK_IDENT_CMDEV_QUE_FAILED ((TLR_RESULT)0xC011F01AL)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  EDD-Task Diagnosis-Codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PNIO_EDD_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Received invalid command in EDD task. */
/*  */
#define TLR_E_PNIO_EDD_COMMAND_INVALID   ((TLR_RESULT)0xC00EF001L)

/*  */
/*  MessageId: TLR_DIAG_E_EDD_TASK_INIT_LOCAL_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize EDD's local resources. */
/*  */
#define TLR_DIAG_E_EDD_TASK_INIT_LOCAL_FAILED ((TLR_RESULT)0xC00EF010L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  DCP-Task Diagnosis-Codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PNIO_DCP_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Received invalid command in DCP task. */
/*  */
#define TLR_E_PNIO_DCP_COMMAND_INVALID   ((TLR_RESULT)0xC012F001L)

/*  */
/*  MessageId: TLR_DIAG_E_DCP_TASK_UCS_RESOURCE_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize DCPUCS. */
/*  */
#define TLR_DIAG_E_DCP_TASK_UCS_RESOURCE_INIT_FAILED ((TLR_RESULT)0xC012F010L)

/*  */
/*  MessageId: TLR_DIAG_E_DCP_TASK_UCR_RESOURCE_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize DCPUCR. */
/*  */
#define TLR_DIAG_E_DCP_TASK_UCR_RESOURCE_INIT_FAILED ((TLR_RESULT)0xC012F011L)

/*  */
/*  MessageId: TLR_DIAG_E_DCP_TASK_MCS_RESOURCE_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize DCPMCS. */
/*  */
#define TLR_DIAG_E_DCP_TASK_MCS_RESOURCE_INIT_FAILED ((TLR_RESULT)0xC012F012L)

/*  */
/*  MessageId: TLR_DIAG_E_DCP_TASK_MCR_RESOURCE_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize DCPMCR. */
/*  */
#define TLR_DIAG_E_DCP_TASK_MCR_RESOURCE_INIT_FAILED ((TLR_RESULT)0xC012F013L)

/*  */
/*  MessageId: TLR_DIAG_E_DCP_TASK_CREATE_QUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to create message-queue for DCP task. */
/*  */
#define TLR_DIAG_E_DCP_TASK_CREATE_QUE_FAILED ((TLR_RESULT)0xC012F014L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  MGT-Task Diagnosis-Codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PNIO_MGT_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Received invalid command in MGT task. */
/*  */
#define TLR_E_PNIO_MGT_COMMAND_INVALID   ((TLR_RESULT)0xC013F001L)

/*  */
/*  MessageId: TLR_DIAG_E_MGT_TASK_RMPM_RESOURCE_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize RMPM. */
/*  */
#define TLR_DIAG_E_MGT_TASK_RMPM_RESOURCE_INIT_FAILED ((TLR_RESULT)0xC013F010L)

/*  */
/*  MessageId: TLR_DIAG_E_MGT_TASK_NRPM_RESOURCE_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize NRPM. */
/*  */
#define TLR_DIAG_E_MGT_TASK_NRPM_RESOURCE_INIT_FAILED ((TLR_RESULT)0xC013F011L)

/*  */
/*  MessageId: TLR_DIAG_E_MGT_TASK_CREATE_QUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to create message-queue for MGT task. */
/*  */
#define TLR_DIAG_E_MGT_TASK_CREATE_QUE_FAILED ((TLR_RESULT)0xC013F012L)

/*  */
/*  MessageId: TLR_DIAG_E_MGT_TASK_IDENT_TCPUDP_QUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get handle to TCP/IP task in MGT task. */
/*  */
#define TLR_DIAG_E_MGT_TASK_IDENT_TCPUDP_QUE_FAILED ((TLR_RESULT)0xC013F013L)

/*  */
/*  MessageId: TLR_DIAG_E_MGT_TASK_IDENT_DCP_QUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get handle to DCP task in MGT task. */
/*  */
#define TLR_DIAG_E_MGT_TASK_IDENT_DCP_QUE_FAILED ((TLR_RESULT)0xC013F014L)

/*  */
/*  MessageId: TLR_DIAG_E_MGT_TASK_IDENT_EDD_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to identify Drv_EDD im MGT task. */
/*  */
#define TLR_DIAG_E_MGT_TASK_IDENT_EDD_FAILED ((TLR_RESULT)0xC013F015L)

/*  */
/*  MessageId: TLR_DIAG_E_MGT_TASK_IDENT_RPC_QUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get handle to RPC task in MGT task. */
/*  */
#define TLR_DIAG_E_MGT_TASK_IDENT_RPC_QUE_FAILED ((TLR_RESULT)0xC013F016L)




#endif  /* __PNIOC_ERROR_H */

#ifndef __PNIOD_16BITIO_ERROR_H
#define __PNIOD_16BITIO_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFINET IO-Device 16 Bit IO Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PNIOD_16BITIO_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_PNIOD_16BITIO_COMMAND_INVALID ((TLR_RESULT)0xC03A0001L)




#endif  /* __PNIOD_16BITIO_ERROR_H */

#ifndef __PNIOD_DPMIF_ERROR_H
#define __PNIOD_DPMIF_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFINET IO-Device DPM Interface */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PNIOD_DPMIF_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_PNIOD_DPMIF_COMMAND_INVALID ((TLR_RESULT)0xC01A0001L)




#endif  /* __PNIOD_DPMIF_ERROR_H */

#ifndef __PNIOD_LENZE_ERROR_H
#define __PNIOD_LENZE_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Lenze Lenze PROFINET IO-Device */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PNIOD_LENZE_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_PNIOD_LENZE_COMMAND_INVALID ((TLR_RESULT)0xC0100001L)

/*  */
/*  MessageId: TLR_E_PNIOD_LENZE_INIT_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_PNIOD_LENZE_INIT_COMMAND_INVALID ((TLR_RESULT)0xC01C0001L)




#endif  /* __PNIOD_LENZE_ERROR_H */

#ifndef __PNS_32BITIO_ERROR_H
#define __PNS_32BITIO_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFINET IO-Device 32BIT IO Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PNS_32BITIO_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_PNS_32BITIO_COMMAND_INVALID ((TLR_RESULT)0xC05E0001L)




#endif  /* __PNS_32BITIO_ERROR_H */

#ifndef __PNS_4BITIO_ERROR_H
#define __PNS_4BITIO_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFINET IO-Device 4 Bit IO Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PNS_4BITIO_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_PNS_4BITIO_COMMAND_INVALID ((TLR_RESULT)0xC0450001L)




#endif  /* __PNS_4BITIO_ERROR_H */

#ifndef __PNS_ERROR_H
#define __PNS_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFINET IO-Device Interface Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PNS_IF_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_PNS_IF_COMMAND_INVALID     ((TLR_RESULT)0xC0300001L)

/*  */
/*  MessageId: TLR_E_PNS_IF_OS_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Initialization of PNS Operating system adapatation failed. */
/*  */
#define TLR_E_PNS_IF_OS_INIT_FAILED      ((TLR_RESULT)0xC0300002L)

/*  */
/*  MessageId: TLR_E_PNS_IF_SET_INIT_IP_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Initialization of PNS IP address failed. */
/*  */
#define TLR_E_PNS_IF_SET_INIT_IP_FAILED  ((TLR_RESULT)0xC0300003L)

/*  */
/*  MessageId: TLR_E_PNS_IF_PNIO_SETUP_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO-Device Setup failed. */
/*  */
#define TLR_E_PNS_IF_PNIO_SETUP_FAILED   ((TLR_RESULT)0xC0300004L)

/*  */
/*  MessageId: TLR_E_PNS_IF_DEVICE_INFO_ALREADY_SET */
/*  */
/*  MessageText: */
/*  */
/*   Device information set already. */
/*  */
#define TLR_E_PNS_IF_DEVICE_INFO_ALREADY_SET ((TLR_RESULT)0xC0300005L)

/*  */
/*  MessageId: TLR_E_PNS_IF_SET_DEVICE_INFO_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Setting of device information failed. */
/*  */
#define TLR_E_PNS_IF_SET_DEVICE_INFO_FAILED ((TLR_RESULT)0xC0300006L)

/*  */
/*  MessageId: TLR_E_PNS_IF_NO_DEVICE_SETUP */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO-Device stack is not initialized. Send PNS_IF_SET_DEVICEINFO_REQ before PNS_IF_OPEN_DEVICE_REQ. */
/*  */
#define TLR_E_PNS_IF_NO_DEVICE_SETUP     ((TLR_RESULT)0xC0300007L)

/*  */
/*  MessageId: TLR_E_PNS_IF_DEVICE_OPEN_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Opening a device instance failed. */
/*  */
#define TLR_E_PNS_IF_DEVICE_OPEN_FAILED  ((TLR_RESULT)0xC0300008L)

/*  */
/*  MessageId: TLR_E_PNS_IF_NO_DEVICE_INSTANCE */
/*  */
/*  MessageText: */
/*  */
/*   No device instance open. */
/*  */
#define TLR_E_PNS_IF_NO_DEVICE_INSTANCE  ((TLR_RESULT)0xC0300009L)

/*  */
/*  MessageId: TLR_E_PNS_IF_PLUG_MODULE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Plugging a module failed. */
/*  */
#define TLR_E_PNS_IF_PLUG_MODULE_FAILED  ((TLR_RESULT)0xC030000AL)

/*  */
/*  MessageId: TLR_E_PNS_IF_PLUG_SUBMODULE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Plugging a submodule failed. */
/*  */
#define TLR_E_PNS_IF_PLUG_SUBMODULE_FAILED ((TLR_RESULT)0xC030000BL)

/*  */
/*  MessageId: TLR_E_PNS_IF_DEVICE_START_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Start of PROFINET IO-Device failed. */
/*  */
#define TLR_E_PNS_IF_DEVICE_START_FAILED ((TLR_RESULT)0xC030000CL)

/*  */
/*  MessageId: TLR_E_PNS_IF_EDD_ENABLE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Start of network communication failed. */
/*  */
#define TLR_E_PNS_IF_EDD_ENABLE_FAILED   ((TLR_RESULT)0xC030000DL)

/*  */
/*  MessageId: TLR_E_PNS_IF_ALLOC_MNGMNT_BUFFER_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Allocation of a device instance management buffer failed. */
/*  */
#define TLR_E_PNS_IF_ALLOC_MNGMNT_BUFFER_FAILED ((TLR_RESULT)0xC030000EL)

/*  */
/*  MessageId: TLR_E_PNS_IF_DEVICE_HANDLE_NULL */
/*  */
/*  MessageText: */
/*  */
/*   Given device handle is NULL. */
/*  */
#define TLR_E_PNS_IF_DEVICE_HANDLE_NULL  ((TLR_RESULT)0xC030000FL)

/*  */
/*  MessageId: TLR_E_PNS_IF_SET_APPL_READY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Command PNS_IF_SET_APPL_READY_REQ failed. */
/*  */
#define TLR_E_PNS_IF_SET_APPL_READY_FAILED ((TLR_RESULT)0xC0300010L)

/*  */
/*  MessageId: TLR_E_PNS_IF_SET_DEVSTATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Command PNS_IF_SET_DEVSTATE_REQ failed. */
/*  */
#define TLR_E_PNS_IF_SET_DEVSTATE_FAILED ((TLR_RESULT)0xC0300011L)

/*  */
/*  MessageId: TLR_E_PNS_IF_PULL_SUBMODULE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Pulling the submodule failed. */
/*  */
#define TLR_E_PNS_IF_PULL_SUBMODULE_FAILED ((TLR_RESULT)0xC0300012L)

/*  */
/*  MessageId: TLR_E_PNS_IF_PULL_MODULE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Pulling the module failed. */
/*  */
#define TLR_E_PNS_IF_PULL_MODULE_FAILED  ((TLR_RESULT)0xC0300013L)

/*  */
/*  MessageId: TLR_E_PNS_IF_WRONG_DEST_ID */
/*  */
/*  MessageText: */
/*  */
/*   Destination ID in command invalid. */
/*  */
#define TLR_E_PNS_IF_WRONG_DEST_ID       ((TLR_RESULT)0xC0300014L)

/*  */
/*  MessageId: TLR_E_PNS_IF_DEVICE_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Device Handle in command invalid. */
/*  */
#define TLR_E_PNS_IF_DEVICE_HANDLE_INVALID ((TLR_RESULT)0xC0300015L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CALLBACK_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   PNS stack callback timeout. */
/*  */
#define TLR_E_PNS_IF_CALLBACK_TIMEOUT    ((TLR_RESULT)0xC0300016L)

/*  */
/*  MessageId: TLR_E_PNS_IF_PACKET_POOL_EMPTY */
/*  */
/*  MessageText: */
/*  */
/*   PNS_IF packet pool empty. */
/*  */
#define TLR_E_PNS_IF_PACKET_POOL_EMPTY   ((TLR_RESULT)0xC0300017L)

/*  */
/*  MessageId: TLR_E_PNS_IF_ADD_API_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Command PNS_IF_ADD_API_REQ failed. */
/*  */
#define TLR_E_PNS_IF_ADD_API_FAILED      ((TLR_RESULT)0xC0300018L)

/*  */
/*  MessageId: TLR_E_PNS_IF_SET_SUB_STATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Setting submodule state failed. */
/*  */
#define TLR_E_PNS_IF_SET_SUB_STATE_FAILED ((TLR_RESULT)0xC0300019L)

/*  */
/*  MessageId: TLR_E_PNS_IF_NO_NW_DBM_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   No network configuration DBM-file. */
/*  */
#define TLR_E_PNS_IF_NO_NW_DBM_ERROR     ((TLR_RESULT)0xC030001AL)

/*  */
/*  MessageId: TLR_E_PNS_IF_NW_SETUP_TABLE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error during reading the "SETUP" table of the network configuration DBM-file . */
/*  */
#define TLR_E_PNS_IF_NW_SETUP_TABLE_ERROR ((TLR_RESULT)0xC030001BL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CFG_SETUP_TABLE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error during reading the "SETUP" table of the config.xxx DBM-file . */
/*  */
#define TLR_E_PNS_IF_CFG_SETUP_TABLE_ERROR ((TLR_RESULT)0xC030001CL)

/*  */
/*  MessageId: TLR_E_PNS_IF_NO_CFG_DBM_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   No config.xxx DBM-file. */
/*  */
#define TLR_E_PNS_IF_NO_CFG_DBM_ERROR    ((TLR_RESULT)0xC030001DL)

/*  */
/*  MessageId: TLR_E_PNS_IF_DBM_DATASET_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error getting dataset pointer. */
/*  */
#define TLR_E_PNS_IF_DBM_DATASET_ERROR   ((TLR_RESULT)0xC030001EL)

/*  */
/*  MessageId: TLR_E_PNS_IF_SETUPEX_TABLE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error getting dataset pointer(SETUP_EX table). */
/*  */
#define TLR_E_PNS_IF_SETUPEX_TABLE_ERROR ((TLR_RESULT)0xC030001FL)

/*  */
/*  MessageId: TLR_E_PNS_IF_AP_TABLE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error getting either dataset pointer or number of datasets(AP table). */
/*  */
#define TLR_E_PNS_IF_AP_TABLE_ERROR      ((TLR_RESULT)0xC0300020L)

/*  */
/*  MessageId: TLR_E_PNS_IF_MODULES_TABLE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error getting either dataset pointer or number of datasets(MODULE table). */
/*  */
#define TLR_E_PNS_IF_MODULES_TABLE_ERROR ((TLR_RESULT)0xC0300021L)

/*  */
/*  MessageId: TLR_E_PNS_IF_SUBMODULES_TABLE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error getting either dataset pointer or number of datasets(SUBMODULE table). */
/*  */
#define TLR_E_PNS_IF_SUBMODULES_TABLE_ERROR ((TLR_RESULT)0xC0300022L)

/*  */
/*  MessageId: TLR_E_PNS_IF_PNIO_SETUP_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error setting up PNIO configuration(PNIO_setup()). */
/*  */
#define TLR_E_PNS_IF_PNIO_SETUP_ERROR    ((TLR_RESULT)0xC0300023L)

/*  */
/*  MessageId: TLR_E_PNS_IF_MODULES_GET_REC */
/*  */
/*  MessageText: */
/*  */
/*   Error getting record of "MODULES" linked table. */
/*  */
#define TLR_E_PNS_IF_MODULES_GET_REC     ((TLR_RESULT)0xC0300024L)

/*  */
/*  MessageId: TLR_E_PNS_IF_SUBMODULES_GET_REC */
/*  */
/*  MessageText: */
/*  */
/*   Error getting record of "SUBMODULES" linked table. */
/*  */
#define TLR_E_PNS_IF_SUBMODULES_GET_REC  ((TLR_RESULT)0xC0300025L)

/*  */
/*  MessageId: TLR_E_PNS_IF_PNIOD_MODULE_ID_TABLE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error accessing "PNIOD_MODULE_ID" table or table record error. */
/*  */
#define TLR_E_PNS_IF_PNIOD_MODULE_ID_TABLE_ERROR ((TLR_RESULT)0xC0300026L)

/*  */
/*  MessageId: TLR_E_PNS_IF_SIGNALS_TABLE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error accessing "SIGNALS" table or table record error. */
/*  */
#define TLR_E_PNS_IF_SIGNALS_TABLE_ERROR ((TLR_RESULT)0xC0300027L)

/*  */
/*  MessageId: TLR_E_PNS_IF_MODULES_IO_TABLE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error accessing "MODULES_IO" table or table record error. */
/*  */
#define TLR_E_PNS_IF_MODULES_IO_TABLE_ERROR ((TLR_RESULT)0xC0300028L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CHANNEL_SETTING_TABLE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error accessing "CHANNEL_SETTING" table or table record error. */
/*  */
#define TLR_E_PNS_IF_CHANNEL_SETTING_TABLE_ERROR ((TLR_RESULT)0xC0300029L)

/*  */
/*  MessageId: TLR_E_PNS_IF_WRITE_DBM */
/*  */
/*  MessageText: */
/*  */
/*   Error writing DBM-file. */
/*  */
#define TLR_E_PNS_IF_WRITE_DBM           ((TLR_RESULT)0xC030002AL)

/*  */
/*  MessageId: TLR_E_PNS_IF_DPM_CONFIG */
/*  */
/*  MessageText: */
/*  */
/*   No basic DPM configuration. */
/*  */
#define TLR_E_PNS_IF_DPM_CONFIG          ((TLR_RESULT)0xC030002BL)

/*  */
/*  MessageId: TLR_E_PNS_IF_WATCHDOG */
/*  */
/*  MessageText: */
/*  */
/*   Application did not trigger the watchdog. */
/*  */
#define TLR_E_PNS_IF_WATCHDOG            ((TLR_RESULT)0xC030002CL)

/*  */
/*  MessageId: TLR_E_PNS_IF_SIGNALS_SUBMODULES */
/*  */
/*  MessageText: */
/*  */
/*   Data length in "SIGNALS" table does not correspond to that in "SUBMODULES" table. */
/*  */
#define TLR_E_PNS_IF_SIGNALS_SUBMODULES  ((TLR_RESULT)0xC030002DL)

/*  */
/*  MessageId: TLR_E_PNS_IF_READ_DPM_SUBAREA */
/*  */
/*  MessageText: */
/*  */
/*   Failed to read DPM subarea. */
/*  */
#define TLR_E_PNS_IF_READ_DPM_SUBAREA    ((TLR_RESULT)0xC030002EL)

/*  */
/*  MessageId: TLR_E_PNS_IF_MOD_0_SUB_1 */
/*  */
/*  MessageText: */
/*  */
/*   Error configuring Module 0 Submodule 1. */
/*  */
#define TLR_E_PNS_IF_MOD_0_SUB_1         ((TLR_RESULT)0xC030002FL)

/*  */
/*  MessageId: TLR_E_PNS_IF_SIGNALS_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Length of I/O signals is bigger then the size of DPM subarea. */
/*  */
#define TLR_E_PNS_IF_SIGNALS_LENGTH      ((TLR_RESULT)0xC0300030L)

/*  */
/*  MessageId: TLR_E_PNS_IF_SUB_TRANSFER_DIRECTION */
/*  */
/*  MessageText: */
/*  */
/*   A submodule can not have input and outputs at the same time. */
/*  */
#define TLR_E_PNS_IF_SUB_TRANSFER_DIRECTION ((TLR_RESULT)0xC0300031L)

/*  */
/*  MessageId: TLR_E_PNS_IF_FORMAT_PNVOLUME */
/*  */
/*  MessageText: */
/*  */
/*   Error while formatting PNVOLUME. */
/*  */
#define TLR_E_PNS_IF_FORMAT_PNVOLUME     ((TLR_RESULT)0xC0300032L)

/*  */
/*  MessageId: TLR_E_PNS_IF_MOUNT_PNVOLUME */
/*  */
/*  MessageText: */
/*  */
/*   Error while mounting PNVOLUME. */
/*  */
#define TLR_E_PNS_IF_MOUNT_PNVOLUME      ((TLR_RESULT)0xC0300033L)

/*  */
/*  MessageId: TLR_E_PNS_IF_INIT_REMOTE */
/*  */
/*  MessageText: */
/*  */
/*   Error during initialization of the remote resources of the stack. */
/*  */
#define TLR_E_PNS_IF_INIT_REMOTE         ((TLR_RESULT)0xC0300034L)

/*  */
/*  MessageId: TLR_E_PNS_IF_WARMSTART_CONFIG_REDUNDANT */
/*  */
/*  MessageText: */
/*  */
/*   Warmstart parameters are redundant. The stack was configured with DBM or packets. */
/*  */
#define TLR_E_PNS_IF_WARMSTART_CONFIG_REDUNDANT ((TLR_RESULT)0xC0300035L)

/*  */
/*  MessageId: TLR_E_PNS_IF_WARMSTART_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Incorrect warmstart parameter(s). */
/*  */
#define TLR_E_PNS_IF_WARMSTART_PARAMETER ((TLR_RESULT)0xC0300036L)

/*  */
/*  MessageId: TLR_E_PNS_IF_SET_APPL_STATE_READY */
/*  */
/*  MessageText: */
/*  */
/*   PNIO_set_appl_state_ready() returns error. */
/*  */
#define TLR_E_PNS_IF_SET_APPL_STATE_READY ((TLR_RESULT)0xC0300037L)

/*  */
/*  MessageId: TLR_E_PNS_IF_SET_DEV_STATE */
/*  */
/*  MessageText: */
/*  */
/*   PNIO_set_dev_state() returns error. */
/*  */
#define TLR_E_PNS_IF_SET_DEV_STATE       ((TLR_RESULT)0xC0300038L)

/*  */
/*  MessageId: TLR_E_PNS_IF_PROCESS_ALARM_SEND */
/*  */
/*  MessageText: */
/*  */
/*   PNIO_process_alarm_send() returns error. */
/*  */
#define TLR_E_PNS_IF_PROCESS_ALARM_SEND  ((TLR_RESULT)0xC0300039L)

/*  */
/*  MessageId: TLR_E_PNS_IF_RET_OF_SUB_ALARM_SEND */
/*  */
/*  MessageText: */
/*  */
/*   PNIO_ret_of_sub_alarm_send() returns error. */
/*  */
#define TLR_E_PNS_IF_RET_OF_SUB_ALARM_SEND ((TLR_RESULT)0xC030003AL)

/*  */
/*  MessageId: TLR_E_PNS_IF_DIAG_ALARM_SEND */
/*  */
/*  MessageText: */
/*  */
/*   PNIO_diag_alarm_send() returns error. */
/*  */
#define TLR_E_PNS_IF_DIAG_ALARM_SEND     ((TLR_RESULT)0xC030003BL)

/*  */
/*  MessageId: TLR_E_PNS_IF_DIAG_GENERIC_ADD */
/*  */
/*  MessageText: */
/*  */
/*   PNIO_diag_generic_add() returns error. */
/*  */
#define TLR_E_PNS_IF_DIAG_GENERIC_ADD    ((TLR_RESULT)0xC030003CL)

/*  */
/*  MessageId: TLR_E_PNS_IF_DIAG_GENERIC_REMOVE */
/*  */
/*  MessageText: */
/*  */
/*   PNIO_diag_generic_remove() returns error. */
/*  */
#define TLR_E_PNS_IF_DIAG_GENERIC_REMOVE ((TLR_RESULT)0xC030003DL)

/*  */
/*  MessageId: TLR_E_PNS_IF_DIAG_CHANNEL_ADD */
/*  */
/*  MessageText: */
/*  */
/*   PNIO_diag_channel_add() returns error. */
/*  */
#define TLR_E_PNS_IF_DIAG_CHANNEL_ADD    ((TLR_RESULT)0xC030003EL)

/*  */
/*  MessageId: TLR_E_PNS_IF_DIAG_CHANNEL_REMOVE */
/*  */
/*  MessageText: */
/*  */
/*   PNIO_diag_channel_remove() returns error. */
/*  */
#define TLR_E_PNS_IF_DIAG_CHANNEL_REMOVE ((TLR_RESULT)0xC030003FL)

/*  */
/*  MessageId: TLR_E_PNS_IF_EXT_DIAG_CHANNEL_ADD */
/*  */
/*  MessageText: */
/*  */
/*   PNIO_ext_diag_channel_add() returns error. */
/*  */
#define TLR_E_PNS_IF_EXT_DIAG_CHANNEL_ADD ((TLR_RESULT)0xC0300040L)

/*  */
/*  MessageId: TLR_E_PNS_IF_EXT_DIAG_CHANNEL_REMOVE */
/*  */
/*  MessageText: */
/*  */
/*   PNIO_ext_diag_channel_remove() returns error. */
/*  */
#define TLR_E_PNS_IF_EXT_DIAG_CHANNEL_REMOVE ((TLR_RESULT)0xC0300041L)

/*  */
/*  MessageId: TLR_E_PNS_IF_STATION_NAME_LEN */
/*  */
/*  MessageText: */
/*  */
/*   Parameter station name length is incorrect. */
/*  */
#define TLR_E_PNS_IF_STATION_NAME_LEN    ((TLR_RESULT)0xC0300042L)

/*  */
/*  MessageId: TLR_E_PNS_IF_STATION_NAME */
/*  */
/*  MessageText: */
/*  */
/*   Parameter station name is incorrect. */
/*  */
#define TLR_E_PNS_IF_STATION_NAME        ((TLR_RESULT)0xC0300043L)

/*  */
/*  MessageId: TLR_E_PNS_IF_STATION_TYPE_LEN */
/*  */
/*  MessageText: */
/*  */
/*   Parameter station type length is incorrect. */
/*  */
#define TLR_E_PNS_IF_STATION_TYPE_LEN    ((TLR_RESULT)0xC0300044L)

/*  */
/*  MessageId: TLR_E_PNS_IF_DEVICE_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Parameter device type is incorrect. */
/*  */
#define TLR_E_PNS_IF_DEVICE_TYPE         ((TLR_RESULT)0xC0300045L)

/*  */
/*  MessageId: TLR_E_PNS_IF_ORDER_ID */
/*  */
/*  MessageText: */
/*  */
/*   Parameter order id is incorrect. */
/*  */
#define TLR_E_PNS_IF_ORDER_ID            ((TLR_RESULT)0xC0300046L)

/*  */
/*  MessageId: TLR_E_PNS_IF_INPUT_STATUS */
/*  */
/*  MessageText: */
/*  */
/*   Parameter input data status bytes length is incorrect. */
/*  */
#define TLR_E_PNS_IF_INPUT_STATUS        ((TLR_RESULT)0xC0300047L)

/*  */
/*  MessageId: TLR_E_PNS_IF_OUTPUT_STATUS */
/*  */
/*  MessageText: */
/*  */
/*   Parameter output data status bytes length is incorrect. */
/*  */
#define TLR_E_PNS_IF_OUTPUT_STATUS       ((TLR_RESULT)0xC0300048L)

/*  */
/*  MessageId: TLR_E_PNS_IF_WATCHDOG_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Parameter watchdog timing is incorrect(must be >= 10). */
/*  */
#define TLR_E_PNS_IF_WATCHDOG_PARAMETER  ((TLR_RESULT)0xC0300049L)

/*  */
/*  MessageId: TLR_E_PNS_IF_OUT_UPDATE */
/*  */
/*  MessageText: */
/*  */
/*   Parameter output data update timing is incorrect. */
/*  */
#define TLR_E_PNS_IF_OUT_UPDATE          ((TLR_RESULT)0xC030004AL)

/*  */
/*  MessageId: TLR_E_PNS_IF_IN_UPDATE */
/*  */
/*  MessageText: */
/*  */
/*   Parameter input data update timing is incorrect. */
/*  */
#define TLR_E_PNS_IF_IN_UPDATE           ((TLR_RESULT)0xC030004BL)

/*  */
/*  MessageId: TLR_E_PNS_IF_IN_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Parameter input memory area size is incorrect. */
/*  */
#define TLR_E_PNS_IF_IN_SIZE             ((TLR_RESULT)0xC030004CL)

/*  */
/*  MessageId: TLR_E_PNS_IF_OUT_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Parameter output memory area size is incorrect. */
/*  */
#define TLR_E_PNS_IF_OUT_SIZE            ((TLR_RESULT)0xC030004DL)

/*  */
/*  MessageId: TLR_E_PNS_IF_GLOBAL_RESOURCES */
/*  */
/*  MessageText: */
/*  */
/*   Unable to allocate memory for global access to local resources. */
/*  */
#define TLR_E_PNS_IF_GLOBAL_RESOURCES    ((TLR_RESULT)0xC030004EL)

/*  */
/*  MessageId: TLR_E_PNS_IF_DYNAMIC_CFG_PCK */
/*  */
/*  MessageText: */
/*  */
/*   Unable to allocate memory for dynamic configuration packet. */
/*  */
#define TLR_E_PNS_IF_DYNAMIC_CFG_PCK     ((TLR_RESULT)0xC030004FL)

/*  */
/*  MessageId: TLR_E_PNS_IF_DEVICE_STOP */
/*  */
/*  MessageText: */
/*  */
/*   Unable to stop device. */
/*  */
#define TLR_E_PNS_IF_DEVICE_STOP         ((TLR_RESULT)0xC0300050L)

/*  */
/*  MessageId: TLR_E_PNS_IF_DEVICE_ID */
/*  */
/*  MessageText: */
/*  */
/*   Parameter device id is incorrect. */
/*  */
#define TLR_E_PNS_IF_DEVICE_ID           ((TLR_RESULT)0xC0300051L)

/*  */
/*  MessageId: TLR_E_PNS_IF_VENDOR_ID */
/*  */
/*  MessageText: */
/*  */
/*   Parameter vendor id is incorrect. */
/*  */
#define TLR_E_PNS_IF_VENDOR_ID           ((TLR_RESULT)0xC0300052L)

/*  */
/*  MessageId: TLR_E_PNS_IF_SYS_START */
/*  */
/*  MessageText: */
/*  */
/*   Parameter system start is incorrect. */
/*  */
#define TLR_E_PNS_IF_SYS_START           ((TLR_RESULT)0xC0300053L)

/*  */
/*  MessageId: TLR_E_PNS_IF_DYN_CFG_IO_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   The length of IO data expected by the controller exceeds the limit specified in warmstart parameters. */
/*  */
#define TLR_E_PNS_IF_DYN_CFG_IO_LENGTH   ((TLR_RESULT)0xC0300054L)

/*  */
/*  MessageId: TLR_E_PNS_IF_DYN_CFG_MOD_NUM */
/*  */
/*  MessageText: */
/*  */
/*   The count of the IO modules expected by the controller exceeds the supported by the stack count. */
/*  */
#define TLR_E_PNS_IF_DYN_CFG_MOD_NUM     ((TLR_RESULT)0xC0300055L)

/*  */
/*  MessageId: TLR_E_PNS_IF_ACCESS_LOCAL_RSC */
/*  */
/*  MessageText: */
/*  */
/*   No global access to local resources. */
/*  */
#define TLR_E_PNS_IF_ACCESS_LOCAL_RSC    ((TLR_RESULT)0xC0300056L)

/*  */
/*  MessageId: TLR_E_PNS_IF_PULL_PLUG */
/*  */
/*  MessageText: */
/*  */
/*   Plugging and pulling modules during creation of communication is not allowed. */
/*  */
#define TLR_E_PNS_IF_PULL_PLUG           ((TLR_RESULT)0xC0300057L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_NUM */
/*  */
/*  MessageText: */
/*  */
/*   Maximum number of ARs is 1. */
/*  */
#define TLR_E_PNS_IF_AR_NUM              ((TLR_RESULT)0xC0300058L)

/*  */
/*  MessageId: TLR_E_PNS_IF_API_NUM */
/*  */
/*  MessageText: */
/*  */
/*   Only API = 0 is supported. */
/*  */
#define TLR_E_PNS_IF_API_NUM             ((TLR_RESULT)0xC0300059L)

/*  */
/*  MessageId: TLR_E_PNS_IF_ALREADY_OPEN */
/*  */
/*  MessageText: */
/*  */
/*   Device is already opened. */
/*  */
#define TLR_E_PNS_IF_ALREADY_OPEN        ((TLR_RESULT)0xC030005AL)

/*  */
/*  MessageId: TLR_E_PNS_IF_API_ADDED */
/*  */
/*  MessageText: */
/*  */
/*   Application is already added. */
/*  */
#define TLR_E_PNS_IF_API_ADDED           ((TLR_RESULT)0xC030005BL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CONFIG_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Configuration modes should not be mixed( DBM-files,application,warmstart message ). */
/*  */
#define TLR_E_PNS_IF_CONFIG_MODE         ((TLR_RESULT)0xC030005CL)

/*  */
/*  MessageId: TLR_E_PNS_IF_UNK_LED_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Unknown LED mode. */
/*  */
#define TLR_E_PNS_IF_UNK_LED_MODE        ((TLR_RESULT)0xC030005DL)

/*  */
/*  MessageId: TLR_E_PNS_IF_PHYSICAL_LINK */
/*  */
/*  MessageText: */
/*  */
/*   Physical link rate is less then 100 Mbit. */
/*  */
#define TLR_E_PNS_IF_PHYSICAL_LINK       ((TLR_RESULT)0xC030005EL)

/*  */
/*  MessageId: TLR_E_PNS_IF_MAX_SLOT_SUBSLOT */
/*  */
/*  MessageText: */
/*  */
/*   Number of slots or subslots too big. */
/*  */
#define TLR_E_PNS_IF_MAX_SLOT_SUBSLOT    ((TLR_RESULT)0xC030005FL)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_MEM */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Out of memory. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_MEM       ((TLR_RESULT)0xC0300060L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_FRAME */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Add provider or consumer failed. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_FRAME     ((TLR_RESULT)0xC0300061L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_MISS */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Consumer missing. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_MISS      ((TLR_RESULT)0xC0300062L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_TIMER */
/*  */
/*  MessageText: */
/*  */
/*   AR error. CMI timeout. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_TIMER     ((TLR_RESULT)0xC0300063L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_ALARM */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Alarm open failed. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_ALARM     ((TLR_RESULT)0xC0300064L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_ALSND */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Alarm send confirmation failed. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_ALSND     ((TLR_RESULT)0xC0300065L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_ALACK */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Alarm acknowledge send confirmation failed. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_ALACK     ((TLR_RESULT)0xC0300066L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_ALLEN */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Alarm data too long. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_ALLEN     ((TLR_RESULT)0xC0300067L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_ASRT */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Alarm indication error. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_ASRT      ((TLR_RESULT)0xC0300068L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_RPC */
/*  */
/*  MessageText: */
/*  */
/*   AR error. RPC client call confirmation failed. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_RPC       ((TLR_RESULT)0xC0300069L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_ABORT */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Abort request. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_ABORT     ((TLR_RESULT)0xC030006AL)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_RERUN */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Re-Run. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_RERUN     ((TLR_RESULT)0xC030006BL)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_REL */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Release indication received. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_REL       ((TLR_RESULT)0xC030006CL)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_PAS */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Device deactivated. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_PAS       ((TLR_RESULT)0xC030006DL)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_RMV */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Device/ar removed. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_RMV       ((TLR_RESULT)0xC030006EL)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_PROT */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Protocol violation. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_PROT      ((TLR_RESULT)0xC030006FL)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_NARE */
/*  */
/*  MessageText: */
/*  */
/*   AR error. NARE error. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_NARE      ((TLR_RESULT)0xC0300070L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_BIND */
/*  */
/*  MessageText: */
/*  */
/*   AR error. RPC-Bind error. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_BIND      ((TLR_RESULT)0xC0300071L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   AR error. RPC-Connect error. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_CONNECT   ((TLR_RESULT)0xC0300072L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_READ */
/*  */
/*  MessageText: */
/*  */
/*   AR error. RPC-Read error. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_READ      ((TLR_RESULT)0xC0300073L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_WRITE */
/*  */
/*  MessageText: */
/*  */
/*   AR error. RPC-Write error. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_WRITE     ((TLR_RESULT)0xC0300074L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_CONTROL */
/*  */
/*  MessageText: */
/*  */
/*   AR error. RPC-Control error. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_CONTROL   ((TLR_RESULT)0xC0300075L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Unknown. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_UNKNOWN   ((TLR_RESULT)0xC0300076L)

/*  */
/*  MessageId: TLR_E_PNS_IF_INIT_WATCHDOG */
/*  */
/*  MessageText: */
/*  */
/*   Watchdog initialization failed. */
/*  */
#define TLR_E_PNS_IF_INIT_WATCHDOG       ((TLR_RESULT)0xC0300077L)

/*  */
/*  MessageId: TLR_E_PNS_IF_NO_PHYSICAL_LINK */
/*  */
/*  MessageText: */
/*  */
/*   The Device is not connected to a network. */
/*  */
#define TLR_E_PNS_IF_NO_PHYSICAL_LINK    ((TLR_RESULT)0xC0300078L)

/*  */
/*  MessageId: TLR_DPM_CYCLIC_IO_RW */
/*  */
/*  MessageText: */
/*  */
/*   Failed to copy from DPM or to DPM the cyclic IO data. */
/*  */
#define TLR_DPM_CYCLIC_IO_RW             ((TLR_RESULT)0xC0300079L)

/*  */
/*  MessageId: TLR_E_PNS_IF_SUBMODULE */
/*  */
/*  MessageText: */
/*  */
/*   Submodule number is wrong. */
/*  */
#define TLR_E_PNS_IF_SUBMODULE           ((TLR_RESULT)0xC030007AL)

/*  */
/*  MessageId: TLR_E_PNS_IF_MODULE */
/*  */
/*  MessageText: */
/*  */
/*   Module number is wrong. */
/*  */
#define TLR_E_PNS_IF_MODULE              ((TLR_RESULT)0xC030007BL)

/*  */
/*  MessageId: TLR_E_PNS_IF_NO_AR */
/*  */
/*  MessageText: */
/*  */
/*   The AR was closed or the AR handle is not valid. */
/*  */
#define TLR_E_PNS_IF_NO_AR               ((TLR_RESULT)0xC030007CL)

/*  */
/*  MessageId: TLR_E_PNS_IF_WRITE_REC_RES_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Timeout while waiting for response to write_record_indication. */
/*  */
#define TLR_E_PNS_IF_WRITE_REC_RES_TIMEOUT ((TLR_RESULT)0xC030007DL)

/*  */
/*  MessageId: TLR_E_PNS_IF_UNREGISTERED_SENDER */
/*  */
/*  MessageText: */
/*  */
/*   The sender of the request in not registered with request PNS_IF_REGISTER_AP_REQ. */
/*  */
#define TLR_E_PNS_IF_UNREGISTERED_SENDER ((TLR_RESULT)0xC030007EL)

/*  */
/*  MessageId: TLR_E_PNS_IF_RECORD_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Unknown record handle. */
/*  */
#define TLR_E_PNS_IF_RECORD_HANDLE_INVALID ((TLR_RESULT)0xC030007FL)

/*  */
/*  MessageId: TLR_E_PNS_IF_REGISTER_AP */
/*  */
/*  MessageText: */
/*  */
/*   Another instance is registered at the moment. */
/*  */
#define TLR_E_PNS_IF_REGISTER_AP         ((TLR_RESULT)0xC0300080L)

/*  */
/*  MessageId: TLR_E_PNS_IF_UNREGISTER_AP */
/*  */
/*  MessageText: */
/*  */
/*   One instance can not unregister another one. */
/*  */
#define TLR_E_PNS_IF_UNREGISTER_AP       ((TLR_RESULT)0xC0300081L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CONFIG_DIFFER */
/*  */
/*  MessageText: */
/*  */
/*   The Must-configuration differs from the Is-configuration. */
/*  */
#define TLR_E_PNS_IF_CONFIG_DIFFER       ((TLR_RESULT)0xC0300082L)

/*  */
/*  MessageId: TLR_E_PNS_IF_NO_COMMUNICATION */
/*  */
/*  MessageText: */
/*  */
/*   No communication processing. */
/*  */
#define TLR_E_PNS_IF_NO_COMMUNICATION    ((TLR_RESULT)0xC0300083L)

/*  */
/*  MessageId: TLR_E_PNS_IF_BAD_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   At least one parameter in a packet was wrong or/and did not meet the requirements. */
/*  */
#define TLR_E_PNS_IF_BAD_PARAMETER       ((TLR_RESULT)0xC0300084L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AREA_OVERFLOW */
/*  */
/*  MessageText: */
/*  */
/*   Input or Output data requires more space than available. */
/*  */
#define TLR_E_PNS_IF_AREA_OVERFLOW       ((TLR_RESULT)0xC0300085L)

/*  */
/*  MessageId: TLR_E_PNS_IF_WRM_PCK_SAVE */
/*  */
/*  MessageText: */
/*  */
/*   Saving Warmstart Configuration for later use was not successful. */
/*  */
#define TLR_E_PNS_IF_WRM_PCK_SAVE        ((TLR_RESULT)0xC0300086L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_PULLPLUG */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Pull and Plug are forbidden after check.rsp and before in-data.ind. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_PULLPLUG  ((TLR_RESULT)0xC0300087L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_AP_RMV */
/*  */
/*  MessageText: */
/*  */
/*   AR error. AP has been removed. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_AP_RMV    ((TLR_RESULT)0xC0300088L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_LNK_DWN */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Link "down". */
/*  */
#define TLR_E_PNS_IF_AR_REASON_LNK_DWN   ((TLR_RESULT)0xC0300089L)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_MMAC */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Could not register multicast-MAC. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_MMAC      ((TLR_RESULT)0xC030008AL)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_SYNC */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Not synchronised(Cannot start companion-AR). */
/*  */
#define TLR_E_PNS_IF_AR_REASON_SYNC      ((TLR_RESULT)0xC030008BL)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_TOPO */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Wrong topology(Cannot start companion-AR). */
/*  */
#define TLR_E_PNS_IF_AR_REASON_TOPO      ((TLR_RESULT)0xC030008CL)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_DCP_NAME */
/*  */
/*  MessageText: */
/*  */
/*   AR error. DCP. Station Name changed. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_DCP_NAME  ((TLR_RESULT)0xC030008DL)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_DCP_RESET */
/*  */
/*  MessageText: */
/*  */
/*   AR error. DCP. Reset to factory-settings. */
/*  */
#define TLR_E_PNS_IF_AR_REASON_DCP_RESET ((TLR_RESULT)0xC030008EL)

/*  */
/*  MessageId: TLR_E_PNS_IF_AR_REASON_PRM */
/*  */
/*  MessageText: */
/*  */
/*   AR error. Cannot start companion-AR because a 0x8ipp submodule in the first AR /has appl-ready-pending/ is locked/ is wrong or pulled/ . */
/*  */
#define TLR_E_PNS_IF_AR_REASON_PRM       ((TLR_RESULT)0xC030008FL)

/*  */
/*  MessageId: TLR_E_PNS_IF_PACKET_MNGMNT */
/*  */
/*  MessageText: */
/*  */
/*   Packet management error. */
/*  */
#define TLR_E_PNS_IF_PACKET_MNGMNT       ((TLR_RESULT)0xC0300090L)

/*  */
/*  MessageId: TLR_E_PNS_IF_WRONG_API_NUM */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_WRONG_API_NUM       ((TLR_RESULT)0xC0300091L)

/*  */
/*  MessageId: TLR_E_PNS_IF_WRONG_MODULE_ID */
/*  */
/*  MessageText: */
/*  */
/*   d. */
/*  */
#define TLR_E_PNS_IF_WRONG_MODULE_ID     ((TLR_RESULT)0xC0300092L)

/*  */
/*  MessageId: TLR_E_PNS_IF_WRONG_MODULE_NUM */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_WRONG_MODULE_NUM    ((TLR_RESULT)0xC0300093L)

/*  */
/*  MessageId: TLR_E_PNS_IF_UNS_AREA */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_UNS_AREA            ((TLR_RESULT)0xC0300094L)

/*  */
/*  MessageId: TLR_E_PNS_IF_WRONG_SUB_ID */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_WRONG_SUB_ID        ((TLR_RESULT)0xC0300095L)

/*  */
/*  MessageId: TLR_E_PNS_IF_WRONG_SUBMODULE_NUM */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_WRONG_SUBMODULE_NUM ((TLR_RESULT)0xC0300096L)

/*  */
/*  MessageId: TLR_E_PNS_IF_DEVICE_STOP_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_DEVICE_STOP_FAILED  ((TLR_RESULT)0xC0300097L)

/*  */
/*  MessageId: TLR_E_PNS_IF_EDD_DISABLE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_EDD_DISABLE_FAILED  ((TLR_RESULT)0xC0300098L)

/*  */
/*  MessageId: TLR_E_PNS_IF_WRITE_IN */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_WRITE_IN            ((TLR_RESULT)0xC0300099L)

/*  */
/*  MessageId: TLR_E_PNS_IF_READ_OUT */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_READ_OUT            ((TLR_RESULT)0xC030009AL)

/*  */
/*  MessageId: TLR_E_PNS_IF_PNIO_STATUS */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_PNIO_STATUS         ((TLR_RESULT)0xC030009BL)

/*  */
/*  MessageId: TLR_E_PNS_IF_WRONG_MODULE_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_WRONG_MODULE_ADDRESS ((TLR_RESULT)0xC030009CL)

/*  */
/*  MessageId: TLR_E_PNS_IF_UNK_DEVICE_STATE */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_UNK_DEVICE_STATE    ((TLR_RESULT)0xC030009DL)

/*  */
/*  MessageId: TLR_E_PNS_IF_ALARM_DATA_LEN */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_ALARM_DATA_LEN      ((TLR_RESULT)0xC030009EL)

/*  */
/*  MessageId: TLR_E_PNS_IF_UNK_SUBMODULE_STATE */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_UNK_SUBMODULE_STATE ((TLR_RESULT)0xC030009FL)

/*  */
/*  MessageId: TLR_E_PNS_IF_BAD_DIAG_HANDLE */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_BAD_DIAG_HANDLE     ((TLR_RESULT)0xC03000A0L)

/*  */
/*  MessageId: TLR_E_PNS_IF_UNS_STRUCT_ID */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_UNS_STRUCT_ID       ((TLR_RESULT)0xC03000A1L)

/*  */
/*  MessageId: TLR_E_PNS_IF_UNK_ALARM_STATE */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_UNK_ALARM_STATE     ((TLR_RESULT)0xC03000A2L)

/*  */
/*  MessageId: TLR_E_PNS_IF_DIAG_DATA_LEN */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_DIAG_DATA_LEN       ((TLR_RESULT)0xC03000A3L)

/*  */
/*  MessageId: TLR_E_PNS_IF_BAD_CHANNEL_ERR_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_BAD_CHANNEL_ERR_TYPE ((TLR_RESULT)0xC03000A4L)

/*  */
/*  MessageId: TLR_E_PNS_IF_BAD_CHANNEL_PROP */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_BAD_CHANNEL_PROP    ((TLR_RESULT)0xC03000A5L)

/*  */
/*  MessageId: TLR_E_PNS_IF_BAD_CHANNEL_NUM */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_BAD_CHANNEL_NUM     ((TLR_RESULT)0xC03000A6L)

/*  */
/*  MessageId: TLR_E_PNS_IF_RCX_RESTART */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_RCX_RESTART         ((TLR_RESULT)0xC03000A7L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CFG_MNGMNT */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_CFG_MNGMNT          ((TLR_RESULT)0xC03000A8L)

/*  */
/*  MessageId: TLR_E_PNS_IF_UNK_INTERN_REQ */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_UNK_INTERN_REQ      ((TLR_RESULT)0xC03000A9L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CFG_STORE */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_CFG_STORE           ((TLR_RESULT)0xC03000AAL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CFG_DELETE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_CFG_DELETE_FAILED   ((TLR_RESULT)0xC03000ABL)

/*  */
/*  MessageId: TLR_E_PNS_IF_READ_CFG */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_READ_CFG            ((TLR_RESULT)0xC03000ACL)

/*  */
/*  MessageId: TLR_E_PNS_IF_ACCESS_SYS_VOLUME */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_ACCESS_SYS_VOLUME   ((TLR_RESULT)0xC03000ADL)

/*  */
/*  MessageId: TLR_E_PNS_IF_ACCESS_BCKUP_VOLUME */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_ACCESS_BCKUP_VOLUME ((TLR_RESULT)0xC03000AEL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CFG_BAD_LEN */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_CFG_BAD_LEN         ((TLR_RESULT)0xC03000AFL)

/*  */
/*  MessageId: TLR_E_PNS_IF_WRM_CFG_MNGMNT */
/*  */
/*  MessageText: */
/*  */
/*   dd. */
/*  */
#define TLR_E_PNS_IF_WRM_CFG_MNGMNT      ((TLR_RESULT)0xC03000B0L)

/*  */
/*  MessageId: TLR_E_PNS_IF_RESET_FACTORY_IND */
/*  */
/*  MessageText: */
/*  */
/*   No registered application. Reset_to_factory_settings Indication failed. */
/*  */
#define TLR_E_PNS_IF_RESET_FACTORY_IND   ((TLR_RESULT)0xC03000B1L)

/*  */
/*  MessageId: TLR_E_PNS_IF_MODULE_ALREADY_PLUGGED */
/*  */
/*  MessageText: */
/*  */
/*   A module was already plugged to the slot. */
/*  */
#define TLR_E_PNS_IF_MODULE_ALREADY_PLUGGED ((TLR_RESULT)0xC03000B2L)

/*  */
/*  MessageId: TLR_E_PNS_IF_OSINIT */
/*  */
/*  MessageText: */
/*  */
/*   Failed to init the OS adaptation layer. */
/*  */
#define TLR_E_PNS_IF_OSINIT              ((TLR_RESULT)0xC03000B3L)

/*  */
/*  MessageId: TLR_E_PNS_IF_OSSOCKINIT */
/*  */
/*  MessageText: */
/*  */
/*   Failed to init the TCPIP adaptation layer. */
/*  */
#define TLR_E_PNS_IF_OSSOCKINIT          ((TLR_RESULT)0xC03000B4L)

/*  */
/*  MessageId: TLR_E_PNS_IF_INVALID_NETMASK */
/*  */
/*  MessageText: */
/*  */
/*   Invalid subnetwork mask. */
/*  */
#define TLR_E_PNS_IF_INVALID_NETMASK     ((TLR_RESULT)0xC03000B5L)

/*  */
/*  MessageId: TLR_E_PNS_IF_INVALID_IP_ADDR */
/*  */
/*  MessageText: */
/*  */
/*   Invalid IP address. */
/*  */
#define TLR_E_PNS_IF_INVALID_IP_ADDR     ((TLR_RESULT)0xC03000B6L)

/*  */
/*  MessageId: TLR_E_PNS_IF_STA_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Erroneous Task start-up parameters. */
/*  */
#define TLR_E_PNS_IF_STA_STARTUP_PARAMETER ((TLR_RESULT)0xC03000B7L)

/*  */
/*  MessageId: TLR_E_PNS_IF_INIT_LOCAL */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize the Task local resources. */
/*  */
#define TLR_E_PNS_IF_INIT_LOCAL          ((TLR_RESULT)0xC03000B8L)

/*  */
/*  MessageId: TLR_E_PNS_IF_APP_CONFIG_INCOMPLETE */
/*  */
/*  MessageText: */
/*  */
/*   The configuration per packets is incomplete. */
/*  */
#define TLR_E_PNS_IF_APP_CONFIG_INCOMPLETE ((TLR_RESULT)0xC03000B9L)

/*  */
/*  MessageId: TLR_E_PNS_IF_INIT_EDD */
/*  */
/*  MessageText: */
/*  */
/*   EDD Initialization failed. */
/*  */
#define TLR_E_PNS_IF_INIT_EDD            ((TLR_RESULT)0xC03000BAL)

/*  */
/*  MessageId: TLR_E_PNS_IF_DPM_NOT_ENABLED */
/*  */
/*  MessageText: */
/*  */
/*   DPM is not enabled. */
/*  */
#define TLR_E_PNS_IF_DPM_NOT_ENABLED     ((TLR_RESULT)0xC03000BBL)

/*  */
/*  MessageId: TLR_E_PNS_IF_READ_LINK_STATUS */
/*  */
/*  MessageText: */
/*  */
/*   Reading Link Status failed. */
/*  */
#define TLR_E_PNS_IF_READ_LINK_STATUS    ((TLR_RESULT)0xC03000BCL)

/*  */
/*  MessageId: TLR_E_PNS_IF_INVALID_GATEWAY */
/*  */
/*  MessageText: */
/*  */
/*   Invalid gateway address (not reachable with configured netmask). */
/*  */
#define TLR_E_PNS_IF_INVALID_GATEWAY     ((TLR_RESULT)0xC03000BDL)

/*  these #defines are from Benjamin - for use with new PNIO stack (none-Siemens) */
/*  */
/*  MessageId: TLR_E_PNS_IF_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Error while sending a packet to another task. */
/*  */
#define TLR_E_PNS_IF_PACKET_SEND_FAILED  ((TLR_RESULT)0xC0300100L)

/*  */
/*  MessageId: TLR_E_PNS_IF_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Unsufficient memory to handle the request. */
/*  */
#define TLR_E_PNS_IF_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0300101L)

/*  */
/*  MessageId: TLR_E_PNS_IF_NO_APPLICATION_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   No application to send the indication to is registered. */
/*  */
#define TLR_E_PNS_IF_NO_APPLICATION_REGISTERED ((TLR_RESULT)0xC0300102L)

/*  */
/*  MessageId: TLR_E_PNS_IF_INVALID_SOURCE_ID */
/*  */
/*  MessageText: */
/*  */
/*   The host-application returned a packet with invalid (changed) SourceID. */
/*  */
#define TLR_E_PNS_IF_INVALID_SOURCE_ID   ((TLR_RESULT)0xC0300103L)

/*  */
/*  MessageId: TLR_E_PNS_IF_PACKET_BUFFER_FULL */
/*  */
/*  MessageText: */
/*  */
/*   The buffer used to store packets exchanged between host-application and stack is full. */
/*  */
#define TLR_E_PNS_IF_PACKET_BUFFER_FULL  ((TLR_RESULT)0xC0300104L)

/*  */
/*  MessageId: TLR_E_PNS_IF_PULL_NO_MODULE */
/*  */
/*  MessageText: */
/*  */
/*   Pulling the (sub)module failed because no module is plugged into the slot specified. */
/*  */
#define TLR_E_PNS_IF_PULL_NO_MODULE      ((TLR_RESULT)0xC0300105L)

/*  */
/*  MessageId: TLR_E_PNS_IF_PULL_NO_SUBMODULE */
/*  */
/*  MessageText: */
/*  */
/*   Pulling the submodule failed because no submodule is plugged into the subslot specified. */
/*  */
#define TLR_E_PNS_IF_PULL_NO_SUBMODULE   ((TLR_RESULT)0xC0300106L)

/*  */
/*  MessageId: TLR_E_PNS_IF_PACKET_BUFFER_RESTORE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   The packet buffer storing packets exchanged between host-application and stack returned an invalid packet. */
/*  */
#define TLR_E_PNS_IF_PACKET_BUFFER_RESTORE_ERROR ((TLR_RESULT)0xC0300107L)

/*  */
/*  MessageId: TLR_E_PNS_IF_DIAG_NO_MODULE */
/*  */
/*  MessageText: */
/*  */
/*   Diagnosis data not accepted because no module is plugged into the slot specified. */
/*  */
#define TLR_E_PNS_IF_DIAG_NO_MODULE      ((TLR_RESULT)0xC0300108L)

/*  */
/*  MessageId: TLR_E_PNS_IF_DIAG_NO_SUBMODULE */
/*  */
/*  MessageText: */
/*  */
/*   Diagnosis data not accepted because no submodule is plugged into the subslot specified. */
/*  */
#define TLR_E_PNS_IF_DIAG_NO_SUBMODULE   ((TLR_RESULT)0xC0300109L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CYCLIC_EXCHANGE_ACTIVE */
/*  */
/*  MessageText: */
/*  */
/*   The services requested is not available while cyclic communication is running. */
/*  */
#define TLR_E_PNS_IF_CYCLIC_EXCHANGE_ACTIVE ((TLR_RESULT)0xC030010AL)

/*  */
/*  MessageId: TLR_E_PNS_IF_FATAL_ERROR_CLB_ALREADY_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   This fatal error callback function could not be registered because there is already a function registered. */
/*  */
#define TLR_E_PNS_IF_FATAL_ERROR_CLB_ALREADY_REGISTERED ((TLR_RESULT)0xC030010BL)

/*  */
/*  MessageId: TLR_E_PNS_IF_ERROR_STACK_WARMSTART_CONFIGURATION */
/*  */
/*  MessageText: */
/*  */
/*   The stack did not accept the warmstart parameters. */
/*  */
#define TLR_E_PNS_IF_ERROR_STACK_WARMSTART_CONFIGURATION ((TLR_RESULT)0xC030010CL)

/*  */
/*  MessageId: TLR_E_PNS_IF_ERROR_STACK_MODULE_CONFIGURATION */
/*  */
/*  MessageText: */
/*  */
/*   The stack did not accept the module configuration packet. */
/*  */
#define TLR_E_PNS_IF_ERROR_STACK_MODULE_CONFIGURATION ((TLR_RESULT)0xC030010DL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CHECK_IND_FOR_UNEXPECTED_MODULE */
/*  */
/*  MessageText: */
/*  */
/*   The stack sent a Check Indication for an unexpected module. This module was not part of the CR Info Indication. */
/*  */
#define TLR_E_PNS_IF_CHECK_IND_FOR_UNEXPECTED_MODULE ((TLR_RESULT)0xC030010EL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CHECK_IND_FOR_UNEXPECTED_SUBMODULE */
/*  */
/*  MessageText: */
/*  */
/*   The stack sent a Check Indication for an unexpected submodule. This submodule was not part of the CR Info Indication. */
/*  */
#define TLR_E_PNS_IF_CHECK_IND_FOR_UNEXPECTED_SUBMODULE ((TLR_RESULT)0xC030010FL)

/*  */
/*  MessageId: TLR_E_PNS_DIAG_BUFFER_FULL */
/*  */
/*  MessageText: */
/*  */
/*   No more diagnosis records can be added to the stack because the maximum amount is already reached. */
/*  */
#define TLR_E_PNS_DIAG_BUFFER_FULL       ((TLR_RESULT)0xC0300110L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CHECK_IND_FOR_UNEXPECTED_API */
/*  */
/*  MessageText: */
/*  */
/*   The stack sent a Check Indication for an unexpected API. This API was not part of the CR Info Indication. */
/*  */
#define TLR_E_PNS_IF_CHECK_IND_FOR_UNEXPECTED_API ((TLR_RESULT)0xC0300111L)

/*  */
/*  MessageId: TLR_E_PNS_IF_DPM_ACCESS_WITH_INVALID_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   The DPM shall be accessed with an invalid data offset. */
/*  */
#define TLR_E_PNS_IF_DPM_ACCESS_WITH_INVALID_OFFSET ((TLR_RESULT)0xC0300112L)

/*  */
/*  MessageId: TLR_E_PNS_IF_DUPLICATE_INPUT_CR_INFO */
/*  */
/*  MessageText: */
/*  */
/*   The stack indicated to CR Info Indications with type input. */
/*  */
#define TLR_E_PNS_IF_DUPLICATE_INPUT_CR_INFO ((TLR_RESULT)0xC0300113L)

/*  */
/*  MessageId: TLR_E_PNS_IF_DUPLICATE_OUTPUT_CR_INFO */
/*  */
/*  MessageText: */
/*  */
/*   The stack indicated to CR Info Indications with type output. */
/*  */
#define TLR_E_PNS_IF_DUPLICATE_OUTPUT_CR_INFO ((TLR_RESULT)0xC0300114L)

/*  */
/*  MessageId: TLR_E_PNS_IF_FAULTY_CR_INFO_IND_RECEIVED */
/*  */
/*  MessageText: */
/*  */
/*   The stack indicated a faulty CR Info Indications. */
/*  */
#define TLR_E_PNS_IF_FAULTY_CR_INFO_IND_RECEIVED ((TLR_RESULT)0xC0300115L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CONFIG_RELOAD_RUNNING */
/*  */
/*  MessageText: */
/*  */
/*   The request can not be executed because configuration reload respectively ChannelInit is running. */
/*  */
#define TLR_E_PNS_IF_CONFIG_RELOAD_RUNNING ((TLR_RESULT)0xC0300116L)

/*  */
/*  MessageId: TLR_E_PNS_IF_NO_MAC_ADDRESS_SET */
/*  */
/*  MessageText: */
/*  */
/*   There is no valid chassis MAC address set Without MAC address the stack will not work. */
/*  */
#define TLR_E_PNS_IF_NO_MAC_ADDRESS_SET  ((TLR_RESULT)0xC0300117L)

/*  */
/*  MessageId: TLR_E_PNS_IF_SET_PORT_MAC_NOT_POSSIBLE */
/*  */
/*  MessageText: */
/*  */
/*   The Port MAC addresses have to be set before sending Set-Configuration Request to the stack. */
/*  */
#define TLR_E_PNS_IF_SET_PORT_MAC_NOT_POSSIBLE ((TLR_RESULT)0xC0300118L)

/*  */
/*  MessageId: TLR_E_PNS_IF_INVALID_MODULE_CONFIGURATION */
/*  */
/*  MessageText: */
/*  */
/*   Evaluating the module configuration failed. */
/*  */
#define TLR_E_PNS_IF_INVALID_MODULE_CONFIGURATION ((TLR_RESULT)0xC030011AL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CONF_IO_LEN_TO_BIG */
/*  */
/*  MessageText: */
/*  */
/*   The sum of IO-data length exceeds the maximum allowed value. */
/*  */
#define TLR_E_PNS_IF_CONF_IO_LEN_TO_BIG  ((TLR_RESULT)0xC030011BL)

/*  */
/*  MessageId: TLR_E_PNS_IF_NO_MODULE_CONFIGURED */
/*  */
/*  MessageText: */
/*  */
/*   The module configuration does not contain at least one module. */
/*  */
#define TLR_E_PNS_IF_NO_MODULE_CONFIGURED ((TLR_RESULT)0xC030011CL)

/*  */
/*  MessageId: TLR_E_PNS_IF_INVALID_SW_REV_PREFIX */
/*  */
/*  MessageText: */
/*  */
/*   The value of bSwRevisionPrefix is invalid. */
/*  */
#define TLR_E_PNS_IF_INVALID_SW_REV_PREFIX ((TLR_RESULT)0xC030011DL)

/*  */
/*  MessageId: TLR_E_PNS_IF_RESERVED_VALUE_NOT_ZERO */
/*  */
/*  MessageText: */
/*  */
/*   The value of usReserved it not zero. */
/*  */
#define TLR_E_PNS_IF_RESERVED_VALUE_NOT_ZERO ((TLR_RESULT)0xC030011EL)

/*  */
/*  MessageId: TLR_E_PNS_IF_IDENTIFY_CMDEV_QUEUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Identifying the stack message queue CMDEV failed. */
/*  */
#define TLR_E_PNS_IF_IDENTIFY_CMDEV_QUEUE_FAILED ((TLR_RESULT)0xC030011FL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CREATE_SYNC_QUEUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creating the sync message queue failed. */
/*  */
#define TLR_E_PNS_IF_CREATE_SYNC_QUEUE_FAILED ((TLR_RESULT)0xC0300120L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CREATE_ALARM_LOW_QUEUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creating the low alarm message queue failed. */
/*  */
#define TLR_E_PNS_IF_CREATE_ALARM_LOW_QUEUE_FAILED ((TLR_RESULT)0xC0300121L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CREATE_ALARM_HIGH_QUEUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creating the high alarm message queue failed. */
/*  */
#define TLR_E_PNS_IF_CREATE_ALARM_HIGH_QUEUE_FAILED ((TLR_RESULT)0xC0300122L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CFG_PACKET_TO_SMALL */
/*  */
/*  MessageText: */
/*  */
/*   While evaulating SetConfiguration packet the packet length was found smaller than amount of configured modules needs. */
/*  */
#define TLR_E_PNS_IF_CFG_PACKET_TO_SMALL ((TLR_RESULT)0xC0300123L)

/*  */
/*  MessageId: TLR_E_PNS_IF_FATAL_ERROR_OCCURRED */
/*  */
/*  MessageText: */
/*  */
/*   A fatal error occurred prior to this request. Therefore this request can not be fullfiled. */
/*  */
#define TLR_E_PNS_IF_FATAL_ERROR_OCCURRED ((TLR_RESULT)0xC0300124L)

/*  */
/*  MessageId: TLR_E_PNS_IF_SUBMODULE_NOT_IN_CYCLIC_EXCHANGE */
/*  */
/*  MessageText: */
/*  */
/*   The request could not be executed because the submodule is not in cyclic dataexchange. */
/*  */
#define TLR_E_PNS_IF_SUBMODULE_NOT_IN_CYCLIC_EXCHANGE ((TLR_RESULT)0xC0300125L)

/*  */
/*  MessageId: TLR_E_PNS_IF_SERVICE_NOT_AVAILABLE_THROUGH_DPM */
/*  */
/*  MessageText: */
/*  */
/*   This service is not available through DPM. */
/*  */
#define TLR_E_PNS_IF_SERVICE_NOT_AVAILABLE_THROUGH_DPM ((TLR_RESULT)0xC0300126L)

/*  */
/*  MessageId: TLR_E_PNS_IF_INVALID_PARAMETER_VERSION */
/*  */
/*  MessageText: */
/*  */
/*   The version of parameters is invalid (most likely too old). */
/*  */
#define TLR_E_PNS_IF_INVALID_PARAMETER_VERSION ((TLR_RESULT)0xC0300127L)

/*  */
/*  MessageId: TLR_E_PNS_IF_DATABASE_USAGE_IS_FORBIDDEN */
/*  */
/*  MessageText: */
/*  */
/*   The usage of database is forbidden by task's startup parameters. */
/*  */
#define TLR_E_PNS_IF_DATABASE_USAGE_IS_FORBIDDEN ((TLR_RESULT)0xC0300128L)

/*  */
/*  MessageId: TLR_E_PNS_IF_RECORD_LENGTH_TOO_BIG */
/*  */
/*  MessageText: */
/*  */
/*   The amount of record data is too big. */
/*  */
#define TLR_E_PNS_IF_RECORD_LENGTH_TOO_BIG ((TLR_RESULT)0xC0300129L)

/*  */
/*  MessageId: TLR_E_PNS_IF_IDENTIFY_LLDP_QUEUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Identifying the stack message queue LLDP failed. */
/*  */
#define TLR_E_PNS_IF_IDENTIFY_LLDP_QUEUE_FAILED ((TLR_RESULT)0xC030012AL)

/*  */
/*  MessageId: TLR_E_PNS_IF_INVALID_TOTAL_PACKET_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   SetConfiguration Requests total packet length is invalid. */
/*  */
#define TLR_E_PNS_IF_INVALID_TOTAL_PACKET_LENGTH ((TLR_RESULT)0xC030012BL)

/*  */
/*  MessageId: TLR_E_PNS_IF_APPLICATION_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   The application needed to much time to respond to an indication. */
/*  */
#define TLR_E_PNS_IF_APPLICATION_TIMEOUT ((TLR_RESULT)0xC030012CL)

/*  */
/*  MessageId: TLR_E_PNS_IF_PACKET_BUFFER_INVALID_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   The packet buffer storing packets exchanged between host-application and stack returned a faulty packet. */
/*  */
#define TLR_E_PNS_IF_PACKET_BUFFER_INVALID_PACKET ((TLR_RESULT)0xC030012DL)

/*  */
/*  MessageId: TLR_E_PNS_IF_NO_IO_IMAGE_CONFIGURATION_AVAILABLE */
/*  */
/*  MessageText: */
/*  */
/*   The request can not be handled until a valid IO Image configuration is available. */
/*  */
#define TLR_E_PNS_IF_NO_IO_IMAGE_CONFIGURATION_AVAILABLE ((TLR_RESULT)0xC030012EL)

/*  */
/*  MessageId: TLR_E_PNS_IF_IO_IMAGE_ALREADY_CONFIGURED */
/*  */
/*  MessageText: */
/*  */
/*   A valid IO Image configuration is already available. */
/*  */
#define TLR_E_PNS_IF_IO_IMAGE_ALREADY_CONFIGURED ((TLR_RESULT)0xC030012FL)

/*  */
/*  MessageId: TLR_E_PNS_IF_INVALID_PDEV_SUBSLOT */
/*  */
/*  MessageText: */
/*  */
/*   A submodule may only be plugged into a PDEV-subslot which does not exceed the number of supported interfaces and portnumbers. */
/*  */
#define TLR_E_PNS_IF_INVALID_PDEV_SUBSLOT ((TLR_RESULT)0xC0300130L)

/*  */
/*  MessageId: TLR_E_PNS_IF_NO_DAP_PRESENT */
/*  */
/*  MessageText: */
/*  */
/*   The module configuration does not contain a the Device Access Point DAP-submodule in slot 0 subslot 1. */
/*  */
#define TLR_E_PNS_IF_NO_DAP_PRESENT      ((TLR_RESULT)0xC0300131L)

/*  START: On 12.11.08 Konstantin added: Area for Abort- and Offline- Reason error codes to support Siemens Stack */
/*  MessageId = 0x0A00 - 0x0AFF */
/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_NONE */
/*  */
/*  MessageText: */
/*  */
/*   None. Unused. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_NONE   ((TLR_RESULT)0xC0300A00L)

/* MessageId       = 0x0A01 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_PNS_IF */
/* SymbolicName    = TLR_E_PNS_IF_ */
/* Language        = English */
/* . */
/* . */
/* Language        = German */
/* . */
/* . */
/*  */
/* MessageId       = 0x0A02 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_PNS_IF */
/* SymbolicName    = TLR_E_PNS_IF_ */
/* Language        = English */
/* . */
/* . */
/* Language        = German */
/* . */
/* . */
/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_MEM */
/*  */
/*  MessageText: */
/*  */
/*   AR Out of memory. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_MEM    ((TLR_RESULT)0xC0300A03L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_FRAME */
/*  */
/*  MessageText: */
/*  */
/*   AR add provider or consumer failed. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_FRAME  ((TLR_RESULT)0xC0300A04L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_MISS */
/*  */
/*  MessageText: */
/*  */
/*   AR consumer DHT/WDT expired. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_MISS   ((TLR_RESULT)0xC0300A05L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_TIMER */
/*  */
/*  MessageText: */
/*  */
/*   AR cmi timeout. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_TIMER  ((TLR_RESULT)0xC0300A06L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_ALARM */
/*  */
/*  MessageText: */
/*  */
/*   AR alarm-open failed. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_ALARM  ((TLR_RESULT)0xC0300A07L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_ALSND */
/*  */
/*  MessageText: */
/*  */
/*   AR alarm-send.cnf(-). */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_ALSND  ((TLR_RESULT)0xC0300A08L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_ALACK */
/*  */
/*  MessageText: */
/*  */
/*   AR alarm-ack-send.cnf(-). */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_ALACK  ((TLR_RESULT)0xC0300A09L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_ALLEN */
/*  */
/*  MessageText: */
/*  */
/*   AR alarm data too long. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_ALLEN  ((TLR_RESULT)0xC0300A0AL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_ASRT */
/*  */
/*  MessageText: */
/*  */
/*   AR alarm.ind(err). */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_ASRT   ((TLR_RESULT)0xC0300A0BL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_RPC */
/*  */
/*  MessageText: */
/*  */
/*   AR rpc-client call.cnf(-). */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_RPC    ((TLR_RESULT)0xC0300A0CL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_ABORT */
/*  */
/*  MessageText: */
/*  */
/*   AR abort.req. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_ABORT  ((TLR_RESULT)0xC0300A0DL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_RERUN */
/*  */
/*  MessageText: */
/*  */
/*   AR re-run aborts existing AR. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_RERUN  ((TLR_RESULT)0xC0300A0EL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_REL */
/*  */
/*  MessageText: */
/*  */
/*   AR release.ind received. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_REL    ((TLR_RESULT)0xC0300A0FL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_PAS */
/*  */
/*  MessageText: */
/*  */
/*   AR device deactivated. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_PAS    ((TLR_RESULT)0xC0300A10L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_RMV */
/*  */
/*  MessageText: */
/*  */
/*   AR removed. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_RMV    ((TLR_RESULT)0xC0300A11L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_PROT */
/*  */
/*  MessageText: */
/*  */
/*   AR protocol violation. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_PROT   ((TLR_RESULT)0xC0300A12L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_NARE */
/*  */
/*  MessageText: */
/*  */
/*   AR name resolution error. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_NARE   ((TLR_RESULT)0xC0300A13L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_BIND */
/*  */
/*  MessageText: */
/*  */
/*   AR RPC-Bind error. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_BIND   ((TLR_RESULT)0xC0300A14L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   AR RPC-Connect error. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_CONNECT ((TLR_RESULT)0xC0300A15L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_READ */
/*  */
/*  MessageText: */
/*  */
/*   AR RPC-Read error. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_READ   ((TLR_RESULT)0xC0300A16L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_WRITE */
/*  */
/*  MessageText: */
/*  */
/*   AR RPC-Write error. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_WRITE  ((TLR_RESULT)0xC0300A17L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_CONTROL */
/*  */
/*  MessageText: */
/*  */
/*   AR RPC-Control error. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_CONTROL ((TLR_RESULT)0xC0300A18L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_PULLPLUG */
/*  */
/*  MessageText: */
/*  */
/*   AR forbidden pull or plug after check.rsp and before in-data.ind. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_PULLPLUG ((TLR_RESULT)0xC0300A19L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_AP_RMV */
/*  */
/*  MessageText: */
/*  */
/*   AR AP removed. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_AP_RMV ((TLR_RESULT)0xC0300A1AL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_LNK_DWN */
/*  */
/*  MessageText: */
/*  */
/*   AR link down. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_LNK_DWN ((TLR_RESULT)0xC0300A1BL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_MMAC */
/*  */
/*  MessageText: */
/*  */
/*   AR could not register multicast-mac address. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_MMAC   ((TLR_RESULT)0xC0300A1CL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_SYNC */
/*  */
/*  MessageText: */
/*  */
/*   Not synchronized (cannot start companion-ar). */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_SYNC   ((TLR_RESULT)0xC0300A1DL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_TOPO */
/*  */
/*  MessageText: */
/*  */
/*   Wrong topology (cannot start companion-ar). */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_TOPO   ((TLR_RESULT)0xC0300A1EL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_DCP_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DCP, station-name changed. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_DCP_NAME ((TLR_RESULT)0xC0300A1FL)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_DCP_RESET */
/*  */
/*  MessageText: */
/*  */
/*   DCP, reset to factory-settings. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_DCP_RESET ((TLR_RESULT)0xC0300A20L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_PRM */
/*  */
/*  MessageText: */
/*  */
/*   0x8ipp submodule in the first AR has either an appl-ready-pending (erroneous parameterisation) or is locked (no parameterisation) or is wrong or pulled (no parameterisation). */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_PRM    ((TLR_RESULT)0xC0300A21L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_IRDATA */
/*  */
/*  MessageText: */
/*  */
/*   No irdata record yet. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_IRDATA ((TLR_RESULT)0xC0300A22L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_PDEV */
/*  */
/*  MessageText: */
/*  */
/*   Ownership of PDEV. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_PDEV   ((TLR_RESULT)0xC0300A23L)

/*  */
/*  MessageId: TLR_E_PNS_IF_CM_AR_REASON_MAX */
/*  */
/*  MessageText: */
/*  */
/*   Max. Unused. */
/*  */
#define TLR_E_PNS_IF_CM_AR_REASON_MAX    ((TLR_RESULT)0xC0300AFFL)

/*  END: On 12.11.08 Konstantin added: Area for Abort- and Offline- Reason error codes to support Siemens Stack */
/*  MessageId = 0x0A00 - 0x0AFF */



#endif  /* __PNS_ERROR_H */

#ifndef __PROFIBUS_APM_ERROR_H
#define __PROFIBUS_APM_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFIBUS Master APM Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PROFIBUS_APM_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_PROFIBUS_APM_COMMAND_INVALID ((TLR_RESULT)0xC0390001L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_APM_COMMAND_ALREADY_IN_RQUEST */
/*  */
/*  MessageText: */
/*  */
/*   Command already in request. */
/*  */
#define TLR_E_PROFIBUS_APM_COMMAND_ALREADY_IN_RQUEST ((TLR_RESULT)0xC0390002L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_APM_TIO_RESET_W_MODE_STOP */
/*  */
/*  MessageText: */
/*  */
/*   Timeout while stopping PROFIBUS. */
/*  */
#define TLR_E_PROFIBUS_APM_TIO_RESET_W_MODE_STOP ((TLR_RESULT)0xC0390003L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_APM_TIO_RESET_W_INIT_FSPMM */
/*  */
/*  MessageText: */
/*  */
/*   Timeout while resetting PROFIBUS. */
/*  */
#define TLR_E_PROFIBUS_APM_TIO_RESET_W_INIT_FSPMM ((TLR_RESULT)0xC0390004L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_APM_NON_EXCHANGE_SLAVE */
/*  */
/*  MessageText: */
/*  */
/*   No data exchange with at least one slave. */
/*  */
#define TLR_E_PROFIBUS_APM_NON_EXCHANGE_SLAVE ((TLR_RESULT)0xC0390005L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_APM_NON_EXCHANGE_ALL */
/*  */
/*  MessageText: */
/*  */
/*   No slave in data exchange. */
/*  */
#define TLR_E_PROFIBUS_APM_NON_EXCHANGE_ALL ((TLR_RESULT)0xC0390006L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_APM_CONFIG_LOCK */
/*  */
/*  MessageText: */
/*  */
/*   Configuration locked . */
/*  */
#define TLR_E_PROFIBUS_APM_CONFIG_LOCK   ((TLR_RESULT)0xC0390007L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_APM_CONFIG_VIA_DBM */
/*  */
/*  MessageText: */
/*  */
/*   Already configured via data base. */
/*  */
#define TLR_E_PROFIBUS_APM_CONFIG_VIA_DBM ((TLR_RESULT)0xC0390008L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_APM_ALREADY_CONFIGURED */
/*  */
/*  MessageText: */
/*  */
/*   Already configured. */
/*  */
#define TLR_E_PROFIBUS_APM_ALREADY_CONFIGURED ((TLR_RESULT)0xC0390009L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_APM_CHANNEL_INIT_IN_PROGRESS */
/*  */
/*  MessageText: */
/*  */
/*   Channel initialization in progress. */
/*  */
#define TLR_E_PROFIBUS_APM_CHANNEL_INIT_IN_PROGRESS ((TLR_RESULT)0xC039000AL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_APM_CHANNEL_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Channel initialization failed. */
/*  */
#define TLR_E_PROFIBUS_APM_CHANNEL_INIT_FAILED ((TLR_RESULT)0xC039000BL)




#endif  /* __PROFIBUS_APM_ERROR_H */

#ifndef __PROFIBUS_APS_ERROR_H
#define __PROFIBUS_APS_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFIBUS APS Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PROFIBUS_APS_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_PROFIBUS_APS_COMMAND_INVALID ((TLR_RESULT)0xC01D0001L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_APS_ALREADY_CONFIGURED */
/*  */
/*  MessageText: */
/*  */
/*   Device is already configured. The new configuration is discard. */
/*  */
#define TLR_E_PROFIBUS_APS_ALREADY_CONFIGURED ((TLR_RESULT)0xC01D0002L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_APS_NO_CONFIG_DBM */
/*  */
/*  MessageText: */
/*  */
/*   No database available. */
/*  */
#define TLR_E_PROFIBUS_APS_NO_CONFIG_DBM ((TLR_RESULT)0xC01D0003L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_APS_CONFIG_DBM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Database is invalid. */
/*  */
#define TLR_E_PROFIBUS_APS_CONFIG_DBM_INVALID ((TLR_RESULT)0xC01D0004L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_APS_CONFIG_MODULE_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Modul configuration consists invalid length. */
/*  */
#define TLR_E_PROFIBUS_APS_CONFIG_MODULE_LENGTH ((TLR_RESULT)0xC01D0005L)




#endif  /* __PROFIBUS_APS_ERROR_H */

#ifndef __PROFIBUS_DL_ERROR_H
#define __PROFIBUS_DL_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFIBUS DL Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_PROFIBUS_DL_COMMAND_INVALID ((TLR_RESULT)0xC0060001L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_XC_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The assigned XC-Data Link Layer is not installed or has a pending error. */
/*  */
#define TLR_E_PROFIBUS_DL_XC_INVALID     ((TLR_RESULT)0xC0060040L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_BAUDRATE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The specified baudrate option is not supported and is out of range. */
/*  */
#define TLR_E_PROFIBUS_DL_BAUDRATE_INVALID ((TLR_RESULT)0xC0060041L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_GAP_UPDATE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The specified GAP update factor option is not supported and is out of range 1-100. */
/*  */
#define TLR_E_PROFIBUS_DL_GAP_UPDATE_INVALID ((TLR_RESULT)0xC0060042L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_DL_ADDR_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The specified local profibus address option is not supported and is out of range 0-125. */
/*  */
#define TLR_E_PROFIBUS_DL_DL_ADDR_INVALID ((TLR_RESULT)0xC0060043L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_RETRY_LIMIT */
/*  */
/*  MessageText: */
/*  */
/*   The specified retry limit option is not supported and is zero. */
/*  */
#define TLR_E_PROFIBUS_DL_RETRY_LIMIT    ((TLR_RESULT)0xC0060044L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_HSA_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The specified highest station address option is not supported and is out of range 0-126. */
/*  */
#define TLR_E_PROFIBUS_DL_HSA_INVALID    ((TLR_RESULT)0xC0060045L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_NO_BUS_PARAMETER_SET */
/*  */
/*  MessageText: */
/*  */
/*   The service can not be executed, there are no bus parameter specified yet. */
/*  */
#define TLR_E_PROFIBUS_DL_NO_BUS_PARAMETER_SET ((TLR_RESULT)0xC0060046L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_DLE_NOT_RESPONDING */
/*  */
/*  MessageText: */
/*  */
/*   The service has detected a timeout at the connected XC-Data Link Layer entity. */
/*  */
#define TLR_E_PROFIBUS_DL_DLE_NOT_RESPONDING ((TLR_RESULT)0xC0060047L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_NO_DL_RESOURCE */
/*  */
/*  MessageText: */
/*  */
/*   There are no further resource blocks available to execute the service within the connected XC-Data Link Layer entity. */
/*  */
#define TLR_E_PROFIBUS_DL_NO_DL_RESOURCE ((TLR_RESULT)0xC0060048L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_FATAL_DL_RESOURCE */
/*  */
/*  MessageText: */
/*  */
/*   There are no further resource blocks available to execute the service within the connected XC-Data Link Layer entity. */
/*  */
#define TLR_E_PROFIBUS_DL_FATAL_DL_RESOURCE ((TLR_RESULT)0xC0060049L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_STOPPED */
/*  */
/*  MessageText: */
/*  */
/*   Profibus is stopped command can not be handled. */
/*  */
#define TLR_E_PROFIBUS_DL_STOPPED        ((TLR_RESULT)0xC0060050L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_PENDING_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Previous pending packet is returned. It could not be handled.  */
/*  */
#define TLR_E_PROFIBUS_DL_PENDING_PACKET ((TLR_RESULT)0xC0060051L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_SLAVE_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Command could not be executed, DL-task is running at slave mode. */
/*  */
#define TLR_E_PROFIBUS_DL_SLAVE_MODE     ((TLR_RESULT)0xC0060052L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_ACK_UE */
/*  */
/*  MessageText: */
/*  */
/*   The remote station the service has been sent to indicates a User Error as service acknowlegdement. */
/*  */
#define TLR_E_PROFIBUS_DL_ACK_UE         ((TLR_RESULT)0xC0060080L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_ACK_RR */
/*  */
/*  MessageText: */
/*  */
/*   The remote station the service has been sent to indicates a Resource Error as service acknowlegdement. */
/*  */
#define TLR_E_PROFIBUS_DL_ACK_RR         ((TLR_RESULT)0xC0060081L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_ACK_RS */
/*  */
/*  MessageText: */
/*  */
/*   The remote station the service has been sent to indicates a Service Access Point Error as service acknowlegdement. */
/*  */
#define TLR_E_PROFIBUS_DL_ACK_RS         ((TLR_RESULT)0xC0060082L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_ACK_NR */
/*  */
/*  MessageText: */
/*  */
/*   The remote station the service has been sent to confirms its positive reception but has no data to confirm. */
/*  */
#define TLR_E_PROFIBUS_DL_ACK_NR         ((TLR_RESULT)0xC0060083L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_ACK_RDH */
/*  */
/*  MessageText: */
/*  */
/*   The remote station the service has been sent to, confirms its reception negatively but has returned high priority data in the response. */
/*  */
#define TLR_E_PROFIBUS_DL_ACK_RDH        ((TLR_RESULT)0xC0060084L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_ACK_RDL */
/*  */
/*  MessageText: */
/*  */
/*   The remote station the service has been sent to, confirms its reception negatively but has returned low priority data in the response. */
/*  */
#define TLR_E_PROFIBUS_DL_ACK_RDL        ((TLR_RESULT)0xC0060085L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_ACK_DH */
/*  */
/*  MessageText: */
/*  */
/*   The remote station the service has been sent to, confirms its reception positively and has returned high priority data in the response. */
/*  */
#define TLR_E_PROFIBUS_DL_ACK_DH         ((TLR_RESULT)0xC0060086L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_ACK_DL */
/*  */
/*  MessageText: */
/*  */
/*   The remote station the service has been sent to, confirms its reception positively and has returned low priority data in the response. */
/*  */
#define TLR_E_PROFIBUS_DL_ACK_DL         ((TLR_RESULT)0xC0060087L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_ACK_NA */
/*  */
/*  MessageText: */
/*  */
/*   The remote station the service has been sent to shows no or no plausible reaction at all. */
/*  */
#define TLR_E_PROFIBUS_DL_ACK_NA         ((TLR_RESULT)0xC0060088L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_ACK_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   The remote station the service has been sent has returned an unknown acknowledgement code. */
/*  */
#define TLR_E_PROFIBUS_DL_ACK_UNKNOWN    ((TLR_RESULT)0xC0060089L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_ACK_LS */
/*  */
/*  MessageText: */
/*  */
/*   The requested service is not activated within the local SAP configuration. */
/*  */
#define TLR_E_PROFIBUS_DL_ACK_LS         ((TLR_RESULT)0xC006008AL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_ACK_LR */
/*  */
/*  MessageText: */
/*  */
/*   The local resources needed to execute the requested service are not available or not sufficient. */
/*  */
#define TLR_E_PROFIBUS_DL_ACK_LR         ((TLR_RESULT)0xC006008BL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_ACK_DS */
/*  */
/*  MessageText: */
/*  */
/*   The local data link layer is not in the logical token ring or disconnected from the network. */
/*  */
#define TLR_E_PROFIBUS_DL_ACK_DS         ((TLR_RESULT)0xC006008CL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_ACK_IV */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter detected in the requested service. */
/*  */
#define TLR_E_PROFIBUS_DL_ACK_IV         ((TLR_RESULT)0xC006008DL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_ACK_NO */
/*  */
/*  MessageText: */
/*  */
/*   The local SAP is not activated because it has been activated already or resources are not sufficient. */
/*  */
#define TLR_E_PROFIBUS_DL_ACK_NO         ((TLR_RESULT)0xC006008EL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_ACK_NO_SET */
/*  */
/*  MessageText: */
/*  */
/*   The variable to be set does not exist. */
/*  */
#define TLR_E_PROFIBUS_DL_ACK_NO_SET     ((TLR_RESULT)0xC006008FL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_ACK_RE */
/*  */
/*  MessageText: */
/*  */
/*   Format error of the telegram. */
/*  */
#define TLR_E_PROFIBUS_DL_ACK_RE         ((TLR_RESULT)0xC0060090L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DL_TSET_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The specified parameter TSET is out of range 1-255. */
/*  */
#define TLR_E_PROFIBUS_DL_TSET_INVALID   ((TLR_RESULT)0xC0060091L)




#endif  /* __PROFIBUS_DL_ERROR_H */

#ifndef __PROFIBUS_FSPMM2_ERROR_H
#define __PROFIBUS_FSPMM2_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFIBUS Master FSPMM2 Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM2_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_PROFIBUS_FSPMM2_COMMAND_INVALID ((TLR_RESULT)0xC0690000L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM2_LENGTH_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid data length. */
/*  */
#define TLR_E_PROFIBUS_FSPMM2_LENGTH_INVALID ((TLR_RESULT)0xC0690001L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM2_NOT_IMPLEMENTED */
/*  */
/*  MessageText: */
/*  */
/*   Service not implemented. */
/*  */
#define TLR_E_PROFIBUS_FSPMM2_NOT_IMPLEMENTED ((TLR_RESULT)0xC0690002L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM2_ADD_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid address. */
/*  */
#define TLR_E_PROFIBUS_FSPMM2_ADD_INVALID ((TLR_RESULT)0xC0690003L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM2_SERVICE_IN_REQUEST */
/*  */
/*  MessageText: */
/*  */
/*   Previous service already in request. */
/*  */
#define TLR_E_PROFIBUS_FSPMM2_SERVICE_IN_REQUEST ((TLR_RESULT)0xC0690004L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM2_NOT_IN_OPEN_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Connection is not in state open. */
/*  */
#define TLR_E_PROFIBUS_FSPMM2_NOT_IN_OPEN_STATE ((TLR_RESULT)0xC0690005L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM2_OUT_OF_RESOURCES */
/*  */
/*  MessageText: */
/*  */
/*   Out of resources for new connections. */
/*  */
#define TLR_E_PROFIBUS_FSPMM2_OUT_OF_RESOURCES ((TLR_RESULT)0xC0690006L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM2_IN_USE */
/*  */
/*  MessageText: */
/*  */
/*   Connection to this slave already in use. */
/*  */
#define TLR_E_PROFIBUS_FSPMM2_IN_USE     ((TLR_RESULT)0xC0690007L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM2_ALREADY_INIT */
/*  */
/*  MessageText: */
/*  */
/*   Stack is already initialized. */
/*  */
#define TLR_E_PROFIBUS_FSPMM2_ALREADY_INIT ((TLR_RESULT)0xC0690008L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM2_COM_REFERENCE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid communication reference. */
/*  */
#define TLR_E_PROFIBUS_FSPMM2_COM_REFERENCE_INVALID ((TLR_RESULT)0xC0690009L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM2_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Timout error. */
/*  */
#define TLR_E_PROFIBUS_FSPMM2_TIMEOUT    ((TLR_RESULT)0xC069000AL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM2_INITIATE_ABT_STO */
/*  */
/*  MessageText: */
/*  */
/*   Parameter Send Timeout to small. */
/*  */
#define TLR_E_PROFIBUS_FSPMM2_INITIATE_ABT_STO ((TLR_RESULT)0xC069000BL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM2_INITIATE_ABT_FE */
/*  */
/*  MessageText: */
/*  */
/*   Telegram format error. */
/*  */
#define TLR_E_PROFIBUS_FSPMM2_INITIATE_ABT_FE ((TLR_RESULT)0xC069000CL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM2_NRS */
/*  */
/*  MessageText: */
/*  */
/*   Negativ response. */
/*  */
#define TLR_E_PROFIBUS_FSPMM2_NRS        ((TLR_RESULT)0xC069000DL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM2_ABORT */
/*  */
/*  MessageText: */
/*  */
/*   Service Aborted. */
/*  */
#define TLR_E_PROFIBUS_FSPMM2_ABORT      ((TLR_RESULT)0xC069000EL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM2_CON_XX */
/*  */
/*  MessageText: */
/*  */
/*   Service confirmation negative. */
/*  */
#define TLR_E_PROFIBUS_FSPMM2_CON_XX     ((TLR_RESULT)0xC0690100L)




#endif  /* __PROFIBUS_FSPMM2_ERROR_H */

#ifndef __PROFIBUS_FSPMM_ERROR_H
#define __PROFIBUS_FSPMM_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFIBUS Master FSPMM Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_COMMAND_INVALID ((TLR_RESULT)0xC0380001L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_INV_BUSMODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid bus mode for this command. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_INV_BUSMODE ((TLR_RESULT)0xC0380002L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_RESET */
/*  */
/*  MessageText: */
/*  */
/*   FSPMM task is reseted. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_RESET       ((TLR_RESULT)0xC0380003L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_ACLR */
/*  */
/*  MessageText: */
/*  */
/*   Profibus master is at auto clear state. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_ACLR        ((TLR_RESULT)0xC0380004L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_CONTROL_TIMER_EXPIRED */
/*  */
/*  MessageText: */
/*  */
/*   Data Control Timer expired. No bus access for sending global control. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_CONTROL_TIMER_EXPIRED ((TLR_RESULT)0xC0380005L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_ALARM_OVERFLOW */
/*  */
/*  MessageText: */
/*  */
/*   Alarm buffer overflow. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_ALARM_OVERFLOW ((TLR_RESULT)0xC0380006L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_ALARM_NOT_INIT */
/*  */
/*  MessageText: */
/*  */
/*   Alarm handler is not initialized. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_ALARM_NOT_INIT ((TLR_RESULT)0xC0380007L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_ALARM_NOT_STARTED */
/*  */
/*  MessageText: */
/*  */
/*   Alarm handler is not started. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_ALARM_NOT_STARTED ((TLR_RESULT)0xC0380008L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_ALARM_NOT_ENABLED */
/*  */
/*  MessageText: */
/*  */
/*   Alarm are disabled. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_ALARM_NOT_ENABLED ((TLR_RESULT)0xC0380009L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_ALARM_NOT_PENDING */
/*  */
/*  MessageText: */
/*  */
/*   Alarm is not at a pending state. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_ALARM_NOT_PENDING ((TLR_RESULT)0xC038000AL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_ALARM_STATE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Alarm state. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_ALARM_STATE_ERROR ((TLR_RESULT)0xC038000BL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_ALARM_SEQ_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Alarm sequence error occurred. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_ALARM_SEQ_ERROR ((TLR_RESULT)0xC038000CL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_MSAC1_STATE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Alarm handler is not at the prober state. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_MSAC1_STATE_ERROR ((TLR_RESULT)0xC038000DL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_MSAC1_FAULT */
/*  */
/*  MessageText: */
/*  */
/*   Get an alarm acknowledge without an alarm. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_MSAC1_FAULT ((TLR_RESULT)0xC038000EL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_INVALID_AREA_CODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid area code or slave address received. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_INVALID_AREA_CODE ((TLR_RESULT)0xC038000FL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_IV_DL_DATA_LEN */
/*  */
/*  MessageText: */
/*  */
/*   Invalid data length. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_IV_DL_DATA_LEN ((TLR_RESULT)0xC0380011L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_IV_BUS_PRM */
/*  */
/*  MessageText: */
/*  */
/*   Invalid bus parameter received. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_IV_BUS_PRM  ((TLR_RESULT)0xC0380012L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_IV_SLAVE_PRM */
/*  */
/*  MessageText: */
/*  */
/*   Invalid slave parameter received. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_IV_SLAVE_PRM ((TLR_RESULT)0xC0380013L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_ACK_NO */
/*  */
/*  MessageText: */
/*  */
/*   Command can not executed at the actual bus state. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_ACK_NO      ((TLR_RESULT)0xC0380014L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_ACK_GE */
/*  */
/*  MessageText: */
/*  */
/*   Error while sending global control. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_ACK_GE      ((TLR_RESULT)0xC0380015L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_MSAL1_FAULT */
/*  */
/*  MessageText: */
/*  */
/*   Failture at alarm handler. Alarm handler is stopped. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_MSAL1_FAULT ((TLR_RESULT)0xC0380016L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_MSAC2_FAULT */
/*  */
/*  MessageText: */
/*  */
/*   Failture at MSAC2 handler. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_MSAC2_FAULT ((TLR_RESULT)0xC0380017L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_REJ_SE */
/*  */
/*  MessageText: */
/*  */
/*   Device is stopping the communication or not in OPEN state. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_REJ_SE      ((TLR_RESULT)0xC0380018L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_REJ_PS */
/*  */
/*  MessageText: */
/*  */
/*   A previous service is still in process. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_REJ_PS      ((TLR_RESULT)0xC0380019L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_REJ_LE */
/*  */
/*  MessageText: */
/*  */
/*   Message have a invalid length. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_REJ_LE      ((TLR_RESULT)0xC038001AL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_REJ_IV */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter at request. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_REJ_IV      ((TLR_RESULT)0xC038001BL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_REJ_ABORT */
/*  */
/*  MessageText: */
/*  */
/*   Device aborts DP V1 communication. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_REJ_ABORT   ((TLR_RESULT)0xC038001CL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_INVALID_SLAVE_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid slave address. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_INVALID_SLAVE_ADDRESS ((TLR_RESULT)0xC038001DL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_ALREADY_INITIALZED */
/*  */
/*  MessageText: */
/*  */
/*   FSPMM Alraedy initialized. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_ALREADY_INITIALZED ((TLR_RESULT)0xC038001EL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_INVALID_APPLICATION */
/*  */
/*  MessageText: */
/*  */
/*   Command from not registerd application. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_INVALID_APPLICATION ((TLR_RESULT)0xC038001FL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_DMPMM_IV_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Command not allowed in actual state. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_DMPMM_IV_STATE ((TLR_RESULT)0xC0380020L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_PB_FLAG_ERROR_ACTION_FLAG */
/*  */
/*  MessageText: */
/*  */
/*   Function 'AUTO CLEAR' not supported. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_PB_FLAG_ERROR_ACTION_FLAG ((TLR_RESULT)0xC0380021L)    

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_PB_FLAG_ISO_MODE_MSK */
/*  */
/*  MessageText: */
/*  */
/*   Function 'ISO_MODE' not supported. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_PB_FLAG_ISO_MODE_MSK ((TLR_RESULT)0xC0380022L)    

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_DL_PB_FLAG_ISOM_SYNC */
/*  */
/*  MessageText: */
/*  */
/*   Function 'ISO_MODE_SYNC' not supported. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_DL_PB_FLAG_ISOM_SYNC ((TLR_RESULT)0xC0380023L)    

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_DL_PB_FLAG_ISOM_FREEZE */
/*  */
/*  MessageText: */
/*  */
/*   Function 'ISO_MODE_FREEZE' not supported. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_DL_PB_FLAG_ISOM_FREEZE ((TLR_RESULT)0xC0380024L)    

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMM_MSAC1_NRS */
/*  */
/*  MessageText: */
/*  */
/*   Negative response received. */
/*  */
#define TLR_E_PROFIBUS_FSPMM_MSAC1_NRS   ((TLR_RESULT)0xC0380025L)    




#endif  /* __PROFIBUS_FSPMM_ERROR_H */

#ifndef __PROFIBUS_FSPMS_ERROR_H
#define __PROFIBUS_FSPMS_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFIBUS FSPMS Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_COMMAND_INVALID ((TLR_RESULT)0xC0090001L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_MAX_EXT_DIAG_SIZE_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   Setting the slave diagnostic failed, because the limit of the maximum number of 238 extended diagnostic bytes is exceeded. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_MAX_EXT_DIAG_SIZE_EXCEEDED ((TLR_RESULT)0xC0090002L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_MAX_CFG_DATA_SIZE_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   Setting the slave's configuration data failed, because the limit of the maximum number of 244 configuration bytes is exceeded. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_MAX_CFG_DATA_SIZE_EXCEEDED ((TLR_RESULT)0xC0090003L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_MS0_INIT_WRONG_STATE */
/*  */
/*  MessageText: */
/*  */
/*   The cyclic slave state machine cannot be initialized, state machine is not in "POWER-ON" state. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_MS0_INIT_WRONG_STATE ((TLR_RESULT)0xC0090004L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_SLAVE_DIAG_POWER_ON */
/*  */
/*  MessageText: */
/*  */
/*   Setting the Slave Diagnostic Data cannot be performed, because slave state machine isn't initialized yet. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_SLAVE_DIAG_POWER_ON ((TLR_RESULT)0xC0090005L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_SET_CFG_POWER_ON */
/*  */
/*  MessageText: */
/*  */
/*   Setting the Slave Configuration Data cannot be performed, because slave state machine isn't initialized yet. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_SET_CFG_POWER_ON ((TLR_RESULT)0xC0090006L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_GET_OUTPUT_POWER_ON */
/*  */
/*  MessageText: */
/*  */
/*   Getting the Slave Output Data cannot be performed, because slave state machine isn't initialized yet. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_GET_OUTPUT_POWER_ON ((TLR_RESULT)0xC0090007L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_GET_OUTPUT_WAIT_PRM */
/*  */
/*  MessageText: */
/*  */
/*   Getting the Slave Output Data cannot be performed, because slave state is currently in state "WAIT-PRM". */
/*  */
#define TLR_E_PROFIBUS_FSPMS_GET_OUTPUT_WAIT_PRM ((TLR_RESULT)0xC0090008L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_SET_INPUT_POWER_ON */
/*  */
/*  MessageText: */
/*  */
/*   Setting the Slave Input Data cannot be performed, because slave state machine isn't initialized yet. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_SET_INPUT_POWER_ON ((TLR_RESULT)0xC0090009L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_SET_INPUT_WAIT_PRM */
/*  */
/*  MessageText: */
/*  */
/*   Setting the Slave Input Data cannot be performed, because slave state is currently in state "WAIT-PRM". */
/*  */
#define TLR_E_PROFIBUS_FSPMS_SET_INPUT_WAIT_PRM ((TLR_RESULT)0xC009000AL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_CHECK_USER_PRM_POWER_ON */
/*  */
/*  MessageText: */
/*  */
/*   Confirming the Slave Parameter Data cannot be performed, because slave state machine isn't initialized yet. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_CHECK_USER_PRM_POWER_ON ((TLR_RESULT)0xC009000BL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_CHECK_USER_PRM_NOT_PENDING */
/*  */
/*  MessageText: */
/*  */
/*   There is no Parameter Data checking command pending, command ignored. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_CHECK_USER_PRM_NOT_PENDING ((TLR_RESULT)0xC009000CL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_CHECK_USER_PRM_NEW_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   The confirmation of the Slave Parameter Data is obsolete, there is new Slave Parameter Data available. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_CHECK_USER_PRM_NEW_PARAMETER ((TLR_RESULT)0xC009000DL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_CHECK_CFG_POWER_ON */
/*  */
/*  MessageText: */
/*  */
/*   Confirming the Slave Configuration Data cannot be performed, because slave state machine isn't initialized yet. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_CHECK_CFG_POWER_ON ((TLR_RESULT)0xC009000EL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_CHECK_CFG_NOT_PENDING */
/*  */
/*  MessageText: */
/*  */
/*   There is no Configuration Data checking command pending, command ignored. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_CHECK_CFG_NOT_PENDING ((TLR_RESULT)0xC009000FL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_CHECK_CFG_NEW_CONFIGURATION */
/*  */
/*  MessageText: */
/*  */
/*   The confirmation of the Slave Configruation Data is obsolete, there is new Slave Configuration Data available. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_CHECK_CFG_NEW_CONFIGURATION ((TLR_RESULT)0xC0090010L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_CHECK_EXT_USER_PRM_POWER_ON */
/*  */
/*  MessageText: */
/*  */
/*   Confirming the extended Slave Parameter Data cannot be performed, because slave state machine isn't initialized yet. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_CHECK_EXT_USER_PRM_POWER_ON ((TLR_RESULT)0xC0090011L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_CHECK_EXT_USER_PRM_NOT_PENDING */
/*  */
/*  MessageText: */
/*  */
/*   There is no extended Parameter Data checking command pending, command ignored. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_CHECK_EXT_USER_PRM_NOT_PENDING ((TLR_RESULT)0xC0090012L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_CHECK_EXT_USER_PRM_NEW_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   The confirmation of the extended Slave Parameter Data is obsolete, there is new extended Slave Parameter Data available. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_CHECK_EXT_USER_PRM_NEW_PARAMETER ((TLR_RESULT)0xC0090013L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_ABORT_IGNORED */
/*  */
/*  MessageText: */
/*  */
/*   The abort command is ignored in the current state of the slave state machine. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_ABORT_IGNORED ((TLR_RESULT)0xC0090014L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_GET_OUTPUT_WAIT_CFG */
/*  */
/*  MessageText: */
/*  */
/*   Getting the Slave Output Data cannot be performed, because slave state is currently in state "WAIT-CFG". */
/*  */
#define TLR_E_PROFIBUS_FSPMS_GET_OUTPUT_WAIT_CFG ((TLR_RESULT)0xC0090015L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_SET_INPUT_NOT_PENDING */
/*  */
/*  MessageText: */
/*  */
/*   Setting the Slave Input Data cannot be performed, because input update is not pending. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_SET_INPUT_NOT_PENDING ((TLR_RESULT)0xC0090016L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_CHECK_USER_PRM_INVALID_MASTER_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   The confirmation of the Slave Parameter Data is obsolete, because meanwhile an other master has parameterized the slave. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_CHECK_USER_PRM_INVALID_MASTER_ADDRESS ((TLR_RESULT)0xC0090017L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_CHECK_CFG_INVALID_MASTER_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   The confirmation of the Slave Configruation Data is obsolete, because meanwhile an other master has configured the slave. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_CHECK_CFG_INVALID_MASTER_ADDRESS ((TLR_RESULT)0xC0090018L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_APPLICATION_READY_IGNORED */
/*  */
/*  MessageText: */
/*  */
/*   The Application ready command is ignored in the current state of the slave state machine. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_APPLICATION_READY_IGNORED ((TLR_RESULT)0xC0090019L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_CHECK_EXT_USER_PRM_INVALID_MASTER_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   The confirmation of the extended Slave Parameter Data is obsolete, because meanwhile an other master has parameterized the slave. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_CHECK_EXT_USER_PRM_INVALID_MASTER_ADDRESS ((TLR_RESULT)0xC009001AL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_GET_OUTPUT_DATA_EXCHANGE_NO_CYCLE */
/*  */
/*  MessageText: */
/*  */
/*   Getting the Slave Output Data cannot be performed, because slave state machine is in state "DATA-EXCH" but no output cycle has been driven yet. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_GET_OUTPUT_DATA_EXCHANGE_NO_CYCLE ((TLR_RESULT)0xC009001BL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_APPLICATION_ALREADY_READY */
/*  */
/*  MessageText: */
/*  */
/*   The Application ready command is ignored, because the application has already signaled its readyness. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_APPLICATION_ALREADY_READY ((TLR_RESULT)0xC009001CL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_SLAVE_DIAG_PENDING */
/*  */
/*  MessageText: */
/*  */
/*   A new Slave Diagnostic command can not be accepted, while a previous one is pending. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_SLAVE_DIAG_PENDING ((TLR_RESULT)0xC009001DL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_READ_RESPONSE_NEG */
/*  */
/*  MessageText: */
/*  */
/*   The read command can not be A new Slave Diagnostic command can not be accepted, while a previous one is pending. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_READ_RESPONSE_NEG ((TLR_RESULT)0xC009001EL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_MS1_INIT_WRONG_STATE */
/*  */
/*  MessageText: */
/*  */
/*   The acyclic slave state machine cannot be initialized, state machine is not in "POWER-ON" state. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_MS1_INIT_WRONG_STATE ((TLR_RESULT)0xC009001FL)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_ALARM_HANDLER_NOT_STARTED */
/*  */
/*  MessageText: */
/*  */
/*   The Alarm Handler state machine isn't started yet, an Alarm cannot be notified. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_ALARM_HANDLER_NOT_STARTED ((TLR_RESULT)0xC0090020L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_ALARM_HANDLER_NOT_ENABLED */
/*  */
/*  MessageText: */
/*  */
/*   The requested Type of Alarm is not enabled, this Alarm cannot be notified. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_ALARM_HANDLER_NOT_ENABLED ((TLR_RESULT)0xC0090022L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_ALARM_HANDLER_LIMIT_EXPIRED */
/*  */
/*  MessageText: */
/*  */
/*   The limit of parallel running alarms is expired, this Alarm cannot be notified. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_ALARM_HANDLER_LIMIT_EXPIRED ((TLR_RESULT)0xC0090023L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_ALARM_HANDLER_PENDING */
/*  */
/*  MessageText: */
/*  */
/*   This requested Type of Alarm is still pending and in operation, this is why the Alarm cannot be notified. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_ALARM_HANDLER_PENDING ((TLR_RESULT)0xC0090024L)

/*  */
/*  MessageId: TLR_W_PROFIBUS_FSPMS_NOTREADY_EXPIRED */
/*  */
/*  MessageText: */
/*  */
/*   Application is at not ready state. */
/*  */
#define TLR_W_PROFIBUS_FSPMS_NOTREADY_EXPIRED ((TLR_RESULT)0x80090025L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_FSPMS_WATCHDOG_EXPIRED */
/*  */
/*  MessageText: */
/*  */
/*   Watchdog error expired. */
/*  */
#define TLR_E_PROFIBUS_FSPMS_WATCHDOG_EXPIRED ((TLR_RESULT)0xC0090026L)




#endif  /* __PROFIBUS_FSPMS_ERROR_H */

#ifndef __PROFIBUS_MPI_AP_ERROR_H
#define __PROFIBUS_MPI_AP_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFIBUS MPI Application  ERROR codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_AP_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_PROFIBUS_MPI_AP_COMMAND_INVALID ((TLR_RESULT)0xC0680001L)




#endif  /* __PROFIBUS_MPI_AP_ERROR_H */

#ifndef __PROFIBUS_MPI_ERROR_H
#define __PROFIBUS_MPI_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFIBUS MPI ERROR codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_PROFIBUS_MPI_COMMAND_INVALID ((TLR_RESULT)0xC0670001L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_INVALID_PACKET_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Invalid packet length received. */
/*  */
#define TLR_E_PROFIBUS_MPI_INVALID_PACKET_LENGTH ((TLR_RESULT)0xC0670002L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_DATA_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Data Counter Error. */
/*  */
#define TLR_E_PROFIBUS_DATA_CNT          ((TLR_RESULT)0xC0670005L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_CON_TO */
/*  */
/*  MessageText: */
/*  */
/*   Timeout. */
/*  */
#define TLR_E_PROFIBUS_MPI_CON_TO        ((TLR_RESULT)0xC0670130L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_CON_SE */
/*  */
/*  MessageText: */
/*  */
/*   Sequenceerror. */
/*  */
#define TLR_E_PROFIBUS_MPI_CON_SE        ((TLR_RESULT)0xC0670139L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_BUS_UNCONFIGURED */
/*  */
/*  MessageText: */
/*  */
/*   Bus unconfigured. */
/*  */
#define TLR_E_PROFIBUS_MPI_BUS_UNCONFIGURED ((TLR_RESULT)0xC0670202L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_ILLEGAL_FUNCTION_NUMBER */
/*  */
/*  MessageText: */
/*  */
/*   Illegalfunction number. */
/*  */
#define TLR_E_PROFIBUS_MPI_ILLEGAL_FUNCTION_NUMBER ((TLR_RESULT)0xC0670203L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_RESET_IN_PROGRESS */
/*  */
/*  MessageText: */
/*  */
/*   Reset in progress. */
/*  */
#define TLR_E_PROFIBUS_MPI_RESET_IN_PROGRESS ((TLR_RESULT)0xC0670204L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_TOO_MANY_REQ_IN_PROGRESS */
/*  */
/*  MessageText: */
/*  */
/*   Too many requests in progress. */
/*  */
#define TLR_E_PROFIBUS_MPI_TOO_MANY_REQ_IN_PROGRESS ((TLR_RESULT)0xC0670205L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_DENIED_BY_WATCHDOG_TO */
/*  */
/*  MessageText: */
/*  */
/*   No Access because of Watchdog Timeout. */
/*  */
#define TLR_E_PROFIBUS_MPI_DENIED_BY_WATCHDOG_TO ((TLR_RESULT)0xC0670206L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_ILLEGAL_WATCHDOG_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Illegal Watchdog time. */
/*  */
#define TLR_E_PROFIBUS_MPI_ILLEGAL_WATCHDOG_TIME ((TLR_RESULT)0xC0670207L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_CON_IN_PROGRESS */
/*  */
/*  MessageText: */
/*  */
/*   Connection to Plc in progress. */
/*  */
#define TLR_E_PROFIBUS_MPI_CON_IN_PROGRESS ((TLR_RESULT)0xC0670208L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_BUS_ALREADY_CONFIGURED */
/*  */
/*  MessageText: */
/*  */
/*   Bus already configured. */
/*  */
#define TLR_E_PROFIBUS_MPI_BUS_ALREADY_CONFIGURED ((TLR_RESULT)0xC0670209L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_REJ_SE */
/*  */
/*  MessageText: */
/*  */
/*   Device stopped communication or is not in Open State. */
/*  */
#define TLR_E_PROFIBUS_MPI_REJ_SE        ((TLR_RESULT)0xC0670281L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_REJ_ABORT */
/*  */
/*  MessageText: */
/*  */
/*   Device aborts communication. */
/*  */
#define TLR_E_PROFIBUS_MPI_REJ_ABORT     ((TLR_RESULT)0xC0670282L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_REJ_PS */
/*  */
/*  MessageText: */
/*  */
/*   Previous Service still in Progress */
/*  */
#define TLR_E_PROFIBUS_MPI_REJ_PS        ((TLR_RESULT)0xC0670283L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_REJ_LE */
/*  */
/*  MessageText: */
/*  */
/*   Length Error. */
/*  */
#define TLR_E_PROFIBUS_MPI_REJ_LE        ((TLR_RESULT)0xC0670284L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_REJ_IV */
/*  */
/*  MessageText: */
/*  */
/*   Specified offset out of limits or not known to remote station. */
/*  */
#define TLR_E_PROFIBUS_MPI_REJ_IV        ((TLR_RESULT)0xC0670285L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_REJ_PDU */
/*  */
/*  MessageText: */
/*  */
/*   Wrong PDU coding. */
/*  */
#define TLR_E_PROFIBUS_MPI_REJ_PDU       ((TLR_RESULT)0xC0670286L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_REJ_OP */
/*  */
/*  MessageText: */
/*  */
/*   Specified Length to read or write out of limits. */
/*  */
#define TLR_E_PROFIBUS_MPI_REJ_OP        ((TLR_RESULT)0xC0670287L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_REJ_HW */
/*  */
/*  MessageText: */
/*  */
/*   Specified address not defined in remote station. */
/*  */
#define TLR_E_PROFIBUS_MPI_REJ_HW        ((TLR_RESULT)0xC0670288L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_REJ_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Remote station not in right operational Mode. */
/*  */
#define TLR_E_PROFIBUS_MPI_REJ_MODE      ((TLR_RESULT)0xC0670289L)

/*  */
/*  MessageId: TLR_E_PROFIBUS_MPI_UNKNOWN_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Unknown error. */
/*  */
#define TLR_E_PROFIBUS_MPI_UNKNOWN_ERROR ((TLR_RESULT)0xC0670290L)




#endif  /* __PROFIBUS_MPI_ERROR_H */

#ifndef __RCX_ERROR_H
#define __RCX_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  RCX Task error codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_RCX_QUE_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   Queue unknown. */
/*  */
#define TLR_E_RCX_QUE_UNKNOWN            ((TLR_RESULT)0xC02B0001L)

/*  */
/*  MessageId: TLR_E_RCX_QUE_IDX_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   Queue table index does not exist. */
/*  */
#define TLR_E_RCX_QUE_IDX_UNKNOWN        ((TLR_RESULT)0xC02B0002L)

/*  */
/*  MessageId: TLR_E_RCX_TSK_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   Task unknown. */
/*  */
#define TLR_E_RCX_TSK_UNKNOWN            ((TLR_RESULT)0xC02B0003L)

/*  */
/*  MessageId: TLR_E_RCX_TSK_IDX_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   Task table index does not exist. */
/*  */
#define TLR_E_RCX_TSK_IDX_UNKNOWN        ((TLR_RESULT)0xC02B0004L)

/*  */
/*  MessageId: TLR_E_RCX_TSK_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Task handle invalid. */
/*  */
#define TLR_E_RCX_TSK_HANDLE_INVALID     ((TLR_RESULT)0xC02B0005L)

/*  */
/*  MessageId: TLR_E_RCX_TSK_INFO_IDX_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   Task info field index unknown. */
/*  */
#define TLR_E_RCX_TSK_INFO_IDX_UNKNOWN   ((TLR_RESULT)0xC02B0006L)

/*  */
/*  MessageId: TLR_I_RCX_FILE_RETRANSMIT */
/*  */
/*  MessageText: */
/*  */
/*   The last data block was invalid, please retransmit. */
/*  */
#define TLR_I_RCX_FILE_RETRANSMIT        ((TLR_RESULT)0x402B0001L)

/*  */
/*  MessageId: TLR_E_RCX_FILE_XFR_TYPE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Requested transfer type invalid. */
/*  */
#define TLR_E_RCX_FILE_XFR_TYPE_INVALID  ((TLR_RESULT)0xC02B0007L)

/*  */
/*  MessageId: TLR_E_RCX_FILE_REQUEST_INCORRECT */
/*  */
/*  MessageText: */
/*  */
/*   Request is incorrectly formatted i.e. wrong parameters. */
/*  */
#define TLR_E_RCX_FILE_REQUEST_INCORRECT ((TLR_RESULT)0xC02B0008L)

/*  */
/*  MessageId: TLR_E_RCX_UNKNOWN_PORT_INDEX */
/*  */
/*  MessageText: */
/*  */
/*   Unknown port index. */
/*  */
#define TLR_E_RCX_UNKNOWN_PORT_INDEX     ((TLR_RESULT)0xC02B0009L)

/*  */
/*  MessageId: TLR_E_RCX_ROUTER_TABLE_FULL */
/*  */
/*  MessageText: */
/*  */
/*   Router Table is full. */
/*  */
#define TLR_E_RCX_ROUTER_TABLE_FULL      ((TLR_RESULT)0xC02B000AL)

/*  */
/*  MessageId: TLR_E_RCX_NO_SUCH_ROUTER_IN_TABLE */
/*  */
/*  MessageText: */
/*  */
/*   No such router in table. */
/*  */
#define TLR_E_RCX_NO_SUCH_ROUTER_IN_TABLE ((TLR_RESULT)0xC02B000BL)

/*  */
/*  MessageId: TLR_E_RCX_INSTANCE_NOT_NULL */
/*  */
/*  MessageText: */
/*  */
/*   Mid_Sys Instance is not 0. */
/*  */
#define TLR_E_RCX_INSTANCE_NOT_NULL      ((TLR_RESULT)0xC02B000CL)

/*  */
/*  MessageId: TLR_E_RCX_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_RCX_COMMAND_INVALID        ((TLR_RESULT)0xC02B000DL)

/*  */
/*  MessageId: TLR_E_RCX_TSK_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid task handle. */
/*  */
#define TLR_E_RCX_TSK_INVALID            ((TLR_RESULT)0xC02B000EL)

/*  */
/*  MessageId: TLR_E_RCX_TSK_NOT_A_USER_TASK */
/*  */
/*  MessageText: */
/*  */
/*   Access denied. Not a user task (See Config-File). */
/*  */
#define TLR_E_RCX_TSK_NOT_A_USER_TASK    ((TLR_RESULT)0xC02B000FL)

/*  */
/*  MessageId: TLR_E_RCX_LOG_QUE_NOT_SETTABLE */
/*  */
/*  MessageText: */
/*  */
/*   Logical queue handle not settable. */
/*  */
#define TLR_E_RCX_LOG_QUE_NOT_SETTABLE   ((TLR_RESULT)0xC02B0010L)

/*  */
/*  MessageId: TLR_E_RCX_LOG_QUE_NOT_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Logical queue handle invalid. */
/*  */
#define TLR_E_RCX_LOG_QUE_NOT_INVALID    ((TLR_RESULT)0xC02B0011L)

/*  */
/*  MessageId: TLR_E_RCX_LOG_QUE_NOT_SET */
/*  */
/*  MessageText: */
/*  */
/*   Logical queue handle has not been set. */
/*  */
#define TLR_E_RCX_LOG_QUE_NOT_SET        ((TLR_RESULT)0xC02B0012L)

/*  */
/*  MessageId: TLR_E_RCX_LOG_QUE_ALREADY_USED */
/*  */
/*  MessageText: */
/*  */
/*   Logical queue handle is already in use. */
/*  */
#define TLR_E_RCX_LOG_QUE_ALREADY_USED   ((TLR_RESULT)0xC02B0013L)

/*  */
/*  MessageId: TLR_E_RCX_TSK_NO_DEFAULT_QUEUE */
/*  */
/*  MessageText: */
/*  */
/*   Task has no default process queue. */
/*  */
#define TLR_E_RCX_TSK_NO_DEFAULT_QUEUE   ((TLR_RESULT)0xC02B0014L)

/*  */
/*  MessageId: TLR_E_RCX_MODULE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Firmware Module is invalid. CRC-32 check failed. */
/*  */
#define TLR_E_RCX_MODULE_INVALID         ((TLR_RESULT)0xC02B0015L)

/*  */
/*  MessageId: TLR_E_RCX_MODULE_NOT_FOUND */
/*  */
/*  MessageText: */
/*  */
/*   Firmware Module has not been found. Maybe it has not been downloaded before. */
/*  */
#define TLR_E_RCX_MODULE_NOT_FOUND       ((TLR_RESULT)0xC02B0016L)

/*  */
/*  MessageId: TLR_E_RCX_MODULE_RELOC_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Firmware Module has an invalid reloc table. */
/*  */
#define TLR_E_RCX_MODULE_RELOC_ERROR     ((TLR_RESULT)0xC02B0017L)

/*  */
/*  MessageId: TLR_E_RCX_MODULE_NO_INIT_TBL */
/*  */
/*  MessageText: */
/*  */
/*   Firmware Module has no init table. */
/*  */
#define TLR_E_RCX_MODULE_NO_INIT_TBL     ((TLR_RESULT)0xC02B0018L)

/*  */
/*  MessageId: TLR_E_RCX_MODULE_NO_ENTRY_POINT */
/*  */
/*  MessageText: */
/*  */
/*   Firmware Module has no code entry point. */
/*  */
#define TLR_E_RCX_MODULE_NO_ENTRY_POINT  ((TLR_RESULT)0xC02B0019L)

/*  */
/*  MessageId: TLR_E_RCX_ACCESS_DENIED_IN_LOCKED_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Access denied due to current operating conditions. */
/*  */
#define TLR_E_RCX_ACCESS_DENIED_IN_LOCKED_STATE ((TLR_RESULT)0xC02B001AL)

/*  */
/*  MessageId: TLR_E_RCX_INVALID_FIRMWARE_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Firmware does not fit into flash. */
/*  */
#define TLR_E_RCX_INVALID_FIRMWARE_SIZE  ((TLR_RESULT)0xC02B001BL)

/*  */
/*  MessageId: TLR_E_RCX_MODULE_RELOCATION_DISTANCE_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   The relocation distance is too long. */
/*  */
#define TLR_E_RCX_MODULE_RELOCATION_DISTANCE_TOO_LONG ((TLR_RESULT)0xC02B001CL)

/*  */
/*  MessageId: TLR_E_RCX_SEC_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Access to the security flash failed. */
/*  */
#define TLR_E_RCX_SEC_FAILED             ((TLR_RESULT)0xC02B001DL)

/*  */
/*  MessageId: TLR_E_RCX_SEC_DISABLED */
/*  */
/*  MessageText: */
/*  */
/*   Security flash is disabled at firmware. */
/*  */
#define TLR_E_RCX_SEC_DISABLED           ((TLR_RESULT)0xC02B001EL)

/*  */
/*  MessageId: TLR_E_RCX_INVALID_EXTENSION */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Extension field. */
/*  */
#define TLR_E_RCX_INVALID_EXTENSION      ((TLR_RESULT)0xC02B001FL)

/*  */
/*  MessageId: TLR_E_RCX_BLOCK_SIZE_OUT_OF_RANGE */
/*  */
/*  MessageText: */
/*  */
/*   Block size out of range. */
/*  */
#define TLR_E_RCX_BLOCK_SIZE_OUT_OF_RANGE ((TLR_RESULT)0xC02B0020L)

/*  */
/*  MessageId: TLR_E_RCX_INVALID_CHANNEL */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Channel. */
/*  */
#define TLR_E_RCX_INVALID_CHANNEL        ((TLR_RESULT)0xC02B0021L)

/*  */
/*  MessageId: TLR_E_RCX_INVLAID_FILE_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Invalid File Length. */
/*  */
#define TLR_E_RCX_INVLAID_FILE_LENGTH    ((TLR_RESULT)0xC02B0022L)

/*  */
/*  MessageId: TLR_E_RCX_INVALID_CHARACTER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Character. */
/*  */
#define TLR_E_RCX_INVALID_CHARACTER      ((TLR_RESULT)0xC02B0023L)

/*  */
/*  MessageId: TLR_E_RCX_PACKET_OUT_OF_SEQUENCE */
/*  */
/*  MessageText: */
/*  */
/*   Packet out of sequence. */
/*  */
#define TLR_E_RCX_PACKET_OUT_OF_SEQUENCE ((TLR_RESULT)0xC02B0024L)

/*  */
/*  MessageId: TLR_E_RCX_NOT_POSSIBLE_IN_CURRENT_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Not possible in current state. */
/*  */
#define TLR_E_RCX_NOT_POSSIBLE_IN_CURRENT_STATE ((TLR_RESULT)0xC02B0025L)

/*  */
/*  MessageId: TLR_E_RCX_SECURITY_EEPROM_INVALID_ZONE */
/*  */
/*  MessageText: */
/*  */
/*   Security Eeprom Zone Parameter is invalid. */
/*  */
#define TLR_E_RCX_SECURITY_EEPROM_INVALID_ZONE ((TLR_RESULT)0xC02B0026L)

/*  */
/*  MessageId: TLR_E_RCX_SECURITY_EEPROM_NOT_ALLOWED */
/*  */
/*  MessageText: */
/*  */
/*   Security Eeprom access is not allowed in current state. */
/*  */
#define TLR_E_RCX_SECURITY_EEPROM_NOT_ALLOWED ((TLR_RESULT)0xC02B0027L)

/*  */
/*  MessageId: TLR_E_RCX_SECURITY_EEPROM_NOT_AVAILABLE */
/*  */
/*  MessageText: */
/*  */
/*   Security Eeprom is not available. */
/*  */
#define TLR_E_RCX_SECURITY_EEPROM_NOT_AVAILABLE ((TLR_RESULT)0xC02B0028L)

/*  */
/*  MessageId: TLR_E_RCX_SECURITY_EEPROM_INVALID_CHECKSUM */
/*  */
/*  MessageText: */
/*  */
/*   Security Eeprom has an invalid checksum. */
/*  */
#define TLR_E_RCX_SECURITY_EEPROM_INVALID_CHECKSUM ((TLR_RESULT)0xC02B0029L)

/*  */
/*  MessageId: TLR_E_RCX_SECURITY_EEPROM_ZONE_NOT_WRITABLE */
/*  */
/*  MessageText: */
/*  */
/*   Security Eeprom Zone is not writeable. */
/*  */
#define TLR_E_RCX_SECURITY_EEPROM_ZONE_NOT_WRITABLE ((TLR_RESULT)0xC02B002AL)

/*  */
/*  MessageId: TLR_E_RCX_SECURITY_EEPROM_READ_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Security Eeprom Read Failed. */
/*  */
#define TLR_E_RCX_SECURITY_EEPROM_READ_FAILED ((TLR_RESULT)0xC02B002BL)

/*  */
/*  MessageId: TLR_E_RCX_SECURITY_EEPROM_WRITE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Security Eeprom Write Failed. */
/*  */
#define TLR_E_RCX_SECURITY_EEPROM_WRITE_FAILED ((TLR_RESULT)0xC02B002CL)

/*  */
/*  MessageId: TLR_E_RCX_SECURITY_EEPROM_ZONE_ACCESS_DENIED */
/*  */
/*  MessageText: */
/*  */
/*   Security Eeprom Zone Access Denied. */
/*  */
#define TLR_E_RCX_SECURITY_EEPROM_ZONE_ACCESS_DENIED ((TLR_RESULT)0xC02B002DL)

/*  */
/*  MessageId: TLR_E_RCX_SECURITY_EEPROM_EMULATED */
/*  */
/*  MessageText: */
/*  */
/*   Security Eeprom Emulated. No write possible. */
/*  */
#define TLR_E_RCX_SECURITY_EEPROM_EMULATED ((TLR_RESULT)0xC02B002EL)

/*  */
/*  MessageId: TLR_E_RCX_FILE_NAME_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   File name is invalid. */
/*  */
#define TLR_E_RCX_FILE_NAME_INVALID      ((TLR_RESULT)0xC02B002FL)

/*  */
/*  MessageId: TLR_E_RCX_FILE_SEQUENCE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   File Sequence Error. */
/*  */
#define TLR_E_RCX_FILE_SEQUENCE_ERROR    ((TLR_RESULT)0xC02B0030L)

/*  */
/*  MessageId: TLR_E_RCX_FILE_SEQUENCE_END_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   File Sequence End Error. */
/*  */
#define TLR_E_RCX_FILE_SEQUENCE_END_ERROR ((TLR_RESULT)0xC02B0031L)

/*  */
/*  MessageId: TLR_E_RCX_FILE_SEQUENCE_BEGIN_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   File Sequence Begin Error. */
/*  */
#define TLR_E_RCX_FILE_SEQUENCE_BEGIN_ERROR ((TLR_RESULT)0xC02B0032L)

/*  */
/*  MessageId: TLR_E_RCX_UNEXPECTED_BLOCK_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Unexpected File Transfer Block Size. */
/*  */
#define TLR_E_RCX_UNEXPECTED_BLOCK_SIZE  ((TLR_RESULT)0xC02B0033L)

/*  */
/*  MessageId: TLR_E_HIL_FILE_HEADER_CRC_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Hilscher File Header has invalid CRC error. */
/*  */
#define TLR_E_HIL_FILE_HEADER_CRC_ERROR  ((TLR_RESULT)0xC02B0034L)

/*  */
/*  MessageId: TLR_E_HIL_FILE_HEADER_MODULE_SIZE_DIFFERS */
/*  */
/*  MessageText: */
/*  */
/*   Hilscher File Header specifies a different module size than the actual module header itself. */
/*  */
#define TLR_E_HIL_FILE_HEADER_MODULE_SIZE_DIFFERS ((TLR_RESULT)0xC02B0035L)

/*  */
/*  MessageId: TLR_E_HIL_FILE_HEADER_MD5_CHECKSUM_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Hilscher File Header contains a wrong MD-5 checksum for file data. */
/*  */
#define TLR_E_HIL_FILE_HEADER_MD5_CHECKSUM_ERROR ((TLR_RESULT)0xC02B0036L)

/*  */
/*  MessageId: TLR_E_RCX_PACKET_WOULD_BE_TOO_LONG_FOR_MTU */
/*  */
/*  MessageText: */
/*  */
/*   The packet would be too long for transfer. */
/*  */
#define TLR_E_RCX_PACKET_WOULD_BE_TOO_LONG_FOR_MTU ((TLR_RESULT)0xC02B0037L)

/*  */
/*  MessageId: TLR_E_INVALID_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   Invalid block id */
/*  */
#define TLR_E_INVALID_BLOCK              ((TLR_RESULT)0xC02B0038L)

/*  */
/*  MessageId: TLR_E_INVALID_STRUCT_NUMBER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid structure number */
/*  */
#define TLR_E_INVALID_STRUCT_NUMBER      ((TLR_RESULT)0xC02B0039L)

/*  */
/*  MessageId: TLR_E_HIL_FILE_HEADER_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid file header */
/*  */
#define TLR_E_HIL_FILE_HEADER_INVALID    ((TLR_RESULT)0xC02B003AL)

/*  */
/*  MessageId: TLR_E_LICENSE_CHIPTYPE_UNSUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   Target device not supported for license update */
/*  */
#define TLR_E_LICENSE_CHIPTYPE_UNSUPPORTED ((TLR_RESULT)0xC02B003BL)

/*  */
/*  MessageId: TLR_E_LICENSE_CHIPTYPE_MISMATCH */
/*  */
/*  MessageText: */
/*  */
/*   License incompatible for target device */
/*  */
#define TLR_E_LICENSE_CHIPTYPE_MISMATCH  ((TLR_RESULT)0xC02B003CL)

/*  */
/*  MessageId: TLR_E_LICENSE_HW_MISMATCH */
/*  */
/*  MessageText: */
/*  */
/*   License generated for different device */
/*  */
#define TLR_E_LICENSE_HW_MISMATCH        ((TLR_RESULT)0xC02B003DL)

/*  */
/*  MessageId: TLR_E_MODULE_CONTAINS_NO_MODULE_DESCRIPTOR */
/*  */
/*  MessageText: */
/*  */
/*   Missing module descriptor in module. */
/*  */
#define TLR_E_MODULE_CONTAINS_NO_MODULE_DESCRIPTOR ((TLR_RESULT)0xC02B003EL)

/*  */
/*  MessageId: TLR_E_MODULE_CONTAINS_UNKNOWN_VERSION */
/*  */
/*  MessageText: */
/*  */
/*   Unknown version in module descriptor. */
/*  */
#define TLR_E_MODULE_CONTAINS_UNKNOWN_VERSION ((TLR_RESULT)0xC02B003FL)

/*  */
/*  MessageId: TLR_E_MODULE_HAS_NO_INIT_FUNCTION */
/*  */
/*  MessageText: */
/*  */
/*   Module has no init function. */
/*  */
#define TLR_E_MODULE_HAS_NO_INIT_FUNCTION ((TLR_RESULT)0xC02B0040L)

/*  */
/*  MessageId: TLR_E_MODULE_OFFSET_RANGE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Module part exceeded offset range. */
/*  */
#define TLR_E_MODULE_OFFSET_RANGE_ERROR  ((TLR_RESULT)0xC02B0041L)

/*  */
/*  MessageId: TLR_E_MODULE_INVALID_ELF_HEADER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid ELF header in module. */
/*  */
#define TLR_E_MODULE_INVALID_ELF_HEADER  ((TLR_RESULT)0xC02B0042L)

/*  */
/*  MessageId: TLR_E_MODULE_INVALID_ELF_SECTION_REFERENCE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid ELF section reference in module. */
/*  */
#define TLR_E_MODULE_INVALID_ELF_SECTION_REFERENCE ((TLR_RESULT)0xC02B0043L)

/*  */
/*  MessageId: TLR_E_MODULE_INVALID_ELF_SYMBOL_REFERENCE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid ELF symbol reference in module. */
/*  */
#define TLR_E_MODULE_INVALID_ELF_SYMBOL_REFERENCE ((TLR_RESULT)0xC02B0044L)

/*  */
/*  MessageId: TLR_E_MODULE_CONTAINS_AN_UNDEFINED_SYMBOL */
/*  */
/*  MessageText: */
/*  */
/*   Module contains an undefined symbol. */
/*  */
#define TLR_E_MODULE_CONTAINS_AN_UNDEFINED_SYMBOL ((TLR_RESULT)0xC02B0045L)

/*  */
/*  MessageId: TLR_E_MODULE_CONTAINS_INVALID_CODE_SYMBOL */
/*  */
/*  MessageText: */
/*  */
/*   Module contains invalid symbol to code area. */
/*  */
#define TLR_E_MODULE_CONTAINS_INVALID_CODE_SYMBOL ((TLR_RESULT)0xC02B0046L)

/*  */
/*  MessageId: TLR_E_MODULE_CONTAINS_UNSUPPORTED_SYMBOL_BINDING */
/*  */
/*  MessageText: */
/*  */
/*   Module contains an supported symbol binding. */
/*  */
#define TLR_E_MODULE_CONTAINS_UNSUPPORTED_SYMBOL_BINDING ((TLR_RESULT)0xC02B0047L)

/*  */
/*  MessageId: TLR_E_MODULE_CONTAINS_UNSUPPORTED_SYMBOL_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Module contains an supported symbol type. */
/*  */
#define TLR_E_MODULE_CONTAINS_UNSUPPORTED_SYMBOL_TYPE ((TLR_RESULT)0xC02B0048L)

/*  */
/*  MessageId: TLR_E_MODULE_INVALID_SECTION_OFFSET_ENCOUNTERED */
/*  */
/*  MessageText: */
/*  */
/*   Invalid section offset encountered. */
/*  */
#define TLR_E_MODULE_INVALID_SECTION_OFFSET_ENCOUNTERED ((TLR_RESULT)0xC02B0049L)

/*  */
/*  MessageId: TLR_E_MODULE_UNSUPPORTED_RELOC_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Unsupported reloc type. */
/*  */
#define TLR_E_MODULE_UNSUPPORTED_RELOC_TYPE ((TLR_RESULT)0xC02B004AL)

/*  */
/*  MessageId: TLR_E_MODULE_RELOC_DISTANCE_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Reloc distance too long. */
/*  */
#define TLR_E_MODULE_RELOC_DISTANCE_TOO_LONG ((TLR_RESULT)0xC02B004BL)

/*  */
/*  MessageId: TLR_E_MODULE_RELOC_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Reloc error. */
/*  */
#define TLR_E_MODULE_RELOC_ERROR         ((TLR_RESULT)0xC02B004CL)

/*  */
/*  MessageId: TLR_E_MODULE_SHT_RELA_NOT_SUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   Rela relocs not supported. */
/*  */
#define TLR_E_MODULE_SHT_RELA_NOT_SUPPORTED ((TLR_RESULT)0xC02B004DL)

/*  */
/*  MessageId: TLR_E_MODULE_SPECIAL_SYM_PARSE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Special syms could not be parsed. */
/*  */
#define TLR_E_MODULE_SPECIAL_SYM_PARSE_ERROR ((TLR_RESULT)0xC02B004EL)

/*  */
/*  MessageId: TLR_E_MODULE_MISSING_SPECIAL_SYMS */
/*  */
/*  MessageText: */
/*  */
/*   Missing special symbols in ELF symtab. */
/*  */
#define TLR_E_MODULE_MISSING_SPECIAL_SYMS ((TLR_RESULT)0xC02B004FL)

/*  */
/*  MessageId: TLR_E_MODULE_RCX_JUMP_TABLE_IS_SHORTER_THAN_EXPECTED */
/*  */
/*  MessageText: */
/*  */
/*   rcX Jump table is shorter than expected. */
/*  */
#define TLR_E_MODULE_RCX_JUMP_TABLE_IS_SHORTER_THAN_EXPECTED ((TLR_RESULT)0xC02B0050L)

/*  */
/*  MessageId: TLR_E_MODULE_LIBC_JUMP_TABLE_IS_SHORTER_THAN_EXPECTED */
/*  */
/*  MessageText: */
/*  */
/*   libc Jump table is shorter than expected. */
/*  */
#define TLR_E_MODULE_LIBC_JUMP_TABLE_IS_SHORTER_THAN_EXPECTED ((TLR_RESULT)0xC02B0051L)

/*  */
/*  MessageId: TLR_E_MODULE_TASK_GROUP_RANGE_DOES_NOT_MATCH_STATIC_TASK_TABLE */
/*  */
/*  MessageText: */
/*  */
/*   Task Group Range does not match static task table. */
/*  */
#define TLR_E_MODULE_TASK_GROUP_RANGE_DOES_NOT_MATCH_STATIC_TASK_TABLE ((TLR_RESULT)0xC02B0052L)

/*  */
/*  MessageId: TLR_E_MODULE_INTERRUPT_GROUP_RANGE_DOES_NOT_MATCH_INTERRUPT_TABLE */
/*  */
/*  MessageText: */
/*  */
/*   Interrupt Group Range does not match interrupt table. */
/*  */
#define TLR_E_MODULE_INTERRUPT_GROUP_RANGE_DOES_NOT_MATCH_INTERRUPT_TABLE ((TLR_RESULT)0xC02B0053L)

/*  */
/*  MessageId: TLR_E_MODULE_INTERRUPT_GROUP_TASK_RANGE_DOES_NOT_MATCH_INTERRUPT_TABLE */
/*  */
/*  MessageText: */
/*  */
/*   Interrupt Group Task-Range does not match interrupt table. */
/*  */
#define TLR_E_MODULE_INTERRUPT_GROUP_TASK_RANGE_DOES_NOT_MATCH_INTERRUPT_TABLE ((TLR_RESULT)0xC02B0054L)

/*  */
/*  MessageId: TLR_E_MODULE_LED_TAG_TOO_SHORT */
/*  */
/*  MessageText: */
/*  */
/*   LED-Tag is too short. */
/*  */
#define TLR_E_MODULE_LED_TAG_TOO_SHORT   ((TLR_RESULT)0xC02B0055L)

/*  */
/*  MessageId: TLR_E_MODULE_LED_TAG_CONTAINS_INVALID_PARAMETERS */
/*  */
/*  MessageText: */
/*  */
/*   LED-Tag contains invalid parameters. */
/*  */
#define TLR_E_MODULE_LED_TAG_CONTAINS_INVALID_PARAMETERS ((TLR_RESULT)0xC02B0056L)

/*  */
/*  MessageId: TLR_E_MODULE_CONTAINS_UNSUPPORTED_COMMON_SYMBOL */
/*  */
/*  MessageText: */
/*  */
/*   Module contains unsupported *COM* symbol. */
/*  */
#define TLR_E_MODULE_CONTAINS_UNSUPPORTED_COMMON_SYMBOL ((TLR_RESULT)0xC02B0057L)

/*  */
/*  MessageId: TLR_E_RCX_DEVICE_CLASS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Device class in file header does not match target. */
/*  */
#define TLR_E_RCX_DEVICE_CLASS_INVALID   ((TLR_RESULT)0xC02B0058L)

/*  */
/*  MessageId: TLR_E_RCX_MFG_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Manufacturer in file header does not match target. */
/*  */
#define TLR_E_RCX_MFG_INVALID            ((TLR_RESULT)0xC02B0059L)

/*  */
/*  MessageId: TLR_E_RCX_HW_COMPATIBILITY_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Hardware compatibility index in file header does not match target. */
/*  */
#define TLR_E_RCX_HW_COMPATIBILITY_INVALID ((TLR_RESULT)0xC02B005AL)

/*  */
/*  MessageId: TLR_E_RCX_HW_OPTIONS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Hardware options in file header does not match target. */
/*  */
#define TLR_E_RCX_HW_OPTIONS_INVALID     ((TLR_RESULT)0xC02B005BL)

/*  */
/*  MessageId: TLR_E_RCX_SECURITY_EEPROM_ZONE_NOT_READABLE */
/*  */
/*  MessageText: */
/*  */
/*   Security Eeprom Zone is not readable. */
/*  */
#define TLR_E_RCX_SECURITY_EEPROM_ZONE_NOT_READABLE ((TLR_RESULT)0xC02B4D52L)

/*  */
/*  MessageId: TLR_E_RCX_FILE_TRANSFER_IN_USE */
/*  */
/*  MessageText: */
/*  */
/*   File Transfer in use. */
/*  */
#define TLR_E_RCX_FILE_TRANSFER_IN_USE   ((TLR_RESULT)0xC02B524CL)

/*  */
/*  MessageId: TLR_E_RCX_FILE_TRANSFER_PACKET_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   File Transfer Packet invalid. */
/*  */
#define TLR_E_RCX_FILE_TRANSFER_PACKET_INVALID ((TLR_RESULT)0xC02B4444L)

/*  */
/*  MessageId: TLR_E_RCX_FILE_TRANSFER_NOT_ACTIVE */
/*  */
/*  MessageText: */
/*  */
/*   File Transfer is not active. */
/*  */
#define TLR_E_RCX_FILE_TRANSFER_NOT_ACTIVE ((TLR_RESULT)0xC02B5342L)

/*  */
/*  MessageId: TLR_E_RCX_FILE_TRANSFER_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   File Transfer has invalid type code. */
/*  */
#define TLR_E_RCX_FILE_TRANSFER_INVALID  ((TLR_RESULT)0xC02B5257L)

/*  */
/*  MessageId: TLR_E_RCX_FILE_CRC_REPEATEDLY_WRONG */
/*  */
/*  MessageText: */
/*  */
/*   File Transfer was tried repeatedly with a wrong CRC. */
/*  */
#define TLR_E_RCX_FILE_CRC_REPEATEDLY_WRONG ((TLR_RESULT)0xC02B4352L)

/*  */
/*  MessageId: TLR_E_RCX_FILE_TRANSFER_TYPE_NOT_AVAILABLE */
/*  */
/*  MessageText: */
/*  */
/*   Transfer Type is not available. */
/*  */
#define TLR_E_RCX_FILE_TRANSFER_TYPE_NOT_AVAILABLE ((TLR_RESULT)0xC02B4353L)

/*  */
/*  MessageId: TLR_E_RCX_PATH_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   File Path submitted in File Transfer was invalid. */
/*  */
#define TLR_E_RCX_PATH_INVALID           ((TLR_RESULT)0xC02B5555L)

/*  */
/*  MessageId: TLR_E_RCX_DRIVER_CFG_TABLE_INIT_FUNCTION_MISSING */
/*  */
/*  MessageText: */
/*  */
/*   Driver Configuration Table Init Function missing. */
/*  */
#define TLR_E_RCX_DRIVER_CFG_TABLE_INIT_FUNCTION_MISSING ((TLR_RESULT)0xC02BFFFFL)

/*  */
/*  MessageId: TLR_E_RCX_CONFIGURATION_LOCKED */
/*  */
/*  MessageText: */
/*  */
/*   Configuration has been locked. */
/*  */
#define TLR_E_RCX_CONFIGURATION_LOCKED   ((TLR_RESULT)0xC02B4B54L)

/*  */
/*  MessageId: TLR_E_RCX_NOT_ENOUGH_SPACE_FOR_FILE */
/*  */
/*  MessageText: */
/*  */
/*   Not enough space on volume for file. */
/*  */
#define TLR_E_RCX_NOT_ENOUGH_SPACE_FOR_FILE ((TLR_RESULT)0xC02B4242L)




#endif  /* __RCX_ERROR_H */

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  rcX Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_RCX_RX_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   RX_TIMEOUT. */
/*  */
#define TLR_E_RCX_RX_TIMEOUT             ((TLR_RESULT)0x00000001L)

/*  */
/*  MessageId: TLR_E_RCX_RX_GET_NO_TOKEN */
/*  */
/*  MessageText: */
/*  */
/*   RX_GET_NO_TOKEN. */
/*  */
#define TLR_E_RCX_RX_GET_NO_TOKEN        ((TLR_RESULT)0x00000002L)

/*  */
/*  MessageId: TLR_E_RCX_RX_KNL_PRIORITY_EXIST */
/*  */
/*  MessageText: */
/*  */
/*   RX_KNL_PRIORITY_EXIST. */
/*  */
#define TLR_E_RCX_RX_KNL_PRIORITY_EXIST  ((TLR_RESULT)0x00000003L)

/*  */
/*  MessageId: TLR_E_RCX_RX_KNL_PRIORITY_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_KNL_PRIORITY_INVALID. */
/*  */
#define TLR_E_RCX_RX_KNL_PRIORITY_INVALID ((TLR_RESULT)0x00000004L)

/*  */
/*  MessageId: TLR_E_RCX_RX_KNL_PRIORITY_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   RX_KNL_PRIORITY_ERROR. */
/*  */
#define TLR_E_RCX_RX_KNL_PRIORITY_ERROR  ((TLR_RESULT)0x00000005L)

/*  */
/*  MessageId: TLR_E_RCX_RX_KNL_TASK_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   RX_KNL_TASK_UNKNOWN. */
/*  */
#define TLR_E_RCX_RX_KNL_TASK_UNKNOWN    ((TLR_RESULT)0x00000006L)

/*  */
/*  MessageId: TLR_E_RCX_RX_KNL_TASK_NOT_BLOCKED */
/*  */
/*  MessageText: */
/*  */
/*   RX_KNL_TASK_NOT_BLOCKED. */
/*  */
#define TLR_E_RCX_RX_KNL_TASK_NOT_BLOCKED ((TLR_RESULT)0x00000007L)

/*  */
/*  MessageId: TLR_E_RCX_RX_KNL_STACK_UNDERRUN */
/*  */
/*  MessageText: */
/*  */
/*   RX_KNL_STACK_UNDERRUN. */
/*  */
#define TLR_E_RCX_RX_KNL_STACK_UNDERRUN  ((TLR_RESULT)0x00000008L)

/*  */
/*  MessageId: TLR_E_RCX_RX_KNL_TASK_BLOCKED */
/*  */
/*  MessageText: */
/*  */
/*   RX_KNL_TASK_BLOCKED. */
/*  */
#define TLR_E_RCX_RX_KNL_TASK_BLOCKED    ((TLR_RESULT)0x00000009L)

/*  */
/*  MessageId: TLR_E_RCX_RX_KNL_TOKEN_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_KNL_TOKEN_INVALID. */
/*  */
#define TLR_E_RCX_RX_KNL_TOKEN_INVALID   ((TLR_RESULT)0x0000000AL)

/*  */
/*  MessageId: TLR_E_RCX_RX_KNL_TOKEN_DOUBLE */
/*  */
/*  MessageText: */
/*  */
/*   RX_KNL_TOKEN_DOUBLE. */
/*  */
#define TLR_E_RCX_RX_KNL_TOKEN_DOUBLE    ((TLR_RESULT)0x0000000BL)

/*  */
/*  MessageId: TLR_E_RCX_RX_KNL_TASK_DOWN */
/*  */
/*  MessageText: */
/*  */
/*   RX_KNL_TASK_DOWN. */
/*  */
#define TLR_E_RCX_RX_KNL_TASK_DOWN       ((TLR_RESULT)0x0000000CL)

/*  */
/*  MessageId: TLR_E_RCX_RX_KNL_PRIOTYPE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_KNL_PRIOTYPE_INVALID. */
/*  */
#define TLR_E_RCX_RX_KNL_PRIOTYPE_INVALID ((TLR_RESULT)0x0000000DL)

/*  */
/*  MessageId: TLR_E_RCX_RX_KNL_PRIOLEVEL_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_KNL_PRIOLEVEL_INVALID. */
/*  */
#define TLR_E_RCX_RX_KNL_PRIOLEVEL_INVALID ((TLR_RESULT)0x0000000EL)

/*  */
/*  MessageId: TLR_E_RCX_RX_KNL_PRIORITY_RESOURCE */
/*  */
/*  MessageText: */
/*  */
/*   RX_KNL_PRIORITY_RESOURCE. */
/*  */
#define TLR_E_RCX_RX_KNL_PRIORITY_RESOURCE ((TLR_RESULT)0x0000000FL)

/*  */
/*  MessageId: TLR_E_RCX_RX_KNL_TOKEN_RESOURCE */
/*  */
/*  MessageText: */
/*  */
/*   RX_KNL_TOKEN_RESOURCE. */
/*  */
#define TLR_E_RCX_RX_KNL_TOKEN_RESOURCE  ((TLR_RESULT)0x00000010L)

/*  */
/*  MessageId: TLR_E_RCX_RX_KNL_KEEP_HOOK */
/*  */
/*  MessageText: */
/*  */
/*   RX_KNL_KEEP_HOOK. */
/*  */
#define TLR_E_RCX_RX_KNL_KEEP_HOOK       ((TLR_RESULT)0x00000011L)

/*  */
/*  MessageId: TLR_E_RCX_RX_KNL_TASK_REACTIVATION */
/*  */
/*  MessageText: */
/*  */
/*   RX_KNL_TASK_REACTIVATION. */
/*  */
#define TLR_E_RCX_RX_KNL_TASK_REACTIVATION ((TLR_RESULT)0x00000012L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MEM_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   RX_MEM_NO_INIT. */
/*  */
#define TLR_E_RCX_RX_MEM_NO_INIT         ((TLR_RESULT)0x00000100L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MEM_NAME */
/*  */
/*  MessageText: */
/*  */
/*   RX_MEM_NAME. */
/*  */
#define TLR_E_RCX_RX_MEM_NAME            ((TLR_RESULT)0x00000101L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MEM_ERR */
/*  */
/*  MessageText: */
/*  */
/*   RX_MEM_ERR. */
/*  */
#define TLR_E_RCX_RX_MEM_ERR             ((TLR_RESULT)0x00000102L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MEM_RESOURCE */
/*  */
/*  MessageText: */
/*  */
/*   RX_MEM_RESOURCE. */
/*  */
#define TLR_E_RCX_RX_MEM_RESOURCE        ((TLR_RESULT)0x00000103L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MEM_ALLOCATE_HEAP_ERR */
/*  */
/*  MessageText: */
/*  */
/*   RX_MEM_ALLOCATE_HEAP_ERR. */
/*  */
#define TLR_E_RCX_RX_MEM_ALLOCATE_HEAP_ERR ((TLR_RESULT)0x00000104L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MEM_FREE_HEAP_ERR */
/*  */
/*  MessageText: */
/*  */
/*   RX_MEM_FREE_HEAP_ERR. */
/*  */
#define TLR_E_RCX_RX_MEM_FREE_HEAP_ERR   ((TLR_RESULT)0x00000105L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MEM_ALLOCATE_SIZE_ERR */
/*  */
/*  MessageText: */
/*  */
/*   RX_MEM_ALLOCATE_SIZE_ERR. */
/*  */
#define TLR_E_RCX_RX_MEM_ALLOCATE_SIZE_ERR ((TLR_RESULT)0x00000106L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MEM_FREE_SIZE_ERR */
/*  */
/*  MessageText: */
/*  */
/*   RX_MEM_FREE_SIZE_ERR. */
/*  */
#define TLR_E_RCX_RX_MEM_FREE_SIZE_ERR   ((TLR_RESULT)0x00000107L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MEM_MEMORY_BLOCKS */
/*  */
/*  MessageText: */
/*  */
/*   RX_MEM_MEMORY_BLOCKS. */
/*  */
#define TLR_E_RCX_RX_MEM_MEMORY_BLOCKS   ((TLR_RESULT)0x00000108L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MEM_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   RX_MEM_UNKNOWN. */
/*  */
#define TLR_E_RCX_RX_MEM_UNKNOWN         ((TLR_RESULT)0x00000109L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MEM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_MEM_INVALID. */
/*  */
#define TLR_E_RCX_RX_MEM_INVALID         ((TLR_RESULT)0x0000010AL)

/*  */
/*  MessageId: TLR_E_RCX_RX_MEM_NO_ACCESS */
/*  */
/*  MessageText: */
/*  */
/*   RX_MEM_NO_ACCESS. */
/*  */
#define TLR_E_RCX_RX_MEM_NO_ACCESS       ((TLR_RESULT)0x0000010BL)

/*  */
/*  MessageId: TLR_E_RCX_RX_MEM_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   RX_MEM_TIMEOUT. */
/*  */
#define TLR_E_RCX_RX_MEM_TIMEOUT         ((TLR_RESULT)0x0000010CL)

/*  */
/*  MessageId: TLR_E_RCX_RX_MEM_DELETED */
/*  */
/*  MessageText: */
/*  */
/*   RX_MEM_DELETED. */
/*  */
#define TLR_E_RCX_RX_MEM_DELETED         ((TLR_RESULT)0x0000010DL)

/*  */
/*  MessageId: TLR_E_RCX_RX_MEM_INVALID_CALLER */
/*  */
/*  MessageText: */
/*  */
/*   RX_MEM_INVALID_CALLER. */
/*  */
#define TLR_E_RCX_RX_MEM_INVALID_CALLER  ((TLR_RESULT)0x0000010EL)

/*  */
/*  MessageId: TLR_E_RCX_RX_MEM_NO_UPDATE */
/*  */
/*  MessageText: */
/*  */
/*   RX_MEM_NO_UPDATE. */
/*  */
#define TLR_E_RCX_RX_MEM_NO_UPDATE       ((TLR_RESULT)0x0000010FL)

/*  */
/*  MessageId: TLR_E_RCX_RX_MEM_NO_BUFFER */
/*  */
/*  MessageText: */
/*  */
/*   RX_MEM_NO_BUFFER. */
/*  */
#define TLR_E_RCX_RX_MEM_NO_BUFFER       ((TLR_RESULT)0x00000110L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MEM_MEMORY_NAME */
/*  */
/*  MessageText: */
/*  */
/*   RX_MEM_MEMORY_NAME. */
/*  */
#define TLR_E_RCX_RX_MEM_MEMORY_NAME     ((TLR_RESULT)0x00000111L)

/*  */
/*  MessageId: TLR_E_RCX_RX_TIM_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   RX_TIM_NO_INIT. */
/*  */
#define TLR_E_RCX_RX_TIM_NO_INIT         ((TLR_RESULT)0x00000200L)

/*  */
/*  MessageId: TLR_E_RCX_RX_TIM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_TIM_INVALID. */
/*  */
#define TLR_E_RCX_RX_TIM_INVALID         ((TLR_RESULT)0x00000201L)

/*  */
/*  MessageId: TLR_E_RCX_RX_TIM_INVALID_CALLER */
/*  */
/*  MessageText: */
/*  */
/*   RX_TIM_INVALID_CALLER. */
/*  */
#define TLR_E_RCX_RX_TIM_INVALID_CALLER  ((TLR_RESULT)0x00000202L)

/*  */
/*  MessageId: TLR_E_RCX_RX_TIM_ZERO */
/*  */
/*  MessageText: */
/*  */
/*   RX_TIM_ZERO. */
/*  */
#define TLR_E_RCX_RX_TIM_ZERO            ((TLR_RESULT)0x00000203L)

/*  */
/*  MessageId: TLR_E_RCX_RX_TIM_ALRDY_CLR */
/*  */
/*  MessageText: */
/*  */
/*   RX_TIM_ALRDY_CLR. */
/*  */
#define TLR_E_RCX_RX_TIM_ALRDY_CLR       ((TLR_RESULT)0x00000204L)

/*  */
/*  MessageId: TLR_E_RCX_RX_TIM_NO_EVE_HDLR */
/*  */
/*  MessageText: */
/*  */
/*   RX_TIM_NO_EVE_HDLR. */
/*  */
#define TLR_E_RCX_RX_TIM_NO_EVE_HDLR     ((TLR_RESULT)0x00000205L)

/*  */
/*  MessageId: TLR_E_RCX_RX_TIM_NOT_HALTED */
/*  */
/*  MessageText: */
/*  */
/*   RX_TIM_NOT_HALTED. */
/*  */
#define TLR_E_RCX_RX_TIM_NOT_HALTED      ((TLR_RESULT)0x00000206L)

/*  */
/*  MessageId: TLR_E_RCX_RX_TIM_NAME */
/*  */
/*  MessageText: */
/*  */
/*   RX_TIM_NAME. */
/*  */
#define TLR_E_RCX_RX_TIM_NAME            ((TLR_RESULT)0x00000207L)

/*  */
/*  MessageId: TLR_E_RCX_RX_TIM_CYCLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_TIM_CYCLE_INVALID. */
/*  */
#define TLR_E_RCX_RX_TIM_CYCLE_INVALID   ((TLR_RESULT)0x00000208L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_NO_INIT. */
/*  */
#define TLR_E_RCX_RX_MBX_NO_INIT         ((TLR_RESULT)0x00000300L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_NAME */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_NAME. */
/*  */
#define TLR_E_RCX_RX_MBX_NAME            ((TLR_RESULT)0x00000301L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_INVALID. */
/*  */
#define TLR_E_RCX_RX_MBX_INVALID         ((TLR_RESULT)0x00000302L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_DELETED */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_DELETED. */
/*  */
#define TLR_E_RCX_RX_MBX_DELETED         ((TLR_RESULT)0x00000303L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_INVALID_CALLER */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_INVALID_CALLER. */
/*  */
#define TLR_E_RCX_RX_MBX_INVALID_CALLER  ((TLR_RESULT)0x00000304L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_TIMEOUT. */
/*  */
#define TLR_E_RCX_RX_MBX_TIMEOUT         ((TLR_RESULT)0x00000305L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_UNKNOWN. */
/*  */
#define TLR_E_RCX_RX_MBX_UNKNOWN         ((TLR_RESULT)0x00000306L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_MSG_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_MSG_INVALID. */
/*  */
#define TLR_E_RCX_RX_MBX_MSG_INVALID     ((TLR_RESULT)0x00000307L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_SEG_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_SEG_INVALID. */
/*  */
#define TLR_E_RCX_RX_MBX_SEG_INVALID     ((TLR_RESULT)0x00000308L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_INTGY_LOAD */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_INTGY_LOAD. */
/*  */
#define TLR_E_RCX_RX_MBX_INTGY_LOAD      ((TLR_RESULT)0x00000309L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_INTGY_DOUBLE */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_INTGY_DOUBLE. */
/*  */
#define TLR_E_RCX_RX_MBX_INTGY_DOUBLE    ((TLR_RESULT)0x0000030AL)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_QUE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_QUE_INVALID. */
/*  */
#define TLR_E_RCX_RX_MBX_QUE_INVALID     ((TLR_RESULT)0x0000030BL)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_QUE_EMPTY */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_QUE_EMPTY. */
/*  */
#define TLR_E_RCX_RX_MBX_QUE_EMPTY       ((TLR_RESULT)0x0000030CL)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_QUE_INTGY_LOAD */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_QUE_INTGY_LOAD. */
/*  */
#define TLR_E_RCX_RX_MBX_QUE_INTGY_LOAD  ((TLR_RESULT)0x0000030DL)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_ALRDY_CLR */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_ALRDY_CLR. */
/*  */
#define TLR_E_RCX_RX_MBX_ALRDY_CLR       ((TLR_RESULT)0x0000030EL)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_NO_EVENTHDLR */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_NO_EVENTHDLR. */
/*  */
#define TLR_E_RCX_RX_MBX_NO_EVENTHDLR    ((TLR_RESULT)0x0000030FL)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_EMPTY */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_EMPTY. */
/*  */
#define TLR_E_RCX_RX_MBX_EMPTY           ((TLR_RESULT)0x00000310L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_NO_SEGMENT */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_NO_SEGMENT. */
/*  */
#define TLR_E_RCX_RX_MBX_NO_SEGMENT      ((TLR_RESULT)0x00000311L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_NO_EVE_HDLR */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_NO_EVE_HDLR. */
/*  */
#define TLR_E_RCX_RX_MBX_NO_EVE_HDLR     ((TLR_RESULT)0x00000312L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_TYPE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_TYPE_ERROR. */
/*  */
#define TLR_E_RCX_RX_MBX_TYPE_ERROR      ((TLR_RESULT)0x00000313L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_PARENT_CONFLICT */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_PARENT_CONFLICT. */
/*  */
#define TLR_E_RCX_RX_MBX_PARENT_CONFLICT ((TLR_RESULT)0x00000314L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_SEG_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_SEG_TIMEOUT. */
/*  */
#define TLR_E_RCX_RX_MBX_SEG_TIMEOUT     ((TLR_RESULT)0x00000315L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_NOT_INSTALLED */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_NOT_INSTALLED. */
/*  */
#define TLR_E_RCX_RX_MBX_NOT_INSTALLED   ((TLR_RESULT)0x00000316L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MBX_MAILBOX_LIMIT */
/*  */
/*  MessageText: */
/*  */
/*   RX_MBX_MAILBOX_LIMIT. */
/*  */
#define TLR_E_RCX_RX_MBX_MAILBOX_LIMIT   ((TLR_RESULT)0x00000317L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SER_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   RX_SER_NO_INIT. */
/*  */
#define TLR_E_RCX_RX_SER_NO_INIT         ((TLR_RESULT)0x00000400L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SER_NAME */
/*  */
/*  MessageText: */
/*  */
/*   RX_SER_NAME. */
/*  */
#define TLR_E_RCX_RX_SER_NAME            ((TLR_RESULT)0x00000401L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SER_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_SER_INVALID. */
/*  */
#define TLR_E_RCX_RX_SER_INVALID         ((TLR_RESULT)0x00000402L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SER_DELETED */
/*  */
/*  MessageText: */
/*  */
/*   RX_SER_DELETED. */
/*  */
#define TLR_E_RCX_RX_SER_DELETED         ((TLR_RESULT)0x00000403L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SER_INVALID_CALLER */
/*  */
/*  MessageText: */
/*  */
/*   RX_SER_INVALID_CALLER. */
/*  */
#define TLR_E_RCX_RX_SER_INVALID_CALLER  ((TLR_RESULT)0x00000404L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SER_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   RX_SER_TIMEOUT. */
/*  */
#define TLR_E_RCX_RX_SER_TIMEOUT         ((TLR_RESULT)0x00000405L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SER_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   RX_SER_UNKNOWN. */
/*  */
#define TLR_E_RCX_RX_SER_UNKNOWN         ((TLR_RESULT)0x00000406L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SER_RESOURCE */
/*  */
/*  MessageText: */
/*  */
/*   RX_SER_RESOURCE. */
/*  */
#define TLR_E_RCX_RX_SER_RESOURCE        ((TLR_RESULT)0x00000407L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SER_OVERRUN */
/*  */
/*  MessageText: */
/*  */
/*   RX_SER_OVERRUN. */
/*  */
#define TLR_E_RCX_RX_SER_OVERRUN         ((TLR_RESULT)0x00000408L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SER_NO_TASK_PENDING */
/*  */
/*  MessageText: */
/*  */
/*   RX_SER_NO_TASK_PENDING. */
/*  */
#define TLR_E_RCX_RX_SER_NO_TASK_PENDING ((TLR_RESULT)0x00000409L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SER_CONF_PENDING */
/*  */
/*  MessageText: */
/*  */
/*   RX_SER_CONF_PENDING. */
/*  */
#define TLR_E_RCX_RX_SER_CONF_PENDING    ((TLR_RESULT)0x0000040AL)

/*  */
/*  MessageId: TLR_E_RCX_RX_SER_NO_LOAD */
/*  */
/*  MessageText: */
/*  */
/*   RX_SER_NO_LOAD. */
/*  */
#define TLR_E_RCX_RX_SER_NO_LOAD         ((TLR_RESULT)0x0000040BL)

/*  */
/*  MessageId: TLR_E_RCX_RX_SER_ACCESS_DENIED */
/*  */
/*  MessageText: */
/*  */
/*   RX_SER_ACCESS_DENIED. */
/*  */
#define TLR_E_RCX_RX_SER_ACCESS_DENIED   ((TLR_RESULT)0x0000040CL)

/*  */
/*  MessageId: TLR_E_RCX_RX_SER_FULL */
/*  */
/*  MessageText: */
/*  */
/*   RX_SER_FULL. */
/*  */
#define TLR_E_RCX_RX_SER_FULL            ((TLR_RESULT)0x0000040DL)

/*  */
/*  MessageId: TLR_E_RCX_RX_SER_OVERRUN_WARN */
/*  */
/*  MessageText: */
/*  */
/*   RX_SER_OVERRUN_WARN. */
/*  */
#define TLR_E_RCX_RX_SER_OVERRUN_WARN    ((TLR_RESULT)0x0000040EL)

/*  */
/*  MessageId: TLR_E_RCX_RX_SEM_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   RX_SEM_NO_INIT. */
/*  */
#define TLR_E_RCX_RX_SEM_NO_INIT         ((TLR_RESULT)0x00000500L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SEM_NAME */
/*  */
/*  MessageText: */
/*  */
/*   RX_SEM_NAME. */
/*  */
#define TLR_E_RCX_RX_SEM_NAME            ((TLR_RESULT)0x00000501L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SEM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_SEM_INVALID. */
/*  */
#define TLR_E_RCX_RX_SEM_INVALID         ((TLR_RESULT)0x00000502L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SEM_DELETED */
/*  */
/*  MessageText: */
/*  */
/*   RX_SEM_DELETED. */
/*  */
#define TLR_E_RCX_RX_SEM_DELETED         ((TLR_RESULT)0x00000503L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SEM_INVALID_CALLER */
/*  */
/*  MessageText: */
/*  */
/*   RX_SEM_INVALID_CALLER. */
/*  */
#define TLR_E_RCX_RX_SEM_INVALID_CALLER  ((TLR_RESULT)0x00000504L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SEM_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   RX_SEM_TIMEOUT. */
/*  */
#define TLR_E_RCX_RX_SEM_TIMEOUT         ((TLR_RESULT)0x00000505L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SEM_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   RX_SEM_UNKNOWN. */
/*  */
#define TLR_E_RCX_RX_SEM_UNKNOWN         ((TLR_RESULT)0x00000506L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SEM_OVERFLOW */
/*  */
/*  MessageText: */
/*  */
/*   RX_SEM_OVERFLOW. */
/*  */
#define TLR_E_RCX_RX_SEM_OVERFLOW        ((TLR_RESULT)0x00000507L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SEM_NOT_AVAILABLE */
/*  */
/*  MessageText: */
/*  */
/*   RX_SEM_NOT_AVAILABLE. */
/*  */
#define TLR_E_RCX_RX_SEM_NOT_AVAILABLE   ((TLR_RESULT)0x00000508L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SEM_INTGY_SEM */
/*  */
/*  MessageText: */
/*  */
/*   RX_SEM_INTGY_SEM. */
/*  */
#define TLR_E_RCX_RX_SEM_INTGY_SEM       ((TLR_RESULT)0x00000509L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SEM_ALRDY_CLR */
/*  */
/*  MessageText: */
/*  */
/*   RX_SEM_ALRDY_CLR. */
/*  */
#define TLR_E_RCX_RX_SEM_ALRDY_CLR       ((TLR_RESULT)0x0000050AL)

/*  */
/*  MessageId: TLR_E_RCX_RX_SEM_NO_COUNT */
/*  */
/*  MessageText: */
/*  */
/*   RX_SEM_NO_COUNT. */
/*  */
#define TLR_E_RCX_RX_SEM_NO_COUNT        ((TLR_RESULT)0x0000050BL)

/*  */
/*  MessageId: TLR_E_RCX_RX_SEM_NO_EVE_HDLR */
/*  */
/*  MessageText: */
/*  */
/*   RX_SEM_NO_EVE_HDLR. */
/*  */
#define TLR_E_RCX_RX_SEM_NO_EVE_HDLR     ((TLR_RESULT)0x0000050CL)

/*  */
/*  MessageId: TLR_E_RCX_RX_MTX_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   RX_MTX_NO_INIT. */
/*  */
#define TLR_E_RCX_RX_MTX_NO_INIT         ((TLR_RESULT)0x00000600L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MTX_NAME */
/*  */
/*  MessageText: */
/*  */
/*   RX_MTX_NAME. */
/*  */
#define TLR_E_RCX_RX_MTX_NAME            ((TLR_RESULT)0x00000601L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MTX_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_MTX_INVALID. */
/*  */
#define TLR_E_RCX_RX_MTX_INVALID         ((TLR_RESULT)0x00000602L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MTX_DELETED */
/*  */
/*  MessageText: */
/*  */
/*   RX_MTX_DELETED. */
/*  */
#define TLR_E_RCX_RX_MTX_DELETED         ((TLR_RESULT)0x00000603L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MTX_INVALID_CALLER */
/*  */
/*  MessageText: */
/*  */
/*   RX_MTX_INVALID_CALLER. */
/*  */
#define TLR_E_RCX_RX_MTX_INVALID_CALLER  ((TLR_RESULT)0x00000604L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MTX_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   RX_MTX_TIMEOUT. */
/*  */
#define TLR_E_RCX_RX_MTX_TIMEOUT         ((TLR_RESULT)0x00000605L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MTX_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   RX_MTX_UNKNOWN. */
/*  */
#define TLR_E_RCX_RX_MTX_UNKNOWN         ((TLR_RESULT)0x00000606L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MTX_LOCKED */
/*  */
/*  MessageText: */
/*  */
/*   RX_MTX_LOCKED. */
/*  */
#define TLR_E_RCX_RX_MTX_LOCKED          ((TLR_RESULT)0x00000607L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MTX_OVERFLOW */
/*  */
/*  MessageText: */
/*  */
/*   RX_MTX_OVERFLOW. */
/*  */
#define TLR_E_RCX_RX_MTX_OVERFLOW        ((TLR_RESULT)0x00000608L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MTX_INTGY_MTX */
/*  */
/*  MessageText: */
/*  */
/*   RX_MTX_INTGY_MTX. */
/*  */
#define TLR_E_RCX_RX_MTX_INTGY_MTX       ((TLR_RESULT)0x00000609L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MTX_NO_EVE_HDLR */
/*  */
/*  MessageText: */
/*  */
/*   RX_MTX_NO_EVE_HDLR. */
/*  */
#define TLR_E_RCX_RX_MTX_NO_EVE_HDLR     ((TLR_RESULT)0x0000060AL)

/*  */
/*  MessageId: TLR_E_RCX_RX_MTX_ALRDY_CLR */
/*  */
/*  MessageText: */
/*  */
/*   RX_MTX_ALRDY_CLR. */
/*  */
#define TLR_E_RCX_RX_MTX_ALRDY_CLR       ((TLR_RESULT)0x0000060BL)

/*  */
/*  MessageId: TLR_E_RCX_RX_MTX_INTGY_ELMT */
/*  */
/*  MessageText: */
/*  */
/*   RX_MTX_INTGY_ELMT. */
/*  */
#define TLR_E_RCX_RX_MTX_INTGY_ELMT      ((TLR_RESULT)0x0000060CL)

/*  */
/*  MessageId: TLR_E_RCX_RX_MTX_NO_EVE_HANDLER */
/*  */
/*  MessageText: */
/*  */
/*   RX_MTX_NO_EVE_HANDLER. */
/*  */
#define TLR_E_RCX_RX_MTX_NO_EVE_HANDLER  ((TLR_RESULT)0x0000060DL)

/*  */
/*  MessageId: TLR_E_RCX_RX_MTX_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   RX_MTX_OUT_OF_MEMORY. */
/*  */
#define TLR_E_RCX_RX_MTX_OUT_OF_MEMORY   ((TLR_RESULT)0x0000060EL)

/*  */
/*  MessageId: TLR_E_RCX_RX_MTX_PROCESS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_MTX_PROCESS_INVALID. */
/*  */
#define TLR_E_RCX_RX_MTX_PROCESS_INVALID ((TLR_RESULT)0x0000060FL)

/*  */
/*  MessageId: TLR_E_RCX_RX_EVEGRP_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   RX_EVEGRP_NO_INIT. */
/*  */
#define TLR_E_RCX_RX_EVEGRP_NO_INIT      ((TLR_RESULT)0x00000700L)

/*  */
/*  MessageId: TLR_E_RCX_RX_EVEGRP_NAME */
/*  */
/*  MessageText: */
/*  */
/*   RX_EVEGRP_NAME. */
/*  */
#define TLR_E_RCX_RX_EVEGRP_NAME         ((TLR_RESULT)0x00000701L)

/*  */
/*  MessageId: TLR_E_RCX_RX_EVEGRP_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_EVEGRP_INVALID. */
/*  */
#define TLR_E_RCX_RX_EVEGRP_INVALID      ((TLR_RESULT)0x00000702L)

/*  */
/*  MessageId: TLR_E_RCX_RX_EVEGRP_DELETED */
/*  */
/*  MessageText: */
/*  */
/*   RX_EVEGRP_DELETED. */
/*  */
#define TLR_E_RCX_RX_EVEGRP_DELETED      ((TLR_RESULT)0x00000703L)

/*  */
/*  MessageId: TLR_E_RCX_RX_EVEGRP_INVALID_CALLER */
/*  */
/*  MessageText: */
/*  */
/*   RX_EVEGRP_INVALID_CALLER. */
/*  */
#define TLR_E_RCX_RX_EVEGRP_INVALID_CALLER ((TLR_RESULT)0x00000704L)

/*  */
/*  MessageId: TLR_E_RCX_RX_EVEGRP_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   RX_EVEGRP_TIMEOUT. */
/*  */
#define TLR_E_RCX_RX_EVEGRP_TIMEOUT      ((TLR_RESULT)0x00000706L)

/*  */
/*  MessageId: TLR_E_RCX_RX_EVEGRP_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   RX_EVEGRP_UNKNOWN. */
/*  */
#define TLR_E_RCX_RX_EVEGRP_UNKNOWN      ((TLR_RESULT)0x00000707L)

/*  */
/*  MessageId: TLR_E_RCX_RX_EVEGRP_NOEVENT */
/*  */
/*  MessageText: */
/*  */
/*   RX_EVEGRP_NOEVENT. */
/*  */
#define TLR_E_RCX_RX_EVEGRP_NOEVENT      ((TLR_RESULT)0x00000708L)

/*  */
/*  MessageId: TLR_E_RCX_RX_EVEGRP_ALRDY_CLR */
/*  */
/*  MessageText: */
/*  */
/*   RX_EVEGRP_ALRDY_CLR. */
/*  */
#define TLR_E_RCX_RX_EVEGRP_ALRDY_CLR    ((TLR_RESULT)0x00000709L)

/*  */
/*  MessageId: TLR_E_RCX_RX_EVEGRP_MODE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_EVEGRP_MODE_INVALID. */
/*  */
#define TLR_E_RCX_RX_EVEGRP_MODE_INVALID ((TLR_RESULT)0x0000070AL)

/*  */
/*  MessageId: TLR_E_RCX_RX_BAR_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   RX_BAR_NO_INIT. */
/*  */
#define TLR_E_RCX_RX_BAR_NO_INIT         ((TLR_RESULT)0x00000800L)

/*  */
/*  MessageId: TLR_E_RCX_RX_BAR_NAME */
/*  */
/*  MessageText: */
/*  */
/*   RX_BAR_NAME. */
/*  */
#define TLR_E_RCX_RX_BAR_NAME            ((TLR_RESULT)0x00000801L)

/*  */
/*  MessageId: TLR_E_RCX_RX_BAR_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_BAR_INVALID. */
/*  */
#define TLR_E_RCX_RX_BAR_INVALID         ((TLR_RESULT)0x00000802L)

/*  */
/*  MessageId: TLR_E_RCX_RX_BAR_DELETED */
/*  */
/*  MessageText: */
/*  */
/*   RX_BAR_DELETED. */
/*  */
#define TLR_E_RCX_RX_BAR_DELETED         ((TLR_RESULT)0x00000803L)

/*  */
/*  MessageId: TLR_E_RCX_RX_BAR_INVALID_CALLER */
/*  */
/*  MessageText: */
/*  */
/*   RX_BAR_INVALID_CALLER. */
/*  */
#define TLR_E_RCX_RX_BAR_INVALID_CALLER  ((TLR_RESULT)0x00000804L)

/*  */
/*  MessageId: TLR_E_RCX_RX_BAR_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   RX_BAR_TIMEOUT. */
/*  */
#define TLR_E_RCX_RX_BAR_TIMEOUT         ((TLR_RESULT)0x00000805L)

/*  */
/*  MessageId: TLR_E_RCX_RX_BAR_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   RX_BAR_UNKNOWN. */
/*  */
#define TLR_E_RCX_RX_BAR_UNKNOWN         ((TLR_RESULT)0x00000806L)

/*  */
/*  MessageId: TLR_E_RCX_RX_BAR_COUNT */
/*  */
/*  MessageText: */
/*  */
/*   RX_BAR_COUNT. */
/*  */
#define TLR_E_RCX_RX_BAR_COUNT           ((TLR_RESULT)0x00000807L)

/*  */
/*  MessageId: TLR_E_RCX_RX_BAR_NOT_REACHED */
/*  */
/*  MessageText: */
/*  */
/*   RX_BAR_NOT_REACHED. */
/*  */
#define TLR_E_RCX_RX_BAR_NOT_REACHED     ((TLR_RESULT)0x00000808L)

/*  */
/*  MessageId: TLR_E_RCX_RX_BAR_NO_EVE_HDLR */
/*  */
/*  MessageText: */
/*  */
/*   RX_BAR_NO_EVE_HDLR. */
/*  */
#define TLR_E_RCX_RX_BAR_NO_EVE_HDLR     ((TLR_RESULT)0x00000809L)

/*  */
/*  MessageId: TLR_E_RCX_RX_BAR_ALRDY_CLR */
/*  */
/*  MessageText: */
/*  */
/*   RX_BAR_ALRDY_CLR. */
/*  */
#define TLR_E_RCX_RX_BAR_ALRDY_CLR       ((TLR_RESULT)0x0000080AL)

/*  */
/*  MessageId: TLR_E_RCX_RX_QUE_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   RX_QUE_NO_INIT. */
/*  */
#define TLR_E_RCX_RX_QUE_NO_INIT         ((TLR_RESULT)0x00000900L)

/*  */
/*  MessageId: TLR_E_RCX_RX_QUE_NAME */
/*  */
/*  MessageText: */
/*  */
/*   RX_QUE_NAME. */
/*  */
#define TLR_E_RCX_RX_QUE_NAME            ((TLR_RESULT)0x00000901L)

/*  */
/*  MessageId: TLR_E_RCX_RX_QUE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_QUE_INVALID. */
/*  */
#define TLR_E_RCX_RX_QUE_INVALID         ((TLR_RESULT)0x00000902L)

/*  */
/*  MessageId: TLR_E_RCX_RX_QUE_DELETED */
/*  */
/*  MessageText: */
/*  */
/*   RX_QUE_DELETED. */
/*  */
#define TLR_E_RCX_RX_QUE_DELETED         ((TLR_RESULT)0x00000903L)

/*  */
/*  MessageId: TLR_E_RCX_RX_QUE_INVALID_CALLER */
/*  */
/*  MessageText: */
/*  */
/*   RX_QUE_INVALID_CALLER. */
/*  */
#define TLR_E_RCX_RX_QUE_INVALID_CALLER  ((TLR_RESULT)0x00000904L)

/*  */
/*  MessageId: TLR_E_RCX_RX_QUE_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   RX_QUE_TIMEOUT. */
/*  */
#define TLR_E_RCX_RX_QUE_TIMEOUT         ((TLR_RESULT)0x00000905L)

/*  */
/*  MessageId: TLR_E_RCX_RX_QUE_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   RX_QUE_UNKNOWN. */
/*  */
#define TLR_E_RCX_RX_QUE_UNKNOWN         ((TLR_RESULT)0x00000906L)

/*  */
/*  MessageId: TLR_E_RCX_RX_QUE_FULL */
/*  */
/*  MessageText: */
/*  */
/*   RX_QUE_FULL. */
/*  */
#define TLR_E_RCX_RX_QUE_FULL            ((TLR_RESULT)0x00000907L)

/*  */
/*  MessageId: TLR_E_RCX_RX_QUE_EMPTY */
/*  */
/*  MessageText: */
/*  */
/*   RX_QUE_EMPTY. */
/*  */
#define TLR_E_RCX_RX_QUE_EMPTY           ((TLR_RESULT)0x00000908L)

/*  */
/*  MessageId: TLR_E_RCX_RX_QUE_NO_EVE_HDLR */
/*  */
/*  MessageText: */
/*  */
/*   RX_QUE_NO_EVE_HDLR. */
/*  */
#define TLR_E_RCX_RX_QUE_NO_EVE_HDLR     ((TLR_RESULT)0x00000909L)

/*  */
/*  MessageId: TLR_E_RCX_RX_QUE_ALRDY_CLR */
/*  */
/*  MessageText: */
/*  */
/*   RX_QUE_ALRDY_CLR. */
/*  */
#define TLR_E_RCX_RX_QUE_ALRDY_CLR       ((TLR_RESULT)0x0000090AL)

/*  */
/*  MessageId: TLR_E_RCX_RX_QUE_NOT_AVAILABLE */
/*  */
/*  MessageText: */
/*  */
/*   RX_QUE_NOT_AVAILABLE. */
/*  */
#define TLR_E_RCX_RX_QUE_NOT_AVAILABLE   ((TLR_RESULT)0x0000090BL)

/*  */
/*  MessageId: TLR_E_RCX_RX_TSS_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   RX_TSS_NO_INIT. */
/*  */
#define TLR_E_RCX_RX_TSS_NO_INIT         ((TLR_RESULT)0x00000B00L)

/*  */
/*  MessageId: TLR_E_RCX_RX_TSS_EMPTY */
/*  */
/*  MessageText: */
/*  */
/*   RX_TSS_EMPTY. */
/*  */
#define TLR_E_RCX_RX_TSS_EMPTY           ((TLR_RESULT)0x00000B01L)

/*  */
/*  MessageId: TLR_E_RCX_RX_TSS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_TSS_INVALID. */
/*  */
#define TLR_E_RCX_RX_TSS_INVALID         ((TLR_RESULT)0x00000B02L)

/*  */
/*  MessageId: TLR_E_RCX_RX_TSS_TASK_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   RX_TSS_TASK_UNKNOWN. */
/*  */
#define TLR_E_RCX_RX_TSS_TASK_UNKNOWN    ((TLR_RESULT)0x00000B03L)

/*  */
/*  MessageId: TLR_E_RCX_RX_TSS_TASK_PRIORITY */
/*  */
/*  MessageText: */
/*  */
/*   RX_TSS_TASK_PRIORITY. */
/*  */
#define TLR_E_RCX_RX_TSS_TASK_PRIORITY   ((TLR_RESULT)0x00000B04L)

/*  */
/*  MessageId: TLR_E_RCX_RX_TSS_TASK_NOT_LISTED */
/*  */
/*  MessageText: */
/*  */
/*   RX_TSS_TASK_NOT_LISTED. */
/*  */
#define TLR_E_RCX_RX_TSS_TASK_NOT_LISTED ((TLR_RESULT)0x00000B05L)

/*  */
/*  MessageId: TLR_E_RCX_RX_TSS_PRIORITY_EXISTS */
/*  */
/*  MessageText: */
/*  */
/*   RX_TSS_PRIORITY_EXISTS. */
/*  */
#define TLR_E_RCX_RX_TSS_PRIORITY_EXISTS ((TLR_RESULT)0x00000B06L)

/*  */
/*  MessageId: TLR_E_RCX_RX_TSS_TASK_CREATION */
/*  */
/*  MessageText: */
/*  */
/*   RX_TSS_TASK_CREATION. */
/*  */
#define TLR_E_RCX_RX_TSS_TASK_CREATION   ((TLR_RESULT)0x00000B07L)

/*  */
/*  MessageId: TLR_E_RCX_RX_TSS_TASK_REMOVE_IDLE */
/*  */
/*  MessageText: */
/*  */
/*   RX_TSS_TASK_REMOVE_IDLE. */
/*  */
#define TLR_E_RCX_RX_TSS_TASK_REMOVE_IDLE ((TLR_RESULT)0x00000B08L)

/*  */
/*  MessageId: TLR_E_RCX_RX_TSS_PRIORITY_ASSIGNED */
/*  */
/*  MessageText: */
/*  */
/*   RX_TSS_PRIORITY_ASSIGNED. */
/*  */
#define TLR_E_RCX_RX_TSS_PRIORITY_ASSIGNED ((TLR_RESULT)0x00000B09L)

/*  */
/*  MessageId: TLR_E_RCX_RX_TSS_USAGE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_TSS_USAGE_INVALID. */
/*  */
#define TLR_E_RCX_RX_TSS_USAGE_INVALID   ((TLR_RESULT)0x00000B0AL)

/*  */
/*  MessageId: TLR_E_RCX_RX_SIG_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   RX_SIG_NO_INIT. */
/*  */
#define TLR_E_RCX_RX_SIG_NO_INIT         ((TLR_RESULT)0x00000C00L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SIG_NAME */
/*  */
/*  MessageText: */
/*  */
/*   RX_SIG_NAME. */
/*  */
#define TLR_E_RCX_RX_SIG_NAME            ((TLR_RESULT)0x00000C01L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SIG_EVENT_NOT_SET */
/*  */
/*  MessageText: */
/*  */
/*   RX_SIG_EVENT_NOT_SET. */
/*  */
#define TLR_E_RCX_RX_SIG_EVENT_NOT_SET   ((TLR_RESULT)0x00000C02L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SIG_OUTOF_EVENTS */
/*  */
/*  MessageText: */
/*  */
/*   RX_SIG_OUTOF_EVENTS. */
/*  */
#define TLR_E_RCX_RX_SIG_OUTOF_EVENTS    ((TLR_RESULT)0x00000C03L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SIG_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   RX_SIG_TIMEOUT. */
/*  */
#define TLR_E_RCX_RX_SIG_TIMEOUT         ((TLR_RESULT)0x00000C04L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SIG_EVENT_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_SIG_EVENT_INVALID. */
/*  */
#define TLR_E_RCX_RX_SIG_EVENT_INVALID   ((TLR_RESULT)0x00000C05L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SIG_EVENT_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   RX_SIG_EVENT_UNKNOWN. */
/*  */
#define TLR_E_RCX_RX_SIG_EVENT_UNKNOWN   ((TLR_RESULT)0x00000C06L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SIG_MULTI_WAIT */
/*  */
/*  MessageText: */
/*  */
/*   RX_SIG_MULTI_WAIT. */
/*  */
#define TLR_E_RCX_RX_SIG_MULTI_WAIT      ((TLR_RESULT)0x00000C07L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SIG_NOT_PRESENT */
/*  */
/*  MessageText: */
/*  */
/*   RX_SIG_NOT_PRESENT. */
/*  */
#define TLR_E_RCX_RX_SIG_NOT_PRESENT     ((TLR_RESULT)0x00000C08L)

/*  */
/*  MessageId: TLR_E_RCX_RX_FSM_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   RX_FSM_NO_INIT. */
/*  */
#define TLR_E_RCX_RX_FSM_NO_INIT         ((TLR_RESULT)0x00000D00L)

/*  */
/*  MessageId: TLR_E_RCX_RX_FSM_NAME */
/*  */
/*  MessageText: */
/*  */
/*   RX_FSM_NAME. */
/*  */
#define TLR_E_RCX_RX_FSM_NAME            ((TLR_RESULT)0x00000D01L)

/*  */
/*  MessageId: TLR_E_RCX_RX_FSM_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   RX_FSM_UNKNOWN. */
/*  */
#define TLR_E_RCX_RX_FSM_UNKNOWN         ((TLR_RESULT)0x00000D02L)

/*  */
/*  MessageId: TLR_E_RCX_RX_FSM_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   RX_FSM_NOT_INITIALIZED. */
/*  */
#define TLR_E_RCX_RX_FSM_NOT_INITIALIZED ((TLR_RESULT)0x00000D03L)

/*  */
/*  MessageId: TLR_E_RCX_RX_FSM_UNKNOWN_RETURN */
/*  */
/*  MessageText: */
/*  */
/*   RX_FSM_UNKNOWN_RETURN. */
/*  */
#define TLR_E_RCX_RX_FSM_UNKNOWN_RETURN  ((TLR_RESULT)0x00000D04L)

/*  */
/*  MessageId: TLR_E_RCX_RX_FSM_STATE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_FSM_STATE_INVALID. */
/*  */
#define TLR_E_RCX_RX_FSM_STATE_INVALID   ((TLR_RESULT)0x00000D05L)

/*  */
/*  MessageId: TLR_E_RCX_RX_FSM_NEXTSTATE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_FSM_NEXTSTATE_INVALID. */
/*  */
#define TLR_E_RCX_RX_FSM_NEXTSTATE_INVALID ((TLR_RESULT)0x00000D06L)

/*  */
/*  MessageId: TLR_E_RCX_RX_FSM_STATEMACHINE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_FSM_STATEMACHINE_INVALID. */
/*  */
#define TLR_E_RCX_RX_FSM_STATEMACHINE_INVALID ((TLR_RESULT)0x00000D07L)

/*  */
/*  MessageId: TLR_E_RCX_RX_FSM_INVALID_CALLER */
/*  */
/*  MessageText: */
/*  */
/*   RX_FSM_INVALID_CALLER. */
/*  */
#define TLR_E_RCX_RX_FSM_INVALID_CALLER  ((TLR_RESULT)0x00000D08L)

/*  */
/*  MessageId: TLR_E_RCX_RX_CPR_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   RX_CPR_NO_INIT. */
/*  */
#define TLR_E_RCX_RX_CPR_NO_INIT         ((TLR_RESULT)0x00000E00L)

/*  */
/*  MessageId: TLR_E_RCX_RX_CPR_DESTINATION_BUFFER_LEN */
/*  */
/*  MessageText: */
/*  */
/*   RX_CPR_DESTINATION_BUFFER_LEN. */
/*  */
#define TLR_E_RCX_RX_CPR_DESTINATION_BUFFER_LEN ((TLR_RESULT)0x00000E01L)

/*  */
/*  MessageId: TLR_E_RCX_RX_CRC_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   RX_CRC_NO_INIT. */
/*  */
#define TLR_E_RCX_RX_CRC_NO_INIT         ((TLR_RESULT)0x00000F00L)

/*  */
/*  MessageId: TLR_E_RCX_RX_CRC_NAME */
/*  */
/*  MessageText: */
/*  */
/*   RX_CRC_NAME. */
/*  */
#define TLR_E_RCX_RX_CRC_NAME            ((TLR_RESULT)0x00000F01L)

/*  */
/*  MessageId: TLR_E_RCX_RX_CRC_ORDER_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_CRC_ORDER_INVALID. */
/*  */
#define TLR_E_RCX_RX_CRC_ORDER_INVALID   ((TLR_RESULT)0x00000F02L)

/*  */
/*  MessageId: TLR_E_RCX_RX_CRC_POLYNOM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_CRC_POLYNOM_INVALID. */
/*  */
#define TLR_E_RCX_RX_CRC_POLYNOM_INVALID ((TLR_RESULT)0x00000F03L)

/*  */
/*  MessageId: TLR_E_RCX_RX_CRC_RESETVALUE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_CRC_RESETVALUE_INVALID. */
/*  */
#define TLR_E_RCX_RX_CRC_RESETVALUE_INVALID ((TLR_RESULT)0x00000F04L)

/*  */
/*  MessageId: TLR_E_RCX_RX_CRC_XORVALUE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_CRC_XORVALUE_INVALID. */
/*  */
#define TLR_E_RCX_RX_CRC_XORVALUE_INVALID ((TLR_RESULT)0x00000F05L)

/*  */
/*  MessageId: TLR_E_RCX_RX_CRC_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_CRC_INVALID. */
/*  */
#define TLR_E_RCX_RX_CRC_INVALID         ((TLR_RESULT)0x00000F06L)

/*  */
/*  MessageId: TLR_E_RCX_RX_DIA_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   RX_DIA_NO_INIT. */
/*  */
#define TLR_E_RCX_RX_DIA_NO_INIT         ((TLR_RESULT)0x00001000L)

/*  */
/*  MessageId: TLR_E_RCX_RX_DIA_INFO_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   RX_DIA_INFO_INVALID. */
/*  */
#define TLR_E_RCX_RX_DIA_INFO_INVALID    ((TLR_RESULT)0x00001001L)

/*  */
/*  MessageId: TLR_E_RCX_RX_DIA_NO_INFO */
/*  */
/*  MessageText: */
/*  */
/*   RX_DIA_NO_INFO. */
/*  */
#define TLR_E_RCX_RX_DIA_NO_INFO         ((TLR_RESULT)0x00001002L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MLP_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   RX_MLP_NO_INIT. */
/*  */
#define TLR_E_RCX_RX_MLP_NO_INIT         ((TLR_RESULT)0x00001100L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MLP_OBJECT_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   RX_MLP_OBJECT_UNKNOWN. */
/*  */
#define TLR_E_RCX_RX_MLP_OBJECT_UNKNOWN  ((TLR_RESULT)0x00001101L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MLP_MASK_IN_USE */
/*  */
/*  MessageText: */
/*  */
/*   RX_MLP_MASK_IN_USE. */
/*  */
#define TLR_E_RCX_RX_MLP_MASK_IN_USE     ((TLR_RESULT)0x00001102L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MLP_INVALID_MASK */
/*  */
/*  MessageText: */
/*  */
/*   RX_MLP_INVALID_MASK. */
/*  */
#define TLR_E_RCX_RX_MLP_INVALID_MASK    ((TLR_RESULT)0x00001103L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MLP_NO_EVENT */
/*  */
/*  MessageText: */
/*  */
/*   RX_MLP_NO_EVENT. */
/*  */
#define TLR_E_RCX_RX_MLP_NO_EVENT        ((TLR_RESULT)0x00001104L)

/*  */
/*  MessageId: TLR_E_RCX_RX_MLP_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   RX_MLP_TIMEOUT. */
/*  */
#define TLR_E_RCX_RX_MLP_TIMEOUT         ((TLR_RESULT)0x00001105L)

/*  */
/*  MessageId: TLR_E_RCX_RX_FLT_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   RX_FLT_NO_INIT. */
/*  */
#define TLR_E_RCX_RX_FLT_NO_INIT         ((TLR_RESULT)0x00001200L)

/*  */
/*  MessageId: TLR_E_RCX_RX_FLT_NAME */
/*  */
/*  MessageText: */
/*  */
/*   RX_FLT_NAME. */
/*  */
#define TLR_E_RCX_RX_FLT_NAME            ((TLR_RESULT)0x00001201L)

/*  */
/*  MessageId: TLR_E_RCX_RX_FLT_NO_FAULT */
/*  */
/*  MessageText: */
/*  */
/*   RX_FLT_NO_FAULT. */
/*  */
#define TLR_E_RCX_RX_FLT_NO_FAULT        ((TLR_RESULT)0x00001202L)

/*  */
/*  MessageId: TLR_E_RCX_RX_SYSTIME_TIMESTAMP_NS_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   RX_SYSTIME_TIMESTAMP_NS_ERROR. */
/*  */
#define TLR_E_RCX_RX_SYSTIME_TIMESTAMP_NS_ERROR ((TLR_RESULT)0x00001300L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_PFLS_NO_INIT       ((TLR_RESULT)0x00004000L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_NAME. */
/*  */
#define TLR_E_RCX_DRV_PFLS_NAME          ((TLR_RESULT)0x00004001L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_INVALID. */
/*  */
#define TLR_E_RCX_DRV_PFLS_INVALID       ((TLR_RESULT)0x00004002L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_PFLS_UNKNOWN       ((TLR_RESULT)0x00004003L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_ACCESS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_ACCESS_INVALID. */
/*  */
#define TLR_E_RCX_DRV_PFLS_ACCESS_INVALID ((TLR_RESULT)0x00004004L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_UNKNOWN_DATATYPE */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_UNKNOWN_DATATYPE. */
/*  */
#define TLR_E_RCX_DRV_PFLS_UNKNOWN_DATATYPE ((TLR_RESULT)0x00004005L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_UNKNOWN_ACCESS */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_UNKNOWN_ACCESS. */
/*  */
#define TLR_E_RCX_DRV_PFLS_UNKNOWN_ACCESS ((TLR_RESULT)0x00004006L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_POINTER_VIOLATION */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_POINTER_VIOLATION. */
/*  */
#define TLR_E_RCX_DRV_PFLS_POINTER_VIOLATION ((TLR_RESULT)0x00004007L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_UNKNOWN_VENDOR */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_UNKNOWN_VENDOR. */
/*  */
#define TLR_E_RCX_DRV_PFLS_UNKNOWN_VENDOR ((TLR_RESULT)0x00004008L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_UNKNOWN_DEVICE */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_UNKNOWN_DEVICE. */
/*  */
#define TLR_E_RCX_DRV_PFLS_UNKNOWN_DEVICE ((TLR_RESULT)0x00004009L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_SECTOR_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_SECTOR_INVALID. */
/*  */
#define TLR_E_RCX_DRV_PFLS_SECTOR_INVALID ((TLR_RESULT)0x0000400AL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_ERASURE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_ERASURE_FAILED. */
/*  */
#define TLR_E_RCX_DRV_PFLS_ERASURE_FAILED ((TLR_RESULT)0x0000400BL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_RAM_INSUFFICIENT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_RAM_INSUFFICIENT. */
/*  */
#define TLR_E_RCX_DRV_PFLS_RAM_INSUFFICIENT ((TLR_RESULT)0x0000400CL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_PROGRAM_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_PROGRAM_FAILED. */
/*  */
#define TLR_E_RCX_DRV_PFLS_PROGRAM_FAILED ((TLR_RESULT)0x0000400DL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_OFFSET_ODD */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_OFFSET_ODD. */
/*  */
#define TLR_E_RCX_DRV_PFLS_OFFSET_ODD    ((TLR_RESULT)0x0000400EL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_NUMBER_ODD */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_NUMBER_ODD. */
/*  */
#define TLR_E_RCX_DRV_PFLS_NUMBER_ODD    ((TLR_RESULT)0x0000400FL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_RANGE_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_RANGE_EXCEEDED. */
/*  */
#define TLR_E_RCX_DRV_PFLS_RANGE_EXCEEDED ((TLR_RESULT)0x00004010L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_PROTECTED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_PROTECTED. */
/*  */
#define TLR_E_RCX_DRV_PFLS_PROTECTED     ((TLR_RESULT)0x00004011L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_OFFSET_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_OFFSET_EXCEEDED. */
/*  */
#define TLR_E_RCX_DRV_PFLS_OFFSET_EXCEEDED ((TLR_RESULT)0x00004012L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PFLS_MAX_SECTOR_ENTRIES_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PFLS_MAX_SECTOR_ENTRIES_EXCEEDED. */
/*  */
#define TLR_E_RCX_DRV_PFLS_MAX_SECTOR_ENTRIES_EXCEEDED ((TLR_RESULT)0x00004013L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_CCH_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_CCH_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_CCH_NO_INIT        ((TLR_RESULT)0x00004080L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_CCH_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_CCH_NAME. */
/*  */
#define TLR_E_RCX_DRV_CCH_NAME           ((TLR_RESULT)0x00004081L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_CCH_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_CCH_INVALID. */
/*  */
#define TLR_E_RCX_DRV_CCH_INVALID        ((TLR_RESULT)0x00004082L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_CCH_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_CCH_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_CCH_UNKNOWN        ((TLR_RESULT)0x00004083L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_MMU_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_MMU_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_MMU_NO_INIT        ((TLR_RESULT)0x00004100L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_MMU_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_MMU_NAME. */
/*  */
#define TLR_E_RCX_DRV_MMU_NAME           ((TLR_RESULT)0x00004101L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_MMU_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_MMU_INVALID. */
/*  */
#define TLR_E_RCX_DRV_MMU_INVALID        ((TLR_RESULT)0x00004102L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_MMU_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_MMU_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_MMU_UNKNOWN        ((TLR_RESULT)0x00004103L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_TCM_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_TCM_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_TCM_NO_INIT        ((TLR_RESULT)0x00004180L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_TCM_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_TCM_NAME. */
/*  */
#define TLR_E_RCX_DRV_TCM_NAME           ((TLR_RESULT)0x00004181L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_TCM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_TCM_INVALID. */
/*  */
#define TLR_E_RCX_DRV_TCM_INVALID        ((TLR_RESULT)0x00004182L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_XC_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_XC_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_XC_NO_INIT         ((TLR_RESULT)0x00004200L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_XC_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_XC_NAME. */
/*  */
#define TLR_E_RCX_DRV_XC_NAME            ((TLR_RESULT)0x00004201L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_XC_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_XC_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_XC_UNKNOWN         ((TLR_RESULT)0x00004202L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_XC_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_XC_INVALID. */
/*  */
#define TLR_E_RCX_DRV_XC_INVALID         ((TLR_RESULT)0x00004203L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_XC_VERIFY_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   DRV_XC_VERIFY_ERROR. */
/*  */
#define TLR_E_RCX_DRV_XC_VERIFY_ERROR    ((TLR_RESULT)0x00004204L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_XC_INVALID_INSTANCE */
/*  */
/*  MessageText: */
/*  */
/*   DRV_XC_INVALID_INSTANCE. */
/*  */
#define TLR_E_RCX_DRV_XC_INVALID_INSTANCE ((TLR_RESULT)0x00004205L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_XC_IO_MEMORY_INSUFFICIENT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_XC_IO_MEMORY_INSUFFICIENT. */
/*  */
#define TLR_E_RCX_DRV_XC_IO_MEMORY_INSUFFICIENT ((TLR_RESULT)0x00004206L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_MPU_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_MPU_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_MPU_NO_INIT        ((TLR_RESULT)0x00004280L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_MPU_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_MPU_NAME. */
/*  */
#define TLR_E_RCX_DRV_MPU_NAME           ((TLR_RESULT)0x00004281L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_MPU_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_MPU_INVALID. */
/*  */
#define TLR_E_RCX_DRV_MPU_INVALID        ((TLR_RESULT)0x00004282L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PHY_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PHY_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_PHY_NO_INIT        ((TLR_RESULT)0x00004300L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PHY_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PHY_NAME. */
/*  */
#define TLR_E_RCX_DRV_PHY_NAME           ((TLR_RESULT)0x00004301L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PHY_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PHY_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_PHY_UNKNOWN        ((TLR_RESULT)0x00004302L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PHY_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PHY_INVALID. */
/*  */
#define TLR_E_RCX_DRV_PHY_INVALID        ((TLR_RESULT)0x00004303L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PHY_OUI_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PHY_OUI_INVALID. */
/*  */
#define TLR_E_RCX_DRV_PHY_OUI_INVALID    ((TLR_RESULT)0x00004304L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PHY_MODEL_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PHY_MODEL_INVALID. */
/*  */
#define TLR_E_RCX_DRV_PHY_MODEL_INVALID  ((TLR_RESULT)0x00004305L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PHY_REVISION_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PHY_REVISION_INVALID. */
/*  */
#define TLR_E_RCX_DRV_PHY_REVISION_INVALID ((TLR_RESULT)0x00004306L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PHY_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PHY_INIT_FAILED. */
/*  */
#define TLR_E_RCX_DRV_PHY_INIT_FAILED    ((TLR_RESULT)0x00004307L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PIO_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PIO_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_PIO_NO_INIT        ((TLR_RESULT)0x00004380L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PIO_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PIO_NAME. */
/*  */
#define TLR_E_RCX_DRV_PIO_NAME           ((TLR_RESULT)0x00004381L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PIO_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PIO_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_PIO_UNKNOWN        ((TLR_RESULT)0x00004382L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PIO_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PIO_INVALID. */
/*  */
#define TLR_E_RCX_DRV_PIO_INVALID        ((TLR_RESULT)0x00004383L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_PIO_NO_ACCESS */
/*  */
/*  MessageText: */
/*  */
/*   DRV_PIO_NO_ACCESS. */
/*  */
#define TLR_E_RCX_DRV_PIO_NO_ACCESS      ((TLR_RESULT)0x00004384L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_LED_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_LED_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_LED_NO_INIT        ((TLR_RESULT)0x00004400L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_LED_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_LED_NAME. */
/*  */
#define TLR_E_RCX_DRV_LED_NAME           ((TLR_RESULT)0x00004401L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_LED_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_LED_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_LED_UNKNOWN        ((TLR_RESULT)0x00004402L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_LED_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_LED_INVALID. */
/*  */
#define TLR_E_RCX_DRV_LED_INVALID        ((TLR_RESULT)0x00004403L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_LED_NO_ACCESS */
/*  */
/*  MessageText: */
/*  */
/*   DRV_LED_NO_ACCESS. */
/*  */
#define TLR_E_RCX_DRV_LED_NO_ACCESS      ((TLR_RESULT)0x00004404L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_EBUS_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_EBUS_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_EBUS_NO_INIT       ((TLR_RESULT)0x00004480L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_EBUS_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_EBUS_NAME. */
/*  */
#define TLR_E_RCX_DRV_EBUS_NAME          ((TLR_RESULT)0x00004481L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_EBUS_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_EBUS_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_EBUS_UNKNOWN       ((TLR_RESULT)0x00004482L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_EBUS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_EBUS_INVALID. */
/*  */
#define TLR_E_RCX_DRV_EBUS_INVALID       ((TLR_RESULT)0x00004483L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_HWTIM_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_HWTIM_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_HWTIM_NO_INIT      ((TLR_RESULT)0x00004500L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_HWTIM_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_HWTIM_NAME. */
/*  */
#define TLR_E_RCX_DRV_HWTIM_NAME         ((TLR_RESULT)0x00004501L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_HWTIM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_HWTIM_INVALID. */
/*  */
#define TLR_E_RCX_DRV_HWTIM_INVALID      ((TLR_RESULT)0x00004502L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_HWTIM_NO_ACCESS */
/*  */
/*  MessageText: */
/*  */
/*   DRV_HWTIM_NO_ACCESS. */
/*  */
#define TLR_E_RCX_DRV_HWTIM_NO_ACCESS    ((TLR_RESULT)0x00004503L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_HWTIM_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_HWTIM_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_HWTIM_UNKNOWN      ((TLR_RESULT)0x00004504L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_HWTIM_INVALID_CALLER */
/*  */
/*  MessageText: */
/*  */
/*   DRV_HWTIM_INVALID_CALLER. */
/*  */
#define TLR_E_RCX_DRV_HWTIM_INVALID_CALLER ((TLR_RESULT)0x00004505L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_HIF_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_HIF_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_HIF_NO_INIT        ((TLR_RESULT)0x00004580L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_HIF_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_HIF_NAME. */
/*  */
#define TLR_E_RCX_DRV_HIF_NAME           ((TLR_RESULT)0x00004581L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_HIF_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_HIF_INVALID. */
/*  */
#define TLR_E_RCX_DRV_HIF_INVALID        ((TLR_RESULT)0x00004582L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_HIF_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_HIF_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_HIF_UNKNOWN        ((TLR_RESULT)0x00004583L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_HIF_ALREADY_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_HIF_ALREADY_INITIALIZED. */
/*  */
#define TLR_E_RCX_DRV_HIF_ALREADY_INITIALIZED ((TLR_RESULT)0x00004584L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_HIF_SUBBLOCK_AUTOMATICALLY_ENABLED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_HIF_SUBBLOCK_AUTOMATICALLY_ENABLED. */
/*  */
#define TLR_E_RCX_DRV_HIF_SUBBLOCK_AUTOMATICALLY_ENABLED ((TLR_RESULT)0x00004585L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_HIF_INVALID_INT_CONFIGURATION */
/*  */
/*  MessageText: */
/*  */
/*   DRV_HIF_INVALID_INT_CONFIGURATION. */
/*  */
#define TLR_E_RCX_DRV_HIF_INVALID_INT_CONFIGURATION ((TLR_RESULT)0x00004586L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_HIFPIO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_HIFPIO_INIT. */
/*  */
#define TLR_E_RCX_DRV_HIFPIO_INIT        ((TLR_RESULT)0x000045C0L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_HIFPIO_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_HIFPIO_NAME. */
/*  */
#define TLR_E_RCX_DRV_HIFPIO_NAME        ((TLR_RESULT)0x000045C1L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_HIFPIO_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_HIFPIO_INVALID. */
/*  */
#define TLR_E_RCX_DRV_HIFPIO_INVALID     ((TLR_RESULT)0x000045C2L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_HIFPIO_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_HIFPIO_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_HIFPIO_UNKNOWN     ((TLR_RESULT)0x000045C3L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_INT_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_INT_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_INT_NO_INIT        ((TLR_RESULT)0x00004600L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_INT_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_INT_NAME. */
/*  */
#define TLR_E_RCX_DRV_INT_NAME           ((TLR_RESULT)0x00004601L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_INT_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_INT_INVALID. */
/*  */
#define TLR_E_RCX_DRV_INT_INVALID        ((TLR_RESULT)0x00004602L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_INT_INVALID_CALLER */
/*  */
/*  MessageText: */
/*  */
/*   DRV_INT_INVALID_CALLER. */
/*  */
#define TLR_E_RCX_DRV_INT_INVALID_CALLER ((TLR_RESULT)0x00004603L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_INT_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_INT_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_INT_UNKNOWN        ((TLR_RESULT)0x00004604L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FIQ_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FIQ_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_FIQ_NO_INIT        ((TLR_RESULT)0x00004640L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FIQ_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FIQ_NAME. */
/*  */
#define TLR_E_RCX_DRV_FIQ_NAME           ((TLR_RESULT)0x00004641L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FIQ_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FIQ_INVALID. */
/*  */
#define TLR_E_RCX_DRV_FIQ_INVALID        ((TLR_RESULT)0x00004642L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FIQ_INVALID_CALLER */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FIQ_INVALID_CALLER. */
/*  */
#define TLR_E_RCX_DRV_FIQ_INVALID_CALLER ((TLR_RESULT)0x00004643L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FIQ_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FIQ_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_FIQ_UNKNOWN        ((TLR_RESULT)0x00004644L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_SFLS_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_SFLS_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_SFLS_NO_INIT       ((TLR_RESULT)0x00004680L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_SFLS_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_SFLS_NAME. */
/*  */
#define TLR_E_RCX_DRV_SFLS_NAME          ((TLR_RESULT)0x00004681L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_SFLS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_SFLS_INVALID. */
/*  */
#define TLR_E_RCX_DRV_SFLS_INVALID       ((TLR_RESULT)0x00004682L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_SFLS_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_SFLS_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_SFLS_UNKNOWN       ((TLR_RESULT)0x00004683L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_SFLS_ACCESS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_SFLS_ACCESS_INVALID. */
/*  */
#define TLR_E_RCX_DRV_SFLS_ACCESS_INVALID ((TLR_RESULT)0x00004684L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_SFLS_UNKNOWN_FLASH */
/*  */
/*  MessageText: */
/*  */
/*   DRV_SFLS_UNKNOWN_FLASH. */
/*  */
#define TLR_E_RCX_DRV_SFLS_UNKNOWN_FLASH ((TLR_RESULT)0x00004685L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_SFLS_ERASURE_NOT_SUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_SFLS_ERASURE_NOT_SUPPORTED. */
/*  */
#define TLR_E_RCX_DRV_SFLS_ERASURE_NOT_SUPPORTED ((TLR_RESULT)0x00004686L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_URT_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_URT_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_URT_NO_INIT        ((TLR_RESULT)0x00004700L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_URT_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_URT_NAME. */
/*  */
#define TLR_E_RCX_DRV_URT_NAME           ((TLR_RESULT)0x00004701L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_URT_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_URT_INVALID. */
/*  */
#define TLR_E_RCX_DRV_URT_INVALID        ((TLR_RESULT)0x00004702L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_URT_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_URT_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_URT_UNKNOWN        ((TLR_RESULT)0x00004703L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_URT_INVALID_CALLER */
/*  */
/*  MessageText: */
/*  */
/*   DRV_URT_INVALID_CALLER. */
/*  */
#define TLR_E_RCX_DRV_URT_INVALID_CALLER ((TLR_RESULT)0x00004704L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_GPIO_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_GPIO_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_GPIO_NO_INIT       ((TLR_RESULT)0x00004780L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_GPIO_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_GPIO_NAME. */
/*  */
#define TLR_E_RCX_DRV_GPIO_NAME          ((TLR_RESULT)0x00004781L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_GPIO_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_GPIO_INVALID. */
/*  */
#define TLR_E_RCX_DRV_GPIO_INVALID       ((TLR_RESULT)0x00004782L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_GPIO_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_GPIO_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_GPIO_UNKNOWN       ((TLR_RESULT)0x00004783L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_USB_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_USB_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_USB_NO_INIT        ((TLR_RESULT)0x00004880L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_USB_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_USB_NAME. */
/*  */
#define TLR_E_RCX_DRV_USB_NAME           ((TLR_RESULT)0x00004881L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_USB_PERIPHERAL_NOT_SUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_USB_PERIPHERAL_NOT_SUPPORTED. */
/*  */
#define TLR_E_RCX_DRV_USB_PERIPHERAL_NOT_SUPPORTED ((TLR_RESULT)0x00004882L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_USB_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_USB_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_USB_UNKNOWN        ((TLR_RESULT)0x00004883L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_USB_OTG_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_USB_OTG_NAME. */
/*  */
#define TLR_E_RCX_DRV_USB_OTG_NAME       ((TLR_RESULT)0x00004884L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_USB_OTG_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_USB_OTG_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_USB_OTG_UNKNOWN    ((TLR_RESULT)0x00004885L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_USB_OTG_FATAL */
/*  */
/*  MessageText: */
/*  */
/*   DRV_USB_OTG_FATAL. */
/*  */
#define TLR_E_RCX_DRV_USB_OTG_FATAL      ((TLR_RESULT)0x00004886L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_USB_COM_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_USB_COM_NAME. */
/*  */
#define TLR_E_RCX_DRV_USB_COM_NAME       ((TLR_RESULT)0x00004887L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_USB_COM_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_USB_COM_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_USB_COM_UNKNOWN    ((TLR_RESULT)0x00004888L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_USB_COM_DISCONNECTED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_USB_COM_DISCONNECTED. */
/*  */
#define TLR_E_RCX_DRV_USB_COM_DISCONNECTED ((TLR_RESULT)0x00004889L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_USB_COM_FATAL */
/*  */
/*  MessageText: */
/*  */
/*   DRV_USB_COM_FATAL. */
/*  */
#define TLR_E_RCX_DRV_USB_COM_FATAL      ((TLR_RESULT)0x0000488AL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_USB_COM_XFER_ACTIVE */
/*  */
/*  MessageText: */
/*  */
/*   DRV_USB_COM_XFER_ACTIVE. */
/*  */
#define TLR_E_RCX_DRV_USB_COM_XFER_ACTIVE ((TLR_RESULT)0x0000488BL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_VOL_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_VOL_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_VOL_NO_INIT        ((TLR_RESULT)0x00004900L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_VOL_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_VOL_NAME. */
/*  */
#define TLR_E_RCX_DRV_VOL_NAME           ((TLR_RESULT)0x00004901L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_VOL_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_VOL_INVALID. */
/*  */
#define TLR_E_RCX_DRV_VOL_INVALID        ((TLR_RESULT)0x00004902L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_VOL_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_VOL_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_VOL_UNKNOWN        ((TLR_RESULT)0x00004903L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_VOL_ALREADY_MOUNTED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_VOL_ALREADY_MOUNTED. */
/*  */
#define TLR_E_RCX_DRV_VOL_ALREADY_MOUNTED ((TLR_RESULT)0x00004904L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_VOL_NOT_MOUNTED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_VOL_NOT_MOUNTED. */
/*  */
#define TLR_E_RCX_DRV_VOL_NOT_MOUNTED    ((TLR_RESULT)0x00004905L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_VOL_SECTOR_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_VOL_SECTOR_INVALID. */
/*  */
#define TLR_E_RCX_DRV_VOL_SECTOR_INVALID ((TLR_RESULT)0x00004906L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_VOL_RANGE_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_VOL_RANGE_EXCEEDED. */
/*  */
#define TLR_E_RCX_DRV_VOL_RANGE_EXCEEDED ((TLR_RESULT)0x00004907L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_VOL_UNKNOWN_DRIVE */
/*  */
/*  MessageText: */
/*  */
/*   DRV_VOL_UNKNOWN_DRIVE. */
/*  */
#define TLR_E_RCX_DRV_VOL_UNKNOWN_DRIVE  ((TLR_RESULT)0x00004908L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_VOL_IS_MOUNTED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_VOL_IS_MOUNTED. */
/*  */
#define TLR_E_RCX_DRV_VOL_IS_MOUNTED     ((TLR_RESULT)0x00004909L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_VOL_INVALID_CALLER */
/*  */
/*  MessageText: */
/*  */
/*   DRV_VOL_INVALID_CALLER. */
/*  */
#define TLR_E_RCX_DRV_VOL_INVALID_CALLER ((TLR_RESULT)0x0000490AL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FTL_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FTL_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_FTL_NO_INIT        ((TLR_RESULT)0x00004980L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FTL_PERIPHERAL_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FTL_PERIPHERAL_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_FTL_PERIPHERAL_UNKNOWN ((TLR_RESULT)0x00004981L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FTL_NOT_MOUNTED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FTL_NOT_MOUNTED. */
/*  */
#define TLR_E_RCX_DRV_FTL_NOT_MOUNTED    ((TLR_RESULT)0x00004982L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FTL_ALREADY_MOUNTED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FTL_ALREADY_MOUNTED. */
/*  */
#define TLR_E_RCX_DRV_FTL_ALREADY_MOUNTED ((TLR_RESULT)0x00004983L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FTL_PERIPHERAL_NOT_SUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FTL_PERIPHERAL_NOT_SUPPORTED. */
/*  */
#define TLR_E_RCX_DRV_FTL_PERIPHERAL_NOT_SUPPORTED ((TLR_RESULT)0x00004984L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FTL_NO_FTL_FORMAT_FOUND */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FTL_NO_FTL_FORMAT_FOUND. */
/*  */
#define TLR_E_RCX_DRV_FTL_NO_FTL_FORMAT_FOUND ((TLR_RESULT)0x00004985L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FTL_FTL_FORMAT_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FTL_FTL_FORMAT_ERROR. */
/*  */
#define TLR_E_RCX_DRV_FTL_FTL_FORMAT_ERROR ((TLR_RESULT)0x00004986L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FTL_FTL_SIZE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FTL_FTL_SIZE_ERROR. */
/*  */
#define TLR_E_RCX_DRV_FTL_FTL_SIZE_ERROR ((TLR_RESULT)0x00004987L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FTL_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FTL_NOT_INITIALIZED. */
/*  */
#define TLR_E_RCX_DRV_FTL_NOT_INITIALIZED ((TLR_RESULT)0x00004988L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FTL_NOT_FORMATTED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FTL_NOT_FORMATTED. */
/*  */
#define TLR_E_RCX_DRV_FTL_NOT_FORMATTED  ((TLR_RESULT)0x00004989L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FTL_RANGE_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FTL_RANGE_EXCEEDED. */
/*  */
#define TLR_E_RCX_DRV_FTL_RANGE_EXCEEDED ((TLR_RESULT)0x0000498AL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FTL_NO_SPACE */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FTL_NO_SPACE. */
/*  */
#define TLR_E_RCX_DRV_FTL_NO_SPACE       ((TLR_RESULT)0x0000498BL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FTL_ERASE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FTL_ERASE_ERROR. */
/*  */
#define TLR_E_RCX_DRV_FTL_ERASE_ERROR    ((TLR_RESULT)0x0000498CL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FTL_NO_FREE_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FTL_NO_FREE_BLOCK. */
/*  */
#define TLR_E_RCX_DRV_FTL_NO_FREE_BLOCK  ((TLR_RESULT)0x0000498DL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FTL_NO_TRANSFER_UNIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FTL_NO_TRANSFER_UNIT. */
/*  */
#define TLR_E_RCX_DRV_FTL_NO_TRANSFER_UNIT ((TLR_RESULT)0x0000498EL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FTL_VOLUME_TOO_BIG */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FTL_VOLUME_TOO_BIG. */
/*  */
#define TLR_E_RCX_DRV_FTL_VOLUME_TOO_BIG ((TLR_RESULT)0x0000498FL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_EDD_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_EDD_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_EDD_NO_INIT        ((TLR_RESULT)0x00004A00L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_EDD_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_EDD_NAME. */
/*  */
#define TLR_E_RCX_DRV_EDD_NAME           ((TLR_RESULT)0x00004A01L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_EDD_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_EDD_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_EDD_UNKNOWN        ((TLR_RESULT)0x00004A02L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_EDD_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_EDD_INVALID. */
/*  */
#define TLR_E_RCX_DRV_EDD_INVALID        ((TLR_RESULT)0x00004A03L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_EDD_NO_ACCESS */
/*  */
/*  MessageText: */
/*  */
/*   DRV_EDD_NO_ACCESS. */
/*  */
#define TLR_E_RCX_DRV_EDD_NO_ACCESS      ((TLR_RESULT)0x00004A04L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_EDD_RESOURCE */
/*  */
/*  MessageText: */
/*  */
/*   DRV_EDD_RESOURCE. */
/*  */
#define TLR_E_RCX_DRV_EDD_RESOURCE       ((TLR_RESULT)0x00004A05L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_EDD_ETH_TYPE_OCCUPIED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_EDD_ETH_TYPE_OCCUPIED. */
/*  */
#define TLR_E_RCX_DRV_EDD_ETH_TYPE_OCCUPIED ((TLR_RESULT)0x00004A06L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_EDD_NO_FRAME_BUF */
/*  */
/*  MessageText: */
/*  */
/*   DRV_EDD_NO_FRAME_BUF. */
/*  */
#define TLR_E_RCX_DRV_EDD_NO_FRAME_BUF   ((TLR_RESULT)0x00004A07L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_EDD_INVALID_FRAME_BUF_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   DRV_EDD_INVALID_FRAME_BUF_TYPE. */
/*  */
#define TLR_E_RCX_DRV_EDD_INVALID_FRAME_BUF_TYPE ((TLR_RESULT)0x00004A08L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_EDD_INVALID_APP_HANDLE */
/*  */
/*  MessageText: */
/*  */
/*   DRV_EDD_INVALID_APP_HANDLE. */
/*  */
#define TLR_E_RCX_DRV_EDD_INVALID_APP_HANDLE ((TLR_RESULT)0x00004A09L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_EDD_PARAM_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   DRV_EDD_PARAM_ERROR. */
/*  */
#define TLR_E_RCX_DRV_EDD_PARAM_ERROR    ((TLR_RESULT)0x00004A0AL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FIF_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FIF_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_FIF_NO_INIT        ((TLR_RESULT)0x00004A80L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FIF_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FIF_NAME. */
/*  */
#define TLR_E_RCX_DRV_FIF_NAME           ((TLR_RESULT)0x00004A81L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FIF_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FIF_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_FIF_UNKNOWN        ((TLR_RESULT)0x00004A82L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FIF_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FIF_INVALID. */
/*  */
#define TLR_E_RCX_DRV_FIF_INVALID        ((TLR_RESULT)0x00004A83L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FIF_FIFOCHANNEL_OUTOF_RANGE */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FIF_FIFOCHANNEL_OUTOF_RANGE. */
/*  */
#define TLR_E_RCX_DRV_FIF_FIFOCHANNEL_OUTOF_RANGE ((TLR_RESULT)0x00004A84L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FIF_ELEMENTDEPTH_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FIF_ELEMENTDEPTH_EXCEEDED. */
/*  */
#define TLR_E_RCX_DRV_FIF_ELEMENTDEPTH_EXCEEDED ((TLR_RESULT)0x00004A85L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FIF_FIFODEPTH_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FIF_FIFODEPTH_INVALID. */
/*  */
#define TLR_E_RCX_DRV_FIF_FIFODEPTH_INVALID ((TLR_RESULT)0x00004A86L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FIF_FIFO_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FIF_FIFO_INVALID. */
/*  */
#define TLR_E_RCX_DRV_FIF_FIFO_INVALID   ((TLR_RESULT)0x00004A87L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FIF_FIFO_EMPTY */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FIF_FIFO_EMPTY. */
/*  */
#define TLR_E_RCX_DRV_FIF_FIFO_EMPTY     ((TLR_RESULT)0x00004A88L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FIF_FIFO_FULL */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FIF_FIFO_FULL. */
/*  */
#define TLR_E_RCX_DRV_FIF_FIFO_FULL      ((TLR_RESULT)0x00004A89L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FIF_CHANNEL_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FIF_CHANNEL_INVALID. */
/*  */
#define TLR_E_RCX_DRV_FIF_CHANNEL_INVALID ((TLR_RESULT)0x00004A8AL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FIF_FIFO_UNDERRUN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FIF_FIFO_UNDERRUN. */
/*  */
#define TLR_E_RCX_DRV_FIF_FIFO_UNDERRUN  ((TLR_RESULT)0x00004A8BL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FIF_FIFO_OVERFLOW */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FIF_FIFO_OVERFLOW. */
/*  */
#define TLR_E_RCX_DRV_FIF_FIFO_OVERFLOW  ((TLR_RESULT)0x00004A8CL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_FIF_FIFO_NOTEMPTY */
/*  */
/*  MessageText: */
/*  */
/*   DRV_FIF_FIFO_NOTEMPTY. */
/*  */
#define TLR_E_RCX_DRV_FIF_FIFO_NOTEMPTY  ((TLR_RESULT)0x00004A8DL)

/*  */
/*  MessageId: TLR_E_RCX_DRV_ICM_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_ICM_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_ICM_NO_INIT        ((TLR_RESULT)0x00004B00L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_ICM_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_ICM_NAME. */
/*  */
#define TLR_E_RCX_DRV_ICM_NAME           ((TLR_RESULT)0x00004B01L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_ICM_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_ICM_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_ICM_UNKNOWN        ((TLR_RESULT)0x00004B02L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_ICM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_ICM_INVALID. */
/*  */
#define TLR_E_RCX_DRV_ICM_INVALID        ((TLR_RESULT)0x00004B03L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_SECPROM_NOT_PERSONALIZED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_SECPROM_NOT_PERSONALIZED. */
/*  */
#define TLR_E_RCX_DRV_SECPROM_NOT_PERSONALIZED ((TLR_RESULT)0x00004B80L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_SECPROM_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_SECPROM_NOT_INITIALIZED. */
/*  */
#define TLR_E_RCX_DRV_SECPROM_NOT_INITIALIZED ((TLR_RESULT)0x00004B81L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_SECPROM_INVALID_INSTANCE */
/*  */
/*  MessageText: */
/*  */
/*   DRV_SECPROM_INVALID_INSTANCE. */
/*  */
#define TLR_E_RCX_DRV_SECPROM_INVALID_INSTANCE ((TLR_RESULT)0x00004B82L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_SECPROM_FLUSH_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   DRV_SECPROM_FLUSH_FAILED. */
/*  */
#define TLR_E_RCX_DRV_SECPROM_FLUSH_FAILED ((TLR_RESULT)0x00004B83L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_SPI_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_SPI_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_SPI_NO_INIT        ((TLR_RESULT)0x00004F00L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_SPI_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_SPI_NAME. */
/*  */
#define TLR_E_RCX_DRV_SPI_NAME           ((TLR_RESULT)0x00004F01L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_SPI_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_SPI_INVALID. */
/*  */
#define TLR_E_RCX_DRV_SPI_INVALID        ((TLR_RESULT)0x00004F02L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_SPI_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_SPI_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_SPI_UNKNOWN        ((TLR_RESULT)0x00004F03L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_SPI_INVALID_CALLER */
/*  */
/*  MessageText: */
/*  */
/*   DRV_SPI_INVALID_CALLER. */
/*  */
#define TLR_E_RCX_DRV_SPI_INVALID_CALLER ((TLR_RESULT)0x00004F04L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_SPI_NOT_OPEN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_SPI_NOT_OPEN. */
/*  */
#define TLR_E_RCX_DRV_SPI_NOT_OPEN       ((TLR_RESULT)0x00004F05L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_IIC_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   DRV_IIC_NO_INIT. */
/*  */
#define TLR_E_RCX_DRV_IIC_NO_INIT        ((TLR_RESULT)0x00004F80L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_IIC_NAME */
/*  */
/*  MessageText: */
/*  */
/*   DRV_IIC_NAME. */
/*  */
#define TLR_E_RCX_DRV_IIC_NAME           ((TLR_RESULT)0x00004F81L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_IIC_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   DRV_IIC_INVALID. */
/*  */
#define TLR_E_RCX_DRV_IIC_INVALID        ((TLR_RESULT)0x00004F82L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_IIC_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   DRV_IIC_UNKNOWN. */
/*  */
#define TLR_E_RCX_DRV_IIC_UNKNOWN        ((TLR_RESULT)0x00004F83L)

/*  */
/*  MessageId: TLR_E_RCX_DRV_IIC_INVALID_CALLER */
/*  */
/*  MessageText: */
/*  */
/*   DRV_IIC_INVALID_CALLER. */
/*  */
#define TLR_E_RCX_DRV_IIC_INVALID_CALLER ((TLR_RESULT)0x00004F84L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_URT_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_URT_NO_INIT. */
/*  */
#define TLR_E_RCX_HAL_URT_NO_INIT        ((TLR_RESULT)0x00005000L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_URT_NO_PORT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_URT_NO_PORT. */
/*  */
#define TLR_E_RCX_HAL_URT_NO_PORT        ((TLR_RESULT)0x00005001L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_URT_PORT_IN_USE */
/*  */
/*  MessageText: */
/*  */
/*   HAL_URT_PORT_IN_USE. */
/*  */
#define TLR_E_RCX_HAL_URT_PORT_IN_USE    ((TLR_RESULT)0x00005002L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_URT_PORT_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_URT_PORT_INVALID. */
/*  */
#define TLR_E_RCX_HAL_URT_PORT_INVALID   ((TLR_RESULT)0x00005003L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_URT_PARITY_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_URT_PARITY_INVALID. */
/*  */
#define TLR_E_RCX_HAL_URT_PARITY_INVALID ((TLR_RESULT)0x00005004L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_URT_STOPBIT_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_URT_STOPBIT_INVALID. */
/*  */
#define TLR_E_RCX_HAL_URT_STOPBIT_INVALID ((TLR_RESULT)0x00005005L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_URT_MODE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_URT_MODE_INVALID. */
/*  */
#define TLR_E_RCX_HAL_URT_MODE_INVALID   ((TLR_RESULT)0x00005006L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_URT_PORT_LIMIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_URT_PORT_LIMIT. */
/*  */
#define TLR_E_RCX_HAL_URT_PORT_LIMIT     ((TLR_RESULT)0x00005007L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_URT_PORT_NAME */
/*  */
/*  MessageText: */
/*  */
/*   HAL_URT_PORT_NAME. */
/*  */
#define TLR_E_RCX_HAL_URT_PORT_NAME      ((TLR_RESULT)0x00005008L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_URT_NO_ACCESS */
/*  */
/*  MessageText: */
/*  */
/*   HAL_URT_NO_ACCESS. */
/*  */
#define TLR_E_RCX_HAL_URT_NO_ACCESS      ((TLR_RESULT)0x00005009L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_URT_NO_DATA */
/*  */
/*  MessageText: */
/*  */
/*   HAL_URT_NO_DATA. */
/*  */
#define TLR_E_RCX_HAL_URT_NO_DATA        ((TLR_RESULT)0x0000500AL)

/*  */
/*  MessageId: TLR_E_RCX_HAL_URT_RECEIVE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   HAL_URT_RECEIVE_ERROR. */
/*  */
#define TLR_E_RCX_HAL_URT_RECEIVE_ERROR  ((TLR_RESULT)0x0000500BL)

/*  */
/*  MessageId: TLR_E_RCX_HAL_URT_TRANSMITTER_BUSY */
/*  */
/*  MessageText: */
/*  */
/*   HAL_URT_TRANSMITTER_BUSY. */
/*  */
#define TLR_E_RCX_HAL_URT_TRANSMITTER_BUSY ((TLR_RESULT)0x0000500CL)

/*  */
/*  MessageId: TLR_E_RCX_HAL_TCM_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_TCM_NO_INIT. */
/*  */
#define TLR_E_RCX_HAL_TCM_NO_INIT        ((TLR_RESULT)0x00005080L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_TCM_BOUNDARY */
/*  */
/*  MessageText: */
/*  */
/*   HAL_TCM_BOUNDARY. */
/*  */
#define TLR_E_RCX_HAL_TCM_BOUNDARY       ((TLR_RESULT)0x00005081L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_TCM_SIZE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_TCM_SIZE_INVALID. */
/*  */
#define TLR_E_RCX_HAL_TCM_SIZE_INVALID   ((TLR_RESULT)0x00005082L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_TCM_TYPE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_TCM_TYPE_INVALID. */
/*  */
#define TLR_E_RCX_HAL_TCM_TYPE_INVALID   ((TLR_RESULT)0x00005083L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HWTIM_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HWTIM_NO_INIT. */
/*  */
#define TLR_E_RCX_HAL_HWTIM_NO_INIT      ((TLR_RESULT)0x00005100L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HWTIM_NAME */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HWTIM_NAME. */
/*  */
#define TLR_E_RCX_HAL_HWTIM_NAME         ((TLR_RESULT)0x00005101L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HWTIM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HWTIM_INVALID. */
/*  */
#define TLR_E_RCX_HAL_HWTIM_INVALID      ((TLR_RESULT)0x00005102L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HWTIM_NO_ACCESS */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HWTIM_NO_ACCESS. */
/*  */
#define TLR_E_RCX_HAL_HWTIM_NO_ACCESS    ((TLR_RESULT)0x00005103L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HWTIME_PRESCALE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HWTIME_PRESCALE_INVALID. */
/*  */
#define TLR_E_RCX_HAL_HWTIME_PRESCALE_INVALID ((TLR_RESULT)0x00005104L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HWTIME_MAXVALUE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HWTIME_MAXVALUE_INVALID. */
/*  */
#define TLR_E_RCX_HAL_HWTIME_MAXVALUE_INVALID ((TLR_RESULT)0x00005105L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_CCH_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_CCH_NO_INIT. */
/*  */
#define TLR_E_RCX_HAL_CCH_NO_INIT        ((TLR_RESULT)0x00005180L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_CCH_UNKNOWN_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   HAL_CCH_UNKNOWN_TYPE. */
/*  */
#define TLR_E_RCX_HAL_CCH_UNKNOWN_TYPE   ((TLR_RESULT)0x00005181L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_INT_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_INT_NO_INIT. */
/*  */
#define TLR_E_RCX_HAL_INT_NO_INIT        ((TLR_RESULT)0x00005200L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_INT_NAME */
/*  */
/*  MessageText: */
/*  */
/*   HAL_INT_NAME. */
/*  */
#define TLR_E_RCX_HAL_INT_NAME           ((TLR_RESULT)0x00005201L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_INT_NUM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_INT_NUM_INVALID. */
/*  */
#define TLR_E_RCX_HAL_INT_NUM_INVALID    ((TLR_RESULT)0x00005202L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_INT_TRIGGER_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_INT_TRIGGER_INVALID. */
/*  */
#define TLR_E_RCX_HAL_INT_TRIGGER_INVALID ((TLR_RESULT)0x00005203L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_INT_NO_ACCESS */
/*  */
/*  MessageText: */
/*  */
/*   HAL_INT_NO_ACCESS. */
/*  */
#define TLR_E_RCX_HAL_INT_NO_ACCESS      ((TLR_RESULT)0x00005204L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_INT_FULL */
/*  */
/*  MessageText: */
/*  */
/*   HAL_INT_FULL. */
/*  */
#define TLR_E_RCX_HAL_INT_FULL           ((TLR_RESULT)0x00005205L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_INT_PRIORITY_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_INT_PRIORITY_INVALID. */
/*  */
#define TLR_E_RCX_HAL_INT_PRIORITY_INVALID ((TLR_RESULT)0x00005206L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_INT_ALREADY_IN_USE */
/*  */
/*  MessageText: */
/*  */
/*   HAL_INT_ALREADY_IN_USE. */
/*  */
#define TLR_E_RCX_HAL_INT_ALREADY_IN_USE ((TLR_RESULT)0x00005207L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_INT_DOUBLE_PRIORITY */
/*  */
/*  MessageText: */
/*  */
/*   HAL_INT_DOUBLE_PRIORITY. */
/*  */
#define TLR_E_RCX_HAL_INT_DOUBLE_PRIORITY ((TLR_RESULT)0x00005208L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EBUS_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EBUS_NO_INIT. */
/*  */
#define TLR_E_RCX_HAL_EBUS_NO_INIT       ((TLR_RESULT)0x00005280L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EBUS_DATAWIDTH */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EBUS_DATAWIDTH. */
/*  */
#define TLR_E_RCX_HAL_EBUS_DATAWIDTH     ((TLR_RESULT)0x00005281L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EBUS_NUM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EBUS_NUM_INVALID. */
/*  */
#define TLR_E_RCX_HAL_EBUS_NUM_INVALID   ((TLR_RESULT)0x00005282L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_LED_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_LED_NO_INIT. */
/*  */
#define TLR_E_RCX_HAL_LED_NO_INIT        ((TLR_RESULT)0x00005300L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_LED_NO_ACCESS */
/*  */
/*  MessageText: */
/*  */
/*   HAL_LED_NO_ACCESS. */
/*  */
#define TLR_E_RCX_HAL_LED_NO_ACCESS      ((TLR_RESULT)0x00005301L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_XC_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_XC_NO_INIT. */
/*  */
#define TLR_E_RCX_HAL_XC_NO_INIT         ((TLR_RESULT)0x00005400L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_XC_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   HAL_XC_UNKNOWN. */
/*  */
#define TLR_E_RCX_HAL_XC_UNKNOWN         ((TLR_RESULT)0x00005401L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_XC_MEMTYPE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_XC_MEMTYPE_INVALID. */
/*  */
#define TLR_E_RCX_HAL_XC_MEMTYPE_INVALID ((TLR_RESULT)0x00005402L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_XC_PROTECTION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   HAL_XC_PROTECTION_FAILED. */
/*  */
#define TLR_E_RCX_HAL_XC_PROTECTION_FAILED ((TLR_RESULT)0x00005403L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_XC_BOARDERSET_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   HAL_XC_BOARDERSET_FAILED. */
/*  */
#define TLR_E_RCX_HAL_XC_BOARDERSET_FAILED ((TLR_RESULT)0x00005404L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_XC_BOADER_NOT_SETTABLE */
/*  */
/*  MessageText: */
/*  */
/*   HAL_XC_BOADER_NOT_SETTABLE. */
/*  */
#define TLR_E_RCX_HAL_XC_BOADER_NOT_SETTABLE ((TLR_RESULT)0x00005405L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_PHY_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_PHY_NO_INIT. */
/*  */
#define TLR_E_RCX_HAL_PHY_NO_INIT        ((TLR_RESULT)0x00005500L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_PHY_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   HAL_PHY_UNKNOWN. */
/*  */
#define TLR_E_RCX_HAL_PHY_UNKNOWN        ((TLR_RESULT)0x00005501L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_PHY_ACCESS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_PHY_ACCESS_INVALID. */
/*  */
#define TLR_E_RCX_HAL_PHY_ACCESS_INVALID ((TLR_RESULT)0x00005502L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_PHY_MACINSTANCE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_PHY_MACINSTANCE_INVALID. */
/*  */
#define TLR_E_RCX_HAL_PHY_MACINSTANCE_INVALID ((TLR_RESULT)0x00005503L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_PHY_ACCESS_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   HAL_PHY_ACCESS_ERROR. */
/*  */
#define TLR_E_RCX_HAL_PHY_ACCESS_ERROR   ((TLR_RESULT)0x00005504L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_PFL_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_PFL_NO_INIT. */
/*  */
#define TLR_E_RCX_HAL_PFL_NO_INIT        ((TLR_RESULT)0x00005600L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_PFL_UKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   HAL_PFL_UKNOWN. */
/*  */
#define TLR_E_RCX_HAL_PFL_UKNOWN         ((TLR_RESULT)0x00005601L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_PFL_BUSY */
/*  */
/*  MessageText: */
/*  */
/*   HAL_PFL_BUSY. */
/*  */
#define TLR_E_RCX_HAL_PFL_BUSY           ((TLR_RESULT)0x00005602L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_PFL_ERSUSP */
/*  */
/*  MessageText: */
/*  */
/*   HAL_PFL_ERSUSP. */
/*  */
#define TLR_E_RCX_HAL_PFL_ERSUSP         ((TLR_RESULT)0x00005603L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_PFL_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_PFL_TIMEOUT. */
/*  */
#define TLR_E_RCX_HAL_PFL_TIMEOUT        ((TLR_RESULT)0x00005604L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_PFL_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   HAL_PFL_ERROR. */
/*  */
#define TLR_E_RCX_HAL_PFL_ERROR          ((TLR_RESULT)0x00005605L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_DPM_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_DPM_NO_INIT. */
/*  */
#define TLR_E_RCX_HAL_DPM_NO_INIT        ((TLR_RESULT)0x00005700L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_DPM_PORT_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_DPM_PORT_INVALID. */
/*  */
#define TLR_E_RCX_HAL_DPM_PORT_INVALID   ((TLR_RESULT)0x00005702L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_DPM_SIZE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_DPM_SIZE_INVALID. */
/*  */
#define TLR_E_RCX_HAL_DPM_SIZE_INVALID   ((TLR_RESULT)0x00005703L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_DPM_HOST_MAILBOX_FULL */
/*  */
/*  MessageText: */
/*  */
/*   HAL_DPM_HOST_MAILBOX_FULL. */
/*  */
#define TLR_E_RCX_HAL_DPM_HOST_MAILBOX_FULL ((TLR_RESULT)0x00005704L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_DPM_NO_MESSAGE */
/*  */
/*  MessageText: */
/*  */
/*   HAL_DPM_NO_MESSAGE. */
/*  */
#define TLR_E_RCX_HAL_DPM_NO_MESSAGE     ((TLR_RESULT)0x00005705L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_MMU_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_MMU_NO_INIT. */
/*  */
#define TLR_E_RCX_HAL_MMU_NO_INIT        ((TLR_RESULT)0x00005800L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_MMU_BOUNDARY */
/*  */
/*  MessageText: */
/*  */
/*   HAL_MMU_BOUNDARY. */
/*  */
#define TLR_E_RCX_HAL_MMU_BOUNDARY       ((TLR_RESULT)0x00005801L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_MMU_TYPE_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   HAL_MMU_TYPE_UNKNOWN. */
/*  */
#define TLR_E_RCX_HAL_MMU_TYPE_UNKNOWN   ((TLR_RESULT)0x00005802L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_MPU_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_MPU_NO_INIT. */
/*  */
#define TLR_E_RCX_HAL_MPU_NO_INIT        ((TLR_RESULT)0x00005880L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_MPU_BOUNDARY */
/*  */
/*  MessageText: */
/*  */
/*   HAL_MPU_BOUNDARY. */
/*  */
#define TLR_E_RCX_HAL_MPU_BOUNDARY       ((TLR_RESULT)0x00005881L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_MPU_REGION_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   HAL_MPU_REGION_UNKNOWN. */
/*  */
#define TLR_E_RCX_HAL_MPU_REGION_UNKNOWN ((TLR_RESULT)0x00005882L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_NO_INIT. */
/*  */
#define TLR_E_RCX_HAL_EDD_NO_INIT        ((TLR_RESULT)0x00005900L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_UNKNOWN. */
/*  */
#define TLR_E_RCX_HAL_EDD_UNKNOWN        ((TLR_RESULT)0x00005901L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_ACCESS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_ACCESS_INVALID. */
/*  */
#define TLR_E_RCX_HAL_EDD_ACCESS_INVALID ((TLR_RESULT)0x00005902L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_ACCESS_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_ACCESS_ERROR. */
/*  */
#define TLR_E_RCX_HAL_EDD_ACCESS_ERROR   ((TLR_RESULT)0x00005903L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_HANDLE_INVALID. */
/*  */
#define TLR_E_RCX_HAL_EDD_HANDLE_INVALID ((TLR_RESULT)0x00005904L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_CALLBACK_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_CALLBACK_INVALID. */
/*  */
#define TLR_E_RCX_HAL_EDD_CALLBACK_INVALID ((TLR_RESULT)0x00005905L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_BUFFER_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_BUFFER_INVALID. */
/*  */
#define TLR_E_RCX_HAL_EDD_BUFFER_INVALID ((TLR_RESULT)0x00005906L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_NO_RESOURCE */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_NO_RESOURCE. */
/*  */
#define TLR_E_RCX_HAL_EDD_NO_RESOURCE    ((TLR_RESULT)0x00005907L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_MGMT_FRAME */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_MGMT_FRAME. */
/*  */
#define TLR_E_RCX_HAL_EDD_MGMT_FRAME     ((TLR_RESULT)0x00005908L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_FRAME_DEQUEUED */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_FRAME_DEQUEUED. */
/*  */
#define TLR_E_RCX_HAL_EDD_FRAME_DEQUEUED ((TLR_RESULT)0x00005909L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_TX_LATE_COLLISION */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_TX_LATE_COLLISION. */
/*  */
#define TLR_E_RCX_HAL_EDD_TX_LATE_COLLISION ((TLR_RESULT)0x0000590AL)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_TX_LINK_DOWN */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_TX_LINK_DOWN. */
/*  */
#define TLR_E_RCX_HAL_EDD_TX_LINK_DOWN   ((TLR_RESULT)0x0000590BL)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_TX_EXCESSIVE_COLLISION */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_TX_EXCESSIVE_COLLISION. */
/*  */
#define TLR_E_RCX_HAL_EDD_TX_EXCESSIVE_COLLISION ((TLR_RESULT)0x0000590CL)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_TX_FRAME_LENGTH_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_TX_FRAME_LENGTH_ERROR. */
/*  */
#define TLR_E_RCX_HAL_EDD_TX_FRAME_LENGTH_ERROR ((TLR_RESULT)0x0000590DL)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_TX_POINTER_ADDRESS_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_TX_POINTER_ADDRESS_ERROR. */
/*  */
#define TLR_E_RCX_HAL_EDD_TX_POINTER_ADDRESS_ERROR ((TLR_RESULT)0x0000590EL)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_TX_FIFO_UNDERFLOW */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_TX_FIFO_UNDERFLOW. */
/*  */
#define TLR_E_RCX_HAL_EDD_TX_FIFO_UNDERFLOW ((TLR_RESULT)0x0000590FL)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_RX_FCS_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_RX_FCS_ERROR. */
/*  */
#define TLR_E_RCX_HAL_EDD_RX_FCS_ERROR   ((TLR_RESULT)0x00005910L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_RX_ALIGNMENT_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_RX_ALIGNMENT_ERROR. */
/*  */
#define TLR_E_RCX_HAL_EDD_RX_ALIGNMENT_ERROR ((TLR_RESULT)0x00005911L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_RX_FRAME_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_RX_FRAME_TOO_LONG. */
/*  */
#define TLR_E_RCX_HAL_EDD_RX_FRAME_TOO_LONG ((TLR_RESULT)0x00005912L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_RX_RUNT_FRAME */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_RX_RUNT_FRAME. */
/*  */
#define TLR_E_RCX_HAL_EDD_RX_RUNT_FRAME  ((TLR_RESULT)0x00005913L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_RX_COLLISION_FRAGMENT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_RX_COLLISION_FRAGMENT. */
/*  */
#define TLR_E_RCX_HAL_EDD_RX_COLLISION_FRAGMENT ((TLR_RESULT)0x00005914L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_RX_START_OF_FRAME_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_RX_START_OF_FRAME_ERROR. */
/*  */
#define TLR_E_RCX_HAL_EDD_RX_START_OF_FRAME_ERROR ((TLR_RESULT)0x00005915L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_RX_FIFO_OVERFLOW */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_RX_FIFO_OVERFLOW. */
/*  */
#define TLR_E_RCX_HAL_EDD_RX_FIFO_OVERFLOW ((TLR_RESULT)0x00005916L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_PARAM_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_PARAM_ERROR. */
/*  */
#define TLR_E_RCX_HAL_EDD_PARAM_ERROR    ((TLR_RESULT)0x00005917L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_EDD_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_EDD_COMMAND_INVALID. */
/*  */
#define TLR_E_RCX_HAL_EDD_COMMAND_INVALID ((TLR_RESULT)0x00005918L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_ICM_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_ICM_NO_INIT. */
/*  */
#define TLR_E_RCX_HAL_ICM_NO_INIT        ((TLR_RESULT)0x00005A00L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_ICM_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   HAL_ICM_UNKNOWN. */
/*  */
#define TLR_E_RCX_HAL_ICM_UNKNOWN        ((TLR_RESULT)0x00005A01L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_ICM_ACCESS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_ICM_ACCESS_INVALID. */
/*  */
#define TLR_E_RCX_HAL_ICM_ACCESS_INVALID ((TLR_RESULT)0x00005A02L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_ICM_ACCESS_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   HAL_ICM_ACCESS_ERROR. */
/*  */
#define TLR_E_RCX_HAL_ICM_ACCESS_ERROR   ((TLR_RESULT)0x00005A03L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_ICM_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_ICM_HANDLE_INVALID. */
/*  */
#define TLR_E_RCX_HAL_ICM_HANDLE_INVALID ((TLR_RESULT)0x00005A04L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_NO_INIT. */
/*  */
#define TLR_E_RCX_HAL_HIF_NO_INIT        ((TLR_RESULT)0x00005B80L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_ILLVECTID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_ILLVECTID. */
/*  */
#define TLR_E_RCX_HAL_HIF_ILLVECTID      ((TLR_RESULT)0x00005B81L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_NOHANDLER */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_NOHANDLER. */
/*  */
#define TLR_E_RCX_HAL_HIF_NOHANDLER      ((TLR_RESULT)0x00005B82L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_ILLSUBIRQMASK */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_ILLSUBIRQMASK. */
/*  */
#define TLR_E_RCX_HAL_HIF_ILLSUBIRQMASK  ((TLR_RESULT)0x00005B83L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_UNINITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_UNINITIALIZED. */
/*  */
#define TLR_E_RCX_HAL_HIF_UNINITIALIZED  ((TLR_RESULT)0x00005B84L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_ALREADY_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_ALREADY_INITIALIZED. */
/*  */
#define TLR_E_RCX_HAL_HIF_ALREADY_INITIALIZED ((TLR_RESULT)0x00005B85L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_AREA_NUM_OF_AREABLOCKS_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_AREA_NUM_OF_AREABLOCKS_EXCEEDED. */
/*  */
#define TLR_E_RCX_HAL_HIF_AREA_NUM_OF_AREABLOCKS_EXCEEDED ((TLR_RESULT)0x00005B86L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_AREA_SIZE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_AREA_SIZE_INVALID. */
/*  */
#define TLR_E_RCX_HAL_HIF_AREA_SIZE_INVALID ((TLR_RESULT)0x00005B87L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_AREA_LAYOUT_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_AREA_LAYOUT_UNKNOWN. */
/*  */
#define TLR_E_RCX_HAL_HIF_AREA_LAYOUT_UNKNOWN ((TLR_RESULT)0x00005B88L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_AREA_SIZE_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_AREA_SIZE_EXCEEDED. */
/*  */
#define TLR_E_RCX_HAL_HIF_AREA_SIZE_EXCEEDED ((TLR_RESULT)0x00005B89L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_AREA_HOST_MAILBOX_FULL */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_AREA_HOST_MAILBOX_FULL. */
/*  */
#define TLR_E_RCX_HAL_HIF_AREA_HOST_MAILBOX_FULL ((TLR_RESULT)0x00005B8AL)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_AREA_SEGMENT_LIMIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_AREA_SEGMENT_LIMIT. */
/*  */
#define TLR_E_RCX_HAL_HIF_AREA_SEGMENT_LIMIT ((TLR_RESULT)0x00005B8BL)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_AREA_SEGMENT_UNUSED */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_AREA_SEGMENT_UNUSED. */
/*  */
#define TLR_E_RCX_HAL_HIF_AREA_SEGMENT_UNUSED ((TLR_RESULT)0x00005B8CL)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_AREA_NAME_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_AREA_NAME_INVALID. */
/*  */
#define TLR_E_RCX_HAL_HIF_AREA_NAME_INVALID ((TLR_RESULT)0x00005B8DL)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_AREA_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_AREA_UNKNOWN. */
/*  */
#define TLR_E_RCX_HAL_HIF_AREA_UNKNOWN   ((TLR_RESULT)0x00005B8EL)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_AREA_ALREADY_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_AREA_ALREADY_INITIALIZED. */
/*  */
#define TLR_E_RCX_HAL_HIF_AREA_ALREADY_INITIALIZED ((TLR_RESULT)0x00005B8FL)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_SUBBLOCK_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_SUBBLOCK_UNKNOWN. */
/*  */
#define TLR_E_RCX_HAL_HIF_SUBBLOCK_UNKNOWN ((TLR_RESULT)0x00005B90L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_SUBBLOCK_CREATION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_SUBBLOCK_CREATION_FAILED. */
/*  */
#define TLR_E_RCX_HAL_HIF_SUBBLOCK_CREATION_FAILED ((TLR_RESULT)0x00005B91L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_SUBBLOCK_OFFSET_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_SUBBLOCK_OFFSET_INVALID. */
/*  */
#define TLR_E_RCX_HAL_HIF_SUBBLOCK_OFFSET_INVALID ((TLR_RESULT)0x00005B92L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_FUNCTION_POSITION_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_FUNCTION_POSITION_INVALID. */
/*  */
#define TLR_E_RCX_HAL_HIF_FUNCTION_POSITION_INVALID ((TLR_RESULT)0x00005B93L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_HIF_FUNCTION_ALREADY_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   HAL_HIF_FUNCTION_ALREADY_INITIALIZED. */
/*  */
#define TLR_E_RCX_HAL_HIF_FUNCTION_ALREADY_INITIALIZED ((TLR_RESULT)0x00005B94L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_SPI_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_SPI_NO_INIT. */
/*  */
#define TLR_E_RCX_HAL_SPI_NO_INIT        ((TLR_RESULT)0x00005D00L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_SPI_NULL */
/*  */
/*  MessageText: */
/*  */
/*   HAL_SPI_NULL. */
/*  */
#define TLR_E_RCX_HAL_SPI_NULL           ((TLR_RESULT)0x00005D01L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_SPI_PORT_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_SPI_PORT_INVALID. */
/*  */
#define TLR_E_RCX_HAL_SPI_PORT_INVALID   ((TLR_RESULT)0x00005D02L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_SPI_SLAVE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_SPI_SLAVE_INVALID. */
/*  */
#define TLR_E_RCX_HAL_SPI_SLAVE_INVALID  ((TLR_RESULT)0x00005D03L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_SPI_BUSY */
/*  */
/*  MessageText: */
/*  */
/*   HAL_SPI_BUSY. */
/*  */
#define TLR_E_RCX_HAL_SPI_BUSY           ((TLR_RESULT)0x00005D04L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_WAIT_FOR_SIGNAL */
/*  */
/*  MessageText: */
/*  */
/*   HAL_WAIT_FOR_SIGNAL. */
/*  */
#define TLR_E_RCX_HAL_WAIT_FOR_SIGNAL    ((TLR_RESULT)0x00005D05L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_IIC_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_IIC_NO_INIT. */
/*  */
#define TLR_E_RCX_HAL_IIC_NO_INIT        ((TLR_RESULT)0x00005E00L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_IIC_NULL */
/*  */
/*  MessageText: */
/*  */
/*   HAL_IIC_NULL. */
/*  */
#define TLR_E_RCX_HAL_IIC_NULL           ((TLR_RESULT)0x00005E01L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_IIC_NOT_OPEN */
/*  */
/*  MessageText: */
/*  */
/*   HAL_IIC_NOT_OPEN. */
/*  */
#define TLR_E_RCX_HAL_IIC_NOT_OPEN       ((TLR_RESULT)0x00005E02L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_IIC_PORT_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_IIC_PORT_INVALID. */
/*  */
#define TLR_E_RCX_HAL_IIC_PORT_INVALID   ((TLR_RESULT)0x00005E03L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_IIC_SLAVE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   HAL_IIC_SLAVE_INVALID. */
/*  */
#define TLR_E_RCX_HAL_IIC_SLAVE_INVALID  ((TLR_RESULT)0x00005E04L)

/*  */
/*  MessageId: TLR_E_RCX_HAL_IIC_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   HAL_IIC_TIMEOUT. */
/*  */
#define TLR_E_RCX_HAL_IIC_TIMEOUT        ((TLR_RESULT)0x00005E05L)

/*  */
/*  MessageId: TLR_E_RCX_MID_NVR_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   MID_NVR_NO_INIT. */
/*  */
#define TLR_E_RCX_MID_NVR_NO_INIT        ((TLR_RESULT)0x00006000L)

/*  */
/*  MessageId: TLR_E_RCX_MID_NVR_PORT_LIMIT */
/*  */
/*  MessageText: */
/*  */
/*   MID_NVR_PORT_LIMIT. */
/*  */
#define TLR_E_RCX_MID_NVR_PORT_LIMIT     ((TLR_RESULT)0x00006001L)

/*  */
/*  MessageId: TLR_E_RCX_MID_COM_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   MID_COM_NO_INIT. */
/*  */
#define TLR_E_RCX_MID_COM_NO_INIT        ((TLR_RESULT)0x00006080L)

/*  */
/*  MessageId: TLR_E_RCX_MID_COM_TASK_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   MID_COM_TASK_FAILED. */
/*  */
#define TLR_E_RCX_MID_COM_TASK_FAILED    ((TLR_RESULT)0x00006081L)

/*  */
/*  MessageId: TLR_E_RCX_MID_STA_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   MID_STA_NO_INIT. */
/*  */
#define TLR_E_RCX_MID_STA_NO_INIT        ((TLR_RESULT)0x00006100L)

/*  */
/*  MessageId: TLR_E_RCX_MID_STA_TASK_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   MID_STA_TASK_FAILED. */
/*  */
#define TLR_E_RCX_MID_STA_TASK_FAILED    ((TLR_RESULT)0x00006101L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_NO_INIT. */
/*  */
#define TLR_E_RCX_MID_FAT_NO_INIT        ((TLR_RESULT)0x00006180L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_NOT_FOUND */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_NOT_FOUND. */
/*  */
#define TLR_E_RCX_MID_FAT_NOT_FOUND      ((TLR_RESULT)0x00006181L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_VOLUME_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_VOLUME_INVALID. */
/*  */
#define TLR_E_RCX_MID_FAT_VOLUME_INVALID ((TLR_RESULT)0x00006182L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_FATTYPE_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_FATTYPE_UNKNOWN. */
/*  */
#define TLR_E_RCX_MID_FAT_FATTYPE_UNKNOWN ((TLR_RESULT)0x00006183L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_VOLUME_FULL */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_VOLUME_FULL. */
/*  */
#define TLR_E_RCX_MID_FAT_VOLUME_FULL    ((TLR_RESULT)0x00006184L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_FILE_ALREADY_EXISTS */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_FILE_ALREADY_EXISTS. */
/*  */
#define TLR_E_RCX_MID_FAT_FILE_ALREADY_EXISTS ((TLR_RESULT)0x00006185L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_FILE_NOT_FOUND */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_FILE_NOT_FOUND. */
/*  */
#define TLR_E_RCX_MID_FAT_FILE_NOT_FOUND ((TLR_RESULT)0x00006186L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_FILE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_FILE_INVALID. */
/*  */
#define TLR_E_RCX_MID_FAT_FILE_INVALID   ((TLR_RESULT)0x00006187L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_ORIGIN_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_ORIGIN_INVALID. */
/*  */
#define TLR_E_RCX_MID_FAT_ORIGIN_INVALID ((TLR_RESULT)0x00006188L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_PATH_NOT_EXISTS */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_PATH_NOT_EXISTS. */
/*  */
#define TLR_E_RCX_MID_FAT_PATH_NOT_EXISTS ((TLR_RESULT)0x00006189L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_PATH_ATTRIBUTE */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_PATH_ATTRIBUTE. */
/*  */
#define TLR_E_RCX_MID_FAT_PATH_ATTRIBUTE ((TLR_RESULT)0x0000618AL)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_DIRECTORY_NOT_EMPTY */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_DIRECTORY_NOT_EMPTY. */
/*  */
#define TLR_E_RCX_MID_FAT_DIRECTORY_NOT_EMPTY ((TLR_RESULT)0x0000618BL)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_END_OF_FILE */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_END_OF_FILE. */
/*  */
#define TLR_E_RCX_MID_FAT_END_OF_FILE    ((TLR_RESULT)0x0000618CL)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_DIRECTORY_ALREADY_EXISTS */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_DIRECTORY_ALREADY_EXISTS. */
/*  */
#define TLR_E_RCX_MID_FAT_DIRECTORY_ALREADY_EXISTS ((TLR_RESULT)0x0000618DL)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_NO_FILESYSTEM_INSTALLED */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_NO_FILESYSTEM_INSTALLED. */
/*  */
#define TLR_E_RCX_MID_FAT_NO_FILESYSTEM_INSTALLED ((TLR_RESULT)0x0000618EL)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_VOLUME_NOT_MOUNTED */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_VOLUME_NOT_MOUNTED. */
/*  */
#define TLR_E_RCX_MID_FAT_VOLUME_NOT_MOUNTED ((TLR_RESULT)0x0000618FL)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_FILE_IS_DIRECTORY */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_FILE_IS_DIRECTORY. */
/*  */
#define TLR_E_RCX_MID_FAT_FILE_IS_DIRECTORY ((TLR_RESULT)0x00006190L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_FILE_READONLY */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_FILE_READONLY. */
/*  */
#define TLR_E_RCX_MID_FAT_FILE_READONLY  ((TLR_RESULT)0x00006191L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_FILE_OPEN */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_FILE_OPEN. */
/*  */
#define TLR_E_RCX_MID_FAT_FILE_OPEN      ((TLR_RESULT)0x00006192L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_FATTABLE_CORRUPT */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_FATTABLE_CORRUPT. */
/*  */
#define TLR_E_RCX_MID_FAT_FATTABLE_CORRUPT ((TLR_RESULT)0x00006193L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_NO_MORE_RECORD */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_NO_MORE_RECORD. */
/*  */
#define TLR_E_RCX_MID_FAT_NO_MORE_RECORD ((TLR_RESULT)0x00006194L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_READ_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_READ_ERROR. */
/*  */
#define TLR_E_RCX_MID_FAT_READ_ERROR     ((TLR_RESULT)0x00006195L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_WRITE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_WRITE_ERROR. */
/*  */
#define TLR_E_RCX_MID_FAT_WRITE_ERROR    ((TLR_RESULT)0x00006196L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_CLUSTER_ALLOC_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_CLUSTER_ALLOC_ERROR. */
/*  */
#define TLR_E_RCX_MID_FAT_CLUSTER_ALLOC_ERROR ((TLR_RESULT)0x00006197L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_CLUSTER_FAT_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_CLUSTER_FAT_ERROR. */
/*  */
#define TLR_E_RCX_MID_FAT_CLUSTER_FAT_ERROR ((TLR_RESULT)0x00006198L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_CLUSTER_CHANGE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_CLUSTER_CHANGE_ERROR. */
/*  */
#define TLR_E_RCX_MID_FAT_CLUSTER_CHANGE_ERROR ((TLR_RESULT)0x00006199L)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_READ_FAT_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_READ_FAT_ERROR. */
/*  */
#define TLR_E_RCX_MID_FAT_READ_FAT_ERROR ((TLR_RESULT)0x0000619AL)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_WRITE_FAT_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_WRITE_FAT_ERROR. */
/*  */
#define TLR_E_RCX_MID_FAT_WRITE_FAT_ERROR ((TLR_RESULT)0x0000619BL)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_WRITE_DIR_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_WRITE_DIR_ERROR. */
/*  */
#define TLR_E_RCX_MID_FAT_WRITE_DIR_ERROR ((TLR_RESULT)0x0000619CL)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_READ_DIR_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_READ_DIR_ERROR. */
/*  */
#define TLR_E_RCX_MID_FAT_READ_DIR_ERROR ((TLR_RESULT)0x0000619DL)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_READ_FSINFO_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_READ_FSINFO_ERROR. */
/*  */
#define TLR_E_RCX_MID_FAT_READ_FSINFO_ERROR ((TLR_RESULT)0x0000619EL)

/*  */
/*  MessageId: TLR_E_RCX_MID_FAT_WRITE_FSINFO_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   MID_FAT_WRITE_FSINFO_ERROR. */
/*  */
#define TLR_E_RCX_MID_FAT_WRITE_FSINFO_ERROR ((TLR_RESULT)0x0000619FL)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_NO_INIT. */
/*  */
#define TLR_E_RCX_MID_DBM_NO_INIT        ((TLR_RESULT)0x00006200L)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_NO_SYSVOLUME */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_NO_SYSVOLUME. */
/*  */
#define TLR_E_RCX_MID_DBM_NO_SYSVOLUME   ((TLR_RESULT)0x00006201L)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_FILE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_FILE_INVALID. */
/*  */
#define TLR_E_RCX_MID_DBM_FILE_INVALID   ((TLR_RESULT)0x00006202L)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_TABLE_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_TABLE_UNKNOWN. */
/*  */
#define TLR_E_RCX_MID_DBM_TABLE_UNKNOWN  ((TLR_RESULT)0x00006203L)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_HANDLE_INVALID. */
/*  */
#define TLR_E_RCX_MID_DBM_HANDLE_INVALID ((TLR_RESULT)0x00006204L)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_DATASET_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_DATASET_ERROR. */
/*  */
#define TLR_E_RCX_MID_DBM_DATASET_ERROR  ((TLR_RESULT)0x00006205L)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_INDEX_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_INDEX_INVALID. */
/*  */
#define TLR_E_RCX_MID_DBM_INDEX_INVALID  ((TLR_RESULT)0x00006206L)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_UNKNOWN_FILE */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_UNKNOWN_FILE. */
/*  */
#define TLR_E_RCX_MID_DBM_UNKNOWN_FILE   ((TLR_RESULT)0x00006207L)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_FNC_ONLY_ON_NEW_DBM */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_FNC_ONLY_ON_NEW_DBM. */
/*  */
#define TLR_E_RCX_MID_DBM_FNC_ONLY_ON_NEW_DBM ((TLR_RESULT)0x00006208L)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_NO_REC0 */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_NO_REC0. */
/*  */
#define TLR_E_RCX_MID_DBM_NO_REC0        ((TLR_RESULT)0x00006209L)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_FNC_NEEDS_LL_TABLE */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_FNC_NEEDS_LL_TABLE. */
/*  */
#define TLR_E_RCX_MID_DBM_FNC_NEEDS_LL_TABLE ((TLR_RESULT)0x0000620AL)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_INVALID_PARAM */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_INVALID_PARAM. */
/*  */
#define TLR_E_RCX_MID_DBM_INVALID_PARAM  ((TLR_RESULT)0x0000620BL)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_KEY_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_KEY_INVALID. */
/*  */
#define TLR_E_RCX_MID_DBM_KEY_INVALID    ((TLR_RESULT)0x0000620CL)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_KEY_NOT_FOUND */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_KEY_NOT_FOUND. */
/*  */
#define TLR_E_RCX_MID_DBM_KEY_NOT_FOUND  ((TLR_RESULT)0x0000620DL)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_NO_RECORD_AVAILABLE */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_NO_RECORD_AVAILABLE. */
/*  */
#define TLR_E_RCX_MID_DBM_NO_RECORD_AVAILABLE ((TLR_RESULT)0x0000620EL)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_FNC_NOT_ON_LL */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_FNC_NOT_ON_LL. */
/*  */
#define TLR_E_RCX_MID_DBM_FNC_NOT_ON_LL  ((TLR_RESULT)0x0000620FL)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_UNKNOWN_PROPERTY */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_UNKNOWN_PROPERTY. */
/*  */
#define TLR_E_RCX_MID_DBM_UNKNOWN_PROPERTY ((TLR_RESULT)0x00006210L)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_FNC_NOT_ON_TAB_TYPE1 */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_FNC_NOT_ON_TAB_TYPE1. */
/*  */
#define TLR_E_RCX_MID_DBM_FNC_NOT_ON_TAB_TYPE1 ((TLR_RESULT)0x00006211L)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_CHECKSUM_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_CHECKSUM_INVALID. */
/*  */
#define TLR_E_RCX_MID_DBM_CHECKSUM_INVALID ((TLR_RESULT)0x00006212L)

/*  */
/*  MessageId: TLR_E_RCX_MID_DBM_BOUNDARY_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   MID_DBM_BOUNDARY_INVALID. */
/*  */
#define TLR_E_RCX_MID_DBM_BOUNDARY_INVALID ((TLR_RESULT)0x00006213L)

/*  */
/*  MessageId: TLR_E_RCX_MID_LED_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   MID_LED_NO_INIT. */
/*  */
#define TLR_E_RCX_MID_LED_NO_INIT        ((TLR_RESULT)0x00006280L)

/*  */
/*  MessageId: TLR_E_RCX_MID_SYS_NO_INIT */
/*  */
/*  MessageText: */
/*  */
/*   MID_SYS_NO_INIT. */
/*  */
#define TLR_E_RCX_MID_SYS_NO_INIT        ((TLR_RESULT)0x00006300L)

/*  */
/*  MessageId: TLR_E_RCX_MID_SYS_NO_LINKAGE */
/*  */
/*  MessageText: */
/*  */
/*   MID_SYS_NO_LINKAGE. */
/*  */
#define TLR_E_RCX_MID_SYS_NO_LINKAGE     ((TLR_RESULT)0x00006302L)

/*  */
/*  MessageId: TLR_E_RCX_AAI_OK */
/*  */
/*  MessageText: */
/*  */
/*   AAI_OK. */
/*  */
#define TLR_E_RCX_AAI_OK                 ((TLR_RESULT)0x00007FFFL)

#ifndef __RPC_ERROR_H
#define __RPC_ERROR_H




/* ////////////////////////////////////////////////////////////////////////////// */
/*  RPC TASK's ERROR AND DIAGNOSIS - CODES */
/* ////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_RPC_TASK_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Received packet with invalid command. */
/*  */
#define TLR_E_RPC_TASK_COMMAND_INVALID   ((TLR_RESULT)0xC02E0001L)

/*  RPC DIAGNOSIS - CODES */
/*  */
/*  MessageId: TLR_DIAG_E_RPC_TASK_CLIENT_RESOURCE_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Initiating CLRPC-Client failed. (CLRPC_Client_Initialize()) */
/*  */
#define TLR_DIAG_E_RPC_TASK_CLIENT_RESOURCE_INIT_FAILED ((TLR_RESULT)0xC02E0010L)

/*  */
/*  MessageId: TLR_DIAG_E_RPC_TASK_SERVER_RESOURCE_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Initiating CLRPC-Server failed (CLRPC_Server_Initialize()). */
/*  */
#define TLR_DIAG_E_RPC_TASK_SERVER_RESOURCE_INIT_FAILED ((TLR_RESULT)0xC02E0011L)

/*  */
/*  MessageId: TLR_DIAG_E_RPC_TASK_EPMAP_RESOURCE_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Initiating CLRPC-Endpoint-Mapper failed (CLRPC_Mapper_Initialize()). */
/*  */
#define TLR_DIAG_E_RPC_TASK_EPMAP_RESOURCE_INIT_FAILED ((TLR_RESULT)0xC02E0012L)

/*  */
/*  MessageId: TLR_DIAG_E_RPC_TASK_INIT_LOCAL_CREATE_QUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creating message queue failed. */
/*  */
#define TLR_DIAG_E_RPC_TASK_INIT_LOCAL_CREATE_QUE_FAILED ((TLR_RESULT)0xC02E0013L)

/*  */
/*  MessageId: TLR_DIAG_E_RPC_TASK_INIT_REMOTE_IDENT_EDD_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Identifying Drv_EDD failed. */
/*  */
#define TLR_DIAG_E_RPC_TASK_INIT_REMOTE_IDENT_EDD_FAILED ((TLR_RESULT)0xC02E0014L)

/*  */
/*  MessageId: TLR_DIAG_E_RPC_TASK_INIT_REMOTE_GET_MAC_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Getting the MAC address failed. */
/*  */
#define TLR_DIAG_E_RPC_TASK_INIT_REMOTE_GET_MAC_FAILED ((TLR_RESULT)0xC02E0015L)

/*  */
/*  MessageId: TLR_DIAG_E_RPC_TASK_INIT_REMOTE_IDENT_TCPUDP_QUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Getting queue handle to TCPIP-Task failed. */
/*  */
#define TLR_DIAG_E_RPC_TASK_INIT_REMOTE_IDENT_TCPUDP_QUE_FAILED ((TLR_RESULT)0xC02E0016L)

/*  GENERIC RPC ERROR - CODES */
/*  */
/*  MessageId: TLR_E_RPC_STATUS */
/*  */
/*  MessageText: */
/*  */
/*   Generic RPC-error code. See Profinet-status code for details. */
/*  */
#define TLR_E_RPC_STATUS                 ((TLR_RESULT)0xC02E0100L)

/*  */
/*  MessageId: TLR_E_RPC_CONNECT_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   There was not enough memory allocated to receive the whole IO-Device's Connect-Response PDU. Most likely it containes a very large ModuleDiff-Block. */
/*  */
#define TLR_E_RPC_CONNECT_OUT_OF_MEMORY  ((TLR_RESULT)0xC02E0101L)

/*  */
/*  MessageId: TLR_E_RPC_FATAL_ERROR_CLB_ALREADY_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   The fatal error callback function is already registered. */
/*  */
#define TLR_E_RPC_FATAL_ERROR_CLB_ALREADY_REGISTERED ((TLR_RESULT)0xC02E0102L)

/*  */
/*  MessageId: TLR_E_CLRPC_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Error while sending internal message to another task. */
/*  */
#define TLR_E_CLRPC_PACKET_SEND_FAILED   ((TLR_RESULT)0xC02E0200L)

/*  */
/*  MessageId: TLR_E_CLRPC_TIMER_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Creating a TLR-Timer-packet in RPC task failed due to insufficient memory. */
/*  */
#define TLR_E_CLRPC_TIMER_OUT_OF_MEMORY  ((TLR_RESULT)0xC02E0201L)

/*  RPC ENDPOINT - MAPPER */
/*  */
/*  MessageId: TLR_E_CLRPC_MAPPER_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The parameter "uiMaxReg" (maximum amount of RPC-mapper registrations) is invalid in CLRPC_EPMap_Initialize(). */
/*  */
#define TLR_E_CLRPC_MAPPER_INIT_FAILED   ((TLR_RESULT)0xC02E0300L)

/*  */
/*  MessageId: TLR_E_CLRPC_MAPPER_RESOURCE_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   The requested Endpoint-Mapper index is invalid. */
/*  */
#define TLR_E_CLRPC_MAPPER_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC02E0301L)

/*  */
/*  MessageId: TLR_E_CLRPC_MAPPER_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory for this request. */
/*  */
#define TLR_E_CLRPC_MAPPER_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC02E0302L)

/*  */
/*  MessageId: TLR_E_CLRPC_MAPPER_STATUS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The state of Endpoint-Mapper is invalid for this request. */
/*  */
#define TLR_E_CLRPC_MAPPER_STATUS_INVALID ((TLR_RESULT)0xC02E0303L)

/*  */
/*  MessageId: TLR_E_CLRPC_MAPPER_STATUS_CLOSING */
/*  */
/*  MessageText: */
/*  */
/*   The Endpoint-Mapper is waiting for close-confirmation and therefore its status isinvalid for this request. */
/*  */
#define TLR_E_CLRPC_MAPPER_STATUS_CLOSING ((TLR_RESULT)0xC02E0304L)

/*  */
/*  MessageId: TLR_E_CLRPC_MAPPER_STATUS_UNKNOWN */
/*  */
/*  MessageText: */
/*  */
/*   The status of Endpoint-Mapper is unknown. */
/*  */
#define TLR_E_CLRPC_MAPPER_STATUS_UNKNOWN ((TLR_RESULT)0xC02E0305L)

/*  */
/*  MessageId: TLR_E_CLRPC_MAPPER_STATUS_CONFLICT */
/*  */
/*  MessageText: */
/*  */
/*   The status of Endpoint-Mapper is not "Ready" and therefore request CLRPC_EPMap_Deregister_req() is invalid. */
/*  */
#define TLR_E_CLRPC_MAPPER_STATUS_CONFLICT ((TLR_RESULT)0xC02E0306L)

/*  */
/*  MessageId: TLR_E_CLRPC_MAPPER_PARAMETER_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter in CLRPC_EPMap_Register_req_Compare(). */
/*  */
#define TLR_E_CLRPC_MAPPER_PARAMETER_FAILED ((TLR_RESULT)0xC02E0307L)

/*  */
/*  MessageId: TLR_E_CLRPC_MAPPER_SERVER_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   CLRPC_EPMap_Deregister_req() is not allowed because at least one RPC-Server is registered to this Endpoint-Mapper. */
/*  */
#define TLR_E_CLRPC_MAPPER_SERVER_REGISTERED ((TLR_RESULT)0xC02E0308L)

/*  RPC SERVER */
/*  */
/*  MessageId: TLR_E_CLRPC_SERVER_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   An error occurred in CLRPC_Server_Initialize(). */
/*  */
#define TLR_E_CLRPC_SERVER_INIT_FAILED   ((TLR_RESULT)0xC02E0400L)

/*  */
/*  MessageId: TLR_E_CLRPC_SERVER_RESOURCE_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   The maximum number of registered RPC-Servers is exceeded or the maximum number of outstanding requests is exceeded. */
/*  */
#define TLR_E_CLRPC_SERVER_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC02E0401L)

/*  */
/*  MessageId: TLR_E_CLRPC_SERVER_TIMER_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creating TLR-Timer for RPC-Server failed. */
/*  */
#define TLR_E_CLRPC_SERVER_TIMER_CREATE_FAILED ((TLR_RESULT)0xC02E0402L)

/*  */
/*  MessageId: TLR_E_CLRPC_SERVER_NO_SERVER_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   There is no RPC-Server registered that could be deregistered (CLRPC_ServerDeregister_req()). */
/*  */
#define TLR_E_CLRPC_SERVER_NO_SERVER_REGISTERED ((TLR_RESULT)0xC02E0403L)

/*  */
/*  MessageId: TLR_E_CLRPC_SERVER_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory to create an instance of RPC-Server. */
/*  */
#define TLR_E_CLRPC_SERVER_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC02E0404L)

/*  */
/*  MessageId: TLR_E_CLRPC_SERVER_MAPPER_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The handle to Endpoint-Mapper in CLRPC_ServerRegister_req() is invalid. */
/*  */
#define TLR_E_CLRPC_SERVER_MAPPER_HANDLE_INVALID ((TLR_RESULT)0xC02E0405L)

/*  */
/*  MessageId: TLR_E_CLRPC_SERVER_MAPPER_STATUS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The status of Endpoint-Mapper in CLRPC_ServerRegister_req() is invalid. */
/*  */
#define TLR_E_CLRPC_SERVER_MAPPER_STATUS_INVALID ((TLR_RESULT)0xC02E0406L)

/*  */
/*  MessageId: TLR_E_CLRPC_SERVER_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The handle to RPC-Server instance is invalid. */
/*  */
#define TLR_E_CLRPC_SERVER_HANDLE_INVALID ((TLR_RESULT)0xC02E0407L)

/*  */
/*  MessageId: TLR_E_CLRPC_SERVER_OBJECT_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   There is at least one object registered to RPC-Server instance. CLRPC_ServerDeregister_req() can not proceed. */
/*  */
#define TLR_E_CLRPC_SERVER_OBJECT_REGISTERED ((TLR_RESULT)0xC02E0408L)

/*  */
/*  MessageId: TLR_E_CLRPC_SERVER_PARAM_RECV_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter "ulMaxRecv" in request-packet in CLRPC_ServerRegister_req(). */
/*  */
#define TLR_E_CLRPC_SERVER_PARAM_RECV_INVALID ((TLR_RESULT)0xC02E0409L)

/*  */
/*  MessageId: TLR_E_CLRPC_SERVER_PARAM_SEND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter "ulMaxSend" in request-packet in CLRPC_ServerRegister_req(). */
/*  */
#define TLR_E_CLRPC_SERVER_PARAM_SEND_INVALID ((TLR_RESULT)0xC02E040AL)

/*  */
/*  MessageId: TLR_E_CLRPC_SERVER_ELEMENT_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid RPC-Server element "ptElem". Internal RPC-Error. */
/*  */
#define TLR_E_CLRPC_SERVER_ELEMENT_INVALID ((TLR_RESULT)0xC02E040BL)

/*  */
/*  MessageId: TLR_E_CLRPC_SERVER_REQUEST_CANCELED */
/*  */
/*  MessageText: */
/*  */
/*   This RPC-Request was cancled. */
/*  */
#define TLR_E_CLRPC_SERVER_REQUEST_CANCELED ((TLR_RESULT)0xC02E040CL)

/*  RPC OBJECT */
/*  */
/*  MessageId: TLR_E_CLRPC_OBJECT_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory to create an RPC-Object instance in CLRPC_ObjectRegister_req(). */
/*  */
#define TLR_E_CLRPC_OBJECT_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC02E0500L)

/*  */
/*  MessageId: TLR_E_CLRPC_OBJECT_SERVER_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The handle to RPC-Server instance in CLRPC_ObjectRegister_req() is invalid. */
/*  */
#define TLR_E_CLRPC_OBJECT_SERVER_HANDLE_INVALID ((TLR_RESULT)0xC02E0501L)

/*  */
/*  MessageId: TLR_E_CLRPC_OBJECT_SERVER_STATUS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The status of RPC-Server instance in CLRPC_ObjectRegister_req() is invalid. */
/*  */
#define TLR_E_CLRPC_OBJECT_SERVER_STATUS_INVALID ((TLR_RESULT)0xC02E0502L)

/*  */
/*  MessageId: TLR_E_CLRPC_OBJECT_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The handle to RPC-Object instance in CLRPC_ObjectDeregister_req() is invalid. */
/*  */
#define TLR_E_CLRPC_OBJECT_HANDLE_INVALID ((TLR_RESULT)0xC02E0503L)

/*  RPC CLIENT */
/*  */
/*  MessageId: TLR_E_CLRPC_CLIENT_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   One of the parameters "uiMaxReg" or "uiMaxReq" in CLRPC_Client_Initialize() is invalid. */
/*  */
#define TLR_E_CLRPC_CLIENT_INIT_FAILED   ((TLR_RESULT)0xC02E0600L)

/*  */
/*  MessageId: TLR_E_CLRPC_CLIENT_RESOURCE_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   The maximum number of parallel RPC-Client instances in reached in CLRPC_ClientRegister_req() */
/*  */
#define TLR_E_CLRPC_CLIENT_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC02E0601L)

/*  */
/*  MessageId: TLR_E_CLRPC_CLIENT_TIMER_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creating the TLR-Timer for RPC-Client instance in CLRPC_ClientRegister_req() failed. */
/*  */
#define TLR_E_CLRPC_CLIENT_TIMER_CREATE_FAILED ((TLR_RESULT)0xC02E0602L)

/*  */
/*  MessageId: TLR_E_CLRPC_CLIENT_RESOURCE_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient memory for this request. */
/*  */
#define TLR_E_CLRPC_CLIENT_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC02E0603L)

/*  */
/*  MessageId: TLR_E_CLRPC_CLIENT_MAPPER_STATUS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The state of Endpoint-Mapper is invalid for this request. */
/*  */
#define TLR_E_CLRPC_CLIENT_MAPPER_STATUS_INVALID ((TLR_RESULT)0xC02E0604L)

/*  */
/*  MessageId: TLR_E_CLRPC_CLIENT_HANDLE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The handle to RPC-Client instance is invalid. */
/*  */
#define TLR_E_CLRPC_CLIENT_HANDLE_INVALID ((TLR_RESULT)0xC02E0605L)

/*  */
/*  MessageId: TLR_E_CLRPC_CLIENT_REQUEST_LIMIT_EXCEEDED */
/*  */
/*  MessageText: */
/*  */
/*   The maximum amount of outstanding RPC-Requests for this RPC-Clients instance is reached. */
/*  */
#define TLR_E_CLRPC_CLIENT_REQUEST_LIMIT_EXCEEDED ((TLR_RESULT)0xC02E0606L)

/*  */
/*  MessageId: TLR_E_CLRPC_CLIENT_OPCODE_SEQUENCE */
/*  */
/*  MessageText: */
/*  */
/*   RPC-Client instances can only connect to an IO-Device if there are no outstanding RPC-Requests. Currently at least one RPC-Request is outstanding. */
/*  */
#define TLR_E_CLRPC_CLIENT_OPCODE_SEQUENCE ((TLR_RESULT)0xC02E0607L)

/*  */
/*  MessageId: TLR_E_CLRPC_CLIENT_DEREGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   The RPC-Client instance you tried to use is going to deregister right now. Aborting your Request ! */
/*  */
#define TLR_E_CLRPC_CLIENT_DEREGISTERED  ((TLR_RESULT)0xC02E0608L)

/*  */
/*  MessageId: TLR_E_CLRPC_CLIENT_ELEMENT_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid RPC-Client instance element "ptElem". Internal RPC-Error. */
/*  */
#define TLR_E_CLRPC_CLIENT_ELEMENT_INVALID ((TLR_RESULT)0xC02E0609L)

/*  */
/*  MessageId: TLR_E_CLRPC_CLIENT_LONG_TIMEOUT_HIT */
/*  */
/*  MessageText: */
/*  */
/*   The LONG timeout TLR-timer for an outstanding RPC-Request hit. Used internaly in RPC only. */
/*  */
#define TLR_E_CLRPC_CLIENT_LONG_TIMEOUT_HIT ((TLR_RESULT)0xC02E060AL)

/*  */
/*  MessageId: TLR_E_CLRPC_CLIENT_RESPONSE_SEQUENCE_NUMBER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid sequence number in RPC-Message received by RPC-Client instance. */
/*  */
#define TLR_E_CLRPC_CLIENT_RESPONSE_SEQUENCE_NUMBER ((TLR_RESULT)0xC02E060BL)




#endif  /* __RPC_ERROR_H */

#ifndef __SERCOS_SL_ERROR_H
#define __SERCOS_SL_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Sercos3 Slave Application  Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_SERCOS_SL_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_SERCOS_SL_COMMAND_INVALID  ((TLR_RESULT)0xC04B0001L)




#endif  /* __SERCOS_SL_ERROR_H */

#ifndef __SERCOSIII_API_ERROR_H
#define __SERCOSIII_API_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Sercos III - Result and Status Codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_SERCOSIII_API_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid data in request detected. */
/*  */
#define TLR_E_SERCOSIII_API_COMMAND_INVALID ((TLR_RESULT)0xC0340001L)




#endif  /* __SERCOSIII_API_ERROR_H */

#ifndef __SERCOSIII_CYCLIC_ERROR_H
#define __SERCOSIII_CYCLIC_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Sercos III - Result and Status Codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_SERCOSIII_CYCLIC_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid data in request detected. */
/*  */
#define TLR_E_SERCOSIII_CYCLIC_COMMAND_INVALID ((TLR_RESULT)0xC0370001L)




#endif  /* __SERCOSIII_CYCLIC_ERROR_H */

#ifndef __SERCOSIII_DL_ERROR_H
#define __SERCOSIII_DL_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Sercos III - Result and Status Codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_SERCOSIII_DL_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid data in request detected. */
/*  */
#define TLR_E_SERCOSIII_DL_COMMAND_INVALID ((TLR_RESULT)0xC0350001L)




#endif  /* __SERCOSIII_DL_ERROR_H */

#ifndef __SERCOSIII_ETH_ERROR_H
#define __SERCOSIII_ETH_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Sercos III - Result and Status Codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_SERCOSIII_ETH_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid data in request detected. */
/*  */
#define TLR_E_SERCOSIII_ETH_COMMAND_INVALID ((TLR_RESULT)0xC0360001L)

/*  */
/*  MessageId: TLR_E_SIII_SL_NRT_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid startup parameters. */
/*  */
#define TLR_E_SIII_SL_NRT_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0360002L)

/*  */
/*  MessageId: TLR_E_SIII_SL_NRT_LLD_NOT_STARTED */
/*  */
/*  MessageText: */
/*  */
/*   Link Layer Driver not started. */
/*  */
#define TLR_E_SIII_SL_NRT_LLD_NOT_STARTED ((TLR_RESULT)0xC0360003L)




#endif  /* __SERCOSIII_ETH_ERROR_H */

#ifndef __SERCOSIII_SL_IDN_ERROR_H
#define __SERCOSIII_SL_IDN_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  SercosIII Slave IDN error codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/* Range 0x1000-0x7FFF is reserved for SVC error mapping */
/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_COMMAND_INVALID ((TLR_RESULT)0xC0850001L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_ALREADY_EXISTS */
/*  */
/*  MessageText: */
/*  */
/*   IDN already exists. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_ALREADY_EXISTS ((TLR_RESULT)0xC0850004L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_ATTRIBUTE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid attribute specified. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_ATTRIBUTE_INVALID ((TLR_RESULT)0xC0850005L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_INVALID_MAX_DATA_SIZE_SPECIFIED */
/*  */
/*  MessageText: */
/*  */
/*   Invalid max data size specified. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_INVALID_MAX_DATA_SIZE_SPECIFIED ((TLR_RESULT)0xC0850006L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_SLAVE_INDEX_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Slave index invalid. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_SLAVE_INDEX_INVALID ((TLR_RESULT)0xC0850007L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_UNDEFINED_NOTIFY_ALREADY_IN_USE */
/*  */
/*  MessageText: */
/*  */
/*   Undefined notify already in use. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_UNDEFINED_NOTIFY_ALREADY_IN_USE ((TLR_RESULT)0xC0850008L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_INVALID_ELEMENT_ID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid element id. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_INVALID_ELEMENT_ID ((TLR_RESULT)0xC0850009L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_APP_PACKET_RESPONSE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Application's Response Packet invalid. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_APP_PACKET_RESPONSE_INVALID ((TLR_RESULT)0xC085000AL)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_APP_TRANSFER_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Application's Transfer Data too long. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_APP_TRANSFER_TOO_LONG ((TLR_RESULT)0xC085000BL)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_APP_TRANSFER_LENGTH_WRONG */
/*  */
/*  MessageText: */
/*  */
/*   Application's Transfer Data length is invalid. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_APP_TRANSFER_LENGTH_WRONG ((TLR_RESULT)0xC085000CL)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_APP_MTU_TOO_LOW */
/*  */
/*  MessageText: */
/*  */
/*   Application's MTU is too low. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_APP_MTU_TOO_LOW ((TLR_RESULT)0xC085000DL)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_INVALID_DEST_ID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid DestId. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_INVALID_DEST_ID ((TLR_RESULT)0xC085000EL)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_LISTS_CANNOT_HAVE_A_MINIMUM_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Lists cannot have a minimum value. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_LISTS_CANNOT_HAVE_A_MINIMUM_VALUE ((TLR_RESULT)0xC085000FL)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_LISTS_CANNOT_HAVE_A_MAXIMUM_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Lists cannot have a maximum value. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_LISTS_CANNOT_HAVE_A_MAXIMUM_VALUE ((TLR_RESULT)0xC0850010L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_NAME_EXCEEDS_ALLOCATED_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Name exceeds allocated length. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_NAME_EXCEEDS_ALLOCATED_LENGTH ((TLR_RESULT)0xC0850011L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_UNIT_EXCEEDS_ALLOCATED_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Unit exceeds allocated length. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_UNIT_EXCEEDS_ALLOCATED_LENGTH ((TLR_RESULT)0xC0850012L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_OPDATA_EXCEEDS_ALLOCATED_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   OpData exceeds allocated length. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_OPDATA_EXCEEDS_ALLOCATED_LENGTH ((TLR_RESULT)0xC0850013L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_INVALID_MAX_LIST_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Invalid max list length. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_INVALID_MAX_LIST_LENGTH ((TLR_RESULT)0xC0850014L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_DEFAULT_VALUE_EXCEEDS_ALLOCATED_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Default value exceeds allocated length. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_DEFAULT_VALUE_EXCEEDS_ALLOCATED_LENGTH ((TLR_RESULT)0xC0850015L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_MINIMUM_AND_MAXIMUM_VALUE_MUST_BE_USED_TOGETHER */
/*  */
/*  MessageText: */
/*  */
/*   Minimum and maximum value must be used together. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_MINIMUM_AND_MAXIMUM_VALUE_MUST_BE_USED_TOGETHER ((TLR_RESULT)0xC0850016L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_USER_APPLICATION_TRANSFER_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   User application transfer error. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_USER_APPLICATION_TRANSFER_ERROR ((TLR_RESULT)0xC0850017L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_INTERNALLY_HANDLED_IDN */
/*  */
/*  MessageText: */
/*  */
/*   IDN is internally handled. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_INTERNALLY_HANDLED_IDN ((TLR_RESULT)0xC0850018L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_NO_IDN */
/*  */
/*  MessageText: */
/*  */
/*   IDN not available. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_NO_IDN    ((TLR_RESULT)0xC0851001L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_INVALID_ACCESS_TO_ELEMENT_1 */
/*  */
/*  MessageText: */
/*  */
/*   Invalid access to element 1. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_INVALID_ACCESS_TO_ELEMENT_1 ((TLR_RESULT)0xC0851009L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_NO_NAME */
/*  */
/*  MessageText: */
/*  */
/*   No Name. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_NO_NAME   ((TLR_RESULT)0xC0852001L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_NAME_TRANSMISSION_IS_TOO_SHORT */
/*  */
/*  MessageText: */
/*  */
/*   Name transmision is too short. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_NAME_TRANSMISSION_IS_TOO_SHORT ((TLR_RESULT)0xC0852002L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_NAME_TRANSMISSION_IS_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Name transmision is too long. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_NAME_TRANSMISSION_IS_TOO_LONG ((TLR_RESULT)0xC0852003L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_NAME_CANNOT_BE_CHANGED */
/*  */
/*  MessageText: */
/*  */
/*   Name cannot be changed (read only). */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_NAME_CANNOT_BE_CHANGED ((TLR_RESULT)0xC0852004L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_NAME_IS_WRITE_PROTECTED_AT_THIS_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Name is write protected at this time. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_NAME_IS_WRITE_PROTECTED_AT_THIS_TIME ((TLR_RESULT)0xC0852005L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_ATTRIBUTE_TRANSMISSION_IS_TOO_SHORT */
/*  */
/*  MessageText: */
/*  */
/*   Attribute transmision is too short. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_ATTRIBUTE_TRANSMISSION_IS_TOO_SHORT ((TLR_RESULT)0xC0853002L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_ATTRIBUTE_TRANSMISSION_IS_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Attribute transmision is too long. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_ATTRIBUTE_TRANSMISSION_IS_TOO_LONG ((TLR_RESULT)0xC0853003L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_ATTRIBUTE_CANNOT_BE_CHANGED */
/*  */
/*  MessageText: */
/*  */
/*   Attribute cannot be changed (read only). */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_ATTRIBUTE_CANNOT_BE_CHANGED ((TLR_RESULT)0xC0853004L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_ATTRIBUTE_IS_WRITE_PROTECTED_AT_THIS_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Attribute is write protected at this time. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_ATTRIBUTE_IS_WRITE_PROTECTED_AT_THIS_TIME ((TLR_RESULT)0xC0853005L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_NO_UNIT */
/*  */
/*  MessageText: */
/*  */
/*   No unit. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_NO_UNIT   ((TLR_RESULT)0xC0854001L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_UNIT_TRANSMISSION_IS_TOO_SHORT */
/*  */
/*  MessageText: */
/*  */
/*   Unit transmision is too short. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_UNIT_TRANSMISSION_IS_TOO_SHORT ((TLR_RESULT)0xC0854002L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_UNIT_TRANSMISSION_IS_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Unit transmision is too long. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_UNIT_TRANSMISSION_IS_TOO_LONG ((TLR_RESULT)0xC0854003L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_UNIT_CANNOT_BE_CHANGED */
/*  */
/*  MessageText: */
/*  */
/*   Unit cannot be changed (read only). */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_UNIT_CANNOT_BE_CHANGED ((TLR_RESULT)0xC0854004L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_UNIT_IS_WRITE_PROTECTED_AT_THIS_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Unit is write protected at this time. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_UNIT_IS_WRITE_PROTECTED_AT_THIS_TIME ((TLR_RESULT)0xC0854005L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_NO_MINIMUM_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   No minimum value. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_NO_MINIMUM_VALUE ((TLR_RESULT)0xC0855001L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_MINIMUM_VALUE_TRANSMISSION_IS_TOO_SHORT */
/*  */
/*  MessageText: */
/*  */
/*   Minimum value transmision is too short. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_MINIMUM_VALUE_TRANSMISSION_IS_TOO_SHORT ((TLR_RESULT)0xC0855002L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_MINIMUM_VALUE_TRANSMISSION_IS_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Minimum value transmision is too long. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_MINIMUM_VALUE_TRANSMISSION_IS_TOO_LONG ((TLR_RESULT)0xC0855003L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_MINIMUM_VALUE_CANNOT_BE_CHANGED */
/*  */
/*  MessageText: */
/*  */
/*   Minimum value cannot be changed (read only). */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_MINIMUM_VALUE_CANNOT_BE_CHANGED ((TLR_RESULT)0xC0855004L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_MINIMUM_VALUE_IS_WRITE_PROTECTED_AT_THIS_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Minimum value is write protected at this time. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_MINIMUM_VALUE_IS_WRITE_PROTECTED_AT_THIS_TIME ((TLR_RESULT)0xC0855005L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_NO_MAXIMUM_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   No maximum value. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_NO_MAXIMUM_VALUE ((TLR_RESULT)0xC0856001L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_MAXIMUM_VALUE_TRANSMISSION_IS_TOO_SHORT */
/*  */
/*  MessageText: */
/*  */
/*   Maximum value transmision is too short. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_MAXIMUM_VALUE_TRANSMISSION_IS_TOO_SHORT ((TLR_RESULT)0xC0856002L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_MAXIMUM_VALUE_TRANSMISSION_IS_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Maximum value transmision is too long. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_MAXIMUM_VALUE_TRANSMISSION_IS_TOO_LONG ((TLR_RESULT)0xC0856003L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_MAXIMUM_VALUE_CANNOT_BE_CHANGED */
/*  */
/*  MessageText: */
/*  */
/*   Maximum value cannot be changed (read only). */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_MAXIMUM_VALUE_CANNOT_BE_CHANGED ((TLR_RESULT)0xC0856004L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_MAXIMUM_VALUE_IS_WRITE_PROTECTED_AT_THIS_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Maximum value is write protected at this time. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_MAXIMUM_VALUE_IS_WRITE_PROTECTED_AT_THIS_TIME ((TLR_RESULT)0xC0856005L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_OPDATA_TRANSMISSION_IS_TOO_SHORT */
/*  */
/*  MessageText: */
/*  */
/*   Operation data transmision is too short. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_OPDATA_TRANSMISSION_IS_TOO_SHORT ((TLR_RESULT)0xC0857002L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_OPDATA_TRANSMISSION_IS_TOO_LONG */
/*  */
/*  MessageText: */
/*  */
/*   Operation data transmision is too long. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_OPDATA_TRANSMISSION_IS_TOO_LONG ((TLR_RESULT)0xC0857003L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_OPDATA_CANNOT_BE_CHANGED */
/*  */
/*  MessageText: */
/*  */
/*   Operation data cannot be changed (read only). */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_OPDATA_CANNOT_BE_CHANGED ((TLR_RESULT)0xC0857004L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_OPDATA_IS_WRITE_PROTECTED_AT_THIS_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Operation data is write protected at this time. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_OPDATA_IS_WRITE_PROTECTED_AT_THIS_TIME ((TLR_RESULT)0xC0857005L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_OPDATA_IS_LOWER_THAN_MINIMUM_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Operation data is lower than Minimum value. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_OPDATA_IS_LOWER_THAN_MINIMUM_VALUE ((TLR_RESULT)0xC0857006L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_OPDATA_IS_HIGHER_THAN_MAXIMUM_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Operation data is higher than Maximum value. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_OPDATA_IS_HIGHER_THAN_MAXIMUM_VALUE ((TLR_RESULT)0xC0857007L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_OPDATA_IS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid operation data. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_OPDATA_IS_INVALID ((TLR_RESULT)0xC0857008L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_OPDATA_IS_WRITE_PROTECTED_BY_PASSWORD */
/*  */
/*  MessageText: */
/*  */
/*   Operation data is write protected by password. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_OPDATA_IS_WRITE_PROTECTED_BY_PASSWORD ((TLR_RESULT)0xC0857009L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_OPDATA_IS_WRITE_PROTECTED_DUE_CYCLICALLY_CONFIGURED */
/*  */
/*  MessageText: */
/*  */
/*   Operation data is write protected. It is configured cyclically. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_OPDATA_IS_WRITE_PROTECTED_DUE_CYCLICALLY_CONFIGURED ((TLR_RESULT)0xC085700AL)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_OPDATA_INVALID_INDIRECT_ADDRESSING */
/*  */
/*  MessageText: */
/*  */
/*   Invalid indirect addressing. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_OPDATA_INVALID_INDIRECT_ADDRESSING ((TLR_RESULT)0xC085700BL)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_OPDATA_IS_WRITE_PROTECTED_DUE_OTHER_SETTINGS */
/*  */
/*  MessageText: */
/*  */
/*   Operation data is write protected due other settings. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_OPDATA_IS_WRITE_PROTECTED_DUE_OTHER_SETTINGS ((TLR_RESULT)0xC085700CL)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_OPDATA_INVALID_FLOATING_POINT_NUMBER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid floating point number. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_OPDATA_INVALID_FLOATING_POINT_NUMBER ((TLR_RESULT)0xC085700DL)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_OPDATA_IS_WRITE_PROTECTED_AT_PARAMETERIZATION_LEVEL */
/*  */
/*  MessageText: */
/*  */
/*   Operation data is write protected at parameterization level. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_OPDATA_IS_WRITE_PROTECTED_AT_PARAMETERIZATION_LEVEL ((TLR_RESULT)0xC085700EL)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_OPDATA_IS_WRITE_PROTECTED_AT_OPERATION_LEVEL */
/*  */
/*  MessageText: */
/*  */
/*   Operation data is write protected at operation level. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_OPDATA_IS_WRITE_PROTECTED_AT_OPERATION_LEVEL ((TLR_RESULT)0xC085700FL)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_OPDATA_PROCEDURE_COMMAND_ALREADY_ACTIVE */
/*  */
/*  MessageText: */
/*  */
/*   Procedure command already active. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_OPDATA_PROCEDURE_COMMAND_ALREADY_ACTIVE ((TLR_RESULT)0xC0857010L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_OPDATA_PROCEDURE_COMMAND_NOT_INTERRUPTIBLE */
/*  */
/*  MessageText: */
/*  */
/*   Procedure command not interruptible. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_OPDATA_PROCEDURE_COMMAND_NOT_INTERRUPTIBLE ((TLR_RESULT)0xC0857011L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_OPDATA_PROCEDURE_COMMAND_NOT_EXECUTABLE_AT_THIS_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Procedure Command is not executable at this time (e.g. wrong slave state). */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_OPDATA_PROCEDURE_COMMAND_NOT_EXECUTABLE_AT_THIS_TIME ((TLR_RESULT)0xC0857012L)

/*  */
/*  MessageId: TLR_E_SERCOSIII_SL_IDN_OPDATA_PROCEDURE_COMMAND_NOT_EXECUTABLE_INVALID_PARAM */
/*  */
/*  MessageText: */
/*  */
/*   Procedure Command is not executable due invalid parameters. */
/*  */
#define TLR_E_SERCOSIII_SL_IDN_OPDATA_PROCEDURE_COMMAND_NOT_EXECUTABLE_INVALID_PARAM ((TLR_RESULT)0xC0857013L)




#endif  /* __SERCOSIII_IDN_ERROR_H */

#ifndef __SERCOSIII_MA_AP_ERROR_H
#define __SERCOSIII_MA_AP_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Sercos III - Result and Status Codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_SIII_MA_AP_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command value. */
/*  */
#define TLR_E_SIII_MA_AP_COMMAND_INVALID ((TLR_RESULT)0xC0720001L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup parameter. */
/*  */
#define TLR_E_SIII_MA_AP_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0720002L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_MDT_PROCESS_DATA_IMAGE_SIZE_NOT_POSSIBLE */
/*  */
/*  MessageText: */
/*  */
/*   Output Process Data Image Size not possible (MDT). */
/*  */
#define TLR_E_SIII_MA_AP_MDT_PROCESS_DATA_IMAGE_SIZE_NOT_POSSIBLE ((TLR_RESULT)0xC0720003L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_AT_PROCESS_DATA_IMAGE_SIZE_NOT_POSSIBLE */
/*  */
/*  MessageText: */
/*  */
/*   Input Process Data Image Size not possible (AT). */
/*  */
#define TLR_E_SIII_MA_AP_AT_PROCESS_DATA_IMAGE_SIZE_NOT_POSSIBLE ((TLR_RESULT)0xC0720004L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_LLD_NOT_STARTED */
/*  */
/*  MessageText: */
/*  */
/*   SercosIII Low Level Driver not started. */
/*  */
#define TLR_E_SIII_MA_AP_LLD_NOT_STARTED ((TLR_RESULT)0xC0720005L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_SET_PHASE_NOT_ALLOWED_DURING_CFG_LOADING */
/*  */
/*  MessageText: */
/*  */
/*   Set Phase command not allowed during configuration loading. */
/*  */
#define TLR_E_SIII_MA_AP_SET_PHASE_NOT_ALLOWED_DURING_CFG_LOADING ((TLR_RESULT)0xC0720006L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_PACKET_CFG_INTERFACE_NOT_AVAILABLE_DURING_CFG_LOADING */
/*  */
/*  MessageText: */
/*  */
/*   Configuration via packets is not available during configuration loading. */
/*  */
#define TLR_E_SIII_MA_AP_PACKET_CFG_INTERFACE_NOT_AVAILABLE_DURING_CFG_LOADING ((TLR_RESULT)0xC0720007L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_C1D_DIAGNOSIS_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   C1D Diagnosis Error. */
/*  */
#define TLR_E_SIII_MA_AP_C1D_DIAGNOSIS_ERROR ((TLR_RESULT)0xC0720008L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_BUS_SYNC_ERROR_THRESHOLD */
/*  */
/*  MessageText: */
/*  */
/*   Bus Sync Error Threshold reached. */
/*  */
#define TLR_E_SIII_MA_AP_BUS_SYNC_ERROR_THRESHOLD ((TLR_RESULT)0xC0720009L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_CHANNEL_INIT */
/*  */
/*  MessageText: */
/*  */
/*   Channel-Init detected. */
/*  */
#define TLR_E_SIII_MA_AP_CHANNEL_INIT    ((TLR_RESULT)0xC072000AL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_CPX_CP0_DEV_STATUS_INVALID_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   CPx -> CP0 Dev Status Invalid Timeout. */
/*  */
#define TLR_E_SIII_MA_AP_CPX_CP0_DEV_STATUS_INVALID_TIMEOUT ((TLR_RESULT)0xC072000BL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_CP1_CP2_DEV_STATUS_INVALID_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   CP1 -> CP2 Dev Status Invalid Timeout. */
/*  */
#define TLR_E_SIII_MA_AP_CP1_CP2_DEV_STATUS_INVALID_TIMEOUT ((TLR_RESULT)0xC072000CL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_CP2_CP3_DEV_STATUS_INVALID_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   CP2 -> CP3 Dev Status Invalid Timeout. */
/*  */
#define TLR_E_SIII_MA_AP_CP2_CP3_DEV_STATUS_INVALID_TIMEOUT ((TLR_RESULT)0xC072000DL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_CP3_CP4_DEV_STATUS_INVALID_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   CP3 -> CP4 Dev Status Invalid Timeout. */
/*  */
#define TLR_E_SIII_MA_AP_CP3_CP4_DEV_STATUS_INVALID_TIMEOUT ((TLR_RESULT)0xC072000EL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_CP1_DEV_STATUS_VALID_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   CP1 Dev Status Valid Timeout. */
/*  */
#define TLR_E_SIII_MA_AP_CP1_DEV_STATUS_VALID_TIMEOUT ((TLR_RESULT)0xC072000FL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_CP2_DEV_STATUS_VALID_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   CP2 Dev Status Valid Timeout. */
/*  */
#define TLR_E_SIII_MA_AP_CP2_DEV_STATUS_VALID_TIMEOUT ((TLR_RESULT)0xC0720010L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_CP3_DEV_STATUS_VALID_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   CP3 Dev Status Valid Timeout. */
/*  */
#define TLR_E_SIII_MA_AP_CP3_DEV_STATUS_VALID_TIMEOUT ((TLR_RESULT)0xC0720011L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_CP4_DEV_STATUS_VALID_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   CP4 Dev Status Valid Timeout. */
/*  */
#define TLR_E_SIII_MA_AP_CP4_DEV_STATUS_VALID_TIMEOUT ((TLR_RESULT)0xC0720012L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_CP3_TIMING_CONFIGURATION_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   CP3 Timing Configuration Error. */
/*  */
#define TLR_E_SIII_MA_AP_CP3_TIMING_CONFIGURATION_ERROR ((TLR_RESULT)0xC0720013L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_CP0_CP1_TOPO_ADDR_INVALID_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   CP0 -> CP1 Topology Address Invalid Timeout. */
/*  */
#define TLR_E_SIII_MA_AP_CP0_CP1_TOPO_ADDR_INVALID_TIMEOUT ((TLR_RESULT)0xC0720014L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_UNKNOWN_STATE_CHG_STOPPED_REASON */
/*  */
/*  MessageText: */
/*  */
/*   Unknown State Change Stopped Reason. */
/*  */
#define TLR_E_SIII_MA_AP_UNKNOWN_STATE_CHG_STOPPED_REASON ((TLR_RESULT)0xC0720015L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_INITCMD_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Service channel access failed (InitCmd). */
/*  */
#define TLR_E_SIII_MA_AP_INITCMD_ERROR   ((TLR_RESULT)0xC0720016L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_CONN_LENGTH_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Connection Length mismatch. */
/*  */
#define TLR_E_SIII_MA_AP_CONN_LENGTH_ERROR ((TLR_RESULT)0xC0720017L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_S_0_127_COMMAND_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   S-0-127 Command execution ended with error. */
/*  */
#define TLR_E_SIII_MA_AP_S_0_127_COMMAND_ERROR ((TLR_RESULT)0xC0720018L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_S_0_128_COMMAND_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   S-0-128 Command execution ended with error. */
/*  */
#define TLR_E_SIII_MA_AP_S_0_128_COMMAND_ERROR ((TLR_RESULT)0xC0720019L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_S_0_1024_COMMAND_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   S-0-1024 Command execution ended with error. */
/*  */
#define TLR_E_SIII_MA_AP_S_0_1024_COMMAND_ERROR ((TLR_RESULT)0xC072001AL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_MDT_NOT_EXCHANGED */
/*  */
/*  MessageText: */
/*  */
/*   MDT not exchanged. */
/*  */
#define TLR_E_SIII_MA_AP_MDT_NOT_EXCHANGED ((TLR_RESULT)0xC072001BL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_AT_NOT_EXCHANGED */
/*  */
/*  MessageText: */
/*  */
/*   AT not exchanged. */
/*  */
#define TLR_E_SIII_MA_AP_AT_NOT_EXCHANGED ((TLR_RESULT)0xC072001CL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_FRAME_LOSS */
/*  */
/*  MessageText: */
/*  */
/*   Frame loss. */
/*  */
#define TLR_E_SIII_MA_AP_FRAME_LOSS      ((TLR_RESULT)0xC072001DL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_EXT_TRIGGER_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   No signal on External Trigger input within timeout. */
/*  */
#define TLR_E_SIII_MA_AP_EXT_TRIGGER_TIMEOUT ((TLR_RESULT)0xC072001EL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_EXT_TRIGGER_LOSS */
/*  */
/*  MessageText: */
/*  */
/*   Signal lost on External Trigger input. */
/*  */
#define TLR_E_SIII_MA_AP_EXT_TRIGGER_LOSS ((TLR_RESULT)0xC072001FL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_ALL_SLAVES_LOST */
/*  */
/*  MessageText: */
/*  */
/*   All slaves lost. */
/*  */
#define TLR_E_SIII_MA_AP_ALL_SLAVES_LOST ((TLR_RESULT)0xC0720020L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_BUS_SCAN_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Bus Scan Timeout. */
/*  */
#define TLR_E_SIII_MA_AP_BUS_SCAN_TIMEOUT ((TLR_RESULT)0xC0720021L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_INTERNAL_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Internal Error detected. */
/*  */
#define TLR_E_SIII_MA_AP_INTERNAL_ERROR  ((TLR_RESULT)0xC0720022L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_S_0_1050_X_5_CONN_LENGTH_READ_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Connection Length could not be read due to incorrect configuration. */
/*  */
#define TLR_E_SIII_MA_AP_S_0_1050_X_5_CONN_LENGTH_READ_ERROR ((TLR_RESULT)0xC0720023L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_OPENING_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing Tag does not match opening tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_OPENING_TAG ((TLR_RESULT)0xC0724000L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_NUMBER_FIELD */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected opening tag in number field. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_NUMBER_FIELD ((TLR_RESULT)0xC0724001L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_NUMBER_FIELD */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected single tag in number field. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_NUMBER_FIELD ((TLR_RESULT)0xC0724002L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_NUMBER_FIELD_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing tag does not match number field tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_NUMBER_FIELD_TAG ((TLR_RESULT)0xC0724003L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_NUMBER_FIELD_IS_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Number Field is invalid. */
/*  */
#define TLR_E_SIII_MA_AP_XML_NUMBER_FIELD_IS_INVALID ((TLR_RESULT)0xC0724004L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_STRING_FIELD */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected opening tag in string field. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_STRING_FIELD ((TLR_RESULT)0xC0724005L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_STRING_FIELD */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected single tag in string field. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_STRING_FIELD ((TLR_RESULT)0xC0724006L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_STRING_FIELD_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing tag does not match string field tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_STRING_FIELD_TAG ((TLR_RESULT)0xC0724007L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_DATA_FIELD */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected opening tag in data field. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_DATA_FIELD ((TLR_RESULT)0xC0724008L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_DATA_FIELD */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected single tag in data field. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_DATA_FIELD ((TLR_RESULT)0xC0724009L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_DATA_FIELD_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing tag does not match data field tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_DATA_FIELD_TAG ((TLR_RESULT)0xC072400AL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_DATA_FIELD_IS_NOT_A_HEX_STRING */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Data field is not a hex string. */
/*  */
#define TLR_E_SIII_MA_AP_XML_DATA_FIELD_IS_NOT_A_HEX_STRING ((TLR_RESULT)0xC072400BL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_SIIICFG_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected opening tag in SIIICfg block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_SIIICFG_BLOCK ((TLR_RESULT)0xC072400CL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_SIIICFG_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected tag in SIIICfg block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_SIIICFG_BLOCK ((TLR_RESULT)0xC072400DL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_CLOSING_TAG_IN_SIIICFG_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected closing tag in SIIICfg block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_CLOSING_TAG_IN_SIIICFG_BLOCK ((TLR_RESULT)0xC072400EL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_TAG_IN_SIIICFG_BLOCK_SLAVE_PART */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected closing tag in SIIICfg block (Slave Part). */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_TAG_IN_SIIICFG_BLOCK_SLAVE_PART ((TLR_RESULT)0xC072400FL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_SIIICFG_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing tag does not match SIIICfg tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_SIIICFG_TAG ((TLR_RESULT)0xC0724010L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_FILE_IS_NOT_A_SIIICFG_XML */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: XML file does not contain a SIIICfg xml. */
/*  */
#define TLR_E_SIII_MA_AP_XML_FILE_IS_NOT_A_SIIICFG_XML ((TLR_RESULT)0xC0724011L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_STD_PARAMS_MASTER_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected tag in std_params_master block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_STD_PARAMS_MASTER_BLOCK ((TLR_RESULT)0xC0724012L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_STD_PARAMS_MASTER_BLOCK_IS_INCOMPLETE */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Incomplete std_params_master block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_STD_PARAMS_MASTER_BLOCK_IS_INCOMPLETE ((TLR_RESULT)0xC0724013L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_STD_PARAMS_MASTER_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Duplicate tag in std_params_master block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_STD_PARAMS_MASTER_BLOCK ((TLR_RESULT)0xC0724014L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_STD_PARAMS_MASTER_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing tag does not match std_params_master tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_STD_PARAMS_MASTER_TAG ((TLR_RESULT)0xC0724015L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_PARAMS_MASTER_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected single tag in params_master block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_PARAMS_MASTER_BLOCK ((TLR_RESULT)0xC0724016L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_PARAMS_MASTER_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Duplicate tag in params_master block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_PARAMS_MASTER_BLOCK ((TLR_RESULT)0xC0724017L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_PARAMS_MASTER_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected opening tag in params_master block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_PARAMS_MASTER_BLOCK ((TLR_RESULT)0xC0724018L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_PARAMS_MASTER_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing tag does not match params_master tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_PARAMS_MASTER_TAG ((TLR_RESULT)0xC0724019L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_PARAMS_MASTER_BLOCK_IS_INCOMPLETE */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Incomplete params_master block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_PARAMS_MASTER_BLOCK_IS_INCOMPLETE ((TLR_RESULT)0xC072401AL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_SYS_IDN_ENTRY_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected opening tag in sys_idn_entry block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_SYS_IDN_ENTRY_BLOCK ((TLR_RESULT)0xC072401BL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_SYS_IDN_ENTRY_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Duplicate tag in sys_idn_entry block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_SYS_IDN_ENTRY_BLOCK ((TLR_RESULT)0xC072401CL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_SYS_IDN_ENTRY_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected single tag in sys_idn_entry block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_SYS_IDN_ENTRY_BLOCK ((TLR_RESULT)0xC072401DL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_SYS_IDN_ENTRY_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing tag does not match sys_idn_entry tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_SYS_IDN_ENTRY_TAG ((TLR_RESULT)0xC072401EL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_SYS_IDN_ENTRY_BLOCK_IS_INCOMPLETE */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Incomplete sys_idn_entry block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_SYS_IDN_ENTRY_BLOCK_IS_INCOMPLETE ((TLR_RESULT)0xC072401FL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_SYS_GLOBAL_IDNS_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected opening tag in sys_global_idns block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_SYS_GLOBAL_IDNS_BLOCK ((TLR_RESULT)0xC0724020L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_SYS_GLOBAL_IDNS_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected single tag in sys_global_idns block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_SYS_GLOBAL_IDNS_BLOCK ((TLR_RESULT)0xC0724021L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_SYS_GLOBAL_IDNS_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing tag does not match sys_global_idns tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_SYS_GLOBAL_IDNS_TAG ((TLR_RESULT)0xC0724022L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_SYS_GLOBAL_IDNS_BLOCK_IS_INCOMPLETE */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Incomplete sys_global_idns block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_SYS_GLOBAL_IDNS_BLOCK_IS_INCOMPLETE ((TLR_RESULT)0xC0724023L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_MASTER_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected opening tag in master block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_MASTER_BLOCK ((TLR_RESULT)0xC0724024L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_MASTER_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected single tag in master block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_MASTER_BLOCK ((TLR_RESULT)0xC0724025L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_MASTER_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing tag does not match master tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_MASTER_TAG ((TLR_RESULT)0xC0724026L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_MASTER_BLOCK_IS_INCOMPLETE */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Incomplete master block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_MASTER_BLOCK_IS_INCOMPLETE ((TLR_RESULT)0xC0724027L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_MASTER_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Duplicate tag in master block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_MASTER_BLOCK ((TLR_RESULT)0xC0724028L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_TELEGRAM_ASSIGNMENT_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected single tag in telegram assignment block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_TELEGRAM_ASSIGNMENT_BLOCK ((TLR_RESULT)0xC0724029L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_TELEGRAM_ASSIGNMENT_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected opening tag in telegram assignment block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_TELEGRAM_ASSIGNMENT_BLOCK ((TLR_RESULT)0xC072402AL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_TELEGRAM_ASSIGNMENT_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Duplicate tag in telegram assignment block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_TELEGRAM_ASSIGNMENT_BLOCK ((TLR_RESULT)0xC072402BL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_TELEGRAM_ASSIGNMENT_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing tag does not match telegram assignment tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_TELEGRAM_ASSIGNMENT_TAG ((TLR_RESULT)0xC072402CL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_TELEGRAM_ASSIGNMENT_IS_INCOMPLETE */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: telegram assignment block is incomplete. */
/*  */
#define TLR_E_SIII_MA_AP_XML_TELEGRAM_ASSIGNMENT_IS_INCOMPLETE ((TLR_RESULT)0xC072402DL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_STD_PARAMS_SLAVE_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected single tag in std_params_slave block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_STD_PARAMS_SLAVE_BLOCK ((TLR_RESULT)0xC072402EL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_STD_PARAMS_SLAVE_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected opening tag in std_params_slave block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_STD_PARAMS_SLAVE_BLOCK ((TLR_RESULT)0xC072402FL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_STD_PARAMS_SLAVE_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Duplicate tag in std_params_slave block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_STD_PARAMS_SLAVE_BLOCK ((TLR_RESULT)0xC0724030L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_STD_PARAMS_SLAVE_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing tag does not match std_params_slave tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_STD_PARAMS_SLAVE_TAG ((TLR_RESULT)0xC0724031L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_STD_PARAMS_SLAVE_BLOCK_IS_INCOMPLETE */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: std_params_slave block is incomplete. */
/*  */
#define TLR_E_SIII_MA_AP_XML_STD_PARAMS_SLAVE_BLOCK_IS_INCOMPLETE ((TLR_RESULT)0xC0724032L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_PARAMS_SLAVE_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected single tag in params_slave block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_PARAMS_SLAVE_BLOCK ((TLR_RESULT)0xC0724033L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_PARAMS_SLAVE_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected opening tag in params_slave block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_PARAMS_SLAVE_BLOCK ((TLR_RESULT)0xC0724034L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_PARAMS_SLAVE_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Duplicate tag in params_slave block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_PARAMS_SLAVE_BLOCK ((TLR_RESULT)0xC0724035L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_PARAMS_SLAVE_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing tag does not match params_slave tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_PARAMS_SLAVE_TAG ((TLR_RESULT)0xC0724036L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_PARAMS_SLAVE_BLOCK_IS_INCOMPLETE */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: params_slave block is incomplete. */
/*  */
#define TLR_E_SIII_MA_AP_XML_PARAMS_SLAVE_BLOCK_IS_INCOMPLETE ((TLR_RESULT)0xC0724037L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_SLAVE_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected single tag in slave block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_SLAVE_BLOCK ((TLR_RESULT)0xC0724038L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_SLAVE_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected opening tag in slave block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_SLAVE_BLOCK ((TLR_RESULT)0xC0724039L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_SLAVE_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Duplicate tag in slave block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_SLAVE_BLOCK ((TLR_RESULT)0xC072403AL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_SLAVE_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing tag does not match slave tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_SLAVE_TAG ((TLR_RESULT)0xC072403BL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_SLAVE_BLOCK_IS_INCOMPLETE */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: slave block is incomplete. */
/*  */
#define TLR_E_SIII_MA_AP_XML_SLAVE_BLOCK_IS_INCOMPLETE ((TLR_RESULT)0xC072403CL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_IDN_ENTRY_DATA_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected single tag in idn_entry block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_IDN_ENTRY_DATA_BLOCK ((TLR_RESULT)0xC072403DL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_IDN_ENTRY_DATA_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected opening tag in idn_entry block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_IDN_ENTRY_DATA_BLOCK ((TLR_RESULT)0xC072403EL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_IDN_ENTRY_DATA_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Duplicate tag in idn_entry block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_IDN_ENTRY_DATA_BLOCK ((TLR_RESULT)0xC072403FL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_IDN_ENTRY_DATA_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing tag does not match idn_entry tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_IDN_ENTRY_DATA_TAG ((TLR_RESULT)0xC0724040L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_IDN_ENTRY_BLOCK_DATA_IS_INCOMPLETE */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: idn_entry block is incomplete. */
/*  */
#define TLR_E_SIII_MA_AP_XML_IDN_ENTRY_BLOCK_DATA_IS_INCOMPLETE ((TLR_RESULT)0xC0724041L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_IDN_ENTRY_BLOCK_HAS_INVALID_ATTRIBUTE */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: idn_entry block has invalid attribute. */
/*  */
#define TLR_E_SIII_MA_AP_XML_IDN_ENTRY_BLOCK_HAS_INVALID_ATTRIBUTE ((TLR_RESULT)0xC0724042L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_IDN_ENTRY_DATA_BLOCK_HAS_INVALID_DATA */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: idn_entry block has invalid data. */
/*  */
#define TLR_E_SIII_MA_AP_XML_IDN_ENTRY_DATA_BLOCK_HAS_INVALID_DATA ((TLR_RESULT)0xC0724043L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_IDN_ENTRY_DATA_BLOCK_CONTAINS_NON_HEX_DIGIT_CHARACTERS */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: idn_entry block contains non-hex digit characters. */
/*  */
#define TLR_E_SIII_MA_AP_XML_IDN_ENTRY_DATA_BLOCK_CONTAINS_NON_HEX_DIGIT_CHARACTERS ((TLR_RESULT)0xC0724044L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_IDN_ENTRY_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected single tag in idn_entry block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_IDN_ENTRY_BLOCK ((TLR_RESULT)0xC0724045L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_IDN_ENTRY_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected opening tag in idn_entry block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_IDN_ENTRY_BLOCK ((TLR_RESULT)0xC0724046L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_IDN_ENTRY_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Duplicate tag in idn_entry block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_IDN_ENTRY_BLOCK ((TLR_RESULT)0xC0724047L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_IDN_ENTRY_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing tag does not match idn_entry tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_IDN_ENTRY_TAG ((TLR_RESULT)0xC0724048L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_IDN_ENTRY_BLOCK_IS_INCOMPLETE */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: idn_entry block is incomplete. */
/*  */
#define TLR_E_SIII_MA_AP_XML_IDN_ENTRY_BLOCK_IS_INCOMPLETE ((TLR_RESULT)0xC0724049L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SEQUENCE_OF_TAGS_IN_IDN_ENTRY_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected sequence of tags in idn_entry block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SEQUENCE_OF_TAGS_IN_IDN_ENTRY_BLOCK ((TLR_RESULT)0xC072404AL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_IDN_CONFIG_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected single tag in idn_config block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_IDN_CONFIG_BLOCK ((TLR_RESULT)0xC072404BL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_IDN_CONFIG_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected opening tag in idn_config block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_IDN_CONFIG_BLOCK ((TLR_RESULT)0xC072404CL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_IDN_CONFIG_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing tag does not match idn_config tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_IDN_CONFIG_TAG ((TLR_RESULT)0xC072404DL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_CONNECTION_ENTRY_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected single tag in connection_entry block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_CONNECTION_ENTRY_BLOCK ((TLR_RESULT)0xC072404EL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_CONNECTION_ENTRY_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected opening tag in connection_entry block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_CONNECTION_ENTRY_BLOCK ((TLR_RESULT)0xC072404FL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_CONNECTION_ENTRY_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Duplicate tag in connection_entry block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_CONNECTION_ENTRY_BLOCK ((TLR_RESULT)0xC0724050L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_CONNECTION_ENTRY_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing tag does not match connection_entry tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_CONNECTION_ENTRY_TAG ((TLR_RESULT)0xC0724051L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CONNECTION_ENTRY_BLOCK_IS_INCOMPLETE */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: connection_entry block is incomplete. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CONNECTION_ENTRY_BLOCK_IS_INCOMPLETE ((TLR_RESULT)0xC0724052L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_CONNECTIONS_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected single tag in connections block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_CONNECTIONS_BLOCK ((TLR_RESULT)0xC0724053L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_CONNECTIONS_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected opening tag in connections block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_CONNECTIONS_BLOCK ((TLR_RESULT)0xC0724054L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_CONNECTIONS_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing tag does not match connections tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_CONNECTIONS_TAG ((TLR_RESULT)0xC0724055L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_CONFIG_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected single tag in config block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SINGLE_TAG_IN_CONFIG_BLOCK ((TLR_RESULT)0xC0724056L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_CONFIG_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected opening tag in config block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_OPENING_TAG_IN_CONFIG_BLOCK ((TLR_RESULT)0xC0724057L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_CONFIG_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Duplicate tag in config block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_CONFIG_BLOCK ((TLR_RESULT)0xC0724058L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_CONFIG_TAG */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Closing tag does not match config tag. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CLOSING_TAG_DOES_NOT_MATCH_CONFIG_TAG ((TLR_RESULT)0xC0724059L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CONFIG_BLOCK_IS_INCOMPLETE */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: config block is incomplete. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CONFIG_BLOCK_IS_INCOMPLETE ((TLR_RESULT)0xC072405AL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNEXPECTED_SEQUENCE_OF_TAGS_IN_CONFIG_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unexpected sequence of tags in config block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNEXPECTED_SEQUENCE_OF_TAGS_IN_CONFIG_BLOCK ((TLR_RESULT)0xC072405BL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_INVALID_DATA_LENGTH_OF_SYS_IDN_ENTRY */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Invalid Data Length of Sys Idn Entry. */
/*  */
#define TLR_E_SIII_MA_AP_XML_INVALID_DATA_LENGTH_OF_SYS_IDN_ENTRY ((TLR_RESULT)0xC072405CL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_SYS_GLOBAL_IDNS_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Duplicate tag in sys_global_idns block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_DUPLICATE_TAG_IN_SYS_GLOBAL_IDNS_BLOCK ((TLR_RESULT)0xC072405DL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_UNSUPPORTED_IDN_IN_SYS_GLOBAL_IDNS_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Unsupported IDN in sys_global_idns block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_UNSUPPORTED_IDN_IN_SYS_GLOBAL_IDNS_BLOCK ((TLR_RESULT)0xC072405EL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_INVALID_IDN_DATA_IN_SYS_GLOBAL_IDNS_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Invalid IDN data in sys_global_idns block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_INVALID_IDN_DATA_IN_SYS_GLOBAL_IDNS_BLOCK ((TLR_RESULT)0xC072405FL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_INVALID_TELEGRAM_NUMBER_IN_TELEGRAM_ASSIGNMENT */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Invalid Telegram Number in Telegram Assignment. */
/*  */
#define TLR_E_SIII_MA_AP_XML_INVALID_TELEGRAM_NUMBER_IN_TELEGRAM_ASSIGNMENT ((TLR_RESULT)0xC0724060L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_INVALID_TELEGRAM_OFFSET_IN_TELEGRAM_ASSIGNMENT */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Invalid Telegram Offset in Telegram Assignment. */
/*  */
#define TLR_E_SIII_MA_AP_XML_INVALID_TELEGRAM_OFFSET_IN_TELEGRAM_ASSIGNMENT ((TLR_RESULT)0xC0724061L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_INVALID_VALUE_IN_ACTIVE_FIELD */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Invalid Value in Active Field. */
/*  */
#define TLR_E_SIII_MA_AP_XML_INVALID_VALUE_IN_ACTIVE_FIELD ((TLR_RESULT)0xC0724062L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_INVALID_SERCOS_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Invalid SERCOS Address in Configuration. */
/*  */
#define TLR_E_SIII_MA_AP_XML_INVALID_SERCOS_ADDRESS ((TLR_RESULT)0xC0724063L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_INVALID_VALUE_IN_HOTPLUG_FIELD */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Invalid Value in Hot Plug Field. */
/*  */
#define TLR_E_SIII_MA_AP_XML_INVALID_VALUE_IN_HOTPLUG_FIELD ((TLR_RESULT)0xC0724064L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_INVALID_VALUE_IN_NRT_SUPPORT_FIELD */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Invalid Value in NRT Support Field. */
/*  */
#define TLR_E_SIII_MA_AP_XML_INVALID_VALUE_IN_NRT_SUPPORT_FIELD ((TLR_RESULT)0xC0724065L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_IDN_DATA_LENGTH_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: IDN Data Length invalid. */
/*  */
#define TLR_E_SIII_MA_AP_XML_IDN_DATA_LENGTH_INVALID ((TLR_RESULT)0xC0724066L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_IDN_PHASE_TRANSITION_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: IDN Phase Transition invalid. */
/*  */
#define TLR_E_SIII_MA_AP_XML_IDN_PHASE_TRANSITION_INVALID ((TLR_RESULT)0xC0724067L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_IDN_ELEMENT_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: IDN Element invalid. */
/*  */
#define TLR_E_SIII_MA_AP_XML_IDN_ELEMENT_INVALID ((TLR_RESULT)0xC0724068L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CONNECTION_NUMBER_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Connection Number invalid. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CONNECTION_NUMBER_INVALID ((TLR_RESULT)0xC0724069L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CONNECTION_TELEGRAM_OFFSET_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Connection Telegram Offset invalid. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CONNECTION_TELEGRAM_OFFSET_INVALID ((TLR_RESULT)0xC072406AL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CONNECTION_TELEGRAM_NUMBER_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Connection Telegram Number invalid. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CONNECTION_TELEGRAM_NUMBER_INVALID ((TLR_RESULT)0xC072406BL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CONNECTION_TELEGRAM_TYPE_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Connection Telegram Type invalid. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CONNECTION_TELEGRAM_TYPE_INVALID ((TLR_RESULT)0xC072406CL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CONNECTION_LENGTH_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Connection Length invalid. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CONNECTION_LENGTH_INVALID ((TLR_RESULT)0xC072406DL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CONNECTION_RTDATA_DPM_OFFSET_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Connection RtData DPM Offset invalid. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CONNECTION_RTDATA_DPM_OFFSET_INVALID ((TLR_RESULT)0xC072406EL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_CONNECTION_CCTRL_DPM_OFFSET_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Connection CCtrl DPM Offset invalid. */
/*  */
#define TLR_E_SIII_MA_AP_XML_CONNECTION_CCTRL_DPM_OFFSET_INVALID ((TLR_RESULT)0xC072406FL)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_XML_INVALID_SEQUENCE_OF_TAGS_IN_SIIICFG_BLOCK */
/*  */
/*  MessageText: */
/*  */
/*   XML structure: Invalid sequence of tags in SIIICfg Block. */
/*  */
#define TLR_E_SIII_MA_AP_XML_INVALID_SEQUENCE_OF_TAGS_IN_SIIICFG_BLOCK ((TLR_RESULT)0xC0724070L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_AT_LEAST_ONE_SLAVE_MISSING */
/*  */
/*  MessageText: */
/*  */
/*   At least one slave is missing. */
/*  */
#define TLR_E_SIII_MA_AP_AT_LEAST_ONE_SLAVE_MISSING ((TLR_RESULT)0xC0724071L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_BUS_IS_SPLIT_IN_TWO_LINES */
/*  */
/*  MessageText: */
/*  */
/*   Bus is split in two lines. */
/*  */
#define TLR_E_SIII_MA_AP_BUS_IS_SPLIT_IN_TWO_LINES ((TLR_RESULT)0xC0724072L)

/*  */
/*  MessageId: TLR_E_SIII_MA_AP_NO_SLAVES_CONNECTED */
/*  */
/*  MessageText: */
/*  */
/*   No slaves connected. */
/*  */
#define TLR_E_SIII_MA_AP_NO_SLAVES_CONNECTED ((TLR_RESULT)0xC0724073L)




#endif  /* __SERCOSIII_MA_AP_ERROR_H */

#ifndef __SERCOSIII_MA_CP_ERROR_H
#define __SERCOSIII_MA_CP_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Sercos III - Result and Status Codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_SIII_MA_CP_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command value. */
/*  */
#define TLR_E_SIII_MA_CP_COMMAND_INVALID ((TLR_RESULT)0xC0700001L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup parameter. */
/*  */
#define TLR_E_SIII_MA_CP_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0700002L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_WAITING_FOR_TOPOLOGY_DETECT */
/*  */
/*  MessageText: */
/*  */
/*   Waiting for Topology Detect (CP0). */
/*  */
#define TLR_E_SIII_MA_CP_WAITING_FOR_TOPOLOGY_DETECT ((TLR_RESULT)0xC0700003L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_NOT_STARTED */
/*  */
/*  MessageText: */
/*  */
/*   SercosIII Low Level Driver not started. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_NOT_STARTED ((TLR_RESULT)0xC0700004L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_INIT_CALLBACK_HP_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Initialization of HP Callback failed. */
/*  */
#define TLR_E_SIII_MA_CP_INIT_CALLBACK_HP_FAILED ((TLR_RESULT)0xC0700005L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_INIT_CALLBACK_DEVSTATUS_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Initialization of DevStatus Callback failed. */
/*  */
#define TLR_E_SIII_MA_CP_INIT_CALLBACK_DEVSTATUS_FAILED ((TLR_RESULT)0xC0700006L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_INIT_CALLBACK_TOPOLOGY_DETECT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Initialization of Topology Detect Callback failed. */
/*  */
#define TLR_E_SIII_MA_CP_INIT_CALLBACK_TOPOLOGY_DETECT_FAILED ((TLR_RESULT)0xC0700007L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_CONFIGURATION_BUFFER_ALREADY_OPEN */
/*  */
/*  MessageText: */
/*  */
/*   Configuration Buffer is already open. */
/*  */
#define TLR_E_SIII_MA_CP_CONFIGURATION_BUFFER_ALREADY_OPEN ((TLR_RESULT)0xC0700008L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_CONFIGURATION_BUFFER_IS_NOT_OPEN */
/*  */
/*  MessageText: */
/*  */
/*   Configuration Buffer is not open. */
/*  */
#define TLR_E_SIII_MA_CP_CONFIGURATION_BUFFER_IS_NOT_OPEN ((TLR_RESULT)0xC0700009L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_INVALID_SLAVE_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid slave address. */
/*  */
#define TLR_E_SIII_MA_CP_INVALID_SLAVE_ADDRESS ((TLR_RESULT)0xC070000AL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_TELEGRAM_OFFSET_CANNOT_BE_IN_MDT_TELEGRAM */
/*  */
/*  MessageText: */
/*  */
/*   Telegram offset cannot be set to MDT telegram. */
/*  */
#define TLR_E_SIII_MA_CP_TELEGRAM_OFFSET_CANNOT_BE_IN_MDT_TELEGRAM ((TLR_RESULT)0xC070000BL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_TELEGRAM_OFFSET_CANNOT_BE_IN_AT_TELEGRAM */
/*  */
/*  MessageText: */
/*  */
/*   Telegram offset cannot be set to AT telegram. */
/*  */
#define TLR_E_SIII_MA_CP_TELEGRAM_OFFSET_CANNOT_BE_IN_AT_TELEGRAM ((TLR_RESULT)0xC070000CL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_TELEGRAM_OFFSET_HAS_INVALID_TELEGRAM_NO */
/*  */
/*  MessageText: */
/*  */
/*   Telegram offset has invalid telegram number. */
/*  */
#define TLR_E_SIII_MA_CP_TELEGRAM_OFFSET_HAS_INVALID_TELEGRAM_NO ((TLR_RESULT)0xC070000DL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_TELEGRAM_OFFSET_HAS_INVALID_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Telegram offset has invalid offset in frame. */
/*  */
#define TLR_E_SIII_MA_CP_TELEGRAM_OFFSET_HAS_INVALID_OFFSET ((TLR_RESULT)0xC070000EL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_MDT_SVCH_TELEGRAM_OFFSET_CANNOT_BE_IN_AT_TELEGRAM */
/*  */
/*  MessageText: */
/*  */
/*   MDT ServiceChannel Telegram offset cannot be set to AT telegram. */
/*  */
#define TLR_E_SIII_MA_CP_MDT_SVCH_TELEGRAM_OFFSET_CANNOT_BE_IN_AT_TELEGRAM ((TLR_RESULT)0xC070000FL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_MDT_SVCH_TELEGRAM_OFFSET_HAS_INVALID_TELEGRAM_NO */
/*  */
/*  MessageText: */
/*  */
/*   MDT ServiceChannel Telegram offset has invalid telegram number. */
/*  */
#define TLR_E_SIII_MA_CP_MDT_SVCH_TELEGRAM_OFFSET_HAS_INVALID_TELEGRAM_NO ((TLR_RESULT)0xC0700010L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_MDT_SVCH_TELEGRAM_OFFSET_HAS_INVALID_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   MDT ServiceChannel Telegram offset has invalid offset in frame. */
/*  */
#define TLR_E_SIII_MA_CP_MDT_SVCH_TELEGRAM_OFFSET_HAS_INVALID_OFFSET ((TLR_RESULT)0xC0700011L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_AT_SVCH_TELEGRAM_OFFSET_CANNOT_BE_IN_MDT_TELEGRAM */
/*  */
/*  MessageText: */
/*  */
/*   AT ServiceChannel Telegram offset cannot be set to MDT telegram. */
/*  */
#define TLR_E_SIII_MA_CP_AT_SVCH_TELEGRAM_OFFSET_CANNOT_BE_IN_MDT_TELEGRAM ((TLR_RESULT)0xC0700012L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_AT_SVCH_TELEGRAM_OFFSET_HAS_INVALID_TELEGRAM_NO */
/*  */
/*  MessageText: */
/*  */
/*   AT ServiceChannel Telegram offset has invalid telegram number. */
/*  */
#define TLR_E_SIII_MA_CP_AT_SVCH_TELEGRAM_OFFSET_HAS_INVALID_TELEGRAM_NO ((TLR_RESULT)0xC0700013L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_AT_SVCH_TELEGRAM_OFFSET_HAS_INVALID_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   AT ServiceChannel Telegram offset has invalid offset in frame. */
/*  */
#define TLR_E_SIII_MA_CP_AT_SVCH_TELEGRAM_OFFSET_HAS_INVALID_OFFSET ((TLR_RESULT)0xC0700014L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_DEV_CTRL_TELEGRAM_OFFSET_CANNOT_BE_IN_AT_TELEGRAM */
/*  */
/*  MessageText: */
/*  */
/*   DeviceControl Telegram offset cannot be set to AT telegram. */
/*  */
#define TLR_E_SIII_MA_CP_DEV_CTRL_TELEGRAM_OFFSET_CANNOT_BE_IN_AT_TELEGRAM ((TLR_RESULT)0xC0700015L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_DEV_CTRL_TELEGRAM_OFFSET_HAS_INVALID_TELEGRAM_NO */
/*  */
/*  MessageText: */
/*  */
/*   DeviceControl Telegram offset has invalid telegram number. */
/*  */
#define TLR_E_SIII_MA_CP_DEV_CTRL_TELEGRAM_OFFSET_HAS_INVALID_TELEGRAM_NO ((TLR_RESULT)0xC0700016L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_DEV_CTRL_TELEGRAM_OFFSET_HAS_INVALID_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Device Control Telegram offset has invalid offset in frame. */
/*  */
#define TLR_E_SIII_MA_CP_DEV_CTRL_TELEGRAM_OFFSET_HAS_INVALID_OFFSET ((TLR_RESULT)0xC0700017L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_DEV_STATUS_TELEGRAM_OFFSET_CANNOT_BE_IN_MDT_TELEGRAM */
/*  */
/*  MessageText: */
/*  */
/*   DeviceControl Telegram offset cannot be set to MDT telegram. */
/*  */
#define TLR_E_SIII_MA_CP_DEV_STATUS_TELEGRAM_OFFSET_CANNOT_BE_IN_MDT_TELEGRAM ((TLR_RESULT)0xC0700018L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_DEV_STATUS_TELEGRAM_OFFSET_HAS_INVALID_TELEGRAM_NO */
/*  */
/*  MessageText: */
/*  */
/*   DeviceStatus Telegram offset has invalid telegram number. */
/*  */
#define TLR_E_SIII_MA_CP_DEV_STATUS_TELEGRAM_OFFSET_HAS_INVALID_TELEGRAM_NO ((TLR_RESULT)0xC0700019L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_DEV_STATUS_TELEGRAM_OFFSET_HAS_INVALID_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   DeviceStatus Telegram offset has invalid offset in frame. */
/*  */
#define TLR_E_SIII_MA_CP_DEV_STATUS_TELEGRAM_OFFSET_HAS_INVALID_OFFSET ((TLR_RESULT)0xC070001AL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_SLAVE_ALREADY_IN_CONFIGURATION */
/*  */
/*  MessageText: */
/*  */
/*   Slave already in configuration. */
/*  */
#define TLR_E_SIII_MA_CP_SLAVE_ALREADY_IN_CONFIGURATION ((TLR_RESULT)0xC070001BL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_SLAVE_NOT_IN_CONFIGURATION */
/*  */
/*  MessageText: */
/*  */
/*   Slave is not in configuration. */
/*  */
#define TLR_E_SIII_MA_CP_SLAVE_NOT_IN_CONFIGURATION ((TLR_RESULT)0xC070001CL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_INITCMD_SEGMENT_DOES_NOT_MATCH_FIRST_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   InitCmd segment does not match the first packet. */
/*  */
#define TLR_E_SIII_MA_CP_INITCMD_SEGMENT_DOES_NOT_MATCH_FIRST_PACKET ((TLR_RESULT)0xC070001DL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_TO_BE_IMPLEMENTED */
/*  */
/*  MessageText: */
/*  */
/*   Unimplemented function detected. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_TO_BE_IMPLEMENTED ((TLR_RESULT)0xC070001EL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_UNKNOWN_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Unknown error. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_UNKNOWN_ERROR ((TLR_RESULT)0xC070001FL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Out of memory. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_OUT_OF_MEMORY ((TLR_RESULT)0xC0700020L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_SERVICE_CHANNEL */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Service Channel number. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_SERVICE_CHANNEL ((TLR_RESULT)0xC0700021L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Slave address. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE ((TLR_RESULT)0xC0700022L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_PHASE_TRANSITION */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Phase transition. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_PHASE_TRANSITION ((TLR_RESULT)0xC0700023L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_NO_CONFIGURATION_DATA_FOR_CP3_4 */
/*  */
/*  MessageText: */
/*  */
/*   No Configuration data for CP3/CP4 available. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_NO_CONFIGURATION_DATA_FOR_CP3_4 ((TLR_RESULT)0xC0700024L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_MDT0_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid MDT0 length. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_MDT0_SIZE ((TLR_RESULT)0xC0700025L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_MDT1_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid MDT1 length. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_MDT1_SIZE ((TLR_RESULT)0xC0700026L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_MDT2_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid MDT2 length. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_MDT2_SIZE ((TLR_RESULT)0xC0700027L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_MDT3_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid MDT3 length. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_MDT3_SIZE ((TLR_RESULT)0xC0700028L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_AT0_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid AT0 length. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_AT0_SIZE ((TLR_RESULT)0xC0700029L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_AT1_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid AT1 length. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_AT1_SIZE ((TLR_RESULT)0xC070002AL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_AT2_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid AT2 length. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_AT2_SIZE ((TLR_RESULT)0xC070002BL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_AT3_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid AT3 length. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_AT3_SIZE ((TLR_RESULT)0xC070002CL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_CONTROL_OFFSET_TEL_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Device Control offset cannot be placed into AT telegram. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_CONTROL_OFFSET_TEL_TYPE ((TLR_RESULT)0xC070002DL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_CONTROL_OFFSET_TEL_NO */
/*  */
/*  MessageText: */
/*  */
/*   Telegram Number in Device Control offset is invalid. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_CONTROL_OFFSET_TEL_NO ((TLR_RESULT)0xC070002EL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_CONTROL_OFFSET_OFS_TOO_LOW */
/*  */
/*  MessageText: */
/*  */
/*   Frame Offset in Device Control offset is too low. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_CONTROL_OFFSET_OFS_TOO_LOW ((TLR_RESULT)0xC070002FL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_CONTROL_OFFSET_OFS_TOO_HIGH */
/*  */
/*  MessageText: */
/*  */
/*   Frame Offset in Device Control offset is too high. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_CONTROL_OFFSET_OFS_TOO_HIGH ((TLR_RESULT)0xC0700030L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_CONTROL_OFFSET_OFS_NOT_EVEN */
/*  */
/*  MessageText: */
/*  */
/*   Frame Offset in Device Control offset is not word-aligned (16bit word). */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_CONTROL_OFFSET_OFS_NOT_EVEN ((TLR_RESULT)0xC0700031L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_STATUS_OFFSET_TEL_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Device Status offset cannot be placed into MDT telegram. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_STATUS_OFFSET_TEL_TYPE ((TLR_RESULT)0xC0700032L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_STATUS_OFFSET_TEL_NO */
/*  */
/*  MessageText: */
/*  */
/*   Telegram Number in Device Status offset is invalid. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_STATUS_OFFSET_TEL_NO ((TLR_RESULT)0xC0700033L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_STATUS_OFFSET_OFS_TOO_LOW */
/*  */
/*  MessageText: */
/*  */
/*   Frame Offset in Device Status offset is too low. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_STATUS_OFFSET_OFS_TOO_LOW ((TLR_RESULT)0xC0700034L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_STATUS_OFFSET_OFS_TOO_HIGH */
/*  */
/*  MessageText: */
/*  */
/*   Frame Offset in Device Status offset is too high. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_STATUS_OFFSET_OFS_TOO_HIGH ((TLR_RESULT)0xC0700035L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_STATUS_OFFSET_OFS_NOT_EVEN */
/*  */
/*  MessageText: */
/*  */
/*   Frame Offset in Device Status offset is not word-aligned (16bit word). */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_DEVICE_STATUS_OFFSET_OFS_NOT_EVEN ((TLR_RESULT)0xC0700036L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_MDT_SVC_CHANNEL_OFFSET_TEL_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   MDT Service Channel offset cannot be placed into AT telegram. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_MDT_SVC_CHANNEL_OFFSET_TEL_TYPE ((TLR_RESULT)0xC0700037L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_MDT_SVC_CHANNEL_OFFSET_TEL_NO */
/*  */
/*  MessageText: */
/*  */
/*   Telegram Number in MDT Service Channel offset is invalid. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_MDT_SVC_CHANNEL_OFFSET_TEL_NO ((TLR_RESULT)0xC0700038L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_MDT_SVC_CHANNEL_OFFSET_OFS_TOO_LOW */
/*  */
/*  MessageText: */
/*  */
/*   Frame Offset in MDT Service Channel offset is too low. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_MDT_SVC_CHANNEL_OFFSET_OFS_TOO_LOW ((TLR_RESULT)0xC0700039L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_MDT_SVC_CHANNEL_OFFSET_OFS_TOO_HIGH */
/*  */
/*  MessageText: */
/*  */
/*   Frame Offset in MDT Service Channel offset is too high. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_MDT_SVC_CHANNEL_OFFSET_OFS_TOO_HIGH ((TLR_RESULT)0xC070003AL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_MDT_SVC_CHANNEL_OFFSET_OFS_NOT_EVEN */
/*  */
/*  MessageText: */
/*  */
/*   Frame Offset in MDT Service Channel offset is not word-aligned (16bit word). */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_MDT_SVC_CHANNEL_OFFSET_OFS_NOT_EVEN ((TLR_RESULT)0xC070003BL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_AT_SVC_CHANNEL_OFFSET_TEL_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   AT Service Channel offset cannot be placed into MDT telegram. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_AT_SVC_CHANNEL_OFFSET_TEL_TYPE ((TLR_RESULT)0xC070003CL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_AT_SVC_CHANNEL_OFFSET_TEL_NO */
/*  */
/*  MessageText: */
/*  */
/*   Telegram Number in AT Service Channel offset is invalid. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_AT_SVC_CHANNEL_OFFSET_TEL_NO ((TLR_RESULT)0xC070003DL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_AT_SVC_CHANNEL_OFFSET_OFS_TOO_LOW */
/*  */
/*  MessageText: */
/*  */
/*   Frame Offset in AT Service Channel offset is too low. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_AT_SVC_CHANNEL_OFFSET_OFS_TOO_LOW ((TLR_RESULT)0xC070003EL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_AT_SVC_CHANNEL_OFFSET_OFS_TOO_HIGH */
/*  */
/*  MessageText: */
/*  */
/*   Frame Offset in AT Service Channel offset is too high. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_AT_SVC_CHANNEL_OFFSET_OFS_TOO_HIGH ((TLR_RESULT)0xC070003FL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_AT_SVC_CHANNEL_OFFSET_OFS_NOT_EVEN */
/*  */
/*  MessageText: */
/*  */
/*   Frame Offset in AT Service Channel offset is not word-aligned (16bit word). */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_AT_SVC_CHANNEL_OFFSET_OFS_NOT_EVEN ((TLR_RESULT)0xC0700040L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_MDT_RTDATA_OFFSET_TEL_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   MDT Connection offset cannot be placed into AT telegram. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_MDT_RTDATA_OFFSET_TEL_TYPE ((TLR_RESULT)0xC0700041L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_MDT_RTDATA_OFFSET_TEL_NO */
/*  */
/*  MessageText: */
/*  */
/*   Telegram Number in MDT Connection offset is invalid. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_MDT_RTDATA_OFFSET_TEL_NO ((TLR_RESULT)0xC0700042L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_MDT_RTDATA_OFFSET_OFS_TOO_LOW */
/*  */
/*  MessageText: */
/*  */
/*   Frame Offset in MDT Connection offset is too low. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_MDT_RTDATA_OFFSET_OFS_TOO_LOW ((TLR_RESULT)0xC0700043L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_MDT_RTDATA_OFFSET_OFS_TOO_HIGH */
/*  */
/*  MessageText: */
/*  */
/*   Frame Offset in MDT Connection offset is too high. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_MDT_RTDATA_OFFSET_OFS_TOO_HIGH ((TLR_RESULT)0xC0700044L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_MDT_RTDATA_OFFSET_OFS_NOT_EVEN */
/*  */
/*  MessageText: */
/*  */
/*   Frame Offset in AT Connection offset is not word-aligned (16bit word). */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_MDT_RTDATA_OFFSET_OFS_NOT_EVEN ((TLR_RESULT)0xC0700045L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_AT_RTDATA_OFFSET_TEL_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   AT Connection offset cannot be placed into MDT telegram. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_AT_RTDATA_OFFSET_TEL_TYPE ((TLR_RESULT)0xC0700046L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_AT_RTDATA_OFFSET_TEL_NO */
/*  */
/*  MessageText: */
/*  */
/*   Telegram Number in AT Connection offset is invalid. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_AT_RTDATA_OFFSET_TEL_NO ((TLR_RESULT)0xC0700047L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_AT_RTDATA_OFFSET_OFS_TOO_LOW */
/*  */
/*  MessageText: */
/*  */
/*   Frame Offset in AT Connection offset is too low. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_AT_RTDATA_OFFSET_OFS_TOO_LOW ((TLR_RESULT)0xC0700048L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_AT_RTDATA_OFFSET_OFS_TOO_HIGH */
/*  */
/*  MessageText: */
/*  */
/*   Frame Offset in AT Connection offset is too high. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_AT_RTDATA_OFFSET_OFS_TOO_HIGH ((TLR_RESULT)0xC0700049L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_AT_RTDATA_OFFSET_OFS_NOT_EVEN */
/*  */
/*  MessageText: */
/*  */
/*   Frame Offset in MDT Connection offset is not word-aligned (16bit word). */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_AT_RTDATA_OFFSET_OFS_NOT_EVEN ((TLR_RESULT)0xC070004AL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_OVERLAPPING_REGIONS_DETECTED_IN_MDT_FRAMES */
/*  */
/*  MessageText: */
/*  */
/*   Overlapping regions detected within MDT frames. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_OVERLAPPING_REGIONS_DETECTED_IN_MDT_FRAMES ((TLR_RESULT)0xC070004BL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_OVERLAPPING_REGIONS_DETECTED_IN_AT_FRAMES */
/*  */
/*  MessageText: */
/*  */
/*   Overlapping regions detected within AT frames. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_OVERLAPPING_REGIONS_DETECTED_IN_AT_FRAMES ((TLR_RESULT)0xC070004CL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_SLAVE_ADDRESS_IN_CP3_4_CONFIG */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Slave address in CP3/CP4 configuration data. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_SLAVE_ADDRESS_IN_CP3_4_CONFIG ((TLR_RESULT)0xC070004DL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_CONFIGURE_NOT_ALLOWED_IN_CURRENT_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Configuring CP3/CP4 not allowed in current state. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_CONFIGURE_NOT_ALLOWED_IN_CURRENT_STATE ((TLR_RESULT)0xC070004EL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_BUILDING_COPY_ROUTINES_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Building of copy routines failed. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_BUILDING_COPY_ROUTINES_FAILED ((TLR_RESULT)0xC070004FL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_MDT_CONNCTRL_PROCESS_IMAGE_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Invalid MDT Connection Control Process Image offset. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_MDT_CONNCTRL_PROCESS_IMAGE_OFFSET ((TLR_RESULT)0xC0700050L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_MDT_RTDATA_PROCESS_IMAGE_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Invalid MDT real time data Process Image offset. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_MDT_RTDATA_PROCESS_IMAGE_OFFSET ((TLR_RESULT)0xC0700051L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_AT_CONNCTRL_PROCESS_IMAGE_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Invalid AT Connection Control Process Image offset. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_AT_CONNCTRL_PROCESS_IMAGE_OFFSET ((TLR_RESULT)0xC0700052L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LLD_INVALID_AT_RTDATA_PROCESS_IMAGE_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Invalid AT real time data Control Process Image offset. */
/*  */
#define TLR_E_SIII_MA_CP_LLD_INVALID_AT_RTDATA_PROCESS_IMAGE_OFFSET ((TLR_RESULT)0xC0700053L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_CONFIGURATION_NOT_POSSIBLE_IN_CURRENT_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Configuration not possible in current master state. */
/*  */
#define TLR_E_SIII_MA_CP_CONFIGURATION_NOT_POSSIBLE_IN_CURRENT_STATE ((TLR_RESULT)0xC0700054L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_PHASE_CHANGE_IN_PROGRESS */
/*  */
/*  MessageText: */
/*  */
/*   Phase Change is in progress. */
/*  */
#define TLR_E_SIII_MA_CP_PHASE_CHANGE_IN_PROGRESS ((TLR_RESULT)0xC0700055L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_REQUESTED_PHASE_IS_ALREADY_CURRENT_PHASE */
/*  */
/*  MessageText: */
/*  */
/*   Requested Phase is already current phase. */
/*  */
#define TLR_E_SIII_MA_CP_REQUESTED_PHASE_IS_ALREADY_CURRENT_PHASE ((TLR_RESULT)0xC0700056L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_FINISH_CONFIGURATION_DOWNLOAD_FIRST */
/*  */
/*  MessageText: */
/*  */
/*   Finish configuration download first. */
/*  */
#define TLR_E_SIII_MA_CP_FINISH_CONFIGURATION_DOWNLOAD_FIRST ((TLR_RESULT)0xC0700057L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_NO_CONFIGURATION_FOR_CP3_AVAILABLE */
/*  */
/*  MessageText: */
/*  */
/*   No configuration for CP3 available. */
/*  */
#define TLR_E_SIII_MA_CP_NO_CONFIGURATION_FOR_CP3_AVAILABLE ((TLR_RESULT)0xC0700058L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_NO_CONFIGURATION_FOR_CP4_AVAILABLE */
/*  */
/*  MessageText: */
/*  */
/*   No configuration for CP4 available. */
/*  */
#define TLR_E_SIII_MA_CP_NO_CONFIGURATION_FOR_CP4_AVAILABLE ((TLR_RESULT)0xC0700059L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_INCOMPLETE_INITCMD_DOWNLOAD */
/*  */
/*  MessageText: */
/*  */
/*   Incomplete InitCmd download detected. */
/*  */
#define TLR_E_SIII_MA_CP_INCOMPLETE_INITCMD_DOWNLOAD ((TLR_RESULT)0xC070005AL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_INVALID_TRANSITION_FLAGS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid transition flags specified in InitCmd download. */
/*  */
#define TLR_E_SIII_MA_CP_INVALID_TRANSITION_FLAGS ((TLR_RESULT)0xC070005BL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_INVALID_INITCMD_LENGTH */
/*  */
/*  MessageText: */
/*  */
/*   Invalid length specified in InitCmd download. */
/*  */
#define TLR_E_SIII_MA_CP_INVALID_INITCMD_LENGTH ((TLR_RESULT)0xC070005CL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_PHASE_INDS_RECEIVER_LIST_IS_FULL */
/*  */
/*  MessageText: */
/*  */
/*   Phase Indication receiver list is full. */
/*  */
#define TLR_E_SIII_MA_CP_PHASE_INDS_RECEIVER_LIST_IS_FULL ((TLR_RESULT)0xC070005DL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_APP_NOT_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   Application queue is not registered. */
/*  */
#define TLR_E_SIII_MA_CP_APP_NOT_REGISTERED ((TLR_RESULT)0xC070005EL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_APP_REGISTERED_ALREADY */
/*  */
/*  MessageText: */
/*  */
/*   Application queue is registered already. */
/*  */
#define TLR_E_SIII_MA_CP_APP_REGISTERED_ALREADY ((TLR_RESULT)0xC070005FL)

/*  */
/*  MessageId: TLR_I_SIII_MA_CP_BUS_IS_OFF */
/*  */
/*  MessageText: */
/*  */
/*   Please issue the BusOn command, since the bus is off. */
/*  */
#define TLR_I_SIII_MA_CP_BUS_IS_OFF      ((TLR_RESULT)0x40700060L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_NO_DIAG_ENTRY_AVAILABLE */
/*  */
/*  MessageText: */
/*  */
/*   No further diagnostic entries currently available. */
/*  */
#define TLR_E_SIII_MA_CP_NO_DIAG_ENTRY_AVAILABLE ((TLR_RESULT)0xC0700061L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LOCKED_DUE_TO_ERROR_IN_PREVIOUS_PHASE_SWITCH */
/*  */
/*  MessageText: */
/*  */
/*   Locked due to error in previous phase switch. */
/*  */
#define TLR_E_SIII_MA_CP_LOCKED_DUE_TO_ERROR_IN_PREVIOUS_PHASE_SWITCH ((TLR_RESULT)0xC0700062L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LOCKED_DUE_TO_DPM_WATCHDOG_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Locked due to error on DPM watchdog. */
/*  */
#define TLR_E_SIII_MA_CP_LOCKED_DUE_TO_DPM_WATCHDOG_ERROR ((TLR_RESULT)0xC0700063L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_BUS_SCAN_NOT_POSSIBLE_WITHOUT_BUS_ON */
/*  */
/*  MessageText: */
/*  */
/*   Bus Scan not possible without Bus On. */
/*  */
#define TLR_E_SIII_MA_CP_BUS_SCAN_NOT_POSSIBLE_WITHOUT_BUS_ON ((TLR_RESULT)0xC0700064L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_ELECTRONIC_LABEL_NOT_READABLE */
/*  */
/*  MessageText: */
/*  */
/*   Electronic Label could not be read. */
/*  */
#define TLR_E_SIII_MA_CP_ELECTRONIC_LABEL_NOT_READABLE ((TLR_RESULT)0xC0700065L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_BUS_SCAN_ALREADY_ACTIVE */
/*  */
/*  MessageText: */
/*  */
/*   Bus Scan already active. */
/*  */
#define TLR_E_SIII_MA_CP_BUS_SCAN_ALREADY_ACTIVE ((TLR_RESULT)0xC0700066L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_BUS_SCAN_ABORTED */
/*  */
/*  MessageText: */
/*  */
/*   Bus Scan aborted. */
/*  */
#define TLR_E_SIII_MA_CP_BUS_SCAN_ABORTED ((TLR_RESULT)0xC0700067L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_TIMING_PARAMETER_NRT_CHANNEL_EXCEEDS_CYCLE_TIME */
/*  */
/*  MessageText: */
/*  */
/*   NRT Channel exceeds cycle time. */
/*  */
#define TLR_E_SIII_MA_CP_TIMING_PARAMETER_NRT_CHANNEL_EXCEEDS_CYCLE_TIME ((TLR_RESULT)0xC0700068L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_TIMING_PARAMETER_END_OF_MDT_IS_LATER_THAN_START_OF_AT */
/*  */
/*  MessageText: */
/*  */
/*   End of MDT is later than start of AT. */
/*  */
#define TLR_E_SIII_MA_CP_TIMING_PARAMETER_END_OF_MDT_IS_LATER_THAN_START_OF_AT ((TLR_RESULT)0xC0700069L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_TIMING_PARAMETER_END_OF_MDT_EXCEEDS_CYCLE_TIME */
/*  */
/*  MessageText: */
/*  */
/*   End of MDT exceeds cycle time. */
/*  */
#define TLR_E_SIII_MA_CP_TIMING_PARAMETER_END_OF_MDT_EXCEEDS_CYCLE_TIME ((TLR_RESULT)0xC070006AL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_TIMING_PARAMETER_START_OF_AT_EXCEEDS_CYCLE_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Start of AT exceeds cycle time. */
/*  */
#define TLR_E_SIII_MA_CP_TIMING_PARAMETER_START_OF_AT_EXCEEDS_CYCLE_TIME ((TLR_RESULT)0xC070006BL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_TIMING_PARAMETER_END_OF_AT_EXCEEDS_CYCLE_TIME */
/*  */
/*  MessageText: */
/*  */
/*   End of AT exceeds cycle time. */
/*  */
#define TLR_E_SIII_MA_CP_TIMING_PARAMETER_END_OF_AT_EXCEEDS_CYCLE_TIME ((TLR_RESULT)0xC070006CL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_TIMING_PARAMETER_END_OF_NRT_IS_LATER_THAN_START_OF_NRT */
/*  */
/*  MessageText: */
/*  */
/*   End of NRT is later than start of NRT. */
/*  */
#define TLR_E_SIII_MA_CP_TIMING_PARAMETER_END_OF_NRT_IS_LATER_THAN_START_OF_NRT ((TLR_RESULT)0xC070006DL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_TIMING_PARAMETER_NRT_CHANNEL_OVERLAPS_MDT_TRANSMISSION */
/*  */
/*  MessageText: */
/*  */
/*   NRT Channel overlaps MDT transmission. */
/*  */
#define TLR_E_SIII_MA_CP_TIMING_PARAMETER_NRT_CHANNEL_OVERLAPS_MDT_TRANSMISSION ((TLR_RESULT)0xC070006EL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_TIMING_PARAMETER_NRT_CHANNEL_OVERLAPS_AT_TRANSMISSION */
/*  */
/*  MessageText: */
/*  */
/*   NRT Channel overlaps AT transmission. */
/*  */
#define TLR_E_SIII_MA_CP_TIMING_PARAMETER_NRT_CHANNEL_OVERLAPS_AT_TRANSMISSION ((TLR_RESULT)0xC070006FL)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_TIMING_PARAMETER_START_OF_AT_IS_EARLIER_THAN_START_OF_MDT */
/*  */
/*  MessageText: */
/*  */
/*   Start of AT is earlier than start of MDT. */
/*  */
#define TLR_E_SIII_MA_CP_TIMING_PARAMETER_START_OF_AT_IS_EARLIER_THAN_START_OF_MDT ((TLR_RESULT)0xC0700070L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_LOCKED_DUE_PREVIOUS_FATAL_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Locked due previous fatal error. */
/*  */
#define TLR_E_SIII_MA_CP_LOCKED_DUE_PREVIOUS_FATAL_ERROR ((TLR_RESULT)0xC0700071L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_TOPOLOGY_INFO_NOT_VALID_AT_THE_MOMENT */
/*  */
/*  MessageText: */
/*  */
/*   Topology info not valid at the moment. */
/*  */
#define TLR_E_SIII_MA_CP_TOPOLOGY_INFO_NOT_VALID_AT_THE_MOMENT ((TLR_RESULT)0xC0700072L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_AT_TRANSMISSION_START_TIME_EXCEEDS_CYCLE_TIME */
/*  */
/*  MessageText: */
/*  */
/*   AT Transmission start time exceeds cycle time. */
/*  */
#define TLR_E_SIII_MA_CP_AT_TRANSMISSION_START_TIME_EXCEEDS_CYCLE_TIME ((TLR_RESULT)0xC0700073L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_NRT_START_TIME_EXCEEDS_CYCLE_TIME */
/*  */
/*  MessageText: */
/*  */
/*   NRT start time exceeds cycle time. */
/*  */
#define TLR_E_SIII_MA_CP_NRT_START_TIME_EXCEEDS_CYCLE_TIME ((TLR_RESULT)0xC0700074L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_NRT_END_TIME_EXCEEDS_CYCLE_TIME */
/*  */
/*  MessageText: */
/*  */
/*   NRT End time exceeds cycle time. */
/*  */
#define TLR_E_SIII_MA_CP_NRT_END_TIME_EXCEEDS_CYCLE_TIME ((TLR_RESULT)0xC0700075L)

/*  */
/*  MessageId: TLR_E_SIII_MA_CP_NRT_START_TIME_IS_GREATER_THAN_NRT_END_TIME */
/*  */
/*  MessageText: */
/*  */
/*   NRT End time is greater than NRT start time. */
/*  */
#define TLR_E_SIII_MA_CP_NRT_START_TIME_IS_GREATER_THAN_NRT_END_TIME ((TLR_RESULT)0xC0700076L)




#endif  /* __SERCOSIII_MA_CP_ERROR_H */

#ifndef __SERCOSIII_MA_NRT_ERROR_H
#define __SERCOSIII_MA_NRT_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Sercos III - Result and Status Codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_SIII_MA_NRT_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup parameter. */
/*  */
#define TLR_E_SIII_MA_NRT_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0790001L)

/*  */
/*  MessageId: TLR_E_SIII_MA_NRT_S3FRAMES_NOT_ALLOWED */
/*  */
/*  MessageText: */
/*  */
/*   SERCOSIII frames not allowed. */
/*  */
#define TLR_E_SIII_MA_NRT_S3FRAMES_NOT_ALLOWED ((TLR_RESULT)0xC0790002L)

/*  */
/*  MessageId: TLR_E_SIII_MA_NRT_LLD_NOT_STARTED */
/*  */
/*  MessageText: */
/*  */
/*   SercosIII Low Level Driver not started. */
/*  */
#define TLR_E_SIII_MA_NRT_LLD_NOT_STARTED ((TLR_RESULT)0xC0790003L)




#endif  /* __SERCOSIII_MA_NRT_ERROR_H */

#ifndef __SERCOSIII_MA_SVC_ERROR_H
#define __SERCOSIII_MA_SVC_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Sercos III - Result and Status Codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command value. */
/*  */
#define TLR_E_SIII_MA_SVC_COMMAND_INVALID ((TLR_RESULT)0xC0710001L)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_SLAVE_HS_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Slave Service Channel Handshake timeout. */
/*  */
#define TLR_E_SIII_MA_SVC_SLAVE_HS_TIMEOUT ((TLR_RESULT)0xC0710002L)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_SLAVE_BUSY_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Slave Service Channel Busy timeout. */
/*  */
#define TLR_E_SIII_MA_SVC_SLAVE_BUSY_TIMEOUT ((TLR_RESULT)0xC0710003L)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_SLAVE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Slave Service Channel error. */
/*  */
#define TLR_E_SIII_MA_SVC_SLAVE_ERROR    ((TLR_RESULT)0xC0710004L)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_TRANSFER_ABORTED */
/*  */
/*  MessageText: */
/*  */
/*   Service Channel transfer aborted. */
/*  */
#define TLR_E_SIII_MA_SVC_TRANSFER_ABORTED ((TLR_RESULT)0xC0710005L)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_INTERN_LOCKED */
/*  */
/*  MessageText: */
/*  */
/*   Service Channels internally locked. */
/*  */
#define TLR_E_SIII_MA_SVC_INTERN_LOCKED  ((TLR_RESULT)0xC0710006L)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_MACRO_STEP_OPENIDN_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Service Channel Macro FSM: OpenIdn failed. */
/*  */
#define TLR_E_SIII_MA_SVC_MACRO_STEP_OPENIDN_FAILED ((TLR_RESULT)0xC0710010L)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_MACRO_STEP_READATTR_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Service Channel Macro FSM: ReadAttribute failed. */
/*  */
#define TLR_E_SIII_MA_SVC_MACRO_STEP_READATTR_FAILED ((TLR_RESULT)0xC0710011L)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_MACRO_STEP_GETLL_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Service Channel Macro FSM: Get ListLength failed. */
/*  */
#define TLR_E_SIII_MA_SVC_MACRO_STEP_GETLL_FAILED ((TLR_RESULT)0xC0710012L)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_MACRO_STEP_ACCESSDATA_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Service Channel Macro FSM: Data access failed. */
/*  */
#define TLR_E_SIII_MA_SVC_MACRO_STEP_ACCESSDATA_FAILED ((TLR_RESULT)0xC0710013L)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_INTERNAL_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Internal Error. */
/*  */
#define TLR_E_SIII_MA_SVC_INTERNAL_ERROR ((TLR_RESULT)0xC0710014L)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_SLAVE_VALID_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Service Channel valid timeout. */
/*  */
#define TLR_E_SIII_MA_SVC_SLAVE_VALID_TIMEOUT ((TLR_RESULT)0xC0710015L)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_INVALID_SENDER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Sender. */
/*  */
#define TLR_E_SIII_MA_SVC_INVALID_SENDER ((TLR_RESULT)0xC0710016L)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_ABORT_ALREADY_RUNNING */
/*  */
/*  MessageText: */
/*  */
/*   Abort Already Running. */
/*  */
#define TLR_E_SIII_MA_SVC_ABORT_ALREADY_RUNNING ((TLR_RESULT)0xC0710017L)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_INVALID_ELEMENT */
/*  */
/*  MessageText: */
/*  */
/*   The parameter element is wrong. */
/*  */
#define TLR_E_SIII_MA_SVC_INVALID_ELEMENT ((TLR_RESULT)0xC0710018L)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_INVALID_SLAVE_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   The parameter slave address is wrong. */
/*  */
#define TLR_E_SIII_MA_SVC_INVALID_SLAVE_ADDRESS ((TLR_RESULT)0xC0710019L)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_ATOMIC_TRANSFER_IN_USE */
/*  */
/*  MessageText: */
/*  */
/*   Atomic transfer in use. */
/*  */
#define TLR_E_SIII_MA_SVC_ATOMIC_TRANSFER_IN_USE ((TLR_RESULT)0xC071001AL)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_ABORT_NOT_POSSIBLE */
/*  */
/*  MessageText: */
/*  */
/*   Abort not possible. */
/*  */
#define TLR_E_SIII_MA_SVC_ABORT_NOT_POSSIBLE ((TLR_RESULT)0xC071001BL)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_DESTID_UNEXPECTED */
/*  */
/*  MessageText: */
/*  */
/*   Unexpected DestId in packet. */
/*  */
#define TLR_E_SIII_MA_SVC_DESTID_UNEXPECTED ((TLR_RESULT)0xC071001CL)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_SEQUENCE_UNEXPECTED */
/*  */
/*  MessageText: */
/*  */
/*   Unexpected sequence in packet. */
/*  */
#define TLR_E_SIII_MA_SVC_SEQUENCE_UNEXPECTED ((TLR_RESULT)0xC071001DL)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_CLOSED */
/*  */
/*  MessageText: */
/*  */
/*   Service Channel is closed. */
/*  */
#define TLR_E_SIII_MA_SVC_CLOSED         ((TLR_RESULT)0xC071001EL)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_PARAMETER_UNEXPECTED */
/*  */
/*  MessageText: */
/*  */
/*   SVC parameter is unexpected. */
/*  */
#define TLR_E_SIII_MA_SVC_PARAMETER_UNEXPECTED ((TLR_RESULT)0xC071001FL)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_INVALID_PRIORITY */
/*  */
/*  MessageText: */
/*  */
/*   Invalid priority. */
/*  */
#define TLR_E_SIII_MA_SVC_INVALID_PRIORITY ((TLR_RESULT)0xC0710020L)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_INVALID_ISLIST */
/*  */
/*  MessageText: */
/*  */
/*   IsList parameter is wrong. */
/*  */
#define TLR_E_SIII_MA_SVC_INVALID_ISLIST ((TLR_RESULT)0xC0710021L)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_MACRO_TRANSFER_IN_USE */
/*  */
/*  MessageText: */
/*  */
/*   A macro transfer is already started. */
/*  */
#define TLR_E_SIII_MA_SVC_MACRO_TRANSFER_IN_USE ((TLR_RESULT)0xC0710022L)

/*  */
/*  MessageId: TLR_E_SIII_MA_SVC_INVALID_CP */
/*  */
/*  MessageText: */
/*  */
/*   Access the Service Channel is currently not allowed (wrong CP). */
/*  */
#define TLR_E_SIII_MA_SVC_INVALID_CP     ((TLR_RESULT)0xC0710023L)




#endif  /* __SERCOSIII_MA_SVC_ERROR_H */

#ifndef __SERCOSIII_SVR_ERROR_H
#define __SERCOSIII_SVR_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Sercos III - Result and Status Codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_SERCOSIII_SVC_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid data in request detected. */
/*  */
#define TLR_E_SERCOSIII_SVC_COMMAND_INVALID ((TLR_RESULT)0xC0330001L)




#endif  /* __SERCOSIII_SVR_ERROR_H */

#ifndef __SERVX_ERROR_H
#define __SERVX_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  ServX ERROR codes */
/* /////////////////////////////////////////////////////////////////////////////////// */



#endif  /* __SERVX_ERROR_H */

#ifndef __SNMP_SERVER_ERROR_H
#define __SNMP_SERVER_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  SNMP Server Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_SNMP_SERVER_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_SNMP_SERVER_COMMAND_INVALID ((TLR_RESULT)0xC03B0001L)




#endif  /* __SNMP_SERVER_ERROR_H */

#ifndef __TCP_CONNECTOR_ERROR_H
#define __TCP_CONNECTOR_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Marshaller TCP Connector status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_TCP_CONNECTOR_MEM_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid memory address. (NULL pointer passing.) */
/*  */
#define TLR_E_TCP_CONNECTOR_MEM_ADDRESS  ((TLR_RESULT)0xC0860001L)

/*  */
/*  MessageId: TLR_E_TCP_CONNECTOR_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Out of memory. */
/*  */
#define TLR_E_TCP_CONNECTOR_MEMORY       ((TLR_RESULT)0xC0860002L)

/*  */
/*  MessageId: TLR_E_TCP_CONNECTOR_RESOURCE */
/*  */
/*  MessageText: */
/*  */
/*   Resource initialization problem. */
/*  */
#define TLR_E_TCP_CONNECTOR_RESOURCE     ((TLR_RESULT)0xC0860003L)

/*  */
/*  MessageId: TLR_E_TCP_CONNECTOR_PARAMETER_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter value. */
/*  */
#define TLR_E_TCP_CONNECTOR_PARAMETER_VALUE ((TLR_RESULT)0xC0860004L)

/*  */
/*  MessageId: TLR_E_TCP_CONNECTOR_STATE_MACHINE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid state. (Resetting state machine ...) */
/*  */
#define TLR_E_TCP_CONNECTOR_STATE_MACHINE ((TLR_RESULT)0xC0860005L)

/*  */
/*  MessageId: TLR_E_TCP_CONNECTOR_PROTOCOL_SUPPORT */
/*  */
/*  MessageText: */
/*  */
/*   TCP not supported by network protocol stack. */
/*  */
#define TLR_E_TCP_CONNECTOR_PROTOCOL_SUPPORT ((TLR_RESULT)0xC0860006L)

/*  */
/*  MessageId: TLR_E_TCP_CONNECTOR_ADDRESS_INFO */
/*  */
/*  MessageText: */
/*  */
/*   Invalid addressing information from network protocol stack. */
/*  */
#define TLR_E_TCP_CONNECTOR_ADDRESS_INFO ((TLR_RESULT)0xC0860007L)

/*  */
/*  MessageId: TLR_E_TCP_CONNECTOR_SERVICE_CNF */
/*  */
/*  MessageText: */
/*  */
/*   Error in service confirmation from network protocol stack. */
/*  */
#define TLR_E_TCP_CONNECTOR_SERVICE_CNF  ((TLR_RESULT)0xC0860008L)

/*  */
/*  MessageId: TLR_E_TCP_CONNECTOR_SEND */
/*  */
/*  MessageText: */
/*  */
/*   Error while sending request to the network protocol stack. */
/*  */
#define TLR_E_TCP_CONNECTOR_SEND         ((TLR_RESULT)0xC0860009L)

/*  */
/*  MessageId: TLR_E_TCP_CONNECTOR_MAX_RETRIES */
/*  */
/*  MessageText: */
/*  */
/*   Maximum number of service retries exceeded. */
/*  */
#define TLR_E_TCP_CONNECTOR_MAX_RETRIES  ((TLR_RESULT)0xC086000AL)




#endif  /* __TCP_CONNECTOR_ERROR_H */

#ifndef __TCPIP_SOCKIF_ERROR_H
#define __TCPIP_SOCKIF_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  TCP/IP Socket Interface Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_TCPIP_SOCKIF_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_TCPIP_SOCKIF_COMMAND_INVALID ((TLR_RESULT)0xC0740001L)

/*  */
/*  MessageId: TLR_E_TCPIP_SOCKIF_TCP_UDP_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to identify the TCP_UDP task. */
/*  */
#define TLR_E_TCPIP_SOCKIF_TCP_UDP_IDENTIFY_FAILED ((TLR_RESULT)0xC0740002L)

/*  */
/*  MessageId: TLR_E_TCPIP_SOCKIF_TCP_UDP_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The queue identification of TCP_UDP task queue has failed. */
/*  */
#define TLR_E_TCPIP_SOCKIF_TCP_UDP_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC0740003L)

/*  */
/*  MessageId: TLR_E_TCPIP_SOCKIF_SEMAPHORE_CREATION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The semaphore creation has failed. */
/*  */
#define TLR_E_TCPIP_SOCKIF_SEMAPHORE_CREATION_FAILED ((TLR_RESULT)0xC0740004L)




#endif  /* __TCPIP_SOCKIF_ERROR_H */

#ifndef __TCPIP_TCP_AP_ERROR_H
#define __TCPIP_TCP_AP_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  TCPIP TCP Application Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_TCPIP_TCP_AP_SOCKET_NOT_CONNECTED */
/*  */
/*  MessageText: */
/*  */
/*   Socket not connected. */
/*  */
#define TLR_E_TCPIP_TCP_AP_SOCKET_NOT_CONNECTED ((TLR_RESULT)0xC0940001L)




#endif  /* __TCPIP_TCP_AP_ERROR_H */

#ifndef __TCPIP_ERROR_H
#define __TCPIP_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  IP Packet Status codes (TCP_UDP task) */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Initialization Error Codes */
/* MessageId       = 50 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_INIT_NO_TCP_TASK */
/* Language        = English */
/* TCP/UDP task not available. */
/* . */
/* Language        = German */
/* TCP/UDP Task nicht vorhanden. */
/* . */
/* MessageId       = 51 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_INIT_TASK_CONFIG */
/* Language        = English */
/* Internal task configuration data not available. */
/* . */
/* Language        = German */
/* Interne Task Konfigurationsdaten nicht verf�gbar. */
/* . */
/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_NO_ETHERNET_ADDR */
/*  */
/*  MessageText: */
/*  */
/*   There is no Ethernet address (MAC address) available. */
/*  */
#define TLR_E_IP_ERR_INIT_NO_ETHERNET_ADDR ((TLR_RESULT)0xC0070034L)

/* MessageId       = 53 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_INIT_WAIT_FOR_WARMSTART */
/* Language        = English */
/* Waiting for warm-start by application program. */
/* . */
/* Language        = German */
/* Warte auf einen Warmstart der Applikation. */
/* . */
/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_INVALID_FLAG */
/*  */
/*  MessageText: */
/*  */
/*   The start parameters contains one or more unknown flags. */
/*  */
#define TLR_E_IP_ERR_INIT_INVALID_FLAG   ((TLR_RESULT)0xC0070036L)

/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_INVALID_IP_ADDR */
/*  */
/*  MessageText: */
/*  */
/*   The start parameters contains an invalid IP address. */
/*  */
#define TLR_E_IP_ERR_INIT_INVALID_IP_ADDR ((TLR_RESULT)0xC0070037L)

/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_INVALID_NETMASK */
/*  */
/*  MessageText: */
/*  */
/*   The start parameters contains an invalid subnet mask. */
/*  */
#define TLR_E_IP_ERR_INIT_INVALID_NETMASK ((TLR_RESULT)0xC0070038L)

/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_INVALID_GATEWAY */
/*  */
/*  MessageText: */
/*  */
/*   The start parameters contains an invalid gateway IP address. */
/*  */
#define TLR_E_IP_ERR_INIT_INVALID_GATEWAY ((TLR_RESULT)0xC0070039L)

/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_UNKNOWN_HARDWARE */
/*  */
/*  MessageText: */
/*  */
/*   The device type is unknown. */
/*  */
#define TLR_E_IP_ERR_INIT_UNKNOWN_HARDWARE ((TLR_RESULT)0xC007003BL)

/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_NO_IP_ADDR */
/*  */
/*  MessageText: */
/*  */
/*   Failed to obtain an IP address from the specified source(s). */
/*  */
#define TLR_E_IP_ERR_INIT_NO_IP_ADDR     ((TLR_RESULT)0xC007003CL)

/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_DRIVER_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The initialisation of the driver layer (EDD) is failed. */
/*  */
#define TLR_E_IP_ERR_INIT_DRIVER_FAILED  ((TLR_RESULT)0xC007003DL)

/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_NO_IP_ADDR_CFG */
/*  */
/*  MessageText: */
/*  */
/*   There is no source for an IP address (BOOTP, DHCP, IP address parameter) specified. */
/*  */
#define TLR_E_IP_ERR_INIT_NO_IP_ADDR_CFG ((TLR_RESULT)0xC007003EL)

/* MessageId       = 63 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_INIT_INVALID_SERIAL_NUMBER */
/* Language        = English */
/* Invalid serial number. */
/* . */
/* Language        = German */
/* Ung�ltige Seriennummer. */
/* . */
/* MessageId       = 64 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_INIT_MEM_NOT_ON_CHIP */
/* Language        = English */
/* . */
/* . */
/* Language        = German */
/* . */
/* . */
/* MessageId       = 65 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_INIT_NO_MEM */
/* Language        = English */
/* . */
/* . */
/* Language        = German */
/* . */
/* . */
/* MessageId       = 66 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_INIT_CREATE_MBX */
/* Language        = English */
/* Failed to create the IP mailbox. */
/* . */
/* Language        = German */
/* Das Erzeugen der IP Mailbox ist fehlgeschlagen. */
/* . */
/* MessageId       = 67 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_INIT_CREATE_INFO_FIELD */
/* Language        = English */
/* Failed to create a task information field (task state). */
/* . */
/* Language        = German */
/* Das Erzeugen eines Task Informationsfeldes (Taskstatus) ist fehlgeschlagen. */
/* . */
/* MessageId       = 68 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_INIT_IDENTIFY_MBX */
/* Language        = English */
/* Failed to identify the mailbox of TCP task. */
/* . */
/* Language        = German */
/* Das Identifizieren der Mailbox der TCP Task ist fehlgeschlagen. */
/* . */
/*  Run-time Error Codes */
/*  */
/*  MessageId: TLR_E_IP_ERR_ETH_ADDR_INVALID_IP_CMD_SET_PARAM */
/*  */
/*  MessageText: */
/*  */
/*   The Ethernet address (MAC address) abEthernetAddr in command TCPIP_IP_CMD_SET_PARAM_REQ is invalid. */
/*   Invalid means, abEthernetAddr is equal to the broadcast address FF-FF-FF-FF-FF-FF. */
/*  */
#define TLR_E_IP_ERR_ETH_ADDR_INVALID_IP_CMD_SET_PARAM ((TLR_RESULT)0xC007007CL)

/* MessageId       = 130 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_MODE_UNKNOWN */
/* Language        = English */
/* The mode parameter is invalid. */
/* . */
/* Language        = German */
/* Der Mode Parameter ist ung�ltig. */
/* . */
/*  */
/*  MessageId: TLR_E_IP_ERR_ARP_CACHE_FULL_IP_CMD_SET_PARAM */
/*  */
/*  MessageText: */
/*  */
/*   The command TCPIP_IP_CMD_SET_PARAM_REQ could not be executed, because the ARP cache is full. */
/*   The ARP cache has per default configuration 64 entries. */
/*  */
#define TLR_E_IP_ERR_ARP_CACHE_FULL_IP_CMD_SET_PARAM ((TLR_RESULT)0xC0070083L)

/*  */
/*  MessageId: TLR_E_IP_ERR_ARP_ENTRY_NOT_FOUND_IP_CMD_SET_PARAM */
/*  */
/*  MessageText: */
/*  */
/*   The specified ARP entry in command TCPIP_IP_CMD_SET_PARAM_REQ could not be deleted. */
/*   The ARP entry was not found in ARP cache. */
/*  */
#define TLR_E_IP_ERR_ARP_ENTRY_NOT_FOUND_IP_CMD_SET_PARAM ((TLR_RESULT)0xC0070086L)

/*  */
/*  MessageId: TLR_E_IP_ERR_ARP_ENTRY_NOT_FOUND_IP_CMD_GET_PARAM */
/*  */
/*  MessageText: */
/*  */
/*   The requested ARP information in command TCPIP_IP_CMD_GET_PARAM_REQ could not be delivered. */
/*   The ARP entry was not found in ARP cache. */
/*  */
#define TLR_E_IP_ERR_ARP_ENTRY_NOT_FOUND_IP_CMD_GET_PARAM ((TLR_RESULT)0xC0070087L)

/* MessageId       = 149 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_UNEXP_ANSWER */
/* Language        = English */
/* Unexpected answer message received. */
/* . */
/* Language        = German */
/* Unerwartete Anwortmessage empfangen. */
/* . */
/*  Special Error Codes from file TcpipIpbase.h */
/*  */
/*  MessageId: TLR_E_IP_ERR_DELAYED */
/*  */
/*  MessageText: */
/*  */
/*   Special internal error code returned by IpStart function. */
/*  */
#define TLR_E_IP_ERR_DELAYED             ((TLR_RESULT)0xC00700FEL)

/*  */
/*  MessageId: TLR_E_IP_ERR_GENERIC */
/*  */
/*  MessageText: */
/*  */
/*   Special internal error code returned by IpStart function. */
/*  */
#define TLR_E_IP_ERR_GENERIC             ((TLR_RESULT)0xC00700FFL)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  TCP_UDP task Packet Status codes */
/*  */
/*  Added here also the "TCP_UDP Diagnostic Status codes" from file tcpip_diag.mc - */
/*  there are no conflicts (except the MessageId 0x0001 and 0x0002 because of old and */
/*  comment out errors/diag codes, see below) - so the error numbers are unchanged. */
/*  But some codes are also comment out, because the corresponding error code exists! */
/*  Renamed from TLR_DIAG_E_xx to TLR_E_xx */
/* /////////////////////////////////////////////////////////////////////////////////// */
/* MessageId       = 0x0001 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCPIP_TCP_TASK_COMMAND_INVALID --> TLR_E_UNKNOWN_COMMAND */
/* Language        = English */
/* Invalid command received. */
/* . */
/* Language        = German */
/* Ung�ltiges Kommando erhalten. */
/* . */
/* MessageId       = 0x0001 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_DIAG_E_TCP_ERR_TASK_PROCESS_TERMINATED */
/* Language        = English */
/* The task process was terminated with error - see task status. */
/* . */
/* Language        = German */
/* Die Task wurde beendet - siehe Taskstatus. */
/* . */
/* MessageId       = 0x0002 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCPIP_TCP_TASK_PROCESS_CANCELED */
/* Language        = English */
/* Cancel process is in progress, command can not be executed. */
/* . */
/* Language        = German */
/* Task wird gerade beendet, das Kommando kann nicht ausgef�hrt werden. */
/* . */
/* MessageId       = 0x0002 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_DIAG_E_TCP_ERR_INIT_RESET_CYCLE */
/* Language        = English */
/* Failed to reset the cyclic event. */
/* . */
/* Language        = German */
/* Das Reseten des zyklischen Events ist fehlgeschlagen. */
/* . */
/*  */
/*  MessageId: TLR_E_TCP_ERR_CODEDIAG_FATAL */
/*  */
/*  MessageText: */
/*  */
/*   A fatal error is occured. Terminate the task. */
/*  */
#define TLR_E_TCP_ERR_CODEDIAG_FATAL     ((TLR_RESULT)0xC0080003L)

/* MessageId       = 0x0004 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_TASK_F_NOT_INITIALIZED */
/* Language        = English */
/* Task is not initialized. */
/* . */
/* Language        = German */
/* Die Task ist nicht initialisiert. */
/* . */
/*  */
/*  MessageId: TLR_E_TCP_TASK_F_INITIALIZATION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize the task. */
/*   Accept Init packets and Config packets only. */
/*  */
#define TLR_E_TCP_TASK_F_INITIALIZATION_FAILED ((TLR_RESULT)0xC0080005L)

/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_INVALID_SERIAL_NUMBER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid serial number. */
/*  */
#define TLR_E_IP_ERR_INIT_INVALID_SERIAL_NUMBER ((TLR_RESULT)0xC0080006L)

/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_IP_INIT_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize the IP layer - see task status. */
/*  */
#define TLR_E_IP_ERR_INIT_IP_INIT_ERROR  ((TLR_RESULT)0xC0080007L)

/* MessageId       = 0x0008 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_INIT_OS_CYCLETIME */
/* Language        = English */
/* The configured operating system cycletime is out of range (0.1 ms ... 20 ms). */
/* . */
/* Language        = German */
/* Die konfigurierte Zykluszeit des Betriebssystems liegt ausserhalb der zul�ssigen Grenzen (0,1 ms ... 20 ms). */
/* . */
/*  */
/*  MessageId: TLR_E_TCPIP_TCP_TASK_PROCESS_CANCELED */
/*  */
/*  MessageText: */
/*  */
/*   Cancel process is in progress, command can not be executed. */
/*  */
#define TLR_E_TCPIP_TCP_TASK_PROCESS_CANCELED ((TLR_RESULT)0xC0080009L)

/*  */
/*  MessageId: TLR_E_TCPIP_EDD_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to identify the EDD (Ethernet Device Driver). */
/*  */
#define TLR_E_TCPIP_EDD_IDENTIFY_FAILED  ((TLR_RESULT)0xC008000AL)

/*  */
/*  MessageId: TLR_E_TCPIP_APPLICATION_TIMER_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to create an application timer (Timer task). */
/*  */
#define TLR_E_TCPIP_APPLICATION_TIMER_CREATE_FAILED ((TLR_RESULT)0xC008000BL)

/*  */
/*  MessageId: TLR_E_TCPIP_APPLICATION_TIMER_INIT_PACKET_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize a packet of application timer (Timer task). */
/*  */
#define TLR_E_TCPIP_APPLICATION_TIMER_INIT_PACKET_FAILED ((TLR_RESULT)0xC008000CL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_SOCKET_MAX_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulSocketMaxCnt. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_SOCKET_MAX_CNT ((TLR_RESULT)0xC008000DL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_POOL_ELEM_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulPoolElemCnt. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_POOL_ELEM_CNT ((TLR_RESULT)0xC008000EL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EDD_OUT_BUF_MAX_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulEddOutBufMaxCnt. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EDD_OUT_BUF_MAX_CNT ((TLR_RESULT)0xC008000FL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_ARP_CACHE_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulArpCacheSize. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_ARP_CACHE_SIZE ((TLR_RESULT)0xC0080010L)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_QUE_FREE_ELEM_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulQueFreeElemCnt. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_QUE_FREE_ELEM_CNT ((TLR_RESULT)0xC0080011L)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_TCP_CYCLE_EVENT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulTcpCycleEvent. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_TCP_CYCLE_EVENT ((TLR_RESULT)0xC0080012L)

/* MessageId       = 0x0013 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_INIT_OS_AND_TCPUDP_CYCLETIME */
/* Language        = English */
/* The combination of configured operating system cycletime and TCP/IP stacks cycletime (startup-parameter */
/* ulTcpCycleEvent) is not possible. The operating system cycletime must be smaller or equal than the */
/* TCP/IP stacks cycletime. */
/* . */
/* Language        = German */
/* Die Kombination aus konfigurierter Zykluszeit des Betriebssystems und der Zykluszeit des TCP/IP Stacks */
/* (Startparameter ulTcpCycleEvent) ist nicht m�glich. Die konfigurierter Zykluszeit des Betriebssystems */
/* muss kleiner oder gleich der Zykluszeit des TCP/IP Stacks sein. */
/* . */
/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_QUE_ELEM_CNT_AP */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulQueElemCnt. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_QUE_ELEM_CNT_AP ((TLR_RESULT)0xC0080014L)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EDD_QUE_POOL_ELEM_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulEddQuePoolElemCnt. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EDD_QUE_POOL_ELEM_CNT ((TLR_RESULT)0xC0080015L)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_START_FLAGS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulStartFlags. Unknown flags are set. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_START_FLAGS ((TLR_RESULT)0xC0080016L)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EDD_NAME */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter pszEddName. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EDD_NAME ((TLR_RESULT)0xC0080017L)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_EDD_NAME */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIF pszEddName. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_EDD_NAME ((TLR_RESULT)0xC0080018L)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_EDD_INSTANCE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIF ulEddInstance. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_EDD_INSTANCE ((TLR_RESULT)0xC0080019L)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_ETH_INTF_NAME */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIF pszEifEthIntfName. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_ETH_INTF_NAME ((TLR_RESULT)0xC008001AL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIF ulEifMode. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_MODE ((TLR_RESULT)0xC008001BL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_PORT_RANGE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIFs ulEifPortStart, ulEifPortEnd. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_PORT_RANGE ((TLR_RESULT)0xC008001CL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_PORT_NMB */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIF ulEifPortNmb. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_PORT_NMB ((TLR_RESULT)0xC008001DL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_ARP_TIMEOUT_CACHE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulArpTimeoutCache. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_ARP_TIMEOUT_CACHE ((TLR_RESULT)0xC008001EL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_FLAGS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIF ulEifFlags. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_FLAGS ((TLR_RESULT)0xC008001FL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_HW_NAME_NETX */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter pszHwNameNetX. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_HW_NAME_NETX ((TLR_RESULT)0xC0080020L)

/*  Initialization Error Codes */
/*  */
/*  MessageId: TLR_E_TCP_ERR_INIT_IP_TASK_NOT_READY */
/*  */
/*  MessageText: */
/*  */
/*   The IP layer is not ready. */
/*  */
#define TLR_E_TCP_ERR_INIT_IP_TASK_NOT_READY ((TLR_RESULT)0xC0080032L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_INIT_IP_TASK_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The initialization of IP layer has failed. */
/*  */
#define TLR_E_TCP_ERR_INIT_IP_TASK_FAILED ((TLR_RESULT)0xC0080034L)

/* MessageId       = 61 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_INIT_CREATE_CYCLE */
/* Language        = English */
/* Failed to create the cyclic event. */
/* . */
/* Language        = German */
/* Das Erzeugen des zyklischen Events ist fehlgeschlagen. */
/* . */
/* MessageId       = 62 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_INIT_RESET_CYCLE */
/* Language        = English */
/* Failed to reset the cyclic event. */
/* . */
/* Language        = German */
/* Das Reseten des zyklischen Events ist fehlgeschlagen. */
/* . */
/* MessageId       = 63 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_INIT_CREATE_MULTIPLE */
/* Language        = English */
/* Failed to create the multiple object. */
/* . */
/* Language        = German */
/* Das Erzeugen des Multiple Objekt ist fehlgeschlagen. */
/* . */
/* MessageId       = 64 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_INIT_CREATE_INFO_FIELD */
/* Language        = English */
/* The creation of an information field (task state) has failed. */
/* . */
/* Language        = German */
/* Das Erzeugen eines Informationsfeldes (Taskstatus) ist fehlgeschlagen. */
/* . */
/*  */
/*  MessageId: TLR_W_TCP_ERR_INIT_TPIF_INIT_REQ_PCKT */
/*  */
/*  MessageText: */
/*  */
/*   Warning: A pending application packet has discarded (because of a new application packet). */
/*  */
#define TLR_W_TCP_ERR_INIT_TPIF_INIT_REQ_PCKT ((TLR_RESULT)0x80080043L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_INIT_OS_CYCLETIME */
/*  */
/*  MessageText: */
/*  */
/*   The configured operating system cycletime is out of range (0.1 ms ... 20 ms). */
/*  */
#define TLR_E_TCP_ERR_INIT_OS_CYCLETIME  ((TLR_RESULT)0xC0080044L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_INIT_OS_AND_TCPUDP_CYCLETIME */
/*  */
/*  MessageText: */
/*  */
/*   The combination of configured operating system cycletime and TCP/IP stacks cycletime (startup-parameter */
/*   ulTcpCycleEvent) is not possible. The operating system cycletime must be smaller or equal than the */
/*   TCP/IP stacks cycletime. */
/*  */
#define TLR_E_TCP_ERR_INIT_OS_AND_TCPUDP_CYCLETIME ((TLR_RESULT)0xC0080045L)

/*  Run-time Error Codes */
/* MessageId       = 111 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_TIMEOUT_INVALID */
/* Language        = English */
/* The timeout parameter is invalid. */
/* . */
/* Language        = German */
/* Der Timeout Parameter ist ung�ltig. */
/* . */
/*  */
/*  MessageId: TLR_E_TCP_ERR_SOCKET_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The socket handle ulDestId is invalid. */
/*   A further reason for this error: The command (Mode) is not applicable on this socket type (TCP/UDP). */
/*  */
#define TLR_E_TCP_ERR_SOCKET_INVALID     ((TLR_RESULT)0xC0080070L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_OPTION_NOT_SUPPORTED_TCP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The option parameter ulOptions in command TCPIP_TCP_CMD_SEND_REQ is invalid. */
/*  */
#define TLR_E_TCP_ERR_OPTION_NOT_SUPPORTED_TCP_CMD_SEND ((TLR_RESULT)0xC0080074L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_PARAMETER_INVALID_TCP_UDP_CMD_SET_SOCK_OPTION */
/*  */
/*  MessageText: */
/*  */
/*   The parameter in command TCPIP_TCP_UDP_CMD_SET_SOCK_OPTION_REQ is invalid. */
/*  */
#define TLR_E_TCP_ERR_PARAMETER_INVALID_TCP_UDP_CMD_SET_SOCK_OPTION ((TLR_RESULT)0xC0080075L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_CONN_CLOSED */
/*  */
/*  MessageText: */
/*  */
/*   The connection has closed (Graceful close). */
/*  */
#define TLR_E_TCP_ERR_CONN_CLOSED        ((TLR_RESULT)0xC0080078L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_CONN_RESET */
/*  */
/*  MessageText: */
/*  */
/*   The Connection has closed by reset (Hard close). */
/*  */
#define TLR_E_TCP_ERR_CONN_RESET         ((TLR_RESULT)0xC0080079L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_PROTOCOL_UNKNOWN_TCP_UDP_CMD_OPEN */
/*  */
/*  MessageText: */
/*  */
/*   The protocol parameter ulProtocol in command TCPIP_TCP_UDP_CMD_OPEN_REQ is invalid. */
/*  */
#define TLR_E_TCP_ERR_PROTOCOL_UNKNOWN_TCP_UDP_CMD_OPEN ((TLR_RESULT)0xC008007AL)

/*  */
/*  MessageId: TLR_E_TCP_ERR_NO_SOCKETS_TCP_UDP_CMD_OPEN */
/*  */
/*  MessageText: */
/*  */
/*   Command TCPIP_TCP_UDP_CMD_OPEN_REQ: There are no socket handles available. */
/*  */
#define TLR_E_TCP_ERR_NO_SOCKETS_TCP_UDP_CMD_OPEN ((TLR_RESULT)0xC008007BL)

/* MessageId       = 130 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_MODE_UNKNOWN */
/* Language        = English */
/* The mode parameter in command is invalid. */
/* . */
/* Language        = German */
/* Das Kommando enth�lt einen ung�ltigen Mode Parameter. */
/* . */
/* MessageId       = 131 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_MAX_DATA_LEN_EXCEEDED */
/* Language        = English */
/* The maximum data length has exceeded. */
/* . */
/* Language        = German */
/* Die maximale Datenl�nge wurde �berschritten. */
/* . */
/* MessageId       = 132 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_MAX_PCKT_CNT_EXCEEDED_UDP_CMD_SEND */
/* Language        = English */
/* Command TCPIP_UDP_CMD_SEND_REQ: The maximum number of queued packets ( = TCPHDL_RCX_PCKT_QUEUED_MAX (6) ) */
/* has exceeded. The request command was rejected. The application must wait for at least one confirmation */
/* command from stack before sending the next request command. */
/* . */
/* Language        = German */
/* Kommando TCPIP_UDP_CMD_SEND_REQ: Die maximale Anzahl gequeueter Pakete ( = TCPHDL_RCX_PCKT_QUEUED_MAX (6) ) */
/* wurde �berschritten. Das Request Command wurde abgelehnt. Die Applikation muss mindestens auf ein */
/* Confirmation Command vom Stack warten, bevor das n�chste Request Command gesendet werden kann. */
/* . */
/*  */
/*  MessageId: TLR_E_TCP_ERR_MAX_GROUP_EXCEEDED_TCP_UDP_CMD_SET_SOCK_OPTION */
/*  */
/*  MessageText: */
/*  */
/*   Command TCPIP_TCP_UDP_CMD_SET_SOCK_OPTION_REQ, ulMode = TCP_SOCK_ADD_MEMBERSHIP: The maximum number of */
/*   IP multicast groups has exceeded (Default configuration = 64). */
/*  */
#define TLR_E_TCP_ERR_MAX_GROUP_EXCEEDED_TCP_UDP_CMD_SET_SOCK_OPTION ((TLR_RESULT)0xC0080085L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_DISCARD_KEPT_REQ_CMD */
/*  */
/*  MessageText: */
/*  */
/*   A kept request command has discarded. This confirmation has no further meaning for the application, unless */
/*   the application must give back this packet to their resource pool! */
/*  */
#define TLR_E_TCP_ERR_DISCARD_KEPT_REQ_CMD ((TLR_RESULT)0xC0080086L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_UNEXP_ANSWER */
/*  */
/*  MessageText: */
/*  */
/*   An unexpected/unknown confirmation command has received. */
/*  */
#define TLR_E_TCP_ERR_UNEXP_ANSWER       ((TLR_RESULT)0xC0080095L)

/* MessageId       = 151 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_TASK_F_MESSAGESIZE --> TLR_E_INVALID_PACKET_LEN */
/* Language        = English */
/* The packet length parameter ulLen is invalid. The correct packet lenght depends on the command parameter ulCmd. */
/* . */
/* Language        = German */
/* Die Paketl�nge (Parameter ulLen) ist ung�ltig. Die korrekte Paketl�nge h�ngt vom Kommando Parameter ulCmd ab. */
/* . */
/* MessageId       = 152 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_TASK_F_MESSAGECOMMAND --> TLR_E_UNKNOWN_COMMAND */
/* Language        = English */
/* The command ulCmd is unknown. */
/* . */
/* Language        = German */
/* Das Kommando ulCmd ist unbekannt. */
/* . */
/* MessageId       = 156 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_TASK_F_MESSAGESEQUENCE */
/* Language        = English */
/* Sequence error during segmented message transfer. */
/* . */
/* Language        = German */
/* Es ist ein Sequenzfehler w�hrend einem segmentierten Messagetransfer aufgetreten. */
/* . */
/* MessageId       = 158 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_TASK_F_MESSAGECOMMANDRUNNING */
/* Language        = English */
/* The command cannot be executed, because the previous command is still running. */
/* . */
/* Language        = German */
/* Das Kommando kann nicht ausgef�hrt werden, weil das vorhergehende Kommando noch l�uft. */
/* . */
/*  */
/*  MessageId: TLR_E_TCP_TASK_F_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   The task is not initialized. */
/*  */
#define TLR_E_TCP_TASK_F_NOT_INITIALIZED ((TLR_RESULT)0xC00800C8L)

/*  */
/*  MessageId: TLR_E_TCP_TASK_F_BUSY */
/*  */
/*  MessageText: */
/*  */
/*   The task is busy (intern). */
/*  */
#define TLR_E_TCP_TASK_F_BUSY            ((TLR_RESULT)0xC00800C9L)

/* MessageId       = 210 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_TASK_F_DATABASE --> TLR_E_DATABASE_ACCESS_FAILED */
/* Language        = English */
/* The configuration database is not available. */
/* . */
/* Language        = German */
/* Die Parameterdatenbank ist nicht vorhanden. */
/* . */
/*  System Error Codes */
/* MessageId       = 212 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_TASK_F_DATABASE_READ --> TLR_E_DATABASE_ACCESS_FAILED */
/* Language        = English */
/* Error while reading configuration database. */
/* . */
/* Language        = German */
/* Beim Lesen der Parameterdatenbank ist ein Fehler aufgetreten. */
/* . */
/* MessageId       = 213 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_TASK_F_STRUCTURE */
/* Language        = English */
/* Error while registering diagnostics structure. */
/* . */
/* Language        = German */
/* Beim Registrieren einer Diagnosestruktur ist ein Fehler aufgetreten. */
/* . */
/* //////// New rcX error codes, starting with a value bigger than the RCS error codes = 255  ////////// */
/* //////// for IP and TCP_UDP error codes!                                                   ////////// */
/* //////// The order of this errors is:                                                      ////////// */
/* ////////   - Parameter errors from application: 0x0100 ... 0x01FF                          ////////// */
/* ////////   - Local source of errors (stack)   : 0x0200 ... 0x02FF                          ////////// */
/* ////////   - Remote source of errors          : 0x0300 ... 0x03FF                          ////////// */
/* ////////   - Parameter errors from application: 0x0100 ... 0x01FF                          ////////// */
/* /// IP address invalid errors 0x0100 ... 0x010F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_IP_ERR_IP_ADDR_INVALID_IP_CMD_PING */
/*  */
/*  MessageText: */
/*  */
/*   The IP address parameter ulIpAddr in command TCPIP_IP_CMD_PING_REQ is invalid. */
/*   This means, the IP address ulIpAddr is equal to the TCP/IP stacks own IP address. */
/*  */
#define TLR_E_IP_ERR_IP_ADDR_INVALID_IP_CMD_PING ((TLR_RESULT)0xC0070100L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_IP_ADDR_INVALID_TCP_UDP_CMD_OPEN */
/*  */
/*  MessageText: */
/*  */
/*   The IP address parameter ulIpAddr in command TCPIP_TCP_UDP_CMD_OPEN_REQ is invalid. */
/*   The parameter ulIpAddr must be zero (0.0.0.0) or equal to the TCP/IP stacks own IP address. */
/*  */
#define TLR_E_TCP_ERR_IP_ADDR_INVALID_TCP_UDP_CMD_OPEN ((TLR_RESULT)0xC0080101L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_IP_ADDR_INVALID_TCP_CMD_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   The IP address parameter ulIpAddr in command TCPIP_TCP_CMD_CONNECT_REQ is invalid. */
/*   The parameter ulIpAddr must be unequal to the TCP/IP stacks own IP address. */
/*  */
#define TLR_E_TCP_ERR_IP_ADDR_INVALID_TCP_CMD_CONNECT ((TLR_RESULT)0xC0080102L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_IP_ADDR_INVALID_UDP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The IP address parameter ulIpAddr in command TCPIP_UDP_CMD_SEND_REQ is invalid or doesn't match to the local sub network. */
/*   This error occurs, if the IP address is zero (0.0.0.0) or equal to the address of the local subnet. */
/*  */
#define TLR_E_TCP_ERR_IP_ADDR_INVALID_UDP_CMD_SEND ((TLR_RESULT)0xC0080103L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_IP_ADDR_INVALID_TCP_UDP_CMD_SET_SOCK_OPTION */
/*  */
/*  MessageText: */
/*  */
/*   The parameter ulMulticastGroup (ulMode = TCP_SOCK_ADD_MEMBERSHIP or TCP_SOCK_DROP_MEMBERSHIP) in command */
/*   TCPIP_TCP_UDP_CMD_SET_SOCK_OPTION_REQ is invalid. */
/*   The parameter ulMulticastGroup must be a valid Multicast address. */
/*   Valid Multicast addresses are 224.0.0.1 ... 239.255.255.255 (224.0.0.0 is reserved as Base-multicast address). */
/*  */
#define TLR_E_TCP_ERR_IP_ADDR_INVALID_TCP_UDP_CMD_SET_SOCK_OPTION ((TLR_RESULT)0xC0080104L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_IP_ADDR_INVALID_TCP_UDP_CMD_BIND */
/*  */
/*  MessageText: */
/*  */
/*   The IP address parameter ulIpAddr in command TCPIP_TCP_UDP_CMD_BIND_REQ is invalid. */
/*   The parameter ulIpAddr must be zero (0.0.0.0) or equal to the TCP/IP stacks own IP address. */
/*  */
#define TLR_E_TCP_ERR_IP_ADDR_INVALID_TCP_UDP_CMD_BIND ((TLR_RESULT)0xC0080105L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_IP_ADDR_INVALID_NO_GATEWAY */
/*  */
/*  MessageText: */
/*  */
/*   The IP address parameter ulIpAddr is invalid, because there is no gateway configured. */
/*   The parameter ulIpAddr must be inside the local network. */
/*  */
#define TLR_E_TCP_ERR_IP_ADDR_INVALID_NO_GATEWAY ((TLR_RESULT)0xC0080106L)

/* /// Port invalid errors 0x0110 ... 0x011F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_TCP_ERR_PORT_INVALID_TCP_UDP_CMD_OPEN */
/*  */
/*  MessageText: */
/*  */
/*   The port parameter ulPort in command TCPIP_TCP_UDP_CMD_OPEN_REQ is invalid or not available. */
/*   The parameter ulPort must be in range 0 ... 65535. */
/*  */
#define TLR_E_TCP_ERR_PORT_INVALID_TCP_UDP_CMD_OPEN ((TLR_RESULT)0xC0080110L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_PORT_INVALID_TCP_CMD_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   The port parameter ulPort in command TCPIP_TCP_CMD_CONNECT_REQ is invalid or not available. */
/*   The parameter ulPort must be in range 1 ... 65535. */
/*  */
#define TLR_E_TCP_ERR_PORT_INVALID_TCP_CMD_CONNECT ((TLR_RESULT)0xC0080111L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_PORT_INVALID_UDP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The port parameter ulPort in command TCPIP_UDP_CMD_SEND_REQ is invalid or not available. */
/*   The parameter ulPort must be in range 0 ... 65535. */
/*  */
#define TLR_E_TCP_ERR_PORT_INVALID_UDP_CMD_SEND ((TLR_RESULT)0xC0080112L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_PORT_INVALID_TCP_UDP_CMD_BIND */
/*  */
/*  MessageText: */
/*  */
/*   The port parameter ulPort in command TCPIP_TCP_UDP_CMD_BIND_REQ is invalid or not available. */
/*   The parameter ulPort must be in range 0 ... 65535. */
/*  */
#define TLR_E_TCP_ERR_PORT_INVALID_TCP_UDP_CMD_BIND ((TLR_RESULT)0xC0080113L)

/* /// Timeout invalid errors 0x0120 ... 0x012F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_IP_ERR_TIMEOUT_INVALID_IP_CMD_PING */
/*  */
/*  MessageText: */
/*  */
/*   The timeout parameter ulTimeout in command TCPIP_IP_CMD_PING_REQ is invalid. */
/*  */
#define TLR_E_IP_ERR_TIMEOUT_INVALID_IP_CMD_PING ((TLR_RESULT)0xC0070120L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_UDP_CMD_CLOSE */
/*  */
/*  MessageText: */
/*  */
/*   The timeout parameter ulTimeout in command TCPIP_TCP_UDP_CMD_CLOSE_REQ is invalid. */
/*   Consider the distinction between TCP and UDP sockets! For UDP sockets, ulTimeout must be zero. */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_UDP_CMD_CLOSE ((TLR_RESULT)0xC0080121L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_UDP_CMD_CLOSE_ALL */
/*  */
/*  MessageText: */
/*  */
/*   The timeout parameter ulTimeout in command TCPIP_TCP_UDP_CMD_CLOSE_ALL_REQ is invalid. */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_UDP_CMD_CLOSE_ALL ((TLR_RESULT)0xC0080122L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_CMD_WAIT_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   The timeout parameter ulTimeoutSend and/or ulTimeoutListen in command TCPIP_TCP_CMD_WAIT_CONNECT_REQ is invalid. */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_CMD_WAIT_CONNECT ((TLR_RESULT)0xC0080123L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_CMD_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   The timeout parameter ulTimeoutSend and/or ulTimeoutConnect in command TCPIP_TCP_CMD_CONNECT_REQ is invalid. */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_CMD_CONNECT ((TLR_RESULT)0xC0080124L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_UDP_CMD_SET_SOCK_OPTION */
/*  */
/*  MessageText: */
/*  */
/*   The timeout parameter ulTimeoutSend (ulMode = TCP_SOCK_SEND_TIMEOUT) or ulTimeoutInactive */
/*   (ulMode = TCP_SOCK_INACTIVE_TIMEOUT) or ulTimeoutKeepAlive (ulMode = TCP_SOCK_KEEPALIVE_TIMEOUT) */
/*   in command TCPIP_TCP_UDP_CMD_SET_SOCK_OPTION_REQ is invalid. */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_UDP_CMD_SET_SOCK_OPTION ((TLR_RESULT)0xC0080125L)

/* /// Mode unknown errors 0x0130 ... 0x013F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_IP_ERR_MODE_UNKNOWN_IP_CMD_SET_PARAM */
/*  */
/*  MessageText: */
/*  */
/*   The mode parameter ulMode in command TCPIP_IP_CMD_SET_PARAM_REQ is invalid. */
/*  */
#define TLR_E_IP_ERR_MODE_UNKNOWN_IP_CMD_SET_PARAM ((TLR_RESULT)0xC0070130L)

/*  */
/*  MessageId: TLR_E_IP_ERR_MODE_UNKNOWN_IP_CMD_GET_PARAM */
/*  */
/*  MessageText: */
/*  */
/*   The mode parameter ulMode in command TCPIP_IP_CMD_GET_PARAM_REQ is invalid. */
/*  */
#define TLR_E_IP_ERR_MODE_UNKNOWN_IP_CMD_GET_PARAM ((TLR_RESULT)0xC0070131L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_MODE_UNKNOWN_TCP_UDP_CMD_SET_SOCK_OPTION */
/*  */
/*  MessageText: */
/*  */
/*   The mode parameter ulMode in command TCPIP_TCP_UDP_CMD_SET_SOCK_OPTION_REQ is invalid. */
/*  */
#define TLR_E_TCP_ERR_MODE_UNKNOWN_TCP_UDP_CMD_SET_SOCK_OPTION ((TLR_RESULT)0xC0080132L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_MODE_UNKNOWN_TCP_UDP_CMD_GET_SOCK_OPTION */
/*  */
/*  MessageText: */
/*  */
/*   The mode parameter ulMode in command TCPIP_TCP_UDP_CMD_GET_SOCK_OPTION_REQ is invalid. */
/*  */
#define TLR_E_TCP_ERR_MODE_UNKNOWN_TCP_UDP_CMD_GET_SOCK_OPTION ((TLR_RESULT)0xC0080133L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_MODE_UNKNOWN_FATAL_DUMMY */
/*  */
/*  MessageText: */
/*  */
/*   Internal fatal error in module TcpipTcphdlPckt.c! */
/*  */
#define TLR_E_TCP_ERR_MODE_UNKNOWN_FATAL_DUMMY ((TLR_RESULT)0xC0080134L)

/* /// Data len errors 0x0140 ... 0x014F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_TCP_ERR_MAX_DATA_LEN_EXCEEDED_TCP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The maximum TCP data count n in command TCPIP_TCP_CMD_SEND_REQ has exceeded. See parameter ulLen. */
/*   The maximum value for n is TCPIP_MAX_TCP_DATA_CNT (1460). */
/*  */
#define TLR_E_TCP_ERR_MAX_DATA_LEN_EXCEEDED_TCP_CMD_SEND ((TLR_RESULT)0xC0080140L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_MAX_DATA_LEN_EXCEEDED_UDP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The maximum UDP data count n in command TCPIP_UDP_CMD_SEND_REQ has exceeded. See parameter ulLen. */
/*   The maximum value for n is TCPIP_MAX_UDP_DATA_CNT (1472). */
/*  */
#define TLR_E_TCP_ERR_MAX_DATA_LEN_EXCEEDED_UDP_CMD_SEND ((TLR_RESULT)0xC0080141L)

/* /// IP Configuration errors 0x0150 ... 0x015F (reserved) - implemented further checkings ///// */
/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_INVALID_FLAGS_IP_CONFIG */
/*  */
/*  MessageText: */
/*  */
/*   The start parameters configures an invalid flag combination for the manual IP configuration */
/*   (IP_CFG_FLAG_IP_ADDR, IP_CFG_FLAG_NET_MASK, IP_CFG_FLAG_GATEWAY). */
/*   Valid flag combinations are: */
/*   - No flag set: No manual configuration - only DHCP and/or BOOTP */
/*   - IP_CFG_FLAG_IP_ADDR + IP_CFG_FLAG_NET_MASK: Local network without gateway */
/*   - IP_CFG_FLAG_IP_ADDR + IP_CFG_FLAG_NET_MASK + IP_CFG_FLAG_GATEWAY: Network with gateway. */
/*  */
#define TLR_E_IP_ERR_INIT_INVALID_FLAGS_IP_CONFIG ((TLR_RESULT)0xC0070150L)

/* ////////   - Local source of errors (stack)   : 0x0200 ... 0x02FF                          ////////// */
/* /// Socket state errors 0x0200 ... 0x020F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_TCP_ERR_SOCKET_STATE_TCP_CMD_WAIT_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   The command TCPIP_TCP_CMD_WAIT_CONNECT_REQ cannot be executed, because the socket is in an inappropriate state. */
/*  */
#define TLR_E_TCP_ERR_SOCKET_STATE_TCP_CMD_WAIT_CONNECT ((TLR_RESULT)0xC0080200L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_SOCKET_STATE_TCP_CMD_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   The command TCPIP_TCP_CMD_CONNECT_REQ cannot be executed, because the socket is in an inappropriate state. */
/*  */
#define TLR_E_TCP_ERR_SOCKET_STATE_TCP_CMD_CONNECT ((TLR_RESULT)0xC0080201L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_SOCKET_STATE_TCP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The command TCPIP_TCP_CMD_SEND_REQ cannot be executed, because the socket is in an inappropriate state. */
/*  */
#define TLR_E_TCP_ERR_SOCKET_STATE_TCP_CMD_SEND ((TLR_RESULT)0xC0080202L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_SOCKET_STATE_TCP_CMD_BIND */
/*  */
/*  MessageText: */
/*  */
/*   The command TCPIP_TCP_UDP_CMD_BIND_REQ cannot be executed, because the TCP socket is in an inappropriate state. */
/*  */
#define TLR_E_TCP_ERR_SOCKET_STATE_TCP_CMD_BIND ((TLR_RESULT)0xC0080203L)

/* /// Resource errors (queues, buffers) 0x0210 ... 0x021F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_TCP_ERR_NO_FREE_QUEUE_ELEMENT_TCP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The TCP send command TCPIP_TCP_CMD_SEND_REQ must be rejected, because the list of free queue elements is empty. */
/*   Remark: Per default configuration, the initial size of this list is 128. */
/*   Every send command (TCPIP_TCP_CMD_SEND_REQ or TCPIP_UDP_CMD_SEND_REQ) occupy one queue element, until the */
/*   confirmation command is given back to the application. To avoid this resource problem, the application must */
/*   reduce the count of open send jobs over all sockets. */
/*  */
#define TLR_E_TCP_ERR_NO_FREE_QUEUE_ELEMENT_TCP_CMD_SEND ((TLR_RESULT)0xC0080210L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_NO_FREE_QUEUE_ELEMENT_UDP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The UDP send command TCPIP_UDP_CMD_SEND_REQ must be rejected, because the list of free queue elements is empty. */
/*   Remark: Per default configuration, the initial size of this list is 128. */
/*   Every send command (TCPIP_TCP_CMD_SEND_REQ or TCPIP_UDP_CMD_SEND_REQ) occupy one queue element, until the */
/*   confirmation command is given back to the application. To avoid this resource problem, the application must */
/*   reduce the count of open send jobs over all sockets. */
/*  */
#define TLR_E_TCP_ERR_NO_FREE_QUEUE_ELEMENT_UDP_CMD_SEND ((TLR_RESULT)0xC0080211L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_NO_ETH_OUT_BUFFER_UDP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The UDP send command TCPIP_UDP_CMD_SEND_REQ must be rejected, because all outgoing Ethernet buffers are occupied. */
/*  */
#define TLR_E_TCP_ERR_NO_ETH_OUT_BUFFER_UDP_CMD_SEND ((TLR_RESULT)0xC0080212L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_NO_FREE_RESOURCE_FOR_ARP_REQ_INTF */
/*  */
/*  MessageText: */
/*  */
/*   The command TCPIP_IP_CMD_SET_PARAM_REQ in mode IP_PRM_SEND_ARP_REQ/IP_PRM_SEND_ARP_TMT_REQ must be rejected, */
/*   because all free resources for this command are occupied. A maximum of 128 parallel jobs is possible. */
/*  */
#define TLR_E_TCP_ERR_NO_FREE_RESOURCE_FOR_ARP_REQ_INTF ((TLR_RESULT)0xC0080213L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_ETH_OUT_SEND_BUFFER */
/*  */
/*  MessageText: */
/*  */
/*   The send of the outgoing Ethernet buffer has failed. The reason of this error is normally a */
/*   resource problem - there is no EDD buffer available. */
/*  */
#define TLR_E_TCP_ERR_ETH_OUT_SEND_BUFFER ((TLR_RESULT)0xC0080214L)

/* /// Multicast errors 0x0220 ... 0x022F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_TCP_ERR_MCAST_CREATE */
/*  */
/*  MessageText: */
/*  */
/*   Failed to create an IP Multicast group. */
/*  */
#define TLR_E_TCP_ERR_MCAST_CREATE       ((TLR_RESULT)0xC0080220L)

/* ////////   - Remote source of errors          : 0x0300 ... 0x03FF                          ////////// */
/* /// Destination unreachable errors 0x0300 ... 0x030F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_IP_ERR_DEST_UNREACHABLE_IP_CMD_PING */
/*  */
/*  MessageText: */
/*  */
/*   The target IP address ulIpAddr in command TCPIP_IP_CMD_PING_REQ is not reachable. */
/*  */
#define TLR_E_IP_ERR_DEST_UNREACHABLE_IP_CMD_PING ((TLR_RESULT)0xC0070300L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_DEST_UNREACHABLE_TCP_UDP_CMD_CLOSE */
/*  */
/*  MessageText: */
/*  */
/*   Command TCPIP_TCP_UDP_CMD_CLOSE_REQ: The destination (host, network, or port) is unreachable. */
/*  */
#define TLR_E_TCP_ERR_DEST_UNREACHABLE_TCP_UDP_CMD_CLOSE ((TLR_RESULT)0xC0080301L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_DEST_UNREACHABLE_TCP_UDP_CMD_CLOSE_ALL */
/*  */
/*  MessageText: */
/*  */
/*   Command TCPIP_TCP_UDP_CMD_CLOSE_ALL_REQ: The destination (host, network, or port) is unreachable. */
/*  */
#define TLR_E_TCP_ERR_DEST_UNREACHABLE_TCP_UDP_CMD_CLOSE_ALL ((TLR_RESULT)0xC0080302L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_DEST_UNREACHABLE_TCP_CMD_WAIT_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   Command TCPIP_TCP_CMD_WAIT_CONNECT_REQ: The destination (host, network, or port) is unreachable. */
/*  */
#define TLR_E_TCP_ERR_DEST_UNREACHABLE_TCP_CMD_WAIT_CONNECT ((TLR_RESULT)0xC0080303L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_DEST_UNREACHABLE_TCP_CMD_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   Command TCPIP_TCP_CMD_CONNECT_REQ: The destination (host, network, or port) is unreachable. */
/*  */
#define TLR_E_TCP_ERR_DEST_UNREACHABLE_TCP_CMD_CONNECT ((TLR_RESULT)0xC0080304L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_DEST_UNREACHABLE_UDP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   Command TCPIP_UDP_CMD_SEND_REQ: The destination (host, network, or port) is unreachable. */
/*  */
#define TLR_E_TCP_ERR_DEST_UNREACHABLE_UDP_CMD_SEND ((TLR_RESULT)0xC0080305L)

/* /// Timeout errors 0x0310 ... 0x031F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_IP_ERR_TIMEOUT_IP_CMD_PING */
/*  */
/*  MessageText: */
/*  */
/*   The specified timeout ulTimeout in command TCPIP_IP_CMD_PING_REQ has expired. */
/*   The specified host is not reachable. */
/*  */
#define TLR_E_IP_ERR_TIMEOUT_IP_CMD_PING ((TLR_RESULT)0xC0070310L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_TCP_UDP_CMD_CLOSE */
/*  */
/*  MessageText: */
/*  */
/*   The TCP Close timeout has expired. A connection to the remote host could not be closed gracefully */
/*   within this time. */
/*   For this timeout, see command TCPIP_TCP_UDP_CMD_CLOSE_REQ, parameter ulTimeout. */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_TCP_UDP_CMD_CLOSE ((TLR_RESULT)0xC0080311L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_TCP_UDP_CMD_CLOSE_ALL */
/*  */
/*  MessageText: */
/*  */
/*   The TCP Close timeout has expired. One or more connections to remote host(s) could not be closed gracefully */
/*   within this time. */
/*   For this timeout, see command TCPIP_TCP_UDP_CMD_CLOSE_ALL_REQ, parameter ulTimeout. */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_TCP_UDP_CMD_CLOSE_ALL ((TLR_RESULT)0xC0080312L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_TCP_CMD_WAIT_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   The TCP Connect timeout has expired. No remote host has connected within this time. */
/*   For this timeout, see command TCPIP_TCP_CMD_WAIT_CONNECT_REQ, parameter ulTimeoutListen. */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_TCP_CMD_WAIT_CONNECT ((TLR_RESULT)0xC0080313L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_TCP_CMD_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   The TCP Connect timeout has expired. A connection to the specified remote host could not be established */
/*   within this time. */
/*   For this timeout, see command TCPIP_TCP_CMD_CONNECT_REQ, parameter ulTimeoutConnect. */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_TCP_CMD_CONNECT ((TLR_RESULT)0xC0080314L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_TCP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The TCP Send timeout has expired by sending TCP data with command TCPIP_TCP_CMD_SEND_REQ. */
/*   The remote host has not answered within the Send Timeout. */
/*   The TCP Send timeout is set in command TCPIP_TCP_CMD_WAIT_CONNECT_REQ or */
/*   TCPIP_TCP_CMD_CONNECT_REQ, parameter ulTimeoutSend (Default = 31 s). */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_TCP_CMD_SEND ((TLR_RESULT)0xC0080315L)

/* /// Further errors 0x0xxx ... ///// */



#endif  /* __TCPIP_ERROR_H */

#ifndef __TLR_GLOBAL_ERROR_H
#define __TLR_GLOBAL_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Hilscher TLR_STATUS definitions */
/* /////////////////////////////////////////////////////////////////////////////////// */

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  common status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */

/*  */
/*  MessageId: TLR_S_OK */
/*  */
/*  MessageText: */
/*  */
/*   Operation succeeded. */
/*  */
#define TLR_S_OK                         ((TLR_RESULT)0x00000000L)

/*  */
/*  MessageId: TLR_E_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Common error, detailed error information optionally present in the data area of packet. */
/*  */
#define TLR_E_FAIL                       ((TLR_RESULT)0xC0000001L)

/*  */
/*  MessageId: TLR_E_UNEXPECTED */
/*  */
/*  MessageText: */
/*  */
/*   Unexpected failure. */
/*  */
#define TLR_E_UNEXPECTED                 ((TLR_RESULT)0xC0000002L)

/*  */
/*  MessageId: TLR_E_OUTOFMEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Ran out of memory. */
/*  */
#define TLR_E_OUTOFMEMORY                ((TLR_RESULT)0xC0000003L)

/*  */
/*  MessageId: TLR_E_UNKNOWN_COMMAND */
/*  */
/*  MessageText: */
/*  */
/*   Unknown Command in Packet received. */
/*  */
#define TLR_E_UNKNOWN_COMMAND            ((TLR_RESULT)0xC0000004L)

/*  */
/*  MessageId: TLR_E_UNKNOWN_DESTINATION */
/*  */
/*  MessageText: */
/*  */
/*   Unknown Destination in Packet received. */
/*  */
#define TLR_E_UNKNOWN_DESTINATION        ((TLR_RESULT)0xC0000005L)

/*  */
/*  MessageId: TLR_E_UNKNOWN_DESTINATION_ID */
/*  */
/*  MessageText: */
/*  */
/*   Unknown Destination Id in Packet received. */
/*  */
#define TLR_E_UNKNOWN_DESTINATION_ID     ((TLR_RESULT)0xC0000006L)

/*  */
/*  MessageId: TLR_E_INVALID_PACKET_LEN */
/*  */
/*  MessageText: */
/*  */
/*   Packet length is invalid. */
/*  */
#define TLR_E_INVALID_PACKET_LEN         ((TLR_RESULT)0xC0000007L)

/*  */
/*  MessageId: TLR_E_INVALID_EXTENSION */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Extension in Packet received. */
/*  */
#define TLR_E_INVALID_EXTENSION          ((TLR_RESULT)0xC0000008L)

/*  */
/*  MessageId: TLR_E_INVALID_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Parameter in Packet found. */
/*  */
#define TLR_E_INVALID_PARAMETER          ((TLR_RESULT)0xC0000009L)

/*  */
/*  MessageId: TLR_E_WATCHDOG_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Watchdog error occurred. */
/*  */
#define TLR_E_WATCHDOG_TIMEOUT           ((TLR_RESULT)0xC000000CL)

/*  */
/*  MessageId: TLR_E_INVALID_LIST_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   list type is invalid. */
/*  */
#define TLR_E_INVALID_LIST_TYPE          ((TLR_RESULT)0xC000000DL)

/*  */
/*  MessageId: TLR_E_UNKNOWN_HANDLE */
/*  */
/*  MessageText: */
/*  */
/*   Handle is unknown. */
/*  */
#define TLR_E_UNKNOWN_HANDLE             ((TLR_RESULT)0xC000000EL)

/*  */
/*  MessageId: TLR_E_PACKET_OUT_OF_SEQ */
/*  */
/*  MessageText: */
/*  */
/*   A packet index has been not in the expected sequence. */
/*  */
#define TLR_E_PACKET_OUT_OF_SEQ          ((TLR_RESULT)0xC000000FL)

/*  */
/*  MessageId: TLR_E_PACKET_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   The amount of fragmented data contained the packet sequence has been too large. */
/*  */
#define TLR_E_PACKET_OUT_OF_MEMORY       ((TLR_RESULT)0xC0000010L)

/*  */
/*  MessageId: TLR_E_QUE_PACKETDONE */
/*  */
/*  MessageText: */
/*  */
/*   The packet done function has failed. */
/*  */
#define TLR_E_QUE_PACKETDONE             ((TLR_RESULT)0xC0000011L)

/*  */
/*  MessageId: TLR_E_QUE_SENDPACKET */
/*  */
/*  MessageText: */
/*  */
/*   The sending of a packet has failed. */
/*  */
#define TLR_E_QUE_SENDPACKET             ((TLR_RESULT)0xC0000012L)

/*  */
/*  MessageId: TLR_E_POOL_PACKET_GET */
/*  */
/*  MessageText: */
/*  */
/*   The request of a packet from packet pool has failed. */
/*  */
#define TLR_E_POOL_PACKET_GET            ((TLR_RESULT)0xC0000013L)

/*  */
/*  MessageId: TLR_E_POOL_PACKET_RELEASE */
/*  */
/*  MessageText: */
/*  */
/*   The release of a packet to packet pool has failed. */
/*  */
#define TLR_E_POOL_PACKET_RELEASE        ((TLR_RESULT)0xC0000014L)

/*  */
/*  MessageId: TLR_E_POOL_GET_LOAD */
/*  */
/*  MessageText: */
/*  */
/*   The get packet pool load function has failed. */
/*  */
#define TLR_E_POOL_GET_LOAD              ((TLR_RESULT)0xC0000015L)

/*  */
/*  MessageId: TLR_E_QUE_GET_LOAD */
/*  */
/*  MessageText: */
/*  */
/*   The get queue load function has failed. */
/*  */
#define TLR_E_QUE_GET_LOAD               ((TLR_RESULT)0xC0000016L)

/*  */
/*  MessageId: TLR_E_QUE_WAITFORPACKET */
/*  */
/*  MessageText: */
/*  */
/*   The waiting for a packet from queue has failed. */
/*  */
#define TLR_E_QUE_WAITFORPACKET          ((TLR_RESULT)0xC0000017L)

/*  */
/*  MessageId: TLR_E_QUE_POSTPACKET */
/*  */
/*  MessageText: */
/*  */
/*   The posting of a packet has failed. */
/*  */
#define TLR_E_QUE_POSTPACKET             ((TLR_RESULT)0xC0000018L)

/*  */
/*  MessageId: TLR_E_QUE_PEEKPACKET */
/*  */
/*  MessageText: */
/*  */
/*   The peek of a packet from queue has failed. */
/*  */
#define TLR_E_QUE_PEEKPACKET             ((TLR_RESULT)0xC0000019L)

/*  */
/*  MessageId: TLR_E_REQUEST_RUNNING */
/*  */
/*  MessageText: */
/*  */
/*   Request is already running. */
/*  */
#define TLR_E_REQUEST_RUNNING            ((TLR_RESULT)0xC000001AL)

/*  */
/*  MessageId: TLR_E_CREATE_TIMER */
/*  */
/*  MessageText: */
/*  */
/*   Creating a timer failed. */
/*  */
#define TLR_E_CREATE_TIMER               ((TLR_RESULT)0xC000001BL)

/*  */
/*  MessageId: TLR_E_INIT_FAULT */
/*  */
/*  MessageText: */
/*  */
/*   General initialization fault. */
/*  */
#define TLR_E_INIT_FAULT                 ((TLR_RESULT)0xC0000100L)

/*  */
/*  MessageId: TLR_E_DATABASE_ACCESS_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Database access failure. */
/*  */
#define TLR_E_DATABASE_ACCESS_FAILED     ((TLR_RESULT)0xC0000101L)

/*  */
/*  MessageId: TLR_E_CIR_MASTER_PARAMETER_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Master parameter can not activated at state operate. */
/*  */
#define TLR_E_CIR_MASTER_PARAMETER_FAILED ((TLR_RESULT)0xC0000102L)

/*  */
/*  MessageId: TLR_E_CIR_SLAVE_PARAMTER_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Slave parameter can not activated at state operate. */
/*  */
#define TLR_E_CIR_SLAVE_PARAMTER_FAILED  ((TLR_RESULT)0xC0000103L)

/*  */
/*  MessageId: TLR_E_NOT_CONFIGURED */
/*  */
/*  MessageText: */
/*  */
/*   Configuration not available */
/*  */
#define TLR_E_NOT_CONFIGURED             ((TLR_RESULT)0xC0000119L)

/*  */
/*  MessageId: TLR_E_CONFIGURATION_FAULT */
/*  */
/*  MessageText: */
/*  */
/*   General configuration fault. */
/*  */
#define TLR_E_CONFIGURATION_FAULT        ((TLR_RESULT)0xC0000120L)

/*  */
/*  MessageId: TLR_E_INCONSISTENT_DATA_SET */
/*  */
/*  MessageText: */
/*  */
/*   Inconsistent configuration data. */
/*  */
#define TLR_E_INCONSISTENT_DATA_SET      ((TLR_RESULT)0xC0000121L)

/*  */
/*  MessageId: TLR_E_DATA_SET_MISMATCH */
/*  */
/*  MessageText: */
/*  */
/*   Configuration data set mismatch. */
/*  */
#define TLR_E_DATA_SET_MISMATCH          ((TLR_RESULT)0xC0000122L)

/*  */
/*  MessageId: TLR_E_INSUFFICIENT_LICENSE */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient license. */
/*  */
#define TLR_E_INSUFFICIENT_LICENSE       ((TLR_RESULT)0xC0000123L)

/*  */
/*  MessageId: TLR_E_PARAMETER_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Parameter error. */
/*  */
#define TLR_E_PARAMETER_ERROR            ((TLR_RESULT)0xC0000124L)

/*  */
/*  MessageId: TLR_E_INVALID_NETWORK_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   Network address invalid. */
/*  */
#define TLR_E_INVALID_NETWORK_ADDRESS    ((TLR_RESULT)0xC0000125L)

/*  */
/*  MessageId: TLR_E_NO_SECURITY_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Security memory chip missing or broken. */
/*  */
#define TLR_E_NO_SECURITY_MEMORY         ((TLR_RESULT)0xC0000126L)

/*  */
/*  MessageId: TLR_E_NETWORK_FAULT */
/*  */
/*  MessageText: */
/*  */
/*   General communication fault. */
/*  */
#define TLR_E_NETWORK_FAULT              ((TLR_RESULT)0xC0000140L)

/*  */
/*  MessageId: TLR_E_CONNECTION_CLOSED */
/*  */
/*  MessageText: */
/*  */
/*   Connection closed. */
/*  */
#define TLR_E_CONNECTION_CLOSED          ((TLR_RESULT)0xC0000141L)

/*  */
/*  MessageId: TLR_E_CONNECTION_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Connection timeout. */
/*  */
#define TLR_E_CONNECTION_TIMEOUT         ((TLR_RESULT)0xC0000142L)

/*  */
/*  MessageId: TLR_E_LONELY_NETWORK */
/*  */
/*  MessageText: */
/*  */
/*   Lonely network. */
/*  */
#define TLR_E_LONELY_NETWORK             ((TLR_RESULT)0xC0000143L)

/*  */
/*  MessageId: TLR_E_DUPLICATE_NODE */
/*  */
/*  MessageText: */
/*  */
/*   Duplicate network address. */
/*  */
#define TLR_E_DUPLICATE_NODE             ((TLR_RESULT)0xC0000144L)

/*  */
/*  MessageId: TLR_E_CABLE_DISCONNECT */
/*  */
/*  MessageText: */
/*  */
/*   Cable disconnected. */
/*  */
#define TLR_E_CABLE_DISCONNECT           ((TLR_RESULT)0xC0000145L)

/*  */
/*  MessageId: TLR_E_BUS_OFF */
/*  */
/*  MessageText: */
/*  */
/*   Bus Off flag is set. */
/*  */
#define TLR_E_BUS_OFF                    ((TLR_RESULT)0xC0000180L)

/*  */
/*  MessageId: TLR_E_CONFIG_LOCK */
/*  */
/*  MessageText: */
/*  */
/*   Changing configuration is not allowed. */
/*  */
#define TLR_E_CONFIG_LOCK                ((TLR_RESULT)0xC0000181L)

/*  */
/*  MessageId: TLR_E_APPLICATION_NOT_READY */
/*  */
/*  MessageText: */
/*  */
/*   Application is not at ready state. */
/*  */
#define TLR_E_APPLICATION_NOT_READY      ((TLR_RESULT)0xC0000182L)

/*  */
/*  MessageId: TLR_E_RESET_IN_PROCESS */
/*  */
/*  MessageText: */
/*  */
/*   Application is performing a reset. */
/*  */
#define TLR_E_RESET_IN_PROCESS           ((TLR_RESULT)0xC0000183L)

/*  */
/*  MessageId: TLR_E_WATCHDOG_TIME_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Watchdog time is out of range. */
/*  */
#define TLR_E_WATCHDOG_TIME_INVALID      ((TLR_RESULT)0xC0000200L)

/*  */
/*  MessageId: TLR_E_APPLICATION_ALREADY_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   Application is already registered. */
/*  */
#define TLR_E_APPLICATION_ALREADY_REGISTERED ((TLR_RESULT)0xC0000201L)

/*  */
/*  MessageId: TLR_E_NO_APPLICATION_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   No application registered. */
/*  */
#define TLR_E_NO_APPLICATION_REGISTERED  ((TLR_RESULT)0xC0000202L)

/*  */
/*  MessageId: TLR_S_FRAGMENTED */
/*  */
/*  MessageText: */
/*  */
/*   Fragment accepted. */
/*  */
#define TLR_S_FRAGMENTED                 ((TLR_RESULT)0x0000F005L)

/*  */
/*  MessageId: TLR_E_RESET_REQUIRED */
/*  */
/*  MessageText: */
/*  */
/*   Reset required. */
/*  */
#define TLR_E_RESET_REQUIRED             ((TLR_RESULT)0xC000F006L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  TLR Timer Packet Status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_TIMER_TASK_INVALID_INSTANCE */
/*  */
/*  MessageText: */
/*  */
/*   Task Instance is invalid. Multiple instances of TLR Timer task are forbidden. */
/*  */
#define TLR_E_TIMER_TASK_INVALID_INSTANCE ((TLR_RESULT)0xC0020001L)

/*  */
/*  MessageId: TLR_E_TIMER_IRQ_PARAM_INVALID_HANDLE */
/*  */
/*  MessageText: */
/*  */
/*   Parameter Interrupt Timer Handle is invalid. */
/*  */
#define TLR_E_TIMER_IRQ_PARAM_INVALID_HANDLE ((TLR_RESULT)0xC0020002L)

/*  */
/*  MessageId: TLR_E_TIMER_IRQ_PARAM_INVALID_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Parameter Interrupt Timer Reload Value is invalid. */
/*  */
#define TLR_E_TIMER_IRQ_PARAM_INVALID_VALUE ((TLR_RESULT)0xC0020003L)

/*  */
/*  MessageId: TLR_E_TIMER_IRQ_RESOURCE_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   There is no resource to create a interrupt timer. */
/*  */
#define TLR_E_TIMER_IRQ_RESOURCE_CREATE_FAILED ((TLR_RESULT)0xC0020004L)

/*  */
/*  MessageId: TLR_E_TIMER_APPL_PARAM_INVALID_HANDLE */
/*  */
/*  MessageText: */
/*  */
/*   Parameter Application Timer Handle is invalid. */
/*  */
#define TLR_E_TIMER_APPL_PARAM_INVALID_HANDLE ((TLR_RESULT)0xC0020005L)

/*  */
/*  MessageId: TLR_E_TIMER_APPL_PARAM_INVALID_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Parameter Application Timer Reload Value is invalid. */
/*  */
#define TLR_E_TIMER_APPL_PARAM_INVALID_VALUE ((TLR_RESULT)0xC0020006L)

/*  */
/*  MessageId: TLR_E_TIMER_APPL_PARAM_INVALID_QUEUE */
/*  */
/*  MessageText: */
/*  */
/*   Parameter Queue Handle is invalid. */
/*  */
#define TLR_E_TIMER_APPL_PARAM_INVALID_QUEUE ((TLR_RESULT)0xC0020007L)

/*  */
/*  MessageId: TLR_E_TIMER_APPL_RESOURCE_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   There is no resource to create an application timer. */
/*  */
#define TLR_E_TIMER_APPL_RESOURCE_CREATE_FAILED ((TLR_RESULT)0xC0020008L)

/*  */
/*  MessageId: TLR_E_TIMER_APPL_RESOURCE_INSERTED */
/*  */
/*  MessageText: */
/*  */
/*   Application timer is already inserted into timer list. */
/*  */
#define TLR_E_TIMER_APPL_RESOURCE_INSERTED ((TLR_RESULT)0xC0020009L)

/*  */
/*  MessageId: TLR_E_TIMER_PACKET_RESOURCE_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   No Resource to retry sending of packet. */
/*  */
#define TLR_E_TIMER_PACKET_RESOURCE_CREATE_FAILED ((TLR_RESULT)0xC002000AL)

/*  */
/*  MessageId: TLR_E_TIMER_TASK_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   TLR Timer Task not initialized. */
/*  */
#define TLR_E_TIMER_TASK_NOT_INITIALIZED ((TLR_RESULT)0xC002000BL)

/*  */
/*  MessageId: TLR_E_TIMER_APPL_PACKET_SENT */
/*  */
/*  MessageText: */
/*  */
/*   Packet of application timer was sent to queue. */
/*  */
#define TLR_E_TIMER_APPL_PACKET_SENT     ((TLR_RESULT)0xC002000CL)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  User Area */
/* /////////////////////////////////////////////////////////////////////////////////// */

/*  */
/*  MessageId: TLR_S_USER_AREA */
/*  */
/*  MessageText: */
/*  */
/*   User code. */
/*  */
#define TLR_S_USER_AREA                  ((TLR_RESULT)0x0FF00000L)




#endif  /* __TLR_GLOBAL_ERROR_H */

#ifndef __TLR_ROUTER_ERROR_H
#define __TLR_ROUTER_ERROR_H




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  TLR router error/status codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_ROUTER_PACKET_TOO_BIG */
/*  */
/*  MessageText: */
/*  */
/*   Router: Packet is too big (maximum overall size is 2048 Bytes). */
/*  */
#define TLR_E_ROUTER_PACKET_TOO_BIG      ((TLR_RESULT)0xC02F0001L)

/*  */
/*  MessageId: TLR_E_ROUTER_LINK_INACTIVE */
/*  */
/*  MessageText: */
/*  */
/*   Router: Link inactive. */
/*  */
#define TLR_E_ROUTER_LINK_INACTIVE       ((TLR_RESULT)0xC02F0002L)

/*  */
/*  MessageId: TLR_E_ROUTER_FRAGMENT_MISSING */
/*  */
/*  MessageText: */
/*  */
/*   Router: Fragment Missing. */
/*  */
#define TLR_E_ROUTER_FRAGMENT_MISSING    ((TLR_RESULT)0xC02F0003L)

/*  */
/*  MessageId: TLR_E_ROUTER_SEND_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Router: Packet Send Timeout reached. */
/*  */
#define TLR_E_ROUTER_SEND_TIMEOUT        ((TLR_RESULT)0xC02F0004L)

/*  */
/*  MessageId: TLR_E_ROUTER_LOGICAL_QUEUE_UNDEFINED */
/*  */
/*  MessageText: */
/*  */
/*   Router: Logical queue handle is undefined. */
/*  */
#define TLR_E_ROUTER_LOGICAL_QUEUE_UNDEFINED ((TLR_RESULT)0xC02F0005L)




#endif  /* __TLR_ROUTER_ERROR_H */

#ifndef __UDP_DEBUG_ERROR_H
#define __UDP_DEBUG_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  UDP Debug Client */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_DEBUG_CLIENT_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command received. */
/*  */
#define TLR_E_DEBUG_CLIENT_COMMAND_INVALID ((TLR_RESULT)0xC01B0001L)




#endif  /* __UDP_DEBUG_ERROR_H */

#ifndef __USB_ROUTER_ERROR_H
#define __USB_ROUTER_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Usb-TLR-Router Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_USB_TLRROUTER_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_USB_TLRROUTER_COMMAND_INVALID ((TLR_RESULT)0xC0440001L)




#endif  /* __USB_ROUTER_ERROR_H */

#ifndef __VIRTUALSWITCH_ERROR_H
#define __VIRTUALSWITCH_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  VirtualSwitch error codes */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_E_VIRTUALSWITCH_COMMAND_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid command. */
/*  */
#define TLR_E_VIRTUALSWITCH_COMMAND_INVALID ((TLR_RESULT)0xC0270001L)

/*  */
/*  MessageId: TLR_E_VIRTUALSWITCH_PORT_ALREADY_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   Port parameter already defined by another port. */
/*  */
#define TLR_E_VIRTUALSWITCH_PORT_ALREADY_REGISTERED ((TLR_RESULT)0xC0270002L)

/*  */
/*  MessageId: TLR_E_VIRTUALSWITCH_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Out of memory. */
/*  */
#define TLR_E_VIRTUALSWITCH_OUT_OF_MEMORY ((TLR_RESULT)0xC0270003L)

/*  */
/*  MessageId: TLR_E_VIRTUALSWITCH_INVALID_PORT_HANDLE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid port handle. */
/*  */
#define TLR_E_VIRTUALSWITCH_INVALID_PORT_HANDLE ((TLR_RESULT)0xC0270004L)

/*  */
/*  MessageId: TLR_E_VIRTUALSWITCH_INVALID_PORT_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid port mode. */
/*  */
#define TLR_E_VIRTUALSWITCH_INVALID_PORT_MODE ((TLR_RESULT)0xC0270005L)

/*  */
/*  MessageId: TLR_E_VIRTUALSWITCH_TABLE_ALREADY_CREATED */
/*  */
/*  MessageText: */
/*  */
/*   MAC routing table already created. */
/*  */
#define TLR_E_VIRTUALSWITCH_TABLE_ALREADY_CREATED ((TLR_RESULT)0xC0270006L)

/*  */
/*  MessageId: TLR_E_VIRTUALSWITCH_TABLE_INSTANCE_NOT_PREDEFINED */
/*  */
/*  MessageText: */
/*  */
/*   Named Virtual Switch Instance does not exist. */
/*  */
#define TLR_E_VIRTUALSWITCH_TABLE_INSTANCE_NOT_PREDEFINED ((TLR_RESULT)0xC0270007L)

/*  */
/*  MessageId: TLR_E_VIRTUALSWITCH_NO_SUCH_NAME */
/*  */
/*  MessageText: */
/*  */
/*   No such name. */
/*  */
#define TLR_E_VIRTUALSWITCH_NO_SUCH_NAME ((TLR_RESULT)0xC0270008L)

/*  */
/*  MessageId: TLR_E_VIRTUALSWITCH_NAME_EXISTS_ALREADY */
/*  */
/*  MessageText: */
/*  */
/*   Name exists already. */
/*  */
#define TLR_E_VIRTUALSWITCH_NAME_EXISTS_ALREADY ((TLR_RESULT)0xC0270009L)




#endif  /* __VIRTUALSWITCH_ERROR_H */

