#ifndef lint
static char	sccsid[] = "@(#)arc.c	4.1 (Berkeley) 6/27/83";
#endif

#include <stdio.h>
#include <plot.h>

extern void	putsi(int a);

void
pl_arc(int xi, int yi, int x0, int y0, int x1, int y1)
{
	putc('a', stdout);
	putsi(xi);
	putsi(yi);
	putsi(x0);
	putsi(y0);
	putsi(x1);
	putsi(y1);
}
