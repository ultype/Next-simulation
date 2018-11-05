#include "accel/accelerometer_ideal.hh"

AccelerometerIdeal::AccelerometerIdeal(Data_exchang &input) {
  snprintf(name, sizeof(name), "Ideal Accelerometer Sensor");
  this->data_exchang = &input;
}

AccelerometerIdeal::AccelerometerIdeal(const AccelerometerIdeal &other) {
  memcpy(this->name, other.name, sizeof(other.name));
  this->FSPCB = other.FSPCB;
  this->EFSPB = other.EFSPB;
}

AccelerometerIdeal &AccelerometerIdeal::operator=(
    const AccelerometerIdeal &other) {
  if (&other == this) return *this;
  memcpy(this->name, other.name, sizeof(other.name));
  this->FSPCB = other.FSPCB;
  this->EFSPB = other.EFSPB;
  return *this;
}

void AccelerometerIdeal::algorithm(double int_step) {
  this->FSPCB = grab_FSPB();
  this->EFSPB.zeros();

  data_exchang->hset("FSPCB", FSPCB);
}
