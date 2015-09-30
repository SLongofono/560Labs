#ifndef NODE_H
#define NODE_H

class Node
{
	public:
		Node();
		//Node(const Node& other);
		int getValue();
		Node* getLeft();
		Node* getRight();
		Node* getParent();
		void setValue(int value);
		void setLeft(Node* left);
		void setRight(Node* right);
		void setParent(Node* parent);

	private:
		Node* m_left;
		Node* m_right;
		Node* m_parent;
		int m_value;

};
#include "Node.hpp"
#endif
