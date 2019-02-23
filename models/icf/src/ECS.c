#ifdef __cplusplus
extern "C"
{
#endif

#include "ECS.h"

#ifdef __cplusplus
}
#endif
struct CIFX_LINUX_INIT ptInit = {
	.init_options = CIFX_DRIVER_INIT_AUTOSCAN, // Find all UIO devices automatically
	.iCardNumber = 0,                          // not used when init_options set to AUTOSCAN
	.fEnableCardLocking = 0,                   // do not lock card
	.base_dir = "/opt/cifx/", 	               // use default (/opt/cifx/)
	.poll_interval = 0, 	                   // use default poll interval (500ms)
	.poll_StackSize = 0, 	                   // used default size (0x5000 Byte)
	.trace_level = 255, 	                   // Enable all debugging outputs to log file
	.user_card_cnt = 0,	                       // no user defined cards
	.user_cards = NULL,	                       // not used
};

int32_t ECS_CreateResources(void** priv_data) {
    /* return value of function */
    int32_t tResult = TLR_S_OK;
    ECS_device_info_t* dev_info = NULL;
    printf("Allocating resources...\n");
    
    dev_info = (ECS_device_info_t*) malloc(sizeof(ECS_device_info_t));
    if (dev_info == NULL) {
        /* at the end of the function we will return the pointer */
        priv_data = NULL;
        return -1;
    }

    /* allocate memory for application data */
    memset(dev_info, 0, sizeof(ECS_device_info_t));
     
    /* allocate memory for read / write buffers */
    dev_info->tCommon.ulCycReadDataSize  = MAX_RTD_SIZE ;
    dev_info->tCommon.ulCycWriteDataSize = MAX_RTD_SIZE ;
        
    dev_info->tCommon.ptCycReadData  =  (uint8_t*) malloc(dev_info->tCommon.ulCycReadDataSize);
    if (dev_info->tCommon.ptCycReadData == NULL) {
         free(dev_info);
         priv_data = NULL;
         return -1;
    }
     
    dev_info->tCommon.ptCycWriteData =  (uint8_t*) malloc(dev_info->tCommon.ulCycWriteDataSize);
    if (dev_info->tCommon.ptCycWriteData == NULL) {
         free(dev_info->tCommon.ptCycReadData);
         free(dev_info);
         priv_data = NULL;
         return -1;
    }

    /* initialize the read and write buffer with zero */
    memset(dev_info->tCommon.ptCycReadData ,  0, dev_info->tCommon.ulCycReadDataSize);
    memset(dev_info->tCommon.ptCycWriteData,  0, dev_info->tCommon.ulCycWriteDataSize);
    
    /* return the pointer */
    printf("Successful.\n");
	*priv_data = dev_info;
    return 0;
}


int32_t ECS_FreeResources(void** priv_data) {
    /* return value of function */
    int32_t tResult = 0;
    
    printf("Free resources...\n");
    ECS_device_info_t* dev_info = (ECS_device_info_t*) *priv_data;
    /* free buffer resources */
    free(dev_info->tCommon.ptCycReadData);
    free(dev_info->tCommon.ptCycWriteData);
    /* free application data container */
    free(dev_info);
    printf("Successful.\n");
    return tResult;
}

int32_t ECS_SendRecvPkt(ECS_device_info_t* dev_info, CIFX_PACKET* ptSendPkt, CIFX_PACKET* ptRecvPkt) {
    /* return value of function */	
    int32_t tResult = 0; 
    
    /* the ulCnfCmd is always: ulReqCmd | 0x01 */
    uint32_t ulCnfCmd = ptSendPkt->tHeader.ulCmd | 0x01;  
    printf("send============\n");
    printPktHeader((TLR_PACKET_HEADER_T*) &ptSendPkt->tHeader);
    printf("================\n");
    /* fire the packet */
    tResult = xChannelPutPacket(dev_info->tCommon.hChannel, ptSendPkt, dev_info->tCommon.ulTimeout);
    if (TLR_S_OK != tResult) {
        return tResult;
    }
    
    /* ok, at this point we have successfully sent a packet */
    
    while(CIFX_NO_ERROR == (tResult = xChannelGetPacket(dev_info->tCommon.hChannel, sizeof(*ptRecvPkt), ptRecvPkt, dev_info->tCommon.ulTimeout))) {
    /* check for our packet */
    if(ptRecvPkt->tHeader.ulCmd == ulCnfCmd) {
      /* it is our packet, so return its status as result */
      tResult = ptRecvPkt->tHeader.ulState;
      printf("recv============\n");
	  printPktHeader((TLR_PACKET_HEADER_T*) &ptRecvPkt->tHeader);
	  printf("================\n");
      /* Note: we also return the packet which we have received (by reference, see signature of function) */

      /* we have received our packet, so we can break here */
      break;
    } else {
      /* it is something else, so place it in the application packet handler */
      ECS_HandlePacket(dev_info, ptRecvPkt);
    }
    }	  
    return tResult;
}

