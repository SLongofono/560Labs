#ifndef HEAP_H
#define HEAP_H
#include <cmath>
#include <queue>
#include "Node.h"

using namespace std;

enum Order{PRE_ORDER,
	IN_ORDER,
	LEVEL_ORDER};

class Heap
{
  public:
    Heap();
    Heap* merge(Heap* h1, Heap* h2);
    void deleteMin(Heap* h);
    void insert(int x, Heap* h);
    void swap(Heap* h1, Heap* h2);
    int adjustRank(Heap* root);
    void setRanks(Heap* h);
    void print(Heap* root, Order order);
    void print(Node* root, Order order, std::queue<Node*> q);
    Node* root;
    Heap* right;
    Heap* left;
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
