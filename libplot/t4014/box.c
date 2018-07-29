#ifndef lint
static char sccsid[] = "@(#)box.c	4.1 (Berkeley) 6/27/83";
#endif

#include <plot.h>

void
box(int x0, int y0, int x1, int y1)
{
	move(x0, y0);
	cont(x0, y1);
	cont(x1, y1);
	cont(x1, y0);
	cont(x0, y0);
	move(x1, y1);
}
