#ifndef Vehicle_list__HH
#define Vehicle_list__HH
#include "aux.hh"
#include <vector>

class FH_module {
 public:
  FH_module(){};
  ~FH_module(){};

  virtual void algorithm(double int_step) = 0;
  virtual void init() = 0;
  virtual void update_diagnostic_attributes(double int_step) = 0;
};

// class Vehicle {
//  private:
//   char Name[32];
//   int module_num;
//   FH_module **module_ptr;

//  public:
//   Vehicle(int num);
//   ~Vehicle();

//   char *get_name();
// };

// class Vehicle_list {
//  private:
//   int howmany;
//   Vehicle **vehicle_ptr;

//  public:
//   Vehicle_list();
//   ~Vehicle_list();
//   void Add_vehicle(Vehicle *ptr);
// };
#endif  // Vehicle_list__HH