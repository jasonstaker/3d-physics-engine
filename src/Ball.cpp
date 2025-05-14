// Ball.cpp
#include "Ball.hpp"

Ball::Ball(Vec position, Vec velocity, Vec acceleration, float mass, float radius)
    : Entity(position, velocity, acceleration, mass), radius(radius) {}

int Ball::getRadius() {
    return radius;
}