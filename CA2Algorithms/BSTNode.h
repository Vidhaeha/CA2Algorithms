#pragma once
#include <iostream>
using namespace std;

template <class T>
class BSTNode
{
	// Data members
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;
    BSTNode<T>* parent;

public:
    BSTNode();
    BSTNode(T data);

    void add(T item);
    T getItem();
    void setItem(T item);

    BSTNode<T>* getLeft();
    BSTNode<T>* getRight();
    void setLeft(BSTNode<T>* node);
    void setRight(BSTNode<T>* node);

    ~BSTNode();
};

// Implementation
template <class T>
BSTNode<T>::BSTNode() { left = right = parent = nullptr; }

template <class T>
BSTNode<T>::BSTNode(T data) { this->data = data; left = right = parent = nullptr; }

template <class T>
T BSTNode<T>::getItem() { return data; }

template <class T>
void BSTNode<T>::setItem(T item) { data = item; }

template <class T>
BSTNode<T>* BSTNode<T>::getLeft() { return left; }

template <class T>
BSTNode<T>* BSTNode<T>::getRight() { return right; }

template <class T>
void BSTNode<T>::setLeft(BSTNode<T>* node) { left = node; }

template <class T>
void BSTNode<T>::setRight(BSTNode<T>* node) { right = node; }

// Add item to BST
template <class T>
void BSTNode<T>::add(T item)
{
    if (item == data) return;
    if (item < data)
    {
        if (left == nullptr)
        {
            left = new BSTNode<T>();
            left->setItem(item);
            left->parent = this;
        }
        else left->add(item);
    }
    else
    {
        if (right == nullptr)
        {
            right = new BSTNode<T>();
            right->setItem(item);
            right->parent = this;
        }
        else right->add(item);
    }
}

// Destructor
template <class T>
BSTNode<T>::~BSTNode()
{
    delete left;
    delete right;
}
