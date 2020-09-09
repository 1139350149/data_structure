#pragma once
#include "Node.h"
#include "ListStack.h"

using namespace std;

template<class T>
class CueBinaryTree {
private:
	CueBinaryTreeNode<T>* root;
public:
	CueBinaryTree();
	CueBinaryTree(CueBinaryTreeNode<T> * root);
	~CueBinaryTree();
	void deleteTree(CueBinaryTreeNode<T> * root);
	void createTree(CueBinaryTreeNode<T> * &root);
	CueBinaryTreeNode<T> * getRoot();
	void InThread(CueBinaryTreeNode<T> * root, CueBinaryTreeNode<T> * &pre);
	void InOrder(CueBinaryTreeNode<T>* root);
};

template<class T>
CueBinaryTree<T>::CueBinaryTree() {
	//root = nullptr;
	createTree(this->root);
}

template<class T>
CueBinaryTree<T>::CueBinaryTree(CueBinaryTreeNode<T> * root) {
	createTree(root);
}

template <class T>
void CueBinaryTree<T>::createTree(CueBinaryTreeNode<T> * &root) {
	T obj;
	cin >> obj;
	if (obj != "#") {
		root = new CueBinaryTreeNode<T>(obj);
		createTree(root->getLeftChild());
		createTree(root->getRightChild());
	}
	else {
		root = nullptr;
	}
}

template<class T>
CueBinaryTree<T>::~CueBinaryTree() {
	deleteTree(this->root);
}

template <class T>
void CueBinaryTree<T>::deleteTree(CueBinaryTreeNode<T> * root) {
	if (root) {
		if (root->getLeftChild()) {
			deleteTree(root->getLeftChild());
		}
		if (root->getRightChild()) {
			deleteTree(root->getRightChild());
		}
		delete root;
	}
}

template <class T>
CueBinaryTreeNode<T> * CueBinaryTree<T>::getRoot() {
	return this->root;
}

template <class T>
void CueBinaryTree<T>::InThread(CueBinaryTreeNode<T> * root, CueBinaryTreeNode<T> * &pre) {
	CueBinaryTreeNode<T> * current = root;
	if (current) {
		InThread(current->getLeftChild(), pre);
		if (current->getLeftChild() == nullptr) {
			current->setLeftTag(1);
			current->setLeftChild(pre);
		}
		if (pre && pre->getRightChild() == nullptr) {
			pre->setRightTag(1);
			pre->setRightChild(root);
		}
		pre = current;
		InThread(current->getRightChild(), pre);
	}
}

template <class T>
void CueBinaryTree<T>::InOrder(CueBinaryTreeNode<T>* root) {
	int count = 1;
	CueBinaryTreeNode<T> * current = root;
	while (current->getLeftTag() != 1) {
		current = current->getLeftChild();
	}
	while (current) {
		cout << count++ << ends << current->getData() << endl;
		if (current->getRightTag() == 1) {
			current = current->getRightChild();
		}
		else {
			current = current->getRightChild();
			while (current && current->getLeftTag() != 1) {
				current = current->getLeftChild();
			}
		}
	}
}