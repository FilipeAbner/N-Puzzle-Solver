#include <iostream>
#include "algorithm_mode_menu.hpp"
#include "util/util.hpp"
#include <chrono>
#include <sys/resource.h>
#include "algorithm/a_star.hpp"
#include "algorithm/ida_star.hpp"
// extern int count_open_list;
// extern int count_closed_list;
// extern int count_interactions_a_star;
// extern int count_interactions_ida_star;
// extern int count_nodes_ida_star;

using namespace std;

void algorithm_by_step_mode(Graph &g, vector<int> goal, vector<vector<int>> weights,bool ida_mode, bool show_stats){
  int idx_last_puzzle;
  int total_steps;

  std::chrono::steady_clock::time_point begin_algorithm = std::chrono::steady_clock::now();
  long current_mem = get_mem_usage();

  cout <<  "Press any key to iterate steps" << endl;
  if(ida_mode){
    cout << "IDA* Single Step" << endl;
    idx_last_puzzle = ida_star(g, goal, weights);
  }else{
    cout << "A* Single Step" << endl;
    idx_last_puzzle = a_star_algorithm(g, goal, weights);
  }
  long end_mem = get_mem_usage();
  std::chrono::steady_clock::time_point end_algorithm = std::chrono::steady_clock::now();

  total_steps = show_solution(idx_last_puzzle, g, false);
  cout << "Total steps: " << total_steps << endl;

  if(show_stats){
    std::cout << "\nTime Costs = " << std::chrono::duration_cast<std::chrono::milliseconds>(end_algorithm - begin_algorithm).count() << "[ms]\n" << std::endl;
    cout << "Mem usage: " << (end_mem - current_mem) << "Kb" << "\n";
  

    if(!ida_mode){
        cout << "Total nodes: " << g.nodes.size() << endl;
        cout << "Open list: " << count_open_list << endl;
        cout << "Closed list: " << count_closed_list << endl;
        cout << "Total iteractions: " << count_interactions_a_star <<"\n" <<endl;
    }else{
      cout << "Total nodes: " << count_nodes_ida_star << endl;
      cout << "Total iteractions: " << count_interactions_ida_star <<"\n"<< endl;
    }
  }
}

void algorithm_by_burst_mode(Graph &g, vector<int> goal, vector<vector<int>> weights, bool ida_mode, bool show_stats){
  int idx_last_puzzle;
  int total_steps;

  std::chrono::steady_clock::time_point begin_algorithm = std::chrono::steady_clock::now();
  long current_mem = get_mem_usage();
  
  if(ida_mode){
    cout << "IDA* Burst Mode" << endl;
    idx_last_puzzle = ida_star(g, goal, weights);
  
  }else{
    cout << "A* Burst Mode" << endl;
    idx_last_puzzle = a_star_algorithm(g, goal, weights);
  }
  
  long end_mem = get_mem_usage();
  std::chrono::steady_clock::time_point end_algorithm = std::chrono::steady_clock::now();

  total_steps = show_solution(idx_last_puzzle, g, true);
  cout << "Total steps: " << total_steps <<"\n" << endl;

  if(show_stats){
    std::cout << "\nTime Costs = " << std::chrono::duration_cast<std::chrono::milliseconds>(end_algorithm - begin_algorithm).count() << "[ms]\n" << std::endl;
    cout << "Mem usage: " << (end_mem - current_mem) << "Kb" << "\n";
   
    if(!ida_mode){
        cout << "Total nodes: " << g.nodes.size() << endl;
        cout << "Open list: " << count_open_list << endl;
        cout << "Closed list: " << count_closed_list << endl;
        cout << "Total iteractions: " << count_interactions_a_star <<"\n"<< endl;
    }else{
      cout << "Total nodes: " << count_nodes_ida_star << endl;
      cout << "Total iteractions: " << count_interactions_ida_star <<"\n"<< endl;
    }
  }
}