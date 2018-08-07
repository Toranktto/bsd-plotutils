#ifndef lint
static char sccsid[] = "@(#)atoplot.c	4.2 (Berkeley) 1/9/85";
#endif

#include <stdio.h>
#include <stdlib.h>
#include <plot.h>
#include <string.h>

float deltx;
float delty;

char *mapLineType(char *cp);
void fplt(FILE *fin);
int getsi(FILE *fin);
void getstr(register char *s, register FILE *fin, int len);

int
main(int argc, char **argv)
{
	int std = 1;
	FILE *fin;

	while (argc-- > 1) {
		if (*argv[1] == '-')
			switch (argv[1][1]) {
			case 'l':
				deltx = atoi(&argv[1][2]) - 1;
				break;
			case 'w':
				delty = atoi(&argv[1][2]) - 1;
				break;
			}

		else {
			std = 0;
			if ((fin = fopen(argv[1], "r")) == NULL) {
				fprintf(stderr, "atoplot: can't open %s\n", argv[1]);
				exit(1);
			}

			fplt(fin);
			fclose(fin);
		}

		argv++;
	}

	if (std)
		fplt(stdin);

	exit(0);
}

void
fplt(FILE *fin)
{
	int c;
	char s[256];
	int xi, yi, x0, y0, x1, y1, r, dx, n, i;
	int *pat;
	unsigned int pat_len = 256;

	pat = malloc(pat_len * sizeof(int));

	pl_openpl();
	while ((c = getc(fin)) != EOF) {
		switch (c) {
		case 'm':
			xi = getsi(fin);
			yi = getsi(fin);
			pl_move(xi, yi);
			break;
		case 'l':
			x0 = getsi(fin);
			y0 = getsi(fin);
			x1 = getsi(fin);
			y1 = getsi(fin);
			pl_line(x0, y0, x1, y1);
			break;
		case 't':
			getstr(s, fin, 256);
			pl_label(s);
			break;
		case 'e':
			pl_erase();
			break;
		case 'p':
			xi = getsi(fin);
			yi = getsi(fin);
			pl_point(xi, yi);
			break;
		case 'n':
			xi = getsi(fin);
			yi = getsi(fin);
			pl_cont(xi, yi);
			break;
		case 's':
			x0 = getsi(fin);
			y0 = getsi(fin);
			x1 = getsi(fin);
			y1 = getsi(fin);
			pl_space(x0, y0, x1, y1);
			break;
		case 'a':
			xi = getsi(fin);
			yi = getsi(fin);
			x0 = getsi(fin);
			y0 = getsi(fin);
			x1 = getsi(fin);
			y1 = getsi(fin);
			pl_arc(xi, yi, x0, y0, x1, y1);
			break;
		case 'c':
			xi = getsi(fin);
			yi = getsi(fin);
			r = getsi(fin);
			pl_circle(xi, yi, r);
			break;
		case 'f':
			getstr(s, fin, 256);
			pl_linemod(mapLineType(s));
			break;
		case 'd':
			xi = getsi(fin);
			yi = getsi(fin);
			dx = getsi(fin);
			n = getsi(fin);
			if (n > pat_len) {
				pat_len *= 2;
				pat = realloc(pat, pat_len * sizeof(int));
			}
			for (i = 0; i < n; i++)
				pat[i] = getsi(fin);
			pl_dot(xi, yi, dx, n, pat);
			break;
		}

		/* scan to newline */
		while ((c = getc(fin)) != '\n') {
			if (c == EOF) {
				break;
			}
		}
	}

	pl_closepl();
	free(pat);
}

/* get an integer. */
int
getsi(FILE *fin)
{
	int i;

	if (fscanf(fin, " %d", &i) != 1) {
		return(EOF);
	}
	return(i);
}

char *lineMap[] = {
	"solid",        /* line type 0 */
	"solid",        /* line type 1 */
	"dotted",       /* line type 2 */
	"dotdashed",    /* line type 3 */
	"shortdashed",  /* line type 4 */
	"longdashed",   /* line type 5 */
	"dotlongdash",  /* line type 6 */
	"dotshortdash", /* line type 7 */
	"dotdotdash",   /* line type 8 */
};

char *
mapLineType(char *cp)
{
	int i;

	if (sscanf(cp, "%d", &i) == 1) {
		if (i < 0 || i > sizeof(lineMap) / sizeof(char *)) {
			i = 1;
		}
		return(lineMap[i]);
	}else {
		return(cp);
	}
}

void
getstr(register char *s, register FILE *fin, int len)
{
	unsigned int s_len;

	fgets(s, len, fin);
	/* Strip newline */
	s_len = strlen(s);
	if (s[s_len - 1] == '\n')
		s[s_len - 1] = '\0';
}
