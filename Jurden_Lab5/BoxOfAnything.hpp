/*
*	@file : BoxOfAnything.hpp
*	@author : Nicholas Jurden
*	@date : 9/30/14
*	Purpose: Implementation file of BoxOfAnything class
*/
#import "Node.h"

BoxOfAnything::BoxOfAnything(Node* value)
{
	this->m_next = nullptr;
	this->m_value = value;
}


Node* BoxOfAnything::getValue()
{
	return(m_value);
}


BoxOfAnything* BoxOfAnything::getNext()
{
	return(m_next);
}


void BoxOfAnything::setValue(Node* value)
{
	this->m_value = value;
}


void BoxOfAnything::setNext(BoxOfAnything* next)
{
	this->m_next = next;
}
