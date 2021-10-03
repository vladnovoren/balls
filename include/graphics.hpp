#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "SFML/Graphics.hpp"
#include "color.hpp"
#include "vector2.hpp"
#include <cassert>

static const double CIRCLE_N_POINTS = 27;

class Graphics {
  sf::RenderWindow window;
  sf::Color color;
  sf::Clock clock;
public:
  Graphics(const Vector2f& size, const char* title);
  ~Graphics();

  bool ShouldClose();
  void Clear(const ColorRGB& color);
  void Display();

  void SetColor(const ColorRGB& color);

  void RenderLine(const Vector2f& start, const Vector2f& end,
                  const ColorRGB& color);
  void RenderSquare(const Vector2f& position, const double side_len,
                    const ColorRGB& color);
  void RenderCircle(const Vector2f& center, const double radius,
                    const ColorRGB& color);

  double ResetTime();

  sf::Vector2f ToSFMLVector(const Vector2f& vector);
  sf::Color ToSFMLColor(const ColorRGB& color);
};

#endif /* graphics.hpp */
