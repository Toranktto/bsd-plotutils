/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)open.c	5.1 (Berkeley) 5/7/85";
#endif /* not lint */

#include <signal.h>
#include <stdlib.h>
#include <plot.h>
#include "crt.h"

double lowX, rangeX;    /* min and range of x */
double lowY, rangeY;    /* min and range of y */
int lastX, lastY;       /* last point plotted */

void
pl_openpl(void)
{
	initscr();
	noecho();
	nonl();
	signal(SIGINT, (__sighandler_t*)pl_closepl);
}

void
pl_openvt(void)
{
	pl_openpl();
}
