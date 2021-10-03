#include "creatures_manager.hpp"


CreaturesManager::CreaturesManager(const CoordSys& coord_sys):
                  coord_sys(coord_sys) {
}


void CreaturesManager::SyncRendWithPhys() {
  for (size_t i = 0; i < creatures_container.NumOfCreatures(); ++i) {
    creatures_container.GetCreature(i)->SyncRendWithPhys();
  }
}


void CreaturesManager::Render(Graphics* graphics) {
  assert(graphics);

  for (size_t i = 0; i < creatures_container.NumOfCreatures(); ++i) {
    creatures_container.GetRendComponent(i)->Render(graphics, coord_sys);
  }
}


void CreaturesManager::Tick(const double dt, Graphics* graphics) {
  assert(graphics);

  phys_engine.Tick(dt, &creatures_container);
  Render(graphics);
}
