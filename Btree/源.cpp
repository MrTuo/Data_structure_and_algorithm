#include <iostream>
#include "Btree.h"
#include "stack.h"
using namespace std;
struct T_stack{
	int n_child;
	BT tree;
};
BT Build_recu(BT pre[], BT mid[], int &ptr, int n);//参数依次为先序序列，中序序列，和中序序列的遍历指针，以及序列规模。
BT Build_iter(BT pre[], BT mid, int n);//
bool Find(BT T, BT arr[], int n);//
bool Find(BT T, BT arr[], int &ptr, int n)
{
	for (int i = 0; i < n;i++)
		if (arr[i] == T)
		{
			ptr = i;
			return true;
		}
	return false;
}

BT Build_recu(BT pre[], BT mid[], int &ptr, int n)
{

	if (n == 0)//如果先序序列中左右子树都是叶节点则可以建立一个树
	{
		return NULL;
	}
	else//否则分别处理左子树序列和右子树序列
	{
		BT LTlst[100], RTlst[100];
		int size_l = 0, size_r = 0;
		int shift = 0;
		BT root = pre[ptr];//获取根节点
		for (int i = 0; i < n; i++)//通过遍历从根节点将先序表达式分为左子树节点和右子树节点
		{
			if (mid[i]->data == root->data)
				shift = 1;
			else if (shift)
				RTlst[size_r++] = mid[i];
			else
				LTlst[size_l++] = mid[i];
		}
		ptr++;// 移动先序表达式指针
		root->LT = Build_recu(pre, LTlst, ptr, size_l);//递归创建左子树
		root->RT = Build_recu(pre, RTlst, ptr, size_r);//递归创建右子树
		return root;
	}
}

BT Build_iter(BT pre[], BT mid[], int n)
{
	T_stack s1Top, s2Top,  lchild, rchild,root_stack;
	BT root;
	stack <T_stack> s1, s2;
	int ptr2 = 0, ptr = 0 ;
	int tag[100];/*建立一个标志数组，用来记录中序表达式中各个元素的状态，长度比mid大2，tag的第二位与mid第一位对齐*/
	for (int i = 0; i < n; i++)
		tag[i + 1] = 0;
	tag[0] = tag[n] = 1;

	while (ptr<n)
	{
		root = pre[ptr];
		root_stack.tree = root;
		root_stack.n_child = 0;
		if (!s1.IsEmpty())
			s1Top = s1.Top();
		if (s1Top.n_child == 2)
		{
			s2.Pop(rchild);
			s2.Pop(lchild);
			s1Top.tree->LT = lchild.tree;
			s1Top.tree->RT = rchild.tree;
			s1.Pop();
			s2.Push(s1Top);
		}
		else
		{
			Find(root, mid, ptr2, n);
			if (tag[ptr2 - 1] && tag[ptr2 + 1])//如果当前扫描位的前一位和后一位都被处理过，则当前扫描位是叶节点。
			{
				s1Top.n_child++;
				s2.Push(root_stack);
			}
			else
				s1.Push(root_stack);
		}
	}
	return pre[0];
}

int main()
{
	char inp[] = "abdcefgh", inp2[100] = "bcdeagfh";
	int a=strlen(inp);
	BT pre[100], mid[100];
	BT tmp;
	Empty(tmp);
	int n, ptr=0;
	n = 8;  
	for (int i = 0; i < n; i++)
	{
		Empty( pre[i]);
		pre[i]->data = inp[i];
		Empty(mid[i]);
		mid[i]->data = inp2[i];
	}
	//tmp = Build_recu(pre, mid, ptr, n);
	tmp = Build_iter(pre, mid, n);
	cout << "先序遍历：";
	PreOrder(tmp);
	cout << endl;
	cout << "中序遍历：";
	InOrder(tmp);
	cout << endl;
	cout << "后序遍历：";
	PostOrder(tmp);

	getchar();
	return 0;
}