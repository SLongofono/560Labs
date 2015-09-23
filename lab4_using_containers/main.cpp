#include <iostream>
#include <fstream>
#include <string>
#include "Hash.h"
//#include "Container.h"

//could do this whole thing with linked lists, make array an array of linked lists

using namespace std;


int main(){
  //Hash* ht = new Hash();
  int prime = 0;

  ifstream infile;
  infile.open("data.txt");
  infile >> prime;
  Hash* ht = new Hash(prime);
  ht->prime = prime;
  ht->num = 0;

  //make table full of empty containers with correct flag and value
  //done for linked lists
  for(int i = 0; i< prime; i++){
  	ht->table[i] = new LinkedList();
  	cout<<"position "<<i<<endl;
  }

  cout<<"done with positions"<<endl;
  int x = -1;
  while(infile.good()){
  	infile >> x;
  	cout<<x<<endl;
  	ht->insert(x);
  }

  ht->print();
  int sel = 0;
  do{

  	cout<<"Enter choice: \n1- insert\n2-delete\n3-print\n4-exit\n"<<endl;
  	cin >> sel;
  	if(sel == 1){
  		int x = 0;
  		cout<<"Enter number to insert: "<<endl;
  		cin >> x;
  		ht->insert(x);
  	}
  	if(sel == 2){
  		int x = 0;
  		cout<<"Enter number to remove: "<<endl;
  		cin >> x;
  		ht->remove(x);
  	}
  	if(sel == 3){
  		ht->print();
  	}
  }while(sel != 4);
  return(0);
};
