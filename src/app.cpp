#include "app.hpp"


void Exec() {
  CreaturesManager creatures_manager;
  Ball ball(1, Vector2f(1, 1), 0, Vector2f(1, 1), 1, 0, ColorRGB(1, 1, 1));
  creatures_manager.AddCreature(new Ball(ball));
  
}
