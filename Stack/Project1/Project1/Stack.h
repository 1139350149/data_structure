#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Stack
{
public:
	Stack(int size = 10);
	~Stack();
	bool IsEmpty() const;
	bool IsFull() const;
	T Top() const;
	Stack<T>& Push(const T& x);
	Stack<T>& Pop(T& x);
	void Clear();

	int getTop();
	int getMaxTop();
	T* getStack();
private:
	int top; //Õ»¶¥
	int MaxTop;	//×î´óÈÝÁ¿
	T* stack; //Õ»
};

template <typename T>
Stack<T>::Stack(int size) {
	MaxTop = size;
	stack = new T[MaxTop];
	top = -1;
}

template <typename T>
Stack<T>::~Stack() {
	if (stack) {
		delete[] stack;
	}
}

template <typename T>
bool Stack<T>::IsEmpty() const {
	return (top == 0);
}

template <typename T>
bool Stack<T>::IsFull() const {
	return (top == MaxTop - 1);
}

template <typename T>
T Stack<T>::Top() const {
	return stack[top];
}

template <typename T>
Stack<T>& Stack<T>::Push(const T& obj) {
	if (this->IsFull()) {
		T* myStack = new T[2 * MaxTop];
		for (int i = 0; i < MaxTop; i++) {
			myStack[i] = stack[i];
		}
		delete[] stack;
		stack = myStack;
		MaxTop *= 2;
	}
	stack[++top] = obj;
	return *this;
}

template <typename T>
Stack<T>& Stack<T>::Pop(T& obj) {
	if (this->IsEmpty()) {
		return *this;
	}
	obj = stack[top--];
	return *this;
}

template <typename T>
void Stack<T>::Clear() {
	top = -1;
}

template <typename T>
int Stack<T>::getMaxTop() {
	return MaxTop;
}

template <typename T>
int Stack<T>::getTop() {
	return top;
}

template <typename T>
T* Stack<T>::getStack() {
	return stack;
}
template <typename T>
ostream& operator << (ostream& out,Stack<T>& obj) {
	for (int i = 0; i <= obj.getTop(); i++) {
		cout << obj.getStack()[i] << ends;
	}
	return out;
}