int32_t ECS_SendRecvEmptyPkt(ECS_device_info_t* dev_info, uint32_t ulCmd) {
	/* return value of function */	
	int32_t tResult = TLR_S_OK;

	/* packets for sending and receiving */
	CIFX_PACKET tSendPkt = {{0}};
	CIFX_PACKET tRecvPkt = {{0}};

	/* all register packets are empty packet, */
	/* which means that they contain no data, */
	/* so a cast to a specific type is not necessary */
	TLR_EMPTY_PACKET_T* ptReq = (TLR_EMPTY_PACKET_T*) &tSendPkt;

	/* ulSrc and ulDest are set by GetPacket / SendPacket */
	ptReq->tHead.ulCmd    = ulCmd;
	ptReq->tHead.ulDest   = 0x20;
	ptReq->tHead.ulDestId = 0;
	ptReq->tHead.ulExt    = 0;
	ptReq->tHead.ulId     = 0;
	ptReq->tHead.ulLen    = 0;
	ptReq->tHead.ulRout   = 0;
	ptReq->tHead.ulSrc    = 0;
	ptReq->tHead.ulSrcId  = 0;
	ptReq->tHead.ulSta    = 0;

	tResult = ECS_SendRecvPkt(dev_info, &tSendPkt, &tRecvPkt);
	if (TLR_S_OK != tResult) {
    	return tResult;
  	}

	return tResult;
}

