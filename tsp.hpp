#include <vector>

int tsp(std::vector<std::vector<int>> &graph, int pos, int visited,
        std::vector<std::vector<int>> &dp,
        std::vector<std::vector<int>> &path);

std::vector<int> getPath(int start, std::vector<std::vector<int>> &path, int n);
