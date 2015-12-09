#include "Tree.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
  ifstream infile;
  infile.open("data1.txt");
  int size = 0;
  int num = 0;
  int x = 0;
  infile >> num;
  std::cout<<num<<"\n";
  Tree* t = new Tree();
  //t->graphs = new Graph[num];
  //t->graphs = g;
  for(int i = 0; i < num; i++)
  {
    infile >> size;
    Graph* g = new Graph(size);
    for(int j = 0; j < size; j++){
      for(int k = 0; k < size; k++)
      {
        infile >> g->edges[j][k];
      }
    }
    t->printGraph(g);
    t->Kruskal(g);
  }
  infile.close();
};
