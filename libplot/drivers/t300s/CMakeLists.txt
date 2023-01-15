add_library(300s
        arc.c box.c circle.c close.c
        dot.c erase.c label.c line.c
        linemod.c move.c open.c point.c
        space.c subr.c con.h)
set_target_properties(300s PROPERTIES
        VERSION 1.0.0
        SOVERSION 1)
target_link_libraries(300s m termcap)
install(TARGETS 300s
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
add_executable(t300s ${CMAKE_SOURCE_DIR}/cmd/plot/driver.c)
target_link_libraries(t300s 300s)
install(TARGETS t300s DESTINATION ${CMAKE_INSTALL_LIBEXECDIR}/plot)
install(FILES ${CMAKE_SOURCE_DIR}/cmd/plot/plot.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 RENAME t300s.1)