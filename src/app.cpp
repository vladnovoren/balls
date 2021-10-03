#include "app.hpp"


App::App():
     graphics(WINDOW_SIZE, "Molecules"),
     creatures_manager(COORD_SYS) {
  Wall* left_wall = new Wall(Vector2f(5, 5), Vector2f(5, WINDOW_HEIGHT - 5), ColorRGB(1, 0, 0), PhysWall::WallType::LEFT);
  Wall* right_wall = new Wall(Vector2f(WINDOW_WIDTH - 5, 5), Vector2f(WINDOW_WIDTH - 5, WINDOW_HEIGHT - 5), ColorRGB(1, 0, 0), PhysWall::WallType::RIGHT);
  Wall* up_wall = new Wall(Vector2f(5, WINDOW_HEIGHT - 5), Vector2f(WINDOW_WIDTH - 5, WINDOW_HEIGHT - 5), ColorRGB(1, 0, 0), PhysWall::WallType::UPPER);
  Wall* down_wall = new Wall(Vector2f(5, 5), Vector2f(WINDOW_WIDTH - 5, 5), ColorRGB(1, 0, 0), PhysWall::WallType::LOWER); 

  creatures_manager.creatures_container.AddCreature(left_wall);
  creatures_manager.creatures_container.AddCreature(right_wall);
  creatures_manager.creatures_container.AddCreature(up_wall);
  creatures_manager.creatures_container.AddCreature(down_wall);

  double delta = 25;

  for (size_t i = 0; i < 20; ++i) {
    for (size_t j = 0; j < 20; ++j) {
      if (i % 2) {
        Ball* ball = new Ball(1,
                              Vector2f(50, 50),
                              Vector2f(0, 0),
                              Vector2f(15 + i * delta, 15 + j * delta), 5,  1,
                              ColorRGB(i % 2, j % 2, (i + j + 1) % 2));
        creatures_manager.creatures_container.AddCreature(ball);
      } else {
        Cube* cube = new Cube(1,
                              Vector2f(50, 50),
                              Vector2f(0, 0),
                              Vector2f(15 + i * delta, 15 + j * delta), 10, 1,
                              ColorRGB(i % 2, j % 2, (i + j + 1) % 2));
        creatures_manager.creatures_container.AddCreature(cube);
      }
    }
  }

  Ball* ball = new Ball(3,
                        Vector2f(-50, 50),
                        Vector2f(0, 0),
                        Vector2f(WINDOW_WIDTH - 15, 15), 5,  0,
                        ColorRGB(1, 0, 0));
  creatures_manager.creatures_container.AddCreature(ball);
}


void App::Exec() {
  while (!graphics.ShouldClose()) {
    double time_diff = graphics.ResetTime();
    graphics.Clear(ColorRGB(0, 0, 0));
    creatures_manager.Tick(time_diff, &graphics);
    creatures_manager.SyncRendWithPhys();
    creatures_manager.Render(&graphics);
    graphics.Display();
  }
}
