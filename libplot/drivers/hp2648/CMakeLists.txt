add_library(plot2648
        arc.c box.c circle.c close.c
        cont.c dot.c erase.c label.c
        line.c linemod.c move.c open.c
        point.c space.c subr.c hp2648.h)
set_target_properties(plot2648 PROPERTIES
        VERSION 1.0.0
        SOVERSION 1)
target_link_libraries(plot2648 m)
install(TARGETS plot2648
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
add_executable(hpplot ${CMAKE_SOURCE_DIR}/cmd/plot/driver.c)
target_link_libraries(hpplot plot2648)
install(TARGETS hpplot DESTINATION ${CMAKE_INSTALL_LIBEXECDIR}/plot)
install(FILES ${CMAKE_SOURCE_DIR}/cmd/plot/plot.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 RENAME hpplot.1)
