#pragma once
#include <iostream>
#include <string>

using namespace std;

class BF {
public:
	BF(string t, string p);
	int match(int startIndex = 0);
private:
	string t, p;
};

