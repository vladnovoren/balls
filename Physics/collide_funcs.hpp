#ifndef COLLIDE_FUNCS_HPP
#define COLLIDE_FUNCS_HPP

#include "creatures.hpp"


bool ReadyToCollide(Creature* creature);

bool DidCollideBallBall(const PhysBall* first, const PhysBall* second);

bool DidCollideBallWall(const PhysBall* ball, const PhysWall* wall);

bool CollideBallBall(PhysObject* raw_ball1, PhysObject* raw_ball2);

bool CollideBallCube(PhysObject* raw_ball, PhysObject* raw_cube);

void PushBallFromWall(PhysBall* ball, PhysWall* wall);

bool CollideBallWall(PhysObject* raw_ball, PhysObject* raw_wall);

bool CollideCubeCube(PhysObject* raw_cube1, PhysObject* raw_cube2);

bool CollideCubeWall(PhysObject* raw_cube, PhysObject* raw_wall);


#endif /* collide_funcs.hpp */