#ifndef lint
static char sccsid[] = "@(#)close.c	4.1 (Berkeley) 6/27/83";
#endif

#include <stdio.h>
#include <plot.h>

extern void putch(int c);

void
pl_closevt(void)
{
	putch(037);
	fflush(stdout);
}

void
pl_closepl(void)
{
	putch(037);
	fflush(stdout);
}
