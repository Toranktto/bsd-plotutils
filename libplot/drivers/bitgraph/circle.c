pl_circle(xc, yc, r) int xc, yc, r;
{
  pl_arc(xc, yc, xc + r, yc, xc - r, yc);
  pl_arc(xc, yc, xc - r, yc, xc + r, yc);
}
