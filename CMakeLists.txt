cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(balls VERSION 1.0)

set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Werror -O2")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(balls Creatures/creatures.cpp Creatures/creatures_container.cpp
               Physics/coord_sys.cpp Physics/collisions.cpp Graphics/color.cpp
               Creatures/component.cpp Graphics/graphics.cpp Physics/phys_engine.cpp
               Creatures/phys_objects.cpp Creatures/renderable.cpp General/app.cpp General/main.cpp
               Tools/tools.cpp Creatures/creatures_manager.cpp Physics/forces_manager.cpp
               Physics/chem_manager.cpp Physics/collide_funcs.cpp Physics/react_funcs.cpp
               Views/view.cpp)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

include_directories(Creatures/ Physics/ Graphics/ General/ Tools/ Views/)

target_link_libraries(balls sfml-graphics)