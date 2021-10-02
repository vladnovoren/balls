#include "app.hpp"


App::App() {
  Ball* ball1 = new Ball(1, Vector2f(1, 1), Vector2f(0, 0), Vector2f(1, 1), 1, 0, ColorRGB(1, 1, 1));

  creatures_manager.creatures_container.AddCreature(ball1);
}


void App::Exec() {
  while (true) {
    graphics.Clear();
    creatures_manager.Tick();
    creatures_manager.RenderAll();
    graphics.Display();
  }
}

