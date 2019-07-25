#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "prim.hpp"


int main(int argc, char* argv[]) {
  // parse the expected input
  // first, the number of nodes for the complete graph part
  int num_nodes;
  std::cin >> num_nodes;

  // second, read in the complete graph
  std::vector< std::vector<int> > graph;
  for(int i=0; i<num_nodes; ++i) {
    std::vector<int> row;
    for (int j=0; j<num_nodes; ++j) {
      int cost;
      std::cin >> cost;
      row.push_back(cost);
    }
    graph.push_back(row);
  }


  MST MST1(num_nodes);

  std::vector< std::vector<int> > graph1 = graph;

  // ...

  // last bit until newline from last cin followed by a blank line
  std::string skip;
  std::getline(std::cin, skip);
  std::getline(std::cin, skip);

  // read in the new edges
  // parse input lines until I find newline
  for(std::string line; std::getline(std::cin, line) && line.compare(""); ) {
    std::stringstream ss(line);
    int from;
    int to;
    int cost;
    ss >> from;
    ss >> to;
    ss >> cost;

    graph1[to][from] = graph1[from][to] = cost;
  }

  // ...
    MST1.primMST(graph, graph1);
    return 0;
}