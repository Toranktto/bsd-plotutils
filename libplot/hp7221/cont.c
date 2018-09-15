/*
 * Copyright (c) 1980 Regents of the University of California. All rights
 * reserved.  The Berkeley software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef lint
static char	sccsid[] = "@(#)cont.c	5.1 (Berkeley) 5/7/85";
#endif				/* not lint */

#include "hp7221.h"
#include <plot.h>

extern void	putMBP(int x, int y);

void
pl_cont(int xi, int yi)
{
	currentx = scaleX(xi);
	currenty = scaleY(yi);
	putchar('q');
	putMBP(currentx, currenty);
}
