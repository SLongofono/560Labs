#ifndef CHASH_H
#define CHASH_H
#include "CContainer.h"

using namespace std;

class CHash
{
public:
  CHash(int p);
  CContainer** table;
  int chash(int long x);
  int prime;
  void Cinsert(int long x);
  bool contains(int long x);
};
#include "CHash.hpp"
#endif
