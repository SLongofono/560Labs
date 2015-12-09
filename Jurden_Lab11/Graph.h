#ifndef GRAPH_H
#define GRAPH_H
#include <fstream>
#include <iostream>

using namespace std;

class Graph {
public:
  Graph(int size);
  int size;
  //dont think we need this... int vertex[size][size];
  int** edges;
};

#include "Graph.hpp"
#endif
