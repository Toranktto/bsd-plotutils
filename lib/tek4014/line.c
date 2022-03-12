#include "internal.h"

void
pl_line(int x0, int y0, int x1, int y1)
{
	pl_move(x0, y0);
	pl_cont(x1, y1);
}
