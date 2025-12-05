cmake_minimum_required(VERSION 3.10)
project(main)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

if(MSVC)
    add_compile_options(/utf-8)
else()
    add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)
endif()

file(GLOB MAIN_SOURCES "${CMAKE_SOURCE_DIR}/*.cpp")
file(GLOB LIB_SOURCES "${CMAKE_SOURCE_DIR}/lib/*.cpp")


add_executable(main ${MAIN_SOURCES} ${LIB_SOURCES})
set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)