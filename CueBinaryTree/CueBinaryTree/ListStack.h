#pragma once
#include "LinkNode_Stack.h"

template <typename T>
class ListStack {
private:
	LinkeNode<T>* top;
	int size;
public:
	ListStack();
	~ListStack();
	void clear();
	bool push(const T item);
	bool pop(T& item);
	bool Top(T& item);
	bool isEmpty();
};

template <typename T>
ListStack<T>::ListStack() {
	top = nullptr;
	size = 0;
}

template <typename T>
ListStack<T>::~ListStack() {
	clear();
}

template <typename T>
void ListStack<T>::clear() {
	while (top) {
		LinkeNode<T>* p = top;
		top = top->next;
		delete p;
	}
	size = 0;
}

template <typename T>
bool ListStack<T>::push(const T item) {
	LinkeNode<T> * p = new LinkeNode<T >(item, top);
	top = p;
	size++;
	return true;
}

template <typename T>
bool ListStack<T> ::pop(T& item) {
	LinkeNode<T>* p;
	if (size == 0) {
		cout << "Stack is Empty!" << endl;
		return false;
	}
	item = top->data;
	p = top->next;
	delete top;
	top = p;
	size--;
	return true;
}

template <typename T>
bool ListStack<T> ::Top(T& item) {
	if (size == 0) {
		item = 0;
		return false;
	}
	item = top->data;
	return true;
}

template<class T>
bool ListStack<T>::isEmpty() {
	return this->size == 0;
}