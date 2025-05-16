#include "Vec.hpp"

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

float Vec::norm() const {
    return sqrt(pow(x,2) + pow(y,2));
}

Vec Vec::getUnit() const {
    float norm = this->norm();
    return Vec(x/norm, y/norm);
}