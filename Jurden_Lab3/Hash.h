#ifndef HASH_H
#define HASH_H

using namespace std;

struct Container {
  bool flag = false;
    int value = -1;
    Container(bool f, int v){
      flag = f;
      value = v;
    }
};

class Hash
{
public:
  Hash(int p);
  Container** table;
  int hash(int x);
  double num;
  int prime;
  double load;
  void insert(int x);
  void print();
  void remove(int x);
  int findprime(int x);
  bool contains(int x);
  int rehash(int x);
  /*
  void hash(x);
  bool contains(x);
  bool isFull();*/
  int* primes; //for picking the prime immediately larger than 2num
  

private:
  
};
#include "Hash.hpp"
#endif
