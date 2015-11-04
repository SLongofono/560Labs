#ifndef HEAP_H
#define HEAP_H
#include <cmath>
#include "Node.h"
class Heap
{
  public:
    Heap();
    void merge(Heap* h1, Heap* h2);
    void deleteMin(Heap* h);
    void insert(Node* x, Heap* h);
    void swap(Heap* h1, Heap* h2);
    int adjustRank(Node* root);
    /*
    void levelOrder();
    void inOrder();
    void preorder();
    */
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
