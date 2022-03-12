/*
 * This accepts plot file formats and produces the appropriate plots
 * for dumb terminals.  It can also be used for printing terminals and
 * lineprinter listings, although there is no way to specify number of
 * lines and columns different from your terminal.  This would be easy
 * to change, and is left as an exercise for the reader.
 */

#ifndef _PLOT_ASCII_INTERNAL_H
#define _PLOT_ASCII_INTERNAL_H

#include <math.h>
#include <plot.h>
#include <stdio.h>
#include <stdlib.h>

#define scale(x, y)                                  \
	y = LINES - 1 - (LINES * y / rangeY + minY); \
	x = COLS * x / rangeX + minX

extern int minX, rangeX; /* min and range of x */
extern int minY, rangeY; /* min and range of y */
extern int currentx, currenty;
extern int COLS, LINES;

/* A very large screen! (probably should use malloc) */
#define MAXCOLS 132
#define MAXLINES 90

extern char screenmat[MAXCOLS][MAXLINES];

void dda_line(char ch, int x0, int y0, int x1, int y1);

#endif