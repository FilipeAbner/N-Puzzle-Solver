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



/**
 * Seach for a puzzle in a list.
 *  @param graph graph with all puzzles
 *  @param idx_neighbor index of puzzle in graph to be searched .
 *  @param list list of puzzles.
 *  @return if find the puzzle in list return index of puzzle in graph else return -1.
 */
int findPuzzle(Graph &graph, int idx_neighbor, vector<int> &list);


