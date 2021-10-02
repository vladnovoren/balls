#include "phys_engine.hpp"


void PhysEngine::UpdateAll(CreaturesContainer* creatures_container) {
  assert(creatures_container);

  collision_manager.CollideAll(creatures_container);
}
