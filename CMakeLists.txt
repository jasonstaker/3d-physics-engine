cmake_minimum_required(VERSION 3.10)
project(PhysicsEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "C:/SFML")
include_directories(
    ${SFML_DIR}/include
    include/
    include/model
    include/ui
)

link_directories(${SFML_DIR}/lib)

configure_file(
    ${CMAKE_SOURCE_DIR}/assets/config/config.json
    ${CMAKE_BINARY_DIR}/config.json
    COPYONLY
)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
    src/main/model/*.cpp
    src/main/ui/*.cpp
)

add_executable(PhysicsEngine ${SOURCES})

target_link_libraries(PhysicsEngine
    sfml-graphics
    sfml-window
    sfml-system
)
