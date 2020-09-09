#pragma once
#include <iostream>

template <typename T>
class LinkNode
{
public:
	T data;
	LinkNode<T>* link;
	LinkNode(const T& element, LinkNode<T>* ptr = nullptr);
};

template <typename T>
LinkNode<T>::LinkNode(const T& element, LinkNode<T>* ptr) {
	data = element;
	link = ptr;
}