// World.cpp
#include "World.hpp"
#include <iostream>

static int counter = 1;

World::World(int width, int height, vector<shared_ptr<Entity>> entities)
    : width(width), height(height), entities(move(entities)) {}

void World::addEntity(shared_ptr<Entity> entity) {
    entities.push_back(move(entity));
}

void World::update(float dt) {
    physics.update(entities, dt);
    cout << "Frame " << counter << ": ";
    cout << entities[0]->getPosition().x << " " << entities[0]->getPosition().y << "\n";
    counter++;
}

int World::getWidth() {
    return width;
}

int World::getHeight() {
    return height;
}