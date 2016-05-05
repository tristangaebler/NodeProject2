//
//  HashTable.cpp
//  NodeProject2
//
//  Created by Gaebler, Tristan on 5/5/16.
//  Copyright © 2016 Gaebler, Tristan. All rights reserved.
//

#include "HashTable.hpp"
using namespace CTECData;

template <class Type>
HashTable<Type>::HashTable()
{
    this->capacity = 10;
    this->efficiencyPercentage = .667;
    this->size = 0;
    this->internalStorage = new Type[capacity];
}

template <class Type>
int HashTable<Type>::getSize()
{
    return this->size();
}

template <class Type>
HashTable<Type>::~HashTable<Type>()
{
    delete [] internalStorage;
}

template <class Type>
void HashTable<Type>::add(const Type &value)
{
    if(!conatins(value))
    {
        int insertPosition = findPosition(value);
        
        if(internalStorage[insertPosition] != nullptr)
        {
            while (internalStorage[insertPosition] != nullptr)
            {
                insertPosition = (insertPosition + 1) % size;
            }
            internalStorage[insertPosition] = value;
        }
        else
        {
            internalStorage[insertPosition] = value;
        }
    }
}










