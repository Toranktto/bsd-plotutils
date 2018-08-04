#	@(#)Makefile	5.3 (Berkeley) 5/11/90

LIB=	plotbg
SRCS=	box.c circle.c arc.c cont.c dot.c erase.c line.c linemod.c point.c \
	label.c move.c open.c close.c space.c
CFLAGS+=	-I../plot -I${INCLUDEDIR}
LDADD=	-L${LIBDIR} -lm
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
