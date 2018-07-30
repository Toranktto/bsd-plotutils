#ifndef lint
static char sccsid[] = "@(#)cont.c	4.1 (Berkeley) 6/27/83";
#endif

#include <stdio.h>
#include <plot.h>

extern void putsi(int a);

void
pl_cont(int xi, int yi)
{
	putc('n',stdout);
	putsi(xi);
	putsi(yi);
}
