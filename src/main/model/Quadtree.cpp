// Quadtree.cpp
#include "Quadtree.hpp"

Quadtree::Quadtree(AABB boundary, int capacity)
    : boundary(boundary), capacity(capacity), divided(false) {}

bool Quadtree::insert(shared_ptr<Entity> entity) {
    Vec pos = entity->getPosition();
    if (!boundary.contains(pos)) {
        return false;
    }

    if (objects.size() < capacity) {
        objects.push_back(entity);
        return true;
    }

    if (!divided) {
        subdivide();
    }

    if (northeast->insert(entity)) return true;
    if (northwest->insert(entity)) return true;
    if (southeast->insert(entity)) return true;
    if (southwest->insert(entity)) return true;

    return false;
}

void Quadtree::subdivide() {
    Vec topLeft = boundary.topLeft;
    Vec bottomRight = boundary.bottomRight;

    float midX = (topLeft.x + bottomRight.x) / 2.0f;
    float midY = (topLeft.y + bottomRight.y) / 2.0f;

    northwest = make_unique<Quadtree>(
        AABB(topLeft, Vec(midX, midY)),
        capacity
    );

    northeast = make_unique<Quadtree>(
        AABB(Vec(midX, topLeft.y), Vec(bottomRight.x, midY)),
        capacity
    );

    southwest = make_unique<Quadtree>(
        AABB(Vec(topLeft.x, midY), Vec(midX, bottomRight.y)),
        capacity
    );

    southeast = make_unique<Quadtree>(
        AABB(Vec(midX, midY), bottomRight),
        capacity
    );

    divided = true;
}

void Quadtree::query(const AABB& range, vector<shared_ptr<Entity>>& out) {
    if (!boundary.intersects(range)) return;

    for (const auto& obj : objects) {
        if (range.contains(obj->getPosition())) {
            out.push_back(obj);
        }
    }

    if (divided) {
        northeast->query(range, out);
        northwest->query(range, out);
        southeast->query(range, out);
        southwest->query(range, out);
    }
}

void Quadtree::clear() {
    objects.clear();

    if (divided) {
        northeast->clear();
        northwest->clear();
        southeast->clear();
        southwest->clear();

        northeast.reset();
        northwest.reset();
        southeast.reset();
        southwest.reset();

        divided = false;
    }
}