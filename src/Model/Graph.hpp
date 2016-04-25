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
namespace CTECData
{
    template<class Type>
    class MorningGraph
    {
    private:
        static const int MAXIMUM = 20;
    public:
        MorningGraph();
        virtual ~MorningGraph();
        void addVertex(const Type& label);
        void addEdge(int source, int target);
        Type& operator [] (int vertex);
    };
}
#endif /* Graph_hpp */
