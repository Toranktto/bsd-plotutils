#ifndef lint
static char sccsid[] = "@(#)point.c	4.1 (Berkeley) 6/27/83";
#endif

#include <plot.h>
#include <unistd.h>

extern int vti;
extern int xnow, ynow;
extern int xsc(int xi);
extern int ysc(int yi);

void
pl_point(int xi, int yi)
{
	struct { char pad, c; int x, y; } p;
	p.c = 2;
	p.x = xnow = xsc(xi);
	p.y = ynow = ysc(yi);
	write(vti, &p.c, 5);
}
