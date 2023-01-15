/*
 * Convert the standard plot input into a readable form for debugging.
 */

#include <stdio.h>

float deltx;
float delty;

void fplt(FILE *fin);
int getsi(FILE *fin);
void getstr(char *s, FILE *fin);
void pl_space(int x0, int y0, int x1, int y1);
void pl_open(void);
void pl_close(void);
void pl_erase(void);
void pl_move(int xi, int yi);
void pl_cont(int xi, int yi);
void pl_line(int x0, int y0, int x1, int y1);
void pl_point(int xi, int yi);
void pl_label(char *s);
void pl_arc(int xcent, int ycent, int xbeg, int ybeg, int xend, int yend);
void pl_circle(int xc, int yc, int r);
void pl_linemod(char *line);
void pl_dot(int xi, int yi, int dx, int n, int *pat);

int main(int argc, char **argv) {
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
        fprintf(stderr, "can't open %s\n", argv[1]);
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

void fplt(FILE *fin) {
  int c;
  char s[256];
  int xi, yi, x0, y0, x1, y1, r, dx, n, i;
  int pat[256];

  pl_open();
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
      getstr(s, fin);
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
      getstr(s, fin);
      pl_linemod(s);
      break;
    case 'd':
      xi = getsi(fin);
      yi = getsi(fin);
      dx = getsi(fin);
      n = getsi(fin);
      for (i = 0; i < n; i++)
        pat[i] = getsi(fin);
      pl_dot(xi, yi, dx, n, pat);
      break;
    }
  }
  pl_close();
}

/* get an integer stored in 2 ascii bytes. */
int getsi(FILE *fin) {
  short a, b;
  if ((b = getc(fin)) == EOF)
    return (EOF);
  if ((a = getc(fin)) == EOF)
    return (EOF);
  a = a << 8;
  return (a | b);
}

void getstr(char *s, FILE *fin) {
  for (; (*s = getc(fin)); s++)
    if (*s == '\n')
      break;
  *s = '\0';
}

/* Print out the arguments to plot routines. */

void pl_space(int x0, int y0, int x1, int y1) {
  printf("s %d %d %d %d\n", x0, y0, x1, y1);
}

void pl_open(void) {}

void pl_close(void) {}

void pl_erase(void) { printf("e\n"); }

void pl_move(int xi, int yi) { printf("m %d %d\n", xi, yi); }

void pl_cont(int xi, int yi) { printf("n %d %d\n", xi, yi); }

void pl_line(int x0, int y0, int x1, int y1) {
  printf("l %d %d %d %d\n", x0, y0, x1, y1);
}

void pl_point(int xi, int yi) { printf("p %d %d\n", xi, yi); }

void pl_label(char *s) { printf("t%s\n\n", s); }

void pl_arc(int xcent, int ycent, int xbeg, int ybeg, int xend, int yend) {
  printf("a %d %d %d %d %d %d\n", xcent, ycent, xbeg, ybeg, xend, yend);
}

void pl_circle(int xc, int yc, int r) { printf("c %d %d %d\n", xc, yc, r); }

void pl_linemod(char *line) { printf("f%s\n\n", line); }

/* don't know what this should do */
/* TODO: fix printing pat */
void pl_dot(int xi, int yi, int dx, int n, int *pat) {
  printf("d %d %d %d %d\n\n", xi, yi, dx, n);
}
