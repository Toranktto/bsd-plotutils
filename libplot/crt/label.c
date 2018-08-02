#ifndef lint
static char sccsid[] = "@(#)crtplot.c	4.1 (Berkeley) 11/11/83";
#endif /* not lint */

#include "crt.h"
#include <plot.h>
#include <string.h>

void
pl_label(char *str)
{
	register int i, length;

	if ((length = strlen(str)) > (COLS - lastX))
		length = COLS - lastX;
	for (i = 0; i < length; ++i)
		plot_addch(str[i]);
}
