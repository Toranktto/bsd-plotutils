add_library(vt0
        arc.c box.c circle.c close.c
        dot.c erase.c frame.c label.c
        line.c linemod.c move.c open.c
        point.c space.c subr.c)
set_target_properties(vt0 PROPERTIES
        VERSION 1.0.0
        SOVERSION 1)
target_link_libraries(vt0 m termcap)
install(TARGETS vt0
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
