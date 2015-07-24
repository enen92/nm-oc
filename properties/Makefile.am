plugindir = $(libdir)/NetworkManager
plugin_LTLIBRARIES = libnm-openconnect-properties.la
if WITH_LIBNM_GLIB
plugin_LTLIBRARIES += libnm-openconnect-properties-old.la
endif

libnm_openconnect_properties_la_SOURCES = \
	auth-helpers.c \
	auth-helpers.h \
	nm-openconnect.c \
	nm-openconnect.h

libnm_openconnect_properties_old_la_SOURCES = \
	$(libnm_openconnect_properties_la_SOURCES)

uidir = $(datadir)/gnome-vpn-properties/openconnect
ui_DATA = nm-openconnect-dialog.ui

common_CFLAGS =                                         \
	$(GLIB_CFLAGS)                                  \
	$(GTK_CFLAGS)                                   \
	$(OPENCONNECT_CFLAGS)                           \
	-I$(top_srcdir)/src                             \
	-DICONDIR=\""$(datadir)/pixmaps"\"              \
	-DUIDIR=\""$(uidir)"\"                          \
	-DG_DISABLE_DEPRECATED                          \
	-DGDK_DISABLE_DEPRECATED                        \
	-DLOCALEDIR=\"$(datadir)/locale\"               \
	-DVERSION=\"$(VERSION)\"

libnm_openconnect_properties_la_CFLAGS =                \
	$(common_CFLAGS)                                \
	$(LIBNM_CFLAGS)

libnm_openconnect_properties_old_la_CFLAGS =            \
	-DNM_OPENCONNECT_OLD                            \
	$(common_CFLAGS)                                \
	$(LIBNM_GLIB_CFLAGS)

libnm_openconnect_properties_la_LIBADD = \
	$(GTK_LIBS) \
	$(LIBNM_LIBS) \
	$(OPENCONNECT_LIBS)

libnm_openconnect_properties_old_la_LIBADD = \
	$(GTK_LIBS) \
	$(LIBNM_GLIB_LIBS) \
	$(OPENCONNECT_LIBS)

libnm_openconnect_properties_la_LDFLAGS = \
	-avoid-version

libnm_openconnect_properties_old_la_LDFLAGS = \
	$(libnm_openconnect_properties_la_LDFLAGS)

CLEANFILES = *.bak *~

EXTRA_DIST =                            \
	$(ui_DATA)
