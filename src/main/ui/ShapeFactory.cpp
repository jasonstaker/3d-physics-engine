// ShapeFactory.cpp
#include "ShapeFactory.hpp"
#include "CircleEntity.hpp"
#include <random>

// REQUIRES: entity is CircleEntity
// EFFECTS: returns a new circle shape with random color and correct origin
std::unique_ptr<sf::Shape>
ShapeFactory::createShape(const std::shared_ptr<Entity>& entity) {
    // static RNG + distribution, initialized once per thread
    static thread_local std::mt19937 rng{ std::random_device{}() };
    static std::uniform_int_distribution<int> dist{ 0, 255 };

    // get your entity & radius
    auto ball   = std::dynamic_pointer_cast<CircleEntity>(entity);
    float radius = ball->getRadius();

    // pick three random bytes
    sf::Color randomColor{
        static_cast<std::uint8_t>(dist(rng)),
        static_cast<std::uint8_t>(dist(rng)),
        static_cast<std::uint8_t>(dist(rng))
    };

    // build the circle
    auto circle = std::make_unique<sf::CircleShape>(radius);
    circle->setFillColor(randomColor);
    circle->setOrigin({radius, radius});
    circle->setPosition({
        ball->getPosition().x,
        ball->getPosition().y
    });

    return circle;
}
