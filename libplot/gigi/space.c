/*
 * Copyright (c) 1980 Regents of the University of California. All rights
 * reserved.  The Berkeley software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef lint
static char	sccsid[] = "@(#)space.c	5.1 (Berkeley) 5/7/85";
#endif				/* not lint */

#include "gigi.h"
#include <plot.h>

void
pl_space(int x0, int y0, int x1, int y1)
{
	lowx = x0;
	lowy = y0;
	scalex = XMAX / (x1 - lowx);
	scaley = YMAX / (y1 - lowy);
}
