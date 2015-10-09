#ifndef CONTAINER_H
#define CONTAINER_H

using namespace std;

class Container
{
public:
    bool flag;
    int value;
    Container();
    Container(bool f, int val);
    void setValue(int val);
    int getValue();

};
#include "Container.hpp"
#endif
