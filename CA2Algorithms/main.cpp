#include <iostream>
#include "BinaryTree.h"
#include "BSTNode.h"
#include "Utils.h"

using namespace std;

int main()
{
	//hi
	BinaryTree<int> tree;
	tree.add(50);
	tree.add(30);
	tree.add(70);
	tree.add(20);
	tree.add(40);
	tree.add(60);
	tree.add(80);
	
	cout << "Original tree (pre-order): ";
	tree.printPreOrder();
	cout << "Original tree (post-order): ";
	tree.printPostOrder();
	cout << "Original tree (in-order): ";
	tree.printInOrder();

	cout << "Balanced tree (in-order): ";
	balance(tree);
	printBT("", tree.root, false);

	//Find item

	//Display

	//Load from file

	tree.remove(20);
	cout << "Tree after removing 20: ";
	printBT("", tree.root, false);

	return 0;
}