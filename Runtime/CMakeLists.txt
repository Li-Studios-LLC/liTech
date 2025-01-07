file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)

add_executable(Runtime)
target_sources(Runtime PRIVATE ${SRCS} ${HDRS})

if(WIN32)
    add_custom_command(TARGET Runtime POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${PROJECT_SOURCE_DIR}/liTech-dependencies/Bin/SDL3.dll
        $<TARGET_FILE_DIR:Runtime>)
endif()

set_target_properties(Runtime PROPERTIES FOLDER "Applications")
target_link_libraries(Runtime liTechFramework SDL3)
target_include_directories(Runtime PUBLIC ${PROJECT_SOURCE_DIR})
target_include_directories(Runtime PUBLIC ${PROJECT_SOURCE_DIR}/liTech-dependencies/Include)
target_link_directories(Runtime PUBLIC ${PROJECT_SOURCE_DIR}/liTech-dependencies/Lib)