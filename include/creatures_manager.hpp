#ifndef CREATURES_MANAGER_HPP
#define CREATURES_MANAGER_HPP

#include "phys_engine.hpp"


class CreaturesManager {
  PhysEngine phys_engine;
  CoordSys coord_sys;
public:
  CreaturesContainer creatures_container;

  CreaturesManager();

  void RenderAll(Graphics* graphics);

  void Tick(const double dt, Graphics* graphics);
};


#endif /* creatures_manger.hpp */
