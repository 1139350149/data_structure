#pragma once
#include "TreeNode.h"
#include <queue>

template<class T>
class Huffman {
public:
	TreeNode<T> * root;
	string * code;
	T* data;
	int length;

	Huffman();
	Huffman(T* data, int* item, int n);
	TreeNode<T> * mergeTree(TreeNode<T> ht1, TreeNode<T> ht2, TreeNode<T> * parent);
	~Huffman();
	void deleteTree(TreeNode<T> * root);
	void breadthFirstOrder(TreeNode<T> * root);
	TreeNode<T> & getMin(TreeNode<T>  nodeArray[], int l);
	void Coding(TreeNode<T> * root, string temp = "" );
	string Encoding(string target);
	string ToBinary(string txt);
};

template<class T>
Huffman<T>::Huffman() {
	this->root = nullptr;
}

template<class T>
Huffman<T>::Huffman(T* data, int* item, int n) {
	code = new string[n];
	this->length = n;
	this->data = new T[n];
	TreeNode<T> Nodelist[30];
	for (int i = 0; i < n; i++) {
		this->data[i] = data[i];
		Nodelist[i].data = data[i];
		Nodelist[i].weight = item[i];
	}
	int j = n;
	TreeNode<T> * parent = nullptr, * first, * second;
	while (j > 1) {
		first = new TreeNode<T>(getMin(Nodelist, j--));
		second = new TreeNode<T>(getMin(Nodelist, j--));
		parent = new TreeNode<T>('\0', first->weight + second->weight, first, second);
		Nodelist[j++] = *parent;
	}
	this->root = parent;
}

template<class T>
Huffman<T>::~Huffman() {
	deleteTree(this->root);
}

template<class T>
void Huffman<T>::deleteTree(TreeNode<T> * root) {
	if (root) {
		delete(root->leftNode);
		delete(root->rightNode);
		delete root;
		root = nullptr;
	}
}

template<class T>
TreeNode<T> * Huffman<T>::mergeTree(TreeNode<T> ht1, TreeNode<T> ht2, TreeNode<T> * parent) {
	if (parent) {
		parent->weight = ht1.weight + ht2.weight;
		parent->leftNode = &ht1;
		parent->rightNode = &ht2;
		return parent;
	}
}

template<class T>
void Huffman<T>::breadthFirstOrder(TreeNode<T> * root) {
	queue<TreeNode<T> * > nodeQueue;
	int count = 1;
	TreeNode<T>* pointer = root;
	if (pointer) {
		nodeQueue.push(pointer);
	}
	while (!nodeQueue.empty()) {
		pointer = nodeQueue.front();
		cout << count++ << " " << pointer->getData() << endl;
		nodeQueue.pop();
		if (pointer->getLeftChild()) {
			nodeQueue.push(pointer->getLeftChild());
		}
		if (pointer->getRightChild()) {
			nodeQueue.push(pointer->getRightChild());
		}
	}
}

template<class T>
TreeNode<T> & Huffman<T>::getMin(TreeNode<T> nodeArray[], int l) {
	if (l) {
		TreeNode<T> temp = nodeArray[0];
		int k = 0;
		for (int i = 1; i < l; i++) {
			if (temp > nodeArray[i]) {
				temp = nodeArray[i];
				k = i;
			}
		}
		nodeArray[k] = nodeArray[l - 1];
		return temp;
	}
}

template<class T>
void Huffman<T>::Coding(TreeNode<T> * root, string temp) {
	if (root) {
		if (root->data != '\0') {
			for (int i = 0; i < length; i++) {
				if (this->data[i] == root->data) {
					code[i] = temp;
				}
			}
		}
		if (root->leftNode) {
			Coding(root->leftNode, temp + "0");
		}
		if (root->rightNode) {
			Coding(root->rightNode, temp + "1");
		}
	}
	else {
		return;
	}
}

template<class T>
string Huffman<T>::Encoding(string target) {	//	将二进制转换为字符
	string temp = "", res = "";
	for (int i = 0; i < target.length(); i++) {
		if (target[i] != ' ') {
			temp += target[i];
		}
		else {
			for (int i = 0; i < length; i++) {
				if (code[i] == temp) {
					res += data[i];
					temp = "";
					break;
				}
				if (i == length) {
					return "目标不在编码范围内!";
				}
			}
		}
	}
	return res;
}

template<class T>
string Huffman<T>::ToBinary(string txt) {
	string  res = "";
	for (int i = 0; i < txt.length(); i++) {
		for (int j = 0; j < length; j++) {
			if (txt[i] == data[i]) {
				if (i != 0) {
					res += ' ';
				}
				res += code[i];
				break;
			}
			if (j == length) {
				return "目标不在编码范围内!";
			}
		}
	}
	return res;
}
