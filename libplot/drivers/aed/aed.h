/*
 * Displays plot files on an AED512 graphics terminal.
 */

#include <plot.h>
#include <sgtty.h>
#include <stdio.h>

extern char dbuf[BUFSIZ];    /* Used to buffer display characters */
extern struct sgttyb sgttyb; /* Used to save terminal control bits */
extern int curx, cury;       /* Current screen position */
extern int xbot, ybot;       /* Coordinates of screen lower-left corner */
extern int scale;            /* The number of pixels per 2**12 units
                              * of world coordinates.
                              */

void chex(int val,      /* Integer value to be converted. */
          char *string, /* Pointer to area for converted result. */
          int nchars    /* Number of characters to be converted. */
);

void outxy20(int x, int y /* The coordinates to be output.  Note:
                           * these are world coordinates, not screen
                           * ones.  We scale in this routine.
                           */
);

void setcolor(char *pcolor /* Pointer to a string giving the desired
                            * color in hexadecimal.
                            */
);

/* The following variables describe the screen. */

#define GRXMAX 511 /* Maximum x-coordinate of screen */
#define GRYMAX 482 /* Maximum y-coordinate of screen */
