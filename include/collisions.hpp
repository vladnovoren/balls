#ifndef COLLISIONS_HPP
#define COLLISIONS_HPP

#include "phys_objects.hpp"
#include "tools.hpp"


class CollisionManager {
public:
  void CollideAll(ObjectManager* obj_manager);

  void Collide(PhysObject* first, PhysObject* second);

  bool DidCollide(const PhysBall& first, const PhysBall& second);

  void CollideBallBall(PhysBall* first, PhysBall* second);
};


#endif /* collisions.hpp */

