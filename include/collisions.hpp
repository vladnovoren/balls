#ifndef COLLISIONS_HPP
#define COLLISIONS_HPP

#include "phys_objects.hpp"
#include "creatures_manager.hpp"
#include "tools.hpp"


class CollisionManager {
public:
  void CollideAll(CreaturesManager* creatures_manager);

  void Collide(PhysObject* first, PhysObject* second);

  bool DidCollide(const PhysBall* first, const PhysBall* second);

  bool CollideBallBall(PhysBall* first, PhysBall* second);
};


#endif /* collisions.hpp */

