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
      PhysObject* phys_obj1 = creatures_container->GetPhysComponent(i);
      PhysObject* phys_obj2 = creatures_container->GetPhysComponent(j);

      int type1 = static_cast<int>(phys_obj1->GetType());
      int type2 = static_cast<int>(phys_obj2->GetType());

      if (type1 > type2) {
        std::swap(phys_obj1, phys_obj2);
        std::swap(type1, type2);
      }

      if (CollideTable[type1][type2])
        (CollideTable[type1][type2])(phys_obj1, phys_obj2);
    }
  }
}

