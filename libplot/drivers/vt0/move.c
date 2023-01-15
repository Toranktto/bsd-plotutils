extern vti;
extern xnow, ynow;
pl_move(xi, yi) {
  struct {
    char pad, c;
    int x, y;
  } p;
  p.c = 9;
  p.x = xnow = xsc(xi);
  p.y = ynow = ysc(yi);
  write(vti, &p.c, 5);
}
