#pragma once
#include "listNode.h"

template<class T>
class listData {
public:
	Node<T> * Edge;
	listData() {
		Edge = nullptr;
	}
	listData(Node<T>* node) {
		Edge = node;
	}
};

