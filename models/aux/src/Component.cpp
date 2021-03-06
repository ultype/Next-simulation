#include "Component.hh"

void ACT_1st::Actuate(double input_command, double int_step) {
  ActRateOutput = (Tau * input_command - Tau * Act_prior_state);
  ActAccOutput = (ActRateOutput - Act_prior_rate) / int_step;

  if (fabs(ActAccOutput) > Ang_acc_limit) {
    if (ActAccOutput > 0) {
      ActAccOutput = Ang_acc_limit;
    } else {
      ActAccOutput = -Ang_acc_limit;
    }
    ActRateOutput = Act_prior_rate + ActAccOutput * int_step;
  }

  if (fabs(ActRateOutput) > Ang_rate_limit) {
    if (ActRateOutput > 0) {
      ActRateOutput = Ang_rate_limit;
    } else {
      ActRateOutput = -Ang_rate_limit;
    }
  }

  ActOuptut = Act_prior_state + ActRateOutput * int_step;
  Act_prior_state = ActOuptut;
  Act_prior_rate = ActRateOutput;

  if (fabs(ActOuptut) > Ang_limit) {
    if (ActOuptut > 0) {
      ActOuptut = Ang_limit;
    } else {
      ActOuptut = -Ang_limit;
    }
  }
}

void ACT_1st::set_1st_act_var(double Ang_limit_in, double Ang_rate_limit_in,
                              double Ang_acc_limit_in, double Tau_in) {
  Ang_limit = Ang_limit_in;
  Ang_rate_limit = Ang_rate_limit_in;
  Ang_acc_limit = Ang_acc_limit_in;
  Tau = Tau_in;
}

void ACT_NO_DYN::Actuate(double input_command, double int_step) {
  ActOuptut = input_command;
}

ENG::ENG()
    : VECTOR_INIT(Q, 6),
      MATRIX_INIT(T_N_B, 3, 3),
      VECTOR_INIT(THRUST, 3),
      VECTOR_INIT(ENG_HINGE_POS, 3),
      VECTOR_INIT(ENG_GAMMA_1, 3),
      VECTOR_INIT(ENG_GAMMA_2, 3),
      VECTOR_INIT(ENG_GAMMA_3, 3),
      VECTOR_INIT(ENG_BETA_4, 3),
      VECTOR_INIT(ENG_BETA_5, 3),
      VECTOR_INIT(ENG_BETA_6, 3) {
  ENG_GAMMA_1(0) = ENG_BETA_4(0) = 1.0;
  ENG_GAMMA_1(1) = ENG_BETA_4(1) = 0.0;
  ENG_GAMMA_1(2) = ENG_BETA_4(2) = 0.0;

  ENG_GAMMA_2(0) = ENG_BETA_5(0) = 0.0;
  ENG_GAMMA_2(1) = ENG_BETA_5(1) = 1.0;
  ENG_GAMMA_2(2) = ENG_BETA_5(2) = 0.0;

  ENG_GAMMA_3(0) = ENG_BETA_6(0) = 0.0;
  ENG_GAMMA_3(1) = ENG_BETA_6(1) = 0.0;
  ENG_GAMMA_3(2) = ENG_BETA_6(2) = 1.0;
}

void ENG::set_ENG_HINGE_POS(double x, double y, double z) {
  ENG_HINGE_POS(0) = x;
  ENG_HINGE_POS(1) = y;
  ENG_HINGE_POS(2) = z;
}

void ENG::set_ENG_Dir(int type_in) { type = static_cast<EngType>(type_in); }

void ENG::Allocate_Actuator(int NumAct, enum ActDynType TYPE) {
  switch (TYPE) {
    case FIRST: {
      ACT_1st **act_list = new ACT_1st *[NumAct];
      for (int i = 0; i < NumAct; i++) {
        act_list[i] = new ACT_1st;
        Act_list.push_back(act_list[i]);
      }
    } break;
    default:
      break;
  }
}

