#include "Node.h"
#include "Queue.h"
#include <iostream>


BinarySearchTree::BinarySearchTree()
{
	m_root = nullptr;
}

/*
BinarySearchTree::BinarySearchTree(const BinarySearchTree& other)
{
	if(other.m_root == nullptr)
	{
		return;
	}
	else
	{
		this->m_root = new Node(*other.m_root);
	}
}
*/
//delete / deconstruct
//--------------------------------------------------------------

BinarySearchTree::~BinarySearchTree()
{
	deleteTree(m_root);
}

void BinarySearchTree::deleteTree(Node* subtree)
{
	if(subtree == nullptr)
	{
		return;
	}

	deleteTree(subtree->getRight());
	deleteTree(subtree->getLeft());
	delete subtree;
}

void BinarySearchTree::deleteTree()
{
	deleteTree(m_root);
	m_root = nullptr;
}

void BinarySearchTree::remove(int value)
{
		if(search(value) == nullptr)
		{
			std::cout <<"value not in tree\n";
		}
		else {
			Node* del = search(value);
			while(del!= nullptr)
			{
				del = search(value);
				//node has no children
				if(del->getLeft() == nullptr && del->getRight() == nullptr)
				{
					delete del;
				}
				//node has only the left child
				else if (del->getLeft() != nullptr && del->getRight() == nullptr)
				{
					Node* parent = del->getParent();
					if(del == parent->getRight())
					{
						parent->setRight(del->getLeft());
						delete del;
					}
					else if (del == parent->getLeft())
					{
						parent->setLeft(del->getLeft());
						delete del;
					}
				}
				//node has only the right child
				else if(del->getLeft() == nullptr && del->getRight() != nullptr)
				{
					Node* parent = del->getParent();
					if(del == parent->getRight())
					{
						parent->setRight(del->getRight());
						delete del;
					}
					else if (del == parent->getLeft())
					{
						parent->setLeft(del->getRight());
						delete del;
					}
				}
				//node has both children, set node to the minimum value of the right subtree
				else if(del->getLeft() != nullptr && del->getRight() != nullptr)
				{
					Node* min = findMin(del->getRight());
					del->setValue(min->getValue());
					min->getParent()->setLeft(min->getRight());
					//delete min;
				}
				del = search(value);
			}
	}
}

void BinarySearchTree::deleteMax()
{
	Node* max = findMax(m_root);
	int x = max->getValue();
	remove(x);
}

void BinarySearchTree::deleteMin()
{
	Node* min = findMin(m_root);
	int x = min->getValue();
	remove(x);
}
//add
//--------------------------------------------------------------

void BinarySearchTree::add(int value)
{
	if(m_root == nullptr)
	{
		Node* node = new Node();
		node->setValue(value);
		m_root = node;
	}
	else
	{
		add(value, m_root);
	}
}


void BinarySearchTree::add(int value, Node* subtree)
{


	if(value < (subtree->getValue()))
	{

		if(subtree->getLeft() == nullptr)
		{
			Node* temp = new Node();
			temp->setValue(value);
			temp->setParent(subtree);
			subtree->setLeft(temp);
		}
		else
		{
			add(value, subtree->getLeft());
		}

	}

	else if(value >= (subtree->getValue()))
	{

		if(subtree->getRight() == nullptr)
		{
			Node* temp = new Node();
			temp->setValue(value);
			temp->setParent(subtree);
			subtree->setRight(temp);
		}
		else
		{
			add(value, subtree->getRight());
		}

	}
}

//print
//--------------------------------------------------------------
void BinarySearchTree::printTree(Order order)
{

	if(order == PRE_ORDER)
	{
		printTree(m_root, PRE_ORDER);
	}
	else if(order == IN_ORDER)
	{
		printTree(m_root, IN_ORDER);
	}
	else if(order == POST_ORDER)
	{
		printTree(m_root, POST_ORDER);
	}
}


void BinarySearchTree::printTree(Node* subtree, Order order)
{
	if(subtree==nullptr)
	{
		return;
	}
	if(order == PRE_ORDER)
	{
		std::cout<<subtree->getValue()<<", ";
		printTree(subtree->getLeft(), order);
		printTree(subtree->getRight(), order);
	}
	if(order == POST_ORDER)
	{
		printTree(subtree->getLeft(), order);
		printTree(subtree->getRight(), order);
		std::cout<<subtree->getValue()<<", ";
	}
	if(order == IN_ORDER)
	{
		printTree(subtree->getLeft(), order);
		std::cout<<subtree->getValue()<<", ";
		printTree(subtree->getRight(), order );
	}

}

void BinarySearchTree::printTree(Node* subtree, Order order, Queue* q)
{

	if (order == LEVEL_ORDER)
	{
		if(subtree->getLeft()!= nullptr)
		{
			q->enqueue(subtree->getLeft());
		}
		if(subtree->getRight()!= nullptr)
		{
			q->enqueue(subtree->getRight());
		}
		int x = q->dequeue()->getValue();
		std::cout << x << " ";
		while(q->getFront() != nullptr)
		{
		printTree(q->getFront()->getValue(), LEVEL_ORDER, q);
		}
	}
}


Node* BinarySearchTree::getRoot()
{
	return m_root;
}
//search--------------------------------------------------------
//--------------------------------------------------------------


Node* BinarySearchTree::findMin(Node* root)
{
	if(root->getLeft() != nullptr)
	{
			return findMin(root->getLeft());
	}
	else
	{
		return root;
	}
}

Node* BinarySearchTree::findMax(Node* root)
{
	if(root->getRight()!= nullptr)
	{
		return findMax(root->getRight());
	}
	else
	{
		return root;
	}
}
Node* BinarySearchTree::search(int value)
{
	search(value, m_root);
}


Node* BinarySearchTree::search(int value, Node* subtree)
{
	if(subtree == nullptr)
	{
		return nullptr;
	}
	else if(value == subtree->getValue())
	{
		return subtree;
	}
	else if(value < subtree->getValue())
	{
		return search(value, subtree->getLeft());
	}
	else if(value > subtree->getValue())
	{
		return search(value, subtree->getRight());
	}

}
