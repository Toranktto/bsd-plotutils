void pl_box(int x0, int y0, int x1, int y1) {
  pl_move(x0, y0);
  pl_cont(x0, y1);
  pl_cont(x1, y1);
  pl_cont(x1, y0);
  pl_cont(x0, y0);
  pl_move(x1, y1);
}
