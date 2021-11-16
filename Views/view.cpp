#include "view.hpp"


View::~View() {}


WindowView::WindowView(const Rect& rect, const ColorRGB& color):
            rect(rect), color(color) {
  molucules_view = new MoleculesView();
  children.push_back(molucules_view);
  children.push_back(new ButtonView(BUTTON_BALL_RECT, BUTTON_BALL_COLOR, ButtonView::Type::ADD_BALL, this));
  children.push_back(new ButtonView(BUTTON_CUBE_RECT, BUTTON_CUBE_COLOR, ButtonView::Type::ADD_CUBE, this));
}


WindowView::~WindowView() {}


void WindowView::Tick(const double dt) {
  for (size_t i = 0; i < children.size(); ++i) {
    children[i]->Tick(dt);
  }
}


bool WindowView::IsMouseHitted(const Vector2f& mouse_pos) {
  return rect.IsPointInRect(mouse_pos);
}


void WindowView::OnClick(const ButtonView::Type type) {
  switch (type) {
    case ButtonView::Type::ADD_BALL:
      molucules_view->AddBall();
      break;
    case ButtonView::Type::ADD_CUBE:
      molucules_view->AddCube();
      break;
  }
}


void WindowView::OnMouse(const Vector2f& mouse_pos) {
  for (size_t i = 0; i < children.size(); ++i) {
    if (children[i]->IsMouseHitted(mouse_pos))
      children[i]->OnMouse(mouse_pos);
  }
}


void WindowView::Render(Graphics* graphics) {
  graphics->Clear(color);
  for (size_t i = 0; i < children.size(); ++i)
    children[i]->Render(graphics);
}


MoleculesView::MoleculesView(): creatures_manager(COORD_SYS) {}


MoleculesView::~MoleculesView() {}


bool MoleculesView::IsMouseHitted(const Vector2f&) {
  return false;
}


void MoleculesView::OnMouse(const Vector2f&) {}


void MoleculesView::Render(Graphics* graphics) {
  creatures_manager.Render(graphics);
}


void MoleculesView::Tick(const double dt) {
  creatures_manager.Tick(dt);
}


void MoleculesView::AddBall() {
  Vector2f velocity = DEFAULT_VELOCITY;
  velocity.Rotate(rand());
  creatures_manager.creatures_container.AddCreature(new Ball(1, velocity,
                                                             Vector2f(0, 0),
                                                             SPAWN_POSITION,
                                                             10,
                                                             1,
                                                             ColorRGB(1, 0, 0))
  );
}


void MoleculesView::AddCube() {
  Vector2f velocity = DEFAULT_VELOCITY;
  velocity.Rotate(rand());
  creatures_manager.creatures_container.AddCreature(new Cube(1, velocity,
                                                             Vector2f(0, 0),
                                                             SPAWN_POSITION,
                                                             10,
                                                             1,
                                                             ColorRGB(0, 0, 1)));
}


ButtonView::ButtonView(const Rect& rect, const ColorRGB& color, const Type type,
                       ButtonViewDelegate* delegate):
            rect(rect), color(color), type(type),
            delegate(delegate) {}


ButtonView::~ButtonView() {}


void ButtonView::Tick(const double) {}


bool ButtonView::IsMouseHitted(const Vector2f& mouse_pos) {
  return rect.IsPointInRect(mouse_pos);
}


void ButtonView::OnMouse(const Vector2f&) {
  delegate->OnClick(type);
}


void ButtonView::Render(Graphics* graphics) {
  assert(graphics);

  graphics->RenderRect(rect, color);
}
