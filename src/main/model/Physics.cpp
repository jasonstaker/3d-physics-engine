// Physics.cpp
#include "Physics.hpp"

// REQUIRES: dt > 0
// MODIFIES: each entity’s position, velocity, acceleration
// EFFECTS: updates all entities by one physics step
void Physics::update(const vector<shared_ptr<Entity>>& entities, float dt) {
    for (const auto& entity : entities) {
        updateEntity(entity, dt);
    }
}

// REQUIRES: entity is valid, dt > 0
// MODIFIES: entity.position, entity.velocity, entity.acceleration
// EFFECTS: integrates motion and applies drag and gravity
void Physics::updateEntity(const shared_ptr<Entity>& entity, float dt) {
    Vec& acc = entity->getAcceleration();
    Vec& vel = entity->getVelocity();
    Vec& pos = entity->getPosition();

    pos = pos + (vel * dt * Config::timeScale * Config::timeScaleMultiplier);
    vel = vel + (acc * dt * Config::timeScale * Config::timeScaleMultiplier);
    acc = (Vec(0, 9.81f) + getLinearDragVec(entity));
}

// REQUIRES: entity is valid
// EFFECTS: returns drag vector opposing current velocity
Vec Physics::getLinearDragVec(const shared_ptr<Entity>& entity) {
    return entity->getVelocity() * Config::dragCoefficient * -1;
}
