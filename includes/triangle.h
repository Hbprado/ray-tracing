#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vector.h"
#include "point.h"
#include "ray.h"

class Triangle {
public:
    Point vertex1, vertex2, vertex3;
    Vector normal;
    Vector color;

    Triangle(const Point& v1, const Point& v2, const Point& v3, const Vector& color);

    bool intersect(const Point& origin, const Vector& direction, double& t) const;

    Vector getColor() const;
};

#endif
