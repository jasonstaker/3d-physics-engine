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
    }

    drawable->setPosition({position.x, position.y});

    float speed = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
    float maxSpeed = 200.f;
    float t = std::min(speed / maxSpeed, 1.f);

    sf::Color color(
        (int)(255 * t),
        0,
        (int)(255 * (1.f - t))
    );

    drawable->setFillColor(color);

    return drawable;
}
