#ifndef lint
static char sccsid[] = "@(#)crtplot.c	4.1 (Berkeley) 11/11/83";
#endif /* not lint */

#include "crt.h"
#include <plot.h>

void
pl_space(int x0, int y0, int x1, int y1)
{
	lowX = (double) x0;
	lowY = (double) y0;
	rangeX = COLS/(double) (x1 - x0);
	rangeY = LINES/(double) (y1 - y0);
}
