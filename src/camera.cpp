#include "../includes/camera.h"
#include <cmath>
#include <iostream>

Camera::Camera(const Point& position, const Point& lookAt, const Vector& up, double distance, int vResolution, int hResolution)
    : position(position), lookAt(lookAt), up(up), distance(distance), vResolution(vResolution), hResolution(hResolution) {
    computeUVW();
}

void Camera::setPosition(const Point& newPosition) {
    position = newPosition;
}

void Camera::setLookAt(const Point& newLookAt) {
    lookAt = newLookAt;
    computeUVW();
}

void Camera::setUpVector(const Vector& newUp) {
    up = newUp;
    computeUVW();
}

void Camera::setDistance(double newDistance) {
    distance = newDistance;
}

void Camera::setResolution(int vRes, int hRes) {
    vResolution = vRes;
    hResolution = hRes;
}

void Camera::move(const Vector& translation) {
    position += translation;
    lookAt += translation;
}

// Configurar a câmera para olhar em uma determinada direção
void Camera::lookAtPoint(const Point& target) {
    lookAt = target;
    computeUVW();
}

// Configurar a distância focal
void Camera::setFocalDistance(double newFocalDistance) {
    focalDistance = newFocalDistance;
}

// Configurar o campo de visão em graus
void Camera::setFieldOfView(double fov) {
    fieldOfView = fov;
}


Ray Camera::calculateRayForPixel(int x, int y) const {
    // Normalizar as coordenadas do pixel
    double ndcX = (x + 0.5) / hResolution;
    double ndcY = (y + 0.5) / vResolution;

    // Converter para coordenadas da tela
    double screenX = 2.0 * ndcX - 1.0;
    double screenY = 1.0 - 2.0 * ndcY;

    // Calcular direção do raio
    Vector rayDirection = w * (-distance) + u * screenX + v * screenY;

    // Ajustar a direção para ser normalizada
    rayDirection = rayDirection.normalize();

    // Criar e retornar o raio
    return Ray(position, rayDirection);
}

// Métodos privados
void Camera::computeUVW() {
    w = (position - lookAt).normalize();
    u = up.cross(w).normalize();
    v = w.cross(u).normalize();
}

/*int main() {
    // Criar uma câmera inicializada com valores padrão
    Camera myCamera(Point(0.0, 0.0, 0.0), Point(0.0, 0.0, -1.0), Vector(0.0, 1.0, 0.0), 1.0, 800, 600);

    // Configurar a câmera
    myCamera.setDistance(2.0);
    myCamera.setResolution(1920, 1080);

    // Mover a câmera
    myCamera.move(Vector(1.0, 0.0, 0.0));

    // Configurar a direção de olhar da câmera
    myCamera.lookAtPoint(Point(1.0, 1.0, 0.0));

    // Configurar a distância focal e o campo de visão
    myCamera.setFocalDistance(1.5);
    myCamera.setFieldOfView(60.0);

    // Imprimir informações da câmera (ou usar conforme necessário)
    std::cout << "Camera Position: (" << myCamera.getPosition().x << ", " << myCamera.getPosition().y << ", " << myCamera.getPosition().z << ")\n";
    std::cout << "Camera LookAt: (" << myCamera.getLookAt().x << ", " << myCamera.getLookAt().y << ", " << myCamera.getLookAt().z << ")\n";
    std::cout << "Camera Up: (" << myCamera.getUp().x << ", " << myCamera.getUp().y << ", " << myCamera.getUp().z << ")\n";
    std::cout << "Camera U: (" << myCamera.getU().x << ", " << myCamera.getU().y << ", " << myCamera.getU().z << ")\n";
    std::cout << "Camera V: (" << myCamera.getV().x << ", " << myCamera.getV().y << ", " << myCamera.getV().z << ")\n";
    std::cout << "Camera W: (" << myCamera.getW().x << ", " << myCamera.getW().y << ", " << myCamera.getW().z << ")\n";
    std::cout << "Camera Distance: " << myCamera.getDistance() << "\n";
    std::cout << "Camera Resolution: (" << myCamera.getVResolution() << "x" << myCamera.getHResolution() << ")\n";
    std::cout << "Camera Focal Distance: " << myCamera.getFocalDistance() << "\n";
    std::cout << "Camera Field of View: " << myCamera.getFieldOfView() << "\n";

    return 0;
}*/