#ifndef CHEM_MANAGER_HPP
#define CHEM_MANAGER_HPP


#include "collide_funcs.hpp"
#include "creatures_container.hpp"
#include "react_funcs.hpp"


class ChemManager {
  typedef bool (*ReactFunc)(PhysObject*, PhysObject*, CreaturesContainer*);
  ReactFunc ReactTable[N_PHYS_OBJECTS][N_PHYS_OBJECTS] = {};
public:
  ChemManager();

  void ReactAll(CreaturesContainer* creatures_container);
};


#endif /* chem_manager.hpp */
