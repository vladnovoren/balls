#include "collisions.hpp"


CollisionManager::CollisionManager() {
  CollideTable[int(PhysObject::PhysType::PHYS_BALL)][int(PhysObject::PhysType::PHYS_BALL)] = &CollideBallBall;
  CollideTable[int(PhysObject::PhysType::PHYS_BALL)][int(PhysObject::PhysType::PHYS_CUBE)] = &CollideBallCube;
  CollideTable[int(PhysObject::PhysType::PHYS_BALL)][int(PhysObject::PhysType::PHYS_WALL)] = &CollideBallWall;
  CollideTable[int(PhysObject::PhysType::PHYS_CUBE)][int(PhysObject::PhysType::PHYS_CUBE)] = &CollideCubeCube;
  CollideTable[int(PhysObject::PhysType::PHYS_CUBE)][int(PhysObject::PhysType::PHYS_WALL)] = &CollideCubeWall;
}


void CollisionManager::CollideAll(CreaturesContainer* creatures_container) {
  assert(creatures_container);

  for (size_t i = 0; i < creatures_container->NumOfCreatures(); ++i) {
    for (size_t j = i + 1; j < creatures_container->NumOfCreatures(); ++j) {
      Creature* creature_i = creatures_container->GetCreature(i);
      Creature* creature_j = creatures_container->GetCreature(j);

      if (!ReadyToCollide(creature_i) || !ReadyToCollide(creature_j))
        continue;

      PhysObject* phys_obj_i = creatures_container->GetPhysComponent(i);
      PhysObject* phys_obj_j = creatures_container->GetPhysComponent(j);

      int type_i = static_cast<int>(phys_obj_i->GetType());
      int type_j = static_cast<int>(phys_obj_j->GetType());

      if (type_i > type_j) {
        std::swap(phys_obj_i, phys_obj_j);
        std::swap(type_i, type_j);
      }

      if (CollideTable[type_i][type_j])
        (CollideTable[type_i][type_j])(phys_obj_i, phys_obj_j);
    }
  }
}

