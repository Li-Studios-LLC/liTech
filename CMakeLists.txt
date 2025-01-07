cmake_minimum_required(VERSION 3.20)
project(liTech)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIGURATION>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIGURATION>)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_compile_definitions(-DUNICODE -D_UNICODE -D_CRT_SECURE_NO_WARNINGS)

if(WIN32)
    add_compile_definitions(-DLITECH_WIN32)
elseif(__linux__)
    add_compile_definitions(-DLITECH_LINUX)
elseif(__EMSCRIPTEN__)
    add_compile_definitions(-DLITECH_WEB)
endif()

add_subdirectory(liTechFramework)
add_subdirectory(Runtime)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Runtime)