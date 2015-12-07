#ifndef BQUEUE_H
#define BQUEUE_H
#include <queue>
#include <iostream>

using namespace std;

class BQueue {
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

public:
  BQueue();
  Node** q;
  void insert(int x);
//  void deletemin();
//  Node* findMin(Node* root);
  void merge(BQueue* q1, BQueue* q2);
  void combineTree(Node* &r1, Node* &r2);
  void levelorderQueue();
  void levelorder(Node* node, std::queue<Node*> pq);
  void swap(Node* &node1, Node* &node2);
  Node* findMin(Node* root);
};

#endif
