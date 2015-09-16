LinkedList::LinkedList()
{
	m_front = nullptr;
	m_back = nullptr;
	m_size = 0;
}

//need to reevaluate this deconstructor depending on how you name variables.
LinkedList::~LinkedList()
{
	Node* temp = m_front;
	Node* next = nullptr;

	while(temp != nullptr)
	{
		next = temp->getNext();
		delete temp;
		m_size--;
		temp = next;
	}
  m_back = nullptr;
}


int LinkedList::size()
{
	return(m_size);
}



bool LinkedList::isEmpty()
{
	return(m_size == 0);
}


void LinkedList::insert(int value)
{
	Node* temp = new Node();
	temp->setValue(value);
	if(m_size==0)
	{
		m_front = temp;
		m_back	= m_front;
	}
	if(m_size>0)
	{
		m_back->setNext(temp);
		temp->setPrev(m_back);
		m_back=temp;
	}
	m_size++;
}


void LinkedList::print()
{
		Node* tempPtr = m_front;
		while(tempPtr != nullptr)
		{
			std::cout<<tempPtr->getValue();
			tempPtr = tempPtr->getNext();
			if(tempPtr != nullptr)
			{
				std::cout<< ",";
			}
		}
}

void LinkedList::erase(int x)
{
	if(find(x)==nullptr){
			std::cout<<"value not in list"<<std::endl;
	}
	else{
		Node* tempN = find(x);
		if(tempN==m_back){
			Node* prev = tempN->getPrev();
			prev->setNext(nullptr);
			m_back = prev;
		}
		else if(tempN == m_front){
			Node* next = tempN->getNext();
			next->setPrev(nullptr);
			m_front = next;
		}
		else{
	  Node* prev = tempN->getPrev();
		Node* next = tempN->getNext();
		next->setPrev(prev);
	  prev->setNext(next);
		}
	  delete tempN;
	  m_size--;
	}
}

Node* LinkedList::find(int x)
{
  Node* temp = m_front;
  while(temp->getValue() != x && temp!= nullptr)
  {
      temp = temp->getNext();
  }

  return(temp);
}

/*
bool LinkedList::operator<< (const Node& rhs) const
{
	return(rhs.getValue());
}
*/
