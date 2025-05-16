// AABB.cpp
#include "AABB.hpp"

AABB::AABB(const Vec& topLeft, const Vec& bottomRight)
    : topLeft(topLeft), bottomRight(bottomRight) {}

bool AABB::intersects(const AABB& other) const {
    return !(other.topLeft.x > bottomRight.x ||
             other.bottomRight.x < topLeft.x ||
             other.topLeft.y > bottomRight.y ||
             other.bottomRight.y < topLeft.y);
}

bool AABB::contains(const Vec& point) const {
    return point.x >= topLeft.x && point.x <= bottomRight.x &&
           point.y >= topLeft.y && point.y <= bottomRight.y;
}
