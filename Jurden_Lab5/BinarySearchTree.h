#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "Node.h"
#include <queue>

enum Order{PRE_ORDER,
	IN_ORDER,
	POST_ORDER};

template <typename T>
class BinarySearchTree
{
	public:
		BinarySearchTree();

		/**
		*	@pre checks to see if copy's m_root is nullptr
		*	@post calls node deep copy method 
		*	
		*/
		BinarySearchTree(const BinarySearchTree<T>& other);

		/**
		*	@post deletes BST
		*	@return none
		*/
		~BinarySearchTree();

		/**
		*	@pre  
		*	@post if m_root is nullptr creates a node assigns to m_root, if not calls private add
		*	@return none
		*/
		void add(T value);

		/**
		*	
		*	@post calls private print tree and passes order and m_root
		*	@return 
		*/
		void printTree(Order order);

		/**
		*	
		*	@post passes in root and value to search for to private search
		*	@return node 
		*/
		Node<T>* search(T value);

		/*
		*	@return m_root
		*/
		Node<T>* getRoot();

		/**
		*	calls private delete tree and passes in root
		*/
		void deleteTree();
	private:
		Node<T>* m_root;

		/**
		*	@pre root not nullptr
		*	@post compares values to subtrees, adds accordingly
		*	@return none
		*/
		void add(T value, Node<T>* subtree);

		/**
		*	@pre none
		*	@post deletes tree from subtree down
		*	@return none
		*/
		void deleteTree(Node<T>* subtree);

		/**
		*	@pre non null tree
		*	@post searches for values
		*	@return nullptr or node with value depending on comparison
		*/
		Node<T>* search(T value, Node<T>* subtree);

		/**
		*	@pre 
		*	@post prints tree according to order
		*	@return none
		*/
		void printTree(Node<T>* subtree, Order order);

		
		
};
#include "BinarySearchTree.hpp"
#endif
