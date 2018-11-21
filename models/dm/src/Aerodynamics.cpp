#include "Aerodynamics.hh"

AeroDynamics::AeroDynamics(Propulsion& prop, Data_exchang& input)
    : propulsion(&prop), VECTOR_INIT(XCP, 3) {
  data_exchang = &input;
}

AeroDynamics::AeroDynamics(const AeroDynamics& other)
    : propulsion(other.propulsion), VECTOR_INIT(XCP, 3) {
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
  this->XCP = other.XCP;
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
  this->XCP = other.XCP;

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
  int liftoff;
  data_exchang->hget("liftoff", &liftoff);

  if (liftoff == 1) {
    double vmach, dvba, alppx, phipx, alt;
    data_exchang->hget("alppx", &alppx);
    data_exchang->hget("phipx", &phipx);
    data_exchang->hget("vmach", &vmach);
    data_exchang->hget("dvba", &dvba);
    data_exchang->hget("alt", &alt);
    
    arma::vec3 WBIB;
    arma::vec3 WBEB;
    arma::vec3 XCG;
    data_exchang->hget("XCG", XCG);
    data_exchang->hget("WBEB", WBEB);
    data_exchang->hget("WBIB", WBIB);


    enum Propulsion::THRUST_TYPE thrust_state = propulsion->get_thrust_state();
    // double vmass  = grab_vmass();
    

    //  transforming body rates from body -> aeroballistic coord.
    double phip = phipx * RAD;
    double cphip = cos(phip);
    double sphip = sin(phip);
    double qqax = RAD * (WBEB(1) * DEG * cphip - WBEB(2) * DEG * sphip);
    double rrax = RAD * (WBEB(1) * DEG * sphip + WBEB(2) * DEG * cphip);

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
    clm = cn * ((-XCG(0) / refd) - XCP(0)) * cphip +
          cmq * ((WBIB(1) * refd) / (2.0 * dvba));
    cln = -cn * ((-XCG(0) / refd) - XCP(0)) * sphip +
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

