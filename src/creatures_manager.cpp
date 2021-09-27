#include "creatures_manager.hpp"


bool CreaturesManager::AddCreature(Creature* creature) {
  assert(creature);

  if (n_creatures == MAX_N_CREATURES)
    return false;

  creatures[n_creatures] = creature;
  phys_components[n_creatures] = creature->phys_component;
  rend_components[n_creatures] = creature->rend_component;
  ++n_creatures;
  return true;
}


PhysObject* CreaturesManager::GetPhysComponent(const size_t creature_num) {
  return phys_components[creature_num];
}


Renderable* CreaturesManager::GetRendComponent(const size_t creature_num) {
  return rend_components[creature_num];
}


size_t CreatureManager::NumOfCreatures() {
  return n_creatures;
}
