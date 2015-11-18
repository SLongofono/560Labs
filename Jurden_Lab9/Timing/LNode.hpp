
LNode::LNode()
{
	left = nullptr;
	right = nullptr;
	value = 0;
	m_rank = 0;
}

int LNode::getRank()
{
		return m_rank;
}


void LNode::setRank(int rank)
{
	m_rank = rank;
}
