# N-Puzzle Solver

## Overview

- The 8 Puzzle is a sliding puzzle consisting of a 3x3 grid with 8 numbered tiles and one empty space. The goal is to rearrange the tiles in the correct order by sliding them into the empty space.

- This project implements the solution to the N Puzzle problem using two different algorithms: A* search algorithm and Iterative Deepening A* (IDA*), both with the Manhattan distance heuristic. The goal is to find the sequence of moves that transforms an initial state of the puzzle into its goal state.

- The A* algorithm is not recommended for puzzles with size greater than 8, as the number of states to explore grows exponentially with the size of the puzzle. However, you can try it with the provided code and enjoy.

## How to Use

### Advanced Users

1. Clone the repository:

```bash
git clone https://github.com/FilipeAbner/N-Puzzle-Solver.git
```

2. Use Makefile to compile the source code:

```bash
make
```
3. Run the executable with the following command:

```bash
./n_puzzle_solver
```

4. Follow the instructions on screen.

### Beginners

1. Download Zip file from the repository.
2. Extract the contents to a folder.
3. Execute the `n_puzzle_solver` executable.
4. Follow the instructions on screen.

## Results
 - Below, we present the results of several executions that allow a detailed comparative analysis between the A* and IDA* algorithms. These results include performance metrics such as execution time, memory consumption, and maximum depth explored in different puzzle scenarios, highlighting the situations in which each algorithm excels. 

 <div align="center">

| **Exemple 1** | **Puzzle** | **Goal** | **Time** | **Memory** | **Nodes explored** | **Depth** |
|---------------|------------|----------|-----------|-------------|--------------------|------------------|
| **A\***       |  8 6 7     |  1 2 3   | 29821 ms  |  2696 Kb    | 18807              |    31            |
| **IDA\***     |  2 5 4     |  4 5 6   | 378 ms    |   28 Kb     |    42472           |       31         |
|               |  3 0 1     |  7 8 9   |           |             |                    |                  |



| **Exemple 2** | **Puzzle** | **Goal** | **Time** | **Memory** | **Nodes explored** | **Depth** |
|---------------|------------|----------|-----------|-------------|--------------------|------------------|
| **A\***       |  1 4 8     |  0 1 2   | 326 ms  |  256 Kb    | 1802              |    23            |
| **IDA\***     |  0 7 5     |  3 4 5   | 26 ms    |   28 Kb     |    3341           |       23         |
|               |  2 6 3     |  6 7 8   |           |             |                    |                  |

| **Exemple 2** | **Puzzle** | **Goal** | **Time** | **Memory** | **Nodes explored** | **Depth** |
|---------------|------------|----------|-----------|-------------|--------------------|------------------|
|               |  14 13 15 7  |  0 1 2 3   |       |            |               |                |
| **IDA\***     |  11 12 9 5   |  4 5 6 7   | 7399916 ms    |   68 Kb     |    443408963           |       57         |
|               |  6  0  2 1     |  8 9 10 11  |  2.05 hours  |             |                    |                  |
|               |  4  8 10 3    |  12 13 14 15  |                  |

</div>

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

### Algorithm Steps

1. Calculate start node f weight.
2. Set start node f weight as bound.
3. Initialize new path list.
4. Add start node to the path list.
5. Call Search:
    1. Get last node inside the path list.
    2. Calculate node f weight.
    3. If node f weight is greater than bound, then:
        - Return it's f weight
    4. If node h weight is 0 (Solution found), then:
        - Add path list nodes to the graph and set it's neighboors
        - Return -1
    5. Set min as INT_MAX 
    6. For each node's successors:
       1. If successor is already in path, then:
          - Skip this successor
       2. Set node as successor's parent
       3. Add successor to path list
       4. Call Search recursively
       5. If Search returns -1, then:
          - Return -1
       6. If Search returns value lower than min, then:
          - Set min as Search value
       7. Pop node off the path list
    7. Return min
6. If Search returns -1 (Solution found), then:
   - Return end state node index
7. If Search returns INT_MAX (Solution not found), then:
   - Returns -1 (In this case, -1 means solution not found)
8. Set bound as Search value
9. Go back to 3.
       
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
├── interface/
│   ├── algorithm_mode_menu.cpp
│   ├── algorithm_mode_menu.hpp
│   ├── main_menu.cpp
│   ├── main_menu.hpp
│   ├── puzzle_state_menu.cpp
│   ├── puzzle_state_menu.hpp
├── util/
│   ├── util.cpp
│   └── util.hpp
└── main.cpp
```
- All functions are documented with string docs in the header files.

## Contributing

```Contributions are welcome!  ```
- For major changes, please open an issue first to discuss what you would like to change.

## Developers

|   | Name             | Github                         | 
| -------------------------------------------------------------------------------------------- | ---------------- | ------------------------------ |
| <img src="https://avatars.githubusercontent.com/u/60756521"  width="100px" heigth="100px" /> | Filipe Abner     | https://github.com/FilipeAbner |
| <img src="https://avatars.githubusercontent.com/u/70250416?v=4"  width="100px" heigth="100px" /> | Lucas Freitas     | https://github.com/LucasFreitaslpf1 |
