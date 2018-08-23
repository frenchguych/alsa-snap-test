bin_PROGRAMS = alsa-snap-test
alsa_snap_test_SOURCES = main.vala

alsa_snap_test_VALAFLAGS = --target-glib 2.32 --vapidir=$(top_srcdir)/pkg --pkg gtk+-3.0 --pkg alsa

alsa_snap_test_CPPFLAGS  = -D_GNU_SOURCE
alsa_snap_test_CPPFLAGS += @GTK_CFLAGS@

alsa_snap_test_CFLAGS  = -D_GNU_SOURCE
alsa_snap_test_CFLAGS += @GTK_CFLAGS@
alsa_snap_test_CFLAGS += -I${top_srcdir}

alsa_snap_test_LDADD  = @GTK_LIBS@
alsa_snap_test_LDADD += ../alsa/libalsa.la

