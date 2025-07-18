cmake_minimum_required(VERSION 3.20)
project(liTech)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
add_compile_definitions(UNICODE _UNICODE _CRT_SECURE_NO_WARNINGS)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(_DEBUG DEBUG)
else()
    add_compile_definitions(_RELEASE RELEASE)
endif()

if(MSVC)
    if(NOT CMAKE_GENERATOR STREQUAL "Ninja")
        add_definitions(/MP)
    endif()
endif()

add_subdirectory(LiDependencies)

file(GLOB_RECURSE SRCS src/*.cpp src/*.c)
file(GLOB_RECURSE HDRS src/*.h)

if(ANDROID)
    set(EXECUTABLE_NAME main)
    add_library(${EXECUTABLE_NAME} SHARED)
else()
    set(EXECUTABLE_NAME ${PROJECT_NAME})
    add_executable(liTech)
endif()

if(WIN32)
    target_link_libraries(${EXECUTABLE_NAME} opengl32)
    target_link_options(${EXECUTABLE_NAME} PRIVATE "$<$<CONFIG:Release>:/SUBSYSTEM:WINDOWS>" "$<$<CONFIG:Debug>:/SUBSYSTEM:CONSOLE>")
endif()

target_sources(${EXECUTABLE_NAME} PUBLIC ${SRCS} ${HDRS})
target_precompile_headers(${EXECUTABLE_NAME} PUBLIC src/pch.h)
target_link_libraries(${EXECUTABLE_NAME} LiDependencies SDL3::SDL3 OpenAL::OpenAL)
target_include_directories(${EXECUTABLE_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)
# Vendors
target_include_directories(${EXECUTABLE_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/LiDependencies/SDL/include)
target_include_directories(${EXECUTABLE_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/LiDependencies/openal-soft)
target_include_directories(${EXECUTABLE_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/LiDependencies/cglm/include)

set_property(TARGET ${EXECUTABLE_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")