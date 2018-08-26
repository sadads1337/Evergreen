set(MODULE_NAME DataSource)

set(PUBLIC_HEADERS
     IDataSource.h
)
set(LIBRARY_SOURCES
	src/DataSource.h
	src/DataSource.cpp
	src/DataSourceParameters.h
)

set(SRC_LIST ${PUBLIC_HEADERS} ${LIBRARY_SOURCES})

evgr_add_lib(${MODULE_NAME} STATIC ${SRC_LIST})

set_target_properties(${MODULE_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${MODULE_NAME}
     PUBLIC
)