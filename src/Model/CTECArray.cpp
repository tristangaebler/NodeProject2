/*
 * CTECArray.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: tgae6529
 */

#include "CTECArray.h"
#include <assert.h>
#include <iostream>

using namespace std;

template<class Type>
CTECArray<Type>::CTECArray(int size) {

	this->size = size;
	this->head = nullptr;

	assert(size > 0);

	for (int index = 0; index < size; index++) {
		if (head != nullptr) {
			//We have more than one arrayNode
			ArrayNode<Type> * nextNode = new ArrayNode<Type>();
			nextNode->setNext(head);
			head = nextNode;
		} else {
			//this is the first in the array
			ArrayNode<Type> * first = new ArrayNode<Type>();
			head = first;
		}
	}

}

template<class Type>
CTECArray<Type>::~CTECArray() {
	ArrayNode<Type> * deleteMe = head;
	for (int index = 0; index < size; index++) {
		if (deleteMe->getNext() != nullptr) {
			head = deleteMe->getNext();
			deleteMe->setNext(nullptr);
		}
		else {
			delete deleteMe->getNext();
			deleteMe = head;
		}
	}
	delete head;
}

template<class Type>
int CTECArray<Type>::getSize() {
	return this->size;
}

template<class Type>
Type CTECArray<Type>::get(int position) {

	assert(position < size && position >= 0); //inclusive check

	ArrayNode<Type> * current = head;
	//Inclusive becase I am inside the bounds :)>
	for (int spot = 0; spot <= position; spot++) { //inclusive check

		if (spot != position) {
			current = current->getNext();
		} else {
			return current->getValue();
		}
	}
    return current->getValue();
}
template<class Type>
void CTECArray<Type>::set(int position, const Type& value) {
	assert(position < size && position >= 0);

	ArrayNode<Type> * current = head;
	for (int spot = 0; spot <= position; spot++) {
		if (spot != position) {
			current = current->getNext();
		} else {
			current->setValue(value);
		}
	}
}

/*
 1)Assert ze is > 0
 2)Declare and init valid return variable
 3)Reference to head and loop
 4)If there, return index, else go to next
 5)Return index
 */
template <class Type>
int CTECArray<Type>::indexOf(Type searchValue){
 
    assert(size > 0);
    
    int indexNotFound = -1;
    ArrayNode<Type> * current = head;
    
    for(int index = 0; index < size; index++) {
        if(current->getValue() == searchValue) {
            return index;
        } else {
            current = current -> getNext();
        }
    }
    return indexNotFound;
}

template <class Type>
int CTECArray<Type>::nextIndexOf(int startingIndex, Type searchValue){
    
    assert(size > 0);
    
    assert(startingIndex >= 0 && startingIndex < this->size);
    
    int indexNotFound = -1;
    ArrayNode<Type> * current = head;
    
    for(int index = 0; index < startingIndex; index++) {
        current = current->getNext();
    }
    
    for(int index = startingIndex; index < size; index++) {
        if(current->getValue() == searchValue) {
            return index;
        } else {
            current = current -> getNext();
        }
    }
    return indexNotFound;
}

template <class Type>
void CTECArray<Type>::swap(int indexOne, int indexTwo)
{
    assert(indexOne < size && indexTwo < size);
    ArrayNode<Type> * first = get(indexOne);
    ArrayNode<Type> * second = get(indexTwo);
    ArrayNode<Type> * temp = new ArrayNode<Type>();
    
    temp->setValue(first->getValue());
    first->setValue(second->getValue());
    second->setValue(temp->getValue());
    
    delete temp;
    
}

template <class Type>
void CTECArray<Type>::selectionSort()
{
    int innerLoop, outerLoop;
    for(outerLoop = 0; outerLoop < this->size()-1; outerLoop++)
    {
        int selectMin = outerLoop;
        for(innerLoop = outerLoop + 1; innerLoop < size; innerLoop++)
        {
            if(get(innerLoop) < get(selectMin))
            {
                selectMin = innerLoop;
            }
        }
        
        if(selectMin != outerLoop)
        {
            swap(outerLoop, selectMin);
        }
    }
}










