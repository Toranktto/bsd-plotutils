/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)circle.c	5.1 (Berkeley) 6/7/85";
#endif not lint

void
circle(int x, int y, int r)
{
	arc(x,y,x+r,y,x+r,y);
}
