#include <iostream>
using namespace std;

template <class T>
class btreeItem
{
public:
	btreeItem(const T& t) :item(t), LT(NULL), RT(NULL);
	T item;
	btreeItem<T>* LT;
	btreeItem<T>* RT;
};
template <class T>
class Btree
{
public:
	Btree(t){ root = new btreeItem<T>(t); };
	Btree(btreeItem<T>* r){ root = r; };
	~Btree();
	bool IsEmpty();
	Btree Lchild();
	Btree Rchild();
	void SetL(Btree);
	void SetR(Btree);
	void SetI(const T &t){ root->item = t; }
	void PreOrder();
	void InOrder();
	void PostOrder();
	void LevelOrder();
private:
	btreeItem<T>* root;
	btreeItem GetRoot(Btree t){return t->root };
};

template<class T>
bool Btree<T>::IsEmpty()
{
	if (root == NULL)
		return true;
	return false;
}

template<class T>
Btree<T> Btree::Lchild()
{
	return Btree(root->LT);
}

template<class T>
Btree<T> Btree::Rchild()
{
	return Btree(root->RT);
}

template <class T>
void Btree<T>::SetL(Btree t)
{
	root->LT = t->GetRoot();
}

template <class T>
void Btree<T>::SetR(Btree)
{
	root->RT = t->GetRoot();
}

template<class T>
void Btree<T>::PreOrder()
{
	if (!IsEmpty())
	{
		cout << root->data << endl;
		Lchild().PreOrder();
		Rchild().PreOrder();
	}
}
template<class T>
void Btree<T>::PreOrder()
{
	if (!IsEmpty())
	{
		Lchild().PreOrder();
		cout << root->data << endl;
		Rchild().PreOrder();
	}
}
template<class T>
void Btree<T>::PreOrder()
{
	if (!IsEmpty())
	{
		Lchild().PreOrder();
		Rchild().PreOrder();
		cout << root->data << endl;
	}
}


