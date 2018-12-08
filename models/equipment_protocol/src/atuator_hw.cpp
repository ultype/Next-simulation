#include "atuator_hw.hh"

static  struct tvc_param_t tvc_no1;
static  struct tvc_param_t tvc_no2;

static int actuator_tvc_range_check(const char *name, struct tvc_param_t *tvc_inst) {
    int rc = ATUATOR_HW_STATUS_SUCCESS;
    if (OUT_RANGE(tvc_inst->pitch_count, -TVC_ROTATION_LIMIT_CNT, TVC_ROTATION_LIMIT_CNT)) {
        fprintf(stderr, "%s.pitch_count: %d\n", name, tvc_inst->pitch_count);
        rc = ATUATOR_HW_STATUS_FAIL;
    }
    if (OUT_RANGE(tvc_inst->yaw_count, -TVC_ROTATION_LIMIT_CNT, TVC_ROTATION_LIMIT_CNT)) {
        fprintf(stderr, "%s.yaw_count: %d\n", name, tvc_inst->yaw_count);
        rc = ATUATOR_HW_STATUS_FAIL;
    }
    return rc;
}

int actuator_tvc_decode_frame(struct can_frame *pframe) {
    struct tvc_param_t *buff = NULL;
    int rc = ATUATOR_HW_STATUS_SUCCESS;
    char which_tvc[8] = {};
    if (pframe == NULL) {
        rc = ATUATOR_HW_STATUS_FAIL;
        goto empty_frame;
    }
    debug_hex_dump("Get from ring", reinterpret_cast<uint8_t *>(pframe), 16);
    switch (pframe->can_id) {
        case FC_to_TVC_II_NO1:
        case FC_to_TVC_III_NO1:
            buff = &tvc_no1;
            snprintf(which_tvc, 8, "TVC_NO1");
            break;
        case FC_to_TVC_II_NO2:
        case FC_to_TVC_III_NO2:
            buff = &tvc_no2;
            snprintf(which_tvc, 8, "TVC_NO2");
            break;
        default:
            fprintf(stderr, "[%d:%s] Unkonw TARGET_ID.\n", __LINE__, __FUNCTION__);
    }
    if (buff == NULL) {
        rc = ATUATOR_HW_STATUS_FAIL;
        goto empty_frame;
    }
    switch (pframe->data[0]) {
        case TVC_MOVEMENT_FAKE:
        case TVC_MOVEMENT_REAL:
        /* TVC no1 pitch_count => theta_a */
        /* TVC no1 yaw_count => theta_b */
        /* TVC no2 pitch_count => theta_c */
        /* TVC no2 yaw_count => theta_d */
            copy_buffer_ntohs(reinterpret_cast<uint16_t *>(&buff->pitch_count), reinterpret_cast<uint8_t *>(&pframe->data[1]));
            copy_buffer_ntohs(reinterpret_cast<uint16_t *>(&buff->yaw_count), reinterpret_cast<uint8_t *>(&pframe->data[3]));
            break;
        default:
            fprintf(stderr, "[%d:%s] Unkonw TASK_ID.\n", __LINE__, __FUNCTION__);
    }
    rc = actuator_tvc_range_check(which_tvc, buff);

empty_frame:
        return rc;
}

void actuator_tvc_cmd2numerical(double *theta_a, double *theta_b, double *theta_c, double *theta_d) {
    *theta_a = tvc_no1.pitch_count * TVC_DSP_RESOLUTION * (PI/180);
    *theta_b = tvc_no1.yaw_count * TVC_DSP_RESOLUTION * (PI/180);
    *theta_c = tvc_no2.pitch_count * TVC_DSP_RESOLUTION * (PI/180);
    *theta_d = tvc_no2.yaw_count * TVC_DSP_RESOLUTION * (PI/180);
}