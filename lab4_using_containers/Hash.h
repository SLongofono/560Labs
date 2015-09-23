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
  int hash(int x);
  double num;
  int prime;
  double load;
  void insert(int x);
  void print();
  void remove(int x);
  int findprime(int x);
  bool contains(int x);
  int rehash();
  /*
  void hash(x);
  bool contains(x);
  bool isFull();*/
  int* primes; //for picking the prime immediately larger than 2num


private:

};
#include "Hash.hpp"
#endif
