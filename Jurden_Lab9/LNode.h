#ifndef LNode_H
#define LNode_H

class LNode
{
	public:
		LNode();
		//LNode(const LNode& other);
		int getRank();
		void setRank(int rank);
		LNode* left;
		LNode* right;
		int value;
	private:

		int m_rank;

};
#include "LNode.hpp"
#endif
