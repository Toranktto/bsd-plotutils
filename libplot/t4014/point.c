#ifndef lint
static char sccsid[] = "@(#)point.c	4.1 (Berkeley) 6/27/83";
#endif

#include <plot.h>

void
point(int xi, int yi)
{
	move(xi,yi);
	cont(xi,yi);
}
