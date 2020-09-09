#pragma once
#include "BinarySearchNode.h"
#include <queue>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class BinarySearchTree {
private:
	BinarySearchNode<T> * root;
public:
	BinarySearchTree();
	~BinarySearchTree();
	void InsertNode(const T& data);
	BinarySearchNode<T> * search(BinarySearchNode<T> * root, T key);
	void deleteByCopying(BinarySearchNode<T> *& node);
	void deleteByMerging(BinarySearchNode<T> *& node);
	void deleteTree(BinarySearchNode<T> * node);
	void BreadthOrder(BinarySearchNode<T> * root);
	BinarySearchNode<T> *& getParent(BinarySearchNode<T> * root,BinarySearchNode<T> * node);
	BinarySearchNode<T> * getRoot() {
		return this->root;
	}
};
template <class T>
BinarySearchTree<T>::BinarySearchTree() {
	root = nullptr;
}
template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
	deleteTree(root);
}
template <class T>
void BinarySearchTree<T>::deleteTree(BinarySearchNode<T> * node) {
	delete(node->getLeftChild());
	delete(node->getRightChild());
	if (node) {
		delete node;
	}
}

template <class T>
void BinarySearchTree<T>::InsertNode(const T& data) {
	if (this->root == nullptr) {
		this->root = new BinarySearchNode<T>(data);
		return;
	}
	int mode = 0;
	BinarySearchNode<T> * p = this->root, *pre = nullptr;
	while (p) {
		pre = p;
		if (p->getData() < data) {
			p = p->rightChild;
			mode = 1;
		}
		else if (p->getData() > data) {
			p = p->leftChild;
			mode = 2;
		}
		else{
			return;
		}
	}
	switch (mode)
	{
	case 1: {
		pre->setRightChild(new BinarySearchNode<T>(data));
		break;
	}
	case 2: {
		pre->setLeftChild(new BinarySearchNode<T>(data));
		break;
	}
	}
}
template <class T> 
BinarySearchNode<T> * BinarySearchTree<T>::search(BinarySearchNode<T> * root, T key) {
	BinarySearchNode<T>  * current = root;
	while (current != nullptr && key != current->getData()) {
		current = (key < current->getData()) ? current->getLeftChild() : current->getRightChild();
	}
	return current;
}
template <class T>
void BinarySearchTree<T>::deleteByCopying(BinarySearchNode<T> *& node) {
	BinarySearchNode<T> * temp = node, * previous;
	if (node) {
		if (node->getRightChild() == nullptr) {
			getParent(root, node)->setLeftChild(node);
			node = node->getLeftChild();
		}
		else if (node->getLeftChild() == nullptr) {
			getParent(root, node)->setLeftChild(node);
			node = node->getRightChild();
		}
		else {
			temp = node->getLeftChild();
			previous = node;
			while (temp->getRightChild() != nullptr) {
				previous = temp;
				temp = temp->getRightChild();
			}
			previous->setRightChild(nullptr);
			node->setData(temp->getData());
			if (previous == node) {
				previous->setLeftChild(temp->getLeftChild());
			}
			else {
				previous->setRightChild(temp->getLeftChild());
			}
		}
	}
}

template<class T>
void BinarySearchTree<T>::deleteByMerging(BinarySearchNode<T> *& node) {
	BinarySearchNode<T> * temp = node;
	if (node) {
		if (!node->rightChild) {
			node = node->leftChild;
		}
		else if (!node->leftChild) {
			node = node->rightChild;
		}
		else {
			temp = node->leftChild;
			while (temp->rightChild != nullptr) {
				temp = temp->rightChild;
			}
			temp->rightChild = node->rightChild;
			temp = node;
			node = node->leftChild;
		}
		delete temp;
	}
}


template<class T>
void BinarySearchTree<T>::BreadthOrder(BinarySearchNode<T> * root) {
	if (root == nullptr) {
		return;
	}
	queue<BinarySearchNode<T> * > queue;
	queue.push(root);
	BinarySearchNode<T> * pointer;
	int count = 1;
	while (!queue.empty()) {
		pointer = queue.front();
		cout << count++ << ends << pointer->getData() << endl;
		if (pointer->getLeftChild()) {
			queue.push(pointer->getLeftChild());
		}
		if (pointer->getRightChild()) {
			queue.push(pointer->getRightChild());
		}
		queue.pop();
	}
}


template<class T>
BinarySearchNode<T> *& BinarySearchTree<T>::getParent(BinarySearchNode<T> * root, BinarySearchNode<T> * node) {
	if (root) {
		if (root->leftChild == node) {
			return root;
		}
		else if (root->rightChild == node) {
			return root;
		}
		getParent(root->leftChild, node);
		getParent(root->rightChild, node);
	}
}
