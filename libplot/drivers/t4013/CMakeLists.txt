add_library(4013
        arc.c box.c circle.c close.c
        dot.c erase.c label.c line.c
        linemod.c move.c open.c point.c
        scale.c space.c subr.c t4013.h)
set_target_properties(4013 PROPERTIES
        VERSION 1.0.0
        SOVERSION 1)
target_link_libraries(4013 m termcap)
install(TARGETS 4013
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
add_executable(t4013 ${CMAKE_SOURCE_DIR}/cmd/plot/driver.c)
target_link_libraries(t4013 4013)
install(TARGETS t4013 DESTINATION ${CMAKE_INSTALL_LIBEXECDIR}/plot)
install(FILES ${CMAKE_SOURCE_DIR}/cmd/plot/plot.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 RENAME t4013.1)
