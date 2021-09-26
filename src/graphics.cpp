#include "graphics.hpp"

Graphics::Graphics(const Vector2f& size, const char* title, const double ppu) {
  window.create(sf::VideoMode(size.x, size.y), title);
  window.setVerticalSyncEnabled(true);
  this->ppu = ppu;
}

Graphics::~Graphics() {
  window.close();
}

bool Graphics::ShouldClose() {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      return true;
  }
  return false;
}

void Graphics::Clear(const ColorRGB& color) {
  window.clear(ToSFMLColor(color));
}

void Graphics::Display() {
  window.display();
}

void Graphics::SetColor(const ColorRGB& color) {
  this->color = ToSFMLColor(color);
}

void Graphics::RenderLine(const Vector2f& start, const Vector2f& end) {
  sf::Vertex line[] = {
    sf::Vertex(ToSFMLVector(start), color),
    sf::Vertex(ToSFMLVector(end), color)
  };

  window.draw(line, 2, sf::Lines);
}

void Graphics::RenderSquare(const Vector2f& position, const double side_len) {
  sf::RectangleShape square(sf::Vector2f(side_len, side_len));
  square.setPosition(position.x, position.y);
  window.draw(square);
}

void Graphics::RenderCircle(const Vector2f& center, const double radius) {
  sf::CircleShape circle;
  circle.setOrigin(sf::Vector2f(radius, radius));
  circle.setRadius(radius);
  circle.setPosition(center.GetX(), center.GetY());
  circle.setFillColor(color);
  sf::Vector2f pos = circle.getPosition();
  window.draw(circle);
}

sf::Vector2f Graphics::ToSFMLVector(const Vector2f& vector) {
  return sf::Vector2f(vector.x, vector.y);
}

sf::Color Graphics::ToSFMLColor(const ColorRGB& color) {
  return sf::Color(color.r * 255, color.g * 255, color.b * 255, 255);
}

Vector2f Graphics::RealToPixelVector(const Vector2f& vector) {
  return Vector2f(
    vector.x * ppu,
    -vector.y * ppu
  );
}

Vector2f Graphics::RealToPixelPoint(const Vector2f& vector) {
  return Vector2f(
    vector.x * ppu,
    -vector.y * ppu + window.getSize().y
  );
}

double Graphics::RealToPixelLen(const double len) {
  return len * ppu;
}
