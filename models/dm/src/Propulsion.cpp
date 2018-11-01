#include "integrate.hh"

#include "Propulsion.hh"
#include "sim_services/include/simtime.h"

Propulsion::Propulsion(Data_exchang &data_exchang)
    : data_exchang(&data_exchang),
      MATRIX_INIT(IBBB, 3, 3),
      MATRIX_INIT(IBBB0, 3, 3),
      MATRIX_INIT(IBBB1, 3, 3),
      VECTOR_INIT(XCG, 3),
      VECTOR_INIT(XCG_0, 3),
      VECTOR_INIT(XCG_1, 3) {
  this->default_data();
}

Propulsion::Propulsion(const Propulsion& other)
    : data_exchang(other.data_exchang),
      MATRIX_INIT(IBBB, 3, 3),
      VECTOR_INIT(XCG, 3),
      VECTOR_INIT(XCG_0, 3),
      VECTOR_INIT(XCG_1, 3) {
  this->default_data();

  /* Constants */
  this->XCG_0 = other.XCG_0;
  this->XCG_1 = other.XCG_1;
  this->XCG = other.XCG;
  this->IBBB = other.IBBB;
  this->vmass0 = other.vmass0;
  this->vmass = other.vmass;
  this->fmass0 = other.fmass0;
  this->fmasse = other.fmasse;
  this->fmassr = other.fmassr;
  this->fuel_flow_rate = other.fuel_flow_rate;
  this->mass_ratio = other.mass_ratio;
  this->isp = other.isp;
  this->payload_mass = other.payload_mass;
  this->faring_mass = other.faring_mass;
  this->thrust = other.thrust;
  this->aexit = other.aexit;
  this->delta_v = other.delta_v;
  this->thrust_state = other.thrust_state;
  this->stage = other.stage;
  this->Eng_list.assign(other.Eng_list.begin(), other.Eng_list.end());
  this->Stage_var_list.assign(other.Stage_var_list.begin(),
                              other.Stage_var_list.end());
}

Propulsion& Propulsion::operator=(const Propulsion& other) {
  if (&other == this) return *this;

  /* Constants */
  this->XCG_0 = other.XCG_0;
  this->XCG_1 = other.XCG_1;
  this->XCG = other.XCG;
  this->IBBB = other.IBBB;
  this->vmass0 = other.vmass0;
  this->vmass = other.vmass;
  this->fmass0 = other.fmass0;
  this->fmasse = other.fmasse;
  this->fmassr = other.fmassr;
  this->fuel_flow_rate = other.fuel_flow_rate;
  this->mass_ratio = other.mass_ratio;
  this->isp = other.isp;
  this->payload_mass = other.payload_mass;
  this->faring_mass = other.faring_mass;
  this->thrust = other.thrust;
  this->aexit = other.aexit;
  this->delta_v = other.delta_v;
  this->thrust_state = other.thrust_state;
  this->stage = other.stage;
  this->Eng_list.assign(other.Eng_list.begin(), other.Eng_list.end());
  this->Stage_var_list.assign(other.Stage_var_list.begin(),
                              other.Stage_var_list.end());
  this->data_exchang = other.data_exchang;
  return *this;
}

void Propulsion::init() {
  this->IBBB = calculate_IBBB();
  vmass = payload_mass + faring_mass + Stage_var_list[STAGE_2]->structure_mass +
          Stage_var_list[STAGE_2]->propellant_mass +
          Stage_var_list[STAGE_2]->remaining_fuel_mass +
          Stage_var_list[STAGE_3]->structure_mass +
          Stage_var_list[STAGE_3]->propellant_mass +
          Stage_var_list[STAGE_3]->remaining_fuel_mass -
          Stage_var_list[STAGE_2]->fmasse;

  for (int i = 0; i < Stage_var_list.size(); i++) {
    Stage_var_list[i]->timer = 0.0;
  }
}

