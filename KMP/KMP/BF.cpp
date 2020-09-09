#include "BF.h"

BF::BF( string p, string t) {
	this->p = p;
	this->t = t;
}

int BF::match(int startIndex) {
	int l = t.length(), i = startIndex, j = 0;
	if (l < p.length()) {
		return -1;
	}
	for (; i < l;i++) {
		if (this->t[i] == this->p[j]) {
			j++;
		}
		else {
			i = i - j;
			j = 0;
		}
		if (j == p.length()) {
			return i - j + 1;
		}
	}
}

