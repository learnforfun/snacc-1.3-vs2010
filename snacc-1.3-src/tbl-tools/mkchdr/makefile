# file: .../tbl-tools/mkchdr/makefile
#
# $Header: /usr/app/odstb/CVS/snacc/tbl-tools/mkchdr/makefile,v 1.1 1997/02/15 19:05:28 rj Exp $
# $Log: makefile,v $
# Revision 1.1  1997/02/15 19:05:28  rj
# first check-in
#

include ../../makehead

TOP		= ../..

ASN1_C_LIB_DIR	= $(TOP)/c-lib
ASN1_C_INC_DIR	= $(ASN1_C_LIB_DIR)/inc
TTBL_ASN1_LIB	= $(ASN1_C_LIB_DIR)/libasn1ctbl.a

CFILES = \
	mkchdr.c	\
	tbl-gen-c-hdr.c

OFILES = \
	mkchdr.o	\
	tbl-gen-c-hdr.o

DISTFILES = \
	README		\
	makefile	\
	$(CFILES)

BUFFLAG		= -DUSE_SBUF

CPPFLAGS	+= -I$(TOP) -I$(ASN1_C_INC_DIR) $(BUFFLAG)

#-------------------------------------------------------------------------------

all::		mkchdr

mkchdr:		$(OFILES) $(TTBL_ASN1_LIB)
		$(REASON)
		$(CC) $(LDFLAGS) -o $@ $(OFILES) $(TTBL_ASN1_LIB) $(LIBS)

$(TTBL_ASN1_LIB):
		cd $(@D) && $(MAKE) tbl-lib

install-sh:
		ln $(TOP)/install-sh $@

$(bindir):
		$(TOP)/mkinstalldirs $@

install::	mkchdr install-sh $(bindir)

install::
		$(INSTALL_PROGRAM) mkchdr $(bindir)/

clean::
		$(RM) *.o *~ core .emacs*

clobber::
		$(RM) mkchdr

include ../../maketail
