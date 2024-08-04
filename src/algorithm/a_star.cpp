#include "algorithm/a_star.hpp"
#include <limits.h>
#include "util/util.hpp"
#include <iostream>
#include <algorithm>
#include "algorithm/heuristic.hpp"
#include "algorithm/sucessors.hpp"
using namespace std;

int a_star_algorithm(Graph &graph, vector<int> goal, vector<vector<int>> weights)
{
    vector<int> open_list;
    vector<int> closed_list;
    int g; // g is movement cost to move from the starting point to a given square on the grid
    int h; // h is the estimated movement cost to move from that given square on the grid to the final destination
    // Ao invéz de adicionar o Nodo adicionamos o Indice dele,
    // permitindo acessar o nodo a qualquer momento e calcular seus vizinhos
    open_list.push_back(0);
    int iteration_limit = 20000;

    int cur_idx_node;
    int count = 0;
    int highest_g = 0;

    //  while (the destination node has not been reached):
    while (true)
    {
        count++;

        if (count >= iteration_limit)
        {
            cout << "limit reached\n";
            cout << "nodes: " << graph.nodes.size() << "\n";
            cout << "depth: " << highest_g << "\n";
            return 0;
        }
        // if (open_list.size() % 1000 == 0)
        // {
        //     cout << "open list size:" << open_list.size() << endl;
        // }

        int lowest_f = INT_MAX;
        int lowest_f_idx = 0;
        int lowest_graph_index = 0;
        for (int i = 0; i < open_list.size(); i++)
        {
            // Check done to improve solution
            if (graph.get_node(open_list[i]).f_weight() == lowest_f)
            {

                if (count_inversions(graph.nodes[open_list[i]].puzzle) < count_inversions(graph.nodes[lowest_graph_index].puzzle))
                {
                    lowest_f_idx = i;
                    lowest_graph_index = graph.get_node(open_list[i]).index_in_graph;
                }
            }
            else if (graph.get_node(open_list[i]).f_weight() < lowest_f)
            {
                lowest_f = graph.get_node(open_list[i]).f_weight();
                lowest_f_idx = i;

                lowest_graph_index = graph.get_node(open_list[i]).index_in_graph;
            }
        }
        open_list.erase(open_list.begin() + lowest_f_idx);
        cur_idx_node = lowest_graph_index;


        //  if (this node is our destination node) : //TODO: trocar a comparaçao do goal para h = 0?
        if (graph.get_node(cur_idx_node).puzzle == goal)
        {
            cout << "Open list: " << open_list.size() << "\n";
            cout << "Closed list: " << closed_list.size() << "\n";
            //  we are finished
            return cur_idx_node;
            //  if not:
        }
        else
        {
            // put the current node in the closed list and look at all of its neighbors
            closed_list.push_back(cur_idx_node);

            // identifies successors adds to graph and creates edge
            vector<Node> successors = get_successor(graph.nodes[cur_idx_node]);

            set_sucessors(graph, successors, cur_idx_node);

            //  for (each neighbor of the current node):
            for (int &idx_neighboor : graph.neighboors[cur_idx_node])
            {
                // check if the neighbor is in the closed list
                int closed_list_idx = find_puzzle(graph, idx_neighboor, closed_list);
                if (closed_list_idx != -1)
                {
                    continue;
                }

                //  increment g cost(basicaly the depth of the node) 
                int new_g_cost = graph.nodes[cur_idx_node].g_weight + 1;
                // set the highest g value to view lather the depth of the solution
                if (new_g_cost > highest_g)
                    highest_g = new_g_cost;

                // check if the neighbor is in the open list
                int open_list_idx = find_puzzle(graph, idx_neighboor, open_list);

                // if the neighbor is not in the open list:
                if (open_list_idx == -1)
                {
                    //  compute its g, h, f values and set the parent as the current node
                    graph.nodes[idx_neighboor].g_weight = new_g_cost;
                    graph.nodes[idx_neighboor].calculate_h_weight(weights, goal);
                    graph.nodes[idx_neighboor].parent_index = cur_idx_node;

                    //  add it to the open list
                    open_list.push_back(idx_neighboor);
                }
                else if (new_g_cost < graph.nodes[open_list_idx].g_weight)
                {
                    //  if this new path is shorter than the one previously recorded for this neighbor,
                    //  change the parent of the neighbor to the current node,
                    //  and recalculate the g value
                    graph.nodes[open_list_idx].g_weight = new_g_cost;
                    graph.nodes[open_list_idx].parent_index = cur_idx_node;
                }
            }
        }
    }
}

