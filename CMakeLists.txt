cmake_minimum_required(VERSION 3.20)
project(liTech)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIGURATION>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIGURATION>)

add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

if(WIN32)
    add_definitions(-DLITECH_WIN32)
elseif(__linux__)
    add_definitions(-DLITECH_LINUX)
endif()

add_subdirectory(liTechFramework)
add_subdirectory(Runtime)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Runtime)