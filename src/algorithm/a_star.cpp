#include "algorithm/a_star.hpp"
#include <limits.h>
#include "util/util.hpp"
#include <iostream>
#include <algorithm>
#include "algorithm/heuristic.hpp"

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
            // Checagem feita Para melhorar a solução
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

        // cur_ix_node = open_list_nodes[0].index_in_graph;
        // cout << "cur_ix_node: " << cur_ix_node << "\n";

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
            //   put the current node in the closed list and look at all of its neighbors
            closed_list.push_back(cur_idx_node);

            // identifica os sucessores adiciona ao grafo e cria aresta
            vector<Node> successors = get_successor(graph.nodes[cur_idx_node]);

            // TODO: ADICIONAR DEPOIS????
            for (auto &node : successors)
            {
                // Adiciona o Nodo ao grafo
                graph.add_node(node);
                // Adiciona aresta de q para node(Aresta do nodo atual gerado para o nodo gerador)
                graph.neighboors[cur_idx_node].push_back(graph.nodes.size() - 1);
            }
            //  for (each neighbor of the current node):
            for (int &idx_neighboor : graph.neighboors[cur_idx_node])
            {
                int closed_list_idx = findPuzzle(graph, idx_neighboor, closed_list);
                if (closed_list_idx != -1)
                {
                    continue;
                }

                int new_g_cost = graph.nodes[cur_idx_node].g_weight + 1;
                if (new_g_cost > highest_g)
                    highest_g = new_g_cost;
                int open_list_idx = findPuzzle(graph, idx_neighboor, open_list);

                // if (new_g_cost < graph.nodes[idx_neighboor].g_weight || open_list_idx == -1)
                // {
                //     graph.nodes[idx_neighboor].g_weight = new_g_cost;
                //     graph.nodes[idx_neighboor].calculate_h_weight(weights);
                //     graph.nodes[idx_neighboor].parent_index = cur_idx_node;

                //     if (open_list_idx == -1)
                //     {
                //         open_list.push_back(idx_neighboor);
                //     }
                // }

                if (open_list_idx == -1)
                {
                    graph.nodes[idx_neighboor].g_weight = new_g_cost;
                    graph.nodes[idx_neighboor].calculate_h_weight(weights,goal);
                    graph.nodes[idx_neighboor].parent_index = cur_idx_node;

                    open_list.push_back(idx_neighboor);
                }
                else if (new_g_cost < graph.nodes[open_list_idx].g_weight)
                {
                    graph.nodes[open_list_idx].g_weight = new_g_cost;
                    graph.nodes[open_list_idx].parent_index = cur_idx_node;
                }
            }
        }
    }
}

vector<int> get_neighbours(Node node)
{
    vector<int> neighbours;

    for (int i = 0; i < node.puzzle.size(); i++)
    {

        if (node.puzzle[i] == 0)
        {
            // POSIÇÃO DO ZERO É O PRIMEIRO VALOR DENTRO DO VETOR
            neighbours.push_back(i);
            int row_size = sqrt(node.puzzle.size());

            // CALCULA OS INDICES 2D DO PUZZLE BASEADO
            // NO INDICE 1D
            std::pair<int, int> xy = calculate_indices_2d_to_1d(i, node.puzzle.size());
            int x = xy.first;
            int y = xy.second;

            // CHECA SE EXISTE UMA PEÇA A ESQUERDA DO ZERO (para esquerda X diminui)
            if ((x - 1) >= 0)
            {
                // CALCULA INDICE 1D DO VETOR DE PUZZLE BASEADO NOS
                // INDICES 2D
                int new_idx = (x - 1) + y * row_size;
                neighbours.push_back(new_idx);
            }

            // CHECA SE EXISTE UMA PEÇA ACIMA DO ZERO (para cima Y diminui)
            if ((y - 1) >= 0)
            {
                int new_idx = x + (y - 1) * row_size;
                neighbours.push_back(new_idx);
            }

            // CHECA SE EXISTE UMA PEÇA ABAIXO DO ZERO (para baixo Y aumenta)
            if ((y + 1) < row_size)
            {
                int new_idx = x + (y + 1) * row_size;
                neighbours.push_back(new_idx);
            }

            // CHECA SE EXISTE UMA PEÇA A DIREITA DO ZERO (para direita X aumenta)
            if ((x + 1) < row_size)
            {
                int new_idx = (x + 1) + y * row_size;
                neighbours.push_back(new_idx);
            }

            break;
        }
    }

    return neighbours;
}

vector<Node> get_successor(Node node)
{
    vector<Node> successors;

    vector<int> neighbours = get_neighbours(node);

    // for (int i = 0; i < neighbours.size(); i++)
    // {
    //     cout << neighbours[i] << " ";
    // }

    int zero_pos = neighbours[0];
    // COMEÇA EM 1 POR QUÊ NO ÍNDICE 0 ESTÁ A POSIÇÃO
    // DO ZERO NO PUZZLE
    for (int i = 1; i < neighbours.size(); i++)
    {
        Node new_node;
        new_node.puzzle = node.puzzle;

        new_node.puzzle[zero_pos] = new_node.puzzle[neighbours[i]];
        new_node.puzzle[neighbours[i]] = 0;

        // new_node.print_puzzle();
        // cout << "\n";
        successors.push_back(new_node);
    }
    return successors;
}

int findPuzzle(Graph &graph, int idx_neighbor, vector<int> &list)
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
