LIB=	plot_tek4014
SRCS=	arc.c box.c circle.c close.c cont.c dot.c erase.c label.c \
	line.c linemod.c move.c open.c point.c space.c scale.c
CFLAGS+=	-I../plot
LDADD=	-L${LIBDIR} -lm
CSTD=c99
SHLIB_MAJOR=	1
SHLIB_MINOR=	0

PREFIX?=	/usr/local
BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib
MANDIR=	${PREFIX}/share/man
FILESDIR=	${PREFIX}/share/misc
INCLUDEDIR=	${PREFIX}/include

.if ${PREFIX} == "/usr/local"
MANDIR=	${PREFIX}/man/man
.endif

.include <bsd.lib.mk>