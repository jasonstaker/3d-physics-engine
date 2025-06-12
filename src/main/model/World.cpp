// World.cpp
#include "World.hpp"

World::World(int width, int height, vector<shared_ptr<Entity>> entities)
    : width(width), height(height), entities(move(entities)) {}

// REQUIRES: entity != nullptr
// MODIFIES: entities
// EFFECTS: appends entity to world
void World::addEntity(shared_ptr<Entity> entity) {
    entities.push_back(move(entity));
}

// REQUIRES: dt >= 0
// MODIFIES: entities via physics and collision subsystems
// EFFECTS: advances physics and resolves collisions
void World::update(float dt) {
    physics.update(entities, dt);
    collision.update(entities);
}

// MODIFIES: entities
// EFFECTS: removes all entities from world
void World::clearEntities() {
    entities.clear();
}

// EFFECTS: returns world width
int World::getWidth() { return width; }

// EFFECTS: returns world height
int World::getHeight() { return height; }

// EFFECTS: returns const reference to entity list
const vector<shared_ptr<Entity>>& World::getEntities() const {
    return entities;
}

// EFFECTS: returns quadtree snapshot from collision system
shared_ptr<Quadtree> World::getQuadtree() const {
    return collision.getQuadtree();
}
