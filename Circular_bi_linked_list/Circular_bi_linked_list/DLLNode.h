#pragma once
#include <iostream>

using namespace std;

template <typename T>
class DllNode {
public:
	T data;
	DllNode *prev, *next;
	DllNode(const T data, DllNode<T>* Prev = nullptr, DllNode<T>* Next = nullptr);
	DllNode(DllNode<T>* Prev = nullptr, DllNode<T>* Next = nullptr);
};


template <typename T>
DllNode<T>::DllNode(const T data, DllNode<T>* Prev, DllNode<T>* Next) {
	this->data = data;
	this->next = Next;
	this->prev = Prev;
}


template <typename T>
DllNode<T>::DllNode(DllNode<T>* Prev, DllNode<T>* Next) {
	this->next = Next;
	this->prev = Prev;
}