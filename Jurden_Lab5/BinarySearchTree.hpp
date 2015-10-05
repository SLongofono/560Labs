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

void BinarySearchTree::removeV(int value)
{
	Node* del = search(value, m_root);
	if(del == nullptr)
	{
		std::cout <<"value not in tree or tree is empty\n";
	}
	else
	{
		while(del != nullptr)
		{
			remove(del);
			del = search(value, m_root);
		}
	}
}
void BinarySearchTree::remove(Node* del)
{
				//node has no children
				if(del->getLeft() == nullptr && del->getRight() == nullptr)
				{
					Node* parent = del->getParent();
					if(parent == nullptr)
					{
						std::cout<<"tree is empty";
						delete del;
					}
					else if(del == parent->getRight())
					{
						parent->setRight(nullptr);
						delete del;
					}
					else if (del == parent->getLeft())
					{
						parent->setLeft(nullptr);
						delete del;
					}

				}
				//node has only the left child
				else if (del->getLeft() != nullptr && del->getRight() == nullptr)
				{
					//Node* parent = del->getParent();
					if (del == m_root)
					{
						m_root = del->getLeft();
						del->getLeft()->setParent(nullptr);
						delete del;
					}
					else if(del == del->getParent()->getRight())
					{
						del->getParent()->setRight(del->getLeft());
						del->getLeft()->setParent(del->getParent());
						delete del;
					}
					else if (del == del->getParent()->getLeft())
					{
						del->getParent()->setLeft(del->getLeft());
						del->getLeft()->setParent(del->getParent());
						delete del;
					}

					
				}
				//node has only the right child
				else if(del->getLeft() == nullptr && del->getRight() != nullptr)
				{
					//Node* parent = del->getParent();
					if (del == m_root)
					{
						m_root = del->getRight();
						del->getRight()->setParent(nullptr);
						delete del;
					}
					else if(del == del->getParent()->getRight())
					{
						del->getParent()->setRight(del->getRight());
						del->getRight()->setParent(del->getParent());
						delete del;
					}
					else if (del == del->getParent()->getLeft())
					{
						del->getParent()->setLeft(del->getRight());
						del->getRight()->setParent(del->getParent());
						delete del;
					}
				}
				//node has both children, set node to the minimum value of the right subtree
				else if(del->getLeft() != nullptr && del->getRight() != nullptr)
				{
					Node* min = findMin(del->getRight());
					std::cout<<"min value of right subtree: "<<min->getValue()<<std::endl;
					if(del == m_root)
					{
						std::cout<<"del is root\n";
						m_root = min;
						min->setLeft(del->getLeft());
						min->setParent(nullptr);
						delete del;
					}
					else
					{
						del->setValue(min->getValue());
						remove(min);
					}
				/*
				if(del == nullptr)
				{
					return;
				}
				else
				{
					remove(value);
				}	*/
	}
}

void BinarySearchTree::deleteMax()
{
	Node* max = findMax(m_root);
	int x = max->getValue();
	removeV(x);
}

void BinarySearchTree::deleteMin()
{
	Node* min = findMin(m_root);
	int x = min->getValue();
	removeV(x);
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
		m_root->setParent(nullptr);
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
			subtree->setLeft(temp);
			temp->setParent(subtree);
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
	return search(value, m_root);
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
	else if(value >= subtree->getValue())
	{
		return search(value, subtree->getRight());
	}

}
