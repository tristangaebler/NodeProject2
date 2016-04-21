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
    int size;
    bool balanced;
    bool contains(Type value, CTECBinaryTree<Type> * currentTree);
    void calculateSize(TreeNode<Type> * currentNode);
    TreeNode<Type>* getRightMostChild(CTECBinaryTree * leftSubTree);
    TreeNode<Type>* getLeftMostChild(CTECBinaryTree * rightSubTree);
public:
    CTECBinaryTree();
    ~CTECBinaryTree();
    bool insert(const Type & value);
    bool contains(Type value);
    Type remove(const Type& value); //Soap take out the binary tree
    int getHeight();
    int getSize();
    TreeNode<Type> * getRoot();
    bool isBalanced();
    void inorderTraversal(TreeNode<Type> * currentNode);
    void preorderTraversal(TreeNode<Type> * currentNode);
    void postorderTraversal(TreeNode<Type> * currentNode);
    TreeNode<Type> * getRightMostChild(CTECBinaryTree<Type> leftSubTree);
    TreeNode<Type> * getLeftMostChild(CTECBinaryTree<Type> rightSubTree);
    
    
};

#endif /* CTECBinaryTree_hpp */
