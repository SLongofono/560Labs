#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "Node.h"

class LinkedList
{
  public:
      LinkedList();
      ~LinkedList();
      void insert(int x);
      bool isEmpty();
      void erase(int x);
      void print();
      Node* find(int x);
      int size();

  private:
      Node* m_back;
      Node* m_front;
      int m_size;
};

#include "LinkedList.hpp"
#endif
