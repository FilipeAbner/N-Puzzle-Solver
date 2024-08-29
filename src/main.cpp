#include <iostream>
#include <vector>
#include "graph/graph.hpp"
#include "algorithm/a_star.hpp"
#include "algorithm/ida_star.hpp"
#include "util/util.hpp"
#include <chrono>
#include <string>
#include <cstring>
#include <sys/resource.h>
#include <fstream>
#include <sstream>

using namespace std;

long get_mem_usage()
{
  struct rusage usage;
  int ret;
  ret = getrusage(RUSAGE_SELF, &usage);
  return usage.ru_maxrss; // in KB
}

// Função para ler o estado do arquivo
void readGoalStateFromFile(const std::string& filename, std::vector<int>& goalState) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo: " << filename << std::endl;
        exit(1);
    }
    int tile;
    while (file >> tile) {
        goalState.push_back(tile);
    }
    file.close();
    printf("Goal state: ");
    for (int i = 0; i < goalState.size(); i++) {
        printf("%d ", goalState[i]);
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
  bool useAStar = false;
  std::string goalStateFile;
  vector<int> puzzle;
  std::vector<int> goal;
  vector<Node> solution;
  int val;
  int puzzleSize;
  int idx_last_puzzle;
  int depth = 0;
  long current_mem;
  long end_mem;
  Node node;
  Node node_solution;

  for (int i = 0; i < 9; i++)
  {
    cin >> val;
    puzzle.push_back(val);
  }

  // Processar argumentos de linha de comando
  for (int i = 1; i < argc; ++i) {
      std::string arg = argv[i];
      if (arg == "-a") {
          useAStar = true;
      } else if (arg == "-g") {
          if (i + 1 < argc) {
              goalStateFile = argv[++i];
          } else {
              std::cerr << "Missing argument for flag -g" << std::endl;
              return 1;
          }
      }
  }
 
  // if file was specified, read the state from the file
  if (!goalStateFile.empty()) {
      readGoalStateFromFile(goalStateFile, goal);
  }else{
    // goal state default
     goal= {1, 2, 3, 4, 5, 6, 7, 8, 0};
  }

  puzzleSize = puzzle.size();

  vector<vector<int>> weights = pre_computate_weight(puzzleSize, goal);
  // print_pre_computate_weight(weights);

  Graph g(puzzleSize);
  node.puzzle = puzzle;
  node.g_weight = 0;
  g.add_node(node);

  if (!check_solvable(node.puzzle, goal))
  {
    cout << "Puzzle not solvable!\n";
    return 0;
  }

  current_mem = get_mem_usage();
  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

  if (useAStar) {

      std::cout << "Using A*..." << std::endl;
      
      idx_last_puzzle = a_star_algorithm(g, goal, weights);

  } else {
      
      std::cout << "Using IDA*...\n" << std::endl;
      
      idx_last_puzzle = ida_star(g, weights, goal);
  }

  //statistics
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  end_mem = get_mem_usage();
  std::cout << "\nTime cost = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]\n"
            << std::endl;
  node_solution = g.get_node(idx_last_puzzle);
  solution.push_back(node_solution);
  

  while (true)
  {
    if (node_solution.parent_index == -1)
    {
      break;
    }
    solution.push_back(g.get_node(node_solution.parent_index));
    node_solution = g.get_node(node_solution.parent_index);
    depth++;
  }

  for (int i = solution.size() - 1; i >= 0; i--)
  {
    solution[i].print_puzzle();
  }

  cout << "Current Mem " << current_mem << "Kb" << "\n";
  cout << "Mem usage: " << (end_mem - current_mem) << "Kb" << "\n";
  cout << "Total de passos: " << depth << endl;
  cout << "Total generated Nodes: " << g.nodes.size() << "\n"
       << endl;
  
  return 0;
}
