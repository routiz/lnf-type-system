#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([xcsample], [0.0.1], [ryu.insang@gmail.com])
AM_INIT_AUTOMAKE([gnits])

AC_CONFIG_SRCDIR([src/signature])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
LT_INIT
AC_CONFIG_MACRO_DIR([m4])

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stddef.h stdint.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 include/Makefile
                 src/Makefile
                 tests/Makefile])
AC_OUTPUT
