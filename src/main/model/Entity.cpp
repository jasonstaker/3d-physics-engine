// Entity.cpp
#include "Entity.hpp"
#include "ShapeFactory.hpp"

Entity::Entity(Vec position, Vec velocity, Vec acceleration, float mass)
    : position(position), velocity(velocity), acceleration(acceleration), mass(mass) {}

// EFFECTS: returns reference to position
Vec& Entity::getPosition() { return position; }

// EFFECTS: returns reference to velocity
Vec& Entity::getVelocity() { return velocity; }

// EFFECTS: returns reference to acceleration
Vec& Entity::getAcceleration() { return acceleration; }

// EFFECTS: returns mass
float Entity::getMass() { return mass; }

// REQUIRES: shared_from_this() valid, ShapeFactory available
// MODIFIES: drawable, baseColor, drawable’s position and color
// EFFECTS: updates and returns an sf::Shape for rendering this entity
std::shared_ptr<sf::Shape> Entity::render() {
    if (!drawable) {
        drawable = ShapeFactory::createShape(shared_from_this());
        baseColor = std::make_shared<sf::Color>(drawable->getFillColor());
    }

    drawable->setPosition({position.x, position.y});
    
    if (Config::showVelocityColors) {
        float speed = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
        float maxSpeed = 200.f;
        float t = std::min(speed / maxSpeed, 1.f);
        sf::Color velocityColor((int)(255 * t), 0, (int)(255 * (1.f - t)));
        drawable->setFillColor(velocityColor);
    } else {
        drawable->setFillColor(*baseColor);
    }

    return drawable;
}
