#ifndef SET_H
#define SET_H
#include <fstream>
#include <iostream>

using namespace std;

class Set {
public:
  Set(int size);
  int arr[];
  void Sunion(int x, int y);
  int find(int v);
};

#include "Set.hpp"
#endif