void ECS_HandlePacket(ECS_device_info_t* dev_info, CIFX_PACKET* ptPacket) {
    TLR_PACKET_HEADER_T* ptPck = (TLR_PACKET_HEADER_T*)ptPacket;
    CIFX_PACKET tSendPkt = {{0}};
    CIFX_PACKET tRecvPkt = {{0}};
    uint32_t tResult;
    /* convert to specific application */
    RCX_LINK_STATUS_CHANGE_IND_T        *rcxPacket     = (RCX_LINK_STATUS_CHANGE_IND_T*)ptPacket;
    ECAT_ESM_ALSTATUS_CHANGED_IND_T     *esmStatPacket = (ECAT_ESM_ALSTATUS_CHANGED_IND_T*)ptPacket;
    ECAT_ESM_ALCONTROL_CHANGED_IND_T    *esmCtrlPacket = (ECAT_ESM_ALCONTROL_CHANGED_IND_T*)ptPacket;
    switch(ptPck->ulCmd) {
        case ECAT_ESM_ALCONTROL_CHANGED_IND:
            printf("********************************\n");
	        printf("RECV ECAT_ESM_ALCONTROL_CHANGED_IND\n");
	        printPktHeader((TLR_PACKET_HEADER_T*) &ptPacket->tHeader);
	        printf("esm state     = %u\n", esmCtrlPacket->tData.tAlControl.uState);
	        printf("esm fAck      = %u\n", esmCtrlPacket->tData.tAlControl.fAcknowledge);
	        printf("esm errLed    = %x\n", esmCtrlPacket->tData.usErrorLed);
	        printf("SyncControl   = %x\n", esmCtrlPacket->tData.usSyncControl);
	        printf("SyncimpulseLen= %u ns\n", (uint32_t)esmCtrlPacket->tData.usSyncImpulseLength*10);
	        printf("Sync0CycleTime= %u ns\n", (uint32_t)esmCtrlPacket->tData.ulSync0CycleTime);
	        printf("Sync1CycleTime= %u ns\n", (uint32_t)esmCtrlPacket->tData.ulSync1CycleTime);
	        printf("SyncPdiConfig = %x\n", esmCtrlPacket->tData.bSyncPdiConfig);
	        printf("********************************\n");
            HandleAlControlChangedRequest(dev_info, (ECAT_ESM_ALCONTROL_CHANGED_IND_T*)ptPacket);
            break;

        case ECAT_ESM_ALSTATUS_CHANGED_IND:
	        printf("********************************\n");
	        printf("RECV ECAT_ESM_ALSTATUS_CHANGED_IND\n");
	        printPktHeader((TLR_PACKET_HEADER_T*) &ptPacket->tHeader);
	        printf("esm state   = %u\n", (uint32_t)esmStatPacket->tData.tAlStatus.uState);
	        printf("esm fchange = %u\n", (uint32_t)esmStatPacket->tData.tAlStatus.fChange);
	        dev_info->tCommon.esmState = esmStatPacket->tData.tAlStatus.uState;
            printf("********************************\n");
            HandleAlStatusChangedIndication(dev_info, (ECAT_ESM_ALSTATUS_CHANGED_IND_T*)ptPacket);
            break;
	    
        case RCX_LINK_STATUS_CHANGE_IND:
	        printf("********************************\n");
	        printf("RECV RCX_LINK_STATUS_CHANGE_IND\n");
	        printPktHeader((TLR_PACKET_HEADER_T*) &ptPacket->tHeader);
	        printf("ulPort1       = %x\n",rcxPacket->tData.atLinkData[0].ulPort);
	        printf("fIsFullDuplex1= %u\n",(uint32_t)rcxPacket->tData.atLinkData[0].fIsFullDuplex);
	        printf("fIsLinkUp1    = %u\n",(uint32_t)rcxPacket->tData.atLinkData[0].fIsLinkUp);
	        printf("ulspeed1      = %u\n",(uint32_t)rcxPacket->tData.atLinkData[0].ulSpeed);
	        printf("ulPort2       = %x\n",rcxPacket->tData.atLinkData[1].ulPort);
	        printf("fIsFullDuplex2= %u\n",(uint32_t)rcxPacket->tData.atLinkData[1].fIsFullDuplex);
	        printf("fIsLinkUp2    = %u\n",(uint32_t)rcxPacket->tData.atLinkData[1].fIsLinkUp);
	        printf("ulspeed2      = %u\n",(uint32_t)rcxPacket->tData.atLinkData[1].ulSpeed);
	        printf("********************************\n");
	        HandleRcxLinkChangedIndication(dev_info, (RCX_LINK_STATUS_CHANGE_IND_T*)ptPacket);
            break;
		case ESM_ALSTATUS_OPERATIONAL_IND:
			printf("state change to OP!\n");
			dev_info->tCommon.esmState = 0x0008;
			break;
		case ESM_ALSTATUS_SAFE_OPERATIONAL_IND:
			printf("state change to SAFEOP!\n");
			dev_info->tCommon.esmState = 0x0004;
			break;
		case ESM_ALSTATUS_PRE_OPERATIONAL_IND:
			printf("state change to PREOP!\n");
			dev_info->tCommon.esmState = 0x0002;
			break;
		case  ESM_ALSTATUS_INIT_IND:
			printf("state change to INIT!\n");
			dev_info->tCommon.esmState = 0x0001;
			break;
    default:
	        printf("********************************\n");
            printf("RECV Unknown packet. ulCmd=0x%x\n", ptPacket->tHeader.ulCmd);
	        printPktHeader((TLR_PACKET_HEADER_T*) &ptPacket->tHeader);
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	        printf("********************************\n");
            break;
    }
}

void HandleAlStatusChangedIndication(ECS_device_info_t*  dev_info, ECAT_ESM_ALSTATUS_CHANGED_IND_T* ptAlStatusInd) {
    /* do not care, just cast and respond */    
    /* currently no further actions needed */
    ECAT_ESM_ALSTATUS_CHANGED_RES_T* ptAlStatusRes = (ECAT_ESM_ALSTATUS_CHANGED_RES_T*)ptAlStatusInd;
    
    /* fill packet header */
    ptAlStatusRes->tHead.ulCmd  |= 0x01;
    ptAlStatusRes->tHead.ulSta  = TLR_S_OK;
    ptAlStatusRes->tHead.ulLen  = 0;

    printf("********************************\n");
    printf("SEND ECAT_ESM_ALSTATUS_CHANGED_RES\n");
    printPktHeader((TLR_PACKET_HEADER_T*) &ptAlStatusRes->tHead);
    printf("********************************\n");
    /* return to sender */
    xChannelPutPacket(dev_info->tCommon.hChannel, (CIFX_PACKET*)ptAlStatusRes, dev_info->tCommon.ulTimeout);
}

