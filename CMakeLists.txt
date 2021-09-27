cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR) 

project(balls VERSION 1.0)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
#set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -O2")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O2")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(balls src/test.cpp src/graphics.cpp src/color.cpp src/tools.cpp
               src/phys_objects.cpp src/renderable.cpp src/collisions.cpp
               src/creatures.cpp src/creatures_manager.cpp)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

include_directories(include/)

target_link_libraries(balls sfml-graphics)
