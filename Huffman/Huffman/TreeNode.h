#pragma once
#include <string>
#include <iostream>

using namespace std;

template<class T>
class TreeNode {
public:
	T data;
	int weight;
	TreeNode<T> * leftNode, *rightNode;

	TreeNode();
	TreeNode(TreeNode<T> * node) {
		this->data = node->data;
		this->weight = node->weight;
		this->leftNode = node->leftNode;
		this->rightNode = node->rightNode;
	}
	TreeNode(const T data);
	TreeNode(const T data, int weight);
	TreeNode(const T data, TreeNode<T>* l, TreeNode<T>* r);
	TreeNode(const T data, int weight, TreeNode<T>* l, TreeNode<T>* r);
	TreeNode<T> *getLeftChild() const;
	TreeNode<T> *getRightChild() const;
	void setLeftChild(TreeNode<T> * l);
	void setRightChild(TreeNode<T> * r);
	T getData() const;
	void setData(const T& data);
	bool isLeaf() const;
	void operator=(const TreeNode<T> & node);
	friend ostream& operator <<(ostream & out, TreeNode<T> & node) {
		cout << node.data << ends <<  node.weight << endl;
		return cout;
	}
	bool operator <(TreeNode<T> & temp) {
		if (this->weight < temp.weight) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator >(TreeNode<T> & temp) {
		if (this->weight > temp.weight) {
			return true;
		}
		else {
			return false;
		}
	}
};

template<class T>
TreeNode<T>::TreeNode() {
	this->leftNode = this->rightNode = nullptr;
	this->weight = 0;
	this->data = 0;
}

template<class T>
TreeNode<T>::TreeNode(const T data) {
	this->data = data;
	this->leftNode = this->rightNode = nullptr;
	this->weight = 0;
}

template<class T>
TreeNode<T>::TreeNode(const T data, int weight) {
	this->data = data;
	this->weight = weight;
	this->rightNode = this->leftNode = nullptr;
}

template<class T>
TreeNode<T>::TreeNode(const T data, TreeNode<T>* l, TreeNode<T>* r) {
	this->data = data;
	this->leftNode = l;
	this->rightNode = r;
}

template<class T>
TreeNode<T>::TreeNode(const T data, int weight, TreeNode<T>* l, TreeNode<T>* r) {
	this->data = data;
	this->weight = weight;
	this->leftNode = l;
	this->rightNode = r;
}

template<class T>
TreeNode<T>* TreeNode<T>::getLeftChild() const {
	return this->leftNode;
}

template<class T>
TreeNode<T>* TreeNode<T>::getRightChild() const {
	return this->rightNode;
}

template<class T>
void TreeNode<T>::setLeftChild(TreeNode<T> * l) {
	this->leftNode = l;
}

template<class T>
void TreeNode<T>::setRightChild(TreeNode<T> * r) {
	this->rightNode = r;
}

template<class T>
T TreeNode<T>::getData() const {
	return this->data;
}

template<class T>
void TreeNode<T>::setData(const T& data) {
	this->data = data;
}

template<class T>
bool TreeNode<T>::isLeaf() const {
	return (this->leftNode == nullptr && this->rightNode == nullptr);
}

template<class T>
void TreeNode<T>::operator=(const TreeNode<T> & obj) {
	this->data = obj.data;
	this->leftNode = obj.leftNode;
	this->rightNode = obj.rightNode;
	this->weight = obj.weight;
}
