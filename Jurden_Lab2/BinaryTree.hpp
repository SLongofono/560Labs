#include "Node.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <array>
#include <string>


BinaryTree::BinaryTree()
{
	m_root = nullptr;
}

//delete / deconstruct

BinaryTree::~BinaryTree()
{
}

void BinaryTree::printTree()
{
		printTree(m_root);
}

int BinaryTree::getMax(int left, int right)
{
	if(left > right)
	{
		return left;
	}
	else
	{
		return right;
	}
}

void BinaryTree::count()
{
	getCount(m_root);
	std::cout<< "leaf count: " << leafcount <<std::endl;
	leafcount = 0;
}

void BinaryTree::getCount(Node* subtree)
{
	if((subtree->getRight() == nullptr) && (subtree->getLeft() == nullptr))
	{
		leafcount++;
	}
	else
	{
		if(subtree->getRight() != nullptr)
		{
			return getCount(subtree->getRight());
		}
		if(subtree->getLeft() != nullptr)
		{
			return getCount(subtree->getLeft());
		}
	}
}

void BinaryTree::largest()
{
	std::cout<<"largest: " << getLargest(m_root, m_root->getLeft(), m_root->getRight());
}

int BinaryTree::getLargest(Node* subtree, Node* left, Node* right)
{
	int val = subtree->getValue();
	int l = 0;
	int r = 0;
	if(subtree->getLeft() != nullptr)
	{
			l = getLargest(subtree->getLeft(), subtree->getLeft()->getLeft(), subtree->getLeft()->getRight());
	}
	if(subtree->getRight() != nullptr)
	{
			r = getLargest(subtree->getRight(), subtree->getRight()->getLeft(), subtree->getRight()->getRight());
	}
	return getMax(r, getMax(l, val));
}

void BinaryTree::printTree(Node* subtree)
{
	if(subtree==nullptr)
	{
		return;
	}
	else
	{
		printTree(subtree->getLeft());
		std::cout<<subtree->getValue()<<", ";
		printTree(subtree->getRight());
	}
}


Node* BinaryTree::getRoot()
{
	return m_root;
}

void BinaryTree::setRoot(Node* root)
{
	m_root = root;
}

void BinaryTree::build()
{
	  std::ifstream infile;
		infile.open("data.txt");
		int target = 0;
		int numline = 0;
		while (infile.good())
		{
				std::string line;
				std::getline(infile,line);
				numline++;
		}
		infile.close();
		infile.open("data.txt");
		while(!infile.eof() && target <= numline)
		{
				if(m_root == nullptr)
				{
						int x = 0;
						infile >> x;
						Node* rt = new Node();
						rt->setValue(x);
						m_root = rt;
				}
				else
				{
						builder(m_root, target, 0, infile);
						std::cout<< "target " << target <<std::endl;
						target++;
				}
		}
		infile.close();
}


void BinaryTree::builder(Node* subtree, int target, int current, std::ifstream& infile)
{
	if(subtree == nullptr || !infile.good()){
		std::cout<< "return"<< infile.good() <<std::endl;
		return;
	}
	else if(target == current){
			int v1;
			int v2;
			infile >> v1;
			infile >> v2;
			std::cout<< subtree << " is the node "<<std::endl;
			if(v1 != 0)
			{
						std::cout<< "inserting";
						Node* l = new Node();
						l->setValue(v1);
						subtree->setLeft(l);
						std::cout<< v1 <<std::endl;
			}
			if(v2 != 0)
			{
						Node* r = new Node();
						r->setValue(v2);
						subtree->setRight(r);
						std::cout<< "inserting"<<v2 <<std::endl;
			}
	}
	else
	{
					builder(subtree->getLeft(), target, current++, infile);
					builder(subtree->getRight(), target, current++, infile);
	}
}
