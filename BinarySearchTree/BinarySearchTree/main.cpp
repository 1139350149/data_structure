#include "BinarySearchTree.h"
#include "MaxHeap.h"

int main() {
	BinarySearchTree<int> BST;
	int n, m;
	cin >> n;
	while (n--) {
		cin >> m;
		BST.InsertNode(m);
	}
	BST.BreadthOrder(BST.getRoot());
	BinarySearchNode<int> * node = BST.search(BST.getRoot(), 5);
	BST.deleteByCopying(node);
	BST.BreadthOrder(BST.getRoot());


	/*int a;
	cin >> a;
	int * b = new int[a];
	for (int i = 0; i < a; i++) {
		cin >> b[i];
	}
	maxHeap<int> mHeap(b, a, 100);
	mHeap.BuildHeap();
	mHeap.insert(1);
	cout << mHeap.RemoveMax() << endl;*/
	
	system("pause");
	return 0;
}
