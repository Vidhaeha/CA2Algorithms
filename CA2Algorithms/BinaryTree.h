#pragma once
#include <iostream>
#include "BSTNode.h"

using namespace std;

// BINARY SEARCH TREE CLASS

template <class T>
class BinaryTree
{
public:
    BSTNode<T>* root; // root pointer

    BinaryTree()
    {
        root = nullptr;
    }

    // Public insert
    void add(T item)
    {
        root = insertRec(root, item);
    }

    // Public remove
    void remove(T item)
    {
        root = removeRec(root, item);
    }

    // Traversals
    void printPreOrder() { preOrder(root); cout << endl; }
    void printInOrder() { inOrder(root); cout << endl; }
    void printPostOrder() { postOrder(root); cout << endl; }

private:


    // INSERT HELPER
    BSTNode<T>* insertRec(BSTNode<T>* node, T item)
    {
        if (!node) return new BSTNode<T>(item);

        if (item < node->getItem())
            node->setLeft(insertRec(node->getLeft(), item));
        else
            node->setRight(insertRec(node->getRight(), item));

        return node;
    }

    // FIND MINIMUM NODE (used in deletion)
    BSTNode<T>* minNode(BSTNode<T>* node)
    {
        while (node->getLeft() != nullptr)
            node = node->getLeft();
        return node;
    }

    // REMOVE HELPER
    BSTNode<T>* removeRec(BSTNode<T>* node, T item)
    {
        if (!node) return nullptr;

        if (item < node->getItem())
            node->setLeft(removeRec(node->getLeft(), item));
        else if (item > node->getItem())
            node->setRight(removeRec(node->getRight(), item));
        else // Found node
        {
            // One or zero children
            if (!node->getLeft()) return node->getRight();
            if (!node->getRight()) return node->getLeft();

            // Two children: replace with inorder successor
            BSTNode<T>* temp = minNode(node->getRight());
            node->setItem(temp->getItem());
            node->setRight(removeRec(node->getRight(), temp->getItem()));
        }
        return node;
    }

    // TRAVERSALS
    void preOrder(BSTNode<T>* node)
    {
        if (!node) return;
        cout << node->getItem() << endl;
        preOrder(node->getLeft());
        preOrder(node->getRight());
    }

    void inOrder(BSTNode<T>* node)
    {
        if (!node) return;
        inOrder(node->getLeft());
        cout << node->getItem() << endl;
        inOrder(node->getRight());
    }

    void postOrder(BSTNode<T>* node)
    {
        if (!node) return;
        postOrder(node->getLeft());
        postOrder(node->getRight());
        cout << node->getItem() << endl;
    }
};
