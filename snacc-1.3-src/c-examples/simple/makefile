# file: c-examples/simple/makefile
#
# WARNING: this makefile isn't safe for parallel making!
#
# $Header: /usr/app/odstb/CVS/snacc/c-examples/simple/makefile,v 1.6 1995/07/24 20:46:17 rj Exp $
# $Log: makefile,v $
# Revision 1.6  1995/07/24 20:46:17  rj
# useful.asn1 renamed to asn-useful.asn1 to accomodate to snacc's new file name generation scheme.
#
# `cd && make' instead of `cd; make'.
#
# changed `_' to `-' in file names.
#
# Revision 1.5  1995/02/20  11:50:49  rj
# build snacc if it doesn't exist.
# some makes leave a trailing slash on $(@D), others don't. this causes some mkdir(1)s to deny their cooperation. therefore, the slash has got to be stripped.
#
# Revision 1.4  1995/02/13  15:05:36  rj
# augment CPPFLAGS, not overwrite.
# use $(@D) and $(@F) instead of `dirname $@` and `basename $@` (not every system's got the commands).
# we need the compiler for the dependencies, so make it if it doesn't yet exist.
#
# Revision 1.3  1994/08/31  21:42:52  rj
# rebuild the executables when the c-lib they get linked against is newer.
# the file good-pr.ber needs to be distributed.
#
# Revision 1.2  1994/08/31  10:31:52  rj
# since .o files get moved, a few more dependencies are needed.
#
# Revision 1.1  1994/08/31  08:46:27  rj
# first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.
#

include ../../makehead

TOP		= ../..

ASN1_SRC_DIR	= $(TOP)/asn1specs

ASN1_C_LIB_DIR	= $(TOP)/c-lib
ASN1_C_INC_DIR	= $(ASN1_C_LIB_DIR)/inc
MBUF_ASN1_LIB	= $(ASN1_C_LIB_DIR)/libasn1cmbuf.a
SBUF_ASN1_LIB	= $(ASN1_C_LIB_DIR)/libasn1csbuf.a
EBUF_ASN1_LIB	= $(ASN1_C_LIB_DIR)/libasn1cebuf.a

COMPILERDIR	= $(TOP)/compiler
SNACC		= $(COMPILERDIR)/snacc
USEFUL_TYPES	= $(ASN1_SRC_DIR)/asn-useful.asn1
SNACCFLAGS	= -u $(USEFUL_TYPES)

CPPFLAGS	+= -I$(TOP) -I$(ASN1_C_INC_DIR) $(BUFFLAG) $(LENFLAG)

ASN1FILES	= $(ASN1_SRC_DIR)/p-rec.asn1
# generated by snacc from p-rec.asn1:
ASN1HFILES	= p-rec.h
ASN1CFILES	= p-rec.c

CFILES = \
	genber.c	\
	minbuf-ex.c	\
	expbuf-ex.c	\
	sbuf-ex.c

BUFFLAG		= -DUSE_SBUF

DISTFILES = \
	README		\
	makefile	\
	$(CFILES)	\
	good-pr.ber

#-------------------------------------------------------------------------------

all::		genber minbuf-def minbuf-indef expbuf-def expbuf-indef sbuf-def sbuf-indef

$(ASN1HFILES)	\
$(ASN1CFILES):	$(SNACC) $(ASN1FILES)
		$(REASON)
		$(SNACC) $(SNACCFLAGS) $(ASN1FILES)

$(SNACC):
		cd $(@D) && $(MAKE) $(@F)

min-def-obj	\
min-indef-obj	\
exp-def-obj	\
exp-indef-obj	\
s-def-obj	\
s-indef-obj:
		mkdir $@

min-def-obj/p-rec.o	\
min-def-obj/minbuf-ex.o:
		$(REASON)
		$(MAKE) BUFFLAG=-DUSE_MIN_BUF LENFLAG= `echo $(@D) | sed -e 's:/$$::'` $(@F)
		mv $(@F) $@

min-indef-obj/p-rec.o	\
min-indef-obj/minbuf-ex.o:
		$(REASON)
		$(MAKE) BUFFLAG=-DUSE_MIN_BUF LENFLAG=-DUSE_INDEF_LEN `echo $(@D) | sed -e 's:/$$::'` $(@F)
		mv $(@F) $@

exp-def-obj/p-rec.o	\
exp-def-obj/expbuf-ex.o:
		$(REASON)
		$(MAKE) BUFFLAG=-DUSE_EXP_BUF LENFLAG= `echo $(@D) | sed -e 's:/$$::'` $(@F)
		mv $(@F) $@

