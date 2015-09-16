#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "Node.h"
#include <queue>
#include <array>
#include <fstream>
#include <iostream>

enum Order{PRE_ORDER,
	IN_ORDER,
	POST_ORDER};

class BinaryTree
{
	public:
		BinaryTree();
		~BinaryTree();
  //  void build()
		void printTree();
		Node* getRoot();
		void setRoot(Node* root);
		int getLargest(Node* subtree, int value);
		void build();
		void builder(Node* subtree, int target, int current, std::ifstream& infile);
		void largest();
		int getLargest(Node* subtree, Node* left, Node* right);
		void count();
		void getCount(Node* subtree);
		int getMax(int left, int right);
		Node* m_root;
		int leafcount;
	private:

		void printTree(Node* subtree);
};
#include "BinaryTree.hpp"
#endif
