#ifndef HEAP_H
#define HEAP_H
#include <cmath>

using namespace std;

class Heap
{
public:
  Heap();
  void insert(int x);
  void deleteMin();
  void deleteMax();
  void remove(int x);
  void levelOrder();
  void heapify();
  void trickleDown(int p);
  void bubbleUp(int i);
  void swap(int x, int y);
  int findMin(int par);
  int findMax();
  int find(int x);

  int heap[500];
  int size;
};
#include "Heap.hpp"
#endif
