// Collision.cpp
#include "Collision.hpp"
#include <Ball.hpp>

Collision::Collision() {}

void Collision::update(const vector<shared_ptr<Entity>>& entities) {
    if (entities.size() < 2) {
        return;
    }

    for (size_t i = 0; i < entities.size() - 1; ++i) {
        for (size_t j = i + 1; j < entities.size(); ++j) {
            auto& a = entities[i];
            auto& b = entities[j];

            if (!a || !b) continue;

            if (checkCollisionBetween(a, b)) {
                // Handle entity–entity collision
            }
        }
    }

    for (const auto& entity : entities) {
        if (!entity) continue;

        if (checkCollisionBorder(entity)) {
            // Handle border collision
        }
    }
    
}

// for circles only currently
bool Collision::checkCollisionBetween(const shared_ptr<Entity>& entityOne, const shared_ptr<Entity>& entityTwo) {
    return false;
}

bool Collision::checkCollisionBorder(const shared_ptr<Entity>& entity) {
    return false;
}

float Collision::distance(const shared_ptr<Entity>& entityOne, const shared_ptr<Entity>& entityTwo) {
    auto ballOne = dynamic_pointer_cast<Ball>(entityOne);
    auto ballTwo = dynamic_pointer_cast<Ball>(entityTwo);
    Vec distanceVectorRadius = ballOne->getPosition() - ballTwo->getPosition();
    Vec distanceVector = distanceVectorRadius.getUnit() * (distanceVectorRadius.norm() + ballOne->getRadius() + ballTwo->getRadius());
    
    return sqrt(pow(distanceVector.x, 2) + pow(distanceVector.y, 2));
}