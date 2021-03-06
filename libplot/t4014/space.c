#ifndef lint
static char	sccsid[] = "@(#)space.c	4.1 (Berkeley) 6/27/83";
#endif

#include <plot.h>

extern float	botx;
extern float	boty;
extern float	obotx;
extern float	oboty;
extern float	scalex;
extern float	scaley;
extern int	scaleflag;

void
pl_space(int x0, int y0, int x1, int y1)
{
	botx = 0.;
	boty = 0.;
	obotx = x0;
	oboty = y0;
	if (scaleflag)
		return;
	scalex = 3120. / (x1 - x0);
	scaley = 3120. / (y1 - y0);
}
