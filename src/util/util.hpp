#pragma once
#define UTIL_HPP
#include <vector>
#include "algorithm/heuristic.hpp"
#include "graph/graph.hpp"

using namespace std;

/**
 * Pre compute all possible weight for every possible movement in puzzle using manhatan distance.
 *  @param size size of puzzle.
 *  @param goal vector of objective puzzle.
 *  @return matrix weight of all possible movement.
 */
vector<vector<int>> pre_computate_weight(int size, vector<int> &goal);

/**
 * Check if puzzle has solution.
 * Basicaly checks if number of inversions for both inicial and goal state is odd or even, if true means puzzle can be solvable.
 *  @param initial_state inicial vector state of puzzle.
 *  @param goal_state inicial vector state puzzle objective.
 *  @return true if puzzle is solvable or false if not.
 */
bool check_solvable(vector<int> &initial_state, vector<int> &goal_state);

/**
 * Show matriz of all possible weight for every possible movement in puzzle using manhatan distance
 *  @param puzzle_weights matrix weight
 *  @return void
 */
void print_pre_computate_weight(vector<vector<int>> &puzzle_weights);

/**
 * Seach for a puzzle in a list.
 *  @param graph graph with all puzzles
 *  @param idx_neighbor index of puzzle in graph to be searched .
 *  @param list list of puzzles.
 *  @return if find the puzzle in list return index of puzzle in graph else return -1.
 */
int find_puzzle(Graph &graph, int idx_neighbor, vector<int> &list);


int show_solution(int idx_last_puzzle, Graph &g, bool burst);

long get_mem_usage();