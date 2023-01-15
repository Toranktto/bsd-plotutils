add_library(plotdumb
        arc.c box.c circle.c close.c
        cont.c dot.c erase.c label.c
        line.c linemod.c move.c open.c
        point.c space.c subr.c dumb.h)
set_target_properties(plotdumb PROPERTIES
        VERSION 1.0.0
        SOVERSION 1)
target_link_libraries(plotdumb m termcap)
install(TARGETS plotdumb
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
add_executable(dumbplot ${CMAKE_SOURCE_DIR}/cmd/plot/driver.c)
target_link_libraries(dumbplot plotdumb)
install(TARGETS dumbplot DESTINATION ${CMAKE_INSTALL_LIBEXECDIR}/plot)
install(FILES ${CMAKE_SOURCE_DIR}/cmd/plot/plot.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 RENAME dumbplot.1)
