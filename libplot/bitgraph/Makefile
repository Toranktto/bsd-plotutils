#	@(#)Makefile	5.3 (Berkeley) 5/11/90

LIB=	plotbg
SRCS=	box.c circle.c arc.c cont.c dot.c erase.c line.c linemod.c point.c \
	label.c move.c open.c close.c space.c
CFLAGS+=	-I../plot -I${INCLUDEDIR}
LDADD=	-L${LIBDIR} -lm
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

INSTALL=	../../scripts/install-fixed.sh
MINSTALL=	../../scripts/install-fixed.sh

.include <bsd.lib.mk>
