// Entity.cpp
#include "Entity.hpp"

Entity::Entity(Vec position, Vec velocity, Vec acceleration, float mass)
    : position(position), velocity(velocity), acceleration(acceleration), mass(mass) {}

Vec& Entity::getPosition() {
    return position;
}

Vec& Entity::getVelocity() {
    return velocity;
}

Vec& Entity::getAcceleration() {
    return acceleration;
}

float Entity::getMass() {
    return mass;
}