AC_INIT([picaster], [0.5], [yannick@frenchguy.ch])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_USE_SYSTEM_EXTENSIONS
AC_PROG_CC
AC_PROG_CXX
AM_PROG_VALAC
AM_PROG_AR
LT_INIT
AC_CONFIG_MACRO_DIRS([m4])

PKG_CHECK_MODULES([GTK], [gtk+-3.0])
PKG_CHECK_MODULES([ALSA], [alsa])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
 Makefile
 alsa/Makefile
 main/Makefile
])
AC_OUTPUT
