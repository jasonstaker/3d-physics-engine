// Collision.cpp
#include "Collision.hpp"

Collision::Collision() {}

void Collision::update(vector<shared_ptr<Entity>>& entities) {
    Quadtree qt(AABB(Vec(0, 0), Vec(Simulation::WINDOW_WIDTH, Simulation::WINDOW_HEIGHT)), 4);
    for (auto& e : entities) {
        qt.insert(e);
    }

    for (auto& ent : entities) {
        if (!ent) continue;
        auto a = dynamic_pointer_cast<Ball>(ent);
        float rA = a->getRadius();
        Vec pos = a->getPosition();

        // Use reach = rA + rA (or rA + maxOtherRadius if they differ)
        float reach = rA * 2.0f;
        AABB range(
            Vec(pos.x - reach, pos.y - reach),
            Vec(pos.x + reach, pos.y + reach)
        );

        auto nearby = qt.query(range);
        for (auto& other : nearby) {
            if (!other || other == ent) continue;

            // ensure each pair only resolved once
            if (ent.get() >= other.get()) continue;

            if (checkCollisionBetween(ent, other)) {
                resolveCollisionBetween(ent, other);
            }
        }
    }

    for (auto& entity : entities) {
        if (entity && checkCollisionBorder(entity)) {
            resolveCollisionBorder(entity);
        }
    }
}


// for circles only currently
bool Collision::checkCollisionBetween(const shared_ptr<Entity>& entityOne, const shared_ptr<Entity>& entityTwo) {
    return distance(entityOne, entityTwo) <= 0;
}

bool Collision::checkCollisionBorder(const shared_ptr<Entity>& entity) {
    auto ball = dynamic_pointer_cast<Ball>(entity);
    return ((ball->getPosition().x + ball->getRadius()) >= Simulation::WINDOW_WIDTH)
            || ((ball->getPosition().y + ball->getRadius()) >= Simulation::WINDOW_HEIGHT)
            || ((ball->getPosition().x - ball->getRadius()) <= 0)
            || ((ball->getPosition().y - ball->getRadius()) <= 0);
}

float Collision::distance(const shared_ptr<Entity>& entityOne, const shared_ptr<Entity>& entityTwo) const {
    auto ballOne = dynamic_pointer_cast<Ball>(entityOne);
    auto ballTwo = dynamic_pointer_cast<Ball>(entityTwo);
    Vec distanceVector = ballOne->getPosition() - ballTwo->getPosition();
    
    return (distanceVector.norm() - ballOne->getRadius() - ballTwo->getRadius());
}

void Collision::resolveCollisionBetween(shared_ptr<Entity>& entityOne, shared_ptr<Entity>& entityTwo) {
    Vec v1 = entityOne->getVelocity();
    Vec v2 = entityTwo->getVelocity();
    float m1 = entityOne->getMass();
    float m2 = entityTwo->getMass();
    
    Vec delta = entityTwo->getPosition() - entityOne->getPosition();
    float correctionLength = distance(entityTwo, entityOne) * -1;
    Vec n = delta.getUnit();

    float combinedMass = m1 + m2;
    float correctionHalf = correctionLength * .501;
    entityOne->getPosition() = entityOne->getPosition() - n * correctionHalf;
    entityTwo->getPosition() = entityTwo->getPosition() + n * correctionHalf;

    
    float coef1 = m1 - Physics::restitution*m2;
    float coef2 = 1 + Physics::restitution;
    float coef3 = m2 - Physics::restitution*m1;

    float v1n = v1.dot(n);
    float v2n = v2.dot(n);
    float v1nAfter = (v1n*coef1 + v2n*coef2*m2)/combinedMass;
    float v2nAfter = (v2n*coef3 + v1n*coef2*m1)/combinedMass;

    Vec v1nVec = n * v1n;
    Vec v2nVec = n * v2n;

    Vec v1tangent = v1 - v1nVec;
    Vec v2tangent = v2 - v2nVec;

    Vec v1nAfterVec = n * v1nAfter;
    Vec v2nAfterVec = n * v2nAfter;

    entityOne->getVelocity() = v1tangent + v1nAfterVec;
    entityTwo->getVelocity() = v2tangent + v2nAfterVec;

}

void Collision::resolveCollisionBorder(shared_ptr<Entity>& entity) {
    auto ball = dynamic_pointer_cast<Ball>(entity);

    if ((ball->getPosition().x + ball->getRadius()) >= Simulation::WINDOW_WIDTH) {
        ball->getVelocity() = Vec(ball->getVelocity().x * -1 * Physics::restitution, ball->getVelocity().y);
        ball->getPosition() = Vec(Simulation::WINDOW_WIDTH - ball->getRadius(), ball->getPosition().y);
    }

    if ((ball->getPosition().y + ball->getRadius()) >= Simulation::WINDOW_HEIGHT) {
        ball->getVelocity() = Vec(ball->getVelocity().x, ball->getVelocity().y * -1 * Physics::restitution);
        ball->getPosition() = Vec(ball->getPosition().x, Simulation::WINDOW_HEIGHT - ball->getRadius());
    }

    if ((ball->getPosition().x - ball->getRadius()) <= 0) {
        ball->getVelocity() = Vec(ball->getVelocity().x * -1 * Physics::restitution, ball->getVelocity().y);
        ball->getPosition() = Vec(ball->getRadius(), ball->getPosition().y);
    }

    if ((ball->getPosition().y - ball->getRadius()) <= 0) {
        ball->getVelocity() = Vec(ball->getVelocity().x, ball->getVelocity().y * -1 * Physics::restitution);
        ball->getPosition() = Vec(ball->getPosition().x, ball->getRadius());
    }


}