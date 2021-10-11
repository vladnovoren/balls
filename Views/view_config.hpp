#ifndef VIEW_CONFIG
#define VIEW_CONFIG

#include "creatures.hpp"
#include "coord_sys.hpp"
#include "color.hpp"
#include "creatures_config.hpp"


const double ppu = 1;

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;
const Vector2f WINDOW_SIZE(WINDOW_WIDTH, WINDOW_HEIGHT);


const Vector2f P_CENTER(0, WINDOW_HEIGHT);
const Vector2f MIN_POINT = LEFT_WALL_BEGIN - Vector2f(5, 5);
const Vector2f MAX_POINT = RIGHT_WALL_END + Vector2f(5, 5);
const Ranges RANGES(MAX_POINT, MIN_POINT);
const CoordSys COORD_SYS(P_CENTER, ppu);

const ColorRGB CLEAR_COLOR(0, 0, 0);

const Vector2f BUTTON_BALL_POS(1010, 5);
const Vector2f BUTTON_BALL_SIZE(185, 100);
const Rect BUTTON_BALL_RECT(BUTTON_BALL_POS, BUTTON_BALL_SIZE);
const ColorRGB BUTTON_BALL_COLOR(1, 0, 0);

const Vector2f BUTTON_CUBE_POS(1010, 110);
const Vector2f BUTTON_CUBE_SIZE = BUTTON_BALL_SIZE;
const Rect BUTTON_CUBE_RECT(BUTTON_CUBE_POS, BUTTON_CUBE_SIZE);
const ColorRGB BUTTON_CUBE_COLOR(0, 0, 1);

const Vector2f SPAWN_POSITION(0.5 * (MAX_POINT + MIN_POINT));


#endif /* view_config.hpp */
