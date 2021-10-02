#ifndef PHYS_ENGINE
#define PHYS_ENGINE

#include "collisions.hpp"
#include "creatures_container.hpp"

const double COULOMBS_LAW_K = 9e9;


class PhysEngine {
  CollisionManager collision_manager;
public:
  void MoveAll(const double dt, CreaturesContainer* creatures_container);

  void Tick(const double dt, CreaturesContainer* creatures_container);
};


#endif /* phys_engine.hpp */
