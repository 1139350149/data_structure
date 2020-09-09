#pragma once
#include <iostream>
#include <string>

using namespace std;

template<class T>
class BinaryTreeNode {
public:
	T data;
	BinaryTreeNode<T>* leftChild, *rightChild;

	BinaryTreeNode();
	BinaryTreeNode(const T& data);
	BinaryTreeNode(const T& data, BinaryTreeNode<T>* l, BinaryTreeNode<T>* r);
	BinaryTreeNode<T> * getLeftChild() const;
	BinaryTreeNode<T> * getRightChild() const;
	void setLeftChild(BinaryTreeNode<T> * l);
	void setRightChild(BinaryTreeNode<T> * r);
	T getData() const;
	void setData(const T& data);
	bool isLeaf() const;
	void operator=(const BinaryTreeNode<T>);
};

template<class T>
BinaryTreeNode<T>::BinaryTreeNode() {
	this->leftChild = this->rightChild = nullptr;
}

template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& data) {
	this->data = data;
	this->leftChild = this->rightChild = nullptr;
}

template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& data, BinaryTreeNode<T>* l, BinaryTreeNode<T>* r) {
	this->data = data;
	this->leftChild = l;
	this->rightChild = r;
}

template<class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getLeftChild() const {
	return this->leftChild;
}

template<class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getRightChild() const {
	return this->rightChild;
}

template<class T>
void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T> * l) {
	this->leftChild = l;
}

template<class T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T> * r) {
	this->rightChild = r;
}

template<class T>
T BinaryTreeNode<T>::getData() const {
	return this->data;
}

template<class T>
void BinaryTreeNode<T>::setData(const T& data) {
	this->data = data;
}

template<class T>
bool BinaryTreeNode<T>::isLeaf() const {
	return (this->leftChild == nullptr && this->rightChild == nullptr);
}

template<class T>
void BinaryTreeNode<T>::operator=(const BinaryTreeNode<T> obj) {
	this->data == obj.getData();
	this->leftChild = obj.getLeftChild();
	this->rightChild = obj.getRightChild();
}
