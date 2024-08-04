#pragma once
#define HEURISTIC_HPP
#include <utility>
#include <vector>
/**
 * Calculate index of points in 2 dimensions and transform in 1 dimension
 * Check for more details: https://ennogames.com/blog/3d-and-2d-coordinates-to-1d-indexes
 *  @param indice element position in matrix
 *  @param puzzleSize Size of puzzle
 *  @return pair of coordinates in vector
 */
std::pair<int,int> calculate_indices_2d_to_1d(int indice,int puzzleSize);

/**
 * Calculates manhattan_distance for future pre computation of weights
 * Check for more details: https://www.datacamp.com/tutorial/manhattan-distance
 *  @param indice_row row index in matrix
 *  @param indice_column column index in matrix
 *  @param puzzleSize Size of puzzle
 *  @return pair for both x and y distances
 */
std::pair<int,int> manhattan_distance(int indice_row,int indice_column, int puzzleSize);

/**
 * Count the number of inversions in puzzle
 * Number of inversion is calculated by counting the numbers smaller than every number occuring after it and find sum for all digits in input configuration(except 0 or blank).
 * Ex: 2 1 5 3 8 4 6 0 7
 * for 2 - 7; only 1 is smaller than 2 then increment count
 * for 1 - 7; no number is smaller than 1
 * for 5 - 7; 3 and 4 is smaller than 5 then increment count 2 times
 * continue until end...
 * total count = 6
 *  @param puzzle vector of puzzle state
 *  @return number of inversions in puzzle
 */
int count_inversions(std::vector<int> &puzzle);