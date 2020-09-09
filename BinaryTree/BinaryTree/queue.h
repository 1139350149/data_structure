#pragma once
#include "linkNode.h"

template<class T>
class Queue {
private:
	int size;
	linkNode<T> * front, *rear;
public:
	Queue();
	~Queue();
	void clear();
	bool EnQueue(const T& item);
	bool DeQueue(T item);
	T getFront() const;
	bool isEmpty() const;
	int getSize() const;
};

template<class T>
Queue<T>::Queue() {
	this->size = 0;
	this->front = nullptr;
	this->rear = nullptr;
}

template<class T>
Queue<T>::~Queue() {
	this->clear();
}

template<class T>
void Queue<T>::clear() {
	while (front) {
		rear = front;
		front = front->getNext();
		delete rear;
	}
	rear = nullptr;
	size = 0;
}

template<class T>
bool Queue<T>::EnQueue(const T& item) {
	linkNode<T> * link = new linkNode<T>(item);
	if (this->rear == nullptr) {
		this->front = this->rear = link;
	}
	else {
		this->rear->setNext(link);
		this->rear = this->rear->getNext();
	}
	size++;
	return true;
}

template<class T>
bool Queue<T>::DeQueue(T item) {
	if (this->size == 0) {
		return false;
	}
	item = this->front->getData();
	this->front = this->front->getNext();
	if (this->front == nullptr) {
		this->rear = nullptr;
	}
	size--;
	return true;
}

template<class T>
T Queue<T>::getFront() const {
	if (this->front == nullptr) {
		return 0;
	}
	return this->front->getData();
}

template<class T>
bool Queue<T>::isEmpty() const {
	return (this->size == 0);
}

template<class T>
int Queue<T>::getSize() const {
	return this->size;
}