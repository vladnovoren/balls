#ifndef CREATURES_CONFIG_HPP
#define CREATURES_CONFIG_HPP

#include "color.hpp"
#include "vector2.hpp"


const ColorRGB WALL_COLOR(1, 0, 0);
const Vector2f LEFT_WALL_BEGIN(5, 195);
const Vector2f LEFT_WALL_END(5, 795);
const Vector2f RIGHT_WALL_BEGIN(1005, 195);
const Vector2f RIGHT_WALL_END(1005, 795);
const double DELTA_POSITION = 60;
const Vector2f DEFAULT_VELOCITY(20, 20);


#endif /* creatures_config.hpp */
