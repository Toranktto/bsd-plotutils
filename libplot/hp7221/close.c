/*
 * Copyright (c) 1980 Regents of the University of California. All rights
 * reserved.  The Berkeley software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef lint
static char	sccsid[] = "@(#)close.c	5.1 (Berkeley) 5/7/85";
#endif				/* not lint */

#include <signal.h>
#include "hp7221.h"
#include <string.h>
#include <plot.h>

void
pl_closepl(void)
{
	printf("v@}");		/* Put pen away. */
	fflush(stdout);
}

void
pl_closevt(void)
{
	pl_closepl();
}
