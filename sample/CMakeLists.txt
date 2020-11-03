cmake_minimum_required( VERSION 3.12 )

project (OptValue.Sample)

######################################
# Register targets
######################################

ADD_EXECUTABLE (${PROJECT_NAME} sample.cpp)

TARGET_LINK_LIBRARIES ( ${PROJECT_NAME}
    OptValue
)

