#include <iostream>
#include "BinaryTree.h"
#include "Utils.h"

using namespace std;

int main()
{
    BinaryTree<int> tree;

    // Insert values
    tree.add(50);
    tree.add(30);
    tree.add(70);
    tree.add(20);
    tree.add(40);
    tree.add(60);
    tree.add(80);

    // Traversals
    cout << "Pre-order:  ";
    tree.printPreOrder();

    cout << "In-order:   ";
    tree.printInOrder();

    cout << "Post-order: ";
    tree.printPostOrder();

    // Display tree visually
    displayTree(tree);

    // FIND example
    int n = 40;
    cout << "\nSearching for: " << n << endl;

    BSTNode<int>* found = findNode(tree.root, n);

    if (found)
        cout << "Found node with value: " << found->getItem() << endl;
    else
        cout << "Value NOT found.\n";

    // Remove example
    cout << "\nRemoving 20...\n";
    tree.remove(20);

    displayTree(tree);

    return 0;
}
