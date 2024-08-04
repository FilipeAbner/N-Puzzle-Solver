#include "util/util.hpp"
#include <cmath>
#include <iostream>
#include <utility>
#include "algorithm/heuristic.hpp"


using namespace std;



vector<vector<int>> pre_computate_weight(int size, vector<int> &goal)
{
  vector<vector<int>> puzzle_weights(size, vector<int>(size, 0));

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      //blank position doesnt afect costs
      if(goal[i] == 0) puzzle_weights[i][j] = 0;
      else{

        std::pair<int, int> dx_dy;

        dx_dy = manhattan_distance(i, goal[j], size);
        // cout << dx_dy.first << " - " <<dx_dy.second << endl;
        int dx = dx_dy.first;
        int dy = dx_dy.second;

        puzzle_weights[i][goal[j]] = dx + dy;
      }

    }
  }

  return puzzle_weights;
}

void print_pre_computate_weight(vector<vector<int>> &puzzle_weights)
{
  for (int i = 0; i < puzzle_weights.size(); i++)
  {
    for (int j = 0; j < puzzle_weights.size(); j++)
    {
      cout << puzzle_weights[i][j] << " ";
    }
    cout << "\n";
  }
}

bool check_solvable(vector<int> &initial_state, vector<int> &goal_state)
{

  if ((count_inversions(initial_state) % 2 == 0) == (count_inversions(goal_state) % 2 == 0))
  {
    return true;
  }

  return false;
}

