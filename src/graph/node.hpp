#pragma once
#define NODE_HPP
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

/**
 * Node structure.
 * @n
 * @arg puzzle: vector with the puzzle.
 * @n
 * @arg index_in_graph: index of the node in the graph.
 * @n
 * @arg parent_index: index of the parent node in the graph.
 * @n
 * @arg g_weight: g is movement cost to move from the starting point to a given square on the grid.
 * @n
 * @arg h_weight: h is the estimated movement cost to move from that given square on the grid to the final destination.
 * @return void
 */
struct Node
{
    vector<int> puzzle;
    int index_in_graph = 0;
    int parent_index = -1;
    int g_weight = 0;
    int h_weight = 0;

    /**
     * move in pre computed weights matrix and calculate the h_weight. 
     * 
     * @param weights vector of vectors with the weights of the puzzle.
     * @param goal vector with the objective puzzle.
     * @return void
     */
    void calculate_h_weight(vector<vector<int>> weights,vector<int> goal);

    /**
     * @deprecated
     * 
     * print the path weight.
     * 
     * @param path vector with the path.
     * @return void
     */
    void print_path_weight(vector<int> &path);

    /**
     * print the puzzle of node.
     * 
     * @return void
     */
    void print_puzzle();

    /**
     * sum of g_weight and h_weight.
     * 
     * @return int f_weight.
     */
    int f_weight() { return g_weight + h_weight; }
};
