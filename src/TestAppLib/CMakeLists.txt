set(MODULE_NAME TestAppLib)

set(PUBLIC_HEADERS
    MainWindow.h
)
set(LIBRARY_SOURCES
    src/MainWindow.cpp
    src/Widget.h
    src/Widget.cpp
)

set(SRC_LIST ${PUBLIC_HEADERS} ${LIBRARY_SOURCES})

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
include_directories(${Qt5Widgets_INCLUDES})
add_definitions(${Qt5Widgets_DEFINITIONS})

evgr_add_lib(${MODULE_NAME} STATIC ${SRC_LIST})

target_link_libraries(${MODULE_NAME}
    PUBLIC
        ${Qt5Widgets_LIBRARIES}
)
