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

# 8 Puzzle Solver with A* Algorithm

## Overview

- This project implements the solution to the 8 Puzzle problem using the A* search algorithm with the Manhattan distance heuristic. The goal is to find the sequence of moves that transforms an initial state of the puzzle into its goal state.

## Project Structure

* The project is organized as follows:

```
src/
├── algorithm/
│ ├── algorithm.cpp
│ ├── algorithm.hpp
│ ├── heuristic.cpp
│ └── heuristic.hpp
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

## A* Algorithm

The A* algorithm is a search technique that uses a cost function to find the shortest path in a graph. In the context of the 8 Puzzle, A* uses the following cost function:

- f(n) = g(n) + h(n)

Where:
- g(n) is the cost of the path from the initial state to state \( n \).
- h(n) is the heuristic that estimates the cost of the path from state \( n \) to the goal.

### Manhattan Distance Heuristic

The Manhattan distance heuristic calculates the sum of the absolute distances of the puzzle pieces relative to their correct positions in the goal state. The formula for the Manhattan distance between a piece and its correct position is:

-
