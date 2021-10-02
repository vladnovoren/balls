#ifndef MOLECULES_MANAGER_HPP
#define MOLECULES_MANAGER_HPP

#include "molecules.hpp"


const size_t MAX_N_MOLECULES = 100;


class MoleculesManager {
  PhysEngine phys_engine;
  CoordSys coord_sys;

  Molecule* molecules[MAX_N_MOLECULES];
  PhysObject* phys_components[MAX_N_MOLECULES];
  Renderable* rend_components[MAX_N_MOLECULES];
  size_t n_molecules;
public:
  ~MoleculesManager();

  bool AddMolecule(Molecule* molecule);

  PhysObject* GetPhysComponent(const size_t molecule_num);

  Renderable* GetRendComponent(const size_t molecule_num);

  size_t NumOfMolecules();

  void Tick(Graphics* graphics);

  void RenderAll();
};


#endif /* molecules_manager.hpp */

