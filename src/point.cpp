#include "point.h"
#include <cmath> 

Point::Point(): x(0.0), y(0.0), z(0.0);

Point::Point(double _x, double _y, double _z): x(_x), y(_y), z(_z) {}

double Point::distance(const Point &other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    double dz = z - other.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

bool Point::operator>(const Point &other) const {
    return (x > other.x) && (y > other.y) && (z > other.z);
}

bool Point::operator<(const Point &other) const {
    return (x < other.x) && (y < other.y) && (z < other.z);
}

bool Point::operator==(const Point &other) const {
    return (x == other.x) && (y == other.y) && (z == other.z);
}

bool Point::operator!=(const Point &other) const {
    return !(*this == other);
}




