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
      Creature* creature1 = creatures_container->GetCreature(i);
      Creature* creature2 = creatures_container->GetCreature(j);

      Creature::ActivityLevel act_level1 = creature1->activity_level;
      Creature::ActivityLevel act_level2 = creature2->activity_level;
      if (act_level1 == Creature::ActivityLevel::NOT_ACTIVE ||
          act_level2 == Creature::ActivityLevel::NOT_ACTIVE)
        continue;

      PhysObject* phys_creature1 = creature1->GetPhysComponent();
      PhysObject* phys_creature2 = creature2->GetPhysComponent();

      if (phys_creature1->GetKineticEnergy() + phys_creature2->GetKineticEnergy() < MIN_REACT_ENERGY)
        continue;

      int type1 = static_cast<int>(creature1->GetPhysComponent()->GetType());
      int type2 = static_cast<int>(creature2->GetPhysComponent()->GetType());

      if (type1 > type2) {
        std::swap(type1, type2);
        std::swap(creature1, creature2);
      }

      if (ReactTable[type1][type2])
        (*ReactTable[type1][type2])(creature1, creature2, creatures_container);
    }
  }
  creatures_container->Split();
}
