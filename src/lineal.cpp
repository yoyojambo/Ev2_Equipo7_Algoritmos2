#include "lineal.hpp"

double calcularDistancia(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
    return std::sqrt(std::pow(p1.first - p2.first, 2) + std::pow(p1.second - p2.second, 2));
}

// Encuentra la central más cercana a una ubicación dada
// Entrada: lista de coordenadas de las centrales, y coordenada de la nueva casa
// Salida: coordenada de la central más cercana o (-1, -1) si la lista está vacía
std::pair<int, int> encontrarCentralMasCercana(const std::vector<std::pair<int, int>>& centrales, const std::pair<int, int>& nuevaCasa) {
    if (centrales.empty()) {
        return {-1, -1};  // Valor especial que indica error
    }

    std::pair<int, int> centralMasCercana = centrales[0];
    double distanciaMinima = calcularDistancia(centrales[0], nuevaCasa);

    for (const auto& central : centrales) {
        double distancia = calcularDistancia(central, nuevaCasa);
        if (distancia < distanciaMinima) {
            distanciaMinima = distancia;
            centralMasCercana = central;
        }
    }

    return centralMasCercana;
}

