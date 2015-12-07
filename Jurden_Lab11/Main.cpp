#include "Tree.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
  ifstream infile;
  infile.open("data.txt");
  int size = 0;
  int num = 0;
  int x = 0;
  infile >> num;
  Tree* t = new Tree(num);
  //t->graphs = new Graph[num];
  //t->graphs = g;
  for(int i = 0; i < num; i++)
  {
    infile >> size;
    Graph* g = new Graph();
    g->size = size;
    for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++)
      {
        infile >> g->edges[i][j];
      }
    }
    t->graphs[i] = g;
    t->printGraph(g);
    /*infile >> size;
    t->graphs[i] = buildGraph(size, infile);
    Graph* g = t->graphs[i];
    t->printGraph(g);*/
  }
  infile.close();
};
