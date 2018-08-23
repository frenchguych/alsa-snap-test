bin_PROGRAMS = picaster
picaster_SOURCES = main.vala

picaster_VALAFLAGS = --target-glib 2.32 --vapidir=$(top_srcdir)/pkg --pkg gtk+-3.0 --pkg picasteralsa

picaster_CPPFLAGS  = -D_GNU_SOURCE
picaster_CPPFLAGS += @GTK_CFLAGS@

picaster_CFLAGS  = -D_GNU_SOURCE
picaster_CFLAGS += @GTK_CFLAGS@
picaster_CFLAGS += -I${top_srcdir}

picaster_LDADD  = @GTK_LIBS@
picaster_LDADD += ../alsa/libpicasteralsa.la

