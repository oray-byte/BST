#ifndef B_TREE_H
#define B_TREE_H

#include <iostream>
#include <vector>

using std::vector;

struct b_node
{
public:
	b_node(int data = 0, b_node* rNode = nullptr, b_node* lNode = nullptr);

	inline void setRightNode(int data) { this->rNode = new b_node(data); }

	inline void setLeftNode(int data) { this->lNode = new b_node(data); }

	int getData() { return data; }

	b_node* rNode;
	b_node* lNode;
private:
	int data;
};

class B_Tree
{
public:
	B_Tree(int data);
	B_Tree(b_node* root); // Implement later. Conflicts with depth logic
	~B_Tree();
	void insert(int data);
	b_node* search(int data);
	void printTree();

	int getSmallestData() { return smallestData; }
	int getDepth();

private:
	void insert(int data, b_node* b_node, int counter = 0);
	void kill(b_node* root);

	b_node* search(int data, b_node* b_node);
	b_node* root;
	b_node* currentNode;
	int smallestData;
};

#endif
