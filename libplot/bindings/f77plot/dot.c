/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)dot.c	5.1 (Berkeley) 6/7/85";
#endif /* not lint */

#include <plot.h>

void
pl_dot_(int *xi, int *yi, int *dx, int *n, int *pat)
{
	pl_dot(*xi, *yi, *dx, *n, pat);
}
