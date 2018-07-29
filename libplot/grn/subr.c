/*
 * Copyright (c) 1980, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)subr.c	6.1 (Berkeley) 8/29/86";
#endif /* not lint */


#include "grnplot.h"
#include <plot.h>


/*---------------------------------------------------------
 *	This local routine outputs an x-y coordinate pair in the standard
 *	format required by the grn file.
 *
 *	Results:	None.
 *	
 *	Side Effects:
 *
 *	Errors:		None.
 *---------------------------------------------------------
 */

/* The coordinates to be output.  Note:
 * these are world coordinates, not screen
 * ones.  We scale in this routine.
 */
void
outxy(int x, int y)
{
    printf("%.2f %.2f\n", (x - xbot)*scale,(y - ybot)*scale);
}

void
outcurxy(void)
{
	outxy(curx,cury);
}

void
startvector(void)
{
	if (!ingrnfile) erase();
	if (invector) return;
	invector = 1;
	printf("VECTOR\n");
	outcurxy();
}

void
endvector(void)
{
	if (!invector) return;
	invector = 0;
	printf("*\n%d 0\n0\n",linestyle);
}
