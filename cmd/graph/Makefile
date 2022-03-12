PROG=	graph
LDADD+=	-L../../lib/plot -lplot -lm
CFLAGS+=    -I../../lib/plot
CSTD=c99

PREFIX?=    /usr/local
BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib
MANDIR=	${PREFIX}/share/man
FILESDIR=	${PREFIX}/share/misc
INCLUDEDIR=	${PREFIX}/include

.if ${PREFIX} == "/usr/local"
MANDIR=	${PREFIX}/man/man
.endif

.include <bsd.prog.mk>