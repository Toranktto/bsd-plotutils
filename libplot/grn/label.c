/*
 * Copyright (c) 1980, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)label.c	6.1 (Berkeley) 8/29/86";
#endif /* not lint */

#include <plot.h>
#include "grnplot.h"
#include <string.h>

extern void outcurxy(void);
extern void endvector(void);

/*---------------------------------------------------------
 *	This routine places a label starting at the current
 *	position.
 *
 *	Results:	None.
 *
 *	Side Effects:
 *	The string indicated by s starting at (curx, cury).
 *	The current position is NOT updated.
 *---------------------------------------------------------
 */
void
label(char *s)
{
	if (!ingrnfile) erase();
	endvector();
	printf("BOTLEFT\n");
	outcurxy();
	printf("*\n%d %d\n%lu %s\n",FONTSTYLE,FONTSIZE,strlen(s)-1,s);
}
