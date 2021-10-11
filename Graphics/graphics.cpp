#include "graphics.hpp"


Rect::Rect() {}


Rect::Rect(const Vector2f& position, const Vector2f& size):
      position(position), size(size) {}


bool Rect::IsPointInRect(const Vector2f& point) {
  return position.x < point.x && point.x < position.x + size.x &&
         position.y < point.y && point.y < position.y + size.y;
}


Circle::Circle() {}


Circle::Circle(const Vector2f& center, const double radius):
        center(center), radius(radius) {}


Line::Line() {}


Line::Line(const Vector2f& begin, const Vector2f& end):
      begin(begin), end(end) {}


Graphics::Graphics(const Vector2f& size, const char* title) {
  window.create(sf::VideoMode(size.x, size.y), title);
  window.setVerticalSyncEnabled(true);
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


void Graphics::RenderLine(const Line& line, const ColorRGB& color) {
  sf::Vertex sf_line[] = {
    sf::Vertex(ToSFMLVector(line.begin), ToSFMLColor(color)),
    sf::Vertex(ToSFMLVector(line.end), ToSFMLColor(color))
  };
  window.draw(sf_line, 2, sf::Lines);
}


void Graphics::RenderRect(const Rect& rect, const ColorRGB& color) {
  sf::RectangleShape sf_rect(ToSFMLVector(rect.size));
  sf_rect.setPosition(ToSFMLVector(rect.position));
  sf_rect.setFillColor(ToSFMLColor(color));
  window.draw(sf_rect);
}


void Graphics::RenderCircle(const Circle& circle, const ColorRGB& color) {
  sf::CircleShape sf_circle;
  sf_circle.setOrigin(sf::Vector2f(circle.radius, circle.radius));
  sf_circle.setRadius(circle.radius);
  sf_circle.setPosition(circle.center.x, circle.center.y);
  sf_circle.setFillColor(ToSFMLColor(color));
  window.draw(sf_circle);
}


double Graphics::ResetTime() {
  return clock.restart().asSeconds();
}


sf::Vector2f Graphics::ToSFMLVector(const Vector2f& vector) {
  return sf::Vector2f(vector.x, vector.y);
}


sf::Color Graphics::ToSFMLColor(const ColorRGB& color) {
  return sf::Color(color.r * 255, color.g * 255, color.b * 255, 255);
}


bool Graphics::IsLeftMouseButtonPressed() {
  return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}


Vector2f Graphics::GetMousePosition() {
  return ToMyVector(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
}


Vector2f Graphics::ToMyVector(const sf::Vector2f& vector) {
  return Vector2f(vector.x, vector.y);
}
