
Node::Node()
{
	m_left = nullptr;
	m_right = nullptr;
	m_parent = nullptr;
	m_value = 0;
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

int Node::getValue()
{
	return m_value;
}


Node* Node::getLeft()
{
	return m_left;
}


Node* Node::getRight()
{
	return m_right;
}

Node* Node::getParent()
{
		return m_parent;
}

void Node::setValue(int value)
{
	m_value = value;
}


void Node::setLeft(Node* left)
{
	m_left = left;
}


void Node::setRight(Node* right)
{
	m_right = right;
}

void Node::setParent(Node* parent)
{
	m_parent = parent;
}
