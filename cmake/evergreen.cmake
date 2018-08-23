option(GENERATE_TESTS "Option which turns on tests" OFF)

set(GCC_AND_CLANG_WARNINGS
     Werror
     Wall
     Wextra
     pedantic
     pedantic-errors
     Wswitch-enum
     Wuninitialized
     Wold-style-cast
     Wconversion
     Wsign-promo
     Wunused
     Wunused-parameter
     Wunused-result
     Wctor-dtor-privacy
     Wdelete-non-virtual-dtor
     Wnarrowing
     Wnon-virtual-dtor
     Woverloaded-virtual
     Wformat
     Wundef
     Wcast-qual
     Wcast-align
     Wwrite-strings
     Wconversion-null
     Wempty-body
     Wenum-compare
     Wredundant-decls
     Winvalid-pch
     Wvla
     Wdisabled-optimization
     Wno-error=unused-function
     Wsign-conversion
     Wmissing-field-initializers
)

set(GCC_ONLY_WARNINGS
     -Wno-error=maybe-uninitialized
     -Wunused-local-typedefs
     -Wlogical-op
)

set(CLANG_ONLY_WARNINGS
     -Wunused-private-field
)

#todo: запилить студийные
set(MSVC_ONLY_WARNINGS
    
)

add_library(EvergreenWarnings INTERFACE)
target_compile_options(EvergreenWarnings INTERFACE
    $<$<CXX_COMPILER_ID:MSVC>:${MSVC_ONLY_WARNINGS}>
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:${GCC_AND_CLANG_WARNINGS}>
    $<$<CXX_COMPILER_ID:GNU>:${GCC_ONLY_WARNINGS}>
    $<$<CXX_COMPILER_ID:Clang>:${CLANG_ONLY_WARNINGS}>
)

add_library(EvergreenDefines INTERFACE)
target_compile_definitions(EvergreenDefines INTERFACE
    EVGR_WINDOWS=$<CXX_COMPILER_ID:MSVC>
    EVGR_WINDOWS_DESKTOP=$<CXX_COMPILER_ID:MSVC>
    EVGR_APPLE=$<PLATFORM_ID:Darwin>
    EVGR_LINUX=$<PLATFORM_ID:Linux>
    EVGR_MSVS=$<CXX_COMPILER_ID:MSVC>
    EVGR_GCC=$<CXX_COMPILER_ID:GNU>
    EVGR_CLANG=$<CXX_COMPILER_ID:Clang>

    # Отключаем все остальное
    EVGR_UWP=0
    EVGR_ANDROID=0
    EVGR_RASPBERRY_PI=0
    EVGR_IOS=0
)

function(evgr_add_hlib lib)
    add_library(${lib} INTERFACE)
    target_link_libraries(${lib} INTERFACE EvergreenDefines)
    target_include_directories(${lib}
        SYSTEM INTERFACE
            ${PROJECT_SOURCE_DIR}/Src
    )
    add_library(evergreen::${lib} ALIAS ${lib})

    add_library(${lib}_IDE OBJECT ${ARGN})
    set_target_properties(${lib}_IDE PROPERTIES LINKER_LANGUAGE CXX)
endfunction()

function(evgr_add_lib lib)
    add_library(${lib} ${ARGN})
    target_link_libraries(${lib}
        PUBLIC
            evergreen::EvergreenAPI
        PRIVATE
            EvergreenWarnings
            EvergreenDefines
    )
    target_include_directories(${lib}
        PUBLIC
            ${PROJECT_SOURCE_DIR}/Src
    )
    add_library(evergreen::${lib} ALIAS ${lib})
endfunction()

function(evgr_add_executable exe)
    add_executable(${exe} ${ARGN})
    target_link_libraries(${exe}
        PRIVATE
            evergreen::EvergreenAPI
            EvergreenWarnings
            EvergreenDefines
    )
    target_include_directories(${exe}
        PUBLIC
            ${PROJECT_SOURCE_DIR}/Src
    )
    add_executable(evergreen::${exe} ALIAS ${exe})
endfunction()