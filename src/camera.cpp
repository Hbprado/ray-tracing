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

// Métodos privados
void Camera::computeUVW() {
    w = (position - lookAt).normalize();
    u = up.cross(w).normalize();
    v = w.cross(u);
}
