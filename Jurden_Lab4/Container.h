#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>

class Container
{
    public:
      Container();
      int getValue();
      void setValue(int val);
      Container* getNext();
      void setNext(Container* next);
      Container* getPrev();
      void setPrev(Container* prev);

    private:
      int m_value;
      Container* m_next;
      Container* m_prev;
};

#include "Container.hpp"
#endif
