/*
 * Copyright (c) 1980 Regents of the University of California. All rights
 * reserved.  The Berkeley software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef lint
static char	sccsid[] = "@(#)circle.c	5.1 (Berkeley) 5/7/85";
#endif				/* not lint */

#include "hp7221.h"
#include <plot.h>

extern void	putMBN(int i);

void
pl_circle(int xc, int yc, int r)
{
	if (r < 1) {
		pl_point(xc, yc);
		return;
	}
	pl_move(xc, yc);
	putchar('t');
	putMBN(scaleX(r));
}
