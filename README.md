# N-Puzzle Solver

## Overview

- The 8 Puzzle is a sliding puzzle consisting of a 3x3 grid with 8 numbered tiles and one empty space. The goal is to rearrange the tiles in the correct order by sliding them into the empty space.

- This project implements the solution to the N Puzzle problem using two different algorithms: A* search algorithm and Iterative Deepening A* (IDA*), both with the Manhattan distance heuristic. The goal is to find the sequence of moves that transforms an initial state of the puzzle into its goal state.

- The A* algorithm is not recommended for puzzles with size greater than 8, as the number of states to explore grows exponentially with the size of the puzzle. However, you can try it with the provided code and enjoy.

## Manhattan Distance Heuristic

The heuristic used is the Manhattan distance, which calculates the sum of the absolute distances of the puzzle pieces relative to their correct positions in the goal state. The formula for the Manhattan distance between a piece and its correct position is:

> distance = |x<sub>1</sub> - x<sub>2</sub>| + |y<sub>1</sub> - y<sub>2</sub>|

Where (x<sub>1</sub>, y<sub>1</sub>) are the current coordinates of the piece and (x<sub>2</sub>, y<sub>2</sub>) are the coordinates of the piece in the goal state.

The Manhattan distance is a popular choice for search problems like the 8 Puzzle because it is admissible (it never overestimates the actual cost of achieving the goal) and consistent (the estimate is always less than or equal to the cost of the current step plus the estimate of the next step). For more details on the Manhattan distance, see [this link](https://www.datacamp.com/tutorial/manhattan-distance).

## Puzzle Solver with A* Algorithm

### Description

The A* algorithm is a search technique that uses a cost function to find the shortest path in a graph. In the context of the 8 Puzzle, A* uses the following cost function:

\[ f(n) = g(n) + h(n) \]

Where:
- \( g(n) \) is the cost of the path from the initial state to state \( n \).
- \( h(n) \) is the [heuristic](#manhattan-distance-heuristic) that estimates the cost of the path from state \( n \) to the goal.

The A* algorithm uses two data structures: an open list and a closed list. The open list contains the states that have been generated but not yet explored, while the closed list contains the states that have been explored.

### Algorithm Steps

1. Add the initial state to the open list.
2. While the open list is not empty:
    1. Select the state with the lowest \( f(n) \) value from the open list. (Optimization with [Number of Inversions](#puzzle-is-solvable))
    2. If the selected state is the goal state, return the path to the goal.
    3. Else put the current node in the closed list and look at all of its neighbors.
3. For each successor:
    1. If the neighbor is in the closed list then continue.
    2. If the neighbor is in the open list then:
        - Compute its g, h, f values and set the parent as the current node.
        - Add it to the open list.
    3. Else if this new path is shorter than the one previously recorded for this neighbor then:
        - Change the parent of the neighbor to the current node.
        - Recalculate the \( g \) value.

## Puzzle Solver with IDA* Algorithm

### Description

- The IDA* algorithm is a variant of the A* algorithm that uses iterative deepening to find the optimal solution. It is more memory-efficient and consumes less memory than A* but may take longer to find the solution.

*To be completed...*

## Puzzle is Solvable?

- It is possible to check if a puzzle is solvable through its number of inversions.
- The number of inversions is calculated by counting the numbers smaller than every number occurring after it and finding the sum for all digits in the input configuration (except 0 or blank).

### Example

- Puzzle: `2 1 5 3 8 4 6 0 7`
    - for `2` - 7; only 1 is smaller than 2, then increment count.
    - for `1` - 7; no number is smaller than 1.
    - for `5` - 7; `3` and `4` are smaller than `5`, then increment count 2 times.
    - continue until end...
    - total = 1 + 0 + 2 + 0 + 3 + 0 + 0 + 0 + 0 = 6

- Now apply this for the goal state and check:
    - If the number of inversions for both the initial and goal state is odd or even, the puzzle is solvable; otherwise, it is not. **The number of inversions can be used as a tiebreaker in cases where the f value is equal for both nodes being compared.**

## Project Structure

The project is organized as follows:

```plaintext
src/
├── algorithm/
│   ├── a_star.cpp
│   ├── a_star.hpp
│   ├── ida_star.cpp
│   ├── ida_star.hpp
│   ├── heuristic.cpp
│   ├── heuristic.hpp
│   ├── successors.cpp
│   └── successors.hpp
├── graph/
│   ├── graph.cpp
│   ├── graph.hpp
│   ├── node.cpp
│   └── node.hpp
├── util/
│   ├── util.cpp
│   └── util.hpp
└── main.cpp
```
- All functions are documented with string docs in the header files.

## How to Use

1. Clone the repository:

```bash
git clone 
```

2. Use Makefile to compile the source code:

```bash
make
```
3. Run the executable with the following command:

```bash
./n_puzzle_solver
```

4. Follow the instructions on the screen to enter the initial state of the puzzle.