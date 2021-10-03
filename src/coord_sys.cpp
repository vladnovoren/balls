#include "coord_sys.hpp"


Ranges::Ranges() {};


Ranges::Ranges(const Vector2f& max, const Vector2f& min):
        max(max), min(min) {
}


CoordSys::CoordSys(const Vector2f& p_center, const Ranges& ranges,
                   const double ppu):
          p_center(p_center), ranges(ranges), ppu(ppu) {
  p_ranges = Ranges();
}


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