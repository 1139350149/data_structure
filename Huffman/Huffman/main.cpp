#include "Huffuman.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	string data;
	int weight[100];
	cin >> data;
	int j = data.length();
	for (int i = 0; i < data.length(); i++) {
		cin >> weight[i];
	}
	Huffman<char> huffmanTree(const_cast<char*>(data.c_str()), weight, data.length());
	huffmanTree.breadthFirstOrder(huffmanTree.root);
	huffmanTree.Coding(huffmanTree.root);
	cin >> data;
	cout << huffmanTree.ToBinary(data) << endl;
	data = "10111 11 1010 000 100 01 10110 001";
	cout << huffmanTree.Encoding(data) << endl;
	system("pause");
	return 0;
}