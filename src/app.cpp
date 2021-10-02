#include "app.hpp"


void Exec() {
  CreaturesManager creatures_container;
  Ball ball(1, Vector2f(1, 1), 0, Vector2f(1, 1), 1, 0, ColorRGB(1, 1, 1));
  creatures_container.AddCreature(new Ball(ball));
  
}
