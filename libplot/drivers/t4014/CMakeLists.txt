add_library(4014
        arc.c box.c circle.c close.c
        dot.c erase.c label.c line.c
        linemod.c move.c open.c point.c
        scale.c space.c subr.c t4014.h)
set_target_properties(4014 PROPERTIES
        VERSION 1.0.0
        SOVERSION 1)
target_link_libraries(4014 m)
install(TARGETS 4014
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
add_executable(tek ${CMAKE_SOURCE_DIR}/cmd/plot/driver.c)
target_link_libraries(tek 4014)
install(TARGETS tek DESTINATION ${CMAKE_INSTALL_LIBEXECDIR}/plot)
install(FILES ${CMAKE_SOURCE_DIR}/cmd/plot/plot.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 RENAME tek.1)
