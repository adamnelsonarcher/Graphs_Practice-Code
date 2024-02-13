# Cycle Detection in Directed Graphs

This repository contains a C++ program that detects cycles in directed graphs using Depth-First Search (DFS). The program takes an input file representing a directed graph and outputs whether the graph contains a cycle or not.

## Usage

### Prerequisites

- C++ compiler supporting C++11 standard
- ArgumentManager.h (included)

### Building the Program

To build the program, compile the `main.cpp` file along with `ArgumentManager.h`.

```
g++ -std=c++11 main.cpp -o cycle_detection
```

### Running the Program

The program takes two command-line arguments:
- `input`: Path to the input file containing the directed graph representation.
- `output`: Path to the output file where the result will be written.

Example usage:

```
./cycle_detection input=input.txt output=output.txt
```

### Input Format

The input file format should follow these specifications:
- The first line contains an integer `n`, representing the number of vertices in the graph.
- Subsequent lines represent directed edges in the graph. Each line contains two integers `x` and `y`, indicating an edge from vertex `x` to vertex `y`.

Example input file (`input.txt`):

```
4
0 1
1 2
2 0
2 3
```

### Output Format

The output file contains a single line indicating whether the input graph contains a cycle or not. It outputs "True" if a cycle exists, and "False" otherwise.

Example output file (`output.txt`):

```
True
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- The implementation utilizes Depth-First Search (DFS) algorithm.
- ArgumentManager.h is used for parsing command-line arguments.
