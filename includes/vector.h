#ifndef VECTOR_H
#define VECTOR_H

#include "point.h"

struct Vector {

    Point origin, direction;

    Vector();
    Vector(const Point &origin, const Point &direction);

    double magnitude() const;
    double dot(const Vector &other) const;
    Vector cross(const Vector &other) const;

    Vector operator+(const Vector &other) const;
    Vector operator-(const Vector &other) const;
    Vector operator*(const double &k) const;
    Vector operator/(const double &k) const;

    Vector normalize() const;
    Vector scale(const double &k) const;

};

#endif
