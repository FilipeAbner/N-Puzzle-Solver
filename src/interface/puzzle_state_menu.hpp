#pragma once
#define PUZZLE_STATE_MENU_HPP
#include <vector>


using namespace std;

/**
 * @brief User interface entry for puzzle and goal values. Handles inconsistent sizes, incoerent values, duplicate values and empty values
 * 
 * @return std::vector<int> puzzle state
 */
std::vector<int> init_puzzle_edit();