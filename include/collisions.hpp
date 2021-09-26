#ifndef COLLISIONS_HPP
#define COLLISIONS_HPP

#include "phys_objects.hpp"


class CollisionManager {
public:
  void Collide(PhysObject* first, PhysObject* second);

  void CollideBallBall(PhysBall* first, PhysBall* second);
};


#endif /* collisions.hpp */

