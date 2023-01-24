#include <fcntl.h>
#include <math.h>
#include <plot.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern int xnow;
extern int ynow;
extern float boty;
extern float botx;
extern float oboty;
extern float obotx;
extern float scalex;
extern float scaley;
extern int vti;

int ysc(int yi);
int xsc(int xi);
void pl_frame(int n);
