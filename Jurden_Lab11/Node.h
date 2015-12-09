#ifndef NODE_H
#define NODE_H
#include <cmath>
#include <queue>

class Node {
public:
    Node();
    Node* left;
    Node* right;
    int value;
    int edge[2];
};
#include "Node.hpp"
#endif
