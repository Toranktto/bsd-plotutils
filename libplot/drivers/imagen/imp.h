#include "imPcodes.h"
#include <math.h>
#include <plot.h>
#include <stdio.h>
#include <stdlib.h>

extern float obotx;
extern float boty;
extern float botx;
extern float oboty;
extern float scalex;
extern float scaley;
extern int scaleflag;
int imPx, imPy;
extern int imPcsize;
extern char *imP_charset;

void scale(int i, double x, double y);
void putch(int c);
void putwd(int w);
void setfont(char *c, int sz);
