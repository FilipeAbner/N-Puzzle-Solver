#pragma once
#define IDA_STAR_HPP
#include "graph/graph.hpp"

using namespace std;

extern long count_interactions_ida_star;
extern long count_nodes_ida_star;


/**
 *  
 *  @param graph graph with all puzzles.
 *  @param weights precomputed weight matrix.
 *  @param goal objective vector.
 *  @return index of the final node (result).
 */
int ida_star(Graph &graph,  vector<int> &goal,vector<vector<int>> &weights);

/**
 *  
 *  @param graph graph with all puzzles.
 *  @param path 
 *  @param weights precomputed weight matrix.
 *  @param goal objective vector.
 *  @return -1 if goal is found.
 */
int search(Graph &graph, vector<Node> &path, int g, int bound, vector<vector<int>> &weights, vector<int> &goal);