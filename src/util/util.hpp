#pragma once
#define UTIL_HPP
#include <vector>


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
