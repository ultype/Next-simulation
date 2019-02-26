CIFX_LIBS += -L/usr/local/lib \
	    	 -L/usr/local/lib/pkgconfig
CIFX_LIBS += -lcifx -lpthread -lrt



TRICK_CFLAGS += --std=gnu11 ${INCLUDES} -g -D_GNU_SOURCE
TRICK_CFLAGS += -Wall -Wmissing-prototypes -Wextra -Wshadow
TRICK_CXXFLAGS += --std=c++17 ${INCLUDES} -g
TRICK_CXXFLAGS += -Wall -Wextra -Wshadow
TRICK_USER_LINK_LIBS += -larmadillo -lhiredis $(CIFX_LIBS)
MAKEFLAGS += -j16
