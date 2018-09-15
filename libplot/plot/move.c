#ifndef lint
static char	sccsid[] = "@(#)move.c	4.1 (Berkeley) 6/27/83";
#endif

#include <stdio.h>
#include <plot.h>

extern void	putsi(int a);

void
pl_move(int xi, int yi)
{
	putc('m', stdout);
	putsi(xi);
	putsi(yi);
}
