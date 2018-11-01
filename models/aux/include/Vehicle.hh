#ifndef Vehicle_list__HH
#define Vehicle_list__HH
#include "aux.hh"
#include <vector>
#include <map>
#include <string>
#include <armadillo>

class FH_module {
 public:
  FH_module(){};
  ~FH_module(){};

  virtual void algorithm(double int_step) = 0;
  virtual void init() = 0;
  virtual void update_diagnostic_attributes(double int_step) = 0;
};

class Data_exchang {
  public :
    Data_exchang(){};
    ~Data_exchang(){};

    void hset(std::string input, int val) { int_table[input] = val; }
    void hset(std::string input, double val) { double_table[input] = val; }
    void hset(std::string input, arma::vec val) { vec_table[input] = val; }
    void hset(std::string input, arma::mat val) { mat_table[input] = val; }

    void hget(std::string input, int *val) { *val = int_table.find(input)->second; }
    void hget(std::string input, double *val) { *val = double_table.find(input)->second; }
    void hget(std::string input, arma::vec val) { val = vec_table.find(input)->second; }
    void hget(std::string input, arma::mat val) { val = mat_table.find(input)->second; }

  private :
    std::map<std::string, int> int_table;
    std::map<std::string, double> double_table;
    std::map<std::string, arma::vec> vec_table;
    std::map<std::string, arma::mat> mat_table;
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