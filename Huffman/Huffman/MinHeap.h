#pragma once

template<class T>
class minHeap {
private:
	T heapData[30];
	int maxSize, currentSize;
public:
	minHeap(const T* Array, int size, int max);
	minHeap() {
		heapData = new T[20];
		maxSize = 20;
		currentSize = 0;
	}
	~minHeap() {};
	void BuildHeap();
	bool isLeaf(int pos) const;
	int leftChild(int pos) const;
	int rightChild(int pos) const;
	int parent(int pos) const;
	bool remove(int pos, T& node);
	void siftDown(int left);
	void siftUp(int position);
	bool insert(const T newNode);
	bool insert(const T * newNode);
	T RemoveMin();
	void BreadthOrder();
	int getSize();
};

template<class T>
minHeap<T>::minHeap(const T* Array, int size, int max) {
	/*heapData = new T[max];*/
	for (int i = 0; i < size; i++) {
		heapData[i] = Array[i];
	}
	currentSize = size;
	maxSize = max;
	BuildHeap();
	BreadthOrder();
	cout << "建堆完毕" << endl;
}

template<class T>
void minHeap<T>::BuildHeap() {
	for (int i = currentSize / 2 - 1; i >= 0; i--) {
		siftDown(i);
	}
}
template<class T>
void minHeap<T>::siftDown(int left) {
	int i = left;
	int j = 2 * i + 1;
	T temp = heapData[i];

	while (j < currentSize) {
		if (j < currentSize - 1 && heapData[j] > heapData[j + 1]) {
			j++;
		}
		if (temp > heapData[j]) {
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
bool minHeap<T>::isLeaf(int pos) const {
	return (pos >= currentSize / 2) && (pos < currentSize);
}

template<class T>
int minHeap<T>::leftChild(int pos) const {
	return (pos * 2 + 1);
}

template<class T>
int minHeap<T>::rightChild(int pos) const {
	return (pos * 2 + 2);
}

template<class T>
int minHeap<T>::parent(int pos) const {
	return ((pos - 1) / 2);
}

template<class T>
bool minHeap<T>::remove(int pos, T& node) {
	if ((pos < 0) || (pos >= currentSize))     return false;
	node = heapData[pos];
	heapData[pos] = heapData[--currentSize];
	if (heapData[parent(pos)] > heapData[pos])
		siftUp(pos);
	else siftUp(pos);
	return true;
}

template<class T>
void minHeap<T>::siftUp(int pos) {
	int temppos = pos;
	T temp = heapData[temppos];
	while ((temppos > 0) && (heapData[parent(temppos)] > temp)) {
		heapData[temppos] = heapData[parent(temppos)];
		temppos = parent(temppos);
	}
	heapData[temppos] = temp;

}

template<class T>
bool minHeap<T>::insert(const T newNode) {
	//for (int i = 0; i < currentSize; i++) {
	//	cout << i << ends << heapData[i] << endl;
	//}
	if (currentSize == maxSize)
		return false;                                       // 堆空间已经满
	heapData[currentSize] = newNode;
	siftUp(currentSize);
	currentSize++;
	return true;
}

template<class T>
bool minHeap<T>::insert(const T * newNode) {
	//for (int i = 0; i < currentSize; i++) {
	//	cout << i << ends << heapData[i] << endl;
	//}
	if (currentSize == maxSize)
		return false;                                       // 堆空间已经满
	heapData[currentSize] = *newNode;
	siftUp(currentSize);
	currentSize++;
	return true;
}

template<class T>
T minHeap<T>::RemoveMin() {
	if (currentSize == 0) {
		cout << "Can't Delete";		// 调用RemoveMin之前，需要判断堆非空
		exit(1);
	}
	else {
		T temp = heapData[0];	                 // 交换堆顶和最后一个元素
		heapData[0] = heapData[currentSize - 1];
		currentSize -= 1;
		if (currentSize > 1)
			siftDown(0);          // 从堆顶开始筛选
		return temp;
	}
}

template<class T>
void minHeap<T>::BreadthOrder() {
	for (int i = 0; i < currentSize; i++) {
		cout << heapData[i] << endl;
	}
}

template<class T>
int minHeap<T>::getSize() {
	return this->currentSize;
}
