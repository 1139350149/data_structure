#pragma once
#include <iostream>
#include "LinkNode.h"

using namespace std;

template <typename T>
class ForwardList
{
public:
	ForwardList();
	~ForwardList();
	int getsize() const;
	bool isEmpty() const;
	void reset(int pos = 0);		//初始化指针位置
	void next();
	bool endOfList() const;
	int currentPosition() const;
	void insertHead(const T& item);
	void insertTail(const T& item);
	void insertAt(const T& item);
	void insertAfter(const T& item);
	T deleteHead();
	void deleteCurrent();
	T& data();
	const T& data() const;
	void clear();
	LinkNode<T>* setPos(int pos);
	bool insertPos(const int, const T value);
	bool deletePos(const int i);

	void reverse();
	LinkNode<T>* getHead() const;
	ForwardList<T>& upSort(ForwardList<T>& obj);
	void printList();

private:
	LinkNode<T> *head, *tail;
	LinkNode<T> *prevPtr, *currPtr;

	int position;
};


#include "ForwardList.h"


template <typename T>
ForwardList<T>::ForwardList() {
	head = nullptr;
	tail = nullptr;
	position = -1;
}

template <typename T>
ForwardList<T>::~ForwardList() {
	LinkNode<T>* p = nullptr;
	while (head && head->link) {
		p = head->link;
		delete head;
		head = p;
	}
}

template <typename T>
int ForwardList<T>::getsize() const {
	int count = 0;
	LinkNode<T>* temp = head;
	while (temp) {
		count++;
		temp = temp->link;
	}
	return count;
}

template <typename T>
bool ForwardList<T> ::isEmpty() const {
	return head;
}

template <typename T>
void ForwardList<T> ::reset(int pos) {
	if (pos < 0 || pos >= getsize()) {
		if (head) {
			position = 0;
			currPtr = head;
			prevPtr = nullptr;
		}
		else {
			currPtr = nullptr;
			prevPtr = nullptr;
			position = -1;
		}
	}
	position = pos;
	if (pos == 0) {
		currPtr = head;
		prevPtr = nullptr;
	}
	if (head) {
		LinkNode<T>* p = head;
		int count = 0;
		while (p->link) {
			p = p->link;
			count++;
			if (count == pos - 1) {
				prevPtr = p;
			}
			if (count == pos) {
				currPtr = p;
			}
		}
	}

}

template <typename T>
void ForwardList<T> ::next() {
	if (currPtr && currPtr->link) {
		prevPtr = currPtr;
		currPtr = currPtr->link;
		position += 1;
	}
}

template <typename T>
bool ForwardList<T> ::endOfList() const {
	return (currPtr == tail);
}

template <typename T>
int ForwardList<T> ::currentPosition() const {
	return position;
}

template <typename T>
void ForwardList<T> ::insertHead(const T& item) {
	LinkNode<T> * p = new LinkNode<T>(item);
	if (head == nullptr) {
		head = p;
		head->link = nullptr;
		tail = p;
		tail->link = nullptr;
		currPtr = head;
		position = 0;
	}
	else {
		if (head->link) {
			p->link = head->link;
			head->link = p;
		}
		else {
			head->link = p;
			tail = p;
		}
	}
}

template <typename T>
void ForwardList<T> ::insertTail(const T& item) {
	LinkNode<T> * p = new LinkNode<T>(item);
	if (!head) {
		head = p;
		tail = p;
		head->link = nullptr;
		tail->link = nullptr;
		currPtr = head;
		position = 0;
	}
	else {
		tail->link = p;
		tail = p;
	}
}

template <typename T>
void ForwardList<T> ::insertAfter(const T& item) {
	LinkNode<T> * p = new LinkNode<T>(item);
	if (currPtr->link) {
		p.link = currPtr->link;
		currPtr->link = p;
	}
	else {
		currPtr->link = p;
		tail = p;
	}
}

