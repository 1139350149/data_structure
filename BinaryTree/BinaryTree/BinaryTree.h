#pragma once
#include "Node.h"
#include "queue.h"
#include "ListStack.h"

template<class T>
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(T* pre, T* in, int n, int mode);
	BinaryTree(int size);
	~BinaryTree();
	bool isEmpty() const;
	void deleteBinaryTree(BinaryTreeNode<T> * pRoot);
	BinaryTreeNode<T> * getRoot() const;
	BinaryTreeNode<T> * getParent(BinaryTreeNode<T> * current) const;
	BinaryTreeNode<T> * getLeftSibling(BinaryTreeNode<T> * current) const;
	BinaryTreeNode<T> * getRightSibling(BinaryTreeNode<T> * current) const;
	void breadthFirstOrder(BinaryTreeNode<T> * root);
	void preOrder(BinaryTreeNode<T> * root);
	void inOrder(BinaryTreeNode<T> * root);
	void postOrder(BinaryTreeNode<T> * root);
	void levelOrder(BinaryTreeNode<T> * root);
	BinaryTreeNode<T> * createTreeByPreAndIn(T* pre, T* in, int n);
	BinaryTreeNode<T> * createTreeByInAndPost(T* in, T* post, int n);
	void count1(BinaryTreeNode<T> * root, int & count);
	void count2(BinaryTreeNode<T> * root , int & count);
	int count0(BinaryTreeNode<T> * root);
	void countHeight(BinaryTreeNode<T> * root, int level, int & depth);
	void countWidth(BinaryTreeNode<T> * root, int depth);
	int getMaxWidth(BinaryTreeNode<T> * root);
	void transform(BinaryTreeNode<T> * root);
	void deleteLeaves(BinaryTreeNode<T> * root, BinaryTreeNode<T> * pre);
	bool judge(BinaryTreeNode<T> * root);
	T findMax(BinaryTreeNode<T> * root);
	int getHeight(BinaryTreeNode<T> * root);
private:
	BinaryTreeNode<T> * root;
	int depth = 0;
	int width[100];
};

template<class T>
BinaryTree<T>::BinaryTree() {
	this->root = nullptr;
}

template<class T>
BinaryTree<T>::BinaryTree(int size) {
	T obj;
	this->root = new BinaryTreeNode<T>;
	BinaryTreeNode<T> * temp;
	Queue<BinaryTreeNode<T>* > nodeQueue;
	nodeQueue.EnQueue(this->root);
	while (size--) {
		temp = nodeQueue.getFront();
		cin >> obj;
		temp->setData(obj);
		nodeQueue.DeQueue(temp);
		temp->setLeftChild(new BinaryTreeNode<T>);
		temp->setRightChild(new BinaryTreeNode<T>); 
		nodeQueue.EnQueue(temp->getLeftChild());
		nodeQueue.EnQueue(temp->getRightChild());
	}
}

template<class T>
void BinaryTree<T>::deleteBinaryTree(BinaryTreeNode<T> * pRoot) {
	BinaryTreeNode<T>* lNode = nullptr, *rNode = nullptr;
	if (pRoot) {
		lNode = pRoot->getLeftChild();
		rNode = pRoot->getRightChild();
		delete pRoot;
	}
	if (lNode) {
		deleteBinaryTree(lNode);
	}
	if (rNode) {
		deleteBinaryTree(rNode);
	}
}

template<class T>
BinaryTree<T>::~BinaryTree() {
	deleteBinaryTree(this->root);
}

template<class T>
bool BinaryTree<T>::isEmpty() const{
	return (this->root == nullptr);
}

template<class T>
BinaryTreeNode<T> * BinaryTree<T>::getRoot() const {
	return this->root;
}

