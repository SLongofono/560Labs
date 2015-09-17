#include "Container.h"

/*
void Hash::insert(int x){
  
}
*/
void Hash::build(){
  std::ifstream infile;
  infile.open("data.txt");
  infile >> prime;
  infile.close();
  table = new Container*[prime];
  while(infile.good()){
    infile >> x;
    insert(x);
  }
}