#pragma once

template<class T>
class Node {
public:
	int index;
	T weight;
	Node<T> * next;
	Node() {
		index = -1;
		next = nullptr;
	}
	Node(int index, T weight);
};

template<class T>
Node<T>::Node(int index, T weight) {
	this->index = index;
	this->weight = weight;
	next = nullptr;
}