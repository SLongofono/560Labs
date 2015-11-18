#ifndef QUEUE_H
#define QUEUE_H
#include <array>
#include <cmath>

class Queue {

public:
  Queue();
  Node* q[10];
  void insert(x);
  void deletemin();
  void merge(Node* q1, Node* q2);
  void levelorder();
  int len;
private:
  struct Node {
    int order;
    int key;
    Node* left;
    Node* right;
    Node* first;

    Node(int o, int k, Node* l, Node* r, Node* f):
    order(o), key(k), left(l), right(r), first(f) {
    }
  };

};

#endif
