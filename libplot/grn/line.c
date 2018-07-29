/*
 * Copyright (c) 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)line.c	6.1 (Berkeley) 8/29/86";
#endif not lint

#include "grnplot.h"

/*---------------------------------------------------------
 *	Line draws a line between two points.
 *
 *	Results:	None.
 *
 *	Side Effects:
 *	A line is drawn on the screen between (x1, y1) and (x2, y2).
 *---------------------------------------------------------
 */
void
line(int x1, int y1, int x2, int y2)
{
	move(x1,y1);
	cont(x2,y2);
}
