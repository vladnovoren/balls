#include "creatures_container.hpp"


CreaturesContainer::CreaturesContainer(): n_creatures(0) {
}


CreaturesContainer::~CreaturesContainer() {
  for (size_t i = 0; i < n_creatures; ++i)
    delete creatures[i];
}


bool CreaturesContainer::AddCreature(Creature* creature) {
  assert(creature);

  if (n_creatures == MAX_N_CREATURES) {
    delete creature;
    return false;
  }

  creatures[n_creatures] = creature;
  phys_components[n_creatures] = creature->phys_component;
  rend_components[n_creatures] = creature->rend_component;
  ++n_creatures;
  return true;
}


PhysObject* CreaturesContainer::GetPhysComponent(const size_t creature_num) {
  return phys_components[creature_num];
}


Renderable* CreaturesContainer::GetRendComponent(const size_t creature_num) {
  return rend_components[creature_num];
}


Creature* CreaturesContainer::GetCreature(const size_t creature_num) {
  return creatures[creature_num];
}


size_t CreaturesContainer::NumOfCreatures() {
  return n_creatures;
}


void CreaturesContainer::Split() {
  size_t new_i = 0;
  size_t saved_n_creatures = n_creatures;
  for (size_t i = 0; i < saved_n_creatures; ++i) {
    if (creatures[i]->activity_level == Creature::ActivityLevel::TO_DELETE) {
      delete creatures[i];
      --n_creatures;
    } else {
      creatures[i]->activity_level = Creature::ActivityLevel::ACTIVE;
      if (new_i < i) {
        creatures[new_i] = creatures[i];
        phys_components[new_i] = phys_components[i];
        rend_components[new_i] = rend_components[i];
      }
      ++new_i;
    }
  }
}
