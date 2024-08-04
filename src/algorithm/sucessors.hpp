#pragma once
#define SUCCESSORS_H
#include <vector>
#include "graph/node.hpp"
#include "algorithm/heuristic.hpp"
#include "graph/graph.hpp"

using namespace std;

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

void set_sucessors(Graph& graph,vector<Node>& successors,int cur_idx_node);