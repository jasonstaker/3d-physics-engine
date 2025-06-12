// Quadtree.cpp
#include "Quadtree.hpp"

// REQUIRES: valid AABB boundary and capacity > 0
// MODIFIES: this
// EFFECTS: constructs empty quadtree node
Quadtree::Quadtree(AABB boundary, int capacity)
    : boundary(boundary), capacity(capacity), divided(false) {}

// REQUIRES: entity pointer valid
// MODIFIES: this or child nodes
// EFFECTS: inserts entity into leaf or subdivides as needed
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

// REQUIRES: not already divided
// MODIFIES: this.northwest, northeast, southwest, southeast, divided flag
// EFFECTS: subdivides boundary into four child quadrants
void Quadtree::subdivide() {
    Vec topLeft = boundary.topLeft;
    Vec bottomRight = boundary.bottomRight;

    float midX = (topLeft.x + bottomRight.x) / 2.0f;
    float midY = (topLeft.y + bottomRight.y) / 2.0f;

    northwest = make_shared<Quadtree>(AABB(topLeft, Vec(midX, midY)), capacity);
    northeast = make_shared<Quadtree>(AABB(Vec(midX, topLeft.y), Vec(bottomRight.x, midY)), capacity);
    southwest = make_shared<Quadtree>(AABB(Vec(topLeft.x, midY), Vec(midX, bottomRight.y)), capacity);
    southeast = make_shared<Quadtree>(AABB(Vec(midX, midY), bottomRight), capacity);

    divided = true;
}

// REQUIRES: out vector is passed by reference
// MODIFIES: out
// EFFECTS: appends entities within range to out (recursive)
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

// MODIFIES: this and child nodes
// EFFECTS: clears all entities and resets subdivision
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

// EFFECTS: returns boundary AABB of this node
AABB Quadtree::getBoundary() const { return boundary; }

// EFFECTS: returns list of child quadtrees if divided
vector<shared_ptr<Quadtree>> Quadtree::getChildren() const {
    vector<shared_ptr<Quadtree>> children;
    if (divided) {
        children.push_back(northwest);
        children.push_back(northeast);
        children.push_back(southwest);
        children.push_back(southeast);
    }
    return children;
}
