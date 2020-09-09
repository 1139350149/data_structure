#include "AVLTree.h"

int main() {
	AVLTree<int> AV;
	int n;
	cin >> n;
	int temp;
	while (n--) {
		cin >> temp;
		AV.insert(temp);
	}
	system("pause");
	return 0;
}