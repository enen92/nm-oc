libexec_PROGRAMS = \
	nm-openconnect-service \
	nm-openconnect-service-csd-wrapper \
	nm-openconnect-service-openconnect-helper

AM_CPPFLAGS = \
	$(GLIB_CFLAGS) \
	$(LIBNM_CFLAGS) \
	-DBINDIR=\"$(bindir)\" \
	-DPREFIX=\""$(prefix)"\" \
	-DSYSCONFDIR=\""$(sysconfdir)"\" \
	-DLIBDIR=\""$(libdir)"\" \
	-DLIBEXECDIR=\""$(libexecdir)"\" \
	-DLOCALSTATEDIR=\""$(localstatedir)"\" \
	-DDATADIR=\"$(datadir)\" \
	-DNM_OPENCONNECT_LOCALEDIR=\"$(datadir)/locale\" \
	-I"$(top_srcdir)"/shared \
	$(NULL)

###############################################################################

noinst_LTLIBRARIES = libnm-openconnect-csd-service-dbus.la

nodist_libnm_openconnect_csd_service_dbus_la_SOURCES = \
	nm-openconnect-csd-service-dbus.c \
	nm-openconnect-csd-service-dbus.h

libnm_openconnect_csd_service_dbus_la_CPPFLAGS = \
	$(cppflags) \
	$(filter-out -DGLIB_VERSION_MAX_ALLOWED%,$(AM_CPPFLAGS))

nm-openconnect-csd-service-dbus.h: nm-openconnect-csd-service.xml
	$(AM_V_GEN) gdbus-codegen \
		--generate-c-code $(basename $@) \
		--c-namespace NMDBus \
		--interface-prefix org.freedesktop.NetworkManager \
		$<

nm-openconnect-csd-service-dbus.c: nm-openconnect-csd-service-dbus.h
	@true

###############################################################################

nm_openconnect_service_csd_wrapper_SOURCES = \
	nm-openconnect-service-csd-wrapper.c \
	nm-openconnect-service.h \
	$(NULL)

nm_openconnect_service_csd_wrapper_LDADD = \
	libnm-openconnect-csd-service-dbus.la \
	$(GLIB_LIBS)

###############################################################################

nm_openconnect_service_SOURCES = \
	$(top_srcdir)/shared/nm-utils/nm-shared-utils.c \
	$(top_srcdir)/shared/nm-utils/nm-shared-utils.h \
	nm-openconnect-service.c \
	nm-openconnect-service.h \
	$(NULL)

nm_openconnect_service_LDADD = \
	libnm-openconnect-csd-service-dbus.la \
	$(GLIB_LIBS) \
	$(LIBNM_LIBS)

###############################################################################

nm_openconnect_service_openconnect_helper_SOURCES = \
	$(top_srcdir)/shared/nm-utils/nm-shared-utils.c \
	$(top_srcdir)/shared/nm-utils/nm-shared-utils.h \
	nm-openconnect-service-openconnect-helper.c

nm_openconnect_service_openconnect_helper_LDADD = \
	$(GTHREAD_LIBS) \
	$(LIBNM_LIBS)

###############################################################################

BUILT_SOURCES = \
	nm-openconnect-csd-service-dbus.h \
	nm-openconnect-csd-service-dbus.c

CLEANFILES = \
	nm-openconnect-csd-service-dbus.h \
	nm-openconnect-csd-service-dbus.c \
	*~

EXTRA_DIST = \
	nm-openconnect-csd-service.xml