void HandleRcxLinkChangedIndication(ECS_device_info_t*  dev_info, RCX_LINK_STATUS_CHANGE_IND_T* ptRcxLinkInd) {
    /* do not care, just cast and respond */
    /* currently no further actions needed */
    RCX_LINK_STATUS_CHANGE_RES_T* ptRcxLinkRes = (RCX_LINK_STATUS_CHANGE_RES_T*) ptRcxLinkInd;

    /* fill packet header */ 
    ptRcxLinkRes->tHead.ulCmd  |= 0x01;
    ptRcxLinkRes->tHead.ulSta  = TLR_S_OK;
    ptRcxLinkRes->tHead.ulLen  = 0;

    printf("********************************\n");
    printf("SEND ECAT_RCX_LINK_STATUS_CHANGED_RES\n");
    printPktHeader((TLR_PACKET_HEADER_T*) &ptRcxLinkRes->tHead);
    printf("********************************\n");
    /* return to sender */
    xChannelPutPacket(dev_info->tCommon.hChannel, (CIFX_PACKET*)ptRcxLinkRes, dev_info->tCommon.ulTimeout);
}

void HandleAlControlChangedRequest(ECS_device_info_t*  dev_info, ECAT_ESM_ALCONTROL_CHANGED_IND_T* ptAlControlInd) {
	/* variable for result values */
	uint32_t tResult = TLR_S_OK;

	/* packets for sending and receiving */
	CIFX_PACKET tSendPkt = {{0}};
	CIFX_PACKET tRecvPkt = {{0}};

	/* casts to specific packets */
	ECAT_ESM_SET_ALSTATUS_REQ_T* ptAlStatusReq  = (ECAT_ESM_SET_ALSTATUS_REQ_T*) &tSendPkt;  

	/* we allow all requested state changes */
	switch(ptAlControlInd->tData.tAlControl.uState)	{
		/* Init->PreOp */
		case ECAT_AL_STATE_PRE_OPERATIONAL:
			printf("INIT -> PREOP\n");
      		/* fill packet header */
      		ptAlStatusReq->tHead.ulCmd     = ECAT_ESM_SET_ALSTATUS_REQ;
      		ptAlStatusReq->tHead.ulSta     = TLR_S_OK;
      		ptAlStatusReq->tHead.ulLen     = sizeof(ptAlStatusReq->tData);
      		ptAlStatusReq->tHead.ulExt     = 0;
      		ptAlStatusReq->tHead.ulSrc     = 0;
      		ptAlStatusReq->tHead.ulSrcId   = 0;
      		ptAlStatusReq->tHead.ulDest    = 0x20;
      		ptAlStatusReq->tHead.ulDestId  = 0;
      		ptAlStatusReq->tHead.ulRout    = 0;
    
      		/* fill data part of packet */
      		ptAlStatusReq->tData.bAlStatus      = ECAT_AL_STATE_PRE_OPERATIONAL;
      		ptAlStatusReq->tData.bErrorLedState = 0; /* TODO: handle LED if necessary */
      		ptAlStatusReq->tData.usAlStatusCode = 0;

      		/* send packet */
      		tResult = ECS_SendRecvPkt(dev_info, &tSendPkt, &tRecvPkt);
      		break;

    	/* PreOp->SafeOp */
    	case ECAT_AL_STATE_SAFE_OPERATIONAL:
	  		printf("PREOP -> SafeOp\n");
      		/* fill packet header */
      		ptAlStatusReq->tHead.ulCmd     = ECAT_ESM_SET_ALSTATUS_REQ;
      		ptAlStatusReq->tHead.ulSta     = TLR_S_OK;
      		ptAlStatusReq->tHead.ulLen     = sizeof(ptAlStatusReq->tData);
      		ptAlStatusReq->tHead.ulExt     = 0;
      		ptAlStatusReq->tHead.ulSrc     = 0;
      		ptAlStatusReq->tHead.ulSrcId   = 0;
      		ptAlStatusReq->tHead.ulDest    = 0x20;
      		ptAlStatusReq->tHead.ulDestId  = 0;
      		ptAlStatusReq->tHead.ulRout    = 0;

      		/* fill data part of packet */
      		ptAlStatusReq->tData.bAlStatus      = ECAT_AL_STATE_SAFE_OPERATIONAL;
      		ptAlStatusReq->tData.bErrorLedState = 0; /* TODO: handle LED if necessary */
      		ptAlStatusReq->tData.usAlStatusCode = 0;

      		/* send packet */
      		tResult = ECS_SendRecvPkt(dev_info, &tSendPkt, &tRecvPkt);
      		break;

    	/* SafeOp->Op */
    	case ECAT_AL_STATE_OPERATIONAL:
	  		printf("SafeOP -> OP\n");
      		/* fill packet header */
      		ptAlStatusReq->tHead.ulCmd     = ECAT_ESM_SET_ALSTATUS_REQ;
      		ptAlStatusReq->tHead.ulSta     = TLR_S_OK;
      		ptAlStatusReq->tHead.ulLen     = sizeof(ptAlStatusReq->tData);
      		ptAlStatusReq->tHead.ulExt     = 0;
      		ptAlStatusReq->tHead.ulSrc     = 0;
      		ptAlStatusReq->tHead.ulSrcId   = 0;
      		ptAlStatusReq->tHead.ulDest    = 0x20;
      		ptAlStatusReq->tHead.ulDestId  = 0;
      		ptAlStatusReq->tHead.ulRout    = ptAlControlInd->tHead.ulRout;

      		/* fill data part of packet */
      		ptAlStatusReq->tData.bAlStatus      = ECAT_AL_STATE_OPERATIONAL;
      		ptAlStatusReq->tData.bErrorLedState = 0; /* TODO: handle LED if necessary */
      		ptAlStatusReq->tData.usAlStatusCode = 0;

      		/* send packet */
      		tResult = ECS_SendRecvPkt(dev_info, &tSendPkt, &tRecvPkt);
      		break;

    	/* unknown state */
    	default:
      		tResult = TLR_E_FAIL;
      		break;
	}

  /* recycle the ind, generate res and reply it */
  ptAlControlInd->tHead.ulCmd |= 0x01;
  ptAlControlInd->tHead.ulLen  = 0x00;
  ptAlControlInd->tHead.ulSta  = tResult;

  /* send packet */
  xChannelPutPacket(dev_info->tCommon.hChannel, (CIFX_PACKET*)ptAlControlInd, dev_info->tCommon.ulTimeout);
}