void Propulsion::default_data() {
  this->thrust = 0;
  this->fmasse = 0;
  this->payload_mass = 0;

  for (int i = 0; i < Eng_list.size(); i++) {
    Eng_list[i] = NULL;
  }

  for (int i = 0; i < Stage_var_list.size(); i++) {
    Stage_var_list[i] = NULL;
  }
}

void Propulsion::set_no_thrust() { this->thrust_state = NO_THRUST; }

void Propulsion::Allocate_stage(unsigned int stage_num) {
  struct STAGE_VAR** stage_var = new STAGE_VAR*[stage_num];
  for (int i = 0; i < stage_num; i++) {
    stage_var[i] = new STAGE_VAR;
    Stage_var_list.push_back(stage_var[i]);
  }
}

void Propulsion::set_stage_var(double isp, double structure_mass,
                               double propellant_mass,
                               double remaining_fuel_mass,
                               unsigned int num_stage) {
  Stage_var_list[num_stage]->isp = isp;
  Stage_var_list[num_stage]->structure_mass = structure_mass;
  Stage_var_list[num_stage]->propellant_mass = propellant_mass;
  Stage_var_list[num_stage]->remaining_fuel_mass = remaining_fuel_mass;
}

void Propulsion::get_input_file_var(double XCG0, double XCG1, double moi_roll0,
                                    double moi_roll1, double moi_pitch0,
                                    double moi_pitch1, double moi_yaw0,
                                    double moi_yaw1, double isp,
                                    double fuel_flow_rate) {
  this->XCG_0(0) = XCG0;
  this->XCG_1(0) = XCG1;
  this->IBBB0(0, 0) = moi_roll0;
  this->IBBB1(0, 0) = moi_roll1;
  this->IBBB0(1, 1) = moi_pitch0;
  this->IBBB1(1, 1) = moi_pitch1;
  this->IBBB0(2, 2) = moi_yaw0;
  this->IBBB1(2, 2) = moi_yaw1;
  this->fuel_flow_rate = fuel_flow_rate;
  this->isp = isp;
  this->fmasse = 0;
}

void Propulsion::engine_ignition() { this->thrust_state = INPUT_THRUST; }

void Propulsion::set_ltg_thrust() { this->thrust_state = LTG_THRUST; }
void Propulsion::set_HOT_STAGE() { this->thrust_state = HOT_STAGE; }
void Propulsion::set_stage_2() { this->stage = STAGE_2; }
void Propulsion::set_stage_3() { this->stage = STAGE_3; }
void Propulsion::set_faring_sep() { this->stage = FARING_SEP; }
void Propulsion::set_faring_mass(double in) { faring_mass = in; }

