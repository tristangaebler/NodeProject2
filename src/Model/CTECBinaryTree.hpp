//
//  CTECBinaryTree.hpp
//  NodeProject2
//
//  Created by Gaebler, Tristan on 4/11/16.
//  Copyright © 2016 Gaebler, Tristan. All rights reserved.
//

#ifndef CTECBinaryTree_hpp
#define CTECBinaryTree_hpp

#include <stdio.h>
#include "TreeNode.cpp"
template <class Type>
class CTECBinaryTree
{
private:
    TreeNode<Type> * root;
    int height;
    bool balanced;
    bool contains(Type value, CTECBinaryTree<Type> * currentTree);
    
public:
    CTECBinaryTree();
    ~CTECBinaryTree();
    bool insert(const Type & value);
    bool contains(Type value);
    Type remove(const Type& value);
    int getHeight();
    TreeNode<Type> * getRoot();
    bool isBalanced();
};

#endif /* CTECBinaryTree_hpp */
