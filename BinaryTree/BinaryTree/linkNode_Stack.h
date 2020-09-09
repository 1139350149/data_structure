#pragma once
#include <iostream>

using namespace std;

template <typename T>
class LinkeNode {
public:
	T data;
	LinkeNode* next;
	LinkeNode(T data, LinkeNode<T>* next = nullptr);
};

template <typename T>
LinkeNode<T>::LinkeNode(T data, LinkeNode<T>* next) {
	this->data = data;
	this->next = next;
}