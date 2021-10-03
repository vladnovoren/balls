#ifndef PHYS_ENGINE
#define PHYS_ENGINE

#include "collisions.hpp"
#include "creatures_container.hpp"
#include "forces_manager.hpp"


class PhysEngine {
  CollisionManager collision_manager;
  ForcesManager forces_manager;
public:
  void Move(const double dt, CreaturesContainer* creatures_container);

  void Tick(const double dt, CreaturesContainer* creatures_container);
};


#endif /* phys_engine.hpp */
