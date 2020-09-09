#pragma once
#include "listGrapg.h"

template<class T>
class Floyd {
public:
	static void floyd(listGraph<T> & g, T ** & Adj, int ** & path) {
		int i, j, v;
		int n = g.getVertexNum();
		Adj = new T * [n];
		path = new int * [n];
		for (int i = 0; i < n; i++) {
			Adj[i] = new T[n];
			path[i] = new int[n];
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (i == j) {
					Adj[i][j] = 0;
					path[i][j] = i + 1;
				}
				else {
					Adj[i][j] = 3254;
					path[i][j] = i + 1;
				}
			}
		}
		for (v = 0; v < n; v++) {
			Node<T> * pointer = g.graphVector[v].Edge;
			while (pointer) {
				Adj[v][pointer->index] = pointer->weight;
				pointer = pointer->next;
			}
		}
		for (v = 0; v < n; v++) {
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					if (Adj[i][j] > Adj[i][v] + Adj[v][j]) {
						Adj[i][j] = Adj[i][v] + Adj[v][j];
						path[i][j] = v + 1;
					}
				}
			}
			/*for (int h = 0; h < n; h++) {
				for (int k = 0; k < n; k++) {
					cout << Adj[h][k] << ends;
				}
				cout << endl;
			}
			cout << "adj:            ###############" << endl;
			for (int h = 0; h < n; h++) {
				for (int k = 0; k < n; k++) {
					cout << path[h][k] << ends;
				}
				cout << endl;
			}
			cout << "path:           ###############" << endl;*/
		}
	}
};
