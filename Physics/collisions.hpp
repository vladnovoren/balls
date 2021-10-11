#ifndef COLLISIONS_HPP
#define COLLISIONS_HPP

#include "creatures_container.hpp"
#include "collide_funcs.hpp"


class CollisionManager {
public:
  CollisionManager();

  void CollideAll(CreaturesContainer* creatures_container);
protected:
  typedef bool (*CollideFunc)(PhysObject*, PhysObject*);
  CollideFunc CollideTable[N_PHYS_OBJECTS][N_PHYS_OBJECTS] = {};
};


#endif /* collisions.hpp */
