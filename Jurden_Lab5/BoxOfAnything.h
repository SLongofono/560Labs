/*
*	@file : BoxOfAnything.h
*	@author : Nicholas Jurden
*	@date : 9/30/14
*	Purpose: Header file of BoxofAnything class
*/


#ifndef BOX_OF_ANYTHING_H
#define	BOX_OF_ANYTHING_H

#include "Node.h"

class BoxOfAnything
{
	public:
		/**
		*  @pre None
		*  @post create and initialize a boxofanything with a value
		*  @return  initialized boxofanything
		*/
		BoxOfAnything(Node* value);

		/**
		*  @pre None
		*  @post get previous boxofanything
		*  @return  previous boxofanything
		*/
		BoxOfAnything* getNext();

		/**
		*  @pre None
		*  @post reads the value in boxofanything
		*  @return  value of boxofanything
		*/
		Node* getValue();

		/**
		*  @pre None
		*  @post set boxofanythings value
		*  @return  boxofanything with new value
		*/
		void setValue(Node* value);

		/**
		*  @pre None
		*  @post sets boxofanything to previous boxofanything
		*  @return  none
		*/
		void setNext(BoxOfAnything* next);

	private:
		BoxOfAnything* m_next;

		Node* m_value;
};

#include "BoxOfAnything.hpp"
#endif
