/*
 * Copyright (c) 1980 Regents of the University of California. All rights
 * reserved.  The Berkeley software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef lint
static char	sccsid[] = "@(#)open.c	5.2 (Berkeley) 4/30/85";
#endif				/* not lint */


/*
 * Displays plot files on a BBN bitgraph terminal.
 */

#include <signal.h>
#include <plot.h>
#include "bg.h"

int		currentx = 0;
int		currenty = 0;
double		lowx = 0.0;
double		lowy = 0.0;
double		scale = 1.0;

void
pl_openpl(void)
{
	/* catch interupts */
	signal(SIGINT, (__sighandler_t *) pl_closepl);
	currentx = 0;
	currenty = 0;

	/* pl_space(0, 0, XMAX, YMAX); */
}

void
pl_openvt(void)
{
	pl_openpl();
}
