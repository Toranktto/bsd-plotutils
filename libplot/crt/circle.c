#ifndef lint
static char sccsid[] = "@(#)crtplot.c	4.1 (Berkeley) 11/11/83";
#endif

#include <plot.h>

void
pl_circle(int xc, int yc, int r)
{
	pl_arc(xc, yc, xc + r, yc, xc - r, yc);
	pl_arc(xc, yc, xc - r, yc, xc + r, yc);
}
