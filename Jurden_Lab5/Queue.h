#ifndef QUEUE_H
#define QUEUE_H

#include "QueueInterface.h"
#include "BoxOfAnything.h"
#include "PreconditionViolationException.h"
#include <stdexcept>

template<typename T>
class Queue : public QueueInterface<T>
{
	public:
		/**
		*  @pre queue with values
		*  @post while queue has values, dequeues 
		*  @return none
		*/
		~Queue();

		/**
		*  @pre None
		*  @post assigns member variables to 0 and nullptr
		*  @return constructed queue
		*/
		Queue();	

		/**
		*  @pre None
		*  @post reads size member variable
		*  @return true if empty, false if not
		*/	
		 bool isEmpty() const;

		/**
		*  @pre takes in user entered value
		*  @post adds item containing value to the queue 
		*  @return none
		*/
		 void enqueue(const T newEntry);

		/**
		*  @pre queue must have at least one item
		*  @post removes item from front of queue
		*  @return value of item removed
		*  @throws PVE if queue is empty
		*/
		T dequeue() throw(PreconditionViolationException);

		/**
		*  @pre queue must have at least one item
		*  @post reads value of item at front of queue
		*  @return value of item at front of queue
		*  @throws PVE if queue is empty
		*/
		T peekFront() const throw(PreconditionViolationException);

		/**
		*  @pre None
		*  @post gets the size member variable
		*  @return value of size member variable
		*/
		 int size() const;

		/**
		*  @pre none
		*  @post prints values of all items in the queue in order
		*  @return none
		*/
		 void print() const;

		/**
		*  @pre None
		*  @post overrides < operator 
		*  @return comparison of size and rhs.size
		*/
		 bool operator< (const QueueInterface<T>& rhs)const;

		/**
		*  @pre None
		*  @post overrides <= operator 
		*  @return comparison of size and rhs.size
		*/
		 bool operator<= (const QueueInterface<T>& rhs) const;

		/**
		*  @pre None
		*  @post overrides > operator 
		*  @return comparison of size and rhs.size
		*/
		 bool operator> (const QueueInterface<T>& rhs) const;

		/**
		*  @pre None
		*  @post overrides >= operator 
		*  @return comparison of size and rhs.size
		*/
		 bool operator>= (const QueueInterface<T>& rhs) const;

		/**
		*  @pre None
		*  @post overrides == operator 
		*  @return comparison of size and rhs.size
		*/
		 bool operator== (const QueueInterface<T>& rhs) const;

		/**
		*  @pre None
		*  @post overrides != operator 
		*  @return comparison of size and rhs.size
		*/
		 bool operator!= (const QueueInterface<T>& rhs) const;
	private:
		int m_size;
		BoxOfAnything<T>* m_last;
		BoxOfAnything<T>* m_first;
};

#include "Queue.hpp"
#endif