int ECS_data_recv(void *priv_data, uint8_t *rx_buff, uint32_t buff_size) {
	int32_t tResult = 0;	
	ECS_device_info_t* dev_info = (ECS_device_info_t*) priv_data;
	
	tResult = xChannelGetPacket(dev_info->tCommon.hChannel, sizeof(CIFX_PACKET), &dev_info->tRecvPkt, 5);
	/* check if we have really received a packet or an error code */
    if (TLR_S_OK == tResult) {
       /* signalize if we got a packet*/
       printf("-%d ",dev_info->tCommon.esmState);    
       /* handle packets */
       ECS_HandlePacket(dev_info, &dev_info->tRecvPkt);
	}
	
	/*recv data IO*/
	if (dev_info->tCommon.esmState ==0x0008) {
		tResult = xChannelIORead(dev_info->tCommon.hChannel, 0, 0, dev_info->tCommon.ulCycReadDataSize, dev_info->tCommon.ptCycReadData, 2);
		if ((CIFX_DEV_EXCHANGE_FAILED == tResult) || (CIFX_DEV_EXCHANGE_TIMEOUT == tResult)) {
        	printf("CIFX_DEV_EXCHANGE_FAILED !!!");
    	} else if (CIFX_DEV_NO_COM_FLAG == tResult) {
        	printf("CIFX_DEV_NO_COM_FLAG !!!\n");
    	} else if (CIFX_NO_ERROR == tResult) {
			/* copy readData to recvData */
			memcpy(rx_buff, dev_info->tCommon.ptCycReadData, (size_t) buff_size);
		}
	}
	
	return tResult;
}

