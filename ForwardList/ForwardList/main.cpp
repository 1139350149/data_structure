#include "ForwardList.h"
#include <list>

int main() {
	ForwardList<int> myList;
	for (int i = 0; i < 10; i += 2) {
		int j = i;
		myList.insertHead(j);
	}
	for (int i = 0; i < myList.getsize(); i++) {
		cout << myList.data() << ends << myList.currentPosition() <<  endl;
		myList.next();
	}
	cout << endl;
	myList.reverse();
	myList.printList();

	system("pause");
}