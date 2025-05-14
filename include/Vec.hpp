#ifndef VEC_HPP
#define VEC_HPP

class Vec {
public:

    // fields
    float x, y;

    // constructors
    Vec();
    Vec(float x, float y);

    // functions
    Vec operator+(const Vec& other) const;
    Vec operator-(const Vec& other) const;
    Vec operator*(float scalar) const;
    Vec operator/(float scalar) const;

};

#endif