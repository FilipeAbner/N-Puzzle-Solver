#include "graph.hpp"
#include <iostream>

Graph::Graph(int _puzzle_size)
{

    puzzle_size = _puzzle_size;
}

void Graph::add_node(Node node)
{
    node.index_in_graph = nodes.size();
    nodes.push_back(node);
    neighboors.push_back({});
    // inicilaliza o index sempre ao adicionar um novo nó
}

void Graph::print_graph()
{
    for (int i = 0; i < neighboors.size(); i++)
    {
        cout << "index:" << i << " " << "f_weight:" << nodes[i].f_weight() << "\n";
        cout << "g_weight: " << nodes[i].g_weight << endl;
        cout << "h_weight: " << nodes[i].h_weight << endl;
        cout << "parent: " << nodes[i].parent_index << endl;
        nodes[i].print_puzzle();

        cout << "\n";
    }
}
