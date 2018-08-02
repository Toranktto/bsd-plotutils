/*
 * Copyright (c) 1980, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)close.c	6.1 (Berkeley) 8/29/86";
#endif /* not lint */


#include "grnplot.h"
#include <plot.h>

extern void endvector(void);

/*---------------------------------------------------------
 *	Closepl ends the gremlin file
 *
 *	Results:	None.
 *
 *	Side Effects:
 *---------------------------------------------------------
 */
void
pl_closepl(void)
{
	if (!ingrnfile) return;
	endvector();
	printf("-1\n");
	ingrnfile = 0;
}

void
pl_closevt(void)
{
	if (!ingrnfile) return;
	endvector();
	printf("-1\n");
	ingrnfile = 0;
}
