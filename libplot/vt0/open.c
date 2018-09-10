#ifndef lint
static char sccsid[] = "@(#)open.c	4.2 (Berkeley) 11/10/83";
#endif

#include <plot.h>
#include <fcntl.h>

int xnow;
int ynow;
float boty = 0.;
float botx = 0.;
float oboty = 0.;
float obotx = 0.;
float scalex = 1.;
float scaley = 1.;
int vti = -1;

void
pl_openvt(void)
{
	pl_openpl();
}

void
pl_openpl(void)
{
	vti = open("/dev/stdout", 1);
}
