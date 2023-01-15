add_library(plot7221
        arc.c box.c circle.c close.c
        cont.c dot.c erase.c label.c
        line.c linemod.c move.c open.c
        point.c space.c subr.c hp7221.h)
set_target_properties(plot7221 PROPERTIES
        VERSION 1.0.0
        SOVERSION 1)
target_link_libraries(plot7221 m)
install(TARGETS plot7221
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
add_executable(hp7221plot ${CMAKE_SOURCE_DIR}/cmd/plot/driver.c)
target_link_libraries(hp7221plot plot7221)
install(TARGETS hp7221plot DESTINATION ${CMAKE_INSTALL_LIBEXECDIR}/plot)
install(FILES ${CMAKE_SOURCE_DIR}/cmd/plot/plot.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 RENAME hp7221plot.1)
