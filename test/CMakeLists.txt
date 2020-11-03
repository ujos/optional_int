cmake_minimum_required( VERSION 3.12 )

project (OptValue.Test)

######################################
# Register targets
######################################

ADD_EXECUTABLE (${PROJECT_NAME} test.cpp)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

TARGET_LINK_LIBRARIES ( ${PROJECT_NAME}
    OptValue
    gtest
    gtest_main
)

