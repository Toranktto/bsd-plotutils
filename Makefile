SUBDIR=	lib cmd

PREFIX?=	/usr/local
BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib
MANDIR=	${PREFIX}/share/man
FILESDIR=	${PREFIX}/share/misc
INCLUDEDIR=	${PREFIX}/include
LIBEXECDIR=	${PREFIX}/libexec

.if ${PREFIX} == "/usr/local"
MANDIR=	${PREFIX}/man/man
.endif

clang-format:
	@find . \( -type f -name '*.c' -o -name '*.h' \) -exec clang-format --verbose -style=file -i {} \;

hier:
	@mkdir -pv ${BINDIR} ${LIBDIR} ${MANDIR} ${MANDIR}/man3 ${MANDIR}/man1 ${MANDIR}/man5 ${FILESDIR} ${INCLUDEDIR} ${LIBEXECDIR}

.include <bsd.subdir.mk>