int ECS_data_send(void *priv_data, uint8_t *payload, uint32_t frame_len) {
	int32_t tResult = 0;
	ECS_device_info_t* dev_info = (ECS_device_info_t*) priv_data;
	tResult = xChannelGetPacket(dev_info->tCommon.hChannel, sizeof(CIFX_PACKET), &dev_info->tRecvPkt, 5);
	/* check if we have really received a packet or an error code */
    if(TLR_S_OK == tResult) {
       /* signalize if we got a packet*/
       printf("-%d ",dev_info->tCommon.esmState);    
       /* handle packets */
       ECS_HandlePacket(dev_info, &dev_info->tRecvPkt);
	}
	
	/* clear sending buffer*/
	memset(dev_info->tCommon.ptCycWriteData, 0, dev_info->tCommon.ulCycWriteDataSize);
    /* copy data */
	memcpy(dev_info->tCommon.ptCycWriteData, payload, (size_t) frame_len);
	
	if (dev_info->tCommon.esmState ==0x0008) {
		tResult = xChannelIOWrite(dev_info->tCommon.hChannel, 0, 0, dev_info->tCommon.ulCycWriteDataSize, dev_info->tCommon.ptCycWriteData, 2);
		if ((CIFX_DEV_EXCHANGE_FAILED == tResult) || (CIFX_DEV_EXCHANGE_TIMEOUT == tResult)) {
    	    printf("CIFX_DEV_EXCHANGE_FAILED !!!");
    	} else if (CIFX_DEV_NO_COM_FLAG == tResult) {
    	    printf("CIFX_DEV_NO_COM_FLAG !!!\n");
    	}
	}
	return tResult;
}


/* === debug function === */
int32_t printPktHeader( TLR_PACKET_HEADER_T* pthead){
	printf("ulDest      = %x\n", pthead->ulDest);
	printf("ulSrc       = %x\n", pthead->ulSrc);
	printf("ulDestId    = %x\n", pthead->ulDestId);
	printf("ulSrcId     = %x\n", pthead->ulSrc);
	printf("ulLen       = %u\n", pthead->ulLen);
	printf("ulID        = %x\n", pthead->ulId);
	printf("ulSta       = %x\n", pthead->ulSta);
	printf("ulCmd       = %x\n", pthead->ulCmd);
    printf("ulExt       = %u\n", pthead->ulExt);
    printf("ulRout      = %u\n", pthead->ulRout);
    return 0;
}

/* name of the board */
//char* szBoardName = "cifX0";

int32_t ECS_RegistNotification(ECS_device_info_t* dev_info) {
	/* return value of function */
	int32_t tResult = TLR_S_OK;
	printf("Register  Notification\n");

	/* register on EcatEsm task (indications for AL status) */
	tResult = ECS_SendRecvEmptyPkt(dev_info, RCX_REGISTER_APP_REQ);
	if(TLR_S_OK != tResult)	{
    	return tResult;
  	}  
  
    /* register on EcatEsm task for indications if AL control changes 
     * (we want to get involved into the bootup of the slave stack)
     */	
	tResult = ECS_SendRecvEmptyPkt(dev_info, ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_REQ);
	if(TLR_S_OK != tResult) {
		return tResult;
	}
  return tResult;
}

