
MKFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
HOME_PATH   := $(patsubst %/exe/HIL/ecs_sample_code/S_overrides.mk, %, $(MKFILE_PATH))

$(info MKFILE_PATH = $(MKFILE_PATH))
$(info HOME_PATH = $(HOME_PATH))

INCLUDES = -I$(HOME_PATH)/models/clock_source_mgmt \
		   -I$(HOME_PATH)/models/gnc/include \
		   -I$(HOME_PATH)/models/icf/include \
		   -I$(HOME_PATH)/models/equipment_protocol/include \
		   -I$(HOME_PATH)/models/icf/include/third_party_header \
		   -I/usr/local/include/hiredis

LIBS += -L/usr/local/lib \
		-L/usr/local/lib/pkgconfig\
 
LIBS += -lcifx -lpthread -lrt 


TRICK_CFLAGS += ${INCLUDES} -g -D_GNU_SOURCE -DCONFIG_FC_ECS_TEST_ENABLE 
TRICK_CFLAGS += -Wall -Wmissing-prototypes -Wextra -Wshadow
TRICK_CXXFLAGS += --std=c++11 ${INCLUDES} -g -DCONFIG_FC_ECS_TEST_ENABLE
TRICK_CXXFLAGS += -Wall -Wextra -Wshadow -Wno-narrowing -lpthread
TRICK_USER_LINK_LIBS += -larmadillo -lboost_serialization -lbiodaq $(LIBS)
MAKEFLAGS += -j16
