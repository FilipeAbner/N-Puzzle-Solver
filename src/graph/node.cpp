#include "graph/graph.hpp"
#include <iostream>

using namespace std;

void Node::calculate_h_weight(vector<vector<int>> weights, vector<int> goal)
{

    int sum = 0;
    int idx_element_in_puzzle;
    int idx_element_in_goal;

    for (auto element : puzzle)
    {
        for(int i = 0; i < puzzle.size(); i++)
        {
            if (element == goal[i])
            {
                idx_element_in_goal = i;
            }
            if(element == puzzle[i])
            {
                idx_element_in_puzzle = i;
            }
        }
        
        sum += weights[idx_element_in_goal][idx_element_in_puzzle];
    }

    h_weight = sum;
}

void Node::print_path_weight(vector<int> &path)
{
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << "\n";
}

void Node::print_puzzle()
{
    for (int i = 0; i < puzzle.size(); i++)
    {
        int row_size = sqrt(puzzle.size());

        cout << puzzle[i] << " ";

        if ((i + 1) % row_size == 0)
        {
            cout << "\n";
        }
    }
    cout << "\n";
}
