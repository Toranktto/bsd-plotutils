#include "internal.h"

void
pl_erase(void)
{
	register int i, j;

	for (i = 0; i < COLS; i++)
		for (j = 0; j < LINES; j++)
			screenmat[i][j] = ' ';
}
