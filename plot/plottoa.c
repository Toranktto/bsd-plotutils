#ifndef lint
static char sccsid[] = "@(#)plottoa.c	4.2 (Berkeley) 1/9/85";
#endif

/*
 * Convert the standard plot input into a readable form for debugging.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

float deltx;
float delty;

void fplt(FILE *fin);
int getsi(FILE *fin);
void getstr(register char *s, register FILE *fin, int len);

void space(int x0, int y0, int x1, int y1);
void openpl(void);
void closepl(void);
void erase(void);
void move(int xi, int yi);
void cont(int xi, int yi);
void line(int x0, int y0, int x1, int y1);
void point(int xi, int yi);
void label(char *s);
void arc(int xcent, int ycent, int xbeg, int ybeg, int xend, int yend);
void circle(int xc, int yc, int r);
void linemod(char *line);
void dot(int xi, int yi, int dx, int n, int pat[]);


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
				fprintf(stderr, "plottoa: can't open %s\n", argv[1]);
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

	openpl();
	while ((c = getc(fin)) != EOF) {
		switch (c) {
		case 'm':
			xi = getsi(fin);
			yi = getsi(fin);
			move(xi, yi);
			break;
		case 'l':
			x0 = getsi(fin);
			y0 = getsi(fin);
			x1 = getsi(fin);
			y1 = getsi(fin);
			line(x0, y0, x1, y1);
			break;
		case 't':
			getstr(s, fin, 256);
			label(s);
			break;
		case 'e':
			erase();
			break;
		case 'p':
			xi = getsi(fin);
			yi = getsi(fin);
			point(xi, yi);
			break;
		case 'n':
			xi = getsi(fin);
			yi = getsi(fin);
			cont(xi, yi);
			break;
		case 's':
			x0 = getsi(fin);
			y0 = getsi(fin);
			x1 = getsi(fin);
			y1 = getsi(fin);
			space(x0, y0, x1, y1);
			break;
		case 'a':
			xi = getsi(fin);
			yi = getsi(fin);
			x0 = getsi(fin);
			y0 = getsi(fin);
			x1 = getsi(fin);
			y1 = getsi(fin);
			arc(xi, yi, x0, y0, x1, y1);
			break;
		case 'c':
			xi = getsi(fin);
			yi = getsi(fin);
			r = getsi(fin);
			circle(xi, yi, r);
			break;
		case 'f':
			getstr(s, fin, 256);
			linemod(s);
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
			dot(xi, yi, dx, n, pat);
			break;
		}
	}

	closepl();
	free(pat);
}

/* get an integer. */
int
getsi(register FILE *fin)
{
	int a;
	short b;

	fread(&b, sizeof(b), 1, fin);
	a = ntohs(b);

	return a;
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

/* Print out the arguments to plot routines. */

void
space(int x0, int y0, int x1, int y1)
{
	printf("s %d %d %d %d\n", x0, y0, x1, y1);
}

void
openpl(void)
{
}

void
closepl(void)
{
}

void
erase(void)
{
	printf("e\n");
}

void
move(int xi, int yi)
{
	printf("m %d %d\n", xi, yi);
}

void
cont(int xi, int yi)
{
	printf("n %d %d\n", xi, yi);
}

void
line(int x0, int y0, int x1, int y1)
{
	printf("l %d %d %d %d\n", x0, y0, x1, y1);
}

void
point(int xi, int yi)
{
	printf("p %d %d\n", xi, yi);
}

void
label(char *s)
{
	printf("t%s\n\n", s);
}

void
arc(int xcent, int ycent, int xbeg, int ybeg, int xend, int yend)
{
	printf("a %d %d %d %d %d %d\n", xcent, ycent, xbeg, ybeg, xend, yend);
}

void
circle(int xc, int yc, int r)
{
	printf("c %d %d %d\n", xc, yc, r);
}

void
linemod(char *line)
{
	printf("f%s\n\n", line);
}

void
dot(int xi, int yi, int dx, int n, int pat[])
{
	register int i;

	printf("d %d %d %d %d ", xi, yi, dx, n);
	for (i = 0; i < n; i++) printf("%d ", pat[i]);
	printf("\n\n");
}
