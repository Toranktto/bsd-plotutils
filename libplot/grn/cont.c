/*
 * Copyright (c) 1980, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)cont.c	6.1 (Berkeley) 8/29/86";
#endif /* not lint */


#include "grnplot.h"
#include <plot.h>

void startvector(void);
void outcurxy(void);

/*---------------------------------------------------------
 *	Cont plots a line between (curx, cury) and (x, y).
 *
 *	Results:	None.
 *	Side Effects:	As above.
 *---------------------------------------------------------
 */
void
pl_cont(int x, int y)
{
	startvector();
	curx = x;
	cury = y;
	outcurxy();
}
