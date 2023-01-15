add_executable(graph graph.c)
target_link_libraries(graph plot m)
install(TARGETS graph DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES graph.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1)
