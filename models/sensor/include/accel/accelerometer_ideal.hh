#ifndef __ACCEL_IDEAL_HH__
#define __ACCEL_IDEAL_HH__
/********************************* TRICK HEADER *******************************
PURPOSE:
      (Ideal Accelerometer Implementation)
LIBRARY DEPENDENCY:
      ((../../src/accel/accelerometer_ideal.cpp))
*******************************************************************************/

#include <armadillo>
#include <aux.hh>

#include "accel/accelerometer.hh"

class AccelerometerIdeal : public Accelerometer {
  TRICK_INTERFACE(AccelerometerIdeal);

 public:
  AccelerometerIdeal(Data_exchang &input);
  AccelerometerIdeal(const AccelerometerIdeal &other);
  AccelerometerIdeal &operator=(const AccelerometerIdeal &other);

  virtual ~AccelerometerIdeal() {}
  virtual void init(){};
  virtual void algorithm(double int_step);
};

#endif  // __ACCEL_IDEAL__
