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
 * Retrieves the index of the numbers that are neighbors of the empty position.
 * Basically checks the movement possibilities of the current state.
 *  @param node node that will be looked at.
 *  @return vector with the index of the numbers that are neighbors of the empty position.
 */
vector<int> get_neighbours(Node node);

/**
 * Retrieves the neighbors of the current node.
 * Basically returns all possible new states of the puzzle.
 *  @param node node that will be looked at.
 *  @return vector of neighboring nodes of the current node.
 */
vector<Node> get_successor(Node node);

/**
 * Seach for a puzzle in a list.
 *  @param graph graph with all puzzles
 *  @param idx_neighbor index of puzzle in graph to be searched .
 *  @param list list of puzzles.
 *  @return if find the puzzle in list return index of puzzle in graph else return -1.
 */
int findPuzzle(Graph &graph, int idx_neighbor, vector<int> &list);


