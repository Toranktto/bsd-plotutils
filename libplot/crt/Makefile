#	@(#)Makefile	5.3 (Berkeley) 5/12/90

LIB=	plotcrt
SRCS=	arc.c box.c circle.c close.c cont.c dot.c erase.c label.c \
	line.c linemod.c move.c open.c point.c space.c subr.c
CFLAGS+=	-I../plot -I${INCLUDEDIR}
LDADD=	-L${LIBDIR} -lm -lcurses
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
