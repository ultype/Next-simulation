CIFX_LIBRARY_VERSION = 2:4:1
CIFX_VERSION_INFO = "\"V1.1.4\""
AUTOMAKE_OPTIONS = subdir-objects

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = cifx.pc

if ETHERNETSUPPORT
AM_CPPFLAGS = -I$(srcdir)/ -I$(srcdir)/Toolkit -I$(srcdir)/netx_tap

lib_LTLIBRARIES       = libcifxpre.la libcifx.la

libcifxpre_la_SOURCES = OS_Linux.c USER_Linux.c cifxlinux.c \
			Toolkit/cifXInit.c Toolkit/Hilmd5.c Toolkit/cifXDownload.c \
			Toolkit/cifXFunctions.c Toolkit/cifXHWFunctions.c \
			Toolkit/cifXInterrupt.c Toolkit/cifXEndianess.c

libcifxpre_la_CFLAGS  = -c -fPIC -Wall -D_GNU_SOURCE -D_REENTRANT @CFLAGS@ @PCIACCESS_CFLAGS@ @CIFXETHFLAGS@ -DVERSION_INFO=${CIFX_VERSION_INFO}

libcifx_la_SOURCES  = netx_tap/netx_tap.c
libcifx_la_CFLAGS   = -fPIC -Wall -D_GNU_SOURCE -D_REENTRANT @CFLAGS@ @PCIACCESS_CFLAGS@ -DVERSION_INFO=${CIFX_VERSION_INFO}
libcifx_la_LDFLAGS  = -version-info $(CIFX_LIBRARY_VERSION) @LDFLAGS@ -lpthread -lrt @PCIACCESS_LIBS@
libcifx_la_LIBADD   = libcifxpre_la-OS_Linux.lo libcifxpre_la-USER_Linux.lo libcifxpre_la-cifxlinux.lo \
			Toolkit/libcifxpre_la-cifXInit.lo Toolkit/libcifxpre_la-Hilmd5.lo Toolkit/libcifxpre_la-cifXDownload.lo \
			Toolkit/libcifxpre_la-cifXFunctions.lo Toolkit/libcifxpre_la-cifXHWFunctions.lo \
			Toolkit/libcifxpre_la-cifXInterrupt.lo Toolkit/libcifxpre_la-cifXEndianess.lo

library_include_HEADERS = Toolkit/rcX_User.h Toolkit/rcX_Public.h Toolkit/TLR_Types.h \
			Toolkit/cifXUser.h cifxlinux.h Toolkit/cifXErrors.h \
			Toolkit/cifXEndianess.h netx_tap/netx_tap.h
else
AM_CPPFLAGS = -I$(srcdir)/ -I$(srcdir)/Toolkit

lib_LTLIBRARIES = libcifx.la

libcifx_la_SOURCES = OS_Linux.c USER_Linux.c cifxlinux.c \
			Toolkit/cifXInit.c Toolkit/Hilmd5.c Toolkit/cifXDownload.c \
			Toolkit/cifXFunctions.c Toolkit/cifXHWFunctions.c \
			Toolkit/cifXInterrupt.c Toolkit/cifXEndianess.c

libcifx_la_CFLAGS  = -fPIC -Wall -D_GNU_SOURCE -D_REENTRANT @CFLAGS@ @PCIACCESS_CFLAGS@ -DVERSION_INFO=${CIFX_VERSION_INFO}
libcifx_la_LDFLAGS = -version-info $(CIFX_LIBRARY_VERSION) @LDFLAGS@ -lpthread -lrt @PCIACCESS_LIBS@

library_include_HEADERS = Toolkit/rcX_User.h Toolkit/rcX_Public.h Toolkit/TLR_Types.h \
			Toolkit/cifXUser.h cifxlinux.h Toolkit/cifXErrors.h \
			Toolkit/cifXEndianess.h
endif

library_includedir=$(includedir)/cifx
