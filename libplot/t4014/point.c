#ifndef lint
static char sccsid[] = "@(#)point.c	4.1 (Berkeley) 6/27/83";
#endif

#include <plot.h>

void
pl_point(int xi, int yi)
{
	pl_move(xi, yi);
	pl_cont(xi, yi);
}
