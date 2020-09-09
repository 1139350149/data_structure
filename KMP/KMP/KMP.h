#pragma once
#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

class KMP {
public:
	KMP(string p, string t);
	void getNext();
	int match(int startIndex = 0);
private:
	string t, p;
	int* Next;
};

