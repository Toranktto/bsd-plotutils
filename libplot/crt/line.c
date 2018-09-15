/*
 * Copyright (c) 1980 Regents of the University of California. All rights
 * reserved.  The Berkeley software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef lint
static char	sccsid[] = "@(#)line.c	5.1 (Berkeley) 5/7/85";
#endif				/* not lint */

#include "crt.h"
#include <plot.h>

extern void	dda_line(char ch, int x0, int y0, int x1, int y1);

void
pl_line(int x0, int y0, int x1, int y1)
{
	plot_movech(y0, x0, '*');
	dda_line('*', scaleX(x0), scaleY(y0), scaleX(x1), scaleY(y1));
}
