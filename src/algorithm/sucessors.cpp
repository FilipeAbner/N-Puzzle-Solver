#include <vector>
#include "sucessors.hpp"

using namespace std;

vector<int> get_neighbours(Node node)
{
    vector<int> neighbours;

    for (int i = 0; i < node.puzzle.size(); i++)
    {

        if (node.puzzle[i] == 0)
        {
            // ZERO POSITION IS THE FIRST VALUE WITHIN THE VECTOR
            neighbours.push_back(i);
            int row_size = sqrt(node.puzzle.size());

            // CALCULATES THE PUZZLE'S 2D INDEXES BASED ON THE 1D INDEX
            std::pair<int, int> xy = calculate_indices_2d_to_1d(i, node.puzzle.size());
            int x = xy.first;
            int y = xy.second;

            // CHECK IF THERE IS A PIECE TO THE LEFT OF ZERO (to the left X decreases)
            if ((x - 1) >= 0)
            {
                // CALCULATES 1D INDEX OF THE PUZZLE VECTOR BASED ON 2D INDICES
                int new_idx = (x - 1) + y * row_size;
                neighbours.push_back(new_idx);
            }

            // CHECK IF THERE IS A PART ABOVE ZERO (up Y decreases)
            if ((y - 1) >= 0)
            {
                int new_idx = x + (y - 1) * row_size;
                neighbours.push_back(new_idx);
            }

            // CHECK IF THERE IS A PART BELOW ZERO (downwards Y increases)
            if ((y + 1) < row_size)
            {
                int new_idx = x + (y + 1) * row_size;
                neighbours.push_back(new_idx);
            }

            // CHECK IF THERE IS A PIECE TO THE RIGHT OF ZERO (to the right X increases)
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

    int zero_pos = neighbours[0];
    
    // STARTS AT 1 BECAUSE INDEX 0 IS THE POSITION OF ZERO IN THE PUZZLE
    for (int i = 1; i < neighbours.size(); i++)
    {
        Node new_node;
        new_node.puzzle = node.puzzle;

        new_node.puzzle[zero_pos] = new_node.puzzle[neighbours[i]];
        new_node.puzzle[neighbours[i]] = 0;

        // new_node.print_puzzle() << endl;
        successors.push_back(new_node);
    }
    return successors;
}

void set_sucessors(Graph& graph,vector<Node>& successors, int cur_idx_node)
{
    for (auto &node : successors)
    {
        // Add the Node to the graph
        graph.add_node(node);
        // Add edge from Q to node(Edge from current generated node to generator node)
        graph.neighboors[cur_idx_node].push_back(graph.nodes.size() - 1);
    }
}