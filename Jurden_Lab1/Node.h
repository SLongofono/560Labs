#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
    public:
      Node();
      int getValue();
      void setValue(int val);
      Node* getNext();
      void setNext(Node* next);
      Node* getPrev();
      void setPrev(Node* prev);
      
    private:
      int m_value;
      Node* m_next;
      Node* m_prev;
};

#include "Node.hpp"
#endif
