/*
 * Copyright (c) 1985 Regents of the University of California. All rights
 * reserved.  The Berkeley software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef lint
static char	sccsid[] = "@(#)close.c	5.1 (Berkeley) 9/21/85";
#endif				/* not lint */

#include "imp.h"
#include "imPcodes.h"

#include <plot.h>

extern void	putch(int c);

void
pl_closepl(void)
{
	putch(imP_ENDPAGE);
	fflush(stdout);
}

void
pl_closevt(void)
{
	pl_closepl();
}
