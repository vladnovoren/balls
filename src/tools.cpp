#include "tools.hpp"


double Max(const double a, const double b) {
  return a > b ? a : b;
}

double Min(const double a, const double b) {
  return a < b ? a : b;
}

bool IsZero(const double a) {
  return fabs(a) < EPSILON;
}
