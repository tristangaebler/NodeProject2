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
#include "HashNode.cpp";
namespace CTECData
{
    template <class Type>
    class HashTable
    {
    private:
        int capacity;
        double efficiencyPercentage;
        int size;
        HashNode<Type> * internalStorage;
        
        int findPosition(HashNode<Type> currentNode);
        int handleCollision(HashNode<Type> * currentNode);
        void updateSize();
    public:
        HashTable();
        ~HashTable();
        void add(HashNode<Type> * currentNode);
        bool remove(HashNode<Type> * currentNode);
        bool contains(HashNode<Type> * currentNode);
        int getSize();
    };
}

#endif /* HashTable_hpp */
