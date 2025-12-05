#pragma once
#include <iostream>
#include <vector>
#include "BinaryTree.h"
using namespace std;

// ZOMBIE STRUCT
struct Zombie
{
    int dangerLevel;
    string type;

    Zombie() {}
    Zombie(int d, string t) { dangerLevel = d; type = t; }

    bool operator<(const Zombie& other) const { return dangerLevel < other.dangerLevel; }
    bool operator>(const Zombie& other) const { return dangerLevel > other.dangerLevel; }
    bool operator==(const Zombie& other) const { return dangerLevel == other.dangerLevel; }

    // For normal printing: danger level only
    friend ostream& operator<<(ostream& os, const Zombie& z) { os << z.dangerLevel; return os; }
};

// FIND NODE BY DANGER LEVEL
template<class T>
BSTNode<T>* findNodeByDanger(BSTNode<T>* node, int danger)
{
    if (!node) return nullptr;

    if (node->getItem().dangerLevel == danger)
        return node;
    else if (danger < node->getItem().dangerLevel)
        return findNodeByDanger(node->getLeft(), danger);
    else
        return findNodeByDanger(node->getRight(), danger);
}

// DISPLAY ZOMBIE TYPE BY DANGER
template<class T>
void printZombieTypeByDanger(BinaryTree<T>& tree, int danger)
{
    BSTNode<T>* found = findNodeByDanger(tree.root, danger);
    if (found)
        cout << "Zombie with danger " << danger << " is: " << found->getItem().type << endl;
    else
        cout << "Zombie with danger " << danger << " not found!" << endl;
}

// DISPLAY TREE (SIDEWAYS) - danger numbers only
template <class T>
void displayTreeHelper(BSTNode<T>* node, int level = 0)
{
    if (!node) return;

    displayTreeHelper(node->getRight(), level + 1);

    for (int i = 0; i < level; i++) cout << "    ";
    cout << node->getItem() << endl;

    displayTreeHelper(node->getLeft(), level + 1);
}

template<class T>
void displayTree(BinaryTree<T>& tree)
{
    cout << "\n--- Zombie Danger Tree ---\n";
    displayTreeHelper(tree.root);
    cout << "--------------------------\n";
}

// BALANCE BST
template<class T>
void addToArray(BSTNode<T>* node, vector<T>& arr)
{
    if (!node) return;
    addToArray(node->getLeft(), arr);
    arr.push_back(node->getItem());
    addToArray(node->getRight(), arr);
}

template<class T>
BSTNode<T>* buildBalanced(const vector<T>& arr, int start, int end)
{
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    BSTNode<T>* node = new BSTNode<T>(arr[mid]);
    node->setLeft(buildBalanced(arr, start, mid - 1));
    node->setRight(buildBalanced(arr, mid + 1, end));
    return node;
}

template<class T>
void balanceBST(BinaryTree<T>& tree)
{
    vector<T> items;
    addToArray(tree.root, items);
    delete tree.root;
    tree.root = buildBalanced(items, 0, items.size() - 1);
}
