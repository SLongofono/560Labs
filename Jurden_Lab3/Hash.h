#ifndef HASH_H
#define HASH_H
#include "Container.h"

using namespace std;

class Hash
{
public:
  Hash();

  Container * table;
  void build();
  int num;
  int prime;
  //int load;
  //void insert(int x);
  //void print();
  /*
  void delete(int x);
  void hash(x);
  bool contains(x);
  bool isFull();
  */

private:
  int* primes[] = {2,3,5,7,11,13,17,19,23,29,31,37};
};
#include "Hash.hpp"
#endif
