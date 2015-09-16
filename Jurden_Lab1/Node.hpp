
Node::Node()
{
	m_next = nullptr;
	m_prev = nullptr;
	m_value = 0;
}



int Node::getValue()
{
	return(m_value);
}


void Node::setValue(int value)
{
	m_value = value;
}


Node* Node::getNext()
{
	return(m_next);
}


void Node::setNext(Node* next)
{
	m_next = next;
}


Node* Node::getPrev()
{
	return(m_prev);
}



void Node::setPrev(Node* prev)
{
	m_prev = prev;
}
