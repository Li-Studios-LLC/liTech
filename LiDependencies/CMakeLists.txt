cmake_minimum_required(VERSION 4.0)
project(LiDependencies)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)
add_compile_definitions(UNICODE _UNICODE _CRT_SECURE_NO_WARNINGS)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(_DEBUG DEBUG)
else()
    add_compile_definitions(_RELEASE RELEASE)
endif()

file(GLOB_RECURSE SRCS src/*.cpp src/*.c)
file(GLOB_RECURSE HDRS src/*.h)

add_library(LiDependencies STATIC)
target_sources(LiDependencies PRIVATE ${SRCS} ${HDRS})
target_include_directories(LiDependencies PUBLIC ${PROJECT_SOURCE_DIR}/Include)