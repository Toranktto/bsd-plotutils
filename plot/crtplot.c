#ifndef lint
static char sccsid[] = "@(#)crtplot.c	4.1 (Berkeley) 11/11/83";
#endif

/*
This plotting routine interprets plot commands and outputs them onto
intelligent terminals (ie, terminals with clear screen and cursor
addressability.  It uses the curses library.  It should be compiled
as follows:
	cc crtdriver.c crtplot.c -lcurses -ltermcap -lm
Note:  This requires as slightly modified driver from the standard driver
because some function names conflicted with the curses library.
(That's what you get when you have a flat name space!)
*/


#include <curses.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <signal.h>
#include <term.h>

/*  These map from plot routine coordinates to screen coordinates.  */
#define scaleX(x)		(int) ((x-lowX)*rangeX + 0.5)
#define scaleY(y)		(int) (LINES-0.5 - ((y-lowY)*rangeY))

#define plot_movech(y, x, ch)	{ plot_move(x, y); plot_addch(ch); }

void arc(int xc, int yc, int xbeg, int ybeg, int xend, int yend);
void dda_line(char ch, int x0, int y0, int x1, int y1);
void closepl(void);


static int plotChar = ' '; /* used to drawing plots */
static double lowX, rangeX;	/* min and range of x */
static double lowY, rangeY;	/* min and range of y */
static int lastX, lastY;	/* last point plotted */

/* This routine just moves the cursor. */
void
screen_move(int y, int x)
{
	/* must check for automatic wrap at last col */
	if (!tgetflag("am") || (y < LINES -1) || (x < COLS -1)) {
		move(y, x);
		lastY = y;
		lastX = x;
	}
}


/* This routine assumes the cursor is positioned correctly. */
void
plot_addch(char ch)
{
	addch(ch);
	if (++lastX >= COLS) {
		if (tgetflag("am")) {
			lastX = 0;
			lastY++;
		} else {
			lastX = COLS - 1;
		}
	}
}		


/* See the curses manual for what is been done and why. */
void
openpl(void)
{
	initscr();
	noecho();
	nonl();
	signal(SIGINT, (__sighandler_t *) closepl);
}


void
closepl(void)
{
	signal(SIGINT, SIG_IGN);
	/* Leave cursor at top of screen. */
	move(0, 0);

	refresh();
	endwin();
	exit(0);
}


void
plot_move(int x, int y)
{
	screen_move(scaleY(y), scaleX(x));
}


void
line(int x0, int y0, int x1, int y1)
{
	plot_movech(y0, x0, plotChar);
	dda_line(plotChar, scaleX(x0), scaleY(y0), scaleX(x1), scaleY(y1));
}

void
label(char *str)
{
	register int i, length;

	if ( (length=strlen(str)) > (COLS-lastX) )
		length = COLS - lastX;
	for (i=0; i<length; ++i)
		plot_addch(str[i]);
}

void
plot_erase(void)
{
	clear();
	move(LINES-1, 0);
	lastX = 0;
	lastY = LINES-1;
	refresh();
}

void
point(int x, int y)
{
	plot_movech(y, x, plotChar);
}

void
cont(int x, int y)
{
	dda_line(plotChar, lastX-1, lastY, scaleX(x), scaleY(y));
}

void
space(int x0, int y0, int x1, int y1)
{
	lowX = (double) x0;
	lowY = (double) y0;
	rangeX = COLS/(double) (x1 - x0);
	rangeY = LINES/(double) (y1 - y0);
}

void
linemod(char *string)
{
	if (strcmp(string, "solid") == 0) {
		plotChar = '*';
	}
	else if (strcmp(string, "dotted") == 0) {
		plotChar = '.';
	}
	else if (strcmp(string, "dotdashed") == 0) {
		plotChar = '\\';
	}
	else if (strcmp(string, "shortdashed") == 0) {
		plotChar = '/';
	}
	else if (strcmp(string, "longdashed") == 0) {
		plotChar = '-';
	}
	else if (strcmp(string, "dotlongdash") == 0) {
		plotChar = 'x';
	}
	else if (strcmp(string, "dotshortdash") == 0) {
		plotChar = 'v';
	}
	else if (strcmp(string, "dotdotdash") == 0) {
		plotChar = ',';
	}
	else {
		plotChar = '*';
	}
}


/* See Neuman & Sproul for explanation and rationale. */
/* Does not plot first point -- assumed that it is already plotted */
/* x0, y0, x1, y1 - already transformed to screen coords */
void
dda_line(char ch, int x0, int y0, int x1, int y1)
{
	int length, i;
	double deltaX, deltaY;
	double x, y;

	length = abs(x1 - x0);
	if (abs(y1 -y0) > length)
		length = abs(y1 - y0);

	if (length == 0)
		return;

	deltaX = (double) (x1 - x0)/(double) length;
	deltaY = (double) (y1 - y0)/(double) length;

	x = (double) x0 + 0.5;
	y = (double) y0 + 0.5;

	for (i=0; i < length; ++i) {
		x += deltaX;
		y += deltaY;
		screen_move((int) floor(y), (int) floor(x));
		plot_addch(ch);
	}
}

void
circle(int xc, int yc,int r)
{
	arc(xc,yc, xc+r,yc, xc-r,yc);
	arc(xc,yc, xc-r,yc, xc+r,yc);
}

/* should include test for equality? */
#define side(x,y)	(a*(x)+b*(y)+c > 0.0 ? 1 : -1)

void
arc(int xc, int yc, int xbeg, int ybeg, int xend, int yend)
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
		point(xc,yc);
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
	plot_move(xbeg+xc, ybeg+yc);
	do {
		dda_line(plotChar,lastX-1, lastY, scaleX(xc + x), scaleY(yc + y ));
		/*
		screen_move( scaleY(yc + y), scaleX(xc + x) );
		plot_addch(plotChar);
		*/
		tempX = x;
		x = x*costheta - y*sintheta;
		y = tempX*sintheta + y*costheta;
	} while( side(x,y) == right_side );
}
