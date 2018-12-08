#ifndef MODELS_EQUIPMENT_PROTOCOL_INCLUDE_ATUATOR_HW_H_
#define MODELS_EQUIPMENT_PROTOCOL_INCLUDE_ATUATOR_HW_H_
/********************************* TRICK HEADER *******************************
PURPOSE:
      SDT GPSR
LIBRARY DEPENDENCY:
      (
        (../src/atuator_hw.cpp)
      )
PROGRAMMERS:
      (((Dung-Ru Tsai) () () () ))
*******************************************************************************/
#include <stdint.h>
#include "icf_trx_ctrl.h"
#include "global_constants.hh"
struct tvc_param_t {
    int valid;
    int16_t pitch_count;
    int16_t yaw_count;
};

typedef enum _ENUM_ATUATOR_HW_STATUS {
    ATUATOR_HW_STATUS_FAIL = -1,
    ATUATOR_HW_STATUS_SUCCESS = 0
}ENUM_ATUATOR_HW_STATUS;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declare */
int actuator_tvc_decode_frame(struct can_frame *pframe);
void actuator_tvc_cmd2numerical(double *theta_a, double *theta_b, double *theta_c, double *theta_d);
#ifdef __cplusplus
}
#endif

#endif  //  MODELS_EQUIPMENT_PROTOCOL_INCLUDE_SDT_IMU_H_
