#pragma once
#include <memory>
#include <iostream>
#include <queue>
#define RADIX 10

using namespace std;

template<class T>
class linkNode {
public:
	T data;
	linkNode<T>* next;
};
template<class T>
class Queue {
public:
	Queue() {
		front = rear = nullptr;
	}
	linkNode<T> *front, *rear;
};

int KeySize(int a[], int n) {
	int key = 1;
	for (int i = 0; i < n; i++) {
		int temp = 1;
		int r = 10;
		while (a[i] / r > 0) {
			temp++;
			r *= 10;
		}
		key = (temp > key) ? temp : key;
	}
	return key;
}

void RadixSort(int a[], int n) //»ùÊýÅÅÐò
{
	int key = KeySize(a, n);
	int bucket[10][10] = { 0 };
	int order[10] = { 0 };
	for (int r = 1; key > 0; key--, r *= 10) {
		for (int i = 0; i < n; i++) {
			int lsd = (a[i] / r) % 10;
			bucket[lsd][order[lsd]++] = a[i];
		}

		int k = 0;
		for (int i = 0; i < 10; i++) {
			if (order[i] != 0) {
				for (int j = 0; j < order[i]; j++)
					a[k++] = bucket[i][j];
			}
			order[i] = 0;
		}
	}
}


template<class T>
class Sort {
public:
	static void insertSort(T *& data, int n);
	static void binaryInsertSort(T *& data, int n);
	static void shellSort(T *& data, int n);
	static void bubbleSort(T *& data, int n);
	static int partition(T *& data, int left, int right);
	static void quickSort(T *& data, int left, int right);
	static void selectionSort(T *& data, int n);
	static void merge(T *& data, int start, int mid, int end);
	static void mergeSort(T *& data, int start, int end);
};

template<class T>
void Sort<T>::insertSort(T *& data, int n) {
	if (n <= 1) {
		return;
	}
	if (data) {
		T temp;
		for (int i = 0; i < n; i++) {
			temp = data[i];
			int  j = i - 1;
			while (j >= 0 && temp < data[j]) {
				data[j + 1] = data[j];
				j = j - 1;
			}
			data[j + 1] = temp;
		}
	}
}
template<class T>
void Sort<T>::binaryInsertSort(T *& data, int n) {
	if (n <= 1) {
		return;
	}
	int left, right, mid, p;
	for (p = 1; p < n; p++) {
		T temp = data[p];
		left = 0;
		right = p - 1;
		while (left < right) {
			mid = (left + right) / 2;
			if (data[mid] > temp) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		for (int i = p - 1; i >= left; i--) {
			data[i + 1] = data[i];
		}
		data[left] = temp;
	}
}
template<class T>
void Sort<T>::shellSort(T *& data, int n) {
	if (n <= 1) {
		return;
	}
	int d = n / 2;
	while (d >= 1) {
		for (int k = 0; k < d; k++) {
			for (int i = k + d; i < n; i += d) {
				T temp = data[i];
				int j = i - d;
				while (j >= k && data[j] > temp) {
					data[j + d] = data[j];
					j -= d;
				}
				data[j + d] = temp;
			}
		}
		d /= 2;
	}
}
template<class T>
void Sort<T>::bubbleSort(T *& data, int n) {
	if (n <= 1) {
		return;
	}
	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n - i; j++) {
			if (data[j] < data[j - 1]) {
				flag = 1;
				T temp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = temp;
			}
			cout << i << ends << j << endl;
		}
	}
}
template<class T>
int Sort<T>::partition(T *& data, int left, int right) {
	T temp = data[left];
	while (left < right) {
		while (left < right && data[right] > temp) {
			right--;
		}
		data[left] = data[right];
		while (left < right && data[left] <= temp) {
			left++;
		}
		data[right] = data[left];
	}
	data[left] = temp;
	return left;
}
template<class T>
void Sort<T>::quickSort(T *& data, int left, int right) {
	if (left < right) {
		int p = partition(data, left, right);
		quickSort(data, left, p - 1);
		quickSort(data, p + 1, right);
	}
}
template<class T>
void Sort<T>::selectionSort(T *& data, int n) {
	for (int i = 0; i < n; i++) {
		int k = i - 1;
		for (int j = i; j < n; j++) {
			if (data[j] < data[k]) {
				k = j;
			}
		}
		if (k != i - 1) {
			T temp = data[k];
			data[k] = data[i - 1];
			data[i - 1] = temp;
		}
	}
}
template<class T>
void Sort<T>::merge(T *& data, int start, int mid, int end) {
	int len1 = mid - start + 1, len2 = end - mid;
	int i, j, k;
	T * left = new T[len1];
	T * right = new T[len2];
	for (i = 0; i < len1; i++) {
		left[i] = data[i + start];
	}
	for (i = 0; i < len2; i++) {
		right[i] = data[i + mid + 1];
	}
	i = 0, j = 0;
	for (k = start; k < end; k++) {
		if (i == len1 || j == len2) {
			break;
		}
		if(left[i] <= right[j]) {
			data[k] = left[i++];
		}
		else{
			data[k] = right[j++];
		}
	}
	while (i < len1) {
		data[k++] = left[i++];
	}
	while (j < len2) {
		data[k++] = right[j++];
	}
	delete[] left;
	delete[] right;
}
template<class T>
void Sort<T>::mergeSort(T *& data, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(data, start, mid);
		mergeSort(data, mid + 1, end);
		merge(data, start, mid, end);
		for (int i = 0; i < 9; i++) {
			cout << data[i] << ends;
		}
		cout << endl << "mergeSort################" << endl;
	}
}


