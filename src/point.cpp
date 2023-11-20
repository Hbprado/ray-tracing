#include "../includes/point.h"
#include <cmath> 
#include <iostream>

using namespace std;
Point::Point(): x(0.0), y(0.0), z(0.0){};

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

Vector Point::operator-(const Point &other) const {
  return Vector(x - other.x, y - other.y, z - other.z);
} 

Point& Point::operator+=(const Vector& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Point Point::operator+(const Vector& other) const {
    return Point(x + other.x, y + other.y, z + other.z);
}

/*int main() {
    // Criar pontos
    Point p1(1.0, 2.0, 3.0);
    Point p2(4.0, 5.0, 6.0);

    // Calcular distância entre os pontos
    double distance = p1.distance(p2);
    std::cout << "Distância entre p1 e p2: " << distance << std::endl;

    // Testar operadores de comparação
    std::cout << "p1 > p2: " << (p1 > p2) << std::endl;
    std::cout << "p1 < p2: " << (p1 < p2) << std::endl;
    std::cout << "p1 == p2: " << (p1 == p2) << std::endl;
    std::cout << "p1 != p2: " << (p1 != p2) << std::endl;

    // Criar vetor a partir da diferença entre pontos
    Vector v = p1 - p2;
    std::cout << "Vetor resultante: (" << v.x << ", " << v.y << ", " << v.z << ")" << std::endl;

    // Testar operador de adição com vetor
    Vector addVector(1.0, 1.0, 1.0);
    p1 += addVector;
    std::cout << "Novo ponto após adição do vetor: (" << p1.x << ", " << p1.y << ", " << p1.z << ")" << std::endl;

    return 0;
}*/