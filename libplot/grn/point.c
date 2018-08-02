/*
 * Copyright (c) 1980, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)point.c	6.1 (Berkeley) 8/29/86";
#endif /* not lint */


#include "grnplot.h"
#include <plot.h>

/*---------------------------------------------------------
 *	This routine plots a single point.
 *
 *	Results:	None.
 *
 *	Side Effects:
 *	A single point is displayed on the screen.
 *	The point is made the current point.
 *---------------------------------------------------------
 */
void
pl_point(int x, int y)
{
	pl_move(x, y);
	pl_label(POINTSTRING);
}
