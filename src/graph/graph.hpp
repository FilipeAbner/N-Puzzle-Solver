#pragma once
#define GRAPH_HPP
#include <vector>
#include <cmath>
#include "node.hpp"

using namespace std;

/**
 * Graph structure.
 * @n
 * @arg neighboors: vector of vectors with the index of the neighbors of each node.
 * @n
 * @arg nodes: vector of nodes.
 * @n
 * @arg puzzle_size: size of puzzle.
 * @n
 * @param puzzle_size: size of puzzle.
 */
struct Graph
{
    vector<vector<int>> neighboors;
    vector<Node> nodes;

    int puzzle_size;

    Graph(int puzzle_size);

    /**
     * Add a node to the graph.
     * @param node node to be added.
     */
    void add_node(Node node);

    /**
     * Get the node by index.
     * @param idx index of the node in graph.
     * @return Node 
     */
    Node get_node(int idx)
    {
        return nodes[idx];
    }
    
    /**
     * Print the graph.
     * @return void
     */
    void print_graph();

    ~Graph() {}
};
