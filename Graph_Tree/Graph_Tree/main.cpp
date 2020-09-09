#include <iostream>
#include "Prim.h"
#include "Kruskal.h"
#include "Dijkstra.h"
#include "Floyd.h"

int main() {
	int **temp;
	Edge<int> * primRes;
	temp = new int*[6];
	int n;
	/*cin >> n;
	for (int i = 0; i < n; i++) {
		temp[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp[i][j];
		}
	}
	listGraph<int> lG(temp, n);
	lG.DFSS();
	cout << "#################" << endl;
	lG.DFSNo_Recursive();
	cout << "#################" << endl;
	lG.BFSS();
	cout << "#################" << endl;
	cin >> n;
	primRes = Prim<int>::prim(lG, n);
	for (int i = 0; i < lG.getVertexNum() - 1; i++) {
		cout << "<v" << primRes[i].start + 1 <<  ", v" << primRes[i].end + 1 << "> weight: " << primRes[i].weight << endl;
	}
	cout << "#################" << endl;
	primRes = Kruskal<int>::krusal(lG);
	for (int i = 0; i < lG.getVertexNum() - 1; i++) {
		cout << "<v" << primRes[i].start + 1 << ", v" << primRes[i].end + 1 << "> weight: " << primRes[i].weight << endl;
	}*/
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		temp[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp[i][j];
		}
	}
	listGraph<int> lG1(temp, n);
	/*Dist * D = nullptr;
	Dijkstra<int>::dijkstra(lG1, D, 0);
	for (int i = 0; i < lG1.getVertexNum(); i++) {
		cout << D[i].getLength() << ends << D[i].getPre() << endl;
	}*/
	int ** A = nullptr;
	int ** P = nullptr;
	Floyd<int>::floyd(lG1, A, P);
	n = lG1.getVertexNum();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << ends;
		}
		cout << endl;
	}
	cout << "#############" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << P[i][j] << ends;
		}
		cout << endl;
	}
	
	system("pause");
	return 0;
}