#ifndef B_TREE_H
#define B_TREE_H

#include <iostream>
#include <vector>

using std::vector;

template <typename T>
struct b_node
{
public:
	b_node(T data = nullptr, b_node* rNode = nullptr, b_node* lNode = nullptr);

	inline void setRightNode(T data) { this->rNode = new b_node<T>(data); }

	inline void setLeftNode(T data) { this->lNode = new b_node<T>(data); }

	T getData() { return data; }

	b_node<T>* rNode;
	b_node<T>* lNode;
private:
	T data;
};

template <class A>
class B_Tree
{
public:
	B_Tree(A data);
	B_Tree(b_node<A>* root); // Implement later. Conflicts with depth logic
	~B_Tree();
	void insert(A data);
	b_node<A>* search(A data);
	void printTree();

	int getDepth() { return depth; }

private:
	void insert(A data, b_node<A>* b_node, int counter = 0);
	void kill(b_node<A>* root);

	b_node<A>* search(A data, b_node<A>* b_node);
	b_node<A>* root;
	b_node<A>* currentNode;
	int depth; // Creates problems when making a tree from a subtree
};

#include "b_tree.hpp"
#endif
