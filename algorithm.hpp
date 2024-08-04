#pragma once
#define ALGORITHM_HPP
#include "graph.hpp"


/**
 * Executa o Algoritmo a* para busca
 *  @param g grafo com seu nodo raiz
 *  @param goal vetor objetivo
 *  @param weights matriz de pesos pre computados
 *  @return indice do nodo final (resultado)
 */
int a_star_algorithm(Graph &g, vector<int> goal, vector<vector<int>> weights);

/**
 * Recupera o indice dos numeros que sao vizinhos do posicao vazia
 * Basicamente checa as possibilidades de movimento do estado atual
 *  @param node nó que vai ser olhado
 *  @return vector com o indice dos numeros que sao vizinhos do posicao vazia
 */
vector<int> get_neighbours(Node node);

/**
 * Recupera os vizinhos do nó atual
 * Basicamente retorna todos os possíves novos estados do puzzle
 *  @param node nó que vai ser olhado
 *  @return vector de nodos vizinhos do no atual
 */
vector<Node> get_successor(Node node);

/**
 *
 *
 *  @param
 *  @return
 */
int findPuzzle(Graph &graph, int idx_neighbor, vector<int> &list);


