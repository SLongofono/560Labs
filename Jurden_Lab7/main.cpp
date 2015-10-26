#include <array>
#include <iostream>
#include <fstream>
#include <cmath>
#include "Heap.h"

using namespace std;

int main()
{
  Heap* h = new Heap();
  h->size = 0;
  ifstream infile;
  infile.open("data.txt");
	int x = 0;
  infile >> x;
  h->heap[0] = x;
  int i = 1;
	  while(infile.good()){
      infile >> x;
      h->heap[i] = x;
      h->size++;
      i++;
	  }
    cout<<"size: "<<h->size<<endl;
  infile.close();
  //heapify the newly populated array
  h->heapify();
  h->levelOrder();
  int max = h->findMax(0);
  cout<<"max: "<<max;
};
