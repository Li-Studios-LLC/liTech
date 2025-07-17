cmake_minimum_required(VERSION 3.20)
project(liTech)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
add_compile_definitions(UNICODE _UNICODE _CRT_SECURE_NO_WARNINGS)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(_DEBUG DEBUG)
else()
    add_compile_definitions(_RELEASE RELEASE)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(LiDependencies)

file(GLOB_RECURSE SRCS src/*.cpp src/*.c)
file(GLOB_RECURSE HDRS src/*.h)

add_executable(liTech)
target_sources(liTech PUBLIC ${SRCS} ${HDRS})

if(WIN32)
    target_link_libraries(liTech opengl32)
    target_link_options(liTech PRIVATE "$<$<CONFIG:Release>:/SUBSYSTEM:WINDOWS>" "$<$<CONFIG:Debug>:/SUBSYSTEM:CONSOLE>")
endif()

target_precompile_headers(liTech PUBLIC src/pch.h)
target_link_libraries(liTech LiDependencies SDL3::SDL3 OpenAL::OpenAL)
target_include_directories(liTech PUBLIC ${PROJECT_SOURCE_DIR}/src)
# Vendors
target_include_directories(liTech PUBLIC ${PROJECT_SOURCE_DIR}/LiDependencies/SDL/include)
target_include_directories(liTech PUBLIC ${PROJECT_SOURCE_DIR}/LiDependencies/openal-soft)
target_include_directories(liTech PUBLIC ${PROJECT_SOURCE_DIR}/LiDependencies/cglm/include)

set_property(TARGET liTech PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")