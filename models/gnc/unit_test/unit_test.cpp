#include "Ins.hh"
#include "Ins_c.h"
#include "Control.hh"
#include "Control_c.h"
#include <iostream>
double loncx = 120.8901527777778;
double latcx = 22.262097222222224;
double altc = 6.0;
//  Rolling  angle of veh wrt geod coord - deg  module kinematics
double phibdcx = 0.0;
//  Pitching angle of veh wrt geod coord - deg  module kinematics
double thtbdcx = 90.0;
//  Yawing   angle of veh wrt geod coord - deg  module kinematics
double psibdcx = 90.0;
//  Initial angle-of-attack   - deg  module newton
double alpha0x = 0;
//  Initial sideslip angle    - deg  module newton
double beta0x = 0;
//  Vehicle geographic speed  - m/s  module newton
double dvbe = 0;
uint32_t gpsupdate  = 0;
unsigned int Year = 2017;
unsigned int DOY = 81;
unsigned int Hour = 2;
unsigned int Min = 0;
unsigned int Sec = 0;

arma::vec3 PHI = {-1.71E-07, 0.000126438, -4.41E-05};
arma::vec3 DELTA_VEL = {0.850612341, -0.001371661, 0.002136415};

/* Stage2 Control Variable Constant */
const double S2_MDOT = 18.54667;
const double S2_FMASS0 = 2782.0;
const double S2_XCG_1 = 5.5404;
const double S2_XCG_0 = 6.9903;
const double S2_ISP = 272.0;
const double S2_MOI_ROLL_0 = 1003.315;
const double S2_MOI_ROLL_1 = 304.448;
const double S2_MOI_PITCH_0 = 22328.316;
const double S2_MOI_PITCH_1 = 14017.096;
const double S2_MOI_YAW_0 = 22326.832;
const double S2_MOI_YAW_1 = 14015.971;
const double S2_KPP = 3.0;
const double S2_KPI = 0.08;
const double S2_KPD = 0.01;
const double S2_KPPP = 9.375;
const double S2_PN = 1000.0;
const double S2_KRP = 3.0;
const double S2_KRI = 0.33;
const double S2_KRD = 0.015;
const double S2_KRPP = 9.375;
const double S2_RN = 1000.0;
const double S2_KYP = 3.0;
const double S2_KYI = 0.08;
const double S2_KYD = 0.01;
const double S2_KYPP = 9.0;
const double S2_YN = 1000.0;
const double S2_KAOAP = 3.0;
const double S2_KAOAI = 0.15;
const double S2_KAOAD = 0.01;
const double S2_KAOAPP = 9.375;
const double S2_AOAN = 1000.0;
const double S2_ROLLCMD = 0.0;
const double S2_PITCHCMD = -1.0;
const double S2_YAWCMD = 0.0;
const double S2_AOACMD = 0.0;
const double S2_REFERENCE_P = -8.55;

int cpp_init(INS *ins, Control *control,time_management *time);
int c_init();

int main(int argc, char *argv[]) {
    INS ins;
    Control control;

    time_management *time = time_management::get_instance();
    INS_alloc();
    cpp_init(&ins, &control, time);
    c_init();


    printf("Error X = %.14f, Error Y = %.14f, Error Z = %.14f\n", ins.get_SBIIC()(0) - gsl_vector_get(SBIIC, 0)
            , ins.get_SBIIC()(1) - gsl_vector_get(SBIIC, 1), ins.get_SBIIC()(2) - gsl_vector_get(SBIIC, 2));
    printf("Error VX = %.14f, Error VY = %.14f, Error VZ = %.14f\n", ins.get_VBIIC()(0) - gsl_vector_get(VBIIC, 0)
            , ins.get_VBIIC()(1) - gsl_vector_get(VBIIC, 1), ins.get_VBIIC()(2) - gsl_vector_get(VBIIC, 2));
        printf("--------------------\n");
    for (int i = 0; i <= 200000; i++){
        time->dm_time(0.05);
        time_add(0.05, &gpstime);
        ins.update(0.05);
        // printf("CPP -> SBIIC X: %.10f  SBIIC Y: %.10f SBIIC Z: %.10f\n", ins.get_SBIIC()(0), ins.get_SBIIC()(1), ins.get_SBIIC()(2));
        
        INS_update(0.05, &dvbec, liftoff, &alphacx, &betacx,
                &alppcx, &phipcx, &loncx, &latcx, &altc, &psivdcx, &thtvdcx,
                &phibdcx, &thtbdcx, &psibdcx,
                PHI_C, DELTA_VEL_C,
                PHI_HIGH_C, PHI_LOW_C, gpstime, TEIC,
                SBIIC, VBIIC, VBIIC_old,GRAVGI, TBIC, SBEEC,
                VBEEC, WEII, TLI, TDCI,
                TBICI, TBDC, TBDCQ);
        
        // for (int i = 0; i < 3; i++) {
        //     for(int j = 0; j < 3; j++) {
        //         printf("%f ",ins.get_TEIC()(i, j) - gsl_matrix_get(TEIC, i, j));
        //     }
        //     printf("\n"); 
        // }
        // printf("C -> SBIIC X: %.10f  SBIIC Y: %.10f SBIIC Z: %.10f\n", gsl_vector_get(SBIIC, 0), gsl_vector_get(SBIIC, 1), gsl_vector_get(SBIIC, 2));
    }
    printf("Error X = %.14f, Error Y = %.14f, Error Z = %.14f\n", ins.get_SBIIC()(0) - gsl_vector_get(SBIIC, 0)
            , ins.get_SBIIC()(1) - gsl_vector_get(SBIIC, 1), ins.get_SBIIC()(2) - gsl_vector_get(SBIIC, 2));
    printf("Error VX = %.14f, Error VY = %.14f, Error VZ = %.14f\n", ins.get_VBIIC()(0) - gsl_vector_get(VBIIC, 0)
            , ins.get_VBIIC()(1) - gsl_vector_get(VBIIC, 1), ins.get_VBIIC()(2) - gsl_vector_get(VBIIC, 2));
    printf("Error GPS Week = %d, Error GPS SOW = %.14f\n", time->get_gpstime().get_week() - gpstime.week, time->get_gpstime().get_SOW() - gpstime.SOW);
    printf("--------------------\n");
    
    return 0;
}

