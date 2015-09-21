#include <iostream>
#include <fstream>
#include <string>
#include "Hash.h"
//#include "Container.h"

using namespace std;
//int prime = 0;
//int n = 0;

int main(){
  //Hash* ht = new Hash();
  int prime = 0;
  ifstream infile;
  infile.open("data.txt");
  infile >> prime;
  Hash* ht = new Hash(prime);
  //ht->primes = {2,3,5,7,11,13,17,19,23,29,31,37};
  ht->num = 0;

  //make table full of empty containers with correct flag and value
  for(int i = 0; i< prime; i++){
  	ht->table[i] = new Container(false, -1);
  	cout<<"position "<<i<<endl;
  }
  cout<<"done with positions"<<endl;
  int x = -1;
  while(infile.good()){
  	infile >> x;
  	cout<<x<<endl;
  	ht->insert(x);
  }
  return(0);
};

