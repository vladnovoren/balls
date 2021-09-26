cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR) 

project(balls VERSION 1.0)

set(CMAKE_CXX_FLAGS "-O3")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(balls src/test.cpp src/graphics.cpp src/color.cpp
               src/phys_objects.cpp src/renderable.cpp src/collisions.cpp)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

include_directories(include/)

target_link_libraries(balls sfml-graphics)
