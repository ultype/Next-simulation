INCLUDES += -I$(TOP_DIR)/models/clock_source_mgmt \
            -I$(TOP_DIR)/models/fc_agent/include
TRICK_CFLAGS += -DCONFIG_PIL_ENABLE
TRICK_CXXFLAGS += -DCONFIG_PIL_ENABLE -Wno-narrowing
TRICK_USER_LINK_LIBS += -larmadillo -lboost_serialization -lbiodaq
TRICK_USER_LINK_LIBS += -lbiodaq
