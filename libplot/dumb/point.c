/*
 * Copyright (c) 1980 Regents of the University of California. All rights
 * reserved.  The Berkeley software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef lint
static char	sccsid[] = "@(#)point.c	5.1 (Berkeley) 5/7/85";
#endif				/* not lint */

#include "dumb.h"
#include <plot.h>

void
pl_point(int x, int y)
{
	scale(x, y);
	currentx = x;
	currenty = y;
	screenmat[currentx][currenty] = '*';
}
