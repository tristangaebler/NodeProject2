//
//  HashTable.cpp
//  NodeProject2
//
//  Created by Gaebler, Tristan on 5/5/16.
//  Copyright © 2016 Gaebler, Tristan. All rights reserved.
//

#include "HashTable.hpp"
#include <CMath>
using namespace CTECData;

template <class Type>
HashTable<Type>::HashTable()
{
    this->capacity = 10;
    this->efficiencyPercentage = .667;
    this->size = 0;
    this->internalStorage = new HashNode<Type>[capacity];
}

template <class Type>
int HashTable<Type>::getSize()
{
    return this->size;
}

template <class Type>
HashTable<Type>::~HashTable<Type>()
{
    delete [] internalStorage;
}

template <class Type>
void HashTable<Type>::add(HashNode<Type> * currentNode)
{
    if(!conatins(currentNode))
    {
        if(this->size/this->capacity >= this->efficiencyPercentage)
        {
            updateSize();
        }
        int insertPosition = findPosition(currentNode);
        
        if(internalStorage[insertPosition] != nullptr)
        {
            while (internalStorage[insertPosition] != nullptr)
            {
                insertPosition = (insertPosition + 1) % capacity;
            }
            internalStorage[insertPosition] = currentNode;
        }
        else
        {
            internalStorage[insertPosition] = currentNode;
        }
    }
}

template <class Type>
int HashTable<Type>::findPosition(HashNode<Type> currentNode)
{
    int position = 0;
    
    position = currentNode.getKey() % capacity;
    
    return position;
}


template <class Type>
int HashTable<Type>::getNextPrime()
{
    int nextPrime = (capacity * 2) + 1;
    
    while(!isPrime(nextPrime))
    {
        nextPrime++;
    }
    
    return nextPrime;
}

template <class Type>
void HashTable<Type>::updateSize()
{
    int updatedCapacity = getNextPrime();
    HashTable<Type> * updatedStorage = new HashTable<Type> [updatedCapacity];
    int oldCapacity = capacity;
    capacity = updatedCapacity;
    for(int index = 0; index < oldCapacity; index++)
    {
        if(internalStorage[index] != nullptr)
        {
            int updatedPosition = findPosition(internalStorage[index]);
            updatedStorage[updatedPosition] = internalStorage[index];
        }
    }
    
    internalStorage = updatedStorage;
}

template <class Type>
bool HashTable<Type>::isPrime(int num)
{
    bool isPrime = true;
    
    if(num < 1)
    {
        return false;
    }
    else if(num == 2 || num == 3)
    {
        isPrime = true;
    }
    else if(num % 2 == 0)
    {
        isPrime = true;
    }
    else
    {
        for(int next = 3; next <= sqrt(num) + 1; next += 2)
        {
            if(num % next == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
    
    return isPrime;
}









