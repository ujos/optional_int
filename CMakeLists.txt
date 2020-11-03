cmake_minimum_required( VERSION 3.12 )

project(OptValue)

set (CMAKE_CXX_STANDARD 17)

find_path(OptValue_INCLUDE_DIR    "opt_value.h" PATHS "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(OptValue_INCLUDE_DIR)
    add_library(OptValue INTERFACE IMPORTED GLOBAL)
    target_include_directories( OptValue INTERFACE "${OptValue_INCLUDE_DIR}" )
endif()

if (OptValue_WITH_UNIT_TESTS)
    enable_testing()

    add_subdirectory( modules )
    add_subdirectory( test )
endif()
