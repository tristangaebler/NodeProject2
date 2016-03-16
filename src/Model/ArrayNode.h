/*
 * ArrayNode.h
 *
 *  Created on: Jan 29, 2016
 *      Author: tgae6529
 */

#ifndef MODEL_ARRAYNODE_H_
#define MODEL_ARRAYNODE_H_

#include "Node.h"

template <class Type>
class ArrayNode: public Node<Type> { //Parent is always at the end
private:
	ArrayNode * next;
public:
	ArrayNode(); //Regular constructor
	ArrayNode(const Type& value);
	ArrayNode(const Type& value, ArrayNode * next);
	virtual ~ArrayNode();
	ArrayNode * getNext();
	void setNext(ArrayNode * next);
};

#endif /* MODEL_ARRAYNODE_H_ */
