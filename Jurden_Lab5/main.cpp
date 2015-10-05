#include <iostream>
#include <fstream>
#include <stdexcept>
#include "BinarySearchTree.h"
#include "Queue.h"
#include "Node.h"
#include "PreconditionViolationException.h"

using namespace std;

void printMenu()
{
std::cout<<"Input a selection:"<<std::endl;
std::cout<<"1) insert"<<std::endl;
std::cout<<"2) remove"<<std::endl;
std::cout<<"3) deletemin"<<std::endl;
std::cout<<"4) deletemax"<<std::endl;
std::cout<<"5) print"<<std::endl;
std::cout<<"6) Search"<<std::endl;
std::cout<<"7) Exit"<<std::endl;
std::cout<<"Your choice: "<<std::endl;
}

int main()
{
	BinarySearchTree* orig = new BinarySearchTree();
	//need to read in values from data.txt
	ifstream infile;
  	infile.open("data.txt");
	int x = 0;
	infile >> x;
	orig->add(x);
	  while(infile.good()){
	  	infile >> x;
	  	orig->add(x);
	  }
	 cout<< orig->getRoot()->getValue() << " = root value";

	int sel;
	do{
		printMenu();
		std::cin>>sel;
		std::cout<<"You chose: "<<sel<<"\n";
		if(sel==1)
		{
			int val;
			std::cout<<"Input a value to add to the tree\n";
			std::cin>>val;
			orig->add(val);
		}

		if(sel==2)
		{

			if(orig->getRoot() == nullptr)
			{
				std::cout<<"Tree doesnt exist \n";
			}
			else
			{
				cout << "which value do you want to remove?";
				int val = 0;
				cin >> val;
				orig->removeV(val);
			}
		}

		if(sel==3)
		{
			orig->deleteMin();
		}

		if(sel==4)

		{
			orig->deleteMax();
		}

		if(sel==5)
		{
			int po;
			std::cout<<"Print order options:\n";
			std::cout<<"\t0 - pre-order\n\t1 - in-order\n\t2 - post-order\n\t3- level-order";
			std::cin>>po;
			std::cout<<"Choice: "<<po<<"\n";
			if(orig->getRoot() != nullptr)
			{
				if(po == 0)
				{
					orig->printTree(PRE_ORDER);
				}
				if(po == 1)
				{
					orig->printTree(IN_ORDER);
				}
				if(po == 2)
				{
					orig->printTree(POST_ORDER);
				}
				if(po == 3)
				{
					Queue* q = new Queue();
					q->enqueue(orig->getRoot());
					orig->printTree(orig->getRoot(), LEVEL_ORDER, q);
				}
			}
		}

		if(sel == 6)
		{
			int val = 0;
			cout<<"enter a value: \n";
			cin >> val;

			Node* temp = orig->search(val);
			cout << temp->getValue() << " = temp val";
			if(temp != nullptr)
			{
				cout <<"val in tree\n";
			}
			else 
			{
				cout<<"val not in tree\n";
			}
		}

	std::cout<<"\n";
}while(sel!=7);
	if(orig != nullptr)
	{
		delete orig;
	}
return(0);
}
