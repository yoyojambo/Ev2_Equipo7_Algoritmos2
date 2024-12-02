#pragma once

#include <vector>
#include <queue>
#include <climits>

bool bfs(std::vector<std::vector<int>> &rGraph, int s, int t, std::vector<int> &parent);

int fordFulkerson(std::vector<std::vector<int>> &graph, int s, int t);
