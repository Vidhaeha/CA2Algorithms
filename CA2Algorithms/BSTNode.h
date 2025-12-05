#pragma once
#include <iostream>
using namespace std;

// -----------------------------
// BST NODE CLASS
// Stores: item, left pointer, right pointer
// -----------------------------
template <class T>
class BSTNode
{
private:
    T item;
    BSTNode<T>* left;
    BSTNode<T>* right;

public:

    // Constructor
    BSTNode(T newItem)
    {
        item = newItem;
        left = nullptr;
        right = nullptr;
    }

    // Getters
    T getItem() { return item; }
    BSTNode<T>* getLeft() { return left; }
    BSTNode<T>* getRight() { return right; }

    // Setters
    void setItem(T newItem) { item = newItem; }
    void setLeft(BSTNode<T>* node) { left = node; }
    void setRight(BSTNode<T>* node) { right = node; }
};
