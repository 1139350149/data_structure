#pragma once
template<class T>
class Edge {
public:
	int start, end;
	T weight;
	Edge();
	Edge(int start, int end, T weight);
	bool operator >(Edge oneEdge);
	bool operator <(Edge oneEdge);
};

template<class T>
Edge<T>::Edge() {
	this->start = this->end = -1;
	this->weight = 0;
}

template<class T>
Edge<T>::Edge(int start, int end, T weight) {
	this->start = start;
	this->end = end;
	this->weight = weight;
}

template<class T>
bool Edge<T>::operator >(Edge oneEdge) {
	if (this->weight > oneEdge.weight) {
		return true;
	}
	else {
		return false;
	}
}

template<class T>
bool Edge<T>::operator <(Edge oneEdge){
	if (this->weight < oneEdge.weight) {
		return true;
	}
	else {
		return false;
	}
}