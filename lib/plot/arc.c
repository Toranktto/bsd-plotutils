#include "internal.h"

void
pl_arc(int xi, int yi, int x0, int y0, int x1, int y1)
{
	putc('a', stdout);
	putsi(xi);
	putsi(yi);
	putsi(x0);
	putsi(y0);
	putsi(x1);
	putsi(y1);
}
