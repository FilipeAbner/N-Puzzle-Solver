#include <iostream>
#include <vector>
#include "graph.hpp"
#include "algorithm.hpp"
#include "util.hpp"
#include <chrono>

using namespace std;

int main()
{
  std::chrono::steady_clock::time_point beginCode = std::chrono::steady_clock::now();
  int tries;
  // for (int tries = 0; tries < 100; tries++)
  // {
    cout << "Intance: " << tries << endl;
    int puzzleSize;
    vector<int> puzzle;
    vector<int> goal;

    // recebe os valores do puzzle
    int val;
    for (int i = 0; i < 9; i++)
    {
      cin >> val;
      puzzle.push_back(val);
    }
    // define o tamanho do puzzle
    puzzleSize = puzzle.size();

    // for (int i = 0; i < puzzleSize; i++)
    // {
    //   goal.push_back(i);
    // }

    goal = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    // goal = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    vector<vector<int>> weights = pre_computate_weight(puzzleSize, goal);
    // print_pre_computate_weight(weights);
    Graph g(puzzleSize);
    // return 0;

    Node node;
    node.puzzle = puzzle;

    if (!check_solvable(node.puzzle, goal))
    {
      cout << "Puzzle not solvable!\n";
      return 0;
    }

    node.g_weight = 0;

    g.add_node(node);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    int idx_last_puzzle = a_star_algorithm(g, goal, weights);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "\nTime difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]\n"
              << std::endl;

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

    for (int i = solution.size() - 1; i >= 0; i--)
    {
      solution[i].print_puzzle();
    }
    cout << "Total de passos: " << count << endl;
    cout << "Nodes: " << g.nodes.size() << "\n"
         << endl;

    // g.print_graph();
  // }
  std::chrono::steady_clock::time_point endCode = std::chrono::steady_clock::now();
  std::cout << "\nTotal time = " << std::chrono::duration_cast<std::chrono::seconds>(endCode - beginCode).count() << "[s]\n" << std::endl;
  return 0;
}
