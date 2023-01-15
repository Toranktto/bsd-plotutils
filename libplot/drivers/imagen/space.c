extern float botx;
extern float boty;
extern float obotx;
extern float oboty;
extern float scalex;
extern float scaley;

int PlotRes = 100;

int scaleflag;
pl_space(x0, y0, x1, y1) {
  botx = 2.;
  boty = 2.;
  obotx = x0;
  oboty = y0;
  if (scaleflag)
    return;
  scalex = (8.0 * PlotRes) / (x1 - x0);
  scaley = (8.0 * PlotRes) / (y1 - y0);
}
