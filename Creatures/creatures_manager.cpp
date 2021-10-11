#include "creatures_manager.hpp"


CreaturesManager::CreaturesManager(const CoordSys& coord_sys):
                  coord_sys(coord_sys) {
  Wall* left_wall = new Wall(LEFT_WALL_BEGIN, LEFT_WALL_END, WALL_COLOR, PhysWall::WallType::LEFT);
  Wall* right_wall = new Wall(RIGHT_WALL_BEGIN, RIGHT_WALL_END, WALL_COLOR, PhysWall::WallType::RIGHT);
  Wall* up_wall = new Wall(LEFT_WALL_END, RIGHT_WALL_END, WALL_COLOR, PhysWall::WallType::UPPER);
  Wall* down_wall = new Wall(LEFT_WALL_BEGIN, RIGHT_WALL_BEGIN, WALL_COLOR, PhysWall::WallType::LOWER);

  creatures_container.AddCreature(left_wall);
  creatures_container.AddCreature(right_wall);
  creatures_container.AddCreature(up_wall);
  creatures_container.AddCreature(down_wall);

  // for (size_t i = 0; i < 10; ++i) {
  //   for (size_t j = 0; j < 10; ++j) {
  //     Cube* cube = new Cube(1,
  //                           DEFAULT_VELOCITY,
  //                           Vector2f(0, 0),
  //                           LEFT_WALL_BEGIN + Vector2f(10 + i * DELTA_POSITION, 10 + j * DELTA_POSITION), 10, pow(-1, rand() % 2),
  //                           ColorRGB(i % 2, j % 2, (i + j + 1) % 2));
  //     creatures_container.AddCreature(cube);
  //   }
  // }
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


void CreaturesManager::Tick(const double dt) {
  phys_engine.Tick(dt, &creatures_container);
  SyncRendWithPhys();
}
