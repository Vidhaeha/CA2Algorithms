#pragma once
#include <iostream>
#include "BinaryTree.h"

using namespace std;

// -----------------------------
// FIND NODE (BST SEARCH)
// -----------------------------
template<class T>
BSTNode<T>* findNode(BSTNode<T>* node, T value)
{
    if (node == nullptr)
        return nullptr;

    if (value == node->getItem())
        return node;

    if (value < node->getItem())
        return findNode(node->getLeft(), value);

    return findNode(node->getRight(), value);
}

// -----------------------------
// DISPLAY TREE (simple sideways print)
// -----------------------------
template <class T>
void displayRec(BSTNode<T>* node, int depth)
{
    if (node == nullptr)
        return;

    // Print right subtree first
    displayRec(node->getRight(), depth + 1);

    // Indent based on depth
    for (int i = 0; i < depth; i++)
        cout << "    ";

    // Print value
    cout << node->getItem() << endl;

    // Print left subtree
    displayRec(node->getLeft(), depth + 1);
}

template<class T>
void displayTree(BinaryTree<T>& tree)
{
    cout << "\n--- Tree Structure ---\n";
    displayRec(tree.root, 0);
    cout << "----------------------\n";
}
