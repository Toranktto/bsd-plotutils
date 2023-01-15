add_executable(atoplot atoplot.c)
target_link_libraries(atoplot plot)
install(TARGETS atoplot DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES ${CMAKE_SOURCE_DIR}/cmd/plot/plot.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 RENAME atoplot.1)
