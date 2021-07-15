cmake_minimum_required(VERSION 3.14)

# set the project name
project(HelloCpp)

add_executable(${PROJECT_NAME} "") #declare target name
add_subdirectory(src)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)






