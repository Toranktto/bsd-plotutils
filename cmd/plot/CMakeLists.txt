install(PROGRAMS plot.sh RENAME plot DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES plot.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1)
install(PROGRAMS plot.sh RENAME tplot DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES plot.1 RENAME tplot.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1)
