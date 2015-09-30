
//do i need to define destructor for queueinterface?

#include<stdexcept>
template<typename T>
bool Queue<T>::isEmpty() const //why is <T> needed in queue before ::
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
template<typename T>
Queue<T>::Queue()
{
	this->m_size = 0;
	this->m_first = nullptr;
	this->m_last = nullptr;
}

template<typename T>
Queue<T>::~Queue()
{
	while(m_first!=nullptr)
	{
		this->dequeue();
	}
}
template<typename T>
void Queue<T>::enqueue(const T newEntry)
{
	BoxOfAnything<T>* temp = new BoxOfAnything<T>(newEntry);
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

template<typename T>
T Queue<T>::dequeue() throw(PreconditionViolationException)
{
	if(m_first==nullptr)
	{	
		throw(PreconditionViolationException("Dequeue attempted on empty queue"));
	}
	else
	{
		BoxOfAnything<T>* temp = m_first;
		T s = m_first->getValue();
		m_first = temp->getNext();
		m_size = m_size - 1;
		delete temp;
		return(s);
	}
}

template<typename T>
T Queue<T>::peekFront() const  throw(PreconditionViolationException)
{
	if(m_first==nullptr)
	{
		throw(PreconditionViolationException("Peek attempted on an empty queue"));
	}
	else
	{
		return(m_first->getValue());
	}
}

template<typename T>
int Queue<T>::size() const
{
	return(this->m_size);
}

template<typename T>
void Queue<T>::print() const
{
	if(m_first==nullptr)
	{
		std::cout<<"Queue Empty"<<std::endl;
	}
	else
	{
		BoxOfAnything<T>* temp = m_first;
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

template<typename T>
bool Queue<T>::operator< (const QueueInterface<T>& rhs) const
{
	return(this->size() < rhs.size());
}

template<typename T>
bool Queue<T>::operator<= (const QueueInterface<T>& rhs) const
{
	return(this->size() <= rhs.size());
}

template<typename T>
bool Queue<T>::operator> (const QueueInterface<T>& rhs) const
{
	return(this->size() > rhs.size());
}

template<typename T>
bool Queue<T>::operator>= (const QueueInterface<T>& rhs) const
{
	return(this->size() >= rhs.size());
}

template<typename T>
bool Queue<T>::operator== (const QueueInterface<T>& rhs) const
{
	return(this->size() == rhs.size());
}

template<typename T>
bool Queue<T>::operator!= (const QueueInterface<T>& rhs) const
{
	return(this->size() != rhs.size());
}

