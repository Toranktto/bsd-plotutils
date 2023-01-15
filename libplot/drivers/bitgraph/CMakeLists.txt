add_library(plotbg
        arc.c box.c circle.c close.c
        cont.c dot.c erase.c label.c
        line.c linemod.c move.c open.c
        point.c space.c bg.h)
set_target_properties(plotbg PROPERTIES
        VERSION 1.0.0
        SOVERSION 1)
target_link_libraries(plotbg m)
install(TARGETS plotbg
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
add_executable(bgplot ${CMAKE_SOURCE_DIR}/cmd/plot/driver.c)
target_link_libraries(bgplot plotbg)
install(TARGETS bgplot DESTINATION ${CMAKE_INSTALL_LIBEXECDIR}/plot)
install(FILES ${CMAKE_SOURCE_DIR}/cmd/plot/plot.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 RENAME bgplot.1)
