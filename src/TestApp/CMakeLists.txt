set(MODULE_NAME TestApp)

set(SRC_LIST
    src/main.cpp
)

evgr_add_executable(${MODULE_NAME} ${SRC_LIST})

target_link_libraries(${MODULE_NAME}
     PUBLIC
         evergreen::TestAppLib
)
