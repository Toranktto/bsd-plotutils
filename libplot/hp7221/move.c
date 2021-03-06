/*
 * Copyright (c) 1980 Regents of the University of California. All rights
 * reserved.  The Berkeley software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef lint
static char	sccsid[] = "@(#)move.c	5.1 (Berkeley) 5/7/85";
#endif				/* not lint */

#include "hp7221.h"
#include <plot.h>

extern void	putMBP(int x, int y);

void
pl_move(int xi, int yi)
{
	currentx = scaleX(xi);
	currenty = scaleY(yi);
	putchar('p');
	putMBP(currentx, currenty);
}
