#pragma once
template<class T>
class UFSets {
private:
	int n;
	int* root;
	int* next;
	int*length;
public:
	UFSets(int size) {
		n = size;
		root = new int[n];
		next = new int[n];
		length = new int[n];
		for (int i = 0; i < n; i++) {
			root[i] = next[i] = i;
			length[i] = 1;
		}
	}
	int Find(int v) { return root[v]; }
	void Union(int v, int u);
};

template<class T>
void UFSets<T>::Union(int v, int u)  {
	if (root[v] == root[u]) {
		return;
	}
	else if (length[root[v]] < length[root[u]]) {
		int rt = root[v];
		length[root[u]] += length[rt];
		root[rt] = root[u];
		for (int j = next[rt]; j != rt; j = next[j])
			root[j] = root[u];
		int temp = next[rt];
		next[rt] = next[root[u]];
		next[root[u]] = temp;
	}
	else {
		int rt = root[u];
		length[root[v]] += length[rt];
		root[rt] = root[v];
		for (int j = next[rt]; j != rt; j = next[j]) {
			root[j] = root[v];
		}
		int temp = next[rt];
		next[rt] = next[root[v]];
		next[root[v]] = temp;
	}
}
