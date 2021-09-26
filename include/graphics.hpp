#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "SFML/Graphics.hpp"
#include "color.hpp"
#include "vector2.hpp"
#include <cassert>

static const double CIRCLE_N_POINTS = 27;

class Graphics {
  double ppu;
  sf::RenderWindow window;
  sf::Color color;
public:
  Graphics(const Vector2f& size, const char* title, const double ppu);
  ~Graphics();

  Vector2f RealToPixelVector(const Vector2f& vector);
  Vector2f RealToPixelPoint(const Vector2f& point);
  double RealToPixelLen(const double len);

  bool ShouldClose();
  void Clear(const ColorRGB& color);
  void Display();

  void SetColor(const ColorRGB& color);

  void RenderLine(const Vector2f& start, const Vector2f& end);
  void RenderSquare(const Vector2f& position, const double side_len);
  void RenderCircle(const Vector2f& center, const double radius);

  sf::Vector2f ToSFMLVector(const Vector2f& vector);
  sf::Color ToSFMLColor(const ColorRGB& color);
};

#endif /* graphics.hpp */
