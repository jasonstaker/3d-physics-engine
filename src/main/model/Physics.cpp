// Physics.cpp
#include "Physics.hpp"

void Physics::update(const vector<shared_ptr<Entity>>& entities, float dt) {
    for (shared_ptr<Entity> entity : entities) {
        updateEntity(entity, dt);
    }
}

void Physics::updateEntity(shared_ptr<Entity> entity, float dt) {
    Vec& acc = entity->getAcceleration();
    Vec& vel = entity->getVelocity();
    Vec& pos = entity->getPosition();

    acc = (gravity + getLinearDragVec(entity));
    vel = vel + (acc * dt * TIME_SCALE);
    pos = pos + (vel * dt * TIME_SCALE);

    acc = Vec();
}

Vec Physics::getLinearDragVec(const shared_ptr<Entity>& entity) {
    return entity->getVelocity() * dragCoefficient * -1;
}