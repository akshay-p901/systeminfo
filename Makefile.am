#AUTOMAKE_OPTIONS = foreign
AUTOMAKE_OPTIONS = subdir-objects
# Ram need to check if separate include directory is needed or not
AM_CXXFLAGS = $(GLIB_CFLAGS) $(GTHREAD_CFLAGS) $(NLMONITOR_CFLAGS) $(NL_CFLAGS)

AM_CXXFLAGS += $(IARM_CFLAGS)

AM_LDFLAGS = $(GLIB_LDFLAGS) $(GLIB_LIBS) \
	$(G_THREAD_LIBS) -lrdkloggers $(LOG4C_LIBS) -lpthread -lcjson -lsqlite3

AM_LDFLAGS += $(IARM_LFLAGS)
AM_CFLAGS =  $(GLIB_CFLAGS) $(GTHREAD_CFLAGS)
AM_CPPFLAGS =  $(GLIB_CFLAGS) $(GTHREAD_CFLAGS)

# the list of header files that belong to the library (to be installed later)
include_HEADERS = systemInfoIarm.h

bin_PROGRAMS = systeminfo
systeminfo_SOURCES = systemInfoMain.cpp
