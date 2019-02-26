#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.65)
AC_INIT([libcifxtk],[1.1.0.0])
AM_INIT_AUTOMAKE
AC_PROG_LIBTOOL
AC_CONFIG_HEADER([config.h])

AM_CONDITIONAL(ETHERNETSUPPORT, [test])

AC_ARG_ENABLE(debug, 
            AS_HELP_STRING([--enable-debug], [Compile application in debug mode]),
            [
                CFLAGS="$CFLAGS -O0 -g3 -DDEBUG"
                AC_MSG_RESULT([******************])
                AC_MSG_RESULT([*** Debug Mode ***])
                AC_MSG_RESULT([******************])
            ],
            [
                CFLAGS="$CFLAGS -O2"
            ])

AC_ARG_ENABLE(verbose, 
            AS_HELP_STRING([--enable-verbose], [Enable console debugging outputs of library]),
            [
                CFLAGS="$CFLAGS -DVERBOSE"
                AC_MSG_RESULT([****************************])
                AC_MSG_RESULT([*** Verbose mode enabled ***])
                AC_MSG_RESULT([****************************])
            ])            

AC_ARG_ENABLE(pci, 
             AS_HELP_STRING([--disable-pci], [Disable pci card support]),
            [
              if test "$enableval" = no; then
                ac_enable_pci=no
              else
                ac_enable_pci=yes
              fi
            ],
            [
              ac_enable_pci=yes
            ])

AC_ARG_ENABLE(single-directory, 
             AS_HELP_STRING([--enable-single-directory], [Use a single directory for the device firmware (used by OEMs if only one device is available)]),
            [
              if test "$enableval" = no; then
                ac_enable_single_directory=no
              else
                ac_enable_single_directory=yes
              fi
            ],
            [
              ac_enable_single_directory=no
            ])

AC_ARG_ENABLE(time-setup, 
            AS_HELP_STRING([--enable-time-setup], [Enable device time setting during start-up]),
            [
                CFLAGS="$CFLAGS -DCIFX_TOOLKIT_TIME"
                AC_MSG_RESULT([***********************************])
                AC_MSG_RESULT([*** Device time setting enabled ***])
                AC_MSG_RESULT([***********************************])
            ])
           
AC_ARG_ENABLE(dma, 
            AS_HELP_STRING([--enable-dma], [Compile driver with dma support]),
            [
                CFLAGS="$CFLAGS -DCIFX_TOOLKIT_DMA"
                AC_MSG_RESULT([************************])
                AC_MSG_RESULT([*** DMA Mode enabled ***])
                AC_MSG_RESULT([************************])
            ])
            
AC_ARG_ENABLE(minsleep, 
            AS_HELP_STRING([--disable-minsleep], [Disable minimum sleep time]),
            [
                CFLAGS="$CFLAGS -DNO_MIN_SLEEP"
                AC_MSG_RESULT([******************************])
                AC_MSG_RESULT([*** Minimum sleep disabled ***])
                AC_MSG_RESULT([******************************])
            ]) 
            
AC_ARG_ENABLE(cifxethernet, 
            AS_HELP_STRING([--enable-cifxethernet], [Enables virtual ethernet interface support]),
            [
                CFLAGS="$CFLAGS -DCIFXETHERNET"
#               APIRENAME: see cifx_tap/netx_tap.c xSysDeviceReset()
                CIFXETHFLAGS="-DAPIRENAME"
                AM_CONDITIONAL(ETHERNETSUPPORT,[test xtrue])
                AC_MSG_RESULT([**************************************************])
                AC_MSG_RESULT([*** Virtual ethernet interface support enabled ***])
                AC_MSG_RESULT([**************************************************])
            ])

AC_ARG_ENABLE(hwif,
            AS_HELP_STRING([--enable-hwif], [Enables the toolkit's Hardware Function Interface (e.g. for SPI)]),
            [
                CFLAGS="$CFLAGS -DCIFX_DRV_HWIF"
                AC_MSG_RESULT([*******************************************])
                AC_MSG_RESULT([*** Hardware Function Interface enabled ***])
                AC_MSG_RESULT([*******************************************])
            ])

AC_ARG_ENABLE(plugins, 
            AS_HELP_STRING([--enable-plugins], [Enables support of device plugins]),
            [
                CFLAGS="$CFLAGS -DCIFX_PLUGIN_SUPPORT"
                AC_MSG_RESULT([**************************************************])
                AC_MSG_RESULT([*** Plugin support enabled                     ***])
                AC_MSG_RESULT([**************************************************])

		if test "$enableval" = no; then
                    ac_enable_plugins=no
		else
		    ac_enable_plugins=yes
		fi
            ],
	    [
		ac_enable_plugins=no
	    ])

# Checks for programs.
dnl Check for install
AC_PROG_INSTALL
if test -z "${INSTALL}"; then
  AC_MSG_ERROR([install could not be found, please install e.g.: GNU coreutils])
fi

dnl Check for gcc
#AC_PROG_CC
AM_PROG_CC_C_O
if test -z "$CC"; then
  AC_MSG_ERROR([gcc could not be found, please install])
fi

dnl Check for libtool
LT_INIT
if test -z "$LIBTOOL"; then
  AC_MSG_ERROR([libtool could not be found, please install])
fi

AC_PROG_LN_S

dnl Check for make
AC_PATH_PROGS(MAKE, gmake gnumake make,, $PATH)
if test -z "$MAKE"; then
  AC_MSG_ERROR([make could not be found, please install])
fi

dnl Check if gcc supports -fno-stack-protector
if test "x$ac_cv_c_compiler_gnu" = xyes; then
  AC_CACHE_CHECK([whether gcc has -fno-stack-protector],
                 no_stack_protector_flag_cv_, 
                 [
                  saved_CFLAGS=$CFLAGS
                  CFLAGS=" $CFLAGS -fno-stack-protector"
                  AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]], [[]])],[no_stack_protector_flag_cv_=yes],[no_stack_protector_flag_cv_=no])
                  CFLAGS=$saved_CFLAGS
                  ])
  if test "x$no_stack_protector_flag_cv_" = xyes; then
    CFLAGS="$CFLAGS -fno-stack-protector"
  fi
