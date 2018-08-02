#ifndef lint
static char sccsid[] = "@(#)point.c	4.1 (Berkeley) 6/27/83";
#endif

#include <stdio.h>
#include <plot.h>

extern void putsi(int a);

void
pl_point(int xi, int yi)
{
	putc('p', stdout);
	putsi(xi);
	putsi(yi);
}
