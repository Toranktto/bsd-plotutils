/*
 * Copyright (c) 2018 Łukasz Derlatka
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _PLOTCOMPAT_H
#define _PLOTCOMPAT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <plot.h>

#define openpl() pl_openpl()
#define closevt() pl_closevt()
#define openvt() pl_openvt()
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
#define closepl() pl_closepl()
#define dot(xi, yi, dx, n, pat) pl_dot(xi, yi, dx, n, pat)
#define box(x0, y0, x1, y1) pl_box(x0, y0, x1, y1)

#ifdef	__cplusplus
}
#endif

#endif