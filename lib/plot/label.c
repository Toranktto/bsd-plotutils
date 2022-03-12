#include "internal.h"

void
pl_label(char *s)
{
	int i;
	putc('t', stdout);
	for (i = 0; s[i];)
		putc(s[i++], stdout);
	putc('\n', stdout);
}
