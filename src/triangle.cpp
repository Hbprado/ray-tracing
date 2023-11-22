#include "../includes/triangle.h"
#include <cmath>

Triangle::Triangle(const Point& v1, const Point& v2, const Point& v3, const Vector& color)
    : vertex1(v1), vertex2(v2), vertex3(v3), color(color) {
    // Calcula a normal do triângulo assumindo que os vértices estão em sentido anti-horário.
    Vector edge1 = Vector(vertex2 - vertex1);
    Vector edge2 = Vector(vertex3 - vertex1);
    normal = edge1.cross(edge2).normalize();
}

bool Triangle::intersect(const Point& origin, const Vector& direction, double& t) const {
    Vector h = direction.cross(Vector(vertex3 - vertex1));
    double a = Vector(vertex2 - vertex1).dot(h);

    if (a > -1e-6 && a < 1e-6) {
        return false;  // O raio é paralelo ao triângulo
    }

    double f = 1.0 / a;
    Vector s = Vector(origin - vertex1);
    double u = f * s.dot(h);

    if (u < 0.0 || u > 1.0) {
        return false;
    }

    Vector q = s.cross(Vector(vertex2 - vertex1));
    double v = f * direction.dot(q);

    if (v < 0.0 || u + v > 1.0) {
        return false;
    }

    t = f * Vector(vertex3 - vertex1).dot(q);

    return t > 1e-6;
}

Vector Triangle::getColor() const {
    return color;
}
