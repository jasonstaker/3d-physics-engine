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

vector<shared_ptr<Entity>> Quadtree::query(const AABB& range) {
    vector<shared_ptr<Entity>> found;

    if (!boundary.intersects(range)) {
        return found;
    }

    for (const auto& obj : objects) {
        if (range.contains(obj->getPosition())) {
            found.push_back(obj);
        }
    }

    if (divided) {
        auto ne = northeast->query(range);
        auto nw = northwest->query(range);
        auto se = southeast->query(range);
        auto sw = southwest->query(range);

        found.insert(found.end(), ne.begin(), ne.end());
        found.insert(found.end(), nw.begin(), nw.end());
        found.insert(found.end(), se.begin(), se.end());
        found.insert(found.end(), sw.begin(), sw.end());
    }

    return found;
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
