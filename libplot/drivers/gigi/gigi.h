/*
 * Displays plot files on a gigi "graphics" terminal.
 */

#include <math.h>
#include <plot.h>
#include <stdio.h>
#include <stdlib.h>

#define ESC 033
#define PI 3.141592659

/*
 * The graphics address range is 0..XMAX, YMAX..0 where (0, YMAX) is the
 * lower left corner.
 */
#define XMAX 767
#define YMAX 479
#define xsc(xi) ((int)((xi - lowx) * scalex + 0.5))
#define ysc(yi) ((int)(YMAX - (yi - lowy) * scaley + 0.5))

extern int currentx;
extern int currenty;
extern double lowx;
extern double lowy;
extern double scalex;
extern double scaley;
