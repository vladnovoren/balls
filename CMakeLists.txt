cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(balls VERSION 1.0)

set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Werror -O2")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(balls src/creatures.cpp src/creatures_container.cpp
               src/coord_sys.cpp src/collisions.cpp src/color.cpp
               src/component.cpp src/graphics.cpp src/phys_engine.cpp
               src/phys_objects.cpp src/renderable.cpp src/app.cpp src/main.cpp
               src/tools.cpp src/creatures_manager.cpp src/forces_manager.cpp
               src/chem_manager.cpp src/collide_funcs.cpp src/react_funcs.cpp)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

include_directories(include/)

target_link_libraries(balls sfml-graphics)