#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "SFML/Graphics.hpp"
#include "color.hpp"
#include "vector2.hpp"
#include <cassert>



struct Rect {
  Vector2f position;
  Vector2f size;

  Rect();
  Rect(const Vector2f& position, const Vector2f& size);

  bool IsPointInRect(const Vector2f& point);
};


struct Circle {
  Vector2f center;
  double radius;

  Circle();
  Circle(const Vector2f& center, const double radius);
};

struct Line {
  Vector2f begin;
  Vector2f end;

  Line();
  Line(const Vector2f& begin, const Vector2f& end);
};


class Graphics {
  sf::RenderWindow window;
  sf::Color color;
  sf::Clock clock;
  sf::Mouse mouse;
public:
  Graphics(const Vector2f& size, const char* title);
  ~Graphics();

  bool ShouldClose();
  void Clear(const ColorRGB& color);
  void Display();

  void SetColor(const ColorRGB& color);

  void RenderLine(const Line& line, const ColorRGB& color);
  void RenderRect(const Rect& rect, const ColorRGB& color);
  void RenderCircle(const Circle& circle, const ColorRGB& color);

  bool IsLeftMouseButtonPressed();
  Vector2f GetMousePosition();

  double ResetTime();

  sf::Vector2f ToSFMLVector(const Vector2f& vector);
  sf::Color ToSFMLColor(const ColorRGB& color);

  Vector2f ToMyVector(const sf::Vector2f& vector);
};

#endif /* graphics.hpp */
