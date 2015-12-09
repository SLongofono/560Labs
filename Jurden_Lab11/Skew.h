#ifndef SKEW_H
#define SKEW_H
#include "Node.h"
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

enum Order{PRE_ORDER,
	IN_ORDER,
	LEVEL_ORDER};

class Skew
{
  public:
    Skew();
    Node* merge(Node* h1, Node* h2);
    void deleteMin(Node* h);
    void insert(int x, Node*& h);
    void print(Node* root, Order order);
    void print(Node* root, Order order, std::queue<Node*> q);
    Node* root;
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
