#include "chem_manager.hpp"


ChemManager::ChemManager() {
  ReactTable[(int)PhysObject::PhysType::PHYS_BALL][(int)PhysObject::PhysType::PHYS_BALL] = &ReactBallBall;
  ReactTable[(int)PhysObject::PhysType::PHYS_BALL][(int)PhysObject::PhysType::PHYS_CUBE] = &ReactBallCube;
  ReactTable[(int)PhysObject::PhysType::PHYS_CUBE][(int)PhysObject::PhysType::PHYS_CUBE] = &ReactCubeCube;
}


void ChemManager::ReactAll(CreaturesContainer* creatures_container) {
  assert(creatures_container);

  size_t n_creatures = creatures_container->NumOfCreatures();
  for (size_t i = 0; i < n_creatures; ++i) {
    for (size_t j = i + 1; j < n_creatures; ++j) {
      Creature* creature_i = creatures_container->GetCreature(i);
      Creature* creature_j = creatures_container->GetCreature(j);

      if (!ReadyToReact(creature_i) || !ReadyToReact(creature_j))
        continue;

      PhysObject* phys_creature_i = creature_i->GetPhysComponent();
      PhysObject* phys_creature_j = creature_j->GetPhysComponent();

      if (!DidReact(phys_creature_i, phys_creature_j))
        continue;

      int type_i = static_cast<int>(creature_i->GetPhysComponent()->GetType());
      int type_j = static_cast<int>(creature_j->GetPhysComponent()->GetType());

      if (type_i > type_j) {
        std::swap(type_i, type_j);
        std::swap(creature_i, creature_j);
        std::swap(phys_creature_i, phys_creature_j);
      }

      if (ReactTable[type_i][type_j])
        (*ReactTable[type_i][type_j])(phys_creature_i, phys_creature_j, creatures_container);
    }
  }
}
