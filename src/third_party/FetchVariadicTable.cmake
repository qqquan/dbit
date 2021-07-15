cmake_minimum_required(VERSION 3.14)

include(FetchContent)

#Set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
    variadic_table_lib
    GIT_REPOSITORY https://github.com/friedmud/variadic_table.git
    GIT_TAG        82fcf65c00c70afca95f71c0c77fba1982a20a86  #master 

)

FetchContent_MakeAvailable(variadic_table_lib) #FetchContent does not support Upper Case in the target name, which would omit SOURCE_DIR to the downloaded library

message(STATUS "download the VariadicTable from git")


target_include_directories(${PROJECT_NAME}  PRIVATE ${variadic_table_lib_SOURCE_DIR}/include)


