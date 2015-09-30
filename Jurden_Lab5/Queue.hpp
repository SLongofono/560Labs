
//do i need to define destructor for queueinterface?

#include<stdexcept>

bool Queue::isEmpty() const //why is <T> needed in queue before ::
{
	if(m_size==0)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

Queue::Queue()
{
	this->m_size = 0;
	this->m_first = nullptr;
	this->m_last = nullptr;
}


Queue::~Queue()
{
	while(m_first!=nullptr)
	{
		this->dequeue();
	}
}

void Queue::enqueue(const T newEntry)
{
	BoxOfAnything* temp = new BoxOfAnything(newEntry);
	if(m_size==0)
	{
		this->m_first= temp;
		this->m_last= temp;
		m_first->setNext(nullptr);
	}
	else
	{
		m_last->setNext(temp);
		this->m_last = temp;
		m_last->setNext(nullptr);
	}
	m_size = m_size + 1;
}


Node* Queue::dequeue() throw(PreconditionViolationException)
{
	if(m_first==nullptr)
	{
		throw(PreconditionViolationException("Dequeue attempted on empty queue"));
	}
	else
	{
		BoxOfAnything* temp = m_first;
		T s = m_first->getValue();
		m_first = temp->getNext();
		m_size = m_size - 1;
		delete temp;
		return(s);
	}
}


BoxOfAnything* Queue::getFront() const  throw(PreconditionViolationException)
{
	if(m_first==nullptr)
	{
		throw(PreconditionViolationException("empty queue"));
	}
	else
	{
		return(m_first);
	}
}


int Queue::size() const
{
	return(this->m_size);
}


void Queue::print() const
{
	if(m_first==nullptr)
	{
		std::cout<<"Queue Empty"<<std::endl;
	}
	else
	{
		BoxOfAnything* temp = m_first;
		while(temp!= nullptr)
		{
			if(temp->getNext()==nullptr)
			{
				std::cout<<temp->getValue();
			}
			else
			{
				std::cout<<temp->getValue()<<", ";
			}
			temp = temp->getNext();
		}
		std::cout<<"\n";
	}
}
