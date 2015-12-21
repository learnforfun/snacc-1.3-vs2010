/*
 * file: tcl-p.c
 * purpose: check and return via exit code whether the tcl interface needs to be made
 *
 * $Header: /usr/app/odstb/CVS/snacc/tcl-p.c,v 1.1 1995/07/25 22:24:48 rj Exp $
 * $Log: tcl-p.c,v $
 * Revision 1.1  1995/07/25 22:24:48  rj
 * new file
 *
 */

#define COMPILER	1

#include "snacc.h"

main()
{
#if TCL
  return 0;
#else
  return 1;
#endif
}
