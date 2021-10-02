#include "phys_engine.hpp"


void PhysEngine::UpdateAll(MoleculesManager* molecules_manager) {
  assert(molecules_manager);

  collision_manager.CollideAll(molecules_manager);
}