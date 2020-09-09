#pragma once
#include "DLLNode.h"

template <typename T>
class BiLinkedList
{
public:
	BiLinkedList();
	~BiLinkedList();
	void insertHead(T& obj);
	void insertAt(const int pos, T& obj);
	void insertAfter(const int pos, T& obj);
	void insertTail(T& obj);
	void printList();
	bool deleteNodeByPos(const int pos);
	bool deleteNodeByValue(const T value);
	void clear();
	const T& getData(const int pos) const;
	T& getData(const int pos);
	int getSize();

	DllNode<T>* getNode(int pos);
	void Nothing();

private:
	DllNode<T> *head, *tail;
	int length;
};

template <typename T>
BiLinkedList<T>::BiLinkedList() {
	head = nullptr;
	tail = nullptr;
	length = 0;
}

template <typename T>
BiLinkedList<T>::~BiLinkedList() {
	DllNode<T>* p = head->next;
	int count = 0;
	while (count < length) {
		delete	head;
		head = p;
		p = p->next;
		count++;
	}
	length = 0;
}

template <typename T>
void BiLinkedList<T>::clear() {
	DllNode<T>* p = head->next;
	while (head) {
		delete	head;
		head = p;
		p = p->next;
	}
	length = 0;
}


template <typename T>
T& BiLinkedList<T> ::getData(const int pos) {
	if (length) {
		if (pos) {
			int count = -1;
			DllNode<T>* p = head;
			while (p) {
				count++;
				if (count == pos) {
					return p->data;
				}
				p = p->next;
			}
		}
		else {
			return head->data;
		}
	}
	else {
		throw std::out_of_range;
	}
}

template <typename T>
const T& BiLinkedList<T>::getData(const int pos) const {
	if (length) {
		if (pos) {
			int count = -1;
			DllNode<T>* p = head;
			while (p) {
				count++;
				if (count == pos) {
					return p->data;
				}
				p = p->next;
			}
		}
		else {
			return head->data;
		}
	}
	else {
		throw std::out_of_range;
	}
}

template <typename T>
void BiLinkedList<T>::insertHead(T& obj) {
	DllNode<T> *p = new DllNode<T>(obj);
	if (!head) {
		head = tail = p;
		head->next = tail;
		head->prev = tail;
		tail->next = head;
		tail->prev = head;
	}
	else if (head->next == head) {
		tail = p;
		head->next = p;
		head->prev = p;
		p->next = head;
		p->prev = head;
	}
	else {
		head->next->prev = p;
		p->next = head->next;
		p->prev = head;
		head->next = p;
	}
	length++;
}

template <typename T>
void BiLinkedList<T>::insertAt(const int pos, T& obj){
	if (pos > -1 && pos < length - 1) {
		DllNode<T>* temp = new DllNode<T>(obj);
		if (pos) {
			int count = -1;
			DllNode<T>* p = head;
			while (p) {
				count++;
				if (count == pos) {
					p = p->prev;
					temp->next = p->next;
					p->next->prev = temp;
					temp->prev = p;
					p->next = temp;
					break;
				}
				p = p->next;
			}
		}
	}
	else {
		insertTail(obj);
	}
	length++;
}

template <typename T>
void BiLinkedList<T> ::insertAfter(const int pos, T& obj) {
	if (pos > -1 && pos < length - 1) {
		DllNode<T>* temp = new DllNode<T>(obj);
		if (pos) {
			int count = -1;
			DllNode<T>* p = head;
			while (p) {
				count++;
				if (count == pos) {
					temp->next = p->next;
					p->next->prev = temp;
					temp->prev = p;
					p->next = temp;
					break;
				}
				p = p->next;
			}
		}
	}
	else {
		insertTail(obj);
	}
	length++;
}

template <typename T>
void BiLinkedList<T>::insertTail(T& obj) {
	if (!head) {
		insertHead(obj);
	}
	else {
		DllNode<T>* p = new DllNode<T>(obj);
		tail->next = p;
		p->prev = tail;
		p->next = head;
		head->prev = p;
		tail = p;
		length++;
	}
}

template <typename T>
void BiLinkedList<T>::printList() {
	cout << "该循环链表长度是" << length << endl << "元素有:" << endl;
	DllNode<T>* p = head;
	int count = 0;
	while (count != length) {
		cout << p->data;
		count++;
		p = p->next;
	}
}

template <typename T>
int BiLinkedList<T>::getSize() {
	return length;
}

template <typename T>
bool BiLinkedList<T>::deleteNodeByPos(const int pos) {
	if (pos < 0 || pos > length - 1) {
		return false;
	}
	else {
		int count = 0;
		DllNode<T>* p = head;
		while (count != length) {
			if (count == pos) {
				if (pos == 0) {
					head = p->next;
				}
				else if (pos == length - 1) {
					tail = p->prev;
				}
				p->prev->next = p->next;
				p->next->prev = p->prev;
				delete p;
				length--;
				return true;
			}
			count++;
			p = p->next;
		}
		return false;
	}
}

template <typename T>
bool BiLinkedList<T> ::deleteNodeByValue(T value) {
	int count = 0;
	DllNode<T>* p = head;
	while (count != length) {
		if (p->data == value) {
			if (count == 0) {
				head = p->next;
			}
			else if (count == length - 1) {
				tail = p->prev;
			}
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			length--;
			return true;
		}
		count++;
		p = p->next;
	}
	return false;
}

template <typename T>
DllNode<T>*  BiLinkedList<T>::getNode(int pos) {
	if (pos < 0 || pos >= length) {
		return head;
	}
	int count = 0;
	DllNode<T>* p = head;
	while (count != length) {
		if (count == pos) {
			return p;
		}
		p = p->next;
		count++;
	}
}

template <typename T>
void BiLinkedList<T>::Nothing() {
	DllNode<T>* p, *p2;
	int count;
	if (length % 2) {
		p = tail->prev;
		count = 1;
	}
	else {
		p = tail->prev->prev;
		count = 0;
	}
	while (p != head) {
		p2 = p->prev;
		if (!(count % 2)) {
			p->prev->next = p->next;
			p->next->prev = p->prev;
			tail->next = p;
			p->prev = tail;
			p->next = head;
			head->prev = p;
			tail = p;
		}
		p = p2;
		cout << endl << p->data << endl;
		count++;
		printList();
	}
}