/*
 * CTECList.cpp
 *
 *  	Date: March 14, 2016
 *      Author: Tristan Gaebler
 *     version: 0.7
 */

#include "CTECList.h"
#include <assert.h>
#include <iostream>

using namespace std;

template<class Type>
CTECList<Type>::CTECList()
{
	this->size = 0;
	this->head = nullptr;
	this->end = nullptr;
}


template<class Type>
CTECList<Type>::~CTECList()
{

	 // Start at head
	 // Loop over nodes
	 // update position
	 // Delete Final
	 //Assign default

	ArrayNode<Type>* current = head;

	while (current->getNext() != nullptr)
	{
		ArrayNode<Type>* temp = current;

		current = current->getNext();
		head = current;
		delete temp;
	}

	delete head;
	head = nullptr;
	end = nullptr;
	size = 0;
}


template<class Type>
int CTECList<Type>::getSize()
{
	this->calculateSize();
	return this->size;
}


template<class Type>
Type CTECList<Type>::getFront()
{
	return head->getValue();
}


template<class Type>
Type CTECList<Type>::getEnd()
{
	return end->getValue();
}


template<class Type>
Type CTECList<Type>::getAtIndex(int index)
{
	assert(index > size || index < 0);
	ArrayNode<Type>* current = head;

	for (int i = 0; i < index - 1; i++)
	{
		current = current->getNext();
	}

	return current->getValue();
}


template<class Type>
void CTECList<Type>::set(int index, const Type& value)
{

	assert(index < size && index >= 0);

	ArrayNode<Type> * current = head;
	for (int spot = 0; spot <= index; spot++)
	{
		if (spot != index)
		{
			current = current->getNext();
		}
		else
		{
			return current->setValue(value);
		}
	}
}


template<class Type>
void CTECList<Type>::addToFront(const Type& value)
{
	ArrayNode<Type>* newNode = new ArrayNode<Type>(value);

	if (head == nullptr)
	{
		newNode->setNext(nullptr);
		head = newNode;
		end = newNode;
	}
	else
	{
		newNode->setNext(head);
		head = newNode;
	}
	calculateSize();
}


template<class Type>
void CTECList<Type>::addToEnd(const Type& value)
{
	ArrayNode<Type>* newNode = new ArrayNode<Type>(value);
	ArrayNode<Type>* current = head;

	if (current->getNext() == nullptr)
	{
		current->setNext(newNode);
		newNode->setNext(nullptr);
		end = newNode;
	}
	else
	{
		while(current->getNext() != nullptr)
		{
			current = current->getNext();
		}
		current->setNext(newNode);
		newNode->setNext(nullptr);
		end = newNode;
	}
	calculateSize();
}


template<class Type>
void CTECList<Type>::addAtIndex(int index, const Type& value)
{
	ArrayNode<Type>* newNode = new ArrayNode<Type>(value);
	ArrayNode<Type>* current = head;
	ArrayNode<Type>* previous = current;

	assert(index <= size && index >= 0);

	if (index == 0)
	{
		addFront(value);
	}
	else if(index == size)
	{
		addEnd(value);
	}
	else
	{
		for(int i = 0; i < index; i++)
		{
			previous = current;
			current = current->getNext();
		}
		previous->setNext(newNode);
		newNode->setNext(current);
	}

	calculateSize();
}


template<class Type>
Type CTECList<Type>::removeFront()
{

	ArrayNode<Type>* newHead = new ArrayNode<Type>();
	Type thing;
	newHead = this->head->getNext();
	thing = this->head->getValue();
	delete this->head;
	this->head = newHead;

	size--;

	this->calculateSize();
	return thing;
}


template<class Type>
Type CTECList<Type>::removeEnd()
{

	assert(size > 0);

	ArrayNode<Type>* previous;
	ArrayNode<Type>* toDelete;
	ArrayNode<Type>* current = head;
	Type thing;

	if (current->getNext() == nullptr)
	{
		toDelete = current;
		thing = toDelete->getValue();
		delete toDelete;
		end = nullptr;
	}
	else
	{
		while(current->getNext() != nullptr)
		{
			previous = current;
			current = current->getNext();
		}
		toDelete = current;
		thing = toDelete->getValue();
		delete toDelete;
		previous->setNext() = nullptr;
		end = previous;
	}

	this->calculateSize();
	return thing;
}

/*
 * Declare all of the nessacary nodes
 * assert
 * find the proper index that matches the input
 * remove the node at index
 */
template<class Type>
Type CTECList<Type>::removeAtIndex(int index)
{
	ArrayNode<Type>* previous;
	ArrayNode<Type>* toDelete;
	ArrayNode<Type>* newNext;
	ArrayNode<Type>* current = head;
	Type thing;

	assert(this->size > 0);
	assert(index > 0 || index <= size);

	if (index == 0)
	{
		thing = removeFront();
	}
	else if (index == size - 1)
	{
		thing = removeEnd();
	}
	else
	{

		for (int i = 0; i < index; i++)
		{
			if (i == index - 1)
			{
				previous = current;
			}
			else if (i == index)
			{
				toDelete = current;
				thing = toDelete->getValue();
				newNext = current->getNext();
				delete toDelete;
				previous->setNext(newNext);
			}
			current = current->next();
		}
	}

	this->calculateSize();
	return thing;
}


template<class Type>
void CTECList<Type>::calculateSize()
{
	assert(size >= 0);

	ArrayNode<Type>* counterPointer = head;
	int count = 0;

	if (counterPointer == nullptr)
	{
		this->size = 0;
		return;
	}
	else
	{
		count++;
		while(counterPointer->getNext() != nullptr)
		{
			counterPointer = counterPointer->getNext();
			count++;
		}

		this->size = count;
	}
}

