/*
 * Displays plot files on a bbn bitgraph terminal.
 */

#include <math.h>
#include <plot.h>
#include <stdio.h>
#include <stdlib.h>

#define ESC 033
#define PI 3.141592659

/* The graphics address range is 0..XMAX, 0..YMAX. */
#define XMAX 768
#define YMAX 1024
#define scaleX(xi) ((int)((xi - lowx) * scale + 0.5))
#define scaleY(yi) ((int)((yi - lowy) * scale + 0.5))

extern int currentx;
extern int currenty;
extern double lowx;
extern double lowy;
extern double scale;
