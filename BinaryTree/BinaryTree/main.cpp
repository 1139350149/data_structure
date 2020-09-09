#include "BinaryTree.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	int size;
	cin >> size;
	/*BinaryTree<string> myBT(size);
	myBT.breadthFirstOrder(myBT.getRoot());
	cout << "##############" << endl;
	myBT.preOrder(myBT.getRoot());
	cout << "##############" << endl;
	myBT.inOrder(myBT.getRoot());
	cout << "##############" << endl;
	myBT.postOrder(myBT.getRoot());
	cout << "##############" << endl;*/
	string pre = "ABECDFGHIJ", in = "EBCDAFHIGJ", post = "EDCBIHJGFA";
	//BinaryTree<char>  myBT(const_cast<char*> (pre.c_str()), const_cast<char*> (in.c_str()), pre.length(), 1);
	BinaryTree<char> myBT(const_cast<char*> (in.c_str()), const_cast<char*> (post.c_str()), in.length(), 2);
	myBT.preOrder(myBT.getRoot());
	int count = 0;
	/*cout << "#########" << endl;
	myBT.postOrder(myBT.getRoot());
	cout << "#########" << endl;
	myBT.inOrder(myBT.getRoot());
	cout << "#########" << endl;
	myBT.breadthFirstOrder(myBT.getRoot());
	cout << "#########" << endl;*/
	/*myBT.findMax(myBT.getRoot());
	cout << endl << "#########" << endl;
	cout << myBT.count0(myBT.getRoot()) << endl;
	cout << "#########" << endl;*/
	myBT.count1(myBT.getRoot(), count);
	cout << count << endl;
	/*cout << "#########" << endl;
	count = 0;
	myBT.count2(myBT.getRoot(), count);
	cout << count << endl;
	cout << "#########" << endl;
	cout << myBT.getHeight(myBT.getRoot()) << endl;
	cout << "#########" << endl;
	cout << myBT.getMaxWidth(myBT.getRoot()) << endl;
	cout << "#########" << endl;*/
	/*myBT.deleteLeaves(myBT.getRoot(), myBT.getRoot());
	cout << myBT.count0(myBT.getRoot());
	cout << "#########" << endl;
	myBT.postOrder(myBT.getRoot());
	cout << "#########" << endl;
	myBT.inOrder(myBT.getRoot());
	cout << "#########" << endl;
	myBT.breadthFirstOrder(myBT.getRoot());
	cout << "#########" << endl;*/
	system("pause");
	return 0;
}

