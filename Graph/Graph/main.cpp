#include "listGrapg.h"
#include <iostream>

int main() {
	int **temp;
	temp = new int*[5];
	for (int i = 0; i < 5; i++) {
		temp[i] = new int[5];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> temp[i][j];
		}
	}
	listGraph<int> lG(temp, 5);
	lG.DFSS();
	cout << "#################" << endl;
	lG.DFSNo_Recursive();
	cout << "#################" << endl;
	lG.BFSS();
	cout << "#################" << endl;
	system("pause");
	return 0;
}