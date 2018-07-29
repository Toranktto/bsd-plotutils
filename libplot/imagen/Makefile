#	@(#)Makefile	5.6 (Berkeley) 5/11/90

LIB=	plotimagen
# DEFRES == default printer resolution dpi
CFLAGS+=-DDEFRES=240
SRCS=	arc.c box.c charset.c circle.c close.c cont.c dot.c \
	erase.c label.c line.c linemod.c move.c open.c point.c \
	scale.c space.c
CFLAGS+=	-I../plot
CSTD=c99
PREFIX=	/usr/local
BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib
MANDIR=	${PREFIX}/man/man
FILESDIR=	${PREFIX}/share/misc
INCLUDEDIR=	${PREFIX}/include

.include <bsd.lib.mk>
