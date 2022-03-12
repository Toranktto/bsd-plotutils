#ifndef _PLOT_TEK4014_INTERNAL_H
#define _PLOT_TEK4014_INTERNAL_H

#include <math.h>
#include <plot.h>
#include <stdio.h>
#include <stdlib.h>

extern int ohiy;
extern int ohix;
extern int oloy;
extern int oextra;
extern float scalex;
extern float scaley;
extern int scaleflag;
extern float botx;
extern float boty;
extern float obotx;
extern float oboty;
extern int del;
int quad(int x, int y, int xp, int yp);
void step(int d);
void putch(int c);

#endif