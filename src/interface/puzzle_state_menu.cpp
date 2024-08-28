

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm> 

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
            for (int i = 0; i < n ; i++){
                if (puzzle[i] >= n || puzzle[i] < 0){
                    cout<< "Inconsistend values due to puzzle size"<< endl;
                    puzzle.clear();
                    return puzzle;
                }
            }
                  
            std::vector<int> puzzleCopy = puzzle;
            std::sort(puzzleCopy.begin(), puzzleCopy.end());
            for (int i = 1; i < n; i++) {
                if (puzzleCopy[i] == puzzleCopy[i - 1]) {
                    std::cout << "Duplicate values found in puzzle." << std::endl;
                    puzzle.clear();
                    return puzzle;
                }
            }

            //Valid puzzle size and coerent values
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