exp-indef-obj/p-rec.o	\
exp-indef-obj/expbuf-ex.o:
		$(REASON)
		$(MAKE) BUFFLAG=-DUSE_EXP_BUF LENFLAG=-DUSE_INDEF_LEN `echo $(@D) | sed -e 's:/$$::'` $(@F)
		mv $(@F) $@

s-def-obj/p-rec.o	\
s-def-obj/sbuf-ex.o:
		$(REASON)
		$(MAKE) LENFLAG= `echo $(@D) | sed -e 's:/$$::'` $(@F)
		mv $(@F) $@

s-indef-obj/p-rec.o	\
s-indef-obj/sbuf-ex.o:
		$(REASON)
		$(MAKE) LENFLAG=-DUSE_INDEF_LEN `echo $(@D) | sed -e 's:/$$::'` $(@F)
		mv $(@F) $@

genber:		s-def-obj/p-rec.o genber.o
		$(REASON)
		$(CC) $(LDFLAGS) -o $@ s-def-obj/p-rec.o genber.o $(SBUF_ASN1_LIB) $(LIBS)

minbuf-def: 	min-def-obj/p-rec.o min-def-obj/minbuf-ex.o
		$(REASON)
		$(CC) $(LDFLAGS) -o $@ min-def-obj/p-rec.o min-def-obj/minbuf-ex.o $(MBUF_ASN1_LIB) $(LIBS)

minbuf-indef:	min-indef-obj/p-rec.o min-indef-obj/minbuf-ex.o
		$(REASON)
		$(CC) $(LDFLAGS) -o $@ min-indef-obj/p-rec.o min-indef-obj/minbuf-ex.o $(MBUF_ASN1_LIB) $(LIBS)

expbuf-def: 	exp-def-obj/p-rec.o exp-def-obj/expbuf-ex.o
		$(REASON)
		$(CC) $(LDFLAGS) -o $@ exp-def-obj/p-rec.o exp-def-obj/expbuf-ex.o $(EBUF_ASN1_LIB) $(LIBS)

expbuf-indef:	exp-indef-obj/p-rec.o exp-indef-obj/expbuf-ex.o
		$(REASON)
		$(CC) $(LDFLAGS) -o $@ exp-indef-obj/p-rec.o exp-indef-obj/expbuf-ex.o $(EBUF_ASN1_LIB) $(LIBS)

sbuf-def: 	s-def-obj/p-rec.o s-def-obj/sbuf-ex.o
		$(REASON)
		$(CC) $(LDFLAGS) -o $@ s-def-obj/p-rec.o s-def-obj/sbuf-ex.o $(SBUF_ASN1_LIB) $(LIBS)

sbuf-indef:	s-indef-obj/p-rec.o s-indef-obj/sbuf-ex.o
		$(REASON)
		$(CC) $(LDFLAGS) -o $@ s-indef-obj/p-rec.o s-indef-obj/sbuf-ex.o $(SBUF_ASN1_LIB) $(LIBS)

genber		\
sbuf-def	\
sbuf-indef:	$(SBUF_ASN1_LIB)

minbuf-def	\
minbuf-indef:	$(MINBUF_ASN1_LIB)

expbuf-def	\
expbuf-indef:	$(EXPBUF_ASN1_LIB)

.PHONY:	check

check::		minbuf-def minbuf-indef expbuf-def expbuf-indef sbuf-def sbuf-indef
		for bt in min exp s; do\
		  $(RM) $$bt-foo.ber $$bt-bar.ber;\
		  ./$${bt}buf-indef good-pr.ber > $$bt-foo.ber;\
		  ./$${bt}buf-def $$bt-foo.ber > $$bt-bar.ber;\
		done
		@for bt in min exp s; do\
		  if cmp -s $$bt-bar.ber good-pr.ber; then\
		    echo "+++ Passed simple encode/decode tests using p-rec.asn1 with $${bt}bufs.";\
		  else\
		    echo "--- Failed simple encode/decode tests using p-rec.asn1 with $${bt}bufs.";\
		  fi;\
		  $(RM) $$bt-foo.ber $$bt-bar.ber;\
		done

clean::
		$(RM) *.o *~ core .emacs*
		$(RM) expbuf-def expbuf-indef sbuf-indef sbuf-def minbuf-def minbuf-indef genber pr.ber $(ASN1HFILES) $(ASN1CFILES)
		$(RM) -r *-def-obj *-indef-obj
		$(RM) *-foo.ber *-bar.ber

depend::	$(SNACC)

include ../../maketail

depend::
		cp dependencies deps
		for dir in min-def-obj min-indef-obj exp-def-obj exp-indef-obj s-def-obj s-indef-obj; do\
		  < dependencies sed -e 's:^\(.*\.o\):'"$$dir"'/\1:' >> deps;\
		done
		mv deps dependencies
