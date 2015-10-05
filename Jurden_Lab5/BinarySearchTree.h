#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "Node.h"
#include "Queue.h"


enum Order{PRE_ORDER,
	IN_ORDER,
	POST_ORDER,
	LEVEL_ORDER};

class BinarySearchTree
{
	public:
		BinarySearchTree();
		//BinarySearchTree(const BinarySearchTree& other);
		~BinarySearchTree();
		void add(int value);
		void add(int value, Node* subtree);
		void printTree(Order order);
		void printTree(Node* subtree, Order order, Queue* q);
		Node* search(int value);
		Node* search(int value, Node* subtree);
		Node* getRoot();
		void deleteTree();
		void remove(int value);
		void deleteMin();
		void deleteMax();
		Node* findMin(Node* root);
		Node* findMax(Node* root);
	private:
		Node* m_root;
		void deleteTree(Node* subtree);
		
		void printTree(Node* subtree, Order order);
};
#include "BinarySearchTree.hpp"
#endif
