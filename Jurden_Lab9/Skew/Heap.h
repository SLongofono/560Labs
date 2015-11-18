#ifndef HEAP_H
#define HEAP_H
#include <cmath>
#include <queue>
#include <algorithm>
#include "Node.h"

using namespace std;

enum Order{PRE_ORDER,
	IN_ORDER,
	LEVEL_ORDER};

class Heap
{
  public:
    Heap();
    Node* merge(Node* h1, Node* h2);
    void deleteMin(Node* h);
    void insert(int x, Node*& h);
    void print(Node* root, Order order);
    void print(Node* root, Order order, std::queue<Node*> q);
    Node* root;
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
