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
  //h->levelOrder();
  //int max = h->findMax(0);
  //cout<<"max: "<<max;
  int sel = 0;
  while(sel != 5)
  {
    cout<<"Make a selection: ";
    cout<<"1-insert"<<endl;
    cout<<"2-deletemin"<<endl;
    cout<<"3-deletemax"<<endl;
    cout<<"4-levelorder"<<endl;
    cout<<"5-exit"<<endl;
    cin>>sel;
    if(sel == 1)
    {
      int num = 0;
      cout<<"What number to insert?"<<endl;
      cin >> num;
      h->insert(num);
    }
    if(sel == 2)
    {
      h->deleteMin();
    }
    if(sel == 3)
    {
      h->deleteMax();
    }
    if(sel == 4)
    {
      cout<<endl;
      h->levelOrder();
      cout<<endl;
    }
  }
};
