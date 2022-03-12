#include "internal.h"

void
pl_circle(int x, int y, int r)
{
	putc('c', stdout);
	putsi(x);
	putsi(y);
	putsi(r);
}
