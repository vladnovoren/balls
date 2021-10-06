#ifndef CHEM_MANAGER_HPP
#define CHEM_MANAGER_HPP


#include "collide_funcs.hpp"
#include "creatures_container.hpp"
#include "react_funcs.hpp"


const double MIN_REACT_ENERGY = 500;


class ChemManager {
  typedef bool (*ReactFunc)(Creature*, Creature*, CreaturesContainer*);
  ReactFunc ReactTable[N_PHYS_OBJECTS][N_PHYS_OBJECTS] = {};
public:
  ChemManager();

  void ReactAll(CreaturesContainer* creatures_container);
};


#endif /* chem_manager.hpp */