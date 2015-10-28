#ifndef HEAP_H
#define HEAP_H
#include <cmath>
class Heap
{
  public:
    Heap();
    void insert(int x);
    void deleteMin();
    void deleteMax();
    void levelOrder();
    void heapify();
    void trickleDown(int p);
    void trickleDownMin(int i);
    void trickleDownMax(int i);
    void bubbleUp(int i);
    void bubbleUpMin(int i);
    void bubbleUpMax(int i);
    void swap(int x, int y);
    int findMin(int par);
    int findMax(int par);
    int find(int x);
    int grandparent(int i);
    int parent(int i);
    int heap[500];
    int size;
};
#include "Heap.hpp"
#endif

/*
heapify //trickledown
deletemin //trickledown
deletemax //trickeldown
insert //bubbleup
levelorder
*/
