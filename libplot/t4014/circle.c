#ifndef lint
static char sccsid[] = "@(#)circle.c	4.1 (Berkeley) 6/27/83";
#endif

#include <plot.h>

void
circle(int x, int y, int r)
{
	arc(x,y,x+r,y,x+r,y);
}
