/*
 * Copyright (c) 1985 Regents of the University of California. All rights
 * reserved.  The Berkeley software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef lint
static char	sccsid[] = "@(#)circle.c	5.1 (Berkeley) 9/21/85";
#endif				/* not lint */

#include <plot.h>

void
pl_circle(int x, int y, int r)
{
	pl_arc(x, y, x + r, y, x + r, y);
}
