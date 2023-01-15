add_library(plotaed
        arc.c box.c circle.c close.c
        cont.c dot.c erase.c label.c
        line.c linemod.c move.c open.c
        point.c space.c subr.c aed.h)
set_target_properties(plotaed PROPERTIES
        VERSION 1.0.0
        SOVERSION 1)
install(TARGETS plotaed
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
add_executable(aedplot ${CMAKE_SOURCE_DIR}/cmd/plot/driver.c)
target_link_libraries(aedplot plotaed)
install(TARGETS aedplot DESTINATION ${CMAKE_INSTALL_LIBEXECDIR}/plot)
install(FILES ${CMAKE_SOURCE_DIR}/cmd/plot/plot.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 RENAME aedplot.1)
