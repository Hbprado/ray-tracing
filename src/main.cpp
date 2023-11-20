#include "../includes/camera.h"
#include "../includes/sphere.h"
#include "../includes/plane.h"
#include "../includes/vector.h"
#include "../includes/point.h"
#include "../includes/ray.h"
#include <iostream>
#include <fstream>
#include <vector>

// Função para salvar a imagem em formato PPM
void saveImage(const std::string& filename, const std::vector<std::vector<Vector>>& image, int width, int height) {
    std::ofstream file(filename);
    file << "P3\n" << width << " " << height << "\n255\n";

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            file << static_cast<int>(image[y][x].x * 255) << " "
                 << static_cast<int>(image[y][x].y * 255) << " "
                 << static_cast<int>(image[y][x].z * 255) << " ";
        }
        file << "\n";
    }

    file.close();
}

// Função para renderizar a cena
void render(const Camera& camera, const Sphere& sphere, const Plane& plane, int width, int height) {
    // Buffer de imagem para armazenar as cores dos pixels
    std::vector<std::vector<Vector>> image(height, std::vector<Vector>(width, Vector()));

    // Loop pelos pixels da tela
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Calcular a direção do raio para este pixel
            double u = static_cast<double>(x) / width;
            double v = static_cast<double>(y) / height;
            Vector rayDirection = camera.getU() * (2 * u - 1) + camera.getV() * (1 - 2 * v) + camera.getW();

            // Criar um raio da câmera
            Ray ray(camera.getPosition(), rayDirection.normalize());

            // Verificar interseções com esfera e plano
            double tSphere, tPlane;
            bool hitSphere = sphere.intersect(ray.getOrigin(), ray.getDirection(), tSphere);
            bool hitPlane = plane.intersect(ray.getOrigin(), ray.getDirection(), tPlane);

            // Determinar a cor do pixel com base nas interseções
            if (hitSphere && (!hitPlane || tSphere < tPlane)) {
                image[y][x] = sphere.getColor();
            } else if (hitPlane) {
                image[y][x] = plane.getColor();
            } else {
                // Cor de fundo (por exemplo, preto)
                image[y][x] = Vector(0.0, 0.0, 0.0);
            }
        }
    }

    // Salvar a imagem em formato PPM
    saveImage("output.ppm", image, width, height);
}

int main() {
    // Configurar a câmera, esfera e plano
    Camera myCamera(Point(0.0, 0.0, 5.0), Point(0.0, 0.0, 0.0), Vector(0.0, 1.0, 0.0), 1.0, 800, 600);
    Sphere mySphere(Point(0.0, 0.0, 0.0), 1.0, Vector(1.0, 0.0, 0.0));
    Plane myPlane(Point(0.0, -1.0, 0.0), Vector(0.0, 1.0, 0.0), Vector(1.0, 0.0, 0.0), Vector(0.0, 0.0, 1.0), Vector(0.5, 0.5, 0.5));

    // Renderizar a cena
    render(myCamera, mySphere, myPlane, 800, 600);

    return 0;
}
