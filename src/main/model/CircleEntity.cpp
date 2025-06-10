// Ball.cpp
#include "CircleEntity.hpp"

CircleEntity::CircleEntity(Vec position, Vec velocity, Vec acceleration, float mass, float radius)
    : Entity(position, velocity, acceleration, mass), radius(radius) {}

int CircleEntity::getRadius() {
    return radius;
}