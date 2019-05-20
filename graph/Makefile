#	@(#)Makefile	4.6 (Berkeley) 5/11/90

PROG=	graph
LDADD=	-L../libplot/plot -L${LIBDIR} -lplot -lm
CFLAGS+=	-I../libplot/plot -I${INCLUDEDIR}
CSTD=c99

BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib
MANDIR=	${PREFIX}/share/man
FILESDIR=	${PREFIX}/share/misc
INCLUDEDIR=	${PREFIX}/include

UNAME_S!=	uname -s
.if ${UNAME_S} == "FreeBSD"
PREFIX?=	/usr/local
.else
PREFIX?=	/usr
.endif

.if ${PREFIX} == "/usr/local"
MANDIR=	${PREFIX}/man/man
.endif

INSTALL=	../install-fixed.sh
MINSTALL=	../install-fixed.sh

.include <bsd.prog.mk>
