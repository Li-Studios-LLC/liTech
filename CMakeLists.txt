cmake_minimum_required(VERSION 3.30)
project(liTech)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

if(WIN32)
    add_definitions(-DLITECH_WIN32)
endif()

add_subdirectory(liTechFramework)
add_subdirectory(Runtime)