/*
 * Copyright (c) 1980, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)arc.c	6.1 (Berkeley) 8/29/86";
#endif /* not lint */

#include "grnplot.h"
#include <math.h>
#include <plot.h>

extern void outxy(int x, int y);
extern void endvector(void);

void
arc(int x, int y, int x0, int y0, int x1, int y1)
{
	if (!ingrnfile) erase();
	endvector();
	printf("ARC\n");
	outxy(x,y);
	outxy(x0,y0);
	outxy(x1,y1);
	printf("*\n%d %d\n0\n",linestyle,(int) (atan2(x1-x,y1-y)-atan2(x0-x,y0-y)));
	curx =x;
	cury =y;
}
