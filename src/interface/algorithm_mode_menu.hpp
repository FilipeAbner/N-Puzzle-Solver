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

void algorithm_by_step_mode(Graph &g, vector<int> goal, vector<vector<int>> weights,bool ida_mode, bool stats);


void algorithm_by_burst_mode(Graph &g, vector<int> goal, vector<vector<int>> weights, bool ida_mode, bool stats);