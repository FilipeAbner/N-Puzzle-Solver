#include "util.hpp"
#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

std::pair<int, int> calculate_indices_2d_to_1d(int indice, int puzzleSize)
{

  int rowSize = sqrt(puzzleSize);
  int x = indice % rowSize;
  int y = indice / rowSize;

  return std::make_pair(x, y);
}

std::pair<int, int> manhattan_distance(int indice_row, int indice_column, int puzzleSize)
{

  std::pair<int, int> dx_dy;
  std::pair<int, int> xy;
  int rowSize = sqrt(puzzleSize);

  xy = calculate_indices_2d_to_1d(indice_row, puzzleSize);
  int x = xy.first;
  int y = xy.second;

  xy = calculate_indices_2d_to_1d(indice_column, puzzleSize);
  int goal_x = xy.first;
  int goal_y = xy.second;

  int dx = abs(x - goal_x);
  int dy = abs(y - goal_y);

  dx_dy = std::make_pair(dx, dy);
  return dx_dy;
}

vector<vector<int>> pre_computate_weight(int size, vector<int> &goal)
{
  vector<vector<int>> puzzle_weights(size, vector<int>(size, 0));

  // for (int i = 1; i < size; i++)
  // {
  //   for (int j = 0; j < size; j++)
  //   {
  //     std::pair<int, int> dx_dy;

  //     dx_dy = manhattan_distance(i, j, size);
  //     // cout << dx_dy.first << " - " <<dx_dy.second << endl;
  //     int dx = dx_dy.first;
  //     int dy = dx_dy.second;

  //     puzzle_weights[i][j] = dx + dy;
  //   }
  // }

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

int count_inversions(vector<int> &puzzle)
{
  int sum = 0;
  for (int i = 0; i < puzzle.size(); i++)
  {
    int count = 0;
    for (int j = i; j < puzzle.size(); j++)
    {
      if (puzzle[j] < puzzle[i] && puzzle[j] != 0)
      {
        count++;
      }
    }
    sum += count;
  }
  return sum;
}
