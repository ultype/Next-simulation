#include "Aerodynamics.hh"

AeroDynamics::AeroDynamics(Propulsion& prop, Data_exchang& input)
    : propulsion(&prop), 
      VECTOR_INIT(XCP, 3) {
      data_exchang = &input;
    }

AeroDynamics::AeroDynamics(const AeroDynamics& other)
    : propulsion(other.propulsion) {
  this->aerotable = other.aerotable;
  this->refa = other.refa;
  this->refd = other.refd;
  this->cy = other.cy;
  this->cll = other.cll;
  this->clm = other.clm;
  this->cln = other.cln;
  this->cx = other.cx;
  this->cz = other.cz;
  this->cn = other.cn;
  this->ca = other.ca;
  this->ca_on = other.ca_on;
  this->cnq = other.cnq;
  this->cmq = other.cmq;
  this->data_exchang = other.data_exchang;
}

AeroDynamics& AeroDynamics::operator=(const AeroDynamics& other) {
  if (&other == this) return *this;

  this->propulsion = other.propulsion;
  this->data_exchang = other.data_exchang;
  this->aerotable = other.aerotable;

  this->refa = other.refa;
  this->refd = other.refd;
  this->cy = other.cy;
  this->cll = other.cll;
  this->clm = other.clm;
  this->cln = other.cln;
  this->cx = other.cx;
  this->cz = other.cz;
  this->cn = other.cn;
  this->ca = other.ca;
  this->ca_on = other.ca_on;
  this->cnq = other.cnq;
  this->cmq = other.cmq;

  return *this;
}

void AeroDynamics::init() {}

void AeroDynamics::load_aerotable(const char* filename) {
  aerotable = Datadeck(filename);
}

void AeroDynamics::set_refa(double in) { refa = in; }
void AeroDynamics::set_refd(double in) { refd = in; }

void AeroDynamics::algorithm(double int_step) {
  /* only calculate when rocket liftoff */
  unsigned int liftoff = grab_liftoff();

  if (liftoff == 1) {
    double alppx = grab_alppx();
    double phipx = grab_phipx();

    double vmach, dvba;
    data_exchang->hget("vmach", &vmach);
    data_exchang->hget("dvba", &dvba);

    double ppx = grab_ppx();
    double qqx = grab_qqx();
    double rrx = grab_rrx();
    arma::vec3 WBIB = grab_WBIB();

    double alt = grab_alt();

    enum Propulsion::THRUST_TYPE thrust_state = propulsion->get_thrust_state();
    // double vmass  = grab_vmass();
    arma::vec3 xcg = grab_xcg();

    //  transforming body rates from body -> aeroballistic coord.
    double phip = phipx * RAD;
    double cphip = cos(phip);
    double sphip = sin(phip);
    double qqax = RAD * (qqx * cphip - rrx * sphip);
    double rrax = RAD * (qqx * sphip + rrx * cphip);

    cn = aerotable.look_up("CN_vs_mach_alpha", alppx, vmach, 1);
    ca = aerotable.look_up("CA_off_vs_mach_alpha_alt", alppx, alt, vmach, 1);
    ca_on = aerotable.look_up("CA_on_vs_mach_alpha_alt", alppx, alt, vmach, 1);
    // cl = aerotable.look_up("CL_vs_mach_alpha", alppx, vmach);
    XCP(0) = aerotable.look_up("Xcp_vs_mach_alpha", alppx, vmach, 1);
    cmq = aerotable.look_up("CMq_vs_mach", vmach, 1);
    cnq = aerotable.look_up("CNq_vs_mach", vmach, 1);

    if (thrust_state = Propulsion::NO_THRUST) {
      cx = -ca;
    } else {
      cx = -ca_on;
    }

    cy = -cn * sphip + cnq * ((WBIB(2) * refd) / (2.0 * dvba));
    cz = -cn * cphip - cnq * ((WBIB(1) * refd) / (2.0 * dvba));

    cll = 0.0;
    clm = cn * ((-xcg(0) / refd) - XCP(0)) * cphip +
          cmq * ((WBIB(1) * refd) / (2.0 * dvba));
    cln = -cn * ((-xcg(0) / refd) - XCP(0)) * sphip +
          cmq * ((WBIB(2) * refd) / (2.0 * dvba));
  }

  data_exchang->hset("refa", refa);
  data_exchang->hset("refd", refd);
  data_exchang->hset("cx", cx);
  data_exchang->hset("cy", cy);
  data_exchang->hset("cz", cz);
  data_exchang->hset("cll", cll);
  data_exchang->hset("clm", clm);
  data_exchang->hset("cln", cln);
  data_exchang->hset("XCP", XCP);
}

double AeroDynamics::get_refa() { return refa; }
double AeroDynamics::get_refd() { return refd; }
double AeroDynamics::get_cy() { return cy; }
double AeroDynamics::get_cll() { return cll; }
double AeroDynamics::get_clm() { return clm; }
double AeroDynamics::get_cln() { return cln; }
double AeroDynamics::get_cx() { return cx; }
double AeroDynamics::get_cz() { return cz; }
arma::vec3 AeroDynamics::get_xcp() { return XCP; }
