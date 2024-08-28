#pragma once
#define ALGORITHM_MODE_MENU_HPP
#include "algorithm/a_star.hpp"
#include "algorithm/ida_star.hpp"

extern int count_open_list;
extern int count_closed_list;
extern int count_interactions_a_star;
extern int count_interactions_ida_star;
extern int count_nodes_ida_star;

#include <vector>

using namespace std;

/**
 * @brief Execute the specified algorithm showing results by steps 
 * 
 * @param g graph with all puzzles
 * @param goal vector with goal state puzzle
 * @param weights vector of vectors with the weights of the puzzle.
 * @param ida_mode bool: if true execute IDA* algorithm, otherwise execute A*
 * @param stats bool: if true showing stats will be enable
 */
void algorithm_by_step_mode(Graph &g, vector<int> goal, vector<vector<int>> weights,bool ida_mode, bool stats);

/**
 * @brief Execute the specified algorithm showing all results
 * 
 * @param g graph with all puzzles
 * @param goal vector with goal state puzzle
 * @param weights vector of vectors with the weights of the puzzle.
 * @param ida_mode bool: if true execute IDA* algorithm, otherwise execute A*
 * @param stats bool: if true showing stats will be enable
 */
void algorithm_by_burst_mode(Graph &g, vector<int> goal, vector<vector<int>> weights, bool ida_mode, bool stats);