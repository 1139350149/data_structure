#pragma once
#include "TreeNode.h"
#include <stack>

template<class T>
class AVLTree {
private:
	BinaryTreeNode<T> * root;
public:
	AVLTree();
	~AVLTree();
	void leftOnceTurn(BinaryTreeNode<T> * node);
	void rightOnceTurn(BinaryTreeNode<T> * node);
	void leftRightTwiceTurn(BinaryTreeNode<T> * node);
	void RightLeftTwiceTurn(BinaryTreeNode<T> * node);
	void deleteTree(BinaryTreeNode<T> * root);
	BinaryTreeNode<T> * search(BinaryTreeNode<T>* root, T key);
	void insert(T data);
	int getHeight(BinaryTreeNode<T> * node);
	void countHeight(BinaryTreeNode<T> * root, int level, int & depth);
	int getSub(BinaryTreeNode<T> * node);
};

template<class T>
AVLTree<T>::AVLTree() {
	root = nullptr;
}
template<class T>
AVLTree<T>::~AVLTree() {
	deleteTree(this->root);
}
template<class T>
void AVLTree<T>::deleteTree(BinaryTreeNode<T> * root) {
	if (root == nullptr) {
		return;
	}
	deleteTree(root->getLeftChild());
	deleteTree(root->getRightChild());
	delete root;
	root = nullptr;
}
template<class T>
BinaryTreeNode<T> * AVLTree<T>::search(BinaryTreeNode<T>* root, T key) {
	if (root == nullptr) {
		return nullptr;
	}
	if (root->getData() == key) {
		return root;
	}
	else if(root->getData() < key) {
		search(root->getRightChild(), key);
	}
	else {
		search(root->getLeftChild(), key);
	}
}
template<class T>
void AVLTree<T>::insert(T data) {
	stack<BinaryTreeNode<T> * > stack;
	BinaryTreeNode<T> * pointer = this->root;
	if (this->root == nullptr) {
		this->root = new BinaryTreeNode<T>(data);
		return;
	}
	stack.push(this->root);
	while (pointer) {
		if (pointer->getData() == data) {
			return;			//平衡二叉树也是二叉搜索树，不允许相同值出现
		}
		if (pointer->getData() > data) {
			if (pointer->getLeftChild() != nullptr) {
				stack.push(pointer->getLeftChild());
				pointer = pointer->getLeftChild();
			}
			else {
				pointer->setLeftChild(new BinaryTreeNode<T>(data));
				return;
			}
		}
		else {
			if (pointer->getRightChild() != nullptr) {
				stack.push(pointer->getRightChild());
				pointer = pointer->getRightChild();
			}
			else {
				pointer->setRightChild(new BinaryTreeNode<T>(data));
				return;
			}
		}
	}
	while (!stack.empty()) {
		pointer = stack.top();
		if (abs(getSub(pointer)) > 1) {
			if (getSub(pointer) == -2 && getSub(pointer->leftChild) == -1) {
				rightOnceTurn(pointer);
			}
			else if (getSub(pointer) == 2 && getSub(pointer->leftChild) == 1) {
				leftOnceTurn(pointer);
			}
			else if (getSub(pointer) == 2 && getSub(pointer->rightChild) == -1) {
				RightLeftTwiceTurn(pointer);
			}
			else if (getSub(pointer) == -2 && getSub(pointer->rightChild) == 1) {
				leftRightTwiceTurn(pointer);
			}
		}
	}
}

template<class T>
void AVLTree<T>::leftOnceTurn(BinaryTreeNode<T> * node) {
	BinaryTreeNode<T> * p = node->rightChild;
	node->rightChild = p->leftChild;
	p->leftChild = node;
	p = node;
}
template<class T>
void AVLTree<T>::rightOnceTurn(BinaryTreeNode<T> * node) {
	BinaryTreeNode<T> * p = node->leftChild;
	node->leftChild = p->rightChild;
	p->rightChild = node;
	p = node;
}
template<class T>
void AVLTree<T>::leftRightTwiceTurn(BinaryTreeNode<T> * node) {
	leftOnceTurn(node->leftChild);
	rightOnceTurn(node);
}
template<class T>
void AVLTree<T>::RightLeftTwiceTurn(BinaryTreeNode<T> * node) {
	rightOnceTurn(node->rightChild);
	leftOnceTurn(node);
}
template<class T>
int AVLTree<T>::getHeight(BinaryTreeNode<T> * node) {
	int level = 1, depth = 1;
	countHeight(node, level, depth);
	return depth;
}
template<class T>
void AVLTree<T>::countHeight(BinaryTreeNode<T> * root, int level, int & depth) {
	if (root) {
		if (level > depth) {
			depth = level;
		}
		countHeight(root->getLeftChild(), level + 1, depth);
		countHeight(root->getRightChild(), level + 1, depth);
	}
}
template<class T>
int AVLTree<T>::getSub(BinaryTreeNode<T> * node) {
	int lDepth = 1;
	int rDepth = 1;
	lDepth = getHeight(node->leftChild);
	rDepth = getHeight(node->rightChild);
	return (rDepth - lDepth);
}