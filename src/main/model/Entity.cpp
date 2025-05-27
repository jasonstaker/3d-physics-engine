// Entity.cpp
#include "Entity.hpp"
#include "ShapeFactory.hpp"

Entity::Entity(Vec position, Vec velocity, Vec acceleration, float mass)
    : position(position), velocity(velocity), acceleration(acceleration), mass(mass) {}

Vec& Entity::getPosition() { return position; }
Vec& Entity::getVelocity() { return velocity; }
Vec& Entity::getAcceleration() { return acceleration; }
float Entity::getMass() { return mass; }

std::shared_ptr<sf::Shape> Entity::render() {
    if (!drawable) {
        drawable = ShapeFactory::createShape(shared_from_this());
    } else {
        drawable->setPosition({position.x, position.y});
    }
    
    return drawable;
}
