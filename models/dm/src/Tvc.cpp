#include "integrate.hh"
#include "math_utility.hh"

#include "Tvc.hh"
#include "dsp_can_interfaces.h"
#include "sim_services/include/simtime.h"

TVC::TVC(Data_exchang &input) : VECTOR_INIT(Q_TVC, 6) { data_exchang = &input; }

TVC::TVC(const TVC &other) : VECTOR_INIT(Q_TVC, 6) {
  this->data_exchang = other.data_exchang;
  this->S2_Eng_list.assign(other.S2_Eng_list.begin(), other.S2_Eng_list.end());
  for (int i = 0; i < this->S2_Eng_list.size(); i++) {
    this->S2_Eng_list[i]->Act_list.assign(
        other.S2_Eng_list[i]->Act_list.begin(),
        other.S2_Eng_list[i]->Act_list.end());
  }
  this->S3_Eng_list.assign(other.S3_Eng_list.begin(), other.S3_Eng_list.end());
  for (int i = 0; i < this->S3_Eng_list.size(); i++) {
    this->S3_Eng_list[i]->Act_list.assign(
        other.S3_Eng_list[i]->Act_list.begin(),
        other.S3_Eng_list[i]->Act_list.end());
  }
  this->mtvc = other.mtvc;
}

TVC &TVC::operator=(const TVC &other) {
  if (&other == this) return *this;

  this->data_exchang = other.data_exchang;
  this->S2_Eng_list.assign(other.S2_Eng_list.begin(), other.S2_Eng_list.end());
  for (int i = 0; i < this->S2_Eng_list.size(); i++) {
    this->S2_Eng_list[i]->Act_list.assign(
        other.S2_Eng_list[i]->Act_list.begin(),
        other.S2_Eng_list[i]->Act_list.end());
  }
  this->S3_Eng_list.assign(other.S3_Eng_list.begin(), other.S3_Eng_list.end());
  for (int i = 0; i < this->S3_Eng_list.size(); i++) {
    this->S3_Eng_list[i]->Act_list.assign(
        other.S3_Eng_list[i]->Act_list.begin(),
        other.S3_Eng_list[i]->Act_list.end());
  }
  this->mtvc = other.mtvc;
  return *this;
}

void TVC::default_data() {}

void TVC::init() {}

void TVC::Allocate_ENG(int NumEng, std::vector<ENG *> &Eng_list) {
  ENG **ENG_list = new ENG *[NumEng];
  for (int i = 0; i < NumEng; i++) {
    ENG_list[i] = new ENG;
    Eng_list.push_back(ENG_list[i]);
  }
}

void TVC::algorithm(double int_step) {
  // input from other modules
  theta_a_cmd = grab_theta_a_cmd();
  theta_b_cmd = grab_theta_b_cmd();
  theta_c_cmd = grab_theta_c_cmd();
  theta_d_cmd = grab_theta_d_cmd();
  double thrust;
  arma::mat33 TBI;
  data_exchang->hget("TBI", TBI);
  data_exchang->hget("thrust", &thrust);
  switch (mtvc) {
    case NO_TVC:
      // return if no tvc
      // thrust forces in body axes
      data_exchang->hset("Q_TVC", Q_TVC);
      return;
      break;
    case S2_TVC:
      Q_TVC.zeros();
      S2_Eng_list[0]->Act_list[0]->Actuate(theta_a_cmd, int_step);
      S2_Eng_list[1]->Act_list[0]->Actuate(theta_b_cmd, int_step);
      S2_Eng_list[2]->Act_list[0]->Actuate(theta_c_cmd, int_step);
      S2_Eng_list[3]->Act_list[0]->Actuate(theta_d_cmd, int_step);

      S2_Eng_list[0]->calculate_Q(S2_Eng_list[0]->Act_list[0]->ActOuptut,
                                  thrust / 4., TBI, Z);
      S2_Eng_list[1]->calculate_Q(S2_Eng_list[1]->Act_list[0]->ActOuptut,
                                  thrust / 4., TBI, Y);
      S2_Eng_list[2]->calculate_Q(S2_Eng_list[2]->Act_list[0]->ActOuptut,
                                  thrust / 4., TBI, Z);
      S2_Eng_list[3]->calculate_Q(S2_Eng_list[3]->Act_list[0]->ActOuptut,
                                  thrust / 4., TBI, Y);

      ActOutput1 = S2_Eng_list[0]->Act_list[0]->ActOuptut;
      ActOutput2 = S2_Eng_list[1]->Act_list[0]->ActOuptut;
      ActOutput3 = S2_Eng_list[2]->Act_list[0]->ActOuptut;
      ActOutput4 = S2_Eng_list[3]->Act_list[0]->ActOuptut;

      for (int i = 0; i < S2_Eng_list.size(); i++) {
        Q_TVC += S2_Eng_list[i]->Q;
      }
      data_exchang->hset("Q_TVC", Q_TVC);
      return;
      break;
    case S3_TVC:
      Q_TVC.zeros();
      S3_Eng_list[0]->Act_list[0]->Actuate(theta_a_cmd, int_step);
      S3_Eng_list[0]->Act_list[1]->Actuate(theta_b_cmd, int_step);

      S3_Eng_list[0]->calculate_Q(S3_Eng_list[0]->Act_list[0]->ActOuptut,
                                  S3_Eng_list[0]->Act_list[1]->ActOuptut,
                                  thrust, TBI, YZ);

      ActOutput1 = S3_Eng_list[0]->Act_list[0]->ActOuptut;
      ActOutput2 = S3_Eng_list[0]->Act_list[1]->ActOuptut;

      for (int i = 0; i < S3_Eng_list.size(); i++) {
        Q_TVC += S3_Eng_list[i]->Q;
      }
      data_exchang->hset("Q_TVC", Q_TVC);
      return;
      break;
    default:
      data_exchang->hset("Q_TVC", Q_TVC);
      break;
  }
}

enum TVC::TVC_TYPE TVC::get_mtvc() { return mtvc; }
void TVC::set_mtvc(enum TVC_TYPE in) { mtvc = in; }

void TVC::set_S2_TVC() { this->mtvc = S2_TVC; }

void TVC::set_S3_TVC() { this->mtvc = S3_TVC; }
