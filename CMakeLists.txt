cmake_minimum_required(VERSION 3.24)
project(bsd-plotutils VERSION 1.4.3)

if ((NOT CMAKE_C_COMPILER_ID MATCHES "Clang") AND (NOT CMAKE_C_COMPILER_ID MATCHES "GNU"))
    message(FATAL_ERROR "This project at the moment supports only Clang and GCC compilers.")
endif ()
add_compile_options(
        -pedantic
        -Wall
        -Werror
        -Wno-implicit-function-declaration
)

include(GNUInstallDirs)
include_directories(libplot/include)

add_subdirectory(libplot/drivers/dumb)
add_subdirectory(libplot/drivers/t4014)
add_subdirectory(libplot/drivers/t4013)
add_subdirectory(libplot/drivers/t450)
add_subdirectory(libplot/drivers/t300)
add_subdirectory(libplot/drivers/t300s)
add_subdirectory(libplot/drivers/aed)
add_subdirectory(libplot/drivers/bitgraph)
add_subdirectory(libplot/drivers/imagen)
add_subdirectory(libplot/drivers/vt0)
add_subdirectory(libplot/drivers/hp7221)
add_subdirectory(libplot/drivers/hp2648)
add_subdirectory(libplot/drivers/gigi)
add_subdirectory(libplot)
add_subdirectory(cmd/graph)
add_subdirectory(cmd/spline)
add_subdirectory(cmd/plot)
add_subdirectory(cmd/plottoa)
add_subdirectory(cmd/atoplot)
add_subdirectory(cmd/vplot)
