/*
 * Copyright (c) 1980, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)space.c	6.1 (Berkeley) 8/29/86";
#endif /* not lint */


#include "grnplot.h"
#include <plot.h>

/*---------------------------------------------------------
 *	Space sets up the world-to-screen transformation so
 *	that the rectangular area described by (x0, y0) and
 *	(x1, y1) will all be on-screen.
 *
 *	Results:	None.
 *
 *	Side Effects:
 *	Our own variables scale, xbot, and ybot are changed.
 *---------------------------------------------------------
 */
void
pl_space(int x0, int y0, int x1, int y1)
{
    double xscale=0.0, yscale=0.0;
    if (x1>x0)
	    xscale = GRXMAX/(double)(x1-x0);
    if (y1>y0)
	    yscale = GRYMAX/(double)(y1-y0);
    scale = (xscale > yscale && yscale > 0)? yscale : xscale;
    if (scale == 0.0) /* scale == 1.0; */ scale = 1.0;
    xbot = x0;
    ybot = y0;
}
