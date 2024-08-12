#include <iostream>
#include <vector>
#include <cstring>
#include "main_menu.hpp"
#include "interface/puzzle_state_menu.hpp"
#include "interface/algorithm_mode_menu.hpp"
#include "util/util.hpp"
#include "graph/graph.hpp"

using namespace std;

// int count_iteractions = 0;
// int count_nodes = 0;

bool check_puzzle_states_content(std::vector<int> &puzzle, std::vector<int> &goal)
{
    if((puzzle.size() == 0 || goal.size() == 0) || (puzzle.size() != goal.size()))
        return false;
    else
        return true;
}


void menu()
{
    int option;
    vector<int> puzzle;
    vector<int> goal;
    vector<vector<int>> weights;
    Graph g;
    bool stats = false;
    char *stats_str = (char*) malloc(9 * sizeof(char));
    
    if (stats_str == nullptr) {
        std::cerr << "Erro ao alocar memória." << std::endl;
        return;
    }
    strcpy(stats_str, "Disabled");

    while(option != 8)
    {
        Node node;
        std::cout << "Choose an Option: "<< std::endl;
        std::cout << "1. Edit Goal " << std::endl;
        std::cout << "2. Edit Puzzle " << std::endl;
        std::cout << "3. Execute A* Single Step " << std::endl;
        std::cout << "4. Execute A* Burst Mode " << std::endl;
        std::cout << "5. Execute IDA* Single Step " << std::endl;
        std::cout << "6. Execute IDA* Burst Mode " << std::endl;
        std::cout << "7. Show stats " << stats_str << endl;
        std::cout << "8. Exit \n" << std::endl;
        
        node.puzzle = puzzle;
        std::cout << "Actual Puzzle State: " << std::endl;
        node.print_puzzle();

        node.puzzle = goal;
        std::cout << "Actual Goal State: "<< "\n" << std::endl;
        node.print_puzzle();

        std::cin >> option;

        switch (option)
        {
        case 1:

            goal = init_puzzle_edit();  
            if(goal.size() != 0){
                if(puzzle.size() != 0)
                    if(!check_solvable(puzzle, goal))
                    {
                        cout << "Puzzle not solvable! Change Puzzle or Goal\n";
                        goal.clear();
                    }
            }
            
            weights = pre_computate_weight(goal.size(), goal);
            break;

        case 2:

            puzzle = init_puzzle_edit();
            if(puzzle.size() != 0)
            {
                g = Graph(puzzle.size());
                node.set_root_node(puzzle);
                g.add_node(node);        
                
                if(goal.size() != 0){
                    if(!check_solvable(node.puzzle, goal))
                    {
                        cout << "Puzzle not solvable! Change Puzzle or Goal\n";
                        puzzle.clear();
                    }
                }
            }
            weights = pre_computate_weight(goal.size(), goal);
            break;

        case 3:

            if(check_puzzle_states_content(puzzle, goal)){
                algorithm_by_step_mode(g, goal, weights, false,stats);
                g = Graph(puzzle.size()); //destroy graph
                node.set_root_node(puzzle);
                g.add_node(node);   //add initial node
            }else
               std::cout << "Puzzle or Goal not defined" << std::endl;
            break;

        case 4:

            if(check_puzzle_states_content(puzzle, goal)){
                algorithm_by_burst_mode(g, goal, weights, false,stats);
                g = Graph(puzzle.size()); //destroy graph
                node.set_root_node(puzzle);
                g.add_node(node);   //add initial node            
            }else
               std::cout << "Puzzle or Goal not defined" << std::endl;
            break;

        case 5:

            if(check_puzzle_states_content(puzzle, goal)){
                algorithm_by_step_mode(g, goal, weights, true,stats);
                g = Graph(puzzle.size()); //destroy graph
                node.set_root_node(puzzle);
                g.add_node(node);   //add initial node            }
            }else
               std::cout << "Puzzle or Goal not defined" << std::endl;
            break;

        case 6:

            if(check_puzzle_states_content(puzzle, goal)){
                algorithm_by_burst_mode(g, goal, weights,true,stats);
                g = Graph(puzzle.size()); //destroy graph
                node.set_root_node(puzzle);
                g.add_node(node);   //add initial node
            }else
               std::cout << "Puzzle or Goal not defined" << std::endl;
            break;

        case 7:

            stats = !stats;
            if (stats) {
               strcpy(stats_str, "Enabled");
            }else{
                strcpy(stats_str, "Disabled");
            }
            break;

        case 8:

            std::cout << "Exiting..." << std::endl;
            break;

        default:
            
            std::cout << "Invalid option" << std::endl;
            break;

        }
    }
}