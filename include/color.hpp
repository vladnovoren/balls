#ifndef COLOR_HPP
#define COLOR_HPP

#include "SFML/Graphics.hpp"
#include "tools.hpp"

struct ColorRGB {
  double r = 0;
  double g = 0;
  double b = 0;

  ColorRGB();
  ColorRGB(double r, double g, double b);

  ColorRGB& operator *= (const double mul);
  ColorRGB& operator *= (const ColorRGB& right);
  ColorRGB& operator += (const ColorRGB& right);
  ColorRGB operator + (const ColorRGB& right) const;
  ColorRGB operator * (const ColorRGB& right) const;
  ColorRGB operator * (const double scalar) const;
  friend ColorRGB operator * (const double scalar, const ColorRGB& color);
};

void Swap(double& first, double& second);

#endif /* color.hpp */
