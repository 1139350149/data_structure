#pragma once
#include <string>
#include <iostream>

using namespace std;

template <class T>
class BinarySearchNode {
public:
	T data;
	BinarySearchNode<T>* leftChild, *rightChild;
	BinarySearchNode();
	BinarySearchNode(const T& data);
	BinarySearchNode(const T& data, BinarySearchNode<T>* l, BinarySearchNode<T>* r);
	BinarySearchNode<T> *getLeftChild() const;
	BinarySearchNode<T> *getRightChild() const;
	void setLeftChild(BinarySearchNode<T> * l);
	void setRightChild(BinarySearchNode<T> * r);
	T getData() const;
	void setData(const T& data);
	bool isLeaf() const;
	void operator=(const BinarySearchNode<T>);
};

template<class T>
BinarySearchNode<T>::BinarySearchNode() {
	this->leftChild = this->rightChild = nullptr;
}

template<class T>
BinarySearchNode<T>::BinarySearchNode(const T& data) {
	this->data = data;
	this->leftChild = this->rightChild = nullptr;
}

template<class T>
BinarySearchNode<T>::BinarySearchNode(const T& data, BinarySearchNode<T>* l, BinarySearchNode<T>* r) {
	this->data = data;
	this->leftChild = l;
	this->rightChild = r;
}

template<class T>
BinarySearchNode<T>* BinarySearchNode<T>::getLeftChild() const {
	return this->leftChild;
}

template<class T>
BinarySearchNode<T>* BinarySearchNode<T>::getRightChild() const {
	return this->rightChild;
}

template<class T>
void BinarySearchNode<T>::setLeftChild(BinarySearchNode<T> * l) {
	this->leftChild = l;
}

template<class T>
void BinarySearchNode<T>::setRightChild(BinarySearchNode<T> * r) {
	this->rightChild = r;
}

template<class T>
T BinarySearchNode<T>::getData() const {
	return this->data;
}

template<class T>
void BinarySearchNode<T>::setData(const T& data) {
	this->data = data;
}

template<class T>
bool BinarySearchNode<T>::isLeaf() const {
	return (this->leftChild == nullptr && this->rightChild == nullptr);
}

template<class T>
void BinarySearchNode<T>::operator=(const BinarySearchNode<T> obj) {
	this->data == obj.getData();
	this->leftChild = obj.getLeftChild();
	this->rightChild = obj.getRightChild();
}
