/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)arc.c	5.1 (Berkeley) 5/7/85";
#endif /* not lint */

#include "hp7221.h"
#include <plot.h>

/* 
 * 7221 requires knowing the anlge of arc.  To do this, the triangle formula
 *	c^2 = a^2 + b^2 - 2*a*b*cos(angle)
 * is used where "a" and "b" are the radius of the circle and "c" is the
 * distance between the beginning point and the end point.
 *
 * This gives us "angle" or angle - 180.  To find out which, draw a line from
 * beg to center.  This splits the plane in half.  All points on one side of the
 * plane will have the same sign when plugged into the equation for the line.
 * Pick a point on the "right side" of the line (see program below).  If "end"
 * has the same sign as this point does, then they are both on the same side
 * of the line and so angle is < 180.  Otherwise, angle > 180.
 */
   
#define side(x,y)	(a*(x)+b*(y)+c > 0.0 ? 1 : -1)

void
arc(int x, int y, int x0, int y0, int x1, int y1)
{
	double radius2, c2;
	double a,b,c;
	int angle;

	/* Probably should check that this is really a circular arc.  */
	radius2 = (x-x0)*(x-x0) + (y-y0)*(y-y0);
	c2 = (x1-x0)*(x1-x0) + (y1-y0)*(y1-y0);
	angle = (int) ( 180.0/PI * acos(1.0 - c2/(2.0*radius2)) + 0.5 );

	a = (double) (y - y0);
	b = (double) (x - x0);
	c = (double) (y*x0 - x*y0);
	if (side(x0 + (y-y0), y0 - (x-x0)) != side(x1,y1))
		angle += 180;
	
	move(x, y);
	/* Not quite implemented...
	printf("C(A%d c)[%d,%d]", angle, x0, y0);
	*/
}
