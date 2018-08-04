#	@(#)Makefile	4.4 (Berkeley) 5/11/90

LIB=	plot
SRCS=	arc.c box.c circle.c close.c cont.c dot.c erase.c label.c \
	line.c linemod.c move.c open.c point.c putsi.c space.c
INCS=	plot.h plotcompat.h
CSTD=c99
CFLAGS+=	-I. -I${INCLUDEDIR}
SHLIB_MAJOR=	1
SHLIB_MINOR=	0
MAN=	plot.3 plot.5
MLINKS=	plot.3 pl_openvt.3 \
		plot.3 pl_openpl.3 \
		plot.3 pl_closepl.3 \
		plot.3 pl_closevt.3 \
		plot.3 pl_erase.3 \
		plot.3 pl_line.3 \
		plot.3 pl_circle.3 \
		plot.3 pl_arc.3 \
		plot.3 pl_move.3 \
		plot.3 pl_cont.3 \
		plot.3 pl_point.3 \
		plot.3 pl_linemod.3 \
		plot.3 pl_space.3 \
		plot.3 pl_dot.3 \
		plot.3 pl_box.3
PREFIX?=	/usr/local
BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib
MANDIR=	${PREFIX}/man/man
FILESDIR=	${PREFIX}/share/misc
INCLUDEDIR=	${PREFIX}/include

.include <bsd.lib.mk>
