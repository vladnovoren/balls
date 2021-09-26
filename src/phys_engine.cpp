#include "phys_engine.hpp"


void PhysEngine::AddCreature(const PhysBall* creature) {
  assert(creature);

  if (n_creatures == MAX_N_CREATURES)
    return;
  creatures[n_creatures++] = *creature;
}


void PhysEngine::ResponseAllForces() {
  for (size_t i = 0; i < n_creatures; ++i) {
    if (creatures[i].GetType() != PhysObject::PhysType::PHYS_CHARGED_BALL)
      continue;
    for (size_t j = i + 1; j < n_creatures; ++j) {
      if (creatures[j].GetType() != PhysObject::PhysType::PHYS_CHARGED_BALL)
        continue;
    }
  }
}
