#pragma once
#define ALGORITHM_HPP
#include "graph/graph.hpp"


/**
 * Execute Algorithm a* to search.
 *  @param g graph with its root node.
 *  @param goal objective vector.
 *  @param weights precomputed weight matrix.
 *  @return index of the final node (result).
 */
int a_star_algorithm(Graph &g, vector<int> goal, vector<vector<int>> weights);





