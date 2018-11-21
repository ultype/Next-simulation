#ifndef EXE_XIL_COMMON_MODIFIED_DATA_GPS_H_
#define EXE_XIL_COMMON_MODIFIED_DATA_GPS_H_

#include "trick/DRAscii.hh"
#include "trick/DataRecordGroup.hh"
#include "trick/data_record_proto.h"

extern "C" void record_gps() {
    Trick::DRAscii *drg = new Trick::DRAscii("ngps");
    drg->set_freq(Trick::DR_Always);
    drg->set_cycle(0.05);
    drg->set_single_prec_only(false);
    drg->add_variable("rkt.dynamics._SBEE[0]");
    drg->add_variable("rkt.dynamics._SBEE[1]");
    drg->add_variable("rkt.dynamics._SBEE[2]");
    drg->add_variable("rkt.dynamics._VBEE[0]");
    drg->add_variable("rkt.dynamics._VBEE[1]");
    drg->add_variable("rkt.dynamics._VBEE[2]");
    drg->add_variable("rkt.dynamics._ABEE[0]");
    drg->add_variable("rkt.dynamics._ABEE[1]");
    drg->add_variable("rkt.dynamics._ABEE[2]");
    // drg->add_variable("rkt.dynamics._SBEE_test[0]");
    // drg->add_variable("rkt.dynamics._SBEE_test[1]");
    // drg->add_variable("rkt.dynamics._SBEE_test[2]");
    // drg->add_variable("rkt.dynamics._VBEE_test[0]");
    // drg->add_variable("rkt.dynamics._VBEE_test[1]");
    // drg->add_variable("rkt.dynamics._VBEE_test[2]");
    // drg->add_variable("rkt.dynamics._ABEE_test[0]");
    // drg->add_variable("rkt.dynamics._ABEE_test[1]");
    // drg->add_variable("rkt.dynamics._ABEE_test[2]");
    // drg->add_variable("rkt.time->gpstime.SOW");
    // drg->add_variable("rkt.dynamics._ABIB[0]");
    // drg->add_variable("rkt.dynamics._ABIB[1]");
    // drg->add_variable("rkt.dynamics._ABIB[2]");
    drg->add_variable("rkt.dynamics._FSPB[0]");
    drg->add_variable("rkt.dynamics._FSPB[1]");
    drg->add_variable("rkt.dynamics._FSPB[2]");
    // drg->add_variable("rkt.dynamics._ABID[0]");
    // drg->add_variable("rkt.dynamics._ABID[1]");
    // drg->add_variable("rkt.dynamics._ABID[2]");
    drg->add_variable("rkt.dynamics._VBII[0]");
    drg->add_variable("rkt.dynamics._VBII[1]");
    drg->add_variable("rkt.dynamics._VBII[2]");
    drg->add_variable("rkt.dynamics._SBII[0]");
    drg->add_variable("rkt.dynamics._SBII[1]");
    drg->add_variable("rkt.dynamics._SBII[2]");
    // drg->add_variable("rkt.dynamics.lonx");
    // drg->add_variable("rkt.dynamics.latx");
    // drg->add_variable("rkt.accelerometer->_FSPCB[0]");
    // drg->add_variable("rkt.accelerometer->_FSPCB[1]");
    // drg->add_variable("rkt.accelerometer->_FSPCB[2]");
    // drg->add_variable("rkt.dynamics._ABII[0]");
    // drg->add_variable("rkt.dynamics._ABII[1]");
    // drg->add_variable("rkt.dynamics._ABII[2]");
    drg->add_variable("rkt.dynamics._ABIB[0]");
    drg->add_variable("rkt.dynamics._ABIB[1]");
    drg->add_variable("rkt.dynamics._ABIB[2]");
    // drg->add_variable("rkt.newton._NEXT_ACC[0]");
    // drg->add_variable("rkt.newton._NEXT_ACC[1]");
    // drg->add_variable("rkt.newton._NEXT_ACC[2]");
    // drg->add_variable("rkt.env._GRAVGE[0]");
    // drg->add_variable("rkt.env._GRAVGE[1]");
    // drg->add_variable("rkt.env._GRAVGE[2]");
    // drg->add_variable("rkt.dynamics._WBIBD[0]");
    // drg->add_variable("rkt.dynamics._WBIBD[1]");
    // drg->add_variable("rkt.dynamics._WBIBD[2]");
    // drg->add_variable("rkt.env.wind->_VAED[0]");
    // drg->add_variable("rkt.env.wind->_VAED[1]");
    // drg->add_variable("rkt.env.wind->_VAED[2]");
    drg->add_variable("rkt.sdt->_DELTA_VEL[0]");
    drg->add_variable("rkt.sdt->_DELTA_VEL[1]");
    drg->add_variable("rkt.sdt->_DELTA_VEL[2]");
    drg->add_variable("rkt.sdt->_PHI[0]");
    drg->add_variable("rkt.sdt->_PHI[1]");
    drg->add_variable("rkt.sdt->_PHI[2]");
    // drg->add_variable("rkt.dynamics._NEXT_ACC[0]");
    // drg->add_variable("rkt.dynamics._NEXT_ACC[1]");
    // drg->add_variable("rkt.dynamics._NEXT_ACC[2]");
    drg->add_variable("rkt.propulsion.thrust");
    drg->add_variable("rkt.propulsion.vmass");
    drg->add_variable("rkt.dynamics.phibdx");
    drg->add_variable("rkt.dynamics.thtbdx");
    drg->add_variable("rkt.dynamics.psibdx");
    // drg->add_variable("rkt.dynamics.alphax");
    // drg->add_variable("rkt.dynamics.alppx");
    // drg->add_variable("rkt.env.vmach");
    // drg->add_variable("rkt.kinematics.alppx");
    // drg->add_variable("rkt.dynamics._thtvdx");
    // drg->add_variable("rkt.dynamics.alphax");
    // drg->add_variable("rkt.dynamics.liftoff");
    // drg->add_variable("rkt.env.wind->_VAED[0]");
    // drg->add_variable("rkt.env.wind->_VAED[1]");
    // drg->add_variable("rkt.env.wind->_VAED[2]");
    // drg->add_variable("rkt.dynamics._VBAB[0]");
    // drg->add_variable("rkt.dynamics._VBAB[1]");
    // drg->add_variable("rkt.dynamics._VBAB[2]");
    drg->add_variable("rkt.dynamics.lonx");
    drg->add_variable("rkt.dynamics.latx");
    drg->add_variable("rkt.dynamics.alt");
    // drg->add_variable("rkt.aerodynamics.cn");
    // drg->add_variable("rkt.aerodynamics.ca");
    // drg->add_variable("rkt.aerodynamics.ca_on");
    // drg->add_variable("rkt.aerodynamics.cl");
    // drg->add_variable("rkt.aerodynamics.cnq");
    // drg->add_variable("rkt.aerodynamics.cmq");
    // drg->add_variable("rkt.aerodynamics._xcp[0]");
    // drg->add_variable("rkt.aerodynamics.clm");
    // drg->add_variable("rkt.aerodynamics.cln");
    // drg->add_variable("rkt.env.vmach");
    // drg->add_variable("rkt.aerodynamics.xcp");
    // drg->add_variable("rkt.aerodynamics.clm");
    // drg->add_variable("rkt.aerodynamics.cln");
    drg->add_variable("rkt.propulsion._XCG[0]");
    // drg->add_variable("rkt.propulsion._xcg[1]");
    // drg->add_variable("rkt.propulsion._xcg[2]");
    // drg->add_variable("rkt.propulsion._structure_XCG[0]");
    // drg->add_variable("rkt.propulsion._structure_XCG[1]");
    // drg->add_variable("rkt.propulsion._structure_XCG[2]");
    // drg->add_variable("rkt.propulsion.vmass");
    // drg->add_variable("rkt.propulsion.fmasse");
    // drg->add_variable("rkt.propulsion.fmass0");
    // drg->add_variable("rkt.propulsion.mass_ratio");
    // drg->add_variable("rkt.propulsion._IBBB[0][0]");
    // drg->add_variable("rkt.propulsion._IBBB[1][1]");
    // drg->add_variable("rkt.propulsion._IBBB[2][2]");
    // drg->add_variable("rkt.env.atmosphere->pressure");
    // drg->add_variable("rkt.env.atmosphere->density");
    // drg->add_variable("rkt.env.atmosphere->tempk");
    // drg->add_variable("rkt.env.atmosphere->vsound");
    // drg->add_variable("rkt.env.atmosphere->zu");
    // drg->add_variable("rkt.env.atmosphere->zl");
    // drg->add_variable("rkt.env.atmosphere->ht");
    // drg->add_variable("rkt.env.atmosphere->z");
    // drg->add_variable("rkt.env.atmosphere->g");
    // drg->add_variable("rkt.env.atmosphere->tmb");
    // drg->add_variable("rkt.env.atmosphere->expv");
    // drg->add_variable("rkt.propulsion.thrust");
    // drg->add_variable("rkt.propulsion.fuel_mass");
    // drg->add_variable("rkt.tvc.s2_act1_y1");
    // drg->add_variable("rkt.tvc.lx");
    // drg->add_variable("rkt.tvc._FPB[0]");
    // drg->add_variable("rkt.tvc._FPB[1]");
    // drg->add_variable("rkt.tvc._FPB[2]");
    // drg->add_variable("rkt.tvc._FMPB[0]");
    // drg->add_variable("rkt.tvc._FMPB[1]");
    // drg->add_variable("rkt.tvc._FMPB[2]");
    // drg->add_variable("rkt.tvc.s2_act2_y1");
    // drg->add_variable("rkt.tvc.s2_act3_y1");
    // drg->add_variable("rkt.tvc.s2_act4_y1");
    // drg->add_variable("rkt.tvc.s2_act1_y1_saturation");
    // drg->add_variable("rkt.tvc.s2_act2_y1_saturation");
    // drg->add_variable("rkt.tvc.s2_act3_y1_saturation");
    // drg->add_variable("rkt.tvc.s2_act4_y1_saturation");
    // drg->add_variable("rkt.tvc.s2_act1_y2");
    // drg->add_variable("rkt.tvc.s2_act2_y2");
    // drg->add_variable("rkt.tvc.s2_act3_y2");
    // drg->add_variable("rkt.tvc.s2_act4_y2");
    // drg->add_variable("rkt.tvc.s2_act1_y2_saturation");
    // drg->add_variable("rkt.tvc.s2_act2_y2_saturation");
    // drg->add_variable("rkt.tvc.s2_act3_y2_saturation");
    // drg->add_variable("rkt.tvc.s2_act4_y2_saturation");
    // drg->add_variable("rkt.tvc.s2_act1_rate");
    // drg->add_variable("rkt.tvc.s2_act2_rate");
    // drg->add_variable("rkt.tvc.s2_act3_rate");
    // drg->add_variable("rkt.tvc.s2_act4_rate");
    // drg->add_variable("rkt.tvc.s2_act1_acc");
    // drg->add_variable("rkt.tvc.s2_act2_acc");
    // drg->add_variable("rkt.tvc.s2_act3_acc");
    // drg->add_variable("rkt.tvc.s2_act4_acc");
    // drg->add_variable("rkt.tvc.s2_act1_rate_saturation");
    // drg->add_variable("rkt.tvc.s2_act2_rate_saturation");
    // drg->add_variable("rkt.tvc.s2_act3_rate_saturation");
    // drg->add_variable("rkt.tvc.s2_act4_rate_saturation");
    // drg->add_variable("rkt.tvc.s3_act1_y2_saturation");
    // drg->add_variable("rkt.tvc.s3_act2_y2_saturation");
    // drg->add_variable("rkt.tvc.s3_act3_y2_saturation");
    // drg->add_variable("rkt.tvc.s3_act4_y2_saturation");
    // drg->add_variable("rkt.tvc.s3_act1_rate_saturation");
    // drg->add_variable("rkt.tvc.s3_act3_rate_saturation");
    // drg->add_variable("rkt.tvc.s3_act2_rate_saturation");
    // drg->add_variable("rkt.tvc.s3_act4_rate_saturation");
    // drg->add_variable("rkt.tvc.theta_a_cmd");
    // drg->add_variable("rkt.tvc.theta_b_cmd");
    // drg->add_variable("rkt.tvc.theta_c_cmd");
    // drg->add_variable("rkt.tvc.theta_d_cmd");
    // drg->add_variable("rkt.forces.pendulum_L");
    // drg->add_variable("rkt.forces.slosh_mass");
    // drg->add_variable("rkt.dynamics.ang_slosh_theta");
    // drg->add_variable("rkt.dynamics.ang_slosh_psi");
    // drg->add_variable("rkt.forces.h");
    // drg->add_variable("rkt.gyro->_WBICB[0]");
    // drg->add_variable("rkt.gyro->_WBICB[1]");
    // drg->add_variable("rkt.gyro->_WBICB[2]");
    // drg->add_variable("rkt.dynamics._WBIB[0]");
    // drg->add_variable("rkt.dynamics._WBIB[1]");
    // drg->add_variable("rkt.dynamics._WBIB[2]");
    // drg->add_variable("rkt.forces._FMB[0]");
    // drg->add_variable("rkt.forces._FMB[1]");
    // drg->add_variable("rkt.forces._FMB[2]");
    // drg->add_variable("rkt.env.pdynmc");
    // drg->add_variable("rkt.forces._SLOSH_CG[0]");
    // drg->add_variable("rkt.forces._SLOSH_CG[1]");
    // drg->add_variable("rkt.forces._SLOSH_CG[2]");
    // drg->add_variable("rkt.forces._e1_XCG[0]");
    // drg->add_variable("rkt.forces._e1_XCG[1]");
    // drg->add_variable("rkt.forces._e1_XCG[2]");
    // drg->add_variable("rkt.forces.Q_E1");
    // drg->add_variable("rkt.forces.Q_E2");
    // drg->add_variable("rkt.forces.Q_E3");
    // drg->add_variable("rkt.forces.Q_E4");
    // drg->add_variable("rkt.forces._f_slosh[0]");
    // drg->add_variable("rkt.forces._f_slosh[1]");
    // drg->add_variable("rkt.forces._f_slosh[2]");
    // drg->add_variable("rkt.forces._f_slosh[3]");
    // drg->add_variable("rkt.forces._f_slosh[4]");
    // drg->add_variable("rkt.forces._f_slosh[5]");
    // drg->add_variable("rkt.forces._f_slosh[6]");
    // drg->add_variable("rkt.forces._f[0]");
    // drg->add_variable("rkt.forces._f[1]");
    // drg->add_variable("rkt.forces._f[2]");
    // drg->add_variable("rkt.forces._f[3]");
    // drg->add_variable("rkt.forces._f[4]");
    // drg->add_variable("rkt.forces._f[5]");
    // drg->add_variable("rkt.forces._ddrP_1[0]");
    // drg->add_variable("rkt.forces._ddrP_1[1]");
    // drg->add_variable("rkt.forces._ddrP_1[2]");
    // drg->add_variable("rkt.forces._Q_G_slosh[0]");
    // drg->add_variable("rkt.forces._Q_G_slosh[1]");
    // drg->add_variable("rkt.forces._Q_G_slosh[2]");
    // drg->add_variable("rkt.forces._Q_G_slosh[3]");
    // drg->add_variable("rkt.forces._Q_G_slosh[4]");
    // drg->add_variable("rkt.forces._Q_G_slosh[5]");
    // drg->add_variable("rkt.forces._Q_G_slosh[6]");
    // drg->add_variable("rkt.dynamics._dvbe");
    // drg->add_variable("rkt.propulsion.fuel_flow_rate");
    // drg->add_variable("rkt.propulsion.fmasse");
    // drg->add_variable("rkt.forces._ddrP_sloshB[0]");
    // drg->add_variable("rkt.forces._ddrP_sloshB[1]");
    // drg->add_variable("rkt.forces._ddrP_sloshB[2]");
    // drg->add_variable("rkt.dynamics._ABIB[0]");
    // drg->add_variable("rkt.dynamics._ABIB[1]");
    // drg->add_variable("rkt.dynamics._ABIB[2]");
    // drg->add_variable("rkt.forces.ddang_slosh_theta");
    // drg->add_variable("rkt.forces.ddang_slosh_psi");
    // drg->add_variable("rkt.forces._Q_Aero[0]");
    // drg->add_variable("rkt.forces._Q_Aero[1]");
    // drg->add_variable("rkt.forces._Q_Aero[2]");
    // drg->add_variable("rkt.forces._Q_Aero[3]");
    // drg->add_variable("rkt.forces._Q_Aero[4]");
    // drg->add_variable("rkt.forces._Q_Aero[5]");
    // drg->add_variable("rkt.forces._FAPB[0]");
    // drg->add_variable("rkt.propulsion.S2_E1_mass");
    // drg->add_variable("rkt.forces._Q_G_S2_E[0]");
    // drg->add_variable("rkt.forces._Q_G_S2_E[1]");
    // drg->add_variable("rkt.forces._Q_G_S2_E[2]");
    // drg->add_variable("rkt.forces._Q_G_S2_E[3]");
    // drg->add_variable("rkt.forces._Q_G_S2_E[4]");
    // drg->add_variable("rkt.forces._Q_G_S2_E[5]");
    // drg->add_variable("rkt.forces._Q_G_S2_E[6]");
    // drg->add_variable("rkt.forces._FAPB[1]");
    // drg->add_variable("rkt.forces._FAPB[2]");
    // drg->add_variable("rkt.propulsion.mass_ratio");
    // drg->add_variable("rkt.propulsion.S2_fmasse");
    // drg->add_variable("rkt.propulsion.S3_fmasse");
    // drg->add_variable("rkt.propulsion.S2_timer");
    // drg->add_variable("rkt.propulsion.S3_timer");
    // drg->add_variable("rkt.dynamics._LT_euler[0]");
    // drg->add_variable("rkt.dynamics._LT_euler[1]");
    // drg->add_variable("rkt.dynamics._LT_euler[2]");
    // drg->add_variable("rkt.dynamics._TBLQ[0]");
    // drg->add_variable("rkt.dynamics._TBLQ[1]");
    // drg->add_variable("rkt.dynamics._TBLQ[2]");
    // drg->add_variable("rkt.dynamics._TBLQ[3]");
    // drg->add_variable("rkt.dynamics.Roll");
    // drg->add_variable("rkt.dynamics.Pitch");
    // drg->add_variable("rkt.dynamics.Yaw");
    // drg->add_variable("rkt.tvc._Q_TVC[0]");
    // drg->add_variable("rkt.tvc._Q_TVC[1]");
    // drg->add_variable("rkt.tvc._Q_TVC[2]");
    // drg->add_variable("rkt.tvc._Q_TVC[3]");
    // drg->add_variable("rkt.tvc._Q_TVC[4]");
    // drg->add_variable("rkt.tvc._Q_TVC[5]");
    drg->add_variable("rkt.tvc.ActOutput1");
    drg->add_variable("rkt.tvc.ActOutput2");
    drg->add_variable("rkt.tvc.ActOutput3");
    drg->add_variable("rkt.tvc.ActOutput4");
    // drg->add_variable("rkt.forces.C_c");
    // drg->add_variable("rkt.forces.C_1");
    // drg->add_variable("rkt.forces.Wn");
    // drg->add_variable("rkt.aerodynamics.cx");
    // drg->add_variable("rkt.aerodynamics.cy");
    // drg->add_variable("rkt.aerodynamics.cz");
    add_data_record_group(drg, Trick::DR_Buffer);
    drg->enable();
}

#endif  // EXE_XIL_COMMON_MODIFIED_DATA_GPS_H_