void Propulsion::algorithm(double int_step) {
  double psl(101300);  // chamber pressure - Pa
  arma::mat33 IBBB0;
  arma::mat33 IBBB1;

  double press;
  data_exchang->hget("press", &press);
  // no thrusting
  switch (this->thrust_state) {
    case NO_THRUST:
      thrust = 0;
      fuel_flow_rate = 0.0;
      switch (this->stage) {
        case STAGE_2:
          mass_ratio = Stage_var_list[STAGE_2]->fmasse / fmass0;
          this->XCG = calculate_XCG();
          this->IBBB = calculate_IBBB();
          vmass = payload_mass + faring_mass +
                  Stage_var_list[STAGE_2]->structure_mass +
                  Stage_var_list[STAGE_2]->propellant_mass +
                  Stage_var_list[STAGE_2]->remaining_fuel_mass +
                  Stage_var_list[STAGE_3]->structure_mass +
                  Stage_var_list[STAGE_3]->propellant_mass +
                  Stage_var_list[STAGE_3]->remaining_fuel_mass -
                  Stage_var_list[STAGE_2]->fmasse;
          break;

        case FARING_SEP:
          mass_ratio = Stage_var_list[STAGE_3]->fmasse / fmass0;
          this->XCG = calculate_XCG();
          this->IBBB = calculate_IBBB();
          vmass = payload_mass + Stage_var_list[STAGE_3]->structure_mass +
                  Stage_var_list[STAGE_3]->propellant_mass +
                  Stage_var_list[STAGE_3]->remaining_fuel_mass -
                  Stage_var_list[STAGE_3]->fmasse;
          break;

        case STAGE_3:
          mass_ratio = Stage_var_list[STAGE_3]->fmasse / fmass0;
          this->XCG = calculate_XCG();
          this->IBBB = calculate_IBBB();
          vmass = payload_mass + Stage_var_list[STAGE_3]->structure_mass +
                  Stage_var_list[STAGE_3]->propellant_mass +
                  Stage_var_list[STAGE_3]->remaining_fuel_mass -
                  Stage_var_list[STAGE_3]->fmasse;
          break;
      }
      break;
    case INPUT_THRUST:
      switch (this->stage) {
        case STAGE_2:
          thrust = proptable.look_up("S2_time_vs_thrust",
                                     Stage_var_list[STAGE_2]->timer, 0) *
                       AGRAV +
                   (-press) * this->aexit;
          fuel_flow_rate =
              proptable.look_up("S2_time_vs_thrust",
                                Stage_var_list[STAGE_2]->timer, 0) /
              Stage_var_list[STAGE_2]->isp;
          // Stage_var_list[STAGE_2]->fmasse += fuel_flow_rate * int_step;
          fuel_expend_integrator(int_step, STAGE_2);
          mass_ratio = Stage_var_list[STAGE_2]->fmasse / fmass0;
          this->XCG = calculate_XCG();
          this->IBBB = calculate_IBBB();
          vmass = payload_mass + faring_mass +
                  Stage_var_list[STAGE_2]->structure_mass +
                  Stage_var_list[STAGE_2]->propellant_mass +
                  Stage_var_list[STAGE_2]->remaining_fuel_mass +
                  Stage_var_list[STAGE_3]->structure_mass +
                  Stage_var_list[STAGE_3]->propellant_mass +
                  Stage_var_list[STAGE_3]->remaining_fuel_mass -
                  Stage_var_list[STAGE_2]->fmasse;
          propagate_delta_v(int_step, Stage_var_list[STAGE_2]->isp,
                            fuel_flow_rate, vmass);
          if (mass_ratio >= 1.0 || fuel_flow_rate < 0.0) {
            this->thrust_state = NO_THRUST;
          }
          Stage_var_list[STAGE_2]->timer =
              Stage_var_list[STAGE_2]->timer + int_step;
          break;

        case FARING_SEP:
          thrust = proptable.look_up("S3_time_vs_thrust",Stage_var_list[STAGE_3]->timer, 0) * AGRAV
                 + (-press) * this->aexit;
          fuel_flow_rate =
              proptable.look_up("S3_time_vs_thrust", Stage_var_list[STAGE_3]->timer, 0)
                / Stage_var_list[STAGE_3]->isp;

          fuel_expend_integrator(int_step, STAGE_3);
          mass_ratio = Stage_var_list[STAGE_3]->fmasse / fmass0;
          this->XCG = calculate_XCG();
          this->IBBB = calculate_IBBB();
          vmass = payload_mass + Stage_var_list[STAGE_3]->structure_mass +
                  Stage_var_list[STAGE_3]->propellant_mass +
                  Stage_var_list[STAGE_3]->remaining_fuel_mass -
                  Stage_var_list[STAGE_3]->fmasse;
          propagate_delta_v(int_step, Stage_var_list[STAGE_3]->isp,
                            fuel_flow_rate, vmass);
          if (mass_ratio >= 1.0 || fuel_flow_rate < 0.0) {
            this->thrust_state = NO_THRUST;
          }
          Stage_var_list[STAGE_3]->timer =
              Stage_var_list[STAGE_3]->timer + int_step;
          break;

        case STAGE_3:
          thrust = proptable.look_up("S3_time_vs_thrust", Stage_var_list[STAGE_3]->timer, 0) * AGRAV 
                + (-press) * this->aexit;
          fuel_flow_rate = proptable.look_up("S3_time_vs_thrust", Stage_var_list[STAGE_3]->timer, 0)
                / Stage_var_list[STAGE_3]->isp;
          fuel_expend_integrator(int_step, STAGE_3);
          mass_ratio = Stage_var_list[STAGE_3]->fmasse / fmass0;
          this->XCG = calculate_XCG();
          this->IBBB = calculate_IBBB();
          vmass = payload_mass + Stage_var_list[STAGE_3]->structure_mass +
                  Stage_var_list[STAGE_3]->propellant_mass +
                  Stage_var_list[STAGE_3]->remaining_fuel_mass + faring_mass -
                  Stage_var_list[STAGE_3]->fmasse;
          propagate_delta_v(int_step, Stage_var_list[STAGE_3]->isp,
                            fuel_flow_rate, vmass);
          if (mass_ratio >= 1.0 || fuel_flow_rate < 0.0) {
            this->thrust_state = NO_THRUST;
          }
          Stage_var_list[STAGE_3]->timer =
              Stage_var_list[STAGE_3]->timer + int_step;
          break;
      }

      break;

    case HOT_STAGE:
      vmass = payload_mass + faring_mass +
              Stage_var_list[STAGE_2]->structure_mass +
              Stage_var_list[STAGE_2]->propellant_mass +
              Stage_var_list[STAGE_2]->remaining_fuel_mass +
              Stage_var_list[STAGE_3]->structure_mass +
              Stage_var_list[STAGE_3]->propellant_mass +
              Stage_var_list[STAGE_3]->remaining_fuel_mass;
      thrust = proptable.look_up("S2_time_vs_thrust", Stage_var_list[STAGE_2]->timer, 0) * AGRAV
             + (-press) * this->aexit;
      fuel_flow_rate = proptable.look_up("S2_time_vs_thrust", Stage_var_list[STAGE_2]->timer, 0)
             / Stage_var_list[STAGE_2]->isp;
      double fuel_flow_rate_hs =
          proptable.look_up("S3_time_vs_thrust", Stage_var_list[STAGE_3]->timer, 0)
           / Stage_var_list[STAGE_3]->isp;
      if (mass_ratio <= 1.0) {
        fuel_expend_integrator(int_step, STAGE_2);
      } else {
        fuel_flow_rate = 0.0;
        thrust = 0.0;
      }
      fuel_expend_integrator(int_step, STAGE_3);
      mass_ratio = Stage_var_list[STAGE_2]->fmasse / fmass0;
      this->XCG = calculate_XCG();
      this->IBBB = calculate_IBBB();
      vmass = payload_mass + faring_mass +
              Stage_var_list[STAGE_2]->structure_mass +
              Stage_var_list[STAGE_2]->propellant_mass +
              Stage_var_list[STAGE_2]->remaining_fuel_mass +
              Stage_var_list[STAGE_3]->structure_mass +
              Stage_var_list[STAGE_3]->propellant_mass +
              Stage_var_list[STAGE_3]->remaining_fuel_mass -
              Stage_var_list[STAGE_2]->fmasse - Stage_var_list[STAGE_3]->fmasse;
      propagate_delta_v(int_step, Stage_var_list[STAGE_2]->isp, fuel_flow_rate,
                        vmass);

      Stage_var_list[STAGE_3]->timer =
          Stage_var_list[STAGE_3]->timer + int_step;
      Stage_var_list[STAGE_2]->timer =
          Stage_var_list[STAGE_2]->timer + int_step;
      break;
  }
  fmasse = Stage_var_list[STAGE_2]->fmasse + Stage_var_list[STAGE_3]->fmasse;
  if (thrust < 0.0) {
    thrust = 0.0;
  }
}

