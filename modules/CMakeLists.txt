cmake_minimum_required( VERSION 3.12 )

if( CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" )
    set (CMAKE_CXX_FLAGS    "${CMAKE_CXX_FLAGS} -W1" )
    set (CMAKE_C_FLAGS      "${CMAKE_CXX_FLAGS} -W1" )

    string(REGEX REPLACE "[/-]WX" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    string(REGEX REPLACE "[/-]WX" "" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

elseif( CMAKE_CXX_COMPILER_ID STREQUAL "GNU" )
    string(REGEX REPLACE "[/-]Wall" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    string(REGEX REPLACE "[/-]Wall" "" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
    string(REGEX REPLACE "[/-]Werror" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    string(REGEX REPLACE "[/-]Werror" "" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
endif()

set(gtest_force_shared_crt          ON  CACHE BOOL "" FORCE)
set(INSTALL_GTEST                   OFF CACHE BOOL "" FORCE)
set(BUILD_GMOCK                     OFF CACHE BOOL "" FORCE)
set(gtest_build_tests               OFF CACHE BOOL "" FORCE)
set(gtest_build_samples             OFF CACHE BOOL "" FORCE)

add_subdirectory( googletest )
