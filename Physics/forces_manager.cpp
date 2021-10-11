#include "forces_manager.hpp"


ForcesManager::ForcesManager() {
  ResponseTable[(int)PhysObject::PhysType::PHYS_BALL][(int)PhysObject::PhysType::PHYS_BALL] = &ForcesManager::CoulombsLawBallBall;
  ResponseTable[(int)PhysObject::PhysType::PHYS_BALL][(int)PhysObject::PhysType::PHYS_CUBE] = &ForcesManager::CoulombsLawBallBall;
  ResponseTable[(int)PhysObject::PhysType::PHYS_CUBE][(int)PhysObject::PhysType::PHYS_CUBE] = &ForcesManager::CoulombsLawBallBall;
}


void ForcesManager::CoulombsLawBallBall(PhysObject* raw_ball1, PhysObject* raw_ball2) {
  assert(raw_ball1);
  assert(raw_ball2);

  PhysBall* ball1 = reinterpret_cast<PhysBall*>(raw_ball1);
  PhysBall* ball2 = reinterpret_cast<PhysBall*>(raw_ball2);

  Vector2f r12 = ball1->center - ball2->center;
  double distance = r12.Length();
  if (IsZero(distance))
    return;
  Vector2f coulumbs_force12 = -COULOMBS_LAW_K * ball1->charge * ball2->charge / pow(distance, 3) * r12;
  ball1->AddForce(coulumbs_force12);
  ball2->AddForce(-coulumbs_force12);
}


void ForcesManager::ResponseAll(CreaturesContainer* creatures_container) {
  assert(creatures_container);

  ResetAccelerations(creatures_container);

  for (size_t i = 0; i < creatures_container->NumOfCreatures(); ++i) {
    for (size_t j = i + 1; j < creatures_container->NumOfCreatures(); ++j) {
      PhysObject* obj1 = creatures_container->GetPhysComponent(i);
      PhysObject* obj2 = creatures_container->GetPhysComponent(j);

      int id1 = static_cast<int>(obj1->GetType());
      int id2 = static_cast<int>(obj2->GetType());

      if (id1 > id2) {
        std::swap(obj1, obj2);
        std::swap(id1, id2);
      }

      if (ResponseTable[id1][id2])
        (this->*ResponseTable[id1][id2])(obj1, obj2);
    }
  }
}


void ForcesManager::ResetAccelerations(CreaturesContainer* creatures_container) {
  assert(creatures_container);

  for (size_t i = 0; i < creatures_container->NumOfCreatures(); ++i) {
    PhysObject* phys_obj = creatures_container->GetPhysComponent(i);
    phys_obj->acceleration = Vector2f(0, 0);
  }
}
