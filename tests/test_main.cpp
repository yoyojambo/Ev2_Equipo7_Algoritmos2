#include "ford_fulkerson.hpp"
#include "kruskal.hpp"
#include "tsp.hpp"
#include <catch2/catch_all.hpp>

// Test Ford-Fulkerson
TEST_CASE("Ford-Fulkerson Test") {
    std::vector<std::vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int maxFlow = fordFulkerson(graph, 0, 5);
    REQUIRE(maxFlow == 23);
}

// Test Kruskal's Algorithm
TEST_CASE("Kruskal's Algorithm Test") {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    auto mst = g.kruskalMST();
    int totalWeight = 0;
    for (auto &[w, u, v] : mst) totalWeight += w;

    REQUIRE(totalWeight == 19);
}

// Test TSP
TEST_CASE("TSP Test") {
    std::vector<std::vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    std::vector<std::vector<int>> dp(graph.size(), std::vector<int>(1 << graph.size(), -1));
    std::vector<std::vector<int>> path(graph.size(), std::vector<int>(1 << graph.size(), -1));
    int result = tsp(graph, 0, 1, dp, path);

    REQUIRE(result == 80);
}
