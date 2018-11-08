#include "Component.hh"

void ACT_1st::Actuate(double input_command, double int_step) {
    Act_post_rate = (Tau * input_command - Tau * Act_prior_state);
    Act_acc = (Act_post_rate - Act_prior_rate) / int_step;

    if (fabs(Act_acc) > Ang_rate_limit) {
        if (Act_acc > 0) {
            Act_acc = Ang_rate_limit;
        } else {
            Act_acc = -Ang_rate_limit;
        }
        Act_post_rate = Act_prior_rate + Act_acc * int_step;
    }

    if (fabs(Act_post_rate) > Ang_rate_limit) {
        if (Act_post_rate > 0) {
            Act_post_rate = Ang_rate_limit;
        } else {
            Act_post_rate = -Ang_rate_limit;
        }
    }

    Act_post_state = Act_prior_state + Act_post_rate * int_step;
    Act_prior_state = Act_post_state;
    Act_prior_rate = Act_post_rate;

    if (fabs(Act_post_state) > Ang_limit) {
        if (Act_post_state > 0) {
            Act_post_state = Ang_limit;
        } else {
            Act_post_state = -Ang_limit;
        }
    }
}

ENG::ENG(int NumAct)
 :  VECTOR_INIT(THRUST, 3),
    VECTOR_INIT(ENG_HINGE_POS, 3),
    VECTOR_INIT(ENG_GAMMA_1, 3),
    VECTOR_INIT(ENG_GAMMA_2, 3),
    VECTOR_INIT(ENG_GAMMA_3, 3),
    VECTOR_INIT(ENG_BETA_4, 3),
    VECTOR_INIT(ENG_BETA_5, 3),
    VECTOR_INIT(ENG_BETA_6, 3) {
    num_act = NumAct;

    Act_list = new ACT[num_act];

    for (int i = 0; i < num_act; i++) {
        *(Act_list + i) = new ACT_1st;
    }
}

void ENG::calculate_Q(double input_ang, enum ActType TYPE) {
    switch(TYPE) {
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
    Q(3) = dot(trans(TBI) * trans(T_N_B) * THRUST, -trans(TBI) * cross_matrix(ENG_HINGE_POS) * ENG_BETA_4);
    Q(4) = dot(trans(TBI) * trans(T_N_B) * THRUST, -trans(TBI) * cross_matrix(ENG_HINGE_POS) * ENG_BETA_5);
    Q(5) = dot(trans(TBI) * trans(T_N_B) * THRUST, -trans(TBI) * cross_matrix(ENG_HINGE_POS) * ENG_BETA_6);
}