#include <vector>
#include <iostream>
#include <limits.h>
#include "ida_star.hpp"
#include "a_star.hpp"
#include "graph/graph.hpp"
#include "algorithm/sucessors.hpp"
#include "util/util.hpp"

using namespace std;

int ida_star(Graph &graph, vector<vector<int>> &weights, vector<int> &goal)
{
    graph.nodes[0].calculate_h_weight(weights, goal);
    int bound = graph.get_node(0).f_weight();


    while (true)
    {
        vector<int> path;
        path.push_back(0);

        int t = search(graph, path, 0, bound, weights, goal);
        if (t == -1)
        {
            return path.back();
        }

        if (t == INT_MAX)
        {
            return -1;
        }

        bound = t;
    }
}

int search(Graph &graph, vector<int> &path, int g, int bound, vector<vector<int>> &weights, vector<int> &goal)
{
    int node_idx = path.back();
    graph.nodes[node_idx].g_weight = g;
    graph.nodes[node_idx].calculate_h_weight(weights, goal);

    // cout << "Node_idx: " << node_idx << "\n";

    if (graph.get_node(node_idx).f_weight() > bound)
    {
        return graph.get_node(node_idx).f_weight();
    }

    // if the node is the goal node
    if (graph.get_node(node_idx).h_weight == 0)
    {
        cout << path.size() << "\n";
        return -1;
    }

    int min = INT_MAX;

    vector<Node> successors = get_successor(graph.nodes[node_idx]);

    set_sucessors(graph, successors, node_idx);

    for (int &idx_neighboor : graph.neighboors[node_idx])
    {
        if (find_puzzle(graph, idx_neighboor, path) == -1)
        {
            graph.nodes[idx_neighboor].parent_index = node_idx;
            path.push_back(idx_neighboor);
            int t = search(graph, path, g + 1, bound, weights, goal);

            if (t == -1)
            {
                return -1;
            }

            if (t < min)
            {
                min = t;
            }
            path.pop_back();
        }
    }

    return min;
}
