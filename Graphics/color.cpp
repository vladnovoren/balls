#include "color.hpp"

ColorRGB::ColorRGB() {
}

ColorRGB::ColorRGB(double r, double g, double b) {
  this->r = r;
  this->g = g;
  this->b = b;
}

ColorRGB& ColorRGB::operator *= (const double mul) {
  r *= mul;
  g *= mul;
  b *= mul;
  return *this;
}

ColorRGB& ColorRGB::operator *= (const ColorRGB& right) {
  r *= right.r;
  g *= right.g;
  b *= right.b;
  return *this;
}

ColorRGB& ColorRGB::operator += (const ColorRGB& right) {
  r += right.r;
  g += right.g;
  b += right.b;
  return *this;
}

ColorRGB ColorRGB::operator + (const ColorRGB& right) const {
  return ColorRGB(
    r + right.r,
    g + right.g,
    b + right.b
  );
}

ColorRGB ColorRGB::operator * (const ColorRGB& right) const {
  return ColorRGB(
    r * right.r,
    g * right.g,
    b * right.b
  );
}

ColorRGB ColorRGB::operator * (const double scalar) const {
  return ColorRGB(
    r * scalar,
    g * scalar,
    b * scalar
  );
}

ColorRGB operator * (const double scalar, const ColorRGB& color) {
  return ColorRGB(
    scalar * color.r,
    scalar * color.g,
    scalar * color.b
  );
}


void Swap(double& first, double& second) {
  double temp = first;
  first = second;
  second = temp;
}

