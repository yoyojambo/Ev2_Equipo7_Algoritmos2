#include "tsp.hpp"
#include <climits>

int tsp(std::vector<std::vector<int>> &graph, int pos, int visited,
        std::vector<std::vector<int>> &dp,
        std::vector<std::vector<int>> &path) {
  int n = graph.size();

  if (visited == (1 << n) - 1)
    return graph[pos][0];

  if (dp[pos][visited] != -1)
    return dp[pos][visited];

  int ans = INT_MAX;
  int nextCity = -1;

  for (int city = 0; city < n; ++city) {
    if (!(visited & (1 << city))) {

      int newAns =
          graph[pos][city] + tsp(graph, city, visited | (1 << city), dp, path);
      if (newAns < ans) {
        ans = newAns;
        nextCity = city;
      }
    }
  }

  dp[pos][visited] = ans;
  path[pos][visited] = nextCity;
  return ans;
}

std::vector<int> getPath(int start, std::vector<std::vector<int>> &path, int n) {
  std::vector<int> order;
  int visited = 1 << start;
  int current = start;

  while (true) {
    order.push_back(current);
    current = path[current][visited];
    if (current == -1)
      break;
    visited |= (1 << current);
  }
  return order;
}
