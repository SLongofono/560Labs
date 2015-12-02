#ifndef QUEUE_H
#define QUEUE_H
#include <array>
#include <cmath>

using namespace std;

class Queue {

public:
  Queue();
  Node* q[10];
  void insert(x);
  void deletemin();
  void merge(Queue* q1, Queue* q2);
  void levelorder();
  int len;
  swap(Node* &node1, Node* &node2)
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
