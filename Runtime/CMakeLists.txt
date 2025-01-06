file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)

add_executable(Runtime ${SRCS} ${HDRS})

target_link_libraries(Runtime SDL3)
target_include_directories(Runtime PUBLIC ${PROJECT_SOURCE_DIR})
target_include_directories(Runtime PUBLIC ${PROJECT_SOURCE_DIR}/liTech-dependencies/Include)
target_link_directories(Runtime PUBLIC ${PROJECT_SOURCE_DIR}/liTech-dependencies/Lib)