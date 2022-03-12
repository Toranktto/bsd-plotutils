#include "internal.h"

void
pl_move(int x, int y)
{
	scale(x, y);
	currentx = x;
	currenty = y;
}
