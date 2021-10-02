#ifndef CREATURES_CONTAINER_HPP
#define CREATURES_CONTAINER_HPP

#include "creatures.hpp"

const size_t MAX_N_CREATURES = 100;


class CreaturesContainer {
  Creature* creatures[MAX_N_CREATURES];
  PhysObject* phys_components[MAX_N_CREATURES];
  Renderable* rend_components[MAX_N_CREATURES];
  size_t n_creatures;
public:
  ~CreaturesContainer();

  bool AddCreature(Creature* creature);

  PhysObject* GetPhysComponent(const size_t creature_num);

  Renderable* GetRendComponent(const size_t creature_num);

  size_t NumOfCreatures();
};


#endif /* creatures_container.hpp */