void Propulsion::fuel_expend_integrator(double int_step, enum STAGE flag) {
  double K1, K2, K3, K4;
  switch (flag) {
    case STAGE_2:
      K1 = proptable.look_up("S2_time_vs_thrust", Stage_var_list[STAGE_2]->timer, 0)
        / Stage_var_list[STAGE_2]->isp;
      K2 = proptable.look_up("S2_time_vs_thrust", Stage_var_list[STAGE_2]->timer + 0.5 * int_step, 0)
        / Stage_var_list[STAGE_2]->isp;
      K3 = proptable.look_up("S2_time_vs_thrust", Stage_var_list[STAGE_2]->timer + 0.5 * int_step, 0)
        / Stage_var_list[STAGE_2]->isp;
      K4 = proptable.look_up("S2_time_vs_thrust", Stage_var_list[STAGE_2]->timer + int_step, 0)
        / Stage_var_list[STAGE_2]->isp;

      Stage_var_list[STAGE_2]->fmasse =
          Stage_var_list[STAGE_2]->fmasse +
          (int_step / 6.0) * (K1 + 2.0 * K2 + 2.0 * K3 + K4);
      break;

    case STAGE_3:
      K1 = proptable.look_up("S3_time_vs_thrust", Stage_var_list[STAGE_3]->timer, 0)
           / Stage_var_list[STAGE_3]->isp;
      K2 = proptable.look_up("S3_time_vs_thrust", Stage_var_list[STAGE_3]->timer + 0.5 * int_step, 0)
           / Stage_var_list[STAGE_3]->isp;
      K3 = proptable.look_up("S3_time_vs_thrust", Stage_var_list[STAGE_3]->timer + 0.5 * int_step, 0)
           / Stage_var_list[STAGE_3]->isp;
      K4 = proptable.look_up("S3_time_vs_thrust", Stage_var_list[STAGE_3]->timer + int_step, 0)
           / Stage_var_list[STAGE_3]->isp;
      Stage_var_list[STAGE_3]->fmasse =
          Stage_var_list[STAGE_3]->fmasse +
          (int_step / 6.0) * (K1 + 2.0 * K2 + 2.0 * K3 + K4);
      break;
  }
}

