#pragma once

#include "BSTNode.h"
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include "BinaryTree.h"
#include "Utils.h"
#include <iomanip>
#include <fstream>
#include <sstream>
template <class T>

class BinaryTree
{

public:
	BSTNode<T>* root;
	BinaryTree();
	void add(T item);
	bool remove(T item);
	void addItemToArray(BSTNode<T>* node, int& pos, T* arr);
	void clear();
	int count();

	T* toArray();
	void printInOrder();
	void printInOrder(BSTNode<T>* node);
	void printPreOrder();
	void printPreOrder(BSTNode<T>* node);
	void printPostOrder();
	void printPostOrder(BSTNode<T>* node);
	//void balanceBST();


	~BinaryTree();

};

template <class T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}

//Adding
template <class T>
void BinaryTree<T>::add(T item)
{
	if (root == nullptr)
		root = new BSTNode<T>(item);
	else
	{
		root->add(item);
	}
}

//Counting
template <class T>
int BinaryTree<T>::count()
{
	if (root == nullptr)
		return 0;
	else
		return root->count();
}

//Removing
template <class T>
bool BinaryTree<T>::remove(T item)
{
	BSTNode<T>* parent = nullptr;
	BSTNode<T>* toBeRemoved = root;
	bool found = false;
	while (!found && toBeRemoved != nullptr) {
		if (toBeRemoved->getItem() == item)
			found = true;
		else {
			parent = toBeRemoved;
			if (toBeRemoved->getItem() > item)
				toBeRemoved = toBeRemoved->getLeft();
			else
				toBeRemoved = toBeRemoved->getRight();

		}
	}
	if (!found)
		return false;
	if (toBeRemoved->getLeft() == nullptr || toBeRemoved->getRight() == nullptr)
	{
		BSTNode<T>* newChild;
		if (toBeRemoved->getLeft() != nullptr)
		{
			newChild = toBeRemoved->getLeft();
		}
		else
		{
			newChild = toBeRemoved->getRight();
		}
		if (root == nullptr)
			root = newChild;
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
	return true;
}

//Helper function to add items to array
template <class T>
void BinaryTree<T>::addItemToArray(BSTNode<T>* node, int& pos, T* arr)
{
	if (node != nullptr)
	{
		addItemToArray(node->getLeft(), pos, arr);
		arr[pos] = node->getItem();
		pos++;
		addItemToArray(node->getRight(), pos, arr);
	}
}

//Function to convert tree to sorted array
template <class T>
T* BinaryTree<T>::toArray()
{
	T* arr = new T[root->count()];
	int pos = 0;
	addItemToArray(root, pos, arr);
	return arr;
}

//Clearing the tree
template <class T>
void BinaryTree<T>::clear()
{
	delete root;
	root = nullptr;
}

//Destructor
template <class T>
BinaryTree<T>::~BinaryTree()
{
	delete root;
}

//In-order traversal
template<class T>
void BinaryTree<T>::printInOrder()
{
	this->printInOrder(root);
	cout << endl;
}

//Helper function for in-order traversal
template<class T>
void BinaryTree<T>::printInOrder(BSTNode<T>* node)
{
	if (node != nullptr)
	{
		printInOrder(node->getLeft());
		cout << node->getItem() << " ";
		printInOrder(node->getRight());
	}
}

//Pre-order traversal
template<class T>
void BinaryTree<T>::printPreOrder()
{
	this->printPreOrder(root);
	cout << "\n" << endl;
}

//Helper function for pre-order traversal (subtree)
template<class T>
void BinaryTree<T>::printPreOrder(BSTNode<T>* node)
{
	if (node != nullptr)
	{
		cout << node->getItem() << " ";
		printPreOrder(node->getLeft());
		printPreOrder(node->getRight());
	}
}

//Post-order traversal
template<class T>
void BinaryTree<T>::printPostOrder()
{
	this->printPostOrder(root);
	cout << endl;
}

//Helper function for post-order traversal (the entire tree)
template<class T>
void BinaryTree<T>::printPostOrder(BSTNode<T>* node)
{
	if (node != nullptr)
	{
		printPostOrder(node->getLeft());
		printPostOrder(node->getRight());
		cout << node->getItem() << " ";
	}
}