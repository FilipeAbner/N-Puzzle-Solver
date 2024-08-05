

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

vector<int> init_puzzle_edit() {

 std::vector<int> puzzle;
    int val;

    std::cout << "Enter the puzzle state (separated by spaces): "<<endl;
    std::cout << "Press -1 to finish." << std::endl;
    while (std::cin >> val) {
        if(val == -1)
            break;
        puzzle.push_back(val);
    }
  
    double n = puzzle.size();
    if (n > 0) {
        double size = (std::sqrt(n));
        double square = size * size;

        if (square == n) {
            //Valid puzzle size
            return puzzle;
        } else {
            std::cout << "\nInvalid size. Please enter a valid number of elements for a NxN puzzle.\n" << std::endl;
            puzzle.clear();
            return puzzle;
        }
    } else {
        std::cout << "No puzzle state entered." << std::endl;
        return puzzle;
    }
}