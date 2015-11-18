#ifndef LEFTIST_H
#define LEFTIST_H
#include <cmath>
#include <queue>
#include <algorithm>
#include "LNode.h"
#include "order.h"

using namespace std;


class Leftist
{
  public:
    Leftist();
    LNode* merge(LNode* h1, LNode* h2);
    void deleteMin(LNode* h);
    void insert(int x, LNode*& h);
    int adjustRank(LNode* root);
    void setRanks(LNode* h);
    void print(LNode* root, Order order);
    void print(LNode* root, Order order, std::queue<LNode*> q);
    LNode* root;
};
#include "Leftist.hpp"
#endif

/*
heapify //trickledown
deletemin //trickledown
deletemax //trickeldown
insert //bubbleup
levelorder
*/
