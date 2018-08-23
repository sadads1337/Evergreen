cmake_minimum_required(VERSION 3.10)
project(Evergreen)

set(OUTPUT_PATH "${PROJECT_BINARY_DIR}/build/${CMAKE_CFG_INTDIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<1:${OUTPUT_PATH}>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY $<1:${OUTPUT_PATH}>)

include(cmake/evergreen.cmake)

include(include/CMakeLists.txt)

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src/Core)
add_subdirectory(src/TestApp)
add_subdirectory(src/TestAppLib)
