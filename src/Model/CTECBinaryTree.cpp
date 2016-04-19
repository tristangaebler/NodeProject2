//
//  CTECBinaryTree.cpp
//  NodeProject2
//
//  Created by Gaebler, Tristan on 4/11/16.
//  Copyright © 2016 Gaebler, Tristan. All rights reserved.


#include "CTECBinaryTree.hpp"

using namespace std;

template <class Type>
CTECBinaryTree<Type> :: CTECBinaryTree()
{
    root = nullptr;
    height = 0;
    balanced = true;
    size = 0;
}

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
    size = 0;
    calculateSize(root);
    return size;
}

template <class Type>
void CTECBinaryTree<Type> :: calculateSize(TreeNode<Type> * currentNode)
{
    
    if(currentNode != nullptr)
    {
        calculateSize(currentNode->getLeftChild());
        calculateSize(currentNode->getRightChild());
        size++;
    }
}

template <class Type>
bool CTECBinaryTree<Type> :: contains(Type value)
{
    bool isInTree = false;
    if (root->getValue() == value)
    {
        return true;
    }
    else if (value < root->getValue())
    {
        return contains(value, root->getLeftChild());
    }
    else
    {
        isInTree =  contains(value, root->getRightChild());
    }
    
    return isInTree;
}

template <class Type>
bool CTECBinaryTree<Type> :: contains(Type value, CTECBinaryTree<Type> * currentTree)
{
    if(currentTree == nullptr)
    {
        return false;
    }
    if (currentTree->getRoot()->getValue() == value)
    {
        return true;
    }
    else if (value < currentTree->getRoot()->root->getValue())
    {
        return contains(value, currentTree->getRoot()->root->getLeftChild());
    }
    else
    {
        return contains(value, currentTree->getRoot()->root->getRightChild());
    }
    
    return false;
}

template <class Type>
bool CTECBinaryTree<Type> :: insert(const Type &value)
{
    if (contains(value))
    {
        return false;
    }
    else
    {
        if(value < root->getValue())
        {
            
        }
        else
        {
            
        }
        
        return true;
    }
}

//*****NOTES*****
//If we go left we get the right most child.
//If we go right we get the left most child.
template <class Type>
Type CTECBinaryTree<Type>::remove(const Type &value)
{
    if(!contains(value))
    {
        return value;
    }
    else
    {
        /*
            Find the node.
            Check to see how many child nodes?
                if 0
                    delete that node
                else if only right
                    replace with left
                else if only left
                    replace with right
                else both
                    find LMR/RMC
                    swap with 
                    do - left only/right only
         */
        
    }
}

















