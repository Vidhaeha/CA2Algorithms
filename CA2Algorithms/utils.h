#pragma once
#include <string>
#include <iostream>
//Hi
// Forward declarations
template<class T> class BinaryTree;
template<class T> class BSTNode;

using namespace std;

//Pretty printing
template<class T>
void printBT(const string& prefix, BSTNode<T>* node, bool isLeft)
{
	if (node != nullptr)
	{
		cout << prefix;
		cout << (isLeft ? "<-- " : "--> ");
		//printing the values
		cout << node->getItem() << endl;
		//enter the next level
		printBT(prefix + (isLeft ? "|   " : "    "), node->getLeft(), true);
		printBT(prefix + (isLeft ? "|   " : "    "), node->getRight(), false);
	}
}

//Recursive function to add each element when balancing a binary search tree
template<class T>
void createBalancedTree(BinaryTree<T>& tree, int start, int end, T* arr)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		tree.add(arr[mid]);
		createBalancedTree(tree, start, mid, arr);
		createBalancedTree(tree, mid + 1, end, arr);
	}
}

//Recursive function used to balance a binary search tree
template<class T>
void balance(BinaryTree<T>& tree) {
	T* arr = tree.toArray();
	int n = tree.count();
	tree.clear();
	createBalancedTree(tree, 0, n, arr);
	delete[] arr;
}

struct Item
{
	int skuCode = 0;
	float price = 0.0f;
	int stock = 0;

	//Constructors
	Item() {}

	Item(int sku, float p, int s)
	{
		this->skuCode = sku;
		this->price = p;
		this->stock = s;
	}

	friend ostream& operator<<(ostream& os, const Item& item)
	{
		os << "SKU: " << item.skuCode << ", Price: " << item.price << ", Stock: " << item.stock;
		return os;
	}

	bool operator<(const Item& other) const
	{
		return this->skuCode < other.skuCode;
	}

	bool operator>(const Item& other) const
	{
		return this->skuCode > other.skuCode;
	}

	bool operator==(const Item& other) const
	{
		return this->skuCode == other.skuCode;
	}

	//Overloading operator for adding stock
	Item operator++()
	{
		this->stock += 1;
		return *this;
	}

	//Overloading operator for reducing stock
	Item operator--()
	{
		if (this->stock > 0)
			this->stock -= 1;
		return *this;
	}

	//Printing
	ostream& print(ostream& os) const
	{
		os << "SKU: " << skuCode << ", Price: " << price << ", Stock: " << stock;
		return os;
	}
};