#include "BiLinkedList.h"

int main() {
	BiLinkedList<int> myList;
	int temp = 0;
	myList.insertTail(temp);
	for (int i = 0; i < 10; i += 2) {
		myList.insertTail(i);
	}
	myList.printList();
	myList.deleteNodeByValue(0);
	myList.printList();
	cout << endl << endl;
	/*myList.Nothing();
	myList.printList();*/
	system("pause");
	return 0;
}