// CircleEntity.cpp
#include "CircleEntity.hpp"

CircleEntity::CircleEntity(Vec position, Vec velocity, Vec acceleration, float mass, float radius)
    : Entity(position, velocity, acceleration, mass), radius(radius) {}

// EFFECTS: returns the radius of this circle
int CircleEntity::getRadius() {
    return radius;
}
