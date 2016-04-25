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
CTECBinaryTree<Type> :: ~CTECBinaryTree()
{
        remove(root);
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
bool CTECBinaryTree<Type> :: contains(Type value, TreeNode<Type> * currentTree)
{
    bool isInTree = false;
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
    TreeNode<Type> * insertedNode(value) = new TreeNode<Type>(value);
    TreeNode<Type> * current;
    TreeNode<Type> * trailingCurrent;
    assert(insertedNode != nullptr);
    if(contains(value))
    {
        return false;
    }
    else
    {
        if(root == nullptr)
        {
            root = insertedNode;
        }
        else
        {
            current = root;
            while(current != nullptr)
            {
                trailingCurrent = current;
                if(current->getValue()>value)
                {
                    current = current->getLeftChild();
                }
                else
                {
                    current = current ->getRighChild();
                }
            }
        }
        if(trailingCurrent->getValue() > value)
        {
            trailingCurrent->setLeftChild(insertedNode);
        }
        else
        {
            trailingCurrent->setRightChild(insertedNode);
        }
        insertedNode->setParent(trailingCurrent);
        
        return true;
    }
}

//*****NOTES*****
//If we go left we get the right most child.
//If we go right we get the left most child.
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

template <class Type>
void CTECBinaryTree<Type>::remove(const Type &value)
{
    TreeNode<Type> * current = root;
    TreeNode<Type> * trailing = current;
    if(!contains(value))
    {
        return;
    }
    else
    {
        while (current != nullptr && current->getValue() != value)
        {
            trailing = current;
            if(current->getValue() > value)
            {
                current = current->getLeftChild();
            }
            else
            {
                current = current->getRightChild();
            }
        }
        
        if(current == true)
        {
            remove(root);
        }
        else if (trailing->getValue() > value)
        {
            remove(trailing->getLeftChild());
        }
        else
        {
            remove(trailing->getRightChild());
        }
    }
}

template <class Type>
void CTECBinaryTree<Type>::remove(TreeNode<Type> * nodeToRemove)
{
    TreeNode<Type> * current;
    TreeNode<Type> * trailing;
    TreeNode<Type> * temp;
    
    if(nodeToRemove == nullptr)
    {
        cerr << " Doh!" <<endl;
    }
    else if(nodeToRemove->getRightChild() == nullptr && nodeToRemove->getLeftChild() == nullptr)
    {
        temp = nodeToRemove;
        nodeToRemove = nullptr;
        delete temp;
    }
    else if (nodeToRemove->getRightChild() == nullptr)
    {
        temp = nodeToRemove;
        nodeToRemove = temp->getLeftChild();
        delete temp;
        
    }
    else if(nodeToRemove->getLeftChild() == nullptr)
    {
        temp = nodeToRemove;
        nodeToRemove = temp->getRightChild();
        delete temp;
    }
    else
    {
        current = nodeToRemove->getLeftChild();
        trailing = nullptr;
        while (current->getRightChild != nullptr)
        {
            trailing = current;
            current = current->getRightChild();
        }
        
        nodeToRemove->setValue(current->getValue());
        
        if(trailing == nullptr)
        {
            nodeToRemove->setLeftChild(current->getLeftChild);
        }
        else
        {
            trailing = setRightChild(current->getLeftChild());
        }
        
        delete current;
    }

}

template<class Type>
TreeNode<Type> * CTECBinaryTree<Type> :: getRightMostChild(TreeNode<Type> * leftSubTree)
{
    TreeNode<Type> * rightNode = leftSubTree->getRoot();
    while(rightNode->getRightChild() != nullptr)
    {
        rightNode = rightNode->getRightChild();
    }
    
    return rightNode;
}

template<class Type>
TreeNode<Type> * CTECBinaryTree<Type> :: getLeftMostChild(TreeNode<Type> * rightSubTree)
{
    TreeNode<Type> * leftNode = rightSubTree->getRoot();
    while(leftNode->getLeftChild() != nullptr)
    {
        leftNode = leftNode->getLeftChild();
    }
    
    return leftNode;
}

















