/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)line.c	5.1 (Berkeley) 5/7/85";
#endif /* not lint */

#include "dumb.h"
#include <plot.h>

extern void dda_line(char ch, int x0, int y0, int x1, int y1);
extern int plotChar;

void
line(int x0, int y0, int x1, int y1)
{
	int x,y;

	scale(x0, y0);
	x = x1;
	y = y1;
	scale(x, y);
	currentx = x0;
	currenty = y0;
	screenmat[currentx][currenty] = plotChar;
	dda_line(plotChar, x0, y0, x1, y1);
}
