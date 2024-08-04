#include "algorithm/heuristic.hpp"
#include <cmath>

using namespace std;

std::pair<int, int> calculate_indices_2d_to_1d(int indice, int puzzle_size)
{

  int row_size = sqrt(puzzle_size);
  int x = indice % row_size;
  int y = indice / row_size;

  return std::make_pair(x, y);
}

std::pair<int, int> manhattan_distance(int indice_row, int indice_column, int puzzle_size)
{

  std::pair<int, int> dx_dy;
  std::pair<int, int> xy;
  int row_size = sqrt(puzzle_size);

  xy = calculate_indices_2d_to_1d(indice_row, puzzle_size);
  int x = xy.first;
  int y = xy.second;

  xy = calculate_indices_2d_to_1d(indice_column, puzzle_size);
  int goal_x = xy.first;
  int goal_y = xy.second;

  int dx = abs(x - goal_x);
  int dy = abs(y - goal_y);

  dx_dy = std::make_pair(dx, dy);
  return dx_dy;
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
