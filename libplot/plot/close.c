#ifndef lint
static char sccsid[] = "@(#)close.c	4.1 (Berkeley) 6/27/83";
#endif

#include <stdio.h>
#include <plot.h>

void
pl_closevt(void)
{
	pl_closepl();
}

void
pl_closepl(void)
{
	fflush(stdout);
}
