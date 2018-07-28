#	@(#)Makefile	4.6 (Berkeley) 5/11/90

PROG=	graph
LDADD=	-L../libplot/plot -lplot -lm
BINDIR=	/usr/local/bin
MANDIR=	/usr/local/man/man

install: maninstall
	install ${STRIP} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${PROG} \
	    ${DESTDIR}${BINDIR}/graph

.include <bsd.prog.mk>
