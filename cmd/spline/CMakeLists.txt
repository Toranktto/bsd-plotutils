add_executable(spline spline.c)
install(TARGETS spline DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES spline.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1)
