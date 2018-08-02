#ifndef lint
static char sccsid[] = "@(#)move.c	4.1 (Berkeley) 6/27/83";
#endif

#include <plot.h>

extern void putch(int c);

void
pl_move(int xi, int yi)
{
	putch(035);
	pl_cont(xi, yi);
}