template<class T>
BinaryTreeNode<T> * BinaryTree<T>::getParent(BinaryTreeNode<T> * current) const {
	Queue<BinaryTreeNode<T>*> nodeQueue;
	BinaryTreeNode<T>* pointer = this->root;
	if (pointer) {
		nodeQueue.EnQueue(pointer);
	}
	while (!nodeQueue.isEmpty()) {
		pointer = nodeQueue.getFront();
		if (pointer->getLeftChild() == current || pointer->getRightChild() == current) {
			return pointer;
		}
		nodeQueue.EnQueue(pointer->getLeftChild());
		nodeQueue.EnQueue(pointer->getRightChild());
	}
	return nullptr;
}

template<class T>
BinaryTreeNode<T> * BinaryTree<T>::getLeftSibling(BinaryTreeNode<T> * current) const {
	return current->getLeftChild();
}

template<class T>
BinaryTreeNode<T> * BinaryTree<T>::getRightSibling(BinaryTreeNode<T> * current) const {
	return current->getRightChild();
}

template<class T>
void BinaryTree<T>::breadthFirstOrder(BinaryTreeNode<T> * root) {
	Queue<BinaryTreeNode<T>*> nodeQueue;
	int count = 1;
	BinaryTreeNode<T>* pointer = root;
	if (pointer) {
		nodeQueue.EnQueue(pointer);
	}
	while (!nodeQueue.isEmpty()) {
		pointer = nodeQueue.getFront();
		cout << count++ << " " << pointer->getData() << endl;
		nodeQueue.DeQueue(pointer);
		if (pointer->getLeftChild()) {
			nodeQueue.EnQueue(pointer->getLeftChild());
		}
		if (pointer->getRightChild()) {
			nodeQueue.EnQueue(pointer->getRightChild());
		}
	}
}

template<class T>
void BinaryTree<T>::levelOrder(BinaryTreeNode<T> * root) {
	breadthFirstOrder(root);
}

template<class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T>* root) {
	ListStack<BinaryTreeNode<T>* > nodeStack;
	BinaryTreeNode<T> * pointer = this->root;
	BinaryTreeNode<T> * p;
	int count = 1;

	while (!nodeStack.isEmpty() || pointer) {
		if (pointer) {
			cout << count++ << " " << pointer->getData() << endl;
			if (pointer->getRightChild()) {
				nodeStack.push(pointer->getRightChild());
			}
			pointer = pointer->getLeftChild();
		}
		else {
			nodeStack.Top(pointer);

			nodeStack.pop(p);
		}
	}
}

template<class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T> * root) {
	ListStack<BinaryTreeNode<T> * > nodeStack;
	BinaryTreeNode<T> * pointer = this->root, *p;
	
	int count = 1;
	while (!nodeStack.isEmpty() || pointer) {
		if (pointer) {
			nodeStack.push(pointer);
			pointer = pointer->getLeftChild();
		}
		else {
			nodeStack.Top(pointer);

			cout << count++ << " " << pointer->getData() << endl;
			pointer = pointer->getRightChild();
			nodeStack.pop(p);

		}
	}
}


template<class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> * root) {
	ListStack<BinaryTreeNode<T> * > nodeStack;
	BinaryTreeNode<T> * pointer = root, *pre = nullptr;
	int count = 1;

	while (pointer){
		for (; pointer->getLeftChild() != nullptr; pointer = pointer->getLeftChild()) {
			nodeStack.push(pointer);
		}
		while (pointer != nullptr && (pointer->getRightChild() == nullptr || pointer->getRightChild() == pre)) {
			cout << count++ << ends <<  pointer->getData() << endl;
			pre = pointer;
			if (nodeStack.isEmpty()) {
				return;
			}
			nodeStack.pop(pointer);
		}
		nodeStack.push(pointer);
		pointer = pointer->getRightChild();
	}
}

template<class T>
BinaryTree<T>::BinaryTree(T* str1, T* str2, int n, int mode) {
	if (mode == 1) {
		root = createTreeByPreAndIn(str1, str2, n);
	}
	else if (mode == 2) {
		root = createTreeByInAndPost(str1, str2, n);
	}
}

