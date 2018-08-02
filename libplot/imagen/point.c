/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)point.c	5.1 (Berkeley) 9/21/85";
#endif /* not lint */

#include <plot.h>

void
pl_point(int xi, int yi)
{
	pl_line(xi, yi, xi, yi);
}
