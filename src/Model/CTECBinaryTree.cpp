//
//  CTECBinaryTree.cpp
//  NodeProject2
//
//  Created by Gaebler, Tristan on 4/11/16.
//  Copyright © 2016 Gaebler, Tristan. All rights reserved.
//

#include "CTECBinaryTree.hpp"

using namespace std;

template <class Type>
void CTECBinaryTree<Type> :: inorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        inorderTraversal(currentNode->getLeftChild());
        cout << currentNode->getValue() << " ";
        inorderTraversal(currentNode->getRightChild());
        
    }
}

template <class Type>
void CTECBinaryTree<Type> :: preorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        cout << currentNode->getValue() << " ";
        inorderTraversal(currentNode->getLeftChild());
        inorderTraversal(currentNode->getRightChild());
        
    }
}

template <class Type>
void CTECBinaryTree<Type> :: postorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        inorderTraversal(currentNode->getLeftChild());
        inorderTraversal(currentNode->getRightChild());
        cout << currentNode->getValue() << " ";
        
    }
}

template <class Type>
int CTECBinaryTree<Type> :: getSize()
{
    calculateSize(root);
    return size;
}

template <class Type>
void CTECBinaryTree<Type> :: calculateSize(TreeNode<Type> * currentNode)
{
    
    if(currentNode != nullptr)
    {
        postorderTraversal(currentNode->getLeftChild());
        postorderTraversal(currentNode->getRightChild());
        size++;
    }
}