PROJECT     := ECS_test
EXECUTABLE  := $(PROJECT).elf 

CC	       	:= gcc
MKFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
HOME_PATH   := $(patsubst %/makefile, %, $(MKFILE_PATH))
ICF_PATH	:= $(patsubst %/unit_test/ECS_test, %, $(HOME_PATH))
MODEL_PATH  := $(patsubst %/icf, %, $(ICF_PATH))

HEADERS     += -I$(ICF_PATH)/include/ \
			   -I$(ICF_PATH)/include/third_party_header/ \
			   -I$(MODEL_PATH)/equipment_protocol/include/ \
			   -I$(MODEL_PATH)/gnc/include/ \
			   -I/usr/local/include/hiredis \
          	   -I/usr/local/include/pkgconfig

$(info MKFILE_PATH = $(MKFILE_PATH))
$(info HOME_PATH   = $(HOME_PATH))
$(info ICF_PATH    = $(ICF_PATH))
$(info MODEL_PATH  = $(MODEL_PATH))
OBJS += $(HOME_PATH)/main.o \
		$(ICF_PATH)/src/ECS.o \
		$(ICF_PATH)/src/icf_trx_ctrl.o \
		$(ICF_PATH)/src/icf_drivers.o \
		$(ICF_PATH)/src/icf_utility.o \
		$(ICF_PATH)/src/ringbuffer.o \
		$(ICF_PATH)/src/ethernet.o \
		$(ICF_PATH)/src/rs422_serialport.o \
		$(ICF_PATH)/src/socket_can.o \
		$(MODEL_PATH)/equipment_protocol/src/flight_computer_eqpt.o

CFLAGS += -g -DCONFIG_FC_ECS_TEST_ENABLE
      	
LIBS += -L/usr/local/lib \
	    -L/usr/local/lib/pkgconfig\

LIBS += -lcifx -lpthread -lrt 


all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS) $(HEADERS) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

clean:
	rm -rf $(EXECUTABLE)
	rm -rf $(OBJS)
.PHONY: clean
