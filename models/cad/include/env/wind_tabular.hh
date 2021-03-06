#ifndef __wind_tabular_HH__
#define __wind_tabular_HH__
/********************************* TRICK HEADER *******************************
PURPOSE:
      (tabular wind model)
LIBRARY DEPENDENCY:
      ((../../src/env/wind_tabular.cpp))
*******************************************************************************/

#include "datadeck.hh"
#include "env/wind.hh"

namespace cad {
class Wind_Tabular : public Wind {
 public:
    Wind_Tabular(char* filepath, double twind, double vertical_wind);

    virtual ~Wind_Tabular();

    virtual void set_altitude(double altitude_in_meter);

 private:
    Datadeck weathertable;
};
}  // namespace cad

#endif  // __wind_tabular__
