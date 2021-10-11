#include "app.hpp"


App::App():
     graphics(WINDOW_SIZE, "Molecules"),
     root_view(Rect(Vector2f(0, 0), WINDOW_SIZE), CLEAR_COLOR) {
}


void App::Exec() {
  while (!graphics.ShouldClose()) {
    if (graphics.IsLeftMouseButtonPressed()) {
      root_view.OnMouse(graphics.GetMousePosition());
    }
    double time_diff = graphics.ResetTime();
    root_view.Tick(time_diff);
    root_view.Render(&graphics);
    graphics.Display();
  }
}
