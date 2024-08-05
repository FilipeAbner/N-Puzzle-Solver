#include "util/util.hpp"
#include <cmath>
#include <iostream>
#include <utility>
#include <sys/resource.h>

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

int find_puzzle(Graph &graph, int idx_neighbor, vector<int> &list)
{
    vector<int> neighboor_puzzle = graph.get_node(idx_neighbor).puzzle;

    for (int i = 0; i < list.size(); i++)
    {
        if (neighboor_puzzle == graph.get_node(list[i]).puzzle)
        {
            return list[i];
        }
    }

    return -1;
}

int show_solution(int idx_last_puzzle, Graph &g, bool burst){

  vector<Node> solution;
  Node node_solution = g.get_node(idx_last_puzzle);
  solution.push_back(node_solution);

  int count = 0;
  while (true)
  {
    if (node_solution.parent_index == -1)
    {
      break;
    }
    solution.push_back(g.get_node(node_solution.parent_index));
    node_solution = g.get_node(node_solution.parent_index);
    count++;
  }
  int total_steps = count;

  if(burst){
    for (int i = solution.size() - 1; i >= 0; i--)
    {
      solution[i].print_puzzle();
    }
  
  }else{
    char key;
    while(cin >> key && count >= 0)
    {
       solution[count].print_puzzle();
       count--;
    }

  }

  return total_steps;
}

long get_mem_usage()
{
  struct rusage usage;
  int ret;
  ret = getrusage(RUSAGE_SELF, &usage);
  return usage.ru_maxrss; // in KB
}
