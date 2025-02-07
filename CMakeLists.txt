cmake_minimum_required(VERSION 3.20)
project(liTech)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_compile_definitions(UNICODE _UNICODE _CRT_SECURE_NO_WARNINGS)

if(WIN32)
    add_compile_definitions(LITECH_WIN32)

    add_compile_definitions($<$<CONFIG:Debug>:LITECH_DEBUG>
      $<$<CONFIG:RelWithDebInfo>:LITECH_DEBUG>
      $<$<CONFIG:Release>:LITECH_RELEASE>
      $<$<CONFIG:MinSizeRel>:LITECH_RELEASE>)
elseif(UNIX AND NOT APPLE)
    add_compile_definitions(LITECH_LINUX LITECH_DEBUG LITECH_OPENGLES)
elseif(APPLE)
    add_compile_definitions(LITECH_WEB LITECH_RELEASE LITECH_OPENGLES)
endif()

add_subdirectory(liTechFramework)
add_subdirectory(Runtime)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Runtime)