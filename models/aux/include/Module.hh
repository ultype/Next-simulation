#ifndef Module_HH
#define Module_HH

#include <armadillo>
#include "Vehicle.hh"
#include "matrix/utility.hh"

class Sensor : public FH_module {
 public:
  char name[32];
  // Preserve for output I/O to FC
};

class Actuator : public FH_module {
 public:
  char name[32];
  // Preserve for recieving input data from FC
};

class FC_Algorithm : public FH_module {
 public:
  char name[32];
  // Preserve for output I/O to FC
};

class Dynamics : public FH_module {
 public:
  char name[32];
  // Preserve for output I/O to test instrument such like SimGen,
  // Ratetable...etc
};

#endif  // Module_HH