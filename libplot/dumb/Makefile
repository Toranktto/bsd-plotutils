#	@(#)Makefile	5.3 (Berkeley) 5/12/90

LIB=	plotdumb
SRCS=	arc.c box.c circle.c close.c cont.c dot.c erase.c label.c \
	line.c linemod.c move.c open.c point.c space.c subr.c
CFLAGS+=	-I../plot -I${INCLUDEDIR}
LDADD=	-L${LIBDIR} -lm -ltermcap
CSTD=c99
SHLIB_MAJOR=	1
SHLIB_MINOR=	0

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

INSTALL=	../../install-fixed.sh
MINSTALL=	../../install-fixed.sh

.include <bsd.lib.mk>