template<class T>
BinaryTreeNode<T> * BinaryTree<T>::createTreeByPreAndIn(T* pre, T* in, int n) {		//先序序列， 中序序列， 序列长度
	if (n == 0) {
		return nullptr;
	}
	BinaryTreeNode<T> * node = new BinaryTreeNode<T>(pre[0]);
	T* lpre = new T[n], *lin = new T[n];
	T* rpre = new T[n], *rin = new T[n];
	int lp1 = 0, rp2 = 0;
	int lin1 = 0, rin2 = 0;
	for (int i = 0; i < n; i++) {
		if (i <= lin1 && in[i] != pre[0]) {
			lin[lin1++] = in[i];
		}
		else if (in[i] != pre[0]) {
			rin[rin2++] = in[i];
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (i < (lin1 + 1))
		{
			lpre[lp1++] = pre[i];
		}
		else
		{
			rpre[rp2++] = pre[i];
		}
	}
	node->setLeftChild(createTreeByPreAndIn(lpre, lin, lin1));
	node->setRightChild(createTreeByPreAndIn(rpre, rin, rin2));
	if (lpre) {
		delete lpre;
	}
	if (lin) {
		delete lin;
	}
	if (rin) {
		delete rin;
	}
	if (rpre) {
		delete rpre;
	}
	return node;
}

template<class T>
BinaryTreeNode<T> * BinaryTree<T>::createTreeByInAndPost(T* in, T* post, int n) {	//中序序列， 后序序列， 序列长度
	if (n == 0) {
		return nullptr;
	}
	BinaryTreeNode<T> * node = new BinaryTreeNode<T>(post[n-1]);
	T* lpost = new T[n], *lin = new T[n];
	T* rpost = new T[n], *rin = new T[n];
	int lin1 = 0, rin2 = 0;
	int lp1 = 0, rp2 = 0;
	for (int i = 0; i < n; i++) {
		if (i <= lin1 && in[i] != post[n - 1]) {
			lin[lin1++] = in[i];
		}
		else if (in[i] != post[n - 1]) {
			rin[rin2++] = in[i];
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (i < lin1)
		{
			lpost[lp1++] = post[i];
		}
		else
		{
			rpost[rp2++] = post[i];
		}
	}
	node->setLeftChild(createTreeByInAndPost(lin, lpost, lin1));
	node->setRightChild(createTreeByInAndPost(rin, rpost, rin2));
	if (lpost) {
		delete lpost;
	}
	if (lin) {
		delete lin;
	}
	if (rin) {
		delete rin;
	}
	if (rpost) {
		delete rpost;
	}
	return node;
}

template<class T>
int BinaryTree<T>::count0(BinaryTreeNode<T> * root) {
	if (root == nullptr) {
		return 0;
	}
	else {
		if (root->getLeftChild() == nullptr && root->getRightChild() == nullptr) {
			return 1;
		}
		else {
			return count0(root->getLeftChild()) + count0(root->getRightChild());
		}
	}
}


template<class T>
void BinaryTree<T>::count2(BinaryTreeNode<T> * root,int & count) {
	if (root == nullptr) {
		return;
	}
	if (root->getLeftChild() != nullptr && root->getRightChild() != nullptr) {
		count++;
	}
	count2(root->getLeftChild(), count);
	count2(root->getRightChild(), count);
}

template<class T>
void BinaryTree<T>::count1(BinaryTreeNode<T> * root, int & count) {
	if (root == nullptr) {
		return;
	}
	if ((root->getLeftChild() != nullptr && root->getRightChild() == nullptr) || (root->getLeftChild() == nullptr && root->getRightChild() != nullptr)) {
		count++;
	}
	count1(root->getLeftChild(), count);
	count1(root->getRightChild(), count);
}

template<class T>
void BinaryTree<T>::countHeight(BinaryTreeNode<T> * root, int level, int & depth) {
	if (root) {
		if (level > depth) {
			depth = level;
		}
		countHeight(root->getLeftChild(), level + 1, depth);
		countHeight(root->getRightChild(), level + 1, depth);
	}
}

template<class T>
int BinaryTree<T>::getHeight(BinaryTreeNode<T> * root) {
	int level = 1, depth = 1;
	countHeight(root, level, depth);
	return depth;
}

template<class T>
void BinaryTree<T>::countWidth(BinaryTreeNode<T> * root, int depth) {
	if (root == nullptr) {
		return;
	}
	width[depth]++;
	countWidth(root->getLeftChild(), depth + 1);
	countWidth(root->getRightChild(), depth + 1);
}

template<class T>
int BinaryTree<T>::getMaxWidth(BinaryTreeNode<T> * root) {
	countWidth(root, 0);
	int width1 = -1;
	for (int i = 0; i < getHeight(root); i++) {
		if (width1 < width[i]) {
			width1 = width[i];
		}
	}
	return width1;
}

template<class T>
void BinaryTree<T>::transform(BinaryTreeNode<T> * root) {
	if (root == nullptr) {
		return;
	}
	BinaryTreeNode<T> * pointer = root->getLeftChild();
	root->setLeftChild(root->getRightChild());
	root->setRightChild(pointer);
	transform(root->getLeftChild());
	transform(root->getRightChild());
}

template<class T>
void BinaryTree<T>::deleteLeaves(BinaryTreeNode<T> * root, BinaryTreeNode<T> * pre) {
	if (root == nullptr) {
		return;
	}
	if (root->getLeftChild() == nullptr && root->getRightChild() == nullptr) {
		if (pre->getLeftChild() == root) {
			pre->setLeftChild(nullptr);
		}
		if (pre->getRightChild() == root) {
			pre->setRightChild(nullptr);
		}
		delete root;
		root = nullptr;
		return;
	}
	if (root) {
		deleteLeaves(root->getLeftChild(), root);
		deleteLeaves(root->getRightChild(), root);
	}
}

template<class T>
bool BinaryTree<T>::judge(BinaryTreeNode<T> * root) {
	Queue<BinaryTreeNode<T> * > queue;
	bool flag = false;	
	if (root) {
		queue.EnQueue(root);
	}
	BinaryTreeNode<T> * pointer = queue.getFront();
	while (pointer) {
		if (pointer->getLeftChild() == nullptr && pointer->getRightChild() != nullptr) {
			return false;
		}
		if (flag == true && (pointer->getLeftChild() || pointer->getRightChild())) {
			return false;
		}
		if (pointer->getLeftChild() == nullptr || pointer->getRightChild() == nullptr) {
			flag = true;
		}
		if (pointer->getLeftChild()) {
			queue.EnQueue(pointer->getLeftChild());
		}
		if (pointer->getRightChild()) {
			queue.EnQueue(pointer->getRightChild());
		}
		if (!queue.isEmpty()) {
			pointer = queue.getFront();
		}
		else {
			pointer = nullptr;
		}
	}
}

template <class T>
T BinaryTree<T>::findMax(BinaryTreeNode<T> * root) {
	if (root == nullptr) {
		return 0;
	}
	T max = 0;
	Queue<BinaryTreeNode<T> * > queue;
	queue.EnQueue(root);
	BinaryTreeNode<T> * pointer = nullptr;
	while (!queue.isEmpty()) {
		pointer = queue.getFront();
		if (max < pointer->getData()) {
			max = pointer->getData();
		}
		queue.DeQueue(pointer);
		if (pointer->getLeftChild()) {
			queue.EnQueue(pointer->getLeftChild());
		}
		if (pointer->getRightChild()) {
			queue.EnQueue(pointer->getRightChild());
		}
	}
	cout << max << ends;
	findMax(root->getLeftChild());
	findMax(root->getRightChild());
	return max;
}
