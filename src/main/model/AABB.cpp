// AABB.cpp
#include "AABB.hpp"

AABB::AABB(const Vec& topLeft, const Vec& bottomRight)
    : topLeft(topLeft), bottomRight(bottomRight) {}

// REQUIRES: other is a valid AABB
// EFFECTS: returns true if this AABB intersects with other
bool AABB::intersects(const AABB& other) const {
    return !(other.topLeft.x > bottomRight.x ||
             other.bottomRight.x < topLeft.x ||
             other.topLeft.y > bottomRight.y ||
             other.bottomRight.y < topLeft.y);
}

// REQUIRES: point is a valid Vec
// EFFECTS: returns true if point is inside this AABB (inclusive)
bool AABB::contains(const Vec& point) const {
    return point.x >= topLeft.x && point.x <= bottomRight.x &&
           point.y >= topLeft.y && point.y <= bottomRight.y;
}
