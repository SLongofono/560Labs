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
		int getRank();
		void setValue(int value);
		void setLeft(Node* left);
		void setRight(Node* right);
		void setRank(int rank);

	private:
		Node* m_left;
		Node* m_right;
		int m_value;
		int m_rank;

};
#include "Node.hpp"
#endif
