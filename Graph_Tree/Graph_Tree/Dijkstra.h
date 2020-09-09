#pragma once
#include "listGrapg.h"

class Dist {
public:
	int length;
	int pre;

	Dist();
	void setLength (int len);
	void setPre (int pre);
	int getLength();
	int getPre();
};

Dist::Dist() {
	this->length = 0;
	this->pre = 0;
}

void Dist::setLength(int len) {
	this->length = len;
}

void Dist::setPre(int pre) {
	this->pre = pre;
}

int Dist::getLength() { return this->length; }

int Dist::getPre() { return this->pre; }

template<class T>
class Dijkstra {
public:
	static void dijkstra(listGraph<T> & g, Dist *& D, int s) {
		int n = g.getVertexNum();
		D = new Dist[n];
		for (int i = 0; i < n; i++) {
			D[i].setLength(-1);
			D[i].setPre(s);
			g.Mark[i] = TYPE::UNVISITED;
		}
		D[s].setLength(0);
		Node<T> * pointer = g.graphVector[s].Edge;
		while (pointer) {
			D[pointer->index].setLength(pointer->weight);
			D[pointer->index].setPre(s);
			pointer = pointer->next;
		}
		for (int i = 0; i < n; i++) {
			if (g.graphVector[i].Edge == nullptr) {
				D[i].length = -1;
				D[i].pre = -1;
				g.Mark[i] = TYPE::UNVISITED;
			}
		}
		cout << "##################" << endl;
		g.Mark[s] = TYPE::VISITED;
		int amount = n - 1;
		while (amount--) {
			int index = s, min = 3254;
			for (int i = 0; i < n; i++) {
				if (min > D[i].length && D[i].length != -1 && D[i].length != 0 && g.Mark[i] != TYPE::VISITED) {
					index = i;
					min = D[i].length;
				}
			}
			g.Mark[index] = TYPE::VISITED;
			pointer = g.graphVector[index].Edge;
			while (pointer) {
				if (D[pointer->index].length > D[index].length + pointer->weight || D[pointer->index].length == -1) {
					D[pointer->index].length = D[index].length + pointer->weight;
					D[pointer->index].pre = index;
				}
				pointer = pointer->next;
			}
		}
	}
};