#pragma once
#define A_STAR_HPP
#include "graph/graph.hpp"

using namespace std;


extern int count_open_list;
extern int count_closed_list;
extern int count_interactions_a_star;


/**
 *  Algorithm a* to search.
 *  @param g graph with its root node.
 *  @param goal objective vector.
 *  @param weights precomputed weight matrix.
 *  @return index of the final node (result).
 */
int a_star_algorithm(Graph &g, vector<int> goal, vector<vector<int>> weights);





