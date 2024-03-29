/*
 * This accepts plot file formats and produces the appropriate plots
 * for dumb terminals.  It can also be used for printing terminals and
 * lineprinter listings, although there is no way to specify number of
 * lines and columns different from your terminal.  This would be easy
 * to change, and is left as an exercise for the reader.
 */

#include "dumb.h"
#include <signal.h>
#include <term.h>

int minX, rangeX; /* min and range of x */
int minY, rangeY; /* min and range of y */
int currentx, currenty;
int COLS, LINES;

/* A very large screen! (probably should use malloc) */
char screenmat[MAXCOLS][MAXLINES];

void pl_open(void) {
  int i, j;
  char *term;
  char bp[1024];

  term = getenv("TERM");
  tgetent(bp, term);

  COLS = tgetnum("co");
  if (COLS > MAXCOLS)
    COLS = MAXCOLS;
  if (COLS < 0)
    COLS = 48; /* lower bound on # of cols? */
  COLS--;      /* prevent auto wrap */

  LINES = tgetnum("li");
  if (LINES > MAXLINES)
    LINES = MAXLINES;
  if (LINES < 0)
    LINES = 20; /* lower bound on # of lines? */

  for (i = 0; i < COLS; i++)
    for (j = 0; j < LINES; j++)
      screenmat[i][j] = ' ';

  signal(SIGINT, (void (*)(int))pl_close);
  currentx = currenty = 0;
}
