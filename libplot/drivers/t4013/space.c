extern float botx;
extern float boty;
extern float obotx;
extern float oboty;
extern float scalex;
extern float scaley;
extern int scaleflag;
void pl_space(int x0, int y0, int x1, int y1) {
  botx = 0.;
  boty = 0.;
  obotx = x0;
  oboty = y0;
  if (scaleflag)
    return;
  scalex = 780. / (x1 - x0);
  scaley = 780. / (y1 - y0);
}