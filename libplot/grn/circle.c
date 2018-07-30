/*
 * Copyright (c) 1980, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)circle.c	6.1 (Berkeley) 8/29/86";
#endif /* not lint */

#include <plot.h>
#include "grnplot.h"

extern void outxy(int x, int y);
extern void endvector(void);

/*---------------------------------------------------------
 *	Circle draws a circle.
 *
 *	Results:	None.
 *
 *	Side Effects:
 *	A circle of radius r is drawn at (x,y).
 *	The current position is set to (x,y);
 *---------------------------------------------------------
 */
void
pl_circle(int x, int y, int r)
{
	if (!ingrnfile) pl_erase();
	endvector();
	printf("ARC\n");
	outxy(x,y);
	outxy(x+r,y);
	outxy(x,y+r);
	outxy(x,y-r);
	outxy(x+r,y);
	outxy(x-r,y);
	printf("*\n%d 0\n0\n",linestyle);
	curx=x;
	cury=y;
}
