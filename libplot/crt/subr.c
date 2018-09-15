#ifndef lint
static char	sccsid[] = "@(#)crtplot.c	4.1 (Berkeley) 11/11/83";
#endif				/* not lint */

#include "crt.h"
#include <math.h>
#include <stdlib.h>
#include <term.h>

/* This routine just moves the cursor. */
void
screen_move(int y, int x)
{
	/* must check for automatic wrap at last col */
	if (!tgetflag("am") || (y < LINES - 1) || (x < COLS - 1)) {
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

/* See Neuman & Sproul for explanation and rationale. */
/* Does not plot first point -- assumed that it is already plotted */
/* x0, y0, x1, y1 - already transformed to screen coords */
void
dda_line(char ch, int x0, int y0, int x1, int y1)
{
	int		length, i;
	double		deltaX, deltaY;
	double		x, y;

	length = abs(x1 - x0);
	if (abs(y1 - y0) > length)
		length = abs(y1 - y0);

	if (length == 0)
		return;

	deltaX = (double)(x1 - x0) / (double)length;
	deltaY = (double)(y1 - y0) / (double)length;

	x = (double)x0 + 0.5;
	y = (double)y0 + 0.5;

	for (i = 0; i < length; ++i) {
		x += deltaX;
		y += deltaY;
		screen_move((int)floor(y), (int)floor(x));
		plot_addch(ch);
	}
}
