#include <iostream>
#include <queue>
#include <random>
#include "BinarySearchTree.h"
#include "Node.h"

void printMenu()
{
std::cout<<"Input a selection:"<<std::endl;
std::cout<<"1) Add more values to original tree"<<std::endl;
std::cout<<"2) Copy the original tree"<<std::endl;
std::cout<<"3) Delete the original tree (one time only)"<<std::endl;
std::cout<<"4) Print the original tree"<<std::endl;
std::cout<<"5) Print copy"<<std::endl;
std::cout<<"6) Search original tree"<<std::endl;
std::cout<<"7) Search copy"<<std::endl;
std::cout<<"8) Exit"<<std::endl;
std::cout<<"Your choice: "<<std::endl;
}

int main(int argc, char** argv)
{
	BinarySearchTree<int>* orig = new BinarySearchTree<int>();
	BinarySearchTree<int>* copy = new BinarySearchTree<int>(*orig);
	
	//noder(orig);
	int nodes = std::stoi(argv[1]);
	static std::default_random_engine generator(time(nullptr));
	static std::uniform_int_distribution<int> distribution(0, 999);
	std::cout<<"Arg Count:"<< argc <<std::endl;
	std::cout<<"Node Count:" << nodes<<std::endl;
	if(nodes < 1)//how do we output this before it begins?
	{
		std::cout<<"Number of nodes must be greater than one!\n";
	}
	else
	{
		for(int i = 0; i<nodes;i++)
		{		
			int addint = distribution(generator);		
			orig->add(addint);
			std::cout<<"Adding "<<addint<<" to the original tree\n"; 
		}
		std::cout<<"\n";
	}

	int sel;
	do{
		printMenu();
		std::cin>>sel;
		std::cout<<"You chose: "<<sel<<"\n";
		if(sel==1)
		{
			if(orig->getRoot() == nullptr)
			{	
				std::cout<<"Original tree doesnt exist.\n";
			}		
			else{				
				int val;
				std::cout<<"Input a value to add to the original\n";
				std::cin>>val;
				orig->add(val);
				std::cout<<"Adding "<<val<<" to the original tree.\n";
			}
		}

		if(sel==2)
		{
			
			if(orig->getRoot() == nullptr)
			{
				std::cout<<"Tree doesnt exist \n";
			}
			else if(copy->getRoot()== nullptr)
			{
				delete copy;
				std::cout<<"Original tree copied\n";
				copy = new BinarySearchTree<int>(*orig);
			}
			else if(copy->getRoot() != nullptr)
			{
				delete copy;
				std::cout<<"Original tree copied\n";
				copy = new BinarySearchTree<int>(*orig);
			}
		}

		if(sel==3)
		{
			orig->deleteTree();			
		}

		if(sel==4)

		{
			int po;			
			std::cout<<"Print order options:\n";
			std::cout<<"\t0 - pre-order\n\t1 - in-order\n\t2 - post-order\n";
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
			}
		}

		if(sel==5)
		{
			int po;			
			std::cout<<"Print order options:\n";
			std::cout<<"\t0 - pre-order\n\t1 - in-order\n\t2 - post-order\n";
			std::cin>>po;
			s the characters representing the maze are storedtd::cout<<"Choice: "<<po<<"\n";
			if(copy->getRoot() != nullptr)
			{
				if(po == 0)
				{	
					copy->printTree(PRE_ORDER);
				}	
				if(po == 1)
				{	
					copy->printTree(IN_ORDER);
				}	
				if(po == 2)
				{	
					copy->printTree(POST_ORDER);
				}
			}
		}

		if(sel==6)
		{
			int value;
			std::cout<<"Enter value you want to search for: ";
			std::cin>>value;
			Node<int>* searchNode = orig->search(value);
			if(orig->getRoot() == nullptr)
			{
				std::cout<<"tree does not exist\n";
			}

			else if(searchNode == nullptr)
			{
				std::cout<<value<<" is not in the tree.\n";	
			}

			else if(searchNode->getValue() == value)
			{
				std::cout<<value<<" is in the tree.\n";
			}	
		}

		if(sel==7)
		{
			int value;
			std::cout<<"Enter value you want to search for: ";
			std::cin>>value;
			Node<int>* searchCopy = copy->search(value);
			if(copy->getRoot() == nullptr)
			{
				std::cout<<"tree does not exist\n";
			}

			else if(searchCopy == nullptr)
			{
				std::cout<<value<<" is not in the tree.\n";	
			}

			else if(searchCopy->getValue() == value)
			{
				std::cout<<value<<" is in the tree.\n";
			}	
		}
	std::cout<<"\n";
	}while(sel!=8);
	if(copy!=nullptr)
	{
		delete copy;
	}
	if(orig != nullptr)
	{
		delete orig;
	}
return(0);
}
