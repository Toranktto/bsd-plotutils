extern vti;
extern xnow, ynow;
pl_point(xi, yi) {
  struct {
    char pad, c;
    int x, y;
  } p;
  p.c = 2;
  p.x = xnow = xsc(xi);
  p.y = ynow = ysc(yi);
  write(vti, &p.c, 5);
}
