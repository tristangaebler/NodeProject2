//
//  HashTable.hpp
//  NodeProject2
//
//  Created by Gaebler, Tristan on 5/5/16.
//  Copyright © 2016 Gaebler, Tristan. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <stdio.h>
#include "CTECList.h";ß
#include "HashNode.cpp";
namespace CTECData
{
    template <class Type>
    class HashTable
    {
    private:
        int capacity;
        int tableCapacity;
        double efficiencyPercentage;
        int size;
        int tableSize;
        HashNode<Type>** internalStorage;
        CTECList<HashNode<Type> > * tableStorage;
        
        void updateTableCapacity();
        void updateSize();
        
        int findPosition(HashNode<Type> currentNode);
        int findTablePosition(HashNode<Type> currentNode);
        
        int handleCollision(HashNode<Type> currentNode);
        
        int getNextPrime();
        bool isPrime(int candidateNumber);
    public:
        HashTable();
        virtual ~HashTable();
        
        void addToTable(HashNode<Type> currentNode);
        void add(HashNode<Type> currentNode);
        
        bool remove(HashNode<Type> currentNode);
        bool contains(HashNode<Type> currentNode);
        int getSize();
    };
}

#endif /* HashTable_hpp */
