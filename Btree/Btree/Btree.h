#include <iostream>
#include "stack.h"
using namespace std;
struct node
{
	char data;
	node * LT;
	node * RT;
};
typedef node* BT;

void Empty(BT &T);
bool IsEmpty(BT);
void PreOrder(BT);
void InOrder(BT); 
BT Lchild(BT T);
BT Rchild(BT T);


void Empty(BT &T)
{
	T = new node;
	T->data = '\0';
	T->LT = NULL;
	T->RT = NULL;
}

bool IsEmpty(BT T)
{
	if (T == NULL)
		return true;
	return false;
}

BT Lchild(BT T)
{
	return T->LT;
}

BT Rchild(BT T)
{
	return T->RT;
}

void PreOrder(BT T)
{
	if (!IsEmpty(T))
	{
		cout << T->data << ";";
		PreOrder(Lchild(T));
		PreOrder(Rchild(T));
	}
}

void InOrder(BT T)
{
	if (!IsEmpty(T))
	{
		InOrder(Lchild(T));
		cout << T->data << ";";
		InOrder(Rchild(T));
	}
}

void PostOrder(BT T)
{
	if (!IsEmpty(T))
	{
		PostOrder(Lchild(T));
		PostOrder(Rchild(T));
		cout << T->data << ";";
	}
}

void LeveOrder(BT T)
{
	stack<BT> s(100);

}







