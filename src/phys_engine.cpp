#include "phys_engine.hpp"


void PhysEngine::Move(const double dt, CreaturesContainer* creatures_container) {
  assert(creatures_container);

  for (size_t i = 0; i < creatures_container->NumOfCreatures(); ++i) {
    creatures_container->GetPhysComponent(i)->Move(dt);
  }
}


void PhysEngine::Tick(const double dt, CreaturesContainer* creatures_container) {
  assert(creatures_container);

  Move(dt, creatures_container);
  collision_manager.CollideAll(creatures_container);
  forces_manager.ResponseAll(creatures_container);
}
