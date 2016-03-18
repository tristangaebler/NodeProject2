/*
 * ArrayNode.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: Tristan Gaebler
 */

#include "ArrayNode.h"
#include "Node.h"

/*
 * ArrayNode method with a template of class Type. That part is still confusing. This points to next which eqauls a nullPointer.
 */
template <class Type>
ArrayNode<Type>::ArrayNode() : Node<Type>(){

	this->next = nullptr;

}
/*
 * ArrayNode Method that returns type. Has a template <class Type>. This points to value which is assigned to value. This points to next which is assigned to nullPointer.
 */
template <class Type>
ArrayNode<Type>::ArrayNode(const Type& value) : Node<Type>(value) {

	this->next = nullptr;
    this->setValue(value);
}

/*
 * ArrayNode Method that returns type. Takes value and next pointer as a parameter. This points to value which is assigned to value. This points to next which is assigned to nullPointer.
 */
template <class Type>
ArrayNode<Type>::ArrayNode(const Type& value, ArrayNode * next) : Node<Type>(value) {

	this->value = value;
	this->next = next;
}

/*
 * The ArrayNode destructor. Nothing currently in it.
 */
template <class Type>
ArrayNode<Type>::~ArrayNode() {
	// TODO Auto-generated destructor stub
}

template <class Type>
void ArrayNode<Type> :: setNext(ArrayNode<Type> * next) {
    this->next = next;
}

template <class Type>
ArrayNode<Type> * ArrayNode<Type> :: getNext() {
	return this->next;
}
