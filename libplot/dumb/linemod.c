/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)linemod.c	5.1 (Berkeley) 5/7/85";
#endif /* not lint */

#include <plot.h>
#include <string.h>

int plotChar = '*'; /* used to drawing plots, by default in solid mode */

void
linemod(char *s)
{
	if (strcmp(s, "dotted") == 0) plotChar = '.';
	else if (strcmp(s, "dotdashed") == 0) plotChar = '\\';
	else if (strcmp(s, "shortdashed") == 0) plotChar = '/';
	else if (strcmp(s, "longdashed") == 0) plotChar = '-';
	else if (strcmp(s, "dotlongdash") == 0) plotChar = 'x';
	else if (strcmp(s, "dotshortdash") == 0) plotChar = 's';
	else if (strcmp(s, "dotdotdash") == 0) plotChar = ',';
	else plotChar = '*';
}
