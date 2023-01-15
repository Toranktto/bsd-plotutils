add_executable(vplot vplot.c chrtab.c)
install(TARGETS vplot DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES ${CMAKE_SOURCE_DIR}/cmd/plot/plot.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 RENAME vplot.1)
