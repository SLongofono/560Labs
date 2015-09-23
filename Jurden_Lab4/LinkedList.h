#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "Container.h"

class LinkedList
{
  public:
      LinkedList();
      ~LinkedList();
      void add(int x);
      bool isEmpty();
      void erase(int x);
      void display();
      Container* find(int x);
      int size();
      Container* m_back;
      Container* m_front;
  private:

      int m_size;
};

#include "LinkedList.hpp"
#endif
