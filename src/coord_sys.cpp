#include "coord_sys.hpp"


double CoordSys::RealToPixelLen(const double len) const {
  return len * ppu;
}


Vector2f CoordSys::RealToPixelVector(const Vector2f& vector) const {
  return Vector2f(
    ppu * vector.x,
    -ppu * vector.y
  );
}


Vector2f CoordSys::RealToPixelPoint(const Vector2f& point) const {
  return p_center + RealToPixelVector(point);
}