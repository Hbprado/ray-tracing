#include "../includes/vector.h"
#include <cmath> 
#include <iostream>

using namespace std;

Vector::Vector(): origin(), direction() {}

Vector::Vector(const Point &origin, const Point &direction): origin(origin), direction(direction) {}

double Vector::magnitude() const {
    return std::sqrt(origin.x * origin.x + origin.y * origin.y + origin.z * origin.z);
}

double Vector::dot(const Vector &other) const {
    return origin.x * other.origin.x + origin.y * other.origin.y + origin.z * other.origin.z;
}

Vector Vector::cross(const Vector &other) const {
    return Vector(origin.y * other.direction.z - origin.z * other.direction.y,
                  origin.z * other.direction.x - origin.x * other.direction.z,
                  origin.x * other.direction.y - origin.y * other.direction.x);
}


Vector Vector::normalize() const {
    double magnitude = magnitude();
    if (magnitude == 0) {
        return Vector();
    }
    return Vector(origin / magnitude, direction / magnitude);
}

Vector Vector::scale(double k) const {
    return Vector(origin * k, direction * k);
}

Vector Vector::operator+(const Vector &other) const {
    return Vector(origin + other.origin, direction + other.direction);
}

Vector Vector::operator-(const Vector &other) const {
    return Vector(origin - other.origin, direction - other.direction);
}

Vector Vector::operator*(double k) const {
    return Vector(origin * k, direction * k);
}

Vector Vector::operator/(double k) const {
    return Vector(origin / k, direction / k);
}
