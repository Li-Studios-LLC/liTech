cmake_minimum_required(VERSION 3.20)
project(liTech)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_compile_definitions(UNICODE _UNICODE _CRT_SECURE_NO_WARNINGS)

# Some compilers dont have this macro
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(_DEBUG DEBUG)
else()
    add_compile_definitions(_RELEASE RELEASE)
endif()

add_subdirectory(liTechFramework)
add_subdirectory(Runtime)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Runtime)