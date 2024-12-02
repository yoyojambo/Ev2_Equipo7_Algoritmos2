#pragma once

#include <vector>
#include <tuple>
#include <algorithm>

typedef std::tuple<int, int, int> Edge; // Define Edge as a tuple of three integers

// Declaration of the Graph class
class Graph {
    int V;                         // Number of vertices
    std::vector<Edge> edges;       // List of edges

public:
    // Constructor
    Graph(int V);

    // Add an edge to the graph
    void addEdge(int u, int v, int weight);

    // Get the Minimum Spanning Tree using Kruskal's algorithm
    std::vector<Edge> kruskalMST();
};

// Declaration of the UnionFind class (used in Kruskal's algorithm)
class UnionFind {
    std::vector<int> parent, rank;

public:
    // Constructor
    UnionFind(int n);

    // Find the root of a set
    int find(int x);

    // Unite two sets
    void unite(int x, int y);
};
