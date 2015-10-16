#ifndef CCONTAINER_H
#define CCONTAINER_H

using namespace std;

class CContainer
{
public:
    bool flag;
    long int value;
    CContainer();
    CContainer(bool f, long int val);
    void setValue(long int val);
    long int getValue();

};
#include "CContainer.hpp"
#endif
