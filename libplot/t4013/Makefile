#	@(#)Makefile	5.3 (Berkeley) 5/11/90

LIB=	plot4013
SRCS=	arc.c box.c circle.c close.c dot.c erase.c label.c \
	line.c linemod.c move.c open.c point.c space.c subr.c
CFLAGS+=	-I../plot
CSTD=c99
SHLIB_MAJOR=	1
SHLIB_MINOR=	0
PREFIX?=	/usr/local
BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib
MANDIR=	${PREFIX}/man/man
FILESDIR=	${PREFIX}/share/misc
INCLUDEDIR=	${PREFIX}/include

.include <bsd.lib.mk>
