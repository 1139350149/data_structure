#include "Sort.h"
#include <string>

int main() {
	int n;
	cin >> n;
	int * data = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	Sort<int>::bubbleSort(data, n);
	for (int i = 0; i < n; i++) {
		cout << data[i] << ends;
	}
	cout << endl << "bubbleSort################" << endl;
	/*Sort<int>::insertSort(data, n);
	for (int i = 0; i < n; i++) {
		cout << data[i] << ends;
	}
	cout << endl << "insertSort################" << endl;*/
	/*Sort<int>::binaryInsertSort(data, n);
	for (int i = 0; i < n; i++) {
		cout << data[i] << ends;
	}
	cout << endl << "binaryInsertSort################" << endl;*/
	/*Sort<int>::mergeSort(data, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << data[i] << ends;
	}
	cout << endl << "mergeSort################" << endl;*/
	/*Sort<int>::quickSort(data, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << data[i] << ends;
	}
	cout << endl << "quickSort################" << endl;*/
	
	/*Sort<int>::shellSort(data, n);
	for (int i = 0; i < n; i++) {
		cout << data[i] << ends;
	}
	cout << endl << "shellSort################" << endl;*/
	/*Sort<int>::selectionSort(data, n);
	for (int i = 0; i < n; i++) {
		cout << data[i] << ends;
	}
	cout << endl << "selectionSort################" << endl;*/
	/*RadixSort(data, n);
	for (int i = 0; i < n; i++) {
		cout << data[i] << ends;
	}
	cout << endl << "RadixSort################" << endl; */
	system("pause");
	return 0;
}