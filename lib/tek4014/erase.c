#include "internal.h"

void
pl_erase(void)
{
	int i;
	putch(033);
	putch(014);
	ohiy = -1;
	ohix = -1;
	oextra = -1;
	oloy = -1;
	return;
}
