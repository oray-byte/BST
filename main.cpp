#include "b_tree.h"
#include <ctime>

int main()
{
	srand(time(nullptr));
	B_Tree<int>* myTree = new B_Tree<int>(50);


	myTree->insert(45);
	myTree->insert(60);
	myTree->insert(40);
	myTree->insert(46);
	myTree->insert(55);
	myTree->insert(65);
	myTree->insert(62);
	myTree->insert(61);

	std::cout << myTree->getDepth() << std::endl;

	delete myTree;
	return 0;
}