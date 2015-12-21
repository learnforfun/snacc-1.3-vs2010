# file: tkuti.tcl
# miscellaneous Tk utilities.
#
# $Header: /usr/app/odstb/CVS/snacc/tcl-lib/tkuti.tcl,v 1.1 1997/01/01 23:12:03 rj Exp $
# $Log: tkuti.tcl,v $
# Revision 1.1  1997/01/01 23:12:03  rj
# first check-in
#

proc getpos {w xn yn} \
{
  upvar $xn x $yn y
  set geom [wm geometry $w]
  scan $geom {%dx%d+%d+%d} w h x y
}
