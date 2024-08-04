#pragma once
#define GRAPH_HPP
#include <vector>
#include <cmath>
#include "node.hpp"

using namespace std;

struct Graph
{
    vector<vector<int>> neighboors;
    vector<Node> nodes;

    int puzzle_size;

    Graph(int puzzle_size);

    void add_node(Node node);

    Node get_node(int idx)
    {
        return nodes[idx];
    }
    void print_graph();

    ~Graph() {}
};

void print_path_weight(vector<int> &path);