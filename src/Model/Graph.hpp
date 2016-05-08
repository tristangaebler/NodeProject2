//
//  Graph.hpp
//  NodeProject2
//
//  Created by Gaebler, Tristan on 4/25/16.
//  Copyright © 2016 Gaebler, Tristan. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp
#include <stdio.h>
#include <set>
#include <iostream>
#include <queue>
namespace CTECData
{
    template<class Type>
    class Graph
    {
    private:
        static const int MAXIMUM = 20;
        bool edges [MAXIMUM][MAXIMUM];
        Type labels [MAXIMUM];
        int manyVertices;
        void depthFirstTraversal(Graph<Type> currentGraph, int vertex, bool * markedVertices);
    public:
        Graph();
        virtual ~Graph();
        void addVertex(const Type& label);
        void addEdge(int source, int target);
        Type& operator [] (int vertex);
        int size() const;
        bool isEdge(int source, int target) const;
        void removeEdge(int source, int target);
        std::set<int> neighbors(int vertex) const;
        Type operator [] (int vertex) const;
        void depthFirstTraversal(Graph<Type> currentGraph, int vertex);
        void breadthFirstTraversal(Graph<Type> currentGraph, int vertex);
    };
}
#endif /* Graph_hpp */
