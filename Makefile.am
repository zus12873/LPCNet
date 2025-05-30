ACLOCAL_AMFLAGS = -I m4

AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/src $(DEPS_CFLAGS)

dist_doc_DATA = COPYING AUTHORS README README.md

include_HEADERS = include/lpcnet.h

lib_LTLIBRARIES = liblpcnet.la
noinst_HEADERS = src/arch.h  \
		 src/burg.h \
		 src/common.h  \
		 src/freq.h  \
		 src/_kiss_fft_guts.h  \
		 src/kiss_fft.h  \
		 src/kiss99.h  \
		 src/lpcnet_private.h \
		 src/opus_types.h  \
		 src/nnet_data.h  \
		 src/plc_data.h  \
		 src/nnet.h  \
		 src/pitch.h  \
		 src/tansig_table.h \
		 src/vec.h \
		 src/vec_avx.h \
		 src/vec_neon.h

liblpcnet_la_SOURCES = \
	src/burg.c \
	src/common.c \
	src/kiss99.c \
	src/lpcnet.c \
	src/lpcnet_dec.c \
	src/lpcnet_enc.c \
	src/lpcnet_tables.c \
	src/nnet.c \
	src/nnet_data.c \
	src/plc_data.c \
	src/ceps_codebooks.c \
	src/pitch.c \
	src/parse_lpcnet_weights.c \
	src/freq.c \
	src/kiss_fft.c \
	src/lpcnet_plc.c

liblpcnet_la_LIBADD = $(DEPS_LIBS) $(lrintf_lib) $(LIBM)
liblpcnet_la_LDFLAGS = -no-undefined \
 -version-info @OP_LT_CURRENT@:@OP_LT_REVISION@:@OP_LT_AGE@

noinst_PROGRAMS = lpcnet_demo dump_data dump_weights_blob

lpcnet_demo_SOURCES = src/lpcnet_demo.c src/freq.c src/kiss_fft.c src/burg.c src/common.c src/lpcnet_tables.c
lpcnet_demo_LDADD = liblpcnet.la $(DEPS_LIBS) $(LIBM)
lpcnet_demo_CFLAGS = $(AM_CFLAGS)


#DUMP_SOURCES = src/freq.c src/kiss_fft.c src/pitch.c src/lpcnet_dec.c src/lpcnet_enc.c src/ceps_codebooks.c src/common.c
#DUMP_OBJ = $(DUMP_SOURCES:.c=.lo)
#dump_data_SOURCES = src/dump_data.c
#dump_data_LDADD = $(DUMP_OBJ) $(LIBM)

dump_data_SOURCES = src/common.c src/dump_data.c src/burg.c src/freq.c src/kiss_fft.c src/pitch.c src/lpcnet_dec.c src/lpcnet_enc.c src/lpcnet_tables.c src/ceps_codebooks.c
dump_data_LDADD = $(LIBM)
dump_data_CFLAGS = $(AM_CFLAGS)

dump_weights_blob_SOURCES = src/write_lpcnet_weights.c
dump_weights_blob_LDADD = $(LIBM)
dump_weights_blob_CFLAGS = $(AM_CFLAGS) -DDUMP_BINARY_WEIGHTS

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = lpcnet.pc

debug:
	$(MAKE) CFLAGS="${CFLAGS} -O0 -ggdb -DOP_ENABLE_ASSERTIONS" all

EXTRA_DIST = \
 lpcnet.pc.in \
 lpcnet-uninstalled.pc.in \
 doc/Doxyfile.in \
 doc/Makefile

# Targets to build and install just the library without the docs
liblpcnet install-liblpcnet: NO_DOXYGEN = 1

lpcnet: all
install-lpcnet: install

# Or just the docs
docs: doc/doxygen-build.stamp

install-docs:
	@if [ -z "$(NO_DOXYGEN)" ]; then \
	  ( cd doc && \
	    echo "Installing documentation in $(DESTDIR)$(docdir)"; \
	    $(INSTALL) -d $(DESTDIR)$(docdir)/html/search; \
	    for f in `find html -type f \! -name "installdox"` ; do \
	      $(INSTALL_DATA) $$f $(DESTDIR)$(docdir)/$$f;     \
	    done ) \
	fi

doc/doxygen-build.stamp: doc/Doxyfile \
                         $(top_srcdir)/include/*.h
	@[ -n "$(NO_DOXYGEN)" ] || ( cd doc && doxygen && touch $(@F) )


if HAVE_DOXYGEN

# Or everything (by default)
all-local: docs

install-data-local: install-docs

clean-local:
	$(RM) -r doc/html
	$(RM) -r doc/latex
	$(RM) doc/doxygen-build.stamp

uninstall-local:
	$(RM) -r $(DESTDIR)$(docdir)/html

endif

# We check this every time make is run, with configure.ac being touched to
# trigger an update of the build system files if update_version changes the
# current PACKAGE_VERSION (or if package_version was modified manually by a
# user with either AUTO_UPDATE=no or no update_version script present - the
# latter being the normal case for tarball releases).
#
# We can't just add the package_version file to CONFIGURE_DEPENDENCIES since
# simply running autoconf will not actually regenerate configure for us when
# the content of that file changes (due to autoconf dependency checking not
# knowing about that without us creating yet another file for it to include).
#
# The MAKECMDGOALS check is a gnu-make'ism, but will degrade 'gracefully' for
# makes that don't support it.  The only loss of functionality is not forcing
# an update of package_version for `make dist` if AUTO_UPDATE=no, but that is
# unlikely to be a real problem for any real user.
$(top_srcdir)/configure.ac: force
	@case "$(MAKECMDGOALS)" in \
	    dist-hook)                             exit 0       ;; \
	    dist-* | dist | distcheck | distclean) _arg=release ;; \
	esac; \
	if ! $(top_srcdir)/update_version $$_arg 2> /dev/null; then \
	    if [ ! -e $(top_srcdir)/package_version ]; then \
		echo 'PACKAGE_VERSION="unknown"' > $(top_srcdir)/package_version; \
	    fi; \
	    . $(top_srcdir)/package_version || exit 1; \
	    [ "$(PACKAGE_VERSION)" != "$$PACKAGE_VERSION" ] || exit 0; \
	fi; \
	touch $@

force:

# Create a minimal package_version file when make dist is run.
dist-hook:
	echo 'PACKAGE_VERSION="$(PACKAGE_VERSION)"' > $(top_distdir)/package_version


.PHONY: lpcnet install-lpcnet docs install-docs