fi

# Checks for header files.
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_CHECK_HEADERS([fcntl.h stdint.h stdlib.h string.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_SIZE_T
AC_HEADER_TIME
AC_STRUCT_TM
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T
AC_C_VOLATILE

AC_C_BIGENDIAN(
  [
    CFLAGS="$CFLAGS -DCIFX_TOOLKIT_BIGENDIAN"
  ])


# Checks for library functions.
AC_FUNC_CLOSEDIR_VOID
AC_FUNC_MALLOC
AC_FUNC_MEMCMP
AC_FUNC_MMAP
AC_FUNC_REALLOC
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([clock_gettime getpagesize gettimeofday memmove memset munmap strdup strncasecmp strstr])


if test "$ac_enable_single_directory" = yes; then
  CFLAGS="$CFLAGS -DCIFX_TOOLKIT_USESINGLE_DIRECTORY"
fi

if test "$ac_enable_pci" = no; then
  CFLAGS="$CFLAGS -DCIFX_TOOLKIT_DISABLEPCI"

else
  REQUIRED_PACKAGES="pciaccess"
  dnl
  dnl Check if libpciaccess is present and at least our tested version 
  dnl

  if test -z "$PCIACCESS_CFLAGS" | test -z "$PCIACCESS_LIBS"; then

    dnl
    dnl No custom flags defined, so we are using pkg-config to find libpciaccess
    dnl

    PKG_CHECK_MODULES([PCIACCESS], [pciaccess >= 0.10.2],
                      ,
                      [AC_MSG_ERROR([libpciaccess not found via pkg-config, or wrong version!])])
  fi

  dnl
  dnl Check if libpciaccess is usable
  dnl

  save_LIBS="$LIBS"
  save_CFLAGS="$CFLAGS"
  LIBS="$LIBS $PCIACCESS_LIBS"
  CFLAGS="$CFLAGS $PCIACCESS_CFLAGS"

  AC_CHECK_LIB(pciaccess, pci_system_init,, 
               [AC_MSG_ERROR([No usable libpciaccess found. See config.log for details!])])
  LIBS="$save_LIBS"
  CFLAGS="$save_CFLAGS"

  AC_SUBST(REQUIRED_PACKAGES)
  AC_SUBST(PCIACCESS_CFLAGS)
  AC_SUBST(PCIACCESS_LIBS)
  AC_SUBST(CIFXETHFLAGS)
fi

if test "$ac_enable_plugins" = yes; then
  AC_CHECK_HEADERS([dlfcn.h])
  AC_CHECK_LIB(dl, dlopen,,
		[AC_MSG_ERROR([No usable libdl found. See config.log for details!])])
  AC_CHECK_LIB(dl, dlclose,,
		[AC_MSG_ERROR([No usable libdl found. See config.log for details!])])
  AC_CHECK_LIB(dl, dlsym,,
		[AC_MSG_ERROR([No usable libdl found. See config.log for details!])])
  AC_SUBST(PLUGIN_LIBS, [-ldl])
fi


dnl
dnl versions
dnl
VERSION_MAJOR=` echo "$PACKAGE_VERSION" | \
  sed -e "s/-/./g" | \
  (IFS=. read VERSION_MAJOR VERSION_MINOR VERSION_MICRO VERSION_EXTRA; echo $VERSION_MAJOR)`
VERSION_MINOR=` echo "$PACKAGE_VERSION" | \
  sed -e "s/-/./g" | \
  (IFS=. read VERSION_MAJOR VERSION_MINOR VERSION_MICRO VERSION_EXTRA; echo $VERSION_MINOR)`
VERSION_MICRO=` echo "$PACKAGE_VERSION" | \
  sed -e "s/-/./g" | \
  (IFS=. read VERSION_MAJOR VERSION_MINOR VERSION_MICRO VERSION_EXTRA; echo $VERSION_MICRO)`
VERSION_EXTRA=` echo "$PACKAGE_VERSION" | \
  sed -e "s/-/./g" | \
  (IFS=. read VERSION_MAJOR VERSION_MINOR VERSION_MICRO VERSION_EXTRA; echo $VERSION_EXTRA)`

if test -n "$VERSION_EXTRA"; then
  VERSION_EXTRA_SEP="."
else
  VERSION_EXTRA_SEP=""
fi

AC_SUBST(PACKAGE_VERSION)
AC_SUBST(VERSION_MAJOR)
AC_SUBST(VERSION_MINOR)
AC_SUBST(VERSION_MICRO)
AC_SUBST(VERSION_EXTRA_SEP)
AC_SUBST(VERSION_EXTRA)

AC_CONFIG_FILES([Makefile src/Makefile src/cifx.pc])
AC_OUTPUT
