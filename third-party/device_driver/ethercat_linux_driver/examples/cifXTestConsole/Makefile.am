bin_PROGRAMS = cifXTestConsole
AUTOMAKE_OPTIONS = subdir-objects

AM_CPPFLAGS = -I./ @libcifx_CFLAGS@ -I./shared/

cifXTestConsole_SOURCES = Main.cpp OS_Specific.c shared/CifxConsole_Watchdog.cpp shared/CifxConsole_Upload.cpp                     \
                          shared/CifxConsole_PLCFunctions.cpp shared/CifxConsole_Packet.cpp shared/CifxConsole_MemoryPointer.cpp   \
                          shared/CifxConsole_Main.cpp shared/CifxConsole_IO.cpp shared/CifxConsole_Download.cpp                    \
                          shared/CifxConsole_ChannelFunctions.cpp shared/CifxConsole_PacketConfig.cpp shared/CifxConsole_Event.cpp \
                          shared/CifxConsole_ExtendedMemoryPointer.cpp

cifXTestConsole_CFLAGS    = @CFLAGS@ -Wall -D_GNU_SOURCE -D_REENTRANT @libcifx_CFLAGS@
cifXTestConsole_CPPFLAGS  = @CPPFLAGS@ -Wall -I./ -I./shared
cifXTestConsole_LDFLAGS   = -lcifx -lpthread @libcifx_LIBS@
cifXTestConsole_LDADD     = -lcifx -lpthread @libcifx_LIBS@

cifXTestConsole_CXXFLAGS  = @CFLAGS@ -Wall -D_GNU_SOURCE -D_REENTRANT @libcifx_CFLAGS@
