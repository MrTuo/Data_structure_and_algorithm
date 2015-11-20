#include <iostream>
#include "Btree.h"
using namespace std;
BT Build(BT pre[], BT mid[], int &ptr, int n);//参数依次为先序序列，中序序列，和中序序列的遍历指针，以及序列规模。

BT Build(BT pre[], BT mid[], int &ptr, int n)
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
		root->LT = Build(pre, LTlst, ptr, size_l);//递归创建左子树
		root->RT = Build(pre, RTlst, ptr, size_r);//递归创建右子树
		return root;
	}
}


int main()
{
	char inp[] = "abdecf", inp2[100] = "dbeacf";
	int a=strlen(inp);
	BT pre[100], mid[100];
	BT tmp;
	Empty(tmp);
	int n, ptr=0;
	n = 6;  
	for (int i = 0; i < n; i++)
	{
		Empty( pre[i]);
		pre[i]->data = inp[i];
		Empty(mid[i]);
		mid[i]->data = inp2[i];
	}
	tmp = Build(pre, mid, ptr, n);
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