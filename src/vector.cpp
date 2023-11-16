#include "../includes/vector.h"
#include <cmath>
#include <iostream>

Vector::Vector() : x(0.0), y(0.0), z(0.0) {}

Vector::Vector(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

Vector Vector::operator+(const Vector &other) const {
    return Vector(x + other.x, y + other.y, z + other.z);
}

Vector Vector::operator-(const Vector &other) const {
    return Vector(x - other.x, y - other.y, z - other.z);
}

Vector Vector::operator*(double scalar) const {
    return Vector(x * scalar, y * scalar, z * scalar);
}

double Vector::dot(const Vector &other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector Vector::cross(const Vector &other) const {
    return Vector(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

double Vector::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vector Vector::normalize() const {
    double len = length();
    if (len != 0.0) {
        return *this * (1.0 / len);
    } else {
        return Vector();
    }
}

/*int main() {
    // Criando dois vetores para teste
    Vector v1(1.0, 2.0, 3.0);
    Vector v2(4.0, 5.0, 6.0);

    // Operações com vetores
    Vector sum = v1 + v2;
    Vector difference = v1 - v2;
    Vector scaled = v1 * 2.0;
    double dotProduct = v1.dot(v2);
    Vector crossProduct = v1.cross(v2);
    double length = v1.length();
    Vector normalized = v1.normalize();

    // Imprimindo resultados
    std::cout << "Soma: (" << sum.x << ", " << sum.y << ", " << sum.z << ")\n";
    std::cout << "Diferença: (" << difference.x << ", " << difference.y << ", " << difference.z << ")\n";
    std::cout << "Multiplicação por escalar: (" << scaled.x << ", " << scaled.y << ", " << scaled.z << ")\n";
    std::cout << "Produto escalar: " << dotProduct << "\n";
    std::cout << "Produto vetorial: (" << crossProduct.x << ", " << crossProduct.y << ", " << crossProduct.z << ")\n";
    std::cout << "Comprimento: " << length << "\n";
    std::cout << "Vetor normalizado: (" << normalized.x << ", " << normalized.y << ", " << normalized.z << ")\n";

    return 0;
}*/