#ifndef lint
static char sccsid[] = "@(#)crtplot.c	4.1 (Berkeley) 11/11/83";
#endif /* not lint */

#include "crt.h"
#include <plot.h>
#include <math.h>

/* should include test for equality? */
#define side(x,y)	(a*(x)+b*(y)+c > 0.0 ? 1 : -1)

extern void screen_move(int y, int x);
extern void dda_line(char ch, int x0, int y0, int x1, int y1);

void
pl_arc(int xc, int yc, int xbeg, int ybeg, int xend, int yend)
{
	double r, radius, costheta, sintheta;
	double a, b, c, x, y, tempX;
	int right_side;

	xbeg -= xc; ybeg -= yc;
	xend -= xc; yend -= yc;

	/* probably should check that arc is truely circular */
	/* Note: r is in screen coordinates. */
	r = sqrt( rangeX*rangeX*xbeg*xbeg + rangeY*rangeY*ybeg*ybeg);

	/*
	This method is reasonably efficient, clean, and clever.
	The easy part is generating the next point on the arc.  This is
	done by rotating the points by the angle theta.  Theta is chosen
	so that no rotation will cause more than one pixel of a move.
	This corresponds to a triangle having 'x side' of r and 'y side' of 1.
	The rotation is done (way) below inside the loop.
	*/
	if (r <= 1.0) {
		/* radius is mapped to length < 1*/
		pl_point(xc,yc);
		return;
	}

	radius = sqrt(r*r + 1.0);
	sintheta = 1.0/radius;
	costheta = r/radius;

	/*
	The hard part of drawing an arc is figuring out when to stop.
	This method works by drawing the line from the beginning point
	to the ending point.  This splits the plane in half, with the
	arc that we wish to draw on one side of the line.  If we evaluate
	side(x,y) = a*x + b*y + c, then all of the points on one side of the
	line will result in side being positive, and all the points on the
	other side of the line will result in side being negative.

	We want to draw the arc in a counter-clockwise direction, so we
	must find out what the sign of "side" is for a point which is to the 
	"right" of a line drawn from "beg" to "end".  A point which must lie 
	on the right is [xbeg + (yend-ybeg), ybeg - (xend-xbeg)].  (This
	point is perpendicular to the line at "beg").

	Thus, we compute "side" of the above point, and then compare the
	sign of side for each new point with the sign of the above point.
	When they are different, we terminate the loop.
	*/

	a = (double) (yend - ybeg);
	b = (double) (xend - xbeg);
	c = (double) (yend*xbeg - xend*ybeg);
	right_side = side(xbeg + (yend-ybeg),
			  ybeg - (xend-xbeg) );

	x = xbeg;
	y = ybeg;
	pl_move(xbeg+xc, ybeg+yc);
	do {
		dda_line('*',lastX-1, lastY, scaleX(xc + x), scaleY(yc + y ));
		tempX = x;
		x = x*costheta - y*sintheta;
		y = tempX*sintheta + y*costheta;
	} while( side(x,y) == right_side );
}

