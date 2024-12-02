#include "kruskal.hpp"

Graph::Graph(int V) : V(V) {}

void Graph::addEdge(int u, int v, int weight) {
  edges.push_back(std::make_tuple(weight, u, v));
}

UnionFind::UnionFind(int n) {
  parent.resize(n);
  rank.resize(n, 0);
  for (int i = 0; i < n; ++i)
    parent[i] = i;
}

int UnionFind::find(int x) {
  if (parent[x] != x)
    parent[x] = find(parent[x]);
  return parent[x];
}

void UnionFind::unite(int x, int y) {
  int rootX = find(x);
  int rootY = find(y);
  if (rootX != rootY) {
    if (rank[rootX] > rank[rootY])
      parent[rootY] = rootX;
    else if (rank[rootX] < rank[rootY])
      parent[rootX] = rootY;
    else {
      parent[rootY] = rootX;
      rank[rootX]++;
    }
  }
}

std::vector<Edge> Graph::kruskalMST() {
  std::sort(edges.begin(), edges.end());
  UnionFind uf(V);
  std::vector<Edge> result;

  for (auto &[weight, u, v] : edges) {
    if (uf.find(u) != uf.find(v)) {
      uf.unite(u, v);
      result.push_back({weight, u, v});
    }
  }
  return result;
}
