#include "creatures_manager.hpp"


CreaturesManager::CreaturesManager() {}


void CreaturesManager::RenderAll(Graphics* graphics) {
  assert(graphics);

  for (size_t i = 0; i < creatures_container.NumOfCreatures(); ++i) {
    creatures_container.GetRendComponent(i)->Render(graphics, coord_sys);
  }
}


void CreaturesManager::Tick(const double dt, Graphics* graphics) {
  assert(graphics);

  phys_engine.Tick(dt, &creatures_container);
  RenderAll(graphics);
}