#include <iostream>
#include <string>
#include <assert.h>
#include "BF.h"
#include "KMP.h"
#include "String.h"

using namespace std;



int main() {
	KMP kmp("aabaac", "aabaadaabaac");
	cout << kmp.match() << endl;
	BF bf("183", "abc18346980377");
	cout << bf.match();
	system("pause");
	/*string temp1, temp2;
	cin >> temp1 >> temp2;
	String obj1(temp1.c_str()), p(temp2.c_str());
	cout << String::Strcmp(obj1, p) << endl << String::rFind(obj1, p) << endl;
	system("pause");*/
	return 0;
}