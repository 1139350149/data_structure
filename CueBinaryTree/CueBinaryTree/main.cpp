#include "CueBinaryTree.h"

int main() {
	CueBinaryTreeNode<string> *pre = nullptr;
	CueBinaryTree<string> myBT;
	myBT.InThread(myBT.getRoot(), pre);
	myBT.InOrder(myBT.getRoot());
	system("pause");
	return 0;
}