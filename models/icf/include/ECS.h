#ifndef __ECS_H
#define __ECS_H
#include "icf_export.h"
#include "icf_utility.h"
#include "icf_drivers.h"

/* protocol v2 pkt cmd*/
#define ESM_ALSTATUS_INIT_IND             0x1962
#define ESM_ALSTATUS_INIT_RES             0x1963

#define ESM_ALSTATUS_PRE_OPERATIONAL_IND  0x1964
#define ESM_ALSTATUS_PRE_OPERATIONAL_RES  0x1965

#define ESM_ALSTATUS_SAFE_OPERATIONAL_IND 0x1968
#define ESM_ALSTATUS_SAFE_OPERATIONAL_RES 0x1969

#define ESM_ALSTATUS_OPERATIONAL_IND      0x1970
#define ESM_ALSTATUS_OPERATIONAL_RES      0x1971

/* ConfigFilePath*/
#define ConfigFilePath   (char*) "/opt/cifx/deviceconfig/1251100/31613/channel0/config.nxd"
#define FirmwareFilePath (char*) "/opt/cifx/deviceconfig/1251100/31613/channel0/cifxecs.nxf" 

/* MAX I/O*/
#define MAX_RTD_SIZE 200

#ifdef __cplusplus
  extern "C" {
#endif  /* _cplusplus */

/* cifx common header */
#include "TLR_Types.h"
#include "TLR_Results.h"
#include "TLR_Packet.h"
#include "cifXErrors.h"
#include "cifXUser.h"
#include "rcx_error.h"
#include "rcX_Public.h"
#include "rcX_User.h"
#include "rX_Types.h"
#include "cifxlinux.h"
#include "EcsV4_Public.h"



typedef struct ECS_common_tag {
  void* hDriver;
  void* hChannel;
  uint32_t ulTimeout;
  uint8_t* ptCycReadData;
  uint32_t ulCycReadDataSize;
  uint8_t* ptCycWriteData;
  uint32_t ulCycWriteDataSize;
  uint32_t esmState;
} ECS_common_t;


typedef struct ECS_device_info_tag {
	ECS_common_t tCommon;
	CIFX_PACKET  tSendPkt;
	CIFX_PACKET  tRecvPkt;
} ECS_device_info_t;


/* create resource */
int32_t ECS_CreateResources(void** priv_data);

int32_t ECS_FreeResources(void** priv_data);

/*initial function*/
int32_t ECS_Init(void** priv_data, char* ifname, int ulChannel);
int32_t ECS_Deinit(void** priv_data);

/* handle packet */
int32_t ECS_RegistNotification(ECS_device_info_t* ptECS);
int32_t ECS_SendRecvEmptyPkt(ECS_device_info_t* ptECS, uint32_t ulCmd); 
int32_t ECS_SendRecvPkt(ECS_device_info_t* ptECS, CIFX_PACKET* ptSendPkt, CIFX_PACKET* ptRecvPkt);

void ECS_HandlePacket(ECS_device_info_t* ptECS, CIFX_PACKET* ptPacket);
void HandleAlStatusChangedIndication(ECS_device_info_t*  ptECS, ECAT_ESM_ALSTATUS_CHANGED_IND_T* ptAlStatusInd);
void HandleRcxLinkChangedIndication(ECS_device_info_t*  ptECS, RCX_LINK_STATUS_CHANGE_IND_T* ptRcxLinkInd);
void HandleAlControlChangedRequest(ECS_device_info_t*  ptECS, ECAT_ESM_ALCONTROL_CHANGED_IND_T* ptAlControlInd);

/* Cyclic data exchange*/
int32_t ECS_data_recv(void *priv_data, uint8_t *rx_buff, uint32_t buff_size);
int32_t ECS_data_send(void *priv_data, uint8_t *payload, uint32_t frame_len);

/* DEBUF FUNCTION*/
int32_t printPktHeader( TLR_PACKET_HEADER_T* pthead);

#ifdef __cplusplus
  }
#endif  /* _cplusplus */

#endif /* #ifndef __ECS_H */
