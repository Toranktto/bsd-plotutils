/*
 * Copyright (c) 1980 Regents of the University of California. All rights
 * reserved.  The Berkeley software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef lint
static char	sccsid[] = "@(#)close.c	5.2 (Berkeley) 4/30/85";
#endif				/* not lint */


#include <signal.h>
#include <plot.h>
#include <stdlib.h>
#include <string.h>
#include "bg.h"

void
pl_closevt(void)
{
	pl_closepl();
}

void
pl_closepl(void)
{
	/* exit graphics mode */
	putchar(ESC);
	printf("[H");
}
