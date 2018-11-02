#ifndef __aerodynamics_HH__
#define __aerodynamics_HH__
/********************************* TRICK HEADER *******************************
PURPOSE:
      (Describe the AERODYNAMICS Module On Board)
LIBRARY DEPENDENCY:
      ((../src/Aerodynamics.cpp))
PROGRAMMERS:
      (((Chun-Hsu Lai) () () () ))
*******************************************************************************/
#include <armadillo>
#include <functional>
#include "Module.hh"
#include "Propulsion.hh"
#include "aux.hh"
#include "datadeck.hh"
#include "global_constants.hh"

class Propulsion;

class AeroDynamics : public Dynamics {
  TRICK_INTERFACE(AeroDynamics);

 public:
  explicit AeroDynamics(Propulsion& prop, Data_exchang& input);
  AeroDynamics(const AeroDynamics& other);

  AeroDynamics& operator=(const AeroDynamics& other);

  void load_aerotable(const char* filename);

  virtual void init();
  virtual void algorithm(double int_step);

  double get_refa();
  double get_refd();
  double get_cy();
  double get_cll();
  double get_clm();
  double get_cln();
  double get_cx();
  double get_cz();
  arma::vec3 get_xcp();

  void set_refa(double);
  void set_refd(double);

  std::function<double()> grab_alppx;
  std::function<double()> grab_phipx;
  std::function<double()> grab_alphax;
  std::function<double()> grab_betax;
  std::function<double()> grab_rho;
  std::function<double()> grab_vmach;
  std::function<double()> grab_pdynmc;
  std::function<double()> grab_tempk;
  std::function<double()> grab_dvba;
  std::function<double()> grab_ppx;
  std::function<double()> grab_qqx;
  std::function<double()> grab_rrx;
  std::function<arma::vec3()> grab_WBIB;
  std::function<double()> grab_alt;
  // std::function<double()> grab_vmass;
  std::function<arma::vec3()> grab_xcg;
  std::function<unsigned int()> grab_liftoff;

 private:
  Propulsion* propulsion;
  Data_exchang* data_exchang;

  Datadeck aerotable; /* ** (--) Aero Deck */

  double refa;  /* *o (m2)     Reference area for aero coefficients - m^2*/
  double refd;  /* *o (m)      Reference length for aero coefficients - m*/
  double cy;    /* *o (--)     Side force coefficient - ND*/
  double cll;   /* *o (--)     Rolling moment coefficient - ND*/
  double clm;   /* *o (--)     Pitching moment coefficient - ND*/
  double cln;   /* *o (--)     Yawing moment coefficient - ND*/
  double cx;    /* *o (--)     X-force coefficient - ND*/
  double cz;    /* *o (--)     Z-force coefficient - ND*/
  double cn;    /* *o (--)     Normal force coefficient */
  double ca;    /* *o (--)     Axial force coefficient */
  double ca_on; /* *o (--)     Axial force coefficient when engine is running */
  double cnq;   /* *o (--)     Normal damping coefficient */
  double cmq;   /* *o (--)     Pitch moment derivative coefficient */

  VECTOR(XCP,
         3); /* *o (m)      Non-dimensional center of pressure (from nose)*/
};

#endif  // __aerodynamics_HH__
