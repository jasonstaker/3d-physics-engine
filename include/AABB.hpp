#pragma once
#include "Vec.hpp"

class AABB {
public:

    // fields
    Vec topLeft;
    Vec bottomRight;

    // constructors
    AABB() = default;
    AABB(const Vec& topLeft, const Vec& bottomRight);

    // functions
    bool intersects(const AABB& other) const;
    bool contains(const Vec& point) const;
    
};
