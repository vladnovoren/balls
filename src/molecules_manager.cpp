#include "molecules_manager.hpp"


MoleculesManager::~MoleculesManager() {
  for (size_t i = 0; i < n_molecules; ++i)
    delete molecules[i];
}


bool MoleculesManager::AddMolecule(Molecule* molecule) {
  assert(molecule);

  if (n_molecules == MAX_N_MOLECULES)
    return false;

  molecules[n_molecules] = molecule;
  phys_components[n_molecules] = molecule->phys_component;
  rend_components[n_molecules] = molecule->rend_component;
  ++n_molecules;
  return true;
}


PhysObject* MoleculesManager::GetPhysComponent(const size_t molecule_num) {
  return phys_components[molecule_num];
}


Renderable* MoleculesManager::GetRendComponent(const size_t molecule_num) {
  return rend_components[molecule_num];
}


size_t MoleculesManager::NumOfMolecules() {
  return n_molecules;
}


void MoleculesManager::Tick(Graphics* graphics) {
  assert(graphics);

  phys_engine.UpdateAll(); 
}


void MoleculesManager::RenderAll() {
  for (size_t i = 0; i < )
}
