#ifndef REACT_FUNCS_HPP
#define REACT_FUNCS_HPP

#include "collide_funcs.hpp"
#include "creatures_container.hpp"

const double MIN_REACT_ENERGY = 1000;


bool ReadyToReact(Creature* creature);

bool DidReact(PhysObject* phys_obj1, PhysObject* phys_obj2);

void TurnCubesIntoBall(PhysCube* phys_cube1, PhysCube* phys_cube2, CreaturesContainer* creatures_container);

void TurnCubeBallIntoBall(PhysBall* phys_ball, PhysCube* phys_cube, CreaturesContainer* creatures_container);

void TurnBallIntoCubes(PhysBall* phys_ball, CreaturesContainer* creatures_container);

bool ReactBallBall(PhysObject* raw_phys_ball1, PhysObject* raw_phys_ball2, CreaturesContainer* creatures_manager);

bool ReactBallCube(PhysObject* raw_phys_ball, PhysObject* raw_phys_cube, CreaturesContainer* creatures_manager);

bool ReactCubeCube(PhysObject* raw_phys_cube1, PhysObject* raw_phys_cube2, CreaturesContainer* creatures_manager);


#endif /* react_funcs.hpp */