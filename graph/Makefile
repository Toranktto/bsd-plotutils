#	@(#)Makefile	4.6 (Berkeley) 5/11/90

PROG=	graph
LDADD=	-L../libplot/plot -lplot -lm
CFLAGS+=	-I../libplot/plot
CSTD=c99
PREFIX?=	/usr/local
BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib
MANDIR=	${PREFIX}/man/man
FILESDIR=	${PREFIX}/share/misc
INCLUDEDIR=	${PREFIX}/include

install: maninstall
	install ${STRIP} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${PROG} \
	    ${DESTDIR}${BINDIR}/graph

.include <bsd.prog.mk>
