/*
 * Copyright (c) 1980 Regents of the University of California. All rights
 * reserved.  The Berkeley software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef lint
static char	sccsid[] = "@(#)box.c	5.2 (Berkeley) 6/8/85";
#endif				/* not lint */

#include <plot.h>

void
pl_box_(int *x0, int *y0, int *x1, int *y1)
{
	/*
	 * pl_move(*x0, *y0); pl_cont(*x0, *y1); pl_cont(*x1, *y1);
	 * pl_cont(*x1, *y0); pl_cont(*x0, *y0); pl_move(*x1, *y1);
	 */

	pl_box(*x0, *y0, *x1, *y1);
}
