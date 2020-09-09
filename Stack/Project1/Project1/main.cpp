#include "Stack.h"


int main() {
	Stack<string> myStack(20);
	for (int i = 0; i < 100;) {
		myStack.Push("wdnmd" + i);
		cout << myStack << endl;
		i += 2;
	}
	system("pause");
	return 0;
}