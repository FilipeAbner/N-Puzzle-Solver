#pragma once
#define IDA_STAR_HPP
#include "graph/graph.hpp"

int ida_star(Graph &graph, vector<vector<int>> &weights, vector<int> &goal);
int search(Graph &graph, vector<int> &path, int g, int bound, vector<vector<int>> &weights, vector<int> &goal);