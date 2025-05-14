cmake_minimum_required(VERSION 3.15)
project(PhysicsEngine2D VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    main/src/*.cpp
)

add_executable(physics-engine ${SOURCES})