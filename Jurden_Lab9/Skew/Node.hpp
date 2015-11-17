
Node::Node()
{
	left = nullptr;
	right = nullptr;
	value = 0;
	m_rank = 0;
}

/*
Node::Node(const Node& other)
{
	this->m_left = nullptr;
	this->m_right = nullptr;
	this->m_value = other.m_value;
	if(other.m_left != nullptr)
	{
		this->m_left = new Node(*other.m_left);
	}
	if(other.m_right != nullptr)
	{
		this->m_right = new Node(*other.m_right);
	}
}
*/
int Node::getRank()
{
		return m_rank;
}


void Node::setRank(int rank)
{
	m_rank = rank;
}
