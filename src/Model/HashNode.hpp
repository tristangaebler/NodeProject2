//
//  HashNode.hpp
//  NodeProject2
//
//  Created by Gaebler, Tristan on 5/9/16.
//  Copyright © 2016 Gaebler, Tristan. All rights reserved.
//

#ifndef HashNode_hpp
#define HashNode_hpp

#include <stdio.h>
namespace CTECData
{
    template <class Type>
    class HashNode
    {
    private:
        int key;
        Type value;
    public:
        HashNode(int key, const Type& value);
        void setKey(int key);
        void setValue(const Type value);
        int getKey();
        Type getValue();
        
        
        
    };
}

#endif /* HashNode_hpp */
