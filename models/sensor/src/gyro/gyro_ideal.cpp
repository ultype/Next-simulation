#include <armadillo>
#include <cstring>

#include "gyro/gyro_ideal.hh"

GyroIdeal::GyroIdeal(Data_exchang &input) {
  snprintf(name, sizeof(name), "Ideal Gyro Sensor");
  data_exchang = &input;
}

GyroIdeal::GyroIdeal(const GyroIdeal &other) {
  this->WBICB = other.WBICB;
  this->EWBIB = other.EWBIB;
  this->data_exchang = other.data_exchang;
}

GyroIdeal &GyroIdeal::operator=(const GyroIdeal &other) {
  if (&other == this) return *this;

  this->WBICB = other.WBICB;
  this->EWBIB = other.EWBIB;
  this->data_exchang = other.data_exchang;

  return *this;
}

void GyroIdeal::init() {
  data_exchang->hget("WBIB", WBICB);
  this->EWBIB.zeros();
  data_exchang->hset("WBICB", WBICB);

}

void GyroIdeal::algorithm(double int_step) {
  this->WBICB;
  data_exchang->hget("WBIB", WBICB);
  this->EWBIB.zeros();

  data_exchang->hset("WBICB", WBICB);
  return;
}
