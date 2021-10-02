#ifndef COLLISIONS_HPP
#define COLLISIONS_HPP

#include "creatures_container.hpp"



class CollisionManager {
public:
  CollisionManager();

  void CollideAll(CreaturesContainer* creatures_container);

  void Collide(PhysObject* first, PhysObject* second);

  bool DidCollide(const PhysBall* first, const PhysBall* second);

  bool CollideBallBall(PhysObject* raw_ball1, PhysObject* raw_ball2);

  bool CollideCubeCube(PhysObject* raw_cube1, PhysObject* raw_cube2);

  bool CollideBallCube(PhysObject* raw_ball, PhysObject* raw_cube);

  bool CollideBallWall(PhysObject* raw_ball, PhysObject* raw_wall);
protected:
  typedef bool (CollisionManager::*CollideFunc)(PhysObject*, PhysObject*);
  CollideFunc CollideTable[N_PHYS_OBJECTS][N_PHYS_OBJECTS] = {};
};


#endif /* collisions.hpp */
