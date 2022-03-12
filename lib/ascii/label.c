#include "internal.h"

void
pl_label(char *s)
{
	while (*s != '\0' && currentx < COLS) {
		screenmat[currentx][currenty] = *s++;
		currentx++;
	}
	if (currentx == COLS)
		currentx = currentx - 1;
}
