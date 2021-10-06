#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <cmath>
#include <cassert>
#include "tools.hpp"
#include "SFML/Graphics.hpp"

template<typename VectorType>
class Vector2 {
public:
  friend class Graphics;
  VectorType x = 0;
  VectorType y = 0;
  Vector2() {}

  Vector2(VectorType x, VectorType y) {
    this->x = x;
    this->y = y;
  }

  double Length() const {
    return sqrt(x * x + y * y);
  }

  Vector2<VectorType> GetProjection(const Vector2<VectorType>& direction) {
    Vector2<VectorType> dir_normalized = direction;
    dir_normalized.Normalize();
    return dir_normalized * (*this * dir_normalized);
  }

  void Normalize() {
    double length = Length();
    if (length) {
      x /= length;
      y /= length;
    }
  }

  void Resize(double new_length) {
    Normalize();
    (*this) *= new_length;
  }

  void Reflect(const Vector2& normal) {
    (*this) = 2 * (normal * *this) * normal - (*this);
  }

  double Angle() const {
    return atan2(y, x);
  }

  void Rotate(const double d_phi) {
    double length = Length();
    double angle = Angle() + d_phi;
    x = cos(angle) * length;
    y = sin(angle) * length;
  }

  Vector2& operator += (const Vector2& right) {
    x += right.x;
    y += right.y;
    return *this;
  }

  Vector2& operator -= (const Vector2& right) {
    x -= right.x;
    y -= right.y;
    return *this;
  }

  Vector2& operator *= (const double scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
  }

  Vector2 operator - () const {
    return Vector2(-x, -y);
  }

  bool operator == (const Vector2& right) const {
    return x == right.x && y == right.y;
  }

  Vector2 operator + (const Vector2& right) const {
    return Vector2(
      x + right.x,
      y + right.y
    );
  }

  Vector2 operator - (const Vector2& right) const {
    return Vector2(
      x - right.x,
      y - right.y
    );
  }

  Vector2 operator * (const double scalar) const {
    return Vector2(
      x * scalar,
      y * scalar
    );
  }

  double operator * (const Vector2& right) const {
    return x * right.x +
           y * right.y;
  }

  void Print() const {
    printf("x: %lf, y: %lf\n", x, y);
  }
};

template<typename T>
Vector2<T> operator * (const double scalar, const Vector2<T>& vector) {
  Vector2<T> res = vector;
  res *= scalar;
  return res;
}

template<typename VectorType>
double Vector2Cos(const Vector2<VectorType>& first, const Vector2<VectorType>& second) {
  VectorType numerator = first * second;
  if (!numerator)
    return 0;
  return numerator / (first.Length() * second.Length());
}

template<typename VectorType>
double Vector2Sin(const Vector2<VectorType>& first, const Vector2<VectorType>& second) {
  VectorType cos = Vector2Cos(first, second);
  return sqrt(1 - cos * cos);
}

typedef Vector2<double> Vector2d;
typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;

#endif /* vector2.hpp */
