#ifndef SET_H
#define SET_H
#include <fstream>
#include <iostream>

using namespace std;

class Graph {
public:
  Set(int size);
  int arr[];
  void union(int x, int y);
  int find(int v);
};

#include "Set.hpp"
#endif
