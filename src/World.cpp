// World.cpp
#include "World.hpp"
#include <iostream>

World::World(int width, int height, vector<shared_ptr<Entity>> entities)
    : width(width), height(height), entities(move(entities)) {}

void World::addEntity(shared_ptr<Entity> entity) {
    entities.push_back(move(entity));
}

void World::update(float dt) {
    cout << "Figure out";
}

int World::getWidth() {
    return width;
}

int World::getHeight() {
    return height;
}