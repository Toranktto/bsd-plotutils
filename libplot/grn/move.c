/*
 * Copyright (c) 1980, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)move.c	6.1 (Berkeley) 8/29/86";
#endif /* not lint */


#include "grnplot.h"
#include <plot.h>

extern void endvector(void);

/*---------------------------------------------------------
 *	This routine moves the current point to (x,y).
 *
 *	Results:	None.
 *	Side Effects:	If current line, close it.
 *---------------------------------------------------------
 */
void
pl_move(int x, int y)
{
	if (!ingrnfile) pl_erase();
	if (invector) endvector();
	curx = x;
	cury = y;
}
