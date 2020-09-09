#pragma once
#include <iostream>
#include <string>

using namespace std;

template<class T>
class CueBinaryTreeNode {
	//friend class CueBinaryTree;
private:
	T data;
	CueBinaryTreeNode<T>* leftChild, *rightChild;
	int leftTag, rightTag;
public:
	CueBinaryTreeNode();
	CueBinaryTreeNode(const T& data);
	CueBinaryTreeNode(const T& data, CueBinaryTreeNode<T>* l, CueBinaryTreeNode<T>* r);
	CueBinaryTreeNode<T> * & getLeftChild();
	CueBinaryTreeNode<T> * & getRightChild();
	void setLeftChild(CueBinaryTreeNode<T> * l);
	void setRightChild(CueBinaryTreeNode<T> * r);
	T getData() const;
	void setData(const T& data);
	bool isLeaf() const;
	void operator=(const CueBinaryTreeNode<T>);
	void setLeftTag(int l);
	void setRightTag(int r);
	int getLeftTag();
	int getRightTag();
};

template<class T>
CueBinaryTreeNode<T>::CueBinaryTreeNode() {
	this->leftChild = this->rightChild = nullptr;
	this->leftTag = this->rightTag = 0;
}

template<class T>
CueBinaryTreeNode<T>::CueBinaryTreeNode(const T& data) {
	this->data = data;
	this->leftChild = this->rightChild = nullptr;
	this->leftTag = this->rightTag = 0;
}

template<class T>
CueBinaryTreeNode<T>::CueBinaryTreeNode(const T& data, CueBinaryTreeNode<T>* l, CueBinaryTreeNode<T>* r) {
	this->data = data;
	this->leftChild = l;
	this->rightChild = r;
	if (l) {
		this.leftTag = 1;
	}
	if (r) {
		this->rightTag = 1;
	}
}

template<class T>
CueBinaryTreeNode<T>* & CueBinaryTreeNode<T>::getLeftChild() {
	return this->leftChild;
}

template<class T>
CueBinaryTreeNode<T>* & CueBinaryTreeNode<T>::getRightChild() {
	return this->rightChild;
}

template<class T>
void CueBinaryTreeNode<T>::setLeftChild(CueBinaryTreeNode<T> * l) {
	this->leftChild = l;
}

template<class T>
void CueBinaryTreeNode<T>::setRightChild(CueBinaryTreeNode<T> * r) {
	this->rightChild = r;
}

template<class T>
T CueBinaryTreeNode<T>::getData() const {
	return this->data;
}

template<class T>
void CueBinaryTreeNode<T>::setData(const T& data) {
	this->data = data;
}

template<class T>
bool CueBinaryTreeNode<T>::isLeaf() const {
	return (this->leftChild == nullptr && this->rightChild == nullptr);
}

template<class T>
void CueBinaryTreeNode<T>::operator=(const CueBinaryTreeNode<T> obj) {
	this->data == obj.getData();
	this->leftChild = obj.getLeftChild();
	this->rightChild = obj.getRightChild();
}


template<class T>
void CueBinaryTreeNode<T>::setLeftTag(int l) {
	this->leftTag = l;
}

template<class T>
void CueBinaryTreeNode<T>::setRightTag(int r) {
	this->rightTag = r;
}

template<class T>
int CueBinaryTreeNode<T>::getLeftTag() {
	return this->leftTag;
}

template<class T>
int CueBinaryTreeNode<T>::getRightTag() {
	return this->rightTag;
}
