#ifndef lint
static char sccsid[] = "@(#)circle.c	4.1 (Berkeley) 6/27/83";
#endif

#include <stdio.h>
#include <plot.h>

extern void putsi(int a);

void
pl_circle(int x, int y, int r)
{
	putc('c', stdout);
	putsi(x);
	putsi(y);
	putsi(r);
}
