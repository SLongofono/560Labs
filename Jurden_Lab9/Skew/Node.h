#ifndef NODE_H
#define NODE_H

class Node
{
	public:
		Node();
		//Node(const Node& other);
		int getRank();
		void setRank(int rank);
		Node* left;
		Node* right;
		int value;
	private:

		int m_rank;

};
#include "Node.hpp"
#endif
