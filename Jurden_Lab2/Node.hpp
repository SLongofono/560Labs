
Node::Node()
{
	m_left = nullptr;
	m_right = nullptr;
	m_value = 0;
}

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
