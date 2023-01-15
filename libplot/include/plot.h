#ifndef _PLOT_H
#define _PLOT_H

#ifdef __cplusplus
extern "C" {
#endif

extern void pl_open(void);
extern void pl_erase(void);
extern void pl_label(char *);
extern void pl_line(int, int, int, int);
extern void pl_circle(int, int, int);
extern void pl_arc(int, int, int, int, int, int);
extern void pl_move(int, int);
extern void pl_cont(int, int);
extern void pl_point(int, int);
extern void pl_linemod(char *);
extern void pl_space(int, int, int, int);
extern void pl_close(void);
extern void pl_dot(int, int, int, int, int *);
extern void pl_box(int, int, int, int);

#ifdef __cplusplus
}
#endif

#endif
