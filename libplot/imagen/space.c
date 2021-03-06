/*
 * Copyright (c) 1985 Regents of the University of California. All rights
 * reserved.  The Berkeley software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef lint
static char	sccsid[] = "@(#)space.c	5.2 (Berkeley) 9/21/85";
#endif				/* not lint */

#include <plot.h>

extern float	botx;
extern float	boty;
extern float	obotx;
extern float	oboty;
extern float	scalex;
extern float	scaley;

int		PlotRes = DEFRES;

int		scaleflag;

void
pl_space(int x0, int y0, int x1, int y1)
{
	botx = 2.;
	boty = 2.;
	obotx = x0;
	oboty = y0;
	if (scaleflag)
		return;
	scalex = (8.0 * PlotRes) / (x1 - x0);
	scaley = (8.0 * PlotRes) / (y1 - y0);
}
