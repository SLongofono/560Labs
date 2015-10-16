#ifndef HASH_H
#define HASH_H

#include "LinkedList.h"
#include "Container.h"
using namespace std;

class Hash
{
public:
  Hash(int p);
  LinkedList** table;
  int hash(long int x);
  int prime;
  void insert(long int x);
  bool contains(long int x);
};
#include "Hash.hpp"
#endif
