#include "imPcodes.h"
#include "imp.h"
float obotx = 0.;
float oboty = 0.;
float botx = 2.;
float boty = 2.;
float scalex = 1.;
float scaley = 1.;
void putch(int c) { putc(c, stdout); }
void putwd(int w) {
  putch(w >> 8);
  putch(w);
}
void pl_line(int x0, int y0, int x1, int y1) {
  putch(imP_CREATE_PATH);
  putwd(2); /* two coordinates follow */
  putwd((int)((x0 - obotx) * scalex + botx));
  putwd((int)((y0 - oboty) * scaley + boty));
  putwd((int)((x1 - obotx) * scalex + botx));
  putwd((int)((y1 - oboty) * scaley + boty));
  putch(imP_DRAW_PATH);
  putch(15); /* "black" lines */
  imPx = x1;
  imPy = y1;
}
