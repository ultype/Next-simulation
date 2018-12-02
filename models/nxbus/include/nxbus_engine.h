#ifndef MODELS_NXBUS_INCLUDE_NXBUS_ENGINE_H_
#define MODELS_NXBUS_INCLUDE_NXBUS_ENGINE_H_
/********************************* TRICK HEADER *******************************
PURPOSE:
      Next Simulation Software Bus
LIBRARY DEPENDENCY:
      (
          (../src/nxbus_engine.c)
      )
PROGRAMMERS:
      (((Dung-Ru Tsai) () () () ))
*******************************************************************************/
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void nxbus_init(void);
void nxbus_mset_vec(const char *key_name, double *vector, size_t dimension);
void nxbus_mget_vec(const char *key_name, double *vector, size_t dimension);
void nxbus_deinit(void);

#ifdef __cplusplus
}
#endif

#endif  // MODELS_NXBUS_INCLUDE_NXBUS_ENGINE_H_
