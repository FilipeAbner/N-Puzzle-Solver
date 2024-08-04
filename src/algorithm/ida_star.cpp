#include <vector>
#include <iostream>
#include <limits.h>
#include "ida_star.hpp"
#include "graph/graph.cpp"
#include "algorithm/sucessors.hpp"

using namespace std;

int ida_star(Graph &graph, vector<vector<int>> &weights, vector<int> &goal)
{
    graph.nodes[0].calculate_h_weight(weights, goal);
    int bound = graph.get_node(0).f_weight();
    vector<int> path;

    while (true)
    {
        int t;
    }
}

int search(Graph &graph, vector<int> path, int g, int bound, vector<vector<int>> &weights, vector<int> &goal)
{
    int node_idx = path.back();
    graph.nodes[node_idx].calculate_h_weight(weights, goal);

    if (graph.get_node(node_idx).f_weight() > bound)
    {
        return graph.get_node(node_idx).f_weight();
    }

    // if the node is the goal node
    if (graph.get_node(node_idx).h_weight == 0)
    {
        return -1;
    }

    int min = INT_MAX;

    vector<Node> successors = get_successor(graph.nodes[node_idx]);
    
    set_sucessors(graph,successors,node_idx);


}
