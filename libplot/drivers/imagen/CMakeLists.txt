add_library(plotimagen
        arc.c box.c charset.c circle.c
        close.c cont.c dot.c erase.c
        label.c line.c linemod.c move.c
        open.c point.c scale.c space.c
        imp.h imPcodes.h)
set_target_properties(plotimagen PROPERTIES
        VERSION 1.0.0
        SOVERSION 1)
target_link_libraries(plotimagen m)
install(TARGETS plotimagen
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
add_executable(implot ${CMAKE_SOURCE_DIR}/cmd/plot/driver.c)
target_link_libraries(implot plotimagen)
install(TARGETS implot DESTINATION ${CMAKE_INSTALL_LIBEXECDIR}/plot)
install(FILES ${CMAKE_SOURCE_DIR}/cmd/plot/plot.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 RENAME implot.1)
