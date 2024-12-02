#include <iostream>
#include <vector>
#include "kruskal.hpp"
#include "tsp.hpp"
#include "ford_fulkerson.hpp"

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> distancias(N, vector<int>(N));
    vector<vector<int>> capacidades(N, vector<int>(N));
    vector<pair<int, int>> ubicaciones(N);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> distancias[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> capacidades[i][j];

    for (int i = 0; i < N; ++i)
        cin >> ubicaciones[i].first >> ubicaciones[i].second;

    pair<int, int> nuevaCasa;
    cin >> nuevaCasa.first >> nuevaCasa.second;

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

    return 0;
}
