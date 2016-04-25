//
//  Graph.cpp
//  NodeProject2
//
//  Created by Gaebler, Tristan on 4/25/16.
//  Copyright © 2016 Gaebler, Tristan. All rights reserved.
//

#include "Graph.hpp"
using namespace CTECData;

template <class Type>
const int Graph<Type> :: MAXIMUM;

template <class Type>
void Graph<Type> :: addEdge(int source, int target)
{
    assert(source < size());
    assert(target < size());
    edges[source][target] = true;
}

template <class Type>
void Graph<Type> :: addVertex(const Type& label)
{
    int newVertexNumber;
    int otherNumber;
    
    assert(size() < MAXIMUM);
    
    newVertexNumber = manyVerticles;
    ++manyVerticles;
    
    for(otherNumber = 0; otherNumber < manyVerticles; otherNumber++)
    {
        edges[otherNumber][newVertexNumber] = false;
        edges[newVertexNumber] [otherNumber] = false;
    }
    
    label[newVertexNumber] = label;
    
}

template<class Type>
bool Graph<Type> :: isEdge(int source, int target) const
{
    bool connected = false;
    
    assert(source < size() && target < size());
    connected = edges [source][target];
    
    return connected;
}

template <class Type>
Type& Graph<Type> :: operator[](int vertex)
{
    assert(vertex < size());
    return labels[vertex];
    
}