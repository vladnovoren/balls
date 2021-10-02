#ifndef PHYS_ENGINE
#define PHYS_ENGINE

#include "collisions.hpp"
#include <cassert>

const double COULOMBS_LAW_K = 9e9;


class MoleculesManager;

class PhysEngine {
  CollisionManager collision_manager;
public:
  void UpdateAll(MoleculesManager* molecules_manager);
};


#endif /* phys_engine.hpp */
