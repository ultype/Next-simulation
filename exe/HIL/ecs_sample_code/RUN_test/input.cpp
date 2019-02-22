#include <cstdlib>
#include <exception>
#include "../S_source.hh"
#include "trick/realtimesync_proto.h"
#include "trick/CheckPointRestart_c_intf.hh"
#include "trick/external_application_c_intf.h"
#include "../../../xil_common/include/realtime.h"

extern "C" int run_me() {
    realtime();
	checkpoint_pre_init(true) ;
    exec_set_terminate_time(100.0);
    return 0;
}
