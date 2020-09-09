#pragma once

template<class T>
class maxHeap {
private:
	T* heapData;
	int maxSize, currentSize;
public:
	maxHeap(T* Array, int size, int max);
	~maxHeap() {};
	void BuildHeap();
	bool isLeaf(int pos) const;
	int leftChild(int pos) const;
	int rightChild(int pos) const;
	int parent(int pos) const;
	bool remove(int pos, T& node);
	void siftDown(int left);
	void siftUp(int position);
	bool insert(const T& newNode);
	T& RemoveMax();
	void BreadthOrder();
};

template<class T>
maxHeap<T>::maxHeap(T* Array, int size, int max) {
	heapData = Array;
	currentSize = size;
	maxSize = max;
}

template<class T>
void maxHeap<T>::BuildHeap() {
	for (int i = currentSize / 2 - 1; i >= 0; i--) {
		siftUp(i);
	}
}
template<class T>
void maxHeap<T>::siftDown(int left) {
	int i = left;
	int j = 2 * i + 1;
	T temp = heapData[i];

	while (j < currentSize) {
		if (j < currentSize - 1 && heapData[j] < heapData[j + 1]) {
			j++;
		}
		if (temp < heapData[j]) {
			heapData[i] = heapData[j];
			i = j;
			j = j * 2 + 1;
		}
		else {
			break;
		}
	}
	heapData[i] = temp;
}

template<class T>
bool maxHeap<T>::isLeaf(int pos) const {
	return (pos >= currentSize / 2) && (pos < currentSize);
}

template<class T>
int maxHeap<T>::leftChild(int pos) const {
	return (pos * 2 + 1);
}

template<class T>
int maxHeap<T>::rightChild(int pos) const {
	return (pos * 2 + 2);
}

template<class T>
int maxHeap<T>::parent(int pos) const {
	return ((pos - 1) / 2);
}

template<class T>
bool maxHeap<T>::remove(int pos, T& node) {
	if ((pos < 0) || (pos >= currentSize))     return false;
	node = heapData[pos];
	heapData[pos] = heapData[--currentSize];	
	if (heapData[parent(pos)] < heapData[pos])
		siftUp(pos);			
	else siftUp(pos);			
	return true;
}

template<class T>
void maxHeap<T>::siftUp(int pos) {
	int temppos = pos;
	T temp = heapData[temppos];
	while ((temppos > 0) && (heapData[parent(temppos)] < temp)) {
		heapData[temppos] = heapData[parent(temppos)];
		temppos = parent(temppos);
	}
	heapData[temppos] = temp;

}

template<class T>
bool maxHeap<T>::insert(const T& newNode) {
	for (int i = 0; i < currentSize; i++) {
		cout << i <<ends << heapData[i] << endl;
	}
	if (currentSize == maxSize)
		return false;                                       // 堆空间已经满
	heapData[currentSize] = newNode;
	siftUp(currentSize);
	currentSize++;
	return true;
}

template<class T>
T& maxHeap<T>::RemoveMax() {
	if (currentSize == 0) {
		cout << "Can't Delete";		// 调用RemoveMin之前，需要判断堆非空
		exit(1);
	}
	else {
		T temp = heapData[0];	                 // 交换堆顶和最后一个元素
		heapData[0] = heapData[currentSize - 1];
		heapData[--currentSize] = temp;
		if (currentSize > 1)  
			siftDown(0);          // 从堆顶开始筛选
		return heapData[currentSize];
	}
}

template<class T>
void maxHeap<T>::BreadthOrder() {
	for (int i = 0; i < currentSize; i++) {
		cout << heapData[i] << endl;
	}
}

