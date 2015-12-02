#include <iostream>
#include "Queue.h"

using namespace std
int main() {
  Queue* que = new Queue();
  ifstream infile;
  infile.open("data.txt");
  int x = 0;
  infile >> x;
  que->q[0]->key = x;
  infile >> x;

  //think about how to populate this - remember to keep track of order !!!!
	  while(infile.good()){
      h->insert(x, h->root);
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
      h->insert(num, h->root);
    }
    if(sel == 2)
    {
      h->deleteMin(h->root);
    }
    if(sel == 3)
    {
      cout<<endl;
      h->print(h->root, PRE_ORDER);
      cout<<endl;
    }
    if(sel == 4)
    {
      cout<<endl;
      h->print(h->root, IN_ORDER);
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
