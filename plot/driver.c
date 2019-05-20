#include <stdio.h>
#include <stdlib.h>
#include <plot.h>
#include <unistd.h>
#include <string.h>
#include <err.h>
#include <netinet/in.h>
#include <signal.h>

float		deltx;
float		delty;

static void	interrupt(void);
static void	fplt(FILE *fin);
static int	getsi(register FILE *fin);
static void	getstr(register char *s, register FILE *fin, int len);

#ifdef __crtplot
static void	winresize(void);
#endif

int
main(int argc, char *argv[])
{
	int		std = 1;
	FILE	       *fin;
	struct sigaction	act;

	memset(&act, 0x00, sizeof(act));
	act.sa_handler = (void(*)(int)) interrupt;
	sigaction(SIGINT, &act, NULL);

#ifdef __crtplot
	if (!isatty(fileno(stdout))) {
		errx(1, "output must be a terminal");
	}

	memset(&act, 0x00, sizeof(act));
	act.sa_handler = (void(*)(int)) winresize;
	sigaction(SIGWINCH, &act, NULL);
#endif

	for (argc--, argv++; argc > 0; argc--, argv++) {
		if (argv[0][0] == '-') {
			switch (argv[0][1]) {
			case 'l':
				deltx = atoi(&argv[0][2]) - 1;
				break;
			case 'w':
				delty = atoi(&argv[0][2]) - 1;
				break;
			}
			continue;
		}
		std = 0;
		fin = fopen(argv[0], "r");
		if (fin == NULL) {
			errx(1, "can't open %s", argv[0]);
		}
		fplt(fin);
		fclose(fin);
	}

	if (std) {
#ifdef __crtplot
		if (isatty(fileno(stdin))) {
			errx(1, "input cannot be a terminal\n");
		}
#endif
		fplt(stdin);
	}

	exit(0);
}

static void
interrupt(void)
{
	struct sigaction	act;

	memset(&act, 0x00, sizeof(act));
	act.sa_handler = SIG_IGN;
	sigaction(SIGINT, &act, NULL);

	pl_closevt();
	exit(0);
}

static void
fplt(FILE *fin)
{
	register int	c;
	char		s[256];
	int		xi, yi, x0, y0, x1, y1, r;
	int		dx, n, i;
	int	       *pat;
	unsigned int	pat_len = 256;

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
			pl_linemod(s);
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
		default:
			pl_closevt();
			free(pat);
			errx(1, "malformed input");
		}
	}

	pl_closepl();
	free(pat);
}

/* get an integer. */
static int
getsi(register FILE * fin)
{
	short		b;

	if (fread(&b, sizeof(b), 1, fin) < 1) {
		pl_closevt();
		errx(1, "malformed input");
	}
	return ntohs(b);
}

static void
getstr(register char *s, register FILE * fin, int len)
{
	if (fgets(s, len, fin) == NULL) {
		pl_closevt();
		errx(1, "malformed input");
	}
	s[strlen(s) - 1] = '\0';
}

#ifdef __crtplot
static void
winresize(void)
{
	struct sigaction	act;

	memset(&act, 0x00, sizeof(act));
	act.sa_handler = SIG_IGN;
	sigaction(SIGWINCH, &act, NULL);

	pl_closevt();
	exit(0);
}
#endif
