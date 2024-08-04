# Overview

- This project implements the solution to the N Puzzle problem using two different algorithms, A* search algorithm and Iterative deepening A* (IDA*), both with the Manhattan distance heuristic. The goal is to find the sequence of moves that transforms an initial state of the puzzle into its goal state.
- The A* algorithm is not recommended for puzzles with size greater than 8, as the number of states to explore grows exponentially with the size of the puzzle. But with the actual code you can try it and enjoy.
- The 8 Puzzle is a sliding puzzle that consists of a 3x3 grid with 8 numbered tiles and one empty space. The goal is to rearrange the tiles in the correct order by sliding them into the empty space.

# N-Puzzle Solver

## How to use

- Execute Makefile with command make and use an entry with puzzle state(where 0 is black possition).
Example:
for puzzle state:
7 8 5
1 2 0
3 4 6

entry will be:
7 8 5 1 2 0 3 4 6

## How code Works:

- Code receives an goal with will be the final possition of puzzle
The code uses a* algorithm to solve the puzzle seaching for the best way

# Puzzle Solver with A* Algorithm

## A* Algorithm

The A* algorithm is a search technique that uses a cost function to find the shortest path in a graph. In the context of the 8 Puzzle, A* uses the following cost function:

- f(n) = g(n) + h(n)

Where:
- g(n) is the cost of the path from the initial state to state \( n \).
- h(n) is the heuristic that estimates the cost of the path from state \( n \) to the goal.

### Manhattan Distance Heuristic


The heuristic used is the Manhattan distance, which calculates the sum of the absolute distances of the puzzle pieces relative to their correct positions in the goal state. The formula for the Manhattan distance between a piece and its correct position is:

> distance = |x<sub>1</sub> - x<sub>2</sub>| + |y<sub>1</sub> - y<sub>2</sub>|

Where (x<sub>1</sub>, y<sub>1</sub>) are the current coordinates of the piece and (x<sub>2</sub>, <sub>2</sub>) are the coordinates of the piece in the goal state.

The Manhattan distance is a popular choice for search problems like the 8 Puzzle because it is admissible (it never overestimates the actual cost of achieving the goal) and consistent (the estimate is always less than or equal to the cost of the current step plus the estimate of the next step). For more details on the Manhattan distance, see [this link](https://www.datacamp.com/tutorial/manhattan-distance).



## Project Structure

* The project is organized as follows:

```
src/
├── algorithm/
│ ├── a_star.cpp
│ ├── a_star.hpp
│ ├── ida_star.cpp
│ ├── ida_star.hpp
│ ├── heuristic.cpp
│ ├── heuristic.hpp
│ ├── sucessors.cpp
│ └── sucessors.hpp
├── graph/
│ ├── graph.cpp
│ ├── graph.hpp
│ ├── node.cpp
│ └── node.hpp
├── util/
│ ├── util.cpp
│ └── util.hpp
└── main.cpp
```
- All functions are documented with string docs in the header files.