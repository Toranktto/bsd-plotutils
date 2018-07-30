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

#include <math.h>
#include <curses.h>

/*  These map from plot routine coordinates to screen coordinates.  */
#define scaleX(x)		(int) ((x-lowX)*rangeX + 0.5)
#define scaleY(y)		(int) (LINES-0.5 - ((y-lowY)*rangeY))

extern void plot_addch(char ch);
#define plot_movech(y, x, ch)	{ pl_move(x, y); plot_addch(ch); }

extern double lowX, rangeX;	/* min and range of x */
extern double lowY, rangeY;	/* min and range of y */
extern int lastX, lastY;	/* last point plotted */
