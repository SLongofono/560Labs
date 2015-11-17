#ifndef SKEW_H
#define SKEW_H
#include <cmath>
#include <queue>
#include <algorithm>
#include "SNode.h"
#include "order.h"

using namespace std;

class Skew
{
  public:
    Skew();
    SNode* merge(SNode* h1, SNode* h2);
    void deleteMin(Skew* h);
    void insert(int x, SNode*& h);
    void print(SNode* root, Order order);
    void print(SNode* root, Order order, std::queue<SNode*> q);
    SNode* root;
};
#include "Skew.hpp"
#endif

/*
Skewify //trickledown
deletemin //trickledown
deletemax //trickeldown
insert //bubbleup
levelorder
*/
