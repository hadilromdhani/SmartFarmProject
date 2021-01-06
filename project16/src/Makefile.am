## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = project16

project16_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	trp.c trp.h \
	plante.c plante.h \
	fonct.c fonct.h \
	ouvrier.c ouvrier.h \
	capteur.c capteur.h

project16_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