int cpp_init(INS *ins, Control *control, time_management *time) {
    time->load_start_time(Year, DOY, Hour, Min, Sec);
    ins->load_location(loncx, latcx, altc);
    ins->load_angle(psibdcx, phibdcx, thtbdcx);
    ins->load_geodetic_velocity(alpha0x, beta0x, dvbe);
    ins->set_ideal();
    //  fc->ins.set_non_ideal();
    ins->set_gps_correction(gpsupdate);
    ins->initialize();

    ins->grab_PHI = []()->arma::vec3 { return PHI; };
    ins->grab_DELTA_VEL = []()->arma::vec3 { return DELTA_VEL; };

    control->set_controller_var(S2_MDOT, S2_FMASS0, S2_XCG_1, S2_XCG_0, S2_ISP, 0.0);
    control->set_IBBB0(S2_MOI_ROLL_0, S2_MOI_PITCH_0, S2_MOI_YAW_0);
    control->set_IBBB1(S2_MOI_ROLL_1, S2_MOI_PITCH_1, S2_MOI_YAW_1);
    control->set_attcmd(S2_ROLLCMD, S2_PITCHCMD, S2_YAWCMD);
    control->set_aoacmd(S2_AOACMD);
    control->get_control_gain(S2_KPP, S2_KPI, S2_KPD, S2_KPPP, S2_PN, S2_KRP, S2_KRI, S2_KRD,
                         S2_KRPP, S2_RN, S2_KYP, S2_KYI, S2_KYD, S2_KYPP, S2_YN, S2_KAOAP, S2_KAOAI, S2_KAOAD, S2_KAOAPP, S2_AOAN);
    control->set_reference_point(S2_REFERENCE_P);
    control->set_engine_d(0.425);

    std::cout << "CPP->SBIIC[0]: " << ins->get_SBIIC()(0) << "SBIIC[1]: " << ins->get_SBIIC()(1) << "SBIIC[2]: " << ins->get_SBIIC()(2) << std::endl;
    return 0;
}

int c_init() {
    INS_init(gpstime);

    load_start_time(Year, DOY, Hour, Min, Sec, &utctime, &gpstime);
    load_location(loncx, latcx, altc);
    load_angle(psibdcx, phibdcx, thtbdcx, gpstime);
    load_geodetic_velocity(alpha0x, beta0x, dvbe);

    gsl_vector_set(PHI_C, 0, -1.71E-07);
    gsl_vector_set(PHI_C, 1, 0.000126438);
    gsl_vector_set(PHI_C, 2, -4.41E-05);
    gsl_vector_set(DELTA_VEL_C, 0, 0.850612341);
    gsl_vector_set(DELTA_VEL_C, 1, -0.001371661);
    gsl_vector_set(DELTA_VEL_C, 2, 0.002136415);

    printf("C->SBIIC[0]: %f, SBIIC[1]: %f, SBIIC[2]: %f\n", gsl_vector_get(SBIIC, 0), gsl_vector_get(SBIIC, 1), gsl_vector_get(SBIIC, 2));
    return 0;
}
