cmake_minimum_required(VERSION 4.0)
project(liTech)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
add_compile_definitions(UNICODE _UNICODE _CRT_SECURE_NO_WARNINGS)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(_DEBUG DEBUG)
else()
    add_compile_definitions(_RELEASE RELEASE)
endif()

add_subdirectory(LiDependencies)

file(GLOB_RECURSE SRCS src/*.cpp src/*.c)
file(GLOB_RECURSE HDRS src/*.h)

add_executable(liTech)
target_sources(liTech PUBLIC ${SRCS} ${HDRS})

if(WIN32)
    add_custom_command(TARGET liTech POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${PROJECT_SOURCE_DIR}/LiDependencies/Bin/SDL3.dll
        $<TARGET_FILE_DIR:liTech>)

    add_custom_command(TARGET liTech POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${PROJECT_SOURCE_DIR}/LiDependencies/Bin/OpenAL32.dll
        $<TARGET_FILE_DIR:liTech>)

    target_link_options(liTech PRIVATE "$<$<CONFIG:Release>:/SUBSYSTEM:WINDOWS>" "$<$<CONFIG:Debug>:/SUBSYSTEM:CONSOLE>")
endif()

target_precompile_headers(liTech PUBLIC src/pch.h)
target_link_libraries(liTech LiDependencies SDL3 OpenAL32 opengl32)
target_include_directories(liTech PUBLIC ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/LiDependencies/Include)
target_link_directories(liTech PUBLIC ${PROJECT_SOURCE_DIR}/LiDependencies/Lib)
set_property(TARGET liTech PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")