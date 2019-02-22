/* application header */
#include "icf_trx_ctrl.h"
#include <time.h>
void wait(int period);

int main(int argc, void* argv[]) { 
	int32_t tResult;	
	uint8_t sendData[200];
	uint8_t recvData[200];
	int64_t i = 0;
	
	struct icf_ctrlblk_t ctrlblk;	
	icf_ctrlblk_init(&ctrlblk, ICF_SYSTEM_TYPE_ECAT_EGSE);

	printf("init ok!!!!\n");
	if(tResult != 0){
		return 0;
	}
	
	memset(sendData,0,200);
	memset(recvData,0,200);

	while(i<2000) {
			icf_rx_ctrl_job(&ctrlblk, HW_PORTA, 200);
			icf_rx_dequeue(&ctrlblk, EGSE_FC_ECS_RX_SW_QIDX, recvData, 4);
			printf("recv Data\n");
			printf("%5d %5d %5d %5d\n", recvData[0], recvData[1], recvData[2], recvData[3]);
			printf("=================================\n");
			
			sendData[0] = (sendData[0]+1)%256;
			sendData[1] = (sendData[1]+1)%256;
			sendData[2] = (sendData[2]+1)%256;
			sendData[3] = (sendData[3]+1)%256;
			
			icf_tx_enqueue(&ctrlblk, EGSE_FC_ECS_TX_SW_QIDX, sendData, 4);
			icf_tx_ctrl_job(&ctrlblk, EGSE_FC_ECS_TX_SW_QIDX);
			
			printf("send Data\n");
			printf("%5d %5d %5d %5d\n", sendData[0], sendData[1], sendData[2], sendData[3]);
			printf("=================================\n");
			i++;
			wait(20);
	}

	icf_ctrlblk_deinit(&ctrlblk, ICF_SYSTEM_TYPE_ECAT_EGSE);
  return 0;
}


void wait(int period){ //msa
	static struct timespec ts;
	uint32_t milli_prev;
	uint32_t milli_now;
	
	clock_gettime(CLOCK_MONOTONIC, &ts);
	milli_prev = ts.tv_nsec / 1000000;
	milli_now  = ts.tv_nsec / 1000000;
	while(milli_now - milli_prev < period) {
		clock_gettime(CLOCK_MONOTONIC, &ts);
		milli_now  = ts.tv_nsec / 1000000;
	}
}
