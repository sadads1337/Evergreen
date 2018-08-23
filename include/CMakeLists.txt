set(MODULE_NAME EvergreenAPI)

set(SRC_LIST
    include/Types.h
)

evgr_add_hlib(${MODULE_NAME} ${SRC_LIST})

target_link_libraries(${MODULE_NAME}
    INTERFACE

)

target_include_directories(${MODULE_NAME}
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}
)
