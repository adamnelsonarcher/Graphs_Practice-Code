#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "ArgumentManager.h"
using namespace std;

bool DFScycle(int vertex, const vector<vector<bool>> &graph, vector<bool> &visited, vector<bool> &recStack) {
  if (!visited[vertex]) {
    visited[vertex] = true;
    recStack[vertex] = true;

    for (int adj = 0; adj < graph[vertex].size(); ++adj) {
      if (graph[vertex][adj] && !visited[adj] && DFScycle(adj, graph, visited, recStack)) {
        return true;
      } else if (graph[vertex][adj] && recStack[adj]) {
        return true;
      }
    }
  }

  recStack[vertex] = false;
  return false;
}

bool hasCycle(const vector<vector<bool>> &graph) {
  vector<bool> visited(graph.size(), false);
  vector<bool> recStack(graph.size(), false);

  for (int i = 0; i < graph.size(); ++i) {
    if (!visited[i] && DFScycle(i, graph, visited, recStack)) {
      return true;
    }
  }

  return false;
}

int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  string inputFilePath = am.get("input");
  string outputFilePath = am.get("output");

  ifstream inputFile(inputFilePath);
  ofstream outputFile(outputFilePath);

  if (!inputFile.is_open() || !outputFile.is_open()) {
    cerr << "Error opening files." << endl;
    return 1;
  }

  int n;
  inputFile >> n;
  vector<vector<bool>> graph(n, vector<bool>(n, false));

  int x, y;
  while (inputFile >> x >> y) {
    graph[x][y] = true;
  }

  outputFile << (hasCycle(graph) ? "True" : "False") << endl;

  inputFile.close();
  outputFile.close();

  return 0;
}
