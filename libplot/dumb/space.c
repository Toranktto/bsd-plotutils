/*
 * Copyright (c) 1980 Regents of the University of California. All rights
 * reserved.  The Berkeley software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef lint
static char	sccsid[] = "@(#)space.c	5.1 (Berkeley) 5/7/85";
#endif				/* not lint */

#include "dumb.h"
#include <plot.h>

void
pl_space(int x0, int y0, int x1, int y1)
{
	minX = x0;
	rangeX = x1 - x0;
	minY = y0;
	rangeY = y1 - y0;
}
