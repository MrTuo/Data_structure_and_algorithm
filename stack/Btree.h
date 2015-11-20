#include <iostream>
using namespace std;

template <class T>
class btreeItem
{
public:
	btreeItem(const T& t) :item(t), LT(NULL), RT(NULL){};
	btreeItem(){ LT = NULL; RT = NULL; item = '\0'; }
	T item;
	btreeItem<T>* LT;
	btreeItem<T>* RT;
};
template <class T>
class Btree
{
public:
	Btree(){ root = new btreeItem<T> };
	Btree(int t){ root = new btreeItem<T>(t); };
	Btree(btreeItem<T>* r){ root = r; };
	bool IsEmpty();
	Btree<T> Lchild();
	Btree<T> Rchild();
	void SetL(Btree);
	void SetR(Btree);
	void SetI(const T &t){ root->item = t; }
	void PreOrder();
	void InOrder();
	void PostOrder();
	void LevelOrder();
private:
	btreeItem<T>* root;
	btreeItem<T>* GetRoot(Btree t){ return t.root; }
};

template<class T>
bool Btree<T>::IsEmpty()
{
	if (root == NULL)
		return true;
	return false;
}

template<class T>
Btree<T> Btree<T>::Lchild()
{
	return Btree(root->LT);
}

template<class T>
Btree<T> Btree<T>::Rchild()
{
	return Btree(root->RT);
}

template <class T>
void Btree<T>::SetL(Btree t)
{
	root->LT = GetRoot(t);
}

template <class T>
void Btree<T>::SetR(Btree t)
{
	root->RT = GetRoot(t);
}

template<class T>
void Btree<T>::PreOrder()
{
	if (!IsEmpty())
	{
		cout << root->item << endl;
		Lchild().PreOrder();
		Rchild().PreOrder();
	}
}
template<class T>
void Btree<T>::InOrder()
{
	if (!IsEmpty())
	{
		Lchild().InOrder();
		cout << root->item << endl;
		Rchild().InOrder();
	}
}
template<class T>
void Btree<T>::PostOrder()
{
	if (!IsEmpty())
	{
		Lchild().PostOrder();
		Rchild().PostOrder();
		cout << root->item << endl;
	}
}


