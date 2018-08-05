/*
This plotting routine interprets plot commands and outputs them onto
intelligent terminals (ie, terminals with clear screen and cursor
addressability. It uses the curses library.
*/

#include <math.h>
#include <curses.h>

/*  These map from plot routine coordinates to screen coordinates.  */
#define scaleX(x) (int) floor(((x - lowX) * rangeX))
#define scaleY(y) (int) floor((LINES - ((y - lowY) * rangeY)))

extern void plot_addch(char ch);
#define plot_movech(y, x, ch)	{ pl_move(x, y); plot_addch(ch); }

extern double lowX, rangeX;	/* min and range of x */
extern double lowY, rangeY;	/* min and range of y */
extern int lastX, lastY;	/* last point plotted */