/* Initial function */
int32_t ECS_Init(void **priv_data, char* ifname, int ulChannel ) {	
	/* ECS PARAMETER */
	int32_t tResult = 0;
    /* Driver Handler pointer */
    void *hDriver  = NULL; 
    /* Channel address */
    void *hChannel = NULL;
	/* variable for host state */
    uint32_t ulState = 0;
	/* default timeout for driver api calls */
    uint32_t  ulTimeout   = 100;
	/* common variables for packets */
    CIFX_PACKET  tSendPkt  = {{0}};
    CIFX_PACKET  tRecvPkt  = {{0}};
    CIFX_PACKET* ptRecvPkt = NULL;
	
	/*device information */
	ECS_device_info_t* dev_info = NULL;
	

	tResult  = ECS_CreateResources(priv_data);
	if(CIFX_NO_ERROR !=tResult){
		printf("create resources error\n");	
	}
	dev_info = (ECS_device_info_t*) *priv_data;
    
    /* ECS dev info parameter setting */
	dev_info->tCommon.ulTimeout = ulTimeout;
	dev_info->tCommon.ulCycReadDataSize  = MAX_RTD_SIZE;
    dev_info->tCommon.ulCycWriteDataSize = MAX_RTD_SIZE;
    dev_info->tCommon.esmState = 0;
	/* initial driver */
	printf("Initial driver...\n");
    long lRet = cifXDriverInit(&ptInit);
    if(lRet != CIFX_NO_ERROR) {
	    printf("Driver initial error!\n");
	    return -1;
    }
    printf("Driver initial success!\n");

    /* Open Driver */
    printf("Opening driver card...\n");
    tResult = xDriverOpen(&hDriver);
    if (CIFX_NO_ERROR != tResult) {
        printf("Driver card open fail!!!\n");
        goto CLOSEDRIVER;
    }
    printf("Driver card open success!\n");
    dev_info->tCommon.hDriver = hDriver;
    	
	
    /* Open Channel */
    printf("Opening channel%d...\n",ulChannel);
    tResult = xChannelOpen(hDriver, ifname, ulChannel, &hChannel);
    if (CIFX_NO_ERROR != tResult) {
        printf("channel%d open fail !\n",ulChannel);
        goto CLOSEDRIVER;
    }
    printf("channel %d open success!\n",ulChannel);
    dev_info->tCommon.hChannel = hChannel;

	tResult = xChannelHostState( hChannel, CIFX_HOST_STATE_READ, &ulState, 1000L);
	if (CIFX_NO_ERROR != tResult) {
		printf("read Host state error\n");		
		goto CLOSECHANNEL;	
	}    
    
	printf("setting Host state...\n");	
    tResult = xChannelHostState( hChannel, CIFX_HOST_STATE_READY, NULL, 1000L);
    if (CIFX_NO_ERROR != tResult) {
		printf("set Host state ready error !\n");		
		goto CLOSECHANNEL;	
	}
	printf("set Host state ready success !\n");

	printf("setting Bus state ON...\n");
    tResult = xChannelBusState( hChannel, CIFX_BUS_STATE_ON, NULL, 1000L);
	/*
	if (CIFX_NO_ERROR != tResult && CIFX_DEV_NO_COM_FLAG != tResult) {
		printf("Set Bus state error ! %x hChannel %x\n", tResult, hChannel);		
		goto CLOSECHANNEL;	
	}
	printf("set Bus state ON success !\n");	
	*/


	/* regist cifx notification */
	printf("regist cifx notification ...");
	tResult = ECS_RegistNotification(dev_info);
	if (CIFX_NO_ERROR != tResult && CIFX_DEV_NO_COM_FLAG != tResult) {
		printf("regist cifx notification Error tResult=%x!\n",tResult);
		goto CLOSECHANNEL;
	} 
	printf("regist cifx notification success!\n");

	tResult = xChannelDMAState( hChannel, CIFX_BUS_STATE_OFF, &ulState);
	if (CIFX_NO_ERROR != tResult) {
		printf("close DMA mode error\n");		
		goto CLOSECHANNEL;	
	}
    
	while(dev_info->tCommon.esmState != 0x0008) {
		/* now we do the acyclic stuff*/
		tResult = xChannelGetPacket(hChannel, sizeof(tRecvPkt), &tRecvPkt, 5);
                
        if(TLR_S_OK == tResult) {
        	/* signalize if we got a packet*/
            printf("-%d ",dev_info->tCommon.esmState);    
            /* handle packets */
            ECS_HandlePacket(dev_info, &tRecvPkt);
		}
	}
	
	return 0;

CLOSECHANNEL:
    printf("Closing channel %d...\n",ulChannel);
    tResult = xChannelClose(hChannel);

CLOSEDRIVER:
    printf("Closing Driver...\n");
    tResult = xDriverClose(hDriver);
    printf("Deinit driver...\n");
    cifXDriverDeinit();
	
	return tResult;
}

int32_t ECS_Deinit(void **priv_data) {
    int32_t tResult = 0;
	ECS_device_info_t* dev_info = (ECS_device_info_t*) *priv_data;
    tResult = xChannelClose(dev_info->tCommon.hChannel);
    tResult = xDriverClose(dev_info->tCommon.hDriver);
	ECS_FreeResources(priv_data);
	cifXDriverDeinit();
    return tResult;
}

uint32_t ECS_frame_get_header_size(void *priv_data) {
    return 0;
}

struct icf_driver_ops icf_driver_ecs_ops = {
    .open_interface = ECS_Init,
    .recv_data = ECS_data_recv,
    .send_data = ECS_data_send,

    .get_header_size = ECS_frame_get_header_size,

    .close_interface = ECS_Deinit,
};

