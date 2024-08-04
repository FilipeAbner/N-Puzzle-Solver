#pragma once
#define IDA_STAR_HPP
#include "graph/graph.hpp"

using namespace std;

/**
 *  
 *  @param graph graph with all puzzles.
 *  @param weights precomputed weight matrix.
 *  @param goal objective vector.
 *  @return index of the final node (result).
 */
int ida_star(Graph &graph, vector<vector<int>> &weights, vector<int> &goal);

/**
 *  
 *  @param graph graph with all puzzles.
 *  @param path 
 *  @param weights precomputed weight matrix.
 *  @param goal objective vector.
 *  @return -1 if goal is found.
 */
int search(Graph &graph, vector<Node> &path, int g, int bound, vector<vector<int>> &weights, vector<int> &goal);