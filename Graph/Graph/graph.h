#pragma once
#include "Edge.h"

enum TYPE
{
	UNVISITED, VISITED
};

template<class T>
class Graph {
public:
	

	Graph(int n);
	~Graph() {
	}
	int getVertexNum() { return this->vertexNum; }
	int getEdgeNum() { return this->edgeNum; }
	bool isEdge(Edge<T> oneEdge) {
		if (oneEdge.weight > 0 && oneEdge.end > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	int getStart(Edge<T> oneEdge) {
		return oneEdge.start;
	}
	int getEnd(Edge<T> oneEdge) {
		return oneEdge.start;
	}
	T getWeight(Edge<T> oneEdge) {
		return oneEdge.weight;
	}
};

template<class T>
Graph<T>::Graph(int n) {}