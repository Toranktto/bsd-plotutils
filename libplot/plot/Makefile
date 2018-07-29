#	@(#)Makefile	4.4 (Berkeley) 5/11/90

LIB=	plot
SRCS=	arc.c box.c circle.c close.c cont.c dot.c erase.c label.c \
	line.c linmod.c move.c open.c point.c putsi.c space.c
INCS=	plot.h
CSTD=c99
CFLAGS+=	-I.
MAN=	plot.3
MLINKS+=	plot.3 f77plot.3
PREFIX=	/usr/local
BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib
MANDIR=	${PREFIX}/man/man
FILESDIR=	${PREFIX}/share/misc
INCLUDEDIR=	${PREFIX}/include

.include <bsd.lib.mk>
