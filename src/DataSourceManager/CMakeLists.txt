set(MODULE_NAME DataSourceManager)

set(PUBLIC_HEADERS
     DataSourceManager.h
)
set(LIBRARY_SOURCES
	src/DataSourceManager.cpp
)

set(SRC_LIST ${PUBLIC_HEADERS} ${LIBRARY_SOURCES})

evgr_add_lib(${MODULE_NAME} STATIC ${SRC_LIST})

set_target_properties(${MODULE_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${MODULE_NAME}
     PUBLIC
)