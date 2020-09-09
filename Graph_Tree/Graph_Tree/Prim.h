#pragma once
#include "listGrapg.h"
#include "Edge.h"
#include <memory>

template<class T>
class Prim {
public:
	static Edge<T> *  prim(listGraph<T> & g, int s) {
		T ** nearest;
		int n = g.getVertexNum();
		Edge<T> * MST = new Edge<T>[n - 1];
		for (int i = 0; i < n; i++) {
			g.Mark[i] = TYPE::UNVISITED;
		}
		g.Mark[s] = TYPE::VISITED;
		int amount = n - 1;
		nearest = new T*[n];		//È¨ÖØ¾ØÕó
		for (int i = 0; i < n; i++) {
			nearest[i] = new T[n];
			for (int j = 0; j < n; j++) {
				nearest[i][j] = 3254;
			}
		}
		int temp = 0;
		for (auto e = g.graphVector.begin(); e != g.graphVector.cend(); e++ ,temp++) {
			Node<T> * tempNode = e->Edge;
			while (tempNode) {
				nearest[temp][tempNode->index] = tempNode->weight;
				tempNode = tempNode->next;
			}
		}
		for (int t = 0; t < n; t++) {
			for (int h = 0; h < n; h++) {
				cout << nearest[t][h] << " ";
			}
			cout << endl;
		}
		while (amount--) {
			int  i = 0, j = 0, flagy = 0, flagx = 0, min = 3254;
			for (i = 0; i < n; i++) {
				min = (min == 3254) ? 3254 : min;
				if (g.Mark[i] == TYPE::VISITED) {
					for (j = 0; j < n; j++) {
						if (g.Mark[j] == TYPE::UNVISITED) {
							if (nearest[i][j] < min) {
								min = nearest[i][j];
								flagx = i;
								flagy = j;
							}
						}
					}
				}
			}
			g.Mark[flagy] = TYPE::VISITED;
			MST[n - 2 - amount].start = flagx;
			MST[n - 2 - amount].end = flagy;
			MST[n - 2 - amount].weight = nearest[flagx][flagy];
		}
		return MST;
	}
};