add_library(plotgigi
        arc.c box.c circle.c close.c
        cont.c dot.c erase.c label.c
        line.c linemod.c move.c open.c
        point.c space.c gigi.h)
set_target_properties(plotgigi PROPERTIES
        VERSION 1.0.0
        SOVERSION 1)
target_link_libraries(plotgigi m)
install(TARGETS plotgigi
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
add_executable(gigiplot ${CMAKE_SOURCE_DIR}/cmd/plot/driver.c)
target_link_libraries(gigiplot plotgigi)
install(TARGETS gigiplot DESTINATION ${CMAKE_INSTALL_LIBEXECDIR}/plot)
install(FILES ${CMAKE_SOURCE_DIR}/cmd/plot/plot.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 RENAME gigiplot.1)
