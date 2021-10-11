#ifndef COORD_SYS_HPP
#define COORD_SYS_HPP

#include "vector2.hpp"


struct Ranges {
  Vector2f max;
  Vector2f min;

  Ranges();

  Ranges(const Vector2f& max, const Vector2f& min);
};


struct CoordSys {
  Vector2f p_center;
  Ranges ranges;
  double ppu;

  CoordSys(const Vector2f& p_center, const double ppu);

  double RealToPixelLen(const double len) const;
  Vector2f RealToPixelVector(const Vector2f& vector) const;
  Vector2f RealToPixelPoint(const Vector2f& point) const;
};


#endif /* coord_sys.hpp */