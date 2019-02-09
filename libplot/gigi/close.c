/*
 * Copyright (c) 1980 Regents of the University of California. All rights
 * reserved.  The Berkeley software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef lint
static char	sccsid[] = "@(#)close.c	5.1 (Berkeley) 5/7/85";
#endif				/* not lint */

#include <signal.h>
#include <stdlib.h>
#include <plot.h>
#include <string.h>
#include "gigi.h"

void
pl_closepl(void)
{
	/* exit graphics mode */
	putchar(ESC);
	putchar('\\');
}

void
pl_closevt(void)
{
	pl_closepl();
}
