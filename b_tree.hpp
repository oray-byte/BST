#include "b_tree.h"
// ------------------------- B_NODE STRUCTURE -------------------------
template <typename T>
b_node<T>::b_node(T data, b_node<T>* rNode, b_node<T>* lNode)
{
	this->data = data;
	this->rNode = rNode;
	this->lNode = lNode;
}

// -------------------------   B_TREE CLASS   -------------------------
template <class A>
B_Tree<A>::B_Tree(A data)
{
	this->root = new b_node<A>(data);
	this->currentNode = root;
	this->depth = 0;
}

template <class A>
B_Tree<A>::~B_Tree()
{
	kill(root);
}

template <class A>
void B_Tree<A>::insert(A data)
{
	if ((data <= root->getData()) && (root->lNode == nullptr))
	{
		if (depth < 1) // Might move out of nested if
		{
			depth = 1;
		}
		root->setLeftNode(data);
		return;
	}

	if ((data > root->getData()) && (root->rNode == nullptr))
	{
		if (depth < 1)
		{
			depth = 1;
		}
		root->setRightNode(data);
		return;
	}

	(data <= root->getData() ? currentNode = root->lNode : currentNode = root->rNode);
	insert(data, currentNode, 1);
}

template <class A>
void B_Tree<A>::insert(A data, b_node<A>* b_node, int counter)
{
	if ((b_node->lNode == nullptr) && (data <= b_node->getData())) // If there is ever a seg fault around this line, change this into a nested if statement
	{
		if ((b_node->rNode == nullptr) && (counter >= depth)) // check to see if nested if can be reduced with DeMorgans
		{
			depth++;
		}
		b_node->setLeftNode(data);
		return;
	}

	if ((b_node->rNode == nullptr) && (data > b_node->getData())) // If there is ever a seg fault around this line, change this into a nested if statement
	{
		if ((b_node->lNode == nullptr) && (counter >= depth))
		{
			depth++;
		}
		b_node->setRightNode(data);
		return;
	}

	(data <= b_node->getData() ? insert(data, b_node->lNode, (counter + 1)) : insert(data, b_node->rNode, (counter + 1)));
}

template <class A>
b_node<A>* B_Tree<A>::search(A data)
{
	if (data == root->getData())
	{
		return root;
	}

	return search(data, root);
}

template <class A>
b_node<A>* B_Tree<A>::search(A data, b_node<A>* b_node)
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

template <class A>
void B_Tree<A>::kill(b_node<A>* b_node)
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

template <class A>
void B_Tree<A>::printTree()
{
	std::cout << root->getData() << std::endl;
}