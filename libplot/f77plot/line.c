/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)line.c	5.1 (Berkeley) 6/7/85";
#endif /* not lint */

#include <plot.h>

void
pl_line_(int *x0, int *y0, int *x1, int *y1)
{
	pl_line(*x0,*y0,*x1,*y1);
}
