#include "KMP.h"

KMP::KMP(string p,string t){
	this->p = p;
	this->t = t;
}
void KMP::getNext() {
	int m = p.length();
	assert(m > 0);
	Next = new int[m];
	Next[0] = 0;
	for (int i = 1; i < m; i++) {
		int k = Next[i - 1];
		while (k > 0 && p[k] != p[i]) {
			k = Next[k - 1];
		}
		if (p[k] == p[i]) {
			Next[i] = k + 1;
		}
		else {
			Next[i] = 0;
		}
	}
	for (int i = 1; i < m; i++) {
		cout << Next[i] << ends;
	}
	cout << endl;
}

int KMP::match(int startIndex) {
	getNext();
	if (t.length() - startIndex + 1 < p.length()) {
		return -1;
	}
	int j = 0;
	for (int i = startIndex; i < t.length(); i++) {
		while (p[j] != t[i] && j > 0) {
			j = Next[j - 1];
		}
		if (p[j] == t[i]) {
			j++;
		}
		if (j == p.length()) {
			return i - j + 1;
		}
	}
}
