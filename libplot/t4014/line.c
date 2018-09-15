#ifndef lint
static char	sccsid[] = "@(#)line.c	4.1 (Berkeley) 6/27/83";
#endif

#include <plot.h>

void
pl_line(int x0, int y0, int x1, int y1)
{
	pl_move(x0, y0);
	pl_cont(x1, y1);
}
