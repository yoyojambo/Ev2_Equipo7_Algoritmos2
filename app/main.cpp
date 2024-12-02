#include <iostream>
#include <vector>
#include <sstream>
#include "kruskal.hpp"
#include "tsp.hpp"
#include "ford_fulkerson.hpp"
#include "lineal.hpp"

using namespace std;


int main() {
    string parentesis;
    int N;
    cin >> N;

    vector<vector<int>> distancias(N, vector<int>(N));
    vector<vector<int>> capacidades(N, vector<int>(N));
    vector<pair<int, int>> ubicaciones(N);
    vector<pair<int, int>> centrales;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> distancias[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> capacidades[i][j];

    for (int i = 0; i < N; ++i) {
        string input;
        cin >> input;
        
        int x, y;
        std::stringstream ss(input.substr(1, input.size() - 2)); 
        char comma;  
        ss >> x >> comma >> y;
        
        ubicaciones[i] = make_pair(x, y);
        centrales.emplace_back(x, y);
    }

    std::pair<int, int> nuevaCasa;
    cin >> parentesis;
    std::stringstream ssCasa(parentesis.substr(1, parentesis.size() - 2));
    char commaCasa;
    ssCasa >> nuevaCasa.first >> commaCasa >> nuevaCasa.second;

    
    Graph g(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (distancias[i][j] != 0) {
                g.addEdge(i, j, distancias[i][j]);
            }
        }
    }

    // Parte 1
    vector<Edge> mst = g.kruskalMST();
    for (auto &[peso, u, v] : mst) {
        cout << "(" << char('A' + u) << ", " << char('A' + v) << ")" << endl;
    }

    vector<vector<int>> dp(N, vector<int>(1 << N, -1));
    vector<vector<int>> path(N, vector<int>(1 << N, -1));
    
    int tspCost = tsp(distancias, 0, 1, dp, path);

    //cout << tspCost << endl;

    // Parte 2
    vector<int> orden_ciudades = getPath(0, path, N);
    for (auto city: orden_ciudades) {
      cout << char('A' + city) << " ";
    }
    cout << (orden_ciudades.size() != 0 ? char('A' + orden_ciudades[0]) : ' ') << endl;

    // Parte 3
    int flujoMaximo = fordFulkerson(capacidades, 0, N - 1);
    cout << flujoMaximo << endl;

    // Parte 4
    pair<int, int> centralCercana = encontrarCentralMasCercana(ubicaciones, nuevaCasa);
    // Modified output format for coordinates
    cout << "(" << centralCercana.first << ", " << centralCercana.second << ")" << endl;

    return 0;
}
