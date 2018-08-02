#ifndef lint
static char sccsid[] = "@(#)space.c	4.2 (Berkeley) 11/10/83";
#endif

#include <plot.h>

extern float boty;
extern float botx;
extern float oboty;
extern float obotx;
extern float scalex;
extern float scaley;
float deltx = 4095.;
float delty = 4095.;

void
pl_space(int x0, int y0, int x1, int y1)
{
	botx = -2047.;
	boty = -2047;
	obotx = x0;
	oboty = y0;
	scalex = deltx / (x1 - x0);
	scaley = delty / (y1 - y0);
}