void ENG::calculate_Q(double input_ang, double thrust_in, arma::mat33 TBI,
                      enum EngType TYPE) {
  THRUST(0) = thrust_in;
  THRUST(1) = 0.0;
  THRUST(2) = 0.0;

  switch (TYPE) {
    case X:
      return;
      break;
    case Y:
      T_N_B(0, 0) = cos(input_ang);
      T_N_B(0, 1) = 0.0;
      T_N_B(0, 2) = -sin(input_ang);
      T_N_B(1, 0) = 0.0;
      T_N_B(1, 1) = 1.0;
      T_N_B(1, 2) = 0.0;
      T_N_B(2, 0) = sin(input_ang);
      T_N_B(2, 1) = 0.0;
      T_N_B(2, 2) = cos(input_ang);
      break;
    case Z:
      T_N_B(0, 0) = cos(input_ang);
      T_N_B(0, 1) = sin(input_ang);
      T_N_B(0, 2) = 0.0;
      T_N_B(1, 0) = -sin(input_ang);
      T_N_B(1, 1) = cos(input_ang);
      T_N_B(1, 2) = 0.0;
      T_N_B(2, 0) = 0.0;
      T_N_B(2, 1) = 0.0;
      T_N_B(2, 2) = 1.0;
      break;
    default:
      break;
  }
  Q(0) = dot(trans(TBI) * trans(T_N_B) * THRUST, ENG_GAMMA_1);
  Q(1) = dot(trans(TBI) * trans(T_N_B) * THRUST, ENG_GAMMA_2);
  Q(2) = dot(trans(TBI) * trans(T_N_B) * THRUST, ENG_GAMMA_3);
  Q(3) = dot(trans(TBI) * trans(T_N_B) * THRUST,
             -trans(TBI) * cross_matrix(ENG_HINGE_POS) * ENG_BETA_4);
  Q(4) = dot(trans(TBI) * trans(T_N_B) * THRUST,
             -trans(TBI) * cross_matrix(ENG_HINGE_POS) * ENG_BETA_5);
  Q(5) = dot(trans(TBI) * trans(T_N_B) * THRUST,
             -trans(TBI) * cross_matrix(ENG_HINGE_POS) * ENG_BETA_6);
}

void ENG::calculate_Q(double input_ang_1, double input_ang_2, double thrust_in,
                      arma::mat33 TBI, enum EngType TYPE) {
  THRUST(0) = thrust_in;
  THRUST(1) = 0.0;
  THRUST(2) = 0.0;

  switch (TYPE) {
    case YZ:
      T_N_B(0, 0) = cos(input_ang_2) * cos(input_ang_1);
      T_N_B(0, 1) = cos(input_ang_2) * sin(input_ang_1);
      T_N_B(0, 2) = -sin(input_ang_2);
      T_N_B(1, 0) = -sin(input_ang_1);
      T_N_B(1, 1) = cos(input_ang_1);
      T_N_B(1, 2) = 0.0;
      T_N_B(2, 0) = sin(input_ang_2) * cos(input_ang_1);
      T_N_B(2, 1) = sin(input_ang_2) * sin(input_ang_1);
      T_N_B(2, 2) = cos(input_ang_2);
      break;
    default:
      break;
  }
  Q(0) = dot(trans(TBI) * trans(T_N_B) * THRUST, ENG_GAMMA_1);
  Q(1) = dot(trans(TBI) * trans(T_N_B) * THRUST, ENG_GAMMA_2);
  Q(2) = dot(trans(TBI) * trans(T_N_B) * THRUST, ENG_GAMMA_3);
  Q(3) = dot(trans(TBI) * trans(T_N_B) * THRUST,
             -trans(TBI) * cross_matrix(ENG_HINGE_POS) * ENG_BETA_4);
  Q(4) = dot(trans(TBI) * trans(T_N_B) * THRUST,
             -trans(TBI) * cross_matrix(ENG_HINGE_POS) * ENG_BETA_5);
  Q(5) = dot(trans(TBI) * trans(T_N_B) * THRUST,
             -trans(TBI) * cross_matrix(ENG_HINGE_POS) * ENG_BETA_6);
}