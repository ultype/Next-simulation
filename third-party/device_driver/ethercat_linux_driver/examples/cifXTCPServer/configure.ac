#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([cifXTCPServer],[0.0.0.0])
AM_INIT_AUTOMAKE
AC_CONFIG_HEADERS([config.h])

AC_ARG_ENABLE(debug,
            AS_HELP_STRING([--enable-debug], [Compile application in debug mode]),
            [
                CFLAGS="$CFLAGS -O0 -g -DDEBUG"
                CPPFLAGS="$CPPFLAGS -O0 -g -DDEBUG"
                AC_MSG_RESULT([******************])
                AC_MSG_RESULT([*** Debug Mode ***])
                AC_MSG_RESULT([******************])
            ],
            [
                CFLAGS="$CFLAGS -O2"
                CPPFLAGS="$CPPFLAGS -O2"
            ])

# Checks for programs.
# Checks for programs.
dnl Check for gcc
AC_PROG_CC
if test -z "$CC"; then
  AC_MSG_ERROR([gcc could not be found, please install])
fi

AM_PROG_CC_C_O
AC_PROG_LN_S
AC_PROG_CXX

dnl Check for make
AC_PATH_PROGS(MAKE, gmake gnumake make,, $PATH)
if test -z "$MAKE"; then
  AC_MSG_ERROR([make could not be found, please install])
fi

dnl Check if gcc supports -fno-stack-protector
save_CFLAGS=$CFLAGS

AC_MSG_CHECKING([if $CC supports -fno-stack-protector])
AC_LANG_PUSH(C)
AC_COMPILE_IFELSE([
  AC_LANG_PROGRAM([],
                  [])],
  [
    AC_MSG_RESULT([yes])
    CFLAGS="$save_CFLAGS -fno-stack-protector"
  ],
  [
    CFLAGS="$save_CFLAGS"
    AC_MSG_RESULT([no])
  ])
AC_LANG_POP()

# Checks for libraries.


if test -z "$libcifx_CFLAGS" | test -z "$libcifx_LIBS"; then

  dnl
  dnl No custom flags defined, so we are using pkg-config to find libcifx
  dnl

  PKG_CHECK_MODULES([libcifx], [cifx >= 1.0.1],
                    ,
                    [AC_MSG_ERROR([libcifx not found via pkg-config, or wrong version!])])
else
  dnl libcifx flags overridden, so check if user provided overrides for libpciaccess.
  dnl If not, we use pkg-config

  if test -z "$PCIACCESS_CFLAGS" | test -z "$PCIACCESS_LIBS"; then

    dnl
    dnl No custom flags defined, so we are using pkg-config to find libpciaccess
    dnl If we don't find it, it might not be a problem, as cifxtoolkit may have been
    dnl compiled without PCI support. This will be check when libcifx is test-linked
    dnl

    PKG_CHECK_MODULES([PCIACCESS], [pciaccess >= 0.10.2])
  fi

  AC_SUBST(PCIACCESS_CFLAGS)
  AC_SUBST(PCIACCESS_LIBS)
fi

AC_SUBST(libcifx_CFLAGS)
AC_SUBST(libcifx_LIBS)


# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h string.h unistd.h])
AC_CHECK_HEADERS([fcntl.h stdint.h stdlib.h string.h sys/time.h unistd.h])

#Check for libcifx and if it is usable
save_LIBS="$LIBS"
save_CFLAGS="$CFLAGS"
save_CPPFLAGS="$CPPFLAGS"
LIBS="$LIBS $PCIACCESS_LIBS $libcifx_LIBS"
CFLAGS="$CFLAGS $PCIACCESS_CFLAGS $libcifx_CFLAGS"
CPPFLAGS="$CPPFLAGS $PCIACCESS_CFLAGS $libcifx_CFLAGS"

AC_CHECK_LIB(cifx, xDriverOpen,,
             [AC_MSG_ERROR([No usable libcifx found. See config.log for details!])])

LIBS="$save_LIBS"
CFLAGS="$save_CFLAGS"
CPPFLAGS="$save_CPPFLAGS"


# Checks for library functions.
AC_CHECK_FUNCS([memset])

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

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
