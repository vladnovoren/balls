#include "tools.hpp"


double Max(const double a, const double b) {
  return a > b ? a : b;
}

double Min(const double a, const double b) {
  return a < b ? a : b;
}

double Sign(const double x) {
  if (!x)
    return x;
  if (x > 0)
    return 1;
  else
    return -1;
}

bool IsZero(const double a) {
  return fabs(a) < EPSILON;
}
