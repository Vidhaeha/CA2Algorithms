#pragma once
#include "BinaryTree.h"
#include "BSTNode.h"
#include "Zombie.h"
#include <vector>
#include <iostream>
using namespace std;

// Find node by danger
BSTNode<Zombie>* findZombieByDanger(BSTNode<Zombie>* node, int danger)
{
    if (!node) return nullptr;
    if (node->getItem().dangerLevel == danger) return node;
    if (danger < node->getItem().dangerLevel)
        return findZombieByDanger(node->getLeft(), danger);
    return findZombieByDanger(node->getRight(), danger);
}

// Print type only
void printZombieTypeByDanger(BinaryTree<Zombie>& tree, int danger)
{
    BSTNode<Zombie>* found = findZombieByDanger(tree.root, danger);
    if (found) cout << "Zombie with danger " << danger << " is: " << found->getItem().type << endl;
    else cout << "Zombie with danger " << danger << " not found!" << endl;
}

// Display sideways (danger only)
void displayTreeHelper(BSTNode<Zombie>* node, int level = 0)
{
    if (!node) return;
    displayTreeHelper(node->getRight(), level + 1);
    for (int i = 0; i < level; i++) cout << "    ";
    cout << node->getItem() << endl;
    displayTreeHelper(node->getLeft(), level + 1);
}

// Wrapper for display
void displayTree(BinaryTree<Zombie>& tree)
{
    cout << "\n--- Zombie Danger Tree ---\n";
    displayTreeHelper(tree.root);
    cout << "--------------------------\n";
}

// Balance BST
void addToArray(BSTNode<Zombie>* node, vector<Zombie>& arr)
{
    if (!node) return;
    addToArray(node->getLeft(), arr);
    arr.push_back(node->getItem());
    addToArray(node->getRight(), arr);
}

// Build balanced BST from sorted array
BSTNode<Zombie>* buildBalanced(const vector<Zombie>& arr, int start, int end)
{
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    BSTNode<Zombie>* node = new BSTNode<Zombie>(arr[mid]);
    node->setLeft(buildBalanced(arr, start, mid - 1));
    node->setRight(buildBalanced(arr, mid + 1, end));
    return node;
}

// Main balance function
void balanceBST(BinaryTree<Zombie>& tree)
{
    if (!tree.root) return;
    vector<Zombie> items;
    addToArray(tree.root, items);
    tree.root = buildBalanced(items, 0, items.size() - 1);
}
