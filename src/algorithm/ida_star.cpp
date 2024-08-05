#include <vector>
#include <iostream>
#include <limits.h>
#include "ida_star.hpp"
#include "a_star.hpp"
#include "graph/graph.hpp"
#include "algorithm/sucessors.hpp"
#include "util/util.hpp"

using namespace std;

long count_interactions_ida_star = 0;
long count_nodes_ida_star = 0;

// int count_interactions_ida_star = 0;
// int count_nodes_ida_star = 0;

int ida_star(Graph &graph, vector<int> &goal,vector<vector<int>> &weights)
{
    count_interactions_ida_star = 0;
    count_nodes_ida_star = 0;
    
    graph.nodes[0].calculate_h_weight(weights, goal);
    int bound = graph.get_node(0).f_weight();
    count_nodes_ida_star++;

    while (true)
    {
        vector<Node> path;
        path.push_back(graph.nodes[0]);

        int t = search(graph, path, 0, bound, weights, goal);
        if (t == -1)
        {
            return path.back().index_in_graph;
        }

        if (t == INT_MAX)
        {
            return -1;
        }

        bound = t;
    }
}

int search(Graph &graph, vector<Node> &path, int g, int bound, vector<vector<int>> &weights, vector<int> &goal)
{
    count_interactions_ida_star++;

    Node node = path.back();
    int node_idx = node.index_in_graph;

    node.g_weight = g;
    node.calculate_h_weight(weights, goal);

    if (node.f_weight() > bound)
    {
        return node.f_weight();
    }

    // if the node is the goal node
    if (node.h_weight == 0)
    {
        // cout << "IDA Total nodes: " << count_nodes << endl;
        // cout << "IDA Total iteractions: " << count_iteractions << endl;
        // Começa em 1 por quê na posição 0 está o 
        // estado inicial que já está no grafo
        for (int i = 1; i < path.size(); i++)
        {
            graph.add_node(path[i]);
            graph.neighboors[path[i].parent_index].push_back(path[i].index_in_graph);     
        }

        return -1;
    }

    int min = INT_MAX;

    vector<Node> successors = get_successor(node);


    for (Node &successor : successors)
    {
        count_nodes_ida_star++;
        bool is_in_path = false;

        for (auto path_node : path)
        {
            if (path_node.puzzle == successor.puzzle)
            {
                is_in_path = true;
                break;
            }
        }

        if (!is_in_path)
        {
            successor.parent_index = node_idx;
            successor.index_in_graph = node_idx + 1;
            path.push_back(successor);
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
