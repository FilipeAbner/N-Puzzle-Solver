#pragma once
#define NODE_HPP
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

struct Node
{
    vector<int> puzzle;
    int index_in_graph = 0;
    int parent_index = -1;
    int g_weight = 0; // g is movement cost to move from the starting point to a given square on the grid.
    int h_weight = 0; // h is the estimated movement cost to move from that given square on the grid to the final destination.

    void calculate_h_weight(vector<vector<int>> weights,vector<int> goal);
    void print_path_weight(vector<int> &path);
    void print_puzzle();
    int f_weight() { return g_weight + h_weight; }
};
