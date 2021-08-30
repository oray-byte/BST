#include "b_tree.h"

// ------------------------- B_NODE STRUCTURE -------------------------
b_node::b_node(int data, b_node* rNode, b_node* lNode)
{
	this->data = data;
	this->rNode = rNode;
	this->lNode = lNode;
}

// -------------------------   B_TREE CLASS   -------------------------
B_Tree::B_Tree(int data)
{
	this->root = new b_node(data);
	this->currentNode = root;
	this->smallestData = data;
}

B_Tree::~B_Tree()
{
	kill(root);
}

void B_Tree::insert(int data)
{
	if (data < smallestData)
	{
		smallestData = data;
	}

	if ((data <= root->getData()) && (root->lNode == nullptr))
	{
		root->setLeftNode(data);
		return;
	}

	if ((data > root->getData()) && (root->rNode == nullptr))
	{
		root->setRightNode(data);
		return;
	}

	(data <= root->getData() ? currentNode = root->lNode : currentNode = root->rNode);
	insert(data, currentNode, 1);
}

void B_Tree::insert(int data, b_node* b_node, int counter)
{
	if ((b_node->lNode == nullptr) && (data <= b_node->getData())) // If there is ever a seg fault around this line, change this into a nested if statement
	{
		b_node->setLeftNode(data);
		return;
	}

	if ((b_node->rNode == nullptr) && (data > b_node->getData())) // If there is ever a seg fault around this line, change this into a nested if statement
	{
		b_node->setRightNode(data);
		return;
	}

	(data <= b_node->getData() ? insert(data, b_node->lNode, (counter + 1)) : insert(data, b_node->rNode, (counter + 1)));
}

b_node* B_Tree::search(int data)
{
	if (data == root->getData())
	{
		return root;
	}

	return search(data, root);
}

b_node* B_Tree::search(int data, b_node* b_node)
{
	if (data == b_node->getData())
	{
		return b_node;
	}

	if ((data <= b_node->getData()) && b_node->lNode != nullptr)
	{
		return search(data, b_node->lNode);
	}
	if ((data > b_node->getData()) && (b_node->rNode != nullptr))
	{
		return search(data, b_node->rNode);
	}

	return nullptr;
}

void B_Tree::kill(b_node* b_node)
{
	if (b_node->lNode != nullptr)
	{
		kill(b_node->lNode);
	}
	if (b_node->rNode != nullptr)
	{
		kill(b_node->rNode);
	}

	delete b_node;
}

void B_Tree::printTree()
{
	std::cout << root->getData() << std::endl;
}

int B_Tree::getDepth()
{
	int depth = 0;

	return depth;
}