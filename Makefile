SUBDIR=	lib cmd

clang-format:
	@find . \( -type f -name '*.c' -o -name '*.h' \) -exec clang-format --verbose -style=file -i {} \;

hier:
	@mkdir -pv ${BINDIR} ${LIBDIR} ${MANDIR}/man1 ${MANDIR}/man3 \
			${MANDIR}/man5 ${FILESDIR} ${INCLUDEDIR} ${LIBEXECDIR}

.include "./Makefile.inc"
.include <bsd.subdir.mk>