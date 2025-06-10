// World.cpp
#include "World.hpp"

World::World(int width, int height, vector<shared_ptr<Entity>> entities)
    : width(width), height(height), entities(move(entities)) {}

void World::addEntity(shared_ptr<Entity> entity) {
    entities.push_back(move(entity));
}

void World::update(float dt) {
    physics.update(entities, dt);
    collision.update(entities);
}

int World::getWidth() { return width; }

int World::getHeight() { return height; }

const vector<shared_ptr<Entity>>& World::getEntities() const { return entities; }

shared_ptr<Quadtree> World::getQuadtree() const {
    return collision.getQuadtree(); // returns a copy (cheap for shared_ptr)
}