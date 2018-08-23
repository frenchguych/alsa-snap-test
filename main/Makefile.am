bin_PROGRAMS = alsasnaptest
alsasnaptest_SOURCES = main.vala

alsasnaptest_VALAFLAGS = --target-glib 2.32 --vapidir=$(top_srcdir)/pkg --pkg gtk+-3.0 --pkg alsa

alsasnaptest_CPPFLAGS  = -D_GNU_SOURCE
alsasnaptest_CPPFLAGS += @GTK_CFLAGS@

alsasnaptest_CFLAGS  = -D_GNU_SOURCE
alsasnaptest_CFLAGS += @GTK_CFLAGS@
alsasnaptest_CFLAGS += -I${top_srcdir}

alsasnaptest_LDADD  = @GTK_LIBS@
alsasnaptest_LDADD += ../alsa/libalsa.la