void Propulsion::propagate_delta_v(double int_step, double spi,
                                   double fuel_flow_rate, double vmass) {
  this->delta_v += spi * AGRAV * (fuel_flow_rate / vmass) * int_step;
}

double Propulsion::calculate_thrust(double press) {
  return proptable.look_up("time_vs_thrust", get_rettime(), 0) * AGRAV +
         (-press) * this->aexit;
}

double Propulsion::calculate_fmassr() { return this->fmass0 - this->fmasse; }

arma::vec3 Propulsion::calculate_XCG() {
  return -(XCG_0 + (XCG_1 - XCG_0) * mass_ratio);
}

arma::mat33 Propulsion::calculate_IBBB() {
  return IBBB0 + (IBBB1 - IBBB0) * mass_ratio;
}

void Propulsion::load_proptable(const char* filename) {
  proptable = Datadeck(filename);
}

void Propulsion::set_vmass0(double in) { vmass0 = in; }
void Propulsion::set_fmass0(double in) { fmass0 = in; }
void Propulsion::set_aexit(double in) { aexit = in; }
void Propulsion::set_payload_mass(double in) { payload_mass = in; }
int Propulsion::get_mprop() {
  return static_cast<int>(this->thrust_state); /*XXX work around*/
}
enum Propulsion::THRUST_TYPE Propulsion::get_thrust_state() {
  return this->thrust_state;
}
double Propulsion::get_vmass() { return vmass; }
arma::vec3 Propulsion::get_XCG() { return XCG; }
arma::vec3 Propulsion::get_XCG_0() { return XCG_0; }
double Propulsion::get_thrust() { return thrust; }
double Propulsion::get_fmassr() { return fmassr; }
arma::mat33 Propulsion::get_IBBB() { return IBBB; }
