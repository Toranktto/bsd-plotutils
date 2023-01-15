#ifndef _PLOT_COMPAT_H
#define _PLOT_COMPAT_H

#include "plot.h"

#define openpl() pl_open()
#define closevt() pl_close()
#define openvt() pl_open()
#define closepl() pl_close()
#define erase() pl_erase()
#define label(s) pl_label(s)
#define line(x0, y0, x1, y1) pl_line(x0, y0, x1, y1)
#define circle(x, y, r) pl_circle(x, y, r)
#define arc(x, y, x0, y0, x1, y1) pl_arc(x, y, x0, y0, x1, y1)
#define move(xi, yi) pl_move(xi, yi)
#define cont(x, y) pl_cont(x, y)
#define point(xi, yi) pl_point(xi, yi)
#define linemod(s) pl_linemod(s)
#define space(x0, y0, x1, y1) pl_space(x0, y0, x1, y1)
#define dot(xi, yi, dx, n, pat) pl_dot(xi, yi, dx, n, pat)
#define box(x0, y0, x1, y1) pl_box(x0, y0, x1, y1)

#endif
