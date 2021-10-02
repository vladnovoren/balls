#include "phys_engine.hpp"


void PhysEngine::MoveAll(const double dt, CreaturesContainer* creaturs_container) {
  assert(creaturs_container);

  for (size_t i = 0; i < creaturs_container->NumOfCreatures(); ++i) {
    creaturs_container->GetPhysComponent(i)->Move(dt);
  }
}


void PhysEngine::Tick(const double dt, CreaturesContainer* creatures_container) {
  assert(creatures_container);

  collision_manager.CollideAll(creatures_container);
  MoveAll(dt, creatures_container);
}
