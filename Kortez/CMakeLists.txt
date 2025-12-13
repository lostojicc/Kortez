#
# Kortez
#

set(SOURCES
    src/Core/Application.h
    src/Core/Application.cpp
)

add_library(Kortez STATIC)

target_sources(Kortez PRIVATE ${SOURCES})

# Match VS filters to directory structure on disk
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

add_compile_definitions(
    GLFW_INCLUDE_NONE
)

target_link_libraries(Kortez glfw)
target_link_libraries(Kortez glad)
target_link_libraries(Kortez glm)

target_include_directories(Kortez PUBLIC "src")