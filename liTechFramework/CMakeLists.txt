file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)

add_library(liTechFramework STATIC ${SRCS} ${HDRS})

target_include_directories(liTechFramework PUBLIC ${PROJECT_SOURCE_DIR})
target_include_directories(liTechFramework PUBLIC ${PROJECT_SOURCE_DIR}/liTech-dependencies/Include)
target_link_directories(liTechFramework PUBLIC ${PROJECT_SOURCE_DIR}/liTech-dependencies/Lib)