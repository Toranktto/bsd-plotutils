#include "internal.h"

void
pl_move(int xi, int yi)
{
	putc('m', stdout);
	putsi(xi);
	putsi(yi);
}
