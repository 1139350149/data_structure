#pragma once
#include "graph.h"
#include "listData.h"
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

template<class T>
class listGraph: public Graph<T>
{
public:
	vector<listData<T>> graphVector;
	int edgeNum;
	int vertexNum;
	int *Mark;

	listGraph(int ** Martrix, int n);
	Edge<T>* firstEdge(int oneVertex);
	Edge<T>* nextEdge(Node<T> * node) {
		Edge<T> edge = new Edge;
		edge.start = node->index;
		if (node->next) {
			edge.end = node->next->index;
			edge.weight = node->next->weight;
			return edge;
		}
		else {
			return nullptr;
		}
	}
	void setEdge(int start, int end, T weight);
	void delEdge(int start, int end);
	void DFS(int n);
	void DFSS();
	void BFS(int n);
	void BFSS();
	void DFSNo_Recursive();
};

template<class T>
listGraph<T>::listGraph(int ** Martrix, int n): Graph<T>(n), graphVector(n) {
	Node<T> * pointer = nullptr;
	vertexNum = n;
	Mark = new int[n];
	for (int i = 0; i < n; i++) {
		Mark[i] = TYPE::UNVISITED;
	}
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (Martrix[i][j] != 0 && Martrix[i][j] != -1) {
				if(graphVector[i].Edge == nullptr)
				graphVector[i].Edge = new Node<T>(j, Martrix[i][j]);
				else {
					pointer = graphVector[i].Edge;
					while (pointer->next) {
						pointer = pointer->next;
					}
					pointer->next = new Node<T>(j, Martrix[i][j]);
				}
				num++;
			}
		}
	}
	edgeNum = num/2;
}

template<class T>
Edge<T> * listGraph<T>::firstEdge(int oneVertex) {
	Edge<T> edge = new Edge<T>;
	edge.start = oneVertex;
	if (graphVector[oneVertex].Edge) {
		edge.end = graphVector[oneVertex].Edge->index;
		edge.weight = graphVector[oneVertex].Edge->weight;
		return edge;
	}
	else {
		return nullptr;
	}
}
template<class T>
void listGraph<T>::setEdge(int start, int end, T weight){
	Node<T> * pointer = graphVector[start].Edge;
	while (pointer) {
		if (pointer->next == end) {
			pointer->weight = weight;
		}
	}
	Node<T> * node = new Node<T>(start, end);
	pointer->next = node;
}
template<class T>
void listGraph<T>::delEdge(int start, int end){
	Node<T> * pointer = graphVector[start].Edge;
	while (pointer) {
		if (pointer->next) {
			if (pointer->next->index == end) {
				Node<T> * temp = pointer->next;
				pointer->next = pointer->next->next;
				delete temp;
			}
		}
	}
}

template<class T>
void listGraph<T>::DFS(int n) {
	if (Mark[n] == TYPE::UNVISITED) {
		Mark[n] = TYPE::VISITED;
		cout << n + 1 << endl;
		Node<T>* e = graphVector[n].Edge;
		while (e->next) {
			if (Mark[e->next->index] == TYPE::UNVISITED) {
				DFS(e->next->index);
			}
			e = e->next;
		}
	}
}

template<class T>
void listGraph<T>::DFSS() {
	for (int i = 0; i < vertexNum; i++) {
		Mark[i] = TYPE::UNVISITED;
	}
	for (int i = 0; i < vertexNum; i++) {
		if (Mark[i] == TYPE::UNVISITED) {
			DFS(i);
		}

	}
}

template<class T>
void listGraph<T>::BFS(int n) {
	queue<int> Q;
	int u;
	Mark[n] = TYPE::VISITED;
	cout << n + 1 << endl;
	Q.push(n);
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		Node<T>* e = graphVector[n].Edge;
		while (e->next) {
			if (Mark[e->next->index] == TYPE::UNVISITED) {
				cout << e->next->index + 1 << endl;
				Mark[e->next->index] = TYPE::VISITED;
				Q.push(e->next->index);
			}
			e = e->next;
		}
	}
}

template<class T>
void listGraph<T>::BFSS() {
	int v;
	for (v = 0; v < vertexNum; v++) {
		Mark[v] = TYPE::UNVISITED;
	}
	for (v = 0; v < vertexNum; v++) {
		if (Mark[v] == TYPE::UNVISITED) {
			BFS(v);
		}
	}
}

template<class T>
void listGraph<T>::DFSNo_Recursive() {
	for (int i = 0; i < vertexNum; i++) {
		Mark[i] = TYPE::UNVISITED;
	}
	int i, v, u;
	stack<int> s;
	for (int i = 0; i < vertexNum; i++) {
		s.push(i);
		while (!s.empty()) {
			v = s.top();
			s.pop();
			if (Mark[v] == TYPE::UNVISITED) {
				Mark[v] = TYPE::VISITED;
				cout << v + 1 << endl;
				Node<T>* e = graphVector[v].Edge;
				while (e->next) {
					if (Mark[e->next->index] == TYPE::UNVISITED) {
						s.push(e->next->index);
					}
					e = e->next;
				}
			}
		}
	}
}