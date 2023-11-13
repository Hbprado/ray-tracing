#ifndef VECTOR_H
#define VECTOR_H

#include "point.h"

struct Vector {
    double x, y, z;

    Vector();
    Vector(double _x, double _y, double _z);

    // Operações com vetores
    Vector operator+(const Vector &other) const;
    Vector operator-(const Vector &other) const;
    Vector operator*(double scalar) const;
    double dot(const Vector &other) const;
    Vector cross(const Vector &other) const;
    double length() const;
    Vector normalize() const;
};

#endif
