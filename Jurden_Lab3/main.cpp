#include <iostream>
#include <string>
#include "Hash.h"

using namespace std;

int main(){
  std::ifstream infile;
  infile.open("data.txt");
  int prime = 0;
  infile >> prime;
  Hash ht = new Hash();
  ht.prime = prime;
  int x = -1;
  while(infile.good()){
    infile >> x;
    ht.insert(x);
  }
  return(0);
};
