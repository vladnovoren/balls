#ifndef VIEW_HPP
#define VIEW_HPP

#include <vector>
#include "graphics.hpp"
#include "creatures_manager.hpp"
#include "view_config.hpp"


// внести размеры в view
class View {
protected:
  std::vector<View*> children;
public:
  virtual void Render(Graphics* graphics) = 0;

  virtual void Tick(const double dt) = 0;

  virtual bool IsMouseHitted(const Vector2f& mouse_pos) = 0;

  virtual void OnMouse(const Vector2f& mouse_pos) = 0;

  virtual ~View() = 0;
};

class ButtonViewDelegate;


// базовый касс для всех кнопок -> наследовать кнопки разных действий
class ButtonView: public View {
public:
  enum class State {
    PRESSED,
    RELEASED
  };

  enum class Type {
    ADD_BALL,
    ADD_CUBE
  };
protected:
  Rect rect;
  ColorRGB color;
  Type type;
  ButtonViewDelegate* delegate;
public:
  ButtonView(const Rect& rect, const ColorRGB& color, const Type type,
             ButtonViewDelegate* delegate);

  ~ButtonView();

  void Tick(const double dt) override;

  bool IsMouseHitted(const Vector2f& mouse_pos) override;

  void OnMouse(const Vector2f& mouse_pos) override;

  void Render(Graphics* graphics) override;
};


class ButtonViewDelegate {
public:
  virtual void OnClick(const ButtonView::Type type) = 0;
};


class MoleculesView: public View {
protected:
  CreaturesManager creatures_manager;
public:
  MoleculesView();

  ~MoleculesView();

  void Tick(const double dt) override;

  bool IsMouseHitted(const Vector2f& mouse_pos) override;

  void OnMouse(const Vector2f& mouse_pos) override;

  void Render(Graphics* graphics) override;

  void AddBall();

  void AddCube();
};


class WindowView: public View, public ButtonViewDelegate {
protected:
  Rect rect;
  ColorRGB color;
  MoleculesView* molucules_view;
public:
  WindowView(const Rect& rect, const ColorRGB& color);

  ~WindowView();

  void Tick(const double dt) override;

  bool IsMouseHitted(const Vector2f& mouse_pos) override;

  void OnClick(const ButtonView::Type type);

  void OnMouse(const Vector2f& mouse_pos) override;

  void Render(Graphics* graphics) override;
};


#endif /* view.hpp */
