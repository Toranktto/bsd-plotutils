#ifndef lint
static char sccsid[] = "@(#)space.c	4.1 (Berkeley) 6/27/83";
#endif

#include <stdio.h>
#include <plot.h>

extern void putsi(int a);

void
space(int x0, int y0, int x1, int y1)
{
	putc('s',stdout);
	putsi(x0);
	putsi(y0);
	putsi(x1);
	putsi(y1);
}
