add_library(plot arc.c box.c circle.c close.c
        cont.c dot.c erase.c label.c
        line.c linemod.c move.c open.c
        point.c putsi.c space.c plotinternal.h
        include/plot.h include/plotcompat.h)
set_target_properties(plot PROPERTIES
        VERSION 1.0.0
        SOVERSION 1
        PUBLIC_HEADER "include/plot.h;include/plotcompat.h")
install(TARGETS plot
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES plot.3 DESTINATION ${CMAKE_INSTALL_MANDIR}/man3)
install(FILES plot.5 DESTINATION ${CMAKE_INSTALL_MANDIR}/man5)
