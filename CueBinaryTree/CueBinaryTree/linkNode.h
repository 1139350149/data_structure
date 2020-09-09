#pragma once

template<class T>
class linkNode {
private:
	T data;
	linkNode<T> * next, *prev;
public:
	linkNode(T data, linkNode<T> * link) {
		this->data = data;
		this->next = link;
		this->prev = nullptr;
	}
	linkNode(T data) {
		this->data = data;
		this->prev = this->next = nullptr;
	}
	void setNext(linkNode<T> * next) {
		this->next = next;
	}
	linkNode<T> * getNext() {
		return this->next;
	}
	T getData() {
		return this->data;
	}
	linkNode<T> * getPrev() {
		return this->prev;
	}
};