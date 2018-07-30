#ifndef lint
static char sccsid[] = "@(#)arc.c	4.1 (Berkeley) 6/27/83";
#endif

#include <plot.h>
#include <unistd.h>

extern int vti;

void
pl_arc(int xi, int yi, int x0, int y0, int x1, int y1)
{
	char c;

	c = 6;
	write(vti,&c,1);
	write(vti,&xi,12);
}
