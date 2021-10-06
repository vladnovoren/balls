#ifndef REACT_FUNCS_HPP
#define REACT_FUNCS_HPP

#include "collide_funcs.hpp"
#include "creatures_container.hpp"


void TurnCubesIntoBall(Cube* cube1, Cube* cube2, CreaturesContainer* creatures_container);

void TurnCubeBallIntoBall(Cube* cube, Ball* ball, CreaturesContainer* creatures_container);

void TurnBallIntoCubes(Ball* ball, CreaturesContainer* creatures_container);

bool ReactBallBall(Creature* raw_ball1, Creature* raw_ball2, CreaturesContainer* creatures_manager);

bool ReactBallCube(Creature* raw_ball, Creature* raw_cube, CreaturesContainer* creatures_manager);

bool ReactCubeCube(Creature* raw_cube1, Creature* raw_cube2, CreaturesContainer* creatures_manager);


#endif /* react_funcs.hpp */