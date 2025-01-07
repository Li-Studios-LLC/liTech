file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)

add_library(liTechFramework STATIC)
target_sources(liTechFramework PRIVATE ${SRCS} ${HDRS})

set_target_properties(liTechFramework PROPERTIES FOLDER "Engine")
target_include_directories(liTechFramework PUBLIC ${PROJECT_SOURCE_DIR})
target_include_directories(liTechFramework PUBLIC ${PROJECT_SOURCE_DIR}/liTechFramework)
target_include_directories(liTechFramework PUBLIC ${PROJECT_SOURCE_DIR}/liTech-dependencies/Include)
target_link_directories(liTechFramework PUBLIC ${PROJECT_SOURCE_DIR}/liTech-dependencies/Lib)