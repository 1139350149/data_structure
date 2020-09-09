#pragma once
#include "listGrapg.h"
#include "Union.h"

template<class T>
class Kruskal {
public:
	static Edge<T> * krusal(listGraph<T> & g) {
		int n = g.getVertexNum();
		/*int * unionSet = new int[n];
		for (int i = 0; i < n; i++) {
			unionSet[i] = i + 1;
		}*/
		UFSets<T> unionSet(n);
		Edge<T> * MST = new Edge<T>[n - 1];
		T ** nearest;
		nearest = new T*[n];		//»®÷ÿæÿ’Û
		for (int i = 0; i < n; i++) {
			nearest[i] = new T[n];
			for (int j = 0; j < n; j++) {
				nearest[i][j] = 3254;
			}
		}
		int temp = 0;
		for (auto e = g.graphVector.begin(); e != g.graphVector.cend(); e++, temp++) {
			Node<T> * tempNode = e->Edge;
			while (tempNode) {
				nearest[temp][tempNode->index] = tempNode->weight;
				tempNode = tempNode->next;
			}
		}
		int amount = n - 1;
		int  i = 0, j = 0, min = 3254, flagx, flagy;
		while (amount--) {
			min = 3254;
			for (i = 0; i < n; i++) {
				min = (min == 3254) ? 3254 : min;
				for (j = 0; j < n; j++) {
					if (unionSet.Find(i) != unionSet.Find(j)) {
						if (min > nearest[i][j]) {
							min = nearest[i][j];
							flagx = i;
							flagy = j;
						}
					}
				}
			}
			MST[n - 2 - amount].start = flagx;
			MST[n - 2 - amount].end = flagy;
			MST[n - 2 - amount].weight = nearest[flagx][flagy];
			//int temp = unionSet[flagy];
			//for (int i = 0; i < n; i++) {
				//if (unionSet[i] == temp) {
					//unionSet[i] = unionSet[flagx];
				//}
			//}
			unionSet.Union(flagx, flagy);
		}
		return MST;
	}
};