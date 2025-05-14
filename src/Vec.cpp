#include "Vec.hpp";

Vec::Vec() : x(0.0f), y(0.0f) {}

Vec::Vec(float x, float y) : x(x), y(y) {}

Vec Vec::operator+(const Vec& other) const {
    return Vec(x + other.x, y + other.y);
}

Vec Vec::operator-(const Vec& other) const {
    return Vec(x - other.x, y - other.y);
}

Vec Vec::operator*(float scalar) const {
    return Vec(x*scalar, y*scalar);
}

Vec Vec::operator/(float scalar) const {
    return Vec(x/scalar, y/scalar);
}