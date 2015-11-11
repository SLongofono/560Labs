#include <array>
#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include "Heap.h"

using namespace std;

int main()
{
  std::queue<Node*> q;
  Heap* h = new Heap();
  ifstream infile;
  infile.open("data.txt");
  int x = 0;
  infile >> x;
  h->root = new Node();
  h->root->setValue(x);
  infile >> x;
	  while(infile.good()){
      h->insert(x, h);
      cout<<"added "<<x<<endl;
      infile >> x;
	  }
  infile.close();

  int sel = 0;
  while(sel != 6)
  {
    cout<<"Make a selection: ";
    cout<<"1-insert"<<endl;
    cout<<"2-deletemin"<<endl;
    cout<<"3-preorder"<<endl;
    cout<<"4-inorder"<<endl;
    cout<<"5-levelorder"<<endl;
    cout<<"6-exit"<<endl;
    cin>>sel;
    if(sel == 1)
    {
      int num = 0;
      cout<<"What number to insert?"<<endl;
      cin >> num;
      h->insert(num, h);
    }
    if(sel == 2)
    {
      h->deleteMin(h);
    }
    if(sel == 3)
    {
      cout<<endl;
      h->print(h, PRE_ORDER);
      cout<<endl;
    }
    if(sel == 4)
    {
      cout<<endl;
      h->print(h, IN_ORDER);
      cout<<endl;
    }
    if(sel == 5)
    {
      cout<<endl;
      h->print(h->root, LEVEL_ORDER, q);
      cout<<endl;
    }
  }
};
