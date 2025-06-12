// Vec.cpp
#include "Vec.hpp"

// MODIFIES: this
// EFFECTS: initializes vector to (0,0)
Vec::Vec() : x(0.0f), y(0.0f) {}

// MODIFIES: this
// EFFECTS: initializes vector to (x,y)
Vec::Vec(float x, float y) : x(x), y(y) {}

// EFFECTS: returns componentwise sum
Vec Vec::operator+(const Vec& other) const {
    return Vec(x + other.x, y + other.y);
}

// EFFECTS: returns componentwise difference
Vec Vec::operator-(const Vec& other) const {
    return Vec(x - other.x, y - other.y);
}

// EFFECTS: returns vector scaled by scalar
Vec Vec::operator*(float scalar) const {
    return Vec(x * scalar, y * scalar);
}

// REQUIRES: scalar != 0
// EFFECTS: returns vector divided by scalar
Vec Vec::operator/(float scalar) const {
    return Vec(x / scalar, y / scalar);
}

// EFFECTS: returns Euclidean norm
float Vec::norm() const {
    return sqrt(pow(x, 2) + pow(y, 2));
}

// REQUIRES: norm() != 0
// EFFECTS: returns unit vector in same direction
Vec Vec::getUnit() const {
    float n = this->norm();
    return Vec(x / n, y / n);
}

// EFFECTS: returns dot product
float Vec::dot(const Vec& vec) const {
    return x * vec.x + y * vec.y;
}

// REQUIRES: *this not zero vector
// EFFECTS: returns projection of vec onto *this
Vec Vec::proj(const Vec& vec) const {
    float coefficient = dot(vec) / dot(*this);
    return (*this) * coefficient;
}
