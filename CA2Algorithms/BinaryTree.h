#pragma once
#include "BSTNode.h"
#include <iostream>
using namespace std;

template <class T>
class BinaryTree
{
	
public:
    BSTNode<T>* root;

	// Constructors and destructor
    BinaryTree() { root = nullptr; }
    ~BinaryTree() { delete root; }

	// Methods
    void add(T item)
    {
        if (root == nullptr)
        {
            root = new BSTNode<T>();
            root->setItem(item);
        }
        else root->add(item);
    }

	// Remove method
    bool remove(T item)
    {
			BSTNode<T>* toBeRemoved = root;
			BSTNode<T>* parent = nullptr;
			bool found = false;

			while (!found && toBeRemoved != nullptr)
			{

				if (toBeRemoved->getItem() == item)
				{

					found = true;
				}
				else
				{
					parent = toBeRemoved;
					if (toBeRemoved->getItem() > item)
					{
						toBeRemoved = toBeRemoved->getLeft();
					}
					else
					{
						toBeRemoved = toBeRemoved->getRight();
					}
				}
			}
			if (!found)
				return false;

			if (toBeRemoved->getLeft() == nullptr || toBeRemoved->getRight() == nullptr)
			{
				BSTNode<T>* newChild;
				if (toBeRemoved->getLeft() == nullptr)
				{
					newChild = toBeRemoved->getRight();
				}
				else
				{
					newChild = toBeRemoved->getLeft();
				}
				if (parent == nullptr)
				{
					root = newChild;
				}
				else if (parent->getLeft() == toBeRemoved)
				{
					parent->setLeft(newChild);
				}
				else
				{
					parent->setRight(newChild);
				}
				return true;
			}

			BSTNode<T>* smallestParent = toBeRemoved;
			BSTNode<T>* smallest = toBeRemoved->getRight();
			while (smallest->getLeft() != nullptr)
			{
				smallestParent = smallest;
				smallest = smallest->getLeft();
			}
			toBeRemoved->setItem(smallest->getItem());
			if (smallestParent == toBeRemoved)
			{
				smallestParent->setRight(smallest->getRight());
			}
			else
			{
				smallestParent->setLeft(smallest->getRight());
			}

	

        return false;
    }

	// Print methods
    void printInOrder() { printInOrder(root); cout << endl; }
    void printPreOrder() { printPreOrder(root); cout << endl; }
    void printPostOrder() { printPostOrder(root); cout << endl; }


    void printInOrder(BSTNode<T>* node)
    {
        if (!node) return;
        printInOrder(node->getLeft());
        cout << node->getItem() << " ";
        printInOrder(node->getRight());
    }

    void printPreOrder(BSTNode<T>* node)
    {
        if (!node) return;
        cout << node->getItem() << " ";
        printPreOrder(node->getLeft());
        printPreOrder(node->getRight());
    }

    void printPostOrder(BSTNode<T>* node)
    {
        if (!node) return;
        printPostOrder(node->getLeft());
        printPostOrder(node->getRight());
        cout << node->getItem() << " ";
    }
};