template <typename T>
void ForwardList<T> ::insertAt(const T& item) {
	LinkNode<T> * p = new LinkNode<T>(item);
	p->link = currPtr;
	prevPtr->link = p;
	prevPtr = p;
	position++;
}

template <typename T>
T ForwardList<T> ::deleteHead() {
	if (head) {
		T temp = head->data;
		LinkNode<T> * p = head;
		if (head->link) {
			head = head->link;
		}
		else {
			head = nullptr;
		}
		position--;
		delete p;
		return temp;
	}
	return 0;
}

template <typename T>
void ForwardList<T> ::deleteCurrent() {
	LinkNode<T>* p = currPtr;
	if (currPtr->link) {
		currPtr = currPtr->link;
	}
	if (head) {
		reset(0);
	}
	else {
		reset(-1);
	}
	delete p;
}

template <typename T>
T& ForwardList<T> ::data() {
	if (currPtr) {
		return currPtr->data;
	}
}

template <typename T>
const T& ForwardList<T> ::data() const {
	if (currPtr) {
		return currPtr->data;
	}
}

template <typename T>
void ForwardList<T> ::clear() {
	LinkNode<T>* p;
	while (head->link) {
		p = head->link;
		delete head;
		head = p;
	}
	reset(0);
}

template <typename T>
LinkNode<T>* ForwardList<T> ::setPos(int pos) {
	if (pos >= getsize() || pos < 0) {
		return nullptr;
	}
	else {
		int count = 0;
		LinkNode<T>* p = head;
		while (p->link) {
			p = p->link;
			count++;
			if (count == pos) {
				return p;
			}
		}
	}
}

template <typename T>
bool ForwardList<T> ::insertPos(const int pos, const T value) {
	reset(0);
	if (head && pos < getsize()) {
		int count = 0;
		while (currPtr->link()) {
			next();
			count++;
			if (count = pos) {
				insertAfter(value);
				return true;
			}
		}
	}
	return false;
}

template <typename T>
bool ForwardList<T> ::deletePos(const int pos) {
	reset(0);
	if (head && pos < getsize()) {
		int count = 0;
		while (currPtr->link()) {
			next();
			count++;
			if (count = pos) {
				deleteCurrent();
				return true;
			}
		}
	}
	return false;
}

template <typename T>
void ForwardList<T> ::reverse() {
	if (NULL == head || NULL == head->link) return;    //少于两个节点没有反转的必要。
	LinkNode<T> *p, *q, *r;
	p = head;
	q = head->link;
	head->link = NULL; //旧的头指针是新的尾指针，link需要指向nullptr
	while (q) {
		r = q->link; //先保留下一个step要处理的指针
		q->link = p; //然后p q交替工作进行反向
		p = q;
		q = r;
	}
	tail = head;
	head = p; // 最后q必然指向空，所以返回了p作为新的头指针
}

template <typename T>
LinkNode<T>* ForwardList<T>::getHead() const {
	return head;
}

template <typename T>
ForwardList<T>& ForwardList<T>::upSort(ForwardList<T>& obj) {
	LinkNode<T>* p1, *p2, *pr;
	pr = this->getHead();
	p1 = this->getHead()->link;
	p2 = obj.getHead()->link;
	while (p1 || p2) {
		if (p1 && p2) {
			if (p1->data < p2->data) {
				pr->link = p1;
				p1 = p1->link;
			}
			else {
				pr->link = p2;
				p2 = p2->link;
			}
		}
		else if (p1) {
			pr->link = p1;
			p1 = p1->link;
		}
		else if (p2) {
			pr->link = p2;
			p2 = p2->link;
		}
		pr = pr->link;
	}
	delete obj.getHead();
	return *this;
}

template <typename T>
void ForwardList<T>::printList() {
	LinkNode<T>* p = this->head;
	while (p) {
		cout << p->data << endl;
		p = p->link;
	